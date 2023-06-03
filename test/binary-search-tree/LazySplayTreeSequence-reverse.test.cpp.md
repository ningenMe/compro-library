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
    path: lib/12-binary-search-tree/LazySplayTreeSequence.cpp
    title: "LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217"
  - icon: ':heavy_check_mark:'
    path: lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
    title: "MonoidRangeFoldSumRangeOperateAffine - fold:\u533A\u9593\u548C, operate:\u533A\
      \u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
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
    \ = 1'000'000'000LL + 7; //'\n#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
    \n/*\n * @title MonoidRangeFoldSumRangeOperateAffine - fold:\u533A\u9593\u548C\
    , operate:\u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAffine.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateAffine {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = {1,0};\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ {new_lazy.first*old_lazy.first,new_lazy.first*old_lazy.second+new_lazy.second};}\n\
    \tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return {node*lazy.first+lazy.second*(r-l)};}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n\
    #line 1 \"lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n/*\n * @title\
    \ LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217\n * @docs md/binary-search-tree/LazySplayTreeSequence.md\n\
    \ */\ntemplate<class Monoid> class LazySplayTreeSequence {\n    using TypeNode\
    \ = typename Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n\
    \    struct Node {\n    private:\n        void build() {left = right = nullptr;size\
    \ = 1;rev=0;range_lazy = Monoid::unit_lazy;}\n    public:\n        Node *left,\
    \ *right, *parent;\n        TypeNode value, range_value;\n        TypeLazy range_lazy;\n\
    \        int size,rev;\n        Node() : value(Monoid::unit_node), range_value(Monoid::unit_node),\
    \ parent(parent) {build();}\n        Node(const TypeNode v) : value(v),range_value(v)\
    \ {build();}\n        friend ostream &operator<<(ostream &os, const Node* node)\
    \ {return os << \"{\" << node->value << \", \" << node->size << \"}\";}\n    };\n\
    \    Node* root;\n    int size(Node *node) {return node==nullptr ? 0 : node->size;}\n\
    \    TypeNode range_value(Node *node) {return node==nullptr ? Monoid::unit_node\
    \ : node->range_value;}\n    void update(Node *node) {\n        if(node==nullptr)\
    \ return;\n\t\tif(node->left != nullptr) propagate(node->left);\n\t\tif(node->right\
    \ != nullptr) propagate(node->right);\n        node->size = size(node->left) +\
    \ size(node->right) + 1;\n        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \    }\n    void propagate(Node *node) {\n        if(node==nullptr || (node->range_lazy\
    \ == Monoid::unit_lazy && node->rev == 0)) return;\n        node->range_value\
    \ = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n \
    \       node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\
    \        if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy),\
    \ node->left->rev ^= node->rev;\n        if(node->right!=nullptr) node->right->range_lazy\
    \ = Monoid::func_lazy(node->right->range_lazy,node->range_lazy), node->right->rev\
    \ ^= node->rev;\n        if(node->rev) swap(node->left,node->right), node->rev\
    \ = 0;\n        node->range_lazy = Monoid::unit_lazy;\n    }\n    void rotate_left(Node*\
    \ node){\n        Node* parent = node->parent;\n        if(parent->parent == nullptr)\
    \ root = node;\n        else if (parent->parent->left == parent) parent->parent->left\
    \ = node;\n        else parent->parent->right = node;\n\n        node->parent\
    \ = parent->parent;\n        parent->parent = node;\n        if(node->left !=\
    \ nullptr) node->left->parent = parent; \n        parent->right = node->left;\n\
    \        node->left = parent;\n    }\n    void rotate_right(Node* node){\n   \
    \     Node* parent = node->parent;\n        if(parent->parent == nullptr) root\
    \ = node;\n        else if (parent->parent->left == parent) parent->parent->left\
    \ = node;\n        else parent->parent->right = node;\n\n        node->parent\
    \ = parent->parent;\n        parent->parent = node;\n        if(node->right !=\
    \ nullptr) node->right->parent = parent; \n        parent->left = node->right;\n\
    \        node->right = parent;\n    }\n    void splay(Node* node){\n        propagate(node);\n\
    \        while(node->parent != nullptr){\n            Node* parent = node->parent;\n\
    \            Node* grand_parent = parent->parent;\n            propagate(grand_parent);\n\
    \            propagate(parent);\n            propagate(node);\n            if(parent->left\
    \ == node){\n                if(grand_parent == nullptr){ rotate_right(node);\
    \ }\n                else if(grand_parent->left  == parent){ rotate_right(parent);\
    \ rotate_right(node); }\n                else if(grand_parent->right == parent){\
    \ rotate_right(node); rotate_left(node); }\n            }\n            else{\n\
    \                if(grand_parent == nullptr){ rotate_left(node); }\n         \
    \       else if(grand_parent->left  == parent){ rotate_left(node); rotate_right(node);\
    \ }\n                else if(grand_parent->right == parent){ rotate_left(parent);\
    \ rotate_left(node); }\n            }\n            update(grand_parent);\n   \
    \         update(parent);\n            update(node);\n        }\n        update(node);\n\
    \    }\n    Node* get_impl(size_t k) {\n        Node* node = root;\n        while(1)\
    \ {\n            propagate(node);\n            if(size(node->left) == k) break;\n\
    \            if(size(node->left) > k) {\n                node = node->left;\n\
    \            }\n            else {\n                k -= size(node->left) + 1;\n\
    \                node = node->right;\n            }\n        }\n        propagate(node);\
    \ //\u3044\u3089\u306A\u3055\u305D\u3046\uFF1F\n        splay(node);\n       \
    \ return node;\n    }\n    //[l,r)\n    Node* get_range_impl(const size_t l, const\
    \ size_t r) {\n        if(r-l==size(root)) return root;\n        if(l==0) return\
    \ get_impl(r)->left; //r-1?\n        if(r==size(root)) return get_impl(l-1)->right;\n\
    \        Node* target_right = get_impl(r);\n        Node* target_left = target_right->left;\n\
    \        root = target_left;\n\n        target_left->parent = nullptr;\n     \
    \   target_left = get_impl(l-1);\n        root=target_right;\n\n        target_right->left=target_left;\n\
    \        target_left->parent=target_right;\n        update(target_right);\n  \
    \      return target_left->right;\n    }\n    void insert_impl(const size_t k,\
    \ const TypeNode value) {\n        Node* node = new Node(value);\n        if(k\
    \ == 0){\n            node->right = root;\n            if(root != nullptr) root->parent\
    \ = node;\n            root = node;\n            update(node);\n            return;\n\
    \        }\n        if(k == size(root)){\n            node->left = root;\n   \
    \         root->parent = node;\n            root = node;\n            update(node);\n\
    \            return;\n        }\n        Node* target = get_impl(k);\n       \
    \ node->left = target->left;\n        node->right = target;\n        root = node;\n\
    \        target->left->parent = node;\n        target->parent = node;\n      \
    \  target->left = nullptr;\n        update(target);\n        update(node);\n \
    \   }\n    void erase_impl(const size_t k){\n        Node* target = get_impl(k);\n\
    \        if(k == 0){\n            root = target->right;\n            if(root !=\
    \ nullptr) root->parent = nullptr;\n        }\n        else if(k+1 == size(root)){\n\
    \            root = target->left;\n            if(root != nullptr) root->parent\
    \ = nullptr;\n        }\n        else{\n            Node* target_left = target->left;\n\
    \            Node* target_right = target->right;\n            target_right->parent\
    \ = nullptr;\n            root = target_right;\n            get_impl(0);\n   \
    \         target_right = root;  \n            target_right->left = target_left;\n\
    \            target_left->parent = target_right;\n            update(target_right);\n\
    \        }\n    }\n    void operate_impl(int l, int r, TypeLazy lazy) {\n    \
    \    if(l < 0 || size(root) <= l || r <= 0 || r-l <= 0) return;\n        Node*\
    \ node=get_range_impl(l,r);\n        node->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n\
    \t\tpropagate(node);\n        splay(node);\n    }\n    inline TypeNode fold_impl(int\
    \ l, int r) {\n        if (l < 0 || size(root) <= l || r<=0 || r-l <= 0) return\
    \ Monoid::unit_node;\n\t\tNode* node=get_range_impl(l,r);\n\t\tpropagate(node);\n\
    \t\tupdate(node);\n        return range_value(node);\n    }\n    void reverse_impl(int\
    \ l, int r) {\n        if (l < 0 || size(root) <= l || r<=0 || r-l <= 0) return;\n\
    \        Node* node=get_range_impl(l,r);\n        node->rev ^= 1;\n        splay(node);\n\
    \    }\n    void print_impl() {\n        int M=5;\n        vector<vector<Node*>>\
    \ vv(M);\n        vv[0].push_back(root);\n        for(int i=0;i+1<M;++i) {\n \
    \           for(int j=0;j<vv[i].size();++j) {\n                auto le = (vv[i][j]==nullptr\
    \ ? nullptr : vv[i][j]->left);\n                auto ri = (vv[i][j]==nullptr ?\
    \ nullptr : vv[i][j]->right);\n                vv[i+1].push_back(le);\n      \
    \          vv[i+1].push_back(ri);\n            }\n        }\n        for(int i=0;i<M;++i)\
    \ {\n            int MM = vv[i].size();\n            for(int j=0;j<MM;++j) {\n\
    \t\t\t\tif(vv[i][j]==nullptr) {\n\t\t\t\t\tcout << \"{:},\";\n\t\t\t\t}\n\t\t\t\
    \telse {\n\t\t\t\t\tcout << \"{\" << vv[i][j]->value << \":\" << vv[i][j]->range_lazy\
    \ << \"}, \";\n\t\t\t\t}\n            }\n            cout << endl;\n        }\n\
    \    }\npublic:\n    LazySplayTreeSequence(): root(nullptr) {}\n    TypeNode get(const\
    \ size_t k) {return get_impl(k)->value; }\n    int size() {return size(root);\
    \ }\n    void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n\
    \    void erase(const size_t k) { erase_impl(k);}\n    inline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {propagate(this->root); operate_impl(l,r,lazy);}\n\
    \    inline TypeNode fold(int l, int r) {return fold_impl(l,r);}\n    inline void\
    \ reverse(int l, int r) {reverse_impl(l,r);}\n    void print() {print_impl();}\n\
    };\n#line 12 \"test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp\"\
    \n\nusing modint = ModInt<MOD_998244353>;\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; read(N); read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>>\
    \ st;\n    for(int i=0;i<N;++i) {\n        int a; read(a); st.insert(i,a);\n \
    \   }\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n       \
    \     int i,x; read(i); read(x);\n            st.insert(i,x);\n        }\n   \
    \     if(q==1) {\n            int i; read(i);\n            st.erase(i);\n    \
    \    }\n\t\tif(q==2) {\n\t\t\tint l,r; read(l); read(r);\n\t\t\tst.reverse(l,r);\n\
    \t\t}\n\t\tif(q==3) {\n\t\t\tint l,r,b,c; read(l); read(r); read(b); read(c);\n\
    \t\t\tst.operate(l,r,{b,c});\n\t\t}\n        if(q==4) {\n            int l,r;\
    \ read(l); read(r);\n            cout << st.fold(l,r) << \"\\n\";\n        }\n\
    \    }\n    return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\
    \n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n\nusing\
    \ modint = ModInt<MOD_998244353>;\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; read(N); read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>>\
    \ st;\n    for(int i=0;i<N;++i) {\n        int a; read(a); st.insert(i,a);\n \
    \   }\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n       \
    \     int i,x; read(i); read(x);\n            st.insert(i,x);\n        }\n   \
    \     if(q==1) {\n            int i; read(i);\n            st.erase(i);\n    \
    \    }\n\t\tif(q==2) {\n\t\t\tint l,r; read(l); read(r);\n\t\t\tst.reverse(l,r);\n\
    \t\t}\n\t\tif(q==3) {\n\t\t\tint l,r,b,c; read(l); read(r); read(b); read(c);\n\
    \t\t\tst.operate(l,r,{b,c});\n\t\t}\n        if(q==4) {\n            int l,r;\
    \ read(l); read(r);\n            cout << st.fold(l,r) << \"\\n\";\n        }\n\
    \    }\n    return 0;\n}\n\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
  - lib/12-binary-search-tree/LazySplayTreeSequence.cpp
  isVerificationFile: true
  path: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
  requiredBy: []
  timestamp: '2023-06-03 10:09:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
- /verify/test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp.html
title: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
---
