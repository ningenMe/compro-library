---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/10-segment-tree/SortableSegmentTree.cpp
    title: "SortableSegmentTree - \u30BD\u30FC\u30C8\u53EF\u80FD\u62BD\u8C61\u5316\
      \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp
    title: "MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\u6570\
      , \u70B9\u66F4\u65B0]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
  bundledCode: "#line 1 \"test/segment-tree/SortableSegmentTree-rcq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <set>\n\
    using namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n\
    \ * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n    inline static constexpr\
    \ int ch_0='0';\n    inline static constexpr int ch_9='9';\n    inline static\
    \ constexpr int ch_n='-';\n    inline static constexpr int ch_s=' ';\n    inline\
    \ static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/00-util/ModInt.cpp\"\n/*\n * @title ModInt\n * @docs md/util/ModInt.md\n\
    \ */\ntemplate<long long mod> class ModInt {\npublic:\n    long long x;\n    constexpr\
    \ ModInt():x(0) {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod -\
    \ (-y)%mod)%mod) {}\n    constexpr ModInt &operator+=(const ModInt &p) {if((x\
    \ += p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator+=(const\
    \ long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n  \
    \  constexpr ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod)\
    \ x -= mod;return *this;}\n    constexpr ModInt &operator-=(const ModInt &p) {if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    constexpr ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x)\
    \ >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator*=(const ModInt\
    \ &p) {x = (x * p.x % mod);return *this;}\n    constexpr ModInt &operator*=(const\
    \ long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    constexpr\
    \ ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n\
    \    constexpr ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    constexpr ModInt &operator^=(const long long y) {ModInt p(y);x\
    \ = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const int\
    \ y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator/=(const\
    \ ModInt &p) {*this *= p.inv();return *this;}\n    constexpr ModInt &operator/=(const\
    \ long long y) {ModInt p(y);*this *= p.inv();return *this;}\n    constexpr ModInt\
    \ &operator/=(const int y) {ModInt p(y);*this *= p.inv();return *this;}\n    constexpr\
    \ ModInt operator=(const int y) {ModInt p(y);*this = p;return *this;}\n    constexpr\
    \ ModInt operator=(const long long y) {ModInt p(y);*this = p;return *this;}\n\
    \    constexpr ModInt operator-() const {return ModInt(-x); }\n    constexpr ModInt\
    \ operator++() {x++;if(x>=mod) x-=mod;return *this;}\n    constexpr ModInt operator--()\
    \ {x--;if(x<0) x+=mod;return *this;}\n    constexpr ModInt operator+(const ModInt\
    \ &p) const { return ModInt(*this) += p; }\n    constexpr ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    constexpr ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    constexpr ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    constexpr ModInt operator^(const\
    \ ModInt &p) const { return ModInt(*this) ^= p; }\n    constexpr bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n    constexpr bool operator!=(const ModInt\
    \ &p) const { return x != p.x; }\n    // ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    constexpr ModInt inv() const {int a=x,b=mod,u=1,v=0,t=0,tmp=0;while(b > 0)\
    \ {t = a / b;a-=t*b;tmp=a;a=b;b=tmp;u-=t*v;tmp=u;u=v;v=tmp;} return ModInt(u);}\n\
    \    constexpr ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul\
    \ *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    constexpr long long MOD_998244353 = 998244353;\nconstexpr long long MOD_1000000007\
    \ = 1'000'000'000LL + 7; //'\n#line 1 \"lib/10-segment-tree/SortableSegmentTree.cpp\"\
    \n/*\n * @title SortableSegmentTree - \u30BD\u30FC\u30C8\u53EF\u80FD\u62BD\u8C61\
    \u5316\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/SortableSegmentTree.md\n\
    \ */\ntemplate<size_t bit_length, class Monoid> class SortableSegmentTree {\n\
    \    using TypeNode = typename Monoid::TypeNode;\n    using TypeSortKey = unsigned\
    \ long long;\n    class InnerTreeSet {\n        struct Node {\n            Node\
    \ *left, *right; size_t size; TypeNode value,rev_value;\n            Node(): size(0),value(Monoid::unit_node),rev_value(Monoid::unit_node)\
    \ {left=right=nullptr;}\n            Node(Node* _left, Node* _right):size(0),value(Monoid::unit_node),rev_value(Monoid::unit_node),left(_left),right(_right)\
    \ {}\n            void clear(){ left=right=nullptr; size=0;value=rev_value=Monoid::unit_node;\
    \ }\n            void init(TypeNode val) {size=1,value=rev_value=val;}\n     \
    \   };\n        Node* root;\n        int rev;\n        size_t size(Node* node)\
    \ const {return (node==nullptr ? 0 : node->size);}\n        TypeNode value(Node*\
    \ node) const {return (node==nullptr ? Monoid::unit_node: node->value);}\n   \
    \     TypeNode rev_value(Node* node) const {return (node==nullptr ? Monoid::unit_node:\
    \ node->rev_value);}\n        void update(Node* node) {\n            size_t sz_l\
    \ = size(node->left);\n            size_t sz_r = size(node->right);\n        \
    \    if(!sz_l && node->left != nullptr) node->left = nullptr;\n            if(!sz_r\
    \ && node->right != nullptr) node->right = nullptr;\n            node->size =\
    \ sz_l + sz_r;\n            node->value=Monoid::func_fold(value(node->left),value(node->right));\n\
    \            node->rev_value=Monoid::func_fold(rev_value(node->right),rev_value(node->left));\
    \  \n        }\n        void insert(Node* node, int i, const TypeSortKey key,\
    \ const TypeNode val) {\n            if(i<0) { node->init(val); return;}\n   \
    \         const TypeSortKey j = ((key>>i) & 1);\n            if(j) { if(node->right\
    \ == nullptr) node->right = new Node(); insert(node->right, i-1, key, val);} \n\
    \            else { if(node->left == nullptr) node->left = new Node(); insert(node->left,\
    \ i-1, key, val);}\n            update(node);\n        }\n        void erase(Node*\
    \ node, int i, const TypeSortKey key) {\n            if(i<0) { node->clear();\
    \ return; }\n            const TypeSortKey j = ((key>>i) & 1);\n            if(j)\
    \ { if(node->right != nullptr) erase(node->right, i-1, key);}\n            else\
    \ { if(node->left != nullptr) erase(node->left, i-1, key);}\n            update(node);\n\
    \        }\n        pair<TypeSortKey, TypeNode> kth_smallest(Node* node, int i,\
    \ size_t k) {\n            if(i<0) { return {0, rev ? rev_value(node): value(node)};}\n\
    \            const TypeSortKey j = (1ULL<<i);\n            size_t sz_l = size(node->left);\n\
    \            if(k<sz_l) { return kth_smallest(node->left,i-1,k);}\n          \
    \  else { auto p = kth_smallest(node->right,i-1,k-sz_l); p.first |= j; return\
    \ p;}\n        }\n        Node* merge(Node* node_x, Node* node_y) {\n        \
    \    if(node_x == nullptr) return node_y;\n            if(node_y == nullptr) return\
    \ node_x;\n            node_x->left = merge(node_x->left, node_y->left);\n   \
    \         node_x->right = merge(node_x->right, node_y->right);\n            node_y->clear();\n\
    \            update(node_x);\n            return node_x;\n        }\n        //[0,k),[k,size)\
    \ \u3067split\n        pair<Node*, Node*> split(Node* node, size_t k) {\n    \
    \        if(k==0) return {nullptr, node};\n            if(k==size(node)) return\
    \ {node, nullptr};\n            size_t sz_l = size(node->left);\n            if(k<sz_l)\
    \ {\n                auto [tmp_left, tmp_right] = split(node->left, k);\n    \
    \            node->left = tmp_right;\n                Node* left = new Node(tmp_left,\
    \ nullptr);\n                update(left), update(node);\n                return\
    \ {left, node};\n            }\n            else {\n                auto [tmp_left,\
    \ tmp_right] = split(node->right, k - sz_l);\n                node->right = tmp_left;\n\
    \                Node* right = new Node(nullptr, tmp_right);\n               \
    \ update(node), update(right);\n                return {node, right};\n      \
    \      }\n        }\n        InnerTreeSet(Node* node, int rev=0): root(node),rev(rev)\
    \ {}\n    public:\n        InnerTreeSet(int rev=0): root(new Node),rev(rev) {}\n\
    \        void insert(const TypeSortKey key, const TypeNode val) {insert(root,bit_length-1,key,val);}\n\
    \        void erase(const TypeSortKey key) {erase(root,bit_length-1,key);}\n \
    \       size_t size() const {return size(root);}\n        pair<TypeSortKey, TypeNode>\
    \ kth_smallest(size_t k) { return kth_smallest(root, bit_length-1, (rev?size()-1-k:k));}\n\
    \        TypeNode fold_all() {return rev ? rev_value(root) : value(root);}\n \
    \       void merge(InnerTreeSet st) { merge(root, st.root); rev=0; st.clear();}\n\
    \        pair<InnerTreeSet, InnerTreeSet> split(size_t k) { \n            if(rev)\
    \ { auto [node_x, node_y] = split(root, size() - k); return {InnerTreeSet(node_y,\
    \ rev), InnerTreeSet(node_x, rev)}; }\n            else { auto [node_x, node_y]\
    \ = split(root, k); return {InnerTreeSet(node_x, rev), InnerTreeSet(node_y, rev)};\
    \ }\n        }\n        void clear() { root=new Node(); rev=0; }\n        void\
    \ sort_asc() {rev=0;}\n        void sort_desc() {rev=1;}\n        // void print()\
    \ {size_t n = size(); cout << \"{\"; for(int i=0;i<n;++i) {auto [key,val]=kth_smallest(i);\
    \ cout << \"{\" << key << \":\" << val << \"},\";} cout << \"}\"; }\n    };\n\n\
    \    size_t length;\n    vector<TypeNode> node;\n    vector<InnerTreeSet> leaf;\n\
    \    set<size_t> range;\n    inline void build(const size_t num) {\n        for\
    \ (length = 1; length <= num; length *= 2);\n        node.resize(2 * length, Monoid::unit_node);\n\
    \        leaf.resize(length);\n        for (int i = 0; i <= length; ++i) range.insert(i);\n\
    \    }\n    void sync_leaf(int i) {\n        if(length <= i) return;\n       \
    \ int idx = i + length;\n        node[idx] = leaf[i].fold_all();\n        while(idx\
    \ >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n \
    \   }\n    //[i,i+1) \u306E leaf\u306B\u30A2\u30AF\u30BB\u30B9\u3067\u304D\u308B\
    \u3088\u3046\u306B\u3059\u308B\n    inline void prepare_access(int i) {\n    \
    \    if(length <= i) return;\n        auto itr = range.lower_bound(i);\n     \
    \   int r = *itr;\n        if(r == i) return;\n        --itr;\n        int l =\
    \ *itr;\n        //[l,r) \u306E\u533A\u9593\u3092 [l,i),[i,r) \u306Bsplit\u3059\
    \u308B\n        auto [st_l, st_r] = leaf[l].split(i-l);\n        leaf[l] = st_l;\
    \ leaf[i] = st_r;\n        sync_leaf(l);\n        range.insert(i);\n    }\n  \
    \  void sort_impl(int l, int r, int rev) {\n        prepare_access(l);\n     \
    \   prepare_access(r);\n        while(1) {\n            size_t c = *range.upper_bound(l);\n\
    \            if(c == r) break;\n            leaf[l].merge(leaf[c]);\n        \
    \    range.erase(c); sync_leaf(c);\n        }\n        if(rev) leaf[l].sort_desc();\n\
    \        else leaf[l].sort_asc();\n        sync_leaf(l), sync_leaf(r);\n    }\n\
    public:\n    //unit\u3067\u521D\u671F\u5316 (key\u306Findex\u306B\u306A\u308B\
    )\n    SortableSegmentTree(const size_t num) {\n        build(num);\n        for\
    \ (int i = 0; i < length; ++i) leaf[i].insert(i, Monoid::unit_node);\n       \
    \ for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \    }\n    //\u540C\u3058init\u3067\u521D\u671F\u5316 (key\u306Findex\u306B\u306A\
    \u308B)\n    SortableSegmentTree(const size_t num, const TypeNode init) {\n  \
    \      build(num);\n        for (int i = 0; i < length; ++i) leaf[i].insert(i,\
    \ i<num ? init : Monoid::unit_node);\n        for (int i = 0; i < length; ++i)\
    \ node[i+length] = leaf[i].fold_all();\n        for (int i = length - 1; i >=\
    \ 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n    }\n\
    \    //vector\u3067\u521D\u671F\u5316\n    SortableSegmentTree(const vector<TypeSortKey>&\
    \ keys, const vector<TypeNode>& vals) {\n        assert(keys.size() == vals.size());\n\
    \        size_t num = keys.size();\n        build(num);\n        for (int i =\
    \ 0; i < num; ++i) leaf[i].insert(keys[i], vals[i]);\n        for (int i = num;\
    \ i < length; ++i) leaf[i].insert(i, Monoid::unit_node);\n        for (int i =\
    \ 0; i < length; ++i) node[i+length] = leaf[i].fold_all();\n        for (int i\
    \ = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \    }\n    void sort_asc(int l, int r) { sort_impl(l,r,0); }\n    void sort_desc(int\
    \ l, int r) { sort_impl(l,r,1); }\n    //[idx,idx+1)\n    TypeNode get(size_t\
    \ idx) {\n        if(idx < 0 || length <= idx) return Monoid::unit_node;\n   \
    \     prepare_access(idx);\n        sync_leaf(idx);\n        return leaf[idx].kth_smallest(0).second;\n\
    \    }\n    //[idx,idx+1)\n    void operate(size_t idx, const TypeSortKey key,\
    \ const TypeNode val) {\n        if(idx < 0 || length <= idx) return;\n      \
    \  prepare_access(idx); prepare_access(idx+1);\n        auto [old_key, old_val]\
    \ = leaf[idx].kth_smallest(0);\n        leaf[idx] = InnerTreeSet();\n        leaf[idx].insert(key,Monoid::func_operate(old_val,val));\n\
    \        sync_leaf(idx); sync_leaf(idx+1);\n    }\n    //[l,r)\n    TypeNode fold(int\
    \ l, int r) {\n        if (l < 0 || length <= l || r < 0 || length < r) return\
    \ Monoid::unit_node;\n        prepare_access(l), prepare_access(r);\n        sync_leaf(l),\
    \ sync_leaf(r);\n        TypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;\n\
    \        for(l += length, r += length; l < r; l >>=1, r >>=1) {\n            if(l&1)\
    \ vl = Monoid::func_fold(vl,node[l++]);\n            if(r&1) vr = Monoid::func_fold(node[--r],vr);\n\
    \        }\n        return Monoid::func_fold(vl,vr);\n    }\n    void print(){\n\
    \        cout << \"vector\" << endl;\n        // cout << range << endl;\n    \
    \    // cout << \"{ \";\n        // for(int i = 0; i < length; ++i) leaf[i].print(),\
    \ cout << \", \";\n        // cout << \" }\" << endl;\n        cout << \"{ \"\
    ;\n        for(int i = 0; i < length; ++i) cout << leaf[i].fold_all() << \", \"\
    ;\n        cout << \" }\" << endl;\n    }\n};\n#line 1 \"lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n/*\n * @title MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\
    \u6570, \u70B9\u66F4\u65B0]\n * @docs md/operator/monoid/MonoidRangeCompositePointUpdate.md\n\
    \ */\ntemplate<class T> struct MonoidRangeCompositePointUpdate {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unit_node = make_pair(1,0);\n   \
    \ inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    \    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return\
    \ r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n#line 12 \"test/segment-tree/SortableSegmentTree-rcq.test.cpp\"\
    \n\nint main(void){\n     cin.tie(0);ios::sync_with_stdio(false);\n    using Mint\
    \ = ModInt<MOD_998244353>;\n\n    int N; read(N);\n    int Q; read(Q);\n    vector<unsigned\
    \ long long> k(N);\n    vector<pair<Mint,Mint>> v(N);\n    for(int i=0;i<N;++i)\
    \ {\n        int p,a,b; read(p),read(a),read(b);\n        k[i]=p,v[i]={a,b};\n\
    \    }\n    SortableSegmentTree<30UL, MonoidRangeCompositePointUpdate<pair<Mint,Mint>>>\
    \ seg(k,v);\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n \
    \           int i,p,a,b; read(i),read(p),read(a),read(b);\n            seg.operate(i,p,{a,b});\n\
    \        }\n        if(q==1) {\n            int l,r,x; read(l),read(r),read(x);\n\
    \            auto [a,b]=seg.fold(l,r);\n            cout << a*x + b << \"\\n\"\
    ;\n        }\n        if(q==2) {\n            int l,r; read(l),read(r);\n    \
    \        seg.sort_asc(l,r);\n        }\n        if(q==3) {\n            int l,r;\
    \ read(l),read(r);\n            seg.sort_desc(l,r);\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <set>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\
    \n#include \"../../lib/10-segment-tree/SortableSegmentTree.cpp\"\n#include \"\
    ../../lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\n\nint main(void){\n\
    \     cin.tie(0);ios::sync_with_stdio(false);\n    using Mint = ModInt<MOD_998244353>;\n\
    \n    int N; read(N);\n    int Q; read(Q);\n    vector<unsigned long long> k(N);\n\
    \    vector<pair<Mint,Mint>> v(N);\n    for(int i=0;i<N;++i) {\n        int p,a,b;\
    \ read(p),read(a),read(b);\n        k[i]=p,v[i]={a,b};\n    }\n    SortableSegmentTree<30UL,\
    \ MonoidRangeCompositePointUpdate<pair<Mint,Mint>>> seg(k,v);\n    while(Q--)\
    \ {\n        int q; read(q);\n        if(q==0) {\n            int i,p,a,b; read(i),read(p),read(a),read(b);\n\
    \            seg.operate(i,p,{a,b});\n        }\n        if(q==1) {\n        \
    \    int l,r,x; read(l),read(r),read(x);\n            auto [a,b]=seg.fold(l,r);\n\
    \            cout << a*x + b << \"\\n\";\n        }\n        if(q==2) {\n    \
    \        int l,r; read(l),read(r);\n            seg.sort_asc(l,r);\n        }\n\
    \        if(q==3) {\n            int l,r; read(l),read(r);\n            seg.sort_desc(l,r);\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/10-segment-tree/SortableSegmentTree.cpp
  - lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp
  isVerificationFile: true
  path: test/segment-tree/SortableSegmentTree-rcq.test.cpp
  requiredBy: []
  timestamp: '2023-07-05 23:24:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree/SortableSegmentTree-rcq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SortableSegmentTree-rcq.test.cpp
- /verify/test/segment-tree/SortableSegmentTree-rcq.test.cpp.html
title: test/segment-tree/SortableSegmentTree-rcq.test.cpp
---
