---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
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
    \    struct Node {\n    public:\n        Node *left, *right;\n        TypeNode\
    \ value, range_value;\n        TypeLazy range_lazy;\n        int rev;\n      \
    \  int size;\n        Node(const TypeNode v) : left(nullptr),right(nullptr),value(v),range_value(v),range_lazy(Monoid::unit_lazy),size(1),rev(0)\
    \ {}\n        friend ostream &operator<<(ostream &os, const Node* node) {return\
    \ os << \"{\" << node->value << \", \" << node->size << \"}\";}\n    };\n    struct\
    \ TupleNode {\n        Node *left, *center, *right;\n        TupleNode(Node *left,Node\
    \ *center,Node *right) : left(left), center(center), right(right) {}\n    };\n\
    \    Node* root;\n    inline int size(Node *node) {return node==nullptr ? 0 :\
    \ node->size;}\n    inline TypeNode range_value(Node *node) {return node==nullptr\
    \ ? Monoid::unit_node : node->range_value;}\n    inline void update(Node *node)\
    \ {\n        node->size = 1;\n        node->range_value = node->value;\n\t\tif(node->left\
    \ != nullptr) {\n            node->size = node->left->size + node->size;\n   \
    \         node->range_value = Monoid::func_fold(node->left->range_value, node->range_value);\n\
    \        }\n\t\tif(node->right != nullptr) {\n            node->size = node->size\
    \ + node->right->size;\n            node->range_value = Monoid::func_fold(node->range_value,\
    \ node->right->range_value);\n        }\n    }\n    inline void propagate(Node\
    \ *node) {\n        if(node==nullptr) return;\n        if(node->range_lazy !=\
    \ Monoid::unit_lazy) {\n            if(node->left  != nullptr) sync_lazy(node->left,\
    \ node->range_lazy);\n            if(node->right != nullptr) sync_lazy(node->right,\
    \ node->range_lazy);\n            node->range_lazy = Monoid::unit_lazy;\n    \
    \    }\n        if(node->rev) {\n            if(node->left  != nullptr) sync_rev(node->left);\n\
    \            if(node->right != nullptr) sync_rev(node->right);\n            node->rev\
    \ = 0;\n        }\n    }\n    inline void sync_lazy(Node *node, const TypeLazy\
    \ lazy) {\n        node->range_lazy = Monoid::func_lazy(node->range_lazy, lazy);\n\
    \        node->value = Monoid::func_operate(node->value, lazy, 0,1);\n       \
    \ node->range_value = Monoid::func_operate(node->range_value, lazy, 0, node->size);\n\
    \    }\n    inline void sync_rev(Node *node) {\n        swap(node->left, node->right);\n\
    \        node->rev ^= 1;\n    }\n    inline Node* rotate_left(Node* node){\n \
    \       Node* right = node->right;\n        node->right = right->left;\n     \
    \   right->left = node;\n        update(node);\n        update(right);\n     \
    \   return right;\n    }\n    inline Node* rotate_right(Node* node){\n       \
    \ Node* left = node->left;\n        node->left = left->right;\n        left->right\
    \ = node;\n        update(node);\n        update(left);\n        return left;\n\
    \    }\n\n    inline Node* splay(Node* node, size_t k){\n        propagate(node);\n\
    \        size_t sz_l = size(node->left);\n        if(k == sz_l) return node;\n\
    \        if(k < sz_l) {\n            node->left = splay(node->left, k);\n    \
    \        node = rotate_right(node);\n        }\n        else {\n            node->right\
    \ = splay(node->right, k - sz_l - 1);\n            node = rotate_left(node);\n\
    \        }\n        update(node);\n        return node;\n    }\n\n    //\u975E\
    \u518D\u5E30\u306F\u9045\u304B\u3063\u305F\n    // stack<pair<Node*, size_t>>\
    \ st;\n    // inline Node* splay(Node* node, size_t k){\n    //     Node* t_node\
    \ = node;\n    //     Node* last = nullptr;\n    //     while(last == nullptr)\
    \ {\n    //         propagate(t_node);\n    //         size_t sz_l = size(t_node->left);\n\
    \    //         if(k == sz_l) {\n    //             last = t_node;\n    //   \
    \          continue;\n    //         }\n    //         if(k < sz_l) {\n    //\
    \             st.emplace(t_node, 1);\n    //             t_node = t_node->left;\n\
    \    //         }\n    //         else {\n    //             st.emplace(t_node,\
    \ 0);\n    //             t_node = t_node->right;\n    //             k = (k -\
    \ sz_l - 1);\n    //         }\n    //     }\n    //     while(st.size()) {\n\
    \    //         auto [t_node,is_left] = st.top(); st.pop();\n    //         if(is_left)\
    \ {\n    //             t_node->left = last;\n    //             t_node = rotate_right(t_node);\n\
    \    //         }\n    //         else {\n    //             t_node->right = last;\n\
    \    //             t_node = rotate_left(t_node);\n    //         }\n    //  \
    \       update(t_node);\n    //         last = t_node;\n    //     }\n    // \
    \    return last;\n    // }\n\n    //    - parent\n    //   |\n    // left\n \
    \   //\u306E\u5F62\u3067\u30DE\u30FC\u30B8\n    Node* merge(Node* left, Node*\
    \ parent) {\n        if(left == nullptr) return parent;\n        if(parent ==\
    \ nullptr) return left;\n        parent = splay(parent, 0);\n        parent->left\
    \ = left;\n        update(parent);\n        return parent;\n    }\n    Node* merge(TupleNode*\
    \ tuple_node) {\n        Node* node = merge(tuple_node->center, tuple_node->right);\n\
    \        if(tuple_node->left == nullptr) return node;\n        tuple_node->left->right\
    \ = node;\n        update(tuple_node->left);\n        return tuple_node->left;\n\
    \    }\n    // [0,k),[k,n) \u3067split\n    pair<Node*,Node*> split(Node* node,\
    \ size_t k) {\n        if(k >= size(node)) return {node, nullptr};\n        Node*\
    \ right = splay(node, k);\n        Node* left = right->left;\n        right->left\
    \ = nullptr;\n        update(right);\n        return {left, right};\n    }\n \
    \   //[0,l),[l,r),[r,n) \u3067split\n    TupleNode* split(Node* node, size_t l,\
    \ size_t r) {\n        if(!l) {\n            auto [center,right] = split(node,\
    \ r);\n            return new TupleNode(nullptr, center, right);\n        }\n\
    \        Node* left = splay(node, l-1);\n        auto [center, right] = split(left->right,\
    \ r-l);\n        left->right = nullptr;\n        update(left);\n        return\
    \ new TupleNode(left, center, right);\n    }\n    void insert_impl(const size_t\
    \ k, const TypeNode value) {\n        Node* new_node = new Node(value);\n    \
    \    if(k == size(root)){\n            new_node->left = root;\n            update(new_node);\n\
    \            root = new_node;\n            return;\n        }\n        if(k ==\
    \ 0){\n            new_node->right = root;\n            update(new_node);\n  \
    \          root = new_node;\n            return;\n        }\n        Node* node\
    \ = splay(root, k);\n        new_node->left = node->left;\n        node->left\
    \ = new_node;\n        update(new_node);\n        update(node);\n        root\
    \ = node;\n        return;\n    }\n    void erase_impl(const size_t k){\n    \
    \    Node* node = splay(root, k);\n        root = merge(node->left,node->right);\n\
    \    }\n    TypeNode fold_impl(int l, int r) {\n        if (l < 0 || size(root)\
    \ <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\t\tTupleNode* tuple_node\
    \ = split(root,l,r);\n        TypeNode res = tuple_node->center->range_value;\n\
    \        root = merge(tuple_node);\n        return res;\n    }\n    void operate_impl(int\
    \ l, int r, TypeLazy lazy) {\n        if(l < 0 || size(root) <= l || r <= 0 ||\
    \ r-l <= 0) return;\n\t\tTupleNode* tuple_node = split(root,l,r);\n        sync_lazy(tuple_node->center,\
    \ lazy);\n        root = merge(tuple_node);\n    }\n    void reverse_impl(int\
    \ l, int r) {\n        if (l < 0 || size(root) <= l || r<=0 || r-l <= 0) return;\n\
    \t\tTupleNode* tuple_node = split(root,l,r);\n        sync_rev(tuple_node->center);\n\
    \        root = merge(tuple_node);\n    }\n    void print_impl() {\n        size_t\
    \ N = size(root);\n        for(int i=0;i<N;++i) cout << get(i) << \" \";\n   \
    \     cout << endl;\n    }\npublic:\n    LazySplayTreeSequence(): root(nullptr)\
    \ {}\n    inline TypeNode get(const size_t k) {root = splay(root , k); return\
    \ root->value; }\n    inline int size() {return size(root); }\n    inline void\
    \ insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n    inline\
    \ void erase(const size_t k) { erase_impl(k);}\n    inline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {operate_impl(l,r,lazy);}\n    inline\
    \ TypeNode fold(int l, int r) {return fold_impl(l,r); }\n    inline void reverse(int\
    \ l, int r) {reverse_impl(l,r);}\n    void print() {print_impl();}\n};\n#line\
    \ 12 \"test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp\"\n\nusing\
    \ modint = ModInt<MOD_998244353>;\n\nint main(void){\n \tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; \n\tread(N); read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>>\
    \ st;\n    for(int i = 0; i < N; ++i) {\n        int a; read(a); st.insert(i,a);\n\
    \    }\n    while(Q--){\n        int q,l,r; \n\t\tread(q); read(l); read(r);\n\
    \        if(q) {\n\t\t\tcout << st.fold(l,r) << \"\\n\";\n\t\t}\n        else\
    \ {\n\t\t\tint b,c; read(b); read(c);\n\t\t\tst.operate(l,r,{modint(b),modint(c)});\n\
    \t\t}\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\
    \n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n\nusing\
    \ modint = ModInt<MOD_998244353>;\n\nint main(void){\n \tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; \n\tread(N); read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>>\
    \ st;\n    for(int i = 0; i < N; ++i) {\n        int a; read(a); st.insert(i,a);\n\
    \    }\n    while(Q--){\n        int q,l,r; \n\t\tread(q); read(l); read(r);\n\
    \        if(q) {\n\t\t\tcout << st.fold(l,r) << \"\\n\";\n\t\t}\n        else\
    \ {\n\t\t\tint b,c; read(b); read(c);\n\t\t\tst.operate(l,r,{modint(b),modint(c)});\n\
    \t\t}\n    }\n}\n\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
  - lib/12-binary-search-tree/LazySplayTreeSequence.cpp
  isVerificationFile: true
  path: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 05:58:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
- /verify/test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp.html
title: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
---
