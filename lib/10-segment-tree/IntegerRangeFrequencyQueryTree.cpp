/*
 * @title IntegerRangeFrequencyQueryTree - integer専用区間freq
 * @docs md/segment-tree/IntegerRangeFrequencyQueryTree.md
 */
template<unsigned int bit_length=20> class IntegerRangeFrequencyQueryTree {
    using u64 = unsigned long long;
    class SimpleBinaryTrie {
        struct Node {
            Node *left, *right;
            u64 size;
            Node(): size(0) {left=right=nullptr;}
        };
        Node* root;
        size_t size(Node* node) const {return (node==nullptr ? 0 : node->size);}
        bool empty(Node* node) const {return size(node) == 0;}
        void print(Node* node,u64 i, u64 val) {
            if(i == bit_length) {
                cout << "{" << val << ":" << size(node) << ":" << size(node->left) << ":" << size(node->right) << "} ";
                return;
            }
            if(node->left != nullptr) {
                print(node->left, i+1, val);
            }
            if(node->right != nullptr) {
                print(node->right, i+1, (val | (1UL<<(bit_length-1-i))) );
            }
        }
    public:
        SimpleBinaryTrie(): root(new Node()) {}
        void insert(const u64 val) {
            Node* curr = root; stack<Node*> st;
            for(u64 i=0; i < bit_length; ++i) {
                u64 j = ((val>>(bit_length-1-i)) & 1UL);
                st.push(curr);
                if(j) {
                    if(curr->right != nullptr) { curr = curr->right;}
                    else {
                        Node* next = new Node();
                        curr->right = next;
                        curr = next;
                    }
                }
                else {
                    if(curr->left != nullptr) curr = curr->left;
                    else {
                        Node* next = new Node();
                        curr->left = next;
                        curr = next;
                    }
                }
            }
            curr->size += 1;
            while(st.size()) {
                auto node=st.top(); st.pop();
                node->size = size(node->left) + size(node->right);
            }
        }
        void erase(const u64 val) {
            Node* curr = root; stack<Node*> st;
            for(u64 i=0; i < bit_length; ++i) {
                u64 j = ((val>>(bit_length-1-i)) & 1UL);
                st.push(curr);
                if(j) {
                    if(curr->right != nullptr) curr = curr->right;
                    else return;
                }
                else {
                    if(curr->left != nullptr) curr = curr->left;
                    else return;
                }
            }
            if(empty(curr)) return;
            curr->size -= 1;
            while(st.size()) {
                auto node=st.top(); st.pop();
                node->size = size(node->left) + size(node->right);
            }
        }
        size_t size() const {return size(root);}
        u64 kth_smallest(u64 k) const {
            Node* curr = root; u64 val=0;
            for(u64 i=0; i < bit_length; ++i) {
                u64 j = 1UL << (bit_length-1-i);
                u64 sz_l = size(curr->left);
                if(k<sz_l) curr = curr->left;
                else {
                    val |= j;
                    k -= sz_l;
                    curr = curr->right;
                }
            }
            return val;
        }
        size_t lower_bound(const u64 val) const {
            Node* curr = root;
            u64 k=0;
            for(u64 i=0; i < bit_length; ++i) {
                u64 j = ((val>>(bit_length-1-i)) & 1UL);
                if(j) {
                    k+=size(curr->left);
                    if(curr->right != nullptr) curr = curr->right;
                    else break;
                }
                else {
                    if(curr->left != nullptr) curr = curr->left;
                    else break;
                }
            }
            return k;
        }
        size_t count(const u64 val) const {
            Node* curr = root;
            for(u64 i=0; i < bit_length; ++i) {
                u64 j = ((val>>(bit_length-1-i)) & 1);
                if(j) {
                    if(curr->right != nullptr) curr = curr->right;
                    else return 0;
                }
                else {
                    if(curr->left != nullptr) curr = curr->left;
                    else return 0;
                }
            }
            return size(curr);
        }
        void print() {
            cout << "{"; print(root,0,0); cout << "}" << endl;
        }
    };
    size_t length;
    size_t num;
    vector<SimpleBinaryTrie> node;
    void insert_impl(size_t idx, const u64 val) {
        if(idx < 0 || length <= idx) return;
        idx += length;
        node[idx].insert(val);
        while(idx >>= 1) node[idx].insert(val);
    }
    void erase_impl(size_t idx, const u64 val) {
        if(idx < 0 || length <= idx) return;
        idx += length;
        node[idx].erase(val);
        while(idx >>= 1) node[idx].erase(val);
    }
    int range_freq_upper_impl(int l, int r, const u64 upper) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        int ret=0;
        for(l += length, r += length; l < r; l >>=1, r >>=1) {
            if(l&1) ret += node[l++].lower_bound(upper);
            if(r&1) ret += node[--r].lower_bound(upper);
        }
        return ret;
    }
    int range_freq_impl(int l, int r, const u64 val) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        int ret=0;
        for(l += length, r += length; l < r; l >>=1, r >>=1) {
            if(l&1) ret += node[l++].count(val);
            if(r&1) ret += node[--r].count(val);
        }
        return ret;
    }
public:
    //unitで初期化
    IntegerRangeFrequencyQueryTree(const vector<u64> & vec) {
        for (length = 1; length <= vec.size(); length *= 2);
        node.resize(2 * length);
        for (int i=0; i < vec.size(); ++i) {
            insert(i, vec[i]);
        }
    }
    //idx番目の要素にinsert
    void insert(const size_t idx, const u64 val) { insert_impl(idx, val);}
    //idx番目の要素にdelete
    void erase(size_t idx, const u64 val) { erase_impl(idx, val);}
    //[l,r) range freq of val (val < upper)
    int range_freq_upper(const int l, const int r, const u64 upper) const {return range_freq_upper_impl(l,r,upper);}
    //[l,r) range freq of val (lower <= val < upper)
    int range_freq_lower_upper(const int l, const int r, const u64 lower, const u64 upper) const { return range_freq_upper_impl(l,r,upper) - range_freq_upper_impl(l,r,lower);}
    //[l,r) range freq of val
    int range_freq(const int l, const int r, const u64 val) const {return range_freq_impl(l,r,val);}
    void print() { for(int i= length; i < 2*length; ++i) node[i].print();}
};