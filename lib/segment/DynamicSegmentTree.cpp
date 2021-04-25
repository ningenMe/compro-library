/*
 * @title DynamicSegmentTree - 非再帰抽象化動的セグメント木
 * @docs md/segment/DynamicSegmentTree.md
 */
template<class Operator> class DynamicSegmentTree {
    using TypeNode = typename Operator::TypeNode; 
    using i64 = long long;

    struct Node{
        Node *left, *right;
        TypeNode val;
        i64 l,r;
        Node(i64 l,i64 r):left(nullptr),right(nullptr),val(Operator::unit_node),l(l),r(r) {}
    };
    
    i64 length;
    Node *root;
    void print(Node *node) {
        if (node==nullptr) return;
        print(node->left);
        cout << node->val << " ";
        print(node->right);
    }
public:

    //unitで初期化
    DynamicSegmentTree(const i64 num) {
        for (length = 1; length <= num; length *= 2);
        root = new Node(0,length);
    }
    ~DynamicSegmentTree() {
        delete root;
        root = nullptr;
    }
    
    //[idx,idx+1)
    void update(i64 idx, const TypeNode var) {
        if(idx < 0 || length <= idx) return;
        Node *node = root;
        node->val = Operator::func_merge(node->val,var);

        i64 l = 0, r = length, m;
        while(r-l>1) {
            m = (r+l)>>1;
            if(idx<m) {
                r = m;
                if(!node->left) node->left=new Node(l,r);
                node = node->left;
            }
            else {
                l = m;
                if(!node->right) node->right = new Node(l,r);
                node = node->right;
            }
            node->val = Operator::func_merge(node->val,var);
        }
    }

    //[l,r)
    TypeNode get(i64 l, i64 r) {
        if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_node;
        TypeNode val = Operator::unit_node;
        stack<Node*> st;
        st.push(root);
        while(st.size()) {
            Node *node = st.top(); st.pop();
            if(l <= node->l && node->r <= r) {
                val = Operator::func_node(val,node->val);
            }
            else if(!(node->r <= l) && !(r <= node->l)) {
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
        }
        return val;
    }

    void print() {
        cout << "{";
        print(this->root);
        cout << "}" << endl;
    }
};

//一点加算 区間総和
template<class T> struct NodeSumPointAdd {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = 0;
    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
    inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}
};
