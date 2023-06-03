---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp
    title: "LazyRandomizedBinarySearchTreeSequence - \u9045\u5EF6\u8A55\u4FA1\u30E9\
      \u30F3\u30C0\u30E0\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\u5217"
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
  bundledCode: "#line 1 \"test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#line 1 \"lib/00-util/ModInt.cpp\"\n/*\n * @title ModInt\n\
    \ * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt {\npublic:\n\
    \    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr ModInt(long long\
    \ y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    constexpr ModInt &operator+=(const\
    \ ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt\
    \ &operator+=(const long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    constexpr ModInt &operator+=(const int y) {ModInt p(y);if((x +=\
    \ p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr\
    \ ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod)\
    \ x -= mod;return *this;}\n    constexpr ModInt &operator-=(const int y) {ModInt\
    \ p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt\
    \ &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n    constexpr\
    \ ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    constexpr ModInt &operator*=(const int y) {ModInt p(y);x = (x *\
    \ p.x % mod);return *this;}\n    constexpr ModInt &operator^=(const ModInt &p)\
    \ {x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const\
    \ long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    constexpr\
    \ ModInt &operator^=(const int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n\
    \    constexpr ModInt &operator/=(const ModInt &p) {*this *= p.inv();return *this;}\n\
    \    constexpr ModInt &operator/=(const long long y) {ModInt p(y);*this *= p.inv();return\
    \ *this;}\n    constexpr ModInt &operator/=(const int y) {ModInt p(y);*this *=\
    \ p.inv();return *this;}\n    constexpr ModInt operator=(const int y) {ModInt\
    \ p(y);*this = p;return *this;}\n    constexpr ModInt operator=(const long long\
    \ y) {ModInt p(y);*this = p;return *this;}\n    constexpr ModInt operator-() const\
    \ {return ModInt(-x); }\n    constexpr ModInt operator++() {x++;if(x>=mod) x-=mod;return\
    \ *this;}\n    constexpr ModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n\
    \    constexpr ModInt operator+(const ModInt &p) const { return ModInt(*this)\
    \ += p; }\n    constexpr ModInt operator-(const ModInt &p) const { return ModInt(*this)\
    \ -= p; }\n    constexpr ModInt operator*(const ModInt &p) const { return ModInt(*this)\
    \ *= p; }\n    constexpr ModInt operator/(const ModInt &p) const { return ModInt(*this)\
    \ /= p; }\n    constexpr ModInt operator^(const ModInt &p) const { return ModInt(*this)\
    \ ^= p; }\n    constexpr bool operator==(const ModInt &p) const { return x ==\
    \ p.x; }\n    constexpr bool operator!=(const ModInt &p) const { return x != p.x;\
    \ }\n    // ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a /\
    \ b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n    constexpr\
    \ ModInt inv() const {int a=x,b=mod,u=1,v=0,t=0,tmp=0;while(b > 0) {t = a / b;a-=t*b;tmp=a;a=b;b=tmp;u-=t*v;tmp=u;u=v;v=tmp;}\
    \ return ModInt(u);}\n    constexpr ModInt pow(long long n) const {ModInt ret(1),\
    \ mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n  \
    \  friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}\n\
    \    friend istream &operator>>(istream &is, ModInt &a) {long long t;is >> t;a\
    \ = ModInt<mod>(t);return (is);}\n};\nconstexpr long long MOD_998244353 = 998244353;\n\
    constexpr long long MOD_1000000007 = 1'000'000'000LL + 7; //'\n#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
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
    #line 1 \"lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp\"\
    \n/*\n * @title LazyRandomizedBinarySearchTreeSequence - \u9045\u5EF6\u8A55\u4FA1\
    \u30E9\u30F3\u30C0\u30E0\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\u5217\n * @docs\
    \ md/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.md\n */\ntemplate<class\
    \ Monoid> class LazyRandomizedBinarySearchTreeSequence {\n    using TypeNode =\
    \ typename Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n\
    \    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\
    \    unsigned int xor_shift() {\n        unsigned int t = (x ^ (x << 11)); x =\
    \ y; y = z; z = w;\n        return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n \
    \   }\n    struct Node {\n    private:\n        void build() {left = right = nullptr;size\
    \ = 1; rev=0; range_lazy = Monoid::unit_lazy;}\n    public:\n        Node *left,\
    \ *right;\n        TypeNode value, range_value;\n        TypeLazy range_lazy;\n\
    \        int size,rev;\n        Node() : value(Monoid::unit_node), range_value(Monoid::unit_node)\
    \ {build();}\n        Node(TypeNode v) : value(v), range_value(v) {build();}\n\
    \        friend ostream &operator<<(ostream &os, const Node* node) {return os\
    \ << \"{\" << node->value << \", \" << node->range_value << \", \" << node->range_lazy\
    \ << \", \" << node->size << \"}\";}\n    };\n    Node* root;\n    inline int\
    \ size(Node *node) {return node==nullptr ? 0 : node->size;}\n    inline TypeNode\
    \ range_value(Node *node) {return node==nullptr ? Monoid::unit_node : node->range_value;}\n\
    \    inline TypeNode get(Node *node, size_t k) {\n        if (node==nullptr) return\
    \ Monoid::unit_node;\n        propagate(node);\n        if (k == size(node->left))\
    \ return node->value;\n        if (k < size(node->left)) return get(node->left,\
    \ k);\n        else return get(node->right, k-1 - size(node->left));\n    }\n\
    \    inline Node* update(Node *node) {\n        node->size = size(node->left)\
    \ + size(node->right) + 1;\n        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \        return node;\n    }\n    inline void propagate(Node *node) {\n      \
    \  if(node==nullptr || (node->range_lazy == Monoid::unit_lazy && node->rev ==\
    \ 0)) return;\n        node->range_value = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n\
    \        node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\
    \        if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy),\
    \ node->left->rev ^= node->rev;\n        if(node->right!=nullptr) node->right->range_lazy\
    \ = Monoid::func_lazy(node->right->range_lazy,node->range_lazy), node->right->rev\
    \ ^= node->rev;\n        if(node->rev) swap(node->left,node->right), node->rev\
    \ = 0;\n        node->range_lazy = Monoid::unit_lazy;\n    }\n    inline Node*\
    \ merge_impl(Node *left, Node *right) {\n        propagate(left);\n        propagate(right);\n\
    \        if (left==nullptr)  return right;\n        if (right==nullptr) return\
    \ left;\n        if (xor_shift() % (left->size + right->size) < left->size) {\n\
    \            left->right = merge_impl(left->right, right);\n            return\
    \ update(left);\n        }\n        else {\n            right->left = merge_impl(left,\
    \ right->left);\n            return update(right);\n        }\n    }\n    inline\
    \ pair<Node*, Node*> split_impl(Node* node, int k) {\n        if (node==nullptr)\
    \ return make_pair(nullptr, nullptr);\n        propagate(node);\n        if (k\
    \ <= size(node->left)) {\n            propagate(node->right);\n            pair<Node*,\
    \ Node*> sub = split_impl(node->left, k);\n            node->left = sub.second;\n\
    \            return make_pair(sub.first, update(node));\n        }\n        else\
    \ {\n            propagate(node->left);\n            pair<Node*, Node*> sub =\
    \ split_impl(node->right, k - 1 - size(node->left));\n            node->right\
    \ = sub.first;\n            return make_pair(update(node), sub.second);\n    \
    \    }\n    }\n    inline TypeNode fold_impl(Node *node, int l, int r) {\n   \
    \     if (l < 0 || size(node) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\
    \        propagate(node);\n        if (l == 0 && r == size(node)) return range_value(node);\n\
    \        TypeNode value = Monoid::unit_node;\n        int sl = size(node->left);\n\
    \        if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));\n\
    \        l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));\n\
    \        return value;\n    }\n    inline void operate_impl(Node *node, int l,\
    \ int r, TypeLazy lazy) {\n        if(l < 0 || size(node) <= l || r <= 0 || r-l\
    \ <= 0) return;\n        if (l == 0 && r == size(node)) {\n            node->range_lazy\
    \ = Monoid::func_lazy(node->range_lazy,lazy);\n            propagate(node);\n\
    \            return;\n        }\n        int sl = size(node->left);\n        propagate(node->left);\n\
    \        propagate(node->right);\n        if(sl > l) operate_impl(node->left,l,min(sl,r),lazy);\n\
    \        l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) node->value =\
    \ Monoid::func_operate(node->value,lazy,0,1);\n        l = max(l-1,0), r -= 1;\n\
    \        if(l >= 0 && r > l) operate_impl(node->right,l,r,lazy);\n        update(node);\n\
    \    }\n    inline void reverse_impl(int l, int r) {\n        if(l < 0 || size(root)\
    \ <= l || r <= 0 || r-l <= 0) return;\n        pair<Node*,Node*> tmp1 = split_impl(this->root,l);\n\
    \        pair<Node*,Node*> tmp2 = split_impl(tmp1.second,r-l);\n        Node*\
    \ nl = tmp1.first;\n        Node* nc = tmp2.first;\n        Node* nr = tmp2.second;\n\
    \        nc->rev ^= 1;\n        this->root = merge_impl(merge_impl(nl,nc),nr);\n\
    \    }\n    inline void insert_impl(const size_t k, const TypeNode value) {\n\
    \        pair<Node*, Node*> sub = split_impl(this->root, k);\n        this->root\
    \ = this->merge_impl(this->merge_impl(sub.first, new Node(value)), sub.second);\n\
    \    }\n    inline void erase_impl(const size_t k) {\n        if(size(this->root)\
    \ <= k) return;\n        auto sub = split_impl(this->root,k);\n        this->root\
    \ = merge_impl(sub.first, split_impl(sub.second, 1).second);\n    }\npublic:\n\
    \    LazyRandomizedBinarySearchTreeSequence() : root(nullptr) {}\n    inline int\
    \ size() {return size(this->root);}\n    inline int empty(void) {return bool(size()==0);}\n\
    \    inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}\n\
    \    inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}\n\
    \    inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n\
    \    inline void erase(const size_t k) {erase_impl(k);}\n    inline TypeNode get(size_t\
    \ k) {return get(this->root, k);}\n    inline void operate(const int l, const\
    \ int r, const TypeLazy lazy) {propagate(this->root); operate_impl(this->root,l,r,lazy);}\n\
    \    inline TypeNode fold(int l, int r) {return fold_impl(this->root,l,r);}\n\
    \    inline void reverse(int l, int r) {reverse_impl(l,r);}\n    void print()\
    \ {int m = size(this->root); for(int i=0;i<m;++i) cout << get(i) << \" \\n\"[i==m-1];}\n\
    };\n#line 11 \"test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp\"\
    \n\nusing modint = ModInt<998244353>;\n\nint main(void){\n    int N,Q;\n\tscanf(\"\
    %d %d\",&N,&Q);\n\tLazyRandomizedBinarySearchTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>\
    \ > rbst;\n    for(int i=0;i<N;++i) {\n\t\tint a; cin >> a;\n\t\trbst.insert(i,a);\n\
    \    }\n    while(Q--) {\n        int q;\n\t\tscanf(\"%d\",&q);\n\t\tif(q==0)\
    \ {\n\t\t\tint i,x;\n\t\t\tscanf(\"%d %d\",&i,&x);\n\t\t\trbst.insert(i,x);\n\t\
    \t}\n\t\tif(q==1) {\n\t\t\tint i;\n\t\t\tscanf(\"%d\",&i);\n\t\t\trbst.erase(i);\n\
    \t\t}\n\t\tif(q==2) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\trbst.reverse(l,r);\n\
    \t\t}\n\t\tif(q==3) {\n\t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d %d %d %d\",&l,&r,&b,&c);\n\
    \t\t\trbst.operate(l,r,{b,c});\n\t\t}\n\t\tif(q==4) {\n\t\t\tint l,r;\n\t\t\t\
    scanf(\"%d %d\",&l,&r);\n\t\t\tprintf(\"%lld\\n\",rbst.fold(l,r).x);\n\t\t}\n\
    \    }\n    return 0; \n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/00-util/ModInt.cpp\"\n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp\"\
    \n\nusing modint = ModInt<998244353>;\n\nint main(void){\n    int N,Q;\n\tscanf(\"\
    %d %d\",&N,&Q);\n\tLazyRandomizedBinarySearchTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>\
    \ > rbst;\n    for(int i=0;i<N;++i) {\n\t\tint a; cin >> a;\n\t\trbst.insert(i,a);\n\
    \    }\n    while(Q--) {\n        int q;\n\t\tscanf(\"%d\",&q);\n\t\tif(q==0)\
    \ {\n\t\t\tint i,x;\n\t\t\tscanf(\"%d %d\",&i,&x);\n\t\t\trbst.insert(i,x);\n\t\
    \t}\n\t\tif(q==1) {\n\t\t\tint i;\n\t\t\tscanf(\"%d\",&i);\n\t\t\trbst.erase(i);\n\
    \t\t}\n\t\tif(q==2) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\trbst.reverse(l,r);\n\
    \t\t}\n\t\tif(q==3) {\n\t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d %d %d %d\",&l,&r,&b,&c);\n\
    \t\t\trbst.operate(l,r,{b,c});\n\t\t}\n\t\tif(q==4) {\n\t\t\tint l,r;\n\t\t\t\
    scanf(\"%d %d\",&l,&r);\n\t\t\tprintf(\"%lld\\n\",rbst.fold(l,r).x);\n\t\t}\n\
    \    }\n    return 0; \n}\n\n"
  dependsOn:
  - lib/00-util/ModInt.cpp
  - lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
  - lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp
  isVerificationFile: true
  path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
  requiredBy: []
  timestamp: '2023-06-03 17:08:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp.html
title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
---
