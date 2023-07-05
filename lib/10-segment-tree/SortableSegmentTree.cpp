/*
 * @title SortableSegmentTree - ソート可能抽象化セグメント木
 * @docs md/segment-tree/SortableSegmentTree.md
 */
template<size_t bit_length, class Monoid> class SortableSegmentTree {
    using TypeNode = typename Monoid::TypeNode;
    using TypeSortKey = unsigned long long;
    class InnerTreeSet {
        struct Node {
            Node *left, *right; size_t size; TypeNode value,rev_value;
            Node(): size(0),value(Monoid::unit_node),rev_value(Monoid::unit_node) {left=right=nullptr;}
            Node(Node* _left, Node* _right):size(0),value(Monoid::unit_node),rev_value(Monoid::unit_node),left(_left),right(_right) {}
            void clear(){ left=right=nullptr; size=0;value=rev_value=Monoid::unit_node; }
            void init(TypeNode val) {size=1,value=rev_value=val;}
        };
        Node* root;
        int rev;
        size_t size(Node* node) const {return (node==nullptr ? 0 : node->size);}
        TypeNode value(Node* node) const {return (node==nullptr ? Monoid::unit_node: node->value);}
        TypeNode rev_value(Node* node) const {return (node==nullptr ? Monoid::unit_node: node->rev_value);}
        void update(Node* node) {
            size_t sz_l = size(node->left);
            size_t sz_r = size(node->right);
            if(!sz_l && node->left != nullptr) node->left = nullptr;
            if(!sz_r && node->right != nullptr) node->right = nullptr;
            node->size = sz_l + sz_r;
            node->value=Monoid::func_fold(value(node->left),value(node->right));
            node->rev_value=Monoid::func_fold(rev_value(node->right),rev_value(node->left));  
        }
        void insert(Node* node, int i, const TypeSortKey key, const TypeNode val) {
            if(i<0) { node->init(val); return;}
            const TypeSortKey j = ((key>>i) & 1);
            if(j) { if(node->right == nullptr) node->right = new Node(); insert(node->right, i-1, key, val);} 
            else { if(node->left == nullptr) node->left = new Node(); insert(node->left, i-1, key, val);}
            update(node);
        }
        void erase(Node* node, int i, const TypeSortKey key) {
            if(i<0) { node->clear(); return; }
            const TypeSortKey j = ((key>>i) & 1);
            if(j) { if(node->right != nullptr) erase(node->right, i-1, key);}
            else { if(node->left != nullptr) erase(node->left, i-1, key);}
            update(node);
        }
        pair<TypeSortKey, TypeNode> kth_smallest(Node* node, int i, size_t k) {
            if(i<0) { return {0, rev ? rev_value(node): value(node)};}
            const TypeSortKey j = (1ULL<<i);
            size_t sz_l = size(node->left);
            if(k<sz_l) { return kth_smallest(node->left,i-1,k);}
            else { auto p = kth_smallest(node->right,i-1,k-sz_l); p.first |= j; return p;}
        }
        Node* merge(Node* node_x, Node* node_y) {
            if(node_x == nullptr) return node_y;
            if(node_y == nullptr) return node_x;
            node_x->left = merge(node_x->left, node_y->left);
            node_x->right = merge(node_x->right, node_y->right);
            node_y->clear();
            update(node_x);
            return node_x;
        }
        //[0,k),[k,size) でsplit
        pair<Node*, Node*> split(Node* node, size_t k) {
            if(k==0) return {nullptr, node};
            if(k==size(node)) return {node, nullptr};
            size_t sz_l = size(node->left);
            if(k<sz_l) {
                auto [tmp_left, tmp_right] = split(node->left, k);
                node->left = tmp_right;
                Node* left = new Node(tmp_left, nullptr);
                update(left), update(node);
                return {left, node};
            }
            else {
                auto [tmp_left, tmp_right] = split(node->right, k - sz_l);
                node->right = tmp_left;
                Node* right = new Node(nullptr, tmp_right);
                update(node), update(right);
                return {node, right};
            }
        }
        InnerTreeSet(Node* node, int rev=0): root(node),rev(rev) {}
    public:
        InnerTreeSet(int rev=0): root(new Node),rev(rev) {}
        void insert(const TypeSortKey key, const TypeNode val) {insert(root,bit_length-1,key,val);}
        void erase(const TypeSortKey key) {erase(root,bit_length-1,key);}
        size_t size() const {return size(root);}
        pair<TypeSortKey, TypeNode> kth_smallest(size_t k) { return kth_smallest(root, bit_length-1, (rev?size()-1-k:k));}
        TypeNode fold_all() {return rev ? rev_value(root) : value(root);}
        void merge(InnerTreeSet st) { merge(root, st.root); rev=0; st.clear();}
        pair<InnerTreeSet, InnerTreeSet> split(size_t k) { 
            if(rev) { auto [node_x, node_y] = split(root, size() - k); return {InnerTreeSet(node_y, rev), InnerTreeSet(node_x, rev)}; }
            else { auto [node_x, node_y] = split(root, k); return {InnerTreeSet(node_x, rev), InnerTreeSet(node_y, rev)}; }
        }
        void clear() { root=new Node(); rev=0; }
        void sort_asc() {rev=0;}
        void sort_desc() {rev=1;}
        // void print() {size_t n = size(); cout << "{"; for(int i=0;i<n;++i) {auto [key,val]=kth_smallest(i); cout << "{" << key << ":" << val << "},";} cout << "}"; }
    };

    size_t length;
    vector<TypeNode> node;
    vector<InnerTreeSet> leaf;
    set<size_t> range;
    inline void build(const size_t num) {
        for (length = 1; length <= num; length *= 2);
        node.resize(2 * length, Monoid::unit_node);
        leaf.resize(length);
        for (int i = 0; i <= length; ++i) range.insert(i);
    }
    void sync_leaf(int i) {
        if(length <= i) return;
        int idx = i + length;
        node[idx] = leaf[i].fold_all();
        while(idx >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);
    }
    //[i,i+1) の leafにアクセスできるようにする
    inline void prepare_access(int i) {
        if(length <= i) return;
        auto itr = range.lower_bound(i);
        int r = *itr;
        if(r == i) return;
        --itr;
        int l = *itr;
        //[l,r) の区間を [l,i),[i,r) にsplitする
        auto [st_l, st_r] = leaf[l].split(i-l);
        leaf[l] = st_l; leaf[i] = st_r;
        sync_leaf(l);
        range.insert(i);
    }
    void sort_impl(int l, int r, int rev) {
        prepare_access(l);
        prepare_access(r);
        while(1) {
            size_t c = *range.upper_bound(l);
            if(c == r) break;
            leaf[l].merge(leaf[c]);
            range.erase(c); sync_leaf(c);
        }
        if(rev) leaf[l].sort_desc();
        else leaf[l].sort_asc();
        sync_leaf(l), sync_leaf(r);
    }
public:
    //unitで初期化 (keyはindexになる)
    SortableSegmentTree(const size_t num) {
        build(num);
        for (int i = 0; i < length; ++i) leaf[i].insert(i, Monoid::unit_node);
        for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);
    }
    //同じinitで初期化 (keyはindexになる)
    SortableSegmentTree(const size_t num, const TypeNode init) {
        build(num);
        for (int i = 0; i < length; ++i) leaf[i].insert(i, i<num ? init : Monoid::unit_node);
        for (int i = 0; i < length; ++i) node[i+length] = leaf[i].fold_all();
        for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);
    }
    //vectorで初期化
    SortableSegmentTree(const vector<TypeSortKey>& keys, const vector<TypeNode>& vals) {
        assert(keys.size() == vals.size());
        size_t num = keys.size();
        build(num);
        for (int i = 0; i < num; ++i) leaf[i].insert(keys[i], vals[i]);
        for (int i = num; i < length; ++i) leaf[i].insert(i, Monoid::unit_node);
        for (int i = 0; i < length; ++i) node[i+length] = leaf[i].fold_all();
        for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);
    }
    void sort_asc(int l, int r) { sort_impl(l,r,0); }
    void sort_desc(int l, int r) { sort_impl(l,r,1); }
    //[idx,idx+1)
    TypeNode get(size_t idx) {
        if(idx < 0 || length <= idx) return Monoid::unit_node;
        prepare_access(idx);
        sync_leaf(idx);
        return leaf[idx].kth_smallest(0).second;
    }
    //[idx,idx+1)
    void operate(size_t idx, const TypeSortKey key, const TypeNode val) {
        if(idx < 0 || length <= idx) return;
        prepare_access(idx); prepare_access(idx+1);
        auto [old_key, old_val] = leaf[idx].kth_smallest(0);
        leaf[idx] = InnerTreeSet();
        leaf[idx].insert(key,Monoid::func_operate(old_val,val));
        sync_leaf(idx); sync_leaf(idx+1);
    }
    //[l,r)
    TypeNode fold(int l, int r) {
        if (l < 0 || length <= l || r < 0 || length < r) return Monoid::unit_node;
        prepare_access(l), prepare_access(r);
        sync_leaf(l), sync_leaf(r);
        TypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;
        for(l += length, r += length; l < r; l >>=1, r >>=1) {
            if(l&1) vl = Monoid::func_fold(vl,node[l++]);
            if(r&1) vr = Monoid::func_fold(node[--r],vr);
        }
        return Monoid::func_fold(vl,vr);
    }
    void print(){
        cout << "vector" << endl;
        // cout << range << endl;
        // cout << "{ ";
        // for(int i = 0; i < length; ++i) leaf[i].print(), cout << ", ";
        // cout << " }" << endl;
        cout << "{ ";
        for(int i = 0; i < length; ++i) cout << leaf[i].fold_all() << ", ";
        cout << " }" << endl;
    }
};