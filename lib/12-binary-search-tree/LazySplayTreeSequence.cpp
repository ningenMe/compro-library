/*
 * @title LazySplayTreeSequence - 遅延評価SplayTree列
 * @docs md/binary-search-tree/LazySplayTreeSequence.md
 */
template<class Monoid> class LazySplayTreeSequence {
    using TypeNode = typename Monoid::TypeNode;
    using TypeLazy = typename Monoid::TypeLazy;
    struct Node {
    public:
        Node *left, *right;
        TypeNode value, range_value;
        TypeLazy range_lazy;
        int rev;
        int size;
        Node(const TypeNode v) : left(nullptr),right(nullptr),value(v),range_value(v),range_lazy(Monoid::unit_lazy),size(1),rev(0) {}
        friend ostream &operator<<(ostream &os, const Node* node) {return os << "{" << node->value << ", " << node->size << "}";}
    };
    struct TupleNode {
        Node *left, *center, *right;
        TupleNode(Node *left,Node *center,Node *right) : left(left), center(center), right(right) {}
    };
    Node* root;
    inline int size(Node *node) {return node==nullptr ? 0 : node->size;}
    inline TypeNode range_value(Node *node) {return node==nullptr ? Monoid::unit_node : node->range_value;}
    inline void update(Node *node) {
        node->size = 1;
        node->range_value = node->value;
		if(node->left != nullptr) {
            node->size = node->left->size + node->size;
            node->range_value = Monoid::func_fold(node->left->range_value, node->range_value);
        }
		if(node->right != nullptr) {
            node->size = node->size + node->right->size;
            node->range_value = Monoid::func_fold(node->range_value, node->right->range_value);
        }
    }
    inline void propagate(Node *node) {
        if(node==nullptr) return;
        if(node->range_lazy != Monoid::unit_lazy) {
            if(node->left  != nullptr) sync_lazy(node->left, node->range_lazy);
            if(node->right != nullptr) sync_lazy(node->right, node->range_lazy);
            node->range_lazy = Monoid::unit_lazy;
        }
        if(node->rev) {
            if(node->left  != nullptr) sync_rev(node->left);
            if(node->right != nullptr) sync_rev(node->right);
            node->rev = 0;
        }
    }
    inline void sync_lazy(Node *node, const TypeLazy lazy) {
        node->range_lazy = Monoid::func_lazy(node->range_lazy, lazy);
        node->value = Monoid::func_operate(node->value, lazy, 0,1);
        node->range_value = Monoid::func_operate(node->range_value, lazy, 0, node->size);
    }
    inline void sync_rev(Node *node) {
        swap(node->left, node->right);
        node->rev ^= 1;
    }
    inline Node* rotate_left(Node* node){
        Node* right = node->right;
        node->right = right->left;
        right->left = node;
        update(node);
        update(right);
        return right;
    }
    inline Node* rotate_right(Node* node){
        Node* left = node->left;
        node->left = left->right;
        left->right = node;
        update(node);
        update(left);
        return left;
    }

    inline Node* splay(Node* node, size_t k){
        propagate(node);
        size_t sz_l = size(node->left);
        if(k == sz_l) return node;
        if(k < sz_l) {
            node->left = splay(node->left, k);
            node = rotate_right(node);
        }
        else {
            node->right = splay(node->right, k - sz_l - 1);
            node = rotate_left(node);
        }
        update(node);
        return node;
    }

    //非再帰は遅かった
    // stack<pair<Node*, size_t>> st;
    // inline Node* splay(Node* node, size_t k){
    //     Node* t_node = node;
    //     Node* last = nullptr;
    //     while(last == nullptr) {
    //         propagate(t_node);
    //         size_t sz_l = size(t_node->left);
    //         if(k == sz_l) {
    //             last = t_node;
    //             continue;
    //         }
    //         if(k < sz_l) {
    //             st.emplace(t_node, 1);
    //             t_node = t_node->left;
    //         }
    //         else {
    //             st.emplace(t_node, 0);
    //             t_node = t_node->right;
    //             k = (k - sz_l - 1);
    //         }
    //     }
    //     while(st.size()) {
    //         auto [t_node,is_left] = st.top(); st.pop();
    //         if(is_left) {
    //             t_node->left = last;
    //             t_node = rotate_right(t_node);
    //         }
    //         else {
    //             t_node->right = last;
    //             t_node = rotate_left(t_node);
    //         }
    //         update(t_node);
    //         last = t_node;
    //     }
    //     return last;
    // }

    //    - parent
    //   |
    // left
    //の形でマージ
    Node* merge(Node* left, Node* parent) {
        if(left == nullptr) return parent;
        if(parent == nullptr) return left;
        parent = splay(parent, 0);
        parent->left = left;
        update(parent);
        return parent;
    }
    Node* merge(TupleNode* tuple_node) {
        Node* node = merge(tuple_node->center, tuple_node->right);
        if(tuple_node->left == nullptr) return node;
        tuple_node->left->right = node;
        update(tuple_node->left);
        return tuple_node->left;
    }
    // [0,k),[k,n) でsplit
    pair<Node*,Node*> split(Node* node, size_t k) {
        if(k >= size(node)) return {node, nullptr};
        Node* right = splay(node, k);
        Node* left = right->left;
        right->left = nullptr;
        update(right);
        return {left, right};
    }
    //[0,l),[l,r),[r,n) でsplit
    TupleNode* split(Node* node, size_t l, size_t r) {
        if(!l) {
            auto [center,right] = split(node, r);
            return new TupleNode(nullptr, center, right);
        }
        Node* left = splay(node, l-1);
        auto [center, right] = split(left->right, r-l);
        left->right = nullptr;
        update(left);
        return new TupleNode(left, center, right);
    }
    void insert_impl(const size_t k, const TypeNode value) {
        Node* new_node = new Node(value);
        if(k == size(root)){
            new_node->left = root;
            update(new_node);
            root = new_node;
            return;
        }
        if(k == 0){
            new_node->right = root;
            update(new_node);
            root = new_node;
            return;
        }
        Node* node = splay(root, k);
        new_node->left = node->left;
        node->left = new_node;
        update(new_node);
        update(node);
        root = node;
        return;
    }
    void erase_impl(const size_t k){
        Node* node = splay(root, k);
        root = merge(node->left,node->right);
    }
    TypeNode fold_impl(int l, int r) {
        if (l < 0 || size(root) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;
		TupleNode* tuple_node = split(root,l,r);
        TypeNode res = tuple_node->center->range_value;
        root = merge(tuple_node);
        return res;
    }
    void operate_impl(int l, int r, TypeLazy lazy) {
        if(l < 0 || size(root) <= l || r <= 0 || r-l <= 0) return;
		TupleNode* tuple_node = split(root,l,r);
        sync_lazy(tuple_node->center, lazy);
        root = merge(tuple_node);
    }
    void reverse_impl(int l, int r) {
        if (l < 0 || size(root) <= l || r<=0 || r-l <= 0) return;
		TupleNode* tuple_node = split(root,l,r);
        sync_rev(tuple_node->center);
        root = merge(tuple_node);
    }
    void print_impl() {
        size_t N = size(root);
        for(int i=0;i<N;++i) cout << get(i) << " ";
        cout << endl;
    }
public:
    LazySplayTreeSequence(): root(nullptr) {}
    inline TypeNode get(const size_t k) {root = splay(root , k); return root->value; }
    inline int size() {return size(root); }
    inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}
    inline void erase(const size_t k) { erase_impl(k);}
    inline void operate(const int l, const int r, const TypeLazy lazy) {operate_impl(l,r,lazy);}
    inline TypeNode fold(int l, int r) {return fold_impl(l,r); }
    inline void reverse(int l, int r) {reverse_impl(l,r);}
    void print() {print_impl();}
};
