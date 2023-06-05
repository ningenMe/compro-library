/*
 * @title Swag
 * @docs md/data-structure/Swag.md
 */
template<class Operator> class SwagQueue{
public:
    using TypeNode = typename Operator::TypeNode;
    stack<pair<TypeNode,TypeNode>> pre,suf;

    SwagQueue() {
        // do nothing
    }
    TypeNode fold() {
        TypeNode res = Operator::unit_node;
        if(pre.size()) res = Operator::func_node(pre.top().second,res);
        if(suf.size()) res = Operator::func_node(res,suf.top().second);
        return res;
    }
    void push(TypeNode val) {
        TypeNode acc = val;
        if(suf.size()) acc = Operator::func_node(suf.top().second,acc);
        suf.emplace(val,acc);
    }
    void pop() {
        if(pre.empty()) {
            TypeNode acc = Operator::unit_node;
            while(suf.size()) {
                auto [val,_] = suf.top();
                suf.pop();
                acc = Operator::func_node(val,acc);
                pre.emplace(val,acc);
            }
        }
        if(pre.size()) pre.pop();
    }
    size_t size(){
        return pre.size()+suf.size();
    }
};

template<class T> struct NodeGcd {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = 0;
    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return r?func_node(r,l%r):l;}
};

template<class T> struct NodeComposite {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = {1,0};
    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}
};