/*
 * @title SwagDeque
 * @docs md/data-structure/Swag.md
 */
template<class Operator> class SwagDeque{
public:
    using TypeNode = typename Operator::TypeNode;
    stack<pair<TypeNode,TypeNode>> pre,suf;
    stack<TypeNode> tmp;

    SwagDeque() {
        // do nothing
    }
    TypeNode fold() {
        TypeNode res = Operator::unit_node;
        if(pre.size()) res = Operator::func_node(pre.top().second,res);
        if(suf.size()) res = Operator::func_node(res,suf.top().second);
        return res;
    }
    void push_back(const TypeNode val) {
        TypeNode acc = val;
        if(suf.size()) acc = Operator::func_node(suf.top().second,val);
        suf.emplace(val,acc);
    }
    void push_front(const TypeNode val) {
        TypeNode acc = val;
        if(pre.size()) acc = Operator::func_node(val,pre.top().second);
        pre.emplace(val,acc);
    }
    void pop_back() {
        if(suf.empty()) {
            while(pre.size()>tmp.size()+1) {
                tmp.push(pre.top().first); pre.pop();
            }
            {
                TypeNode acc = Operator::unit_node;
                while(pre.size()) {
                    auto [val,_] = pre.top(); pre.pop();
                    acc = Operator::func_node(acc,val);
                    suf.emplace(val,acc);
                }
            }
            {
                TypeNode acc = Operator::unit_node;
                while(tmp.size()) {
                    TypeNode val = tmp.top(); tmp.pop();
                    acc = Operator::func_node(val,acc);
                    pre.emplace(val,acc);
                }
            }
        }
        suf.pop();
    }
    void pop_front() {
        if(pre.empty()) {
            while(suf.size()>tmp.size()+1) {
                tmp.push(suf.top().first); suf.pop();
            }
            {
                TypeNode acc = Operator::unit_node;
                while(suf.size()) {
                    auto [val,_] = suf.top(); suf.pop();
                    acc = Operator::func_node(val,acc);
                    pre.emplace(val,acc);
                }
            }
            {
                TypeNode acc = Operator::unit_node;
                while(tmp.size()) {
                    TypeNode val = tmp.top(); tmp.pop();
                    acc = Operator::func_node(acc,val);
                    suf.emplace(val,acc);
                }
            }
        }
        pre.pop();
    }
    size_t size() const {
        return pre.size()+suf.size();
    }
    bool empty() const {
        return pre.empty() && suf.empty();
    }
    void print() {
        stack<pair<TypeNode,TypeNode>> ls,rs;
        vector<pair<TypeNode,TypeNode>> lv,rv;
        while(pre.size()) {
            auto p=pre.top(); pre.pop();
            lv.push_back(p);
            ls.push(p);
        }
        while(suf.size()) {
            rs.emplace(suf.top()); suf.pop();
        }
        while(ls.size()) {
            pre.push(ls.top()); ls.pop();
        }
        while(rs.size()) {
            auto p=rs.top(); rs.pop();
            rv.push_back(p);
            suf.push(p);
        }
        cout << "{";
        for(int i=0;i<lv.size();++i) {
            cout << "{" << lv[i].first << ":" << lv[i].second << "} ";
        }
        cout << "} , {";
        for(int i=0;i<rv.size();++i) {
            cout << "{" << rv[i].first << ":" << rv[i].second << "} ";
        }
        cout << "}" << endl;
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
    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {l.first*r.first, r.first*l.second+r.second};}
};