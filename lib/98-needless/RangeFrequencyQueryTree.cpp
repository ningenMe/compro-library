/*
 * @title RangeFrequencyQueryTree - 区間freqクエリ用Tree
 * @docs md/needless/RangeFrequencyQueryTree.md
 */
template<class T> class RangeFrequencyQueryTree {
    template<class U> class BinarySearchTreeSet {
        unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned int xor_shift() {
            unsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;
            return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
        }
        struct Node {
        private:
            void build() {left = right = nullptr;size = 1;}
        public:
            Node *left, *right;
            U value;
            int size;
            Node() {build();}
            Node(U v) : value(v) {build();}
            friend ostream &operator<<(ostream &os, const Node* node) {return os << "{" << node->value << ", " << node->range_value << ", " << node->size << "}";}
        };
        Node* root;
        inline int size(Node *node) const {return node==nullptr ? 0 : node->size;}
        inline Node* update(Node *node) {
            node->size = size(node->left) + size(node->right) + 1;
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
        inline int lower_bound(Node *node, U value) const {
            if (node==nullptr) return 0;
            if (value <= node->value) return lower_bound(node->left, value);
            else return size(node->left) + lower_bound(node->right, value) + 1;
        }
        inline int upper_bound(Node *node, U value) const {
            if (node==nullptr) return 0;
            if (value < node->value) return upper_bound(node->left, value);
            else return size(node->left) + upper_bound(node->right, value) + 1;
        }
        inline void insert_impl(const U value) {
            pair<Node*, Node*> sub = split_impl(this->root, lower_bound(this->root,value));
            this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)), sub.second);
        }
        inline void erase_impl(const U value) {
            int k1 = lower_bound(value), k2 = upper_bound(value);
            if(k1==k2) return;
            auto sub = split_impl(this->root,k1);
            this->root = merge_impl(sub.first, split_impl(sub.second, 1).second);
        }
    public:
        BinarySearchTreeSet() : root(nullptr) {}
        inline int size() {return size(this->root);}
        inline int empty(void) {return bool(size()==0);}
        inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}
        inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}
        inline void insert(const U value) {insert_impl(value);}
        inline void erase(const U value) {erase_impl(value);}
        inline int lower_bound(U value) const {return lower_bound(this->root,value);}
        inline int upper_bound(U value) const {return upper_bound(this->root,value);}
        inline int count(U value) const {return upper_bound(value) - lower_bound(value);}
    };
    size_t length;
    vector<BinarySearchTreeSet<T>> node;
    void insert_impl(size_t idx, const T var) {
        if(idx < 0 || length <= idx) return;
        idx += length;
        node[idx].insert(var);
        while(idx >>= 1) node[idx].insert(var);
    }
    void erase_impl(size_t idx, const T var) {
        if(idx < 0 || length <= idx) return;
        idx += length;
        node[idx].erase(var);
        while(idx >>= 1) node[idx].erase(var);
    }
    int range_freq_upper_impl(int l, int r, const T upper) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        int ret=0;
        for(l += length, r += length; l < r; l >>=1, r >>=1) {
            if(l&1) ret += node[l++].lower_bound(upper);
            if(r&1) ret += node[--r].lower_bound(upper);
        }
        return ret;
    }
    int range_freq_impl(int l, int r, const T val) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        int ret=0;
        for(l += length, r += length; l < r; l >>=1, r >>=1) {
            if(l&1) ret += node[l++].count(val);
            if(r&1) ret += node[--r].count(val);
        }
        return ret;
    }
public:
    RangeFrequencyQueryTree(const vector<T> & vec) {
        for (length = 1; length <= vec.size(); length *= 2);
        node.resize(2 * length, BinarySearchTreeSet<T>());
        for (int i=0; i < vec.size(); ++i) {
            insert_impl(i, vec[i]);
        }
    }
    //idx番目の要素をupdate
    void update(const size_t idx, const T var) { erase_impl(idx, var); insert_impl(idx, var);}
    //[l,r) range freq of val (val < upper)
    int range_freq_upper(const int l, const int r, const T upper) const {return range_freq_upper_impl(l,r,upper);}
    //[l,r) range freq of val (lower <= val < upper)
    int range_freq_lower_upper(const int l, const int r, const T lower, const T upper) const {return range_freq_upper_impl(l,r,upper) - range_freq_upper_impl(l,r,lower);}
    //[l,r) range freq of val
    int range_freq(const int l, const int r, const T val) const {return range_freq_impl(l,r,val);}
};