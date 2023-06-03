/*
 * @title RandomizedBinarySearchTreeSequence - ランダム平衡二分探索木列
 * @docs md/binary-search-tree/RandomizedBinarySearchTreeSequence.md
 */
template<class Monoid> class RandomizedBinarySearchTreeSequence {
    using TypeNode = typename Monoid::TypeNode;
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int xor_shift() {
        unsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;
        return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
    }
    struct Node {
    private:
        void build() {left = right = nullptr;size = 1; rev=0;}
    public:
        Node *left, *right;
        TypeNode value, range_value;
        int size,rev;
        Node() : value(Monoid::unit_node), range_value(Monoid::unit_node) {build();}
        Node(TypeNode v) : value(v), range_value(v) {build();}
        friend ostream &operator<<(ostream &os, const Node* node) {return os << "{" << node->value << ", " << node->range_value << ", " << node->size << "}";}
    };
    Node* root;
    inline int size(Node *node) {return node==nullptr ? 0 : node->size;}
    inline TypeNode range_value(Node *node) {return node==nullptr ? Monoid::unit_node : node->range_value;}
    inline TypeNode get(Node *node, size_t k) {
        if (node==nullptr) return Monoid::unit_node;
        if (k == size(node->left)) return node->value;
        if (k < size(node->left)) return get(node->left, k);
        else return get(node->right, k-1 - size(node->left));
    }
    inline Node* update(Node *node) {
        node->size = size(node->left) + size(node->right) + 1;
        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));
        return node;
    }
    inline Node* merge_impl(Node *left, Node *right) {
        if (left==nullptr)  return right;
        if (right==nullptr) return left;
        if (xor_shift() % (left->size + right->size) < left->size) {
            left->right = merge_impl(left->right, right);
            return update(left);
        }
        else {
            right->left = merge_impl(left, right->left);
            return update(right);
        }
    }
    inline pair<Node*, Node*> split_impl(Node* node, int k) {
        if (node==nullptr) return make_pair(nullptr, nullptr);
        if (k <= size(node->left)) {
            pair<Node*, Node*> sub = split_impl(node->left, k);
            node->left = sub.second;
            return make_pair(sub.first, update(node));
        }
        else {
            pair<Node*, Node*> sub = split_impl(node->right, k - 1 - size(node->left));
            node->right = sub.first;
            return make_pair(update(node), sub.second);
        }
    }
    inline void operate_impl(Node *node, int k, TypeNode value) {
        if(k < 0 || size(node) <= k) return;
        int sl = size(node->left);
        if(k < sl) operate_impl(node->left,k,value);
        else if(k==sl) node->value = Monoid::func_operate(node->value,value);
        else operate_impl(node->right,k-1-sl,value);
        update(node);
    }
    inline TypeNode fold_impl(Node *node, int l, int r) {
        if (l < 0 || size(node) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;
        if (l == 0 && r == size(node)) return range_value(node);
        TypeNode value = Monoid::unit_node;
        int sl = size(node->left);
        if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));
        l = max(l-sl,0), r -= sl;
        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);
        l = max(l-1,0), r -= 1;
        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));
        return value;
    }
    inline void insert_impl(const size_t k, const TypeNode value) {
        pair<Node*, Node*> sub = split_impl(this->root, k);
        this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)), sub.second);
    }
    inline void erase_impl(const size_t k) {
        if(size(this->root) <= k) return;
        auto sub = split_impl(this->root,k);
        this->root = merge_impl(sub.first, split_impl(sub.second, 1).second);
    }
public:
    RandomizedBinarySearchTreeSequence() : root(nullptr) {}
    inline int size() {return size(this->root);}
    inline int empty(void) {return bool(size()==0);}
    inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}
    inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}
    inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}
    inline void erase(const size_t k) {erase_impl(k);}
    inline TypeNode get(size_t k) {return get(this->root, k);}
    inline void operate(const int k, const TypeNode value) {operate_impl(this->root,k,value);}
    inline TypeNode fold(int l, int r) {return fold_impl(this->root,l,r);}
    void print() {int m = size(this->root); for(int i=0;i<m;++i) cout << get(i) << " \n"[i==m-1];}
};