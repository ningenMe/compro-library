/*
 * @title RangeIntegerFrequencyQuerySqrtTree - integer専用区間freq
 * @docs md/segment-tree/RangeIntegerFrequencyQuerySqrtTree.md
 */
template<unsigned int bit_length=20> class RangeIntegerFrequencyQuerySqrtTree {
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
                cout << "{" << val << ":" << size(node) << "} ";
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
        bool empty() const {return empty(root);}
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
            cout << "{"; print(root,0,0); cout << "} ";
        }
    };
    size_t length;
    size_t bucket_size;
    vector<SimpleBinaryTrie> node0;
    vector<u64> node1;
    inline static constexpr u64 inf = 1UL << bit_length;
    void insert_impl(size_t idx, const u64 val) {
        if(idx < 0 || length <= idx) return;
        node0[idx/bucket_size].insert(val);
        node1[idx]=val;
    }
    void erase_impl(size_t idx) {
        if(idx < 0 || length <= idx) return;
        if(node1[idx]==inf) return;
        u64 val = node1[idx];
        node0[idx/bucket_size].erase(val);
        node1[idx]=inf;
    }
    int range_freq_upper_impl(int l, int r, const u64 upper) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;

        int ret=0;
        if(r-l <= bucket_size) {
            for(int i=l; i<r; ++i) ret += (node1[i] < upper);
            return ret;         
        }
        int bl0 = l / bucket_size + !!(l%bucket_size), br0 = r / bucket_size;
        int bl1 = bl0 * bucket_size, br1 = br0 * bucket_size;

        for(int i=l; i < min(bl1,r); ++i) ret += (node1[i] < upper);
        for(int i=bl0; i < br0; ++i) ret += node0[i].lower_bound(upper);
        for(int i=max(br1,l); i < r; ++i) ret += (node1[i] < upper);

        return ret;
    }
    int range_freq_impl(int l, int r, const u64 val) const {
        if (l < 0 || length <= l || r < 0 || length < r) return 0;
        int ret=0;
        if(r-l <= bucket_size) {
            for(int i=l; i<r; ++i) ret += (node1[i] == val);
            return ret;         
        }
        int bl0 = l / bucket_size + !!(l%bucket_size), br0 = r / bucket_size;
        int bl1 = bl0 * bucket_size, br1 = br0 * bucket_size;

        for(int i=l; i < min(bl1,r); ++i) ret += (node1[i] == val);
        for(int i=bl0; i < br0; ++i) ret += node0[i].count(val);
        for(int i=max(br1,l); i < r; ++i) ret += (node1[i] == val);

        return ret;
    }
public:
    RangeIntegerFrequencyQuerySqrtTree(const u64 length): length(length), node1(length,inf) {
        bucket_size = 5*sqrt(length);
        if(!bucket_size) bucket_size=1;
        node0.resize(length / bucket_size + 1);
    }
    //idx番目の要素をupdate
    void update(const size_t idx, const u64 val) { erase_impl(idx); insert_impl(idx, val);}
    //idx番目の要素をerase
    void erase(const size_t idx) { erase_impl(idx); }
    //[l,r) range freq of val (val < upper)
    int range_freq_upper(const int l, const int r, const u64 upper) const {return range_freq_upper_impl(l,r,upper);}
    //[l,r) range freq of val (lower <= val < upper)
    int range_freq_lower_upper(const int l, const int r, const u64 lower, const u64 upper) const { return range_freq_upper_impl(l,r,upper) - range_freq_upper_impl(l,r,lower);}
    //[l,r) range freq of val
    int range_freq(const int l, const int r, const u64 val) const {return range_freq_impl(l,r,val);}
    void print() { 
        cout << length << " " << bucket_size << endl;
        for(int i= 0; i < length / bucket_size + 1; ++i) node0[i].print();
        cout << endl;
        for(int i= 0; i < length; ++i) cout << node1[i] << " \n"[i==length-1];
        cout << endl;
    }
};