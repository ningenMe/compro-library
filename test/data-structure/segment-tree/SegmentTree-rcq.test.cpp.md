---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/segment-tree/SegmentTree.cpp
    title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp
    title: "MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\u6570\
      , \u70B9\u66F4\u65B0]"
  - icon: ':question:'
    path: lib/util/ModInt.cpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/data-structure/segment-tree/SegmentTree-rcq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#line 1 \"lib/data-structure/segment-tree/SegmentTree.cpp\"\n/*\n * @title\
    \ SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @docs md/data-structure/segment-tree/SegmentTree.md\n */\ntemplate<class\
    \ Monoid> class SegmentTree {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n    vector<pair<int,int>>\
    \ range;\n    inline void build() {\n        for (int i = length - 1; i >= 0;\
    \ --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n        range.resize(2\
    \ * length);\n        for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \        for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \    }\npublic:\n\n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t\
    \ num): num(num) {\n        for (length = 1; length <= num; length *= 2);\n  \
    \      node.resize(2 * length, Monoid::unit_node);\n        build();\n    }\n\n\
    \    //vector\u3067\u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode>\
    \ & vec) : num(vec.size()) {\n        for (length = 1; length <= vec.size(); length\
    \ *= 2);\n        node.resize(2 * length, Monoid::unit_node);\n        for (int\
    \ i = 0; i < vec.size(); ++i) node[i + length] = vec[i];\n        build();\n \
    \   }\n\n    //\u540C\u3058init\u3067\u521D\u671F\u5316\n    SegmentTree(const\
    \ size_t num, const TypeNode init) : num(num) {\n        for (length = 1; length\
    \ <= num; length *= 2);\n        node.resize(2 * length, Monoid::unit_node);\n\
    \        for (int i = 0; i < length; ++i) node[i+length] = init;\n        build();\n\
    \    }\n\n    //[idx,idx+1)\n    void operate(size_t idx, const TypeNode var)\
    \ {\n        if(idx < 0 || length <= idx) return;\n        idx += length;\n  \
    \      node[idx] = Monoid::func_operate(node[idx],var);\n        while(idx >>=\
    \ 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n    }\n\
    \n    //[l,r)\n    TypeNode fold(int l, int r) {\n        if (l < 0 || length\
    \ <= l || r < 0 || length < r) return Monoid::unit_node;\n        TypeNode vl\
    \ = Monoid::unit_node, vr = Monoid::unit_node;\n        for(l += length, r +=\
    \ length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Monoid::func_fold(vl,node[l++]);\n\
    \            if(r&1) vr = Monoid::func_fold(node[--r],vr);\n        }\n      \
    \  return Monoid::func_fold(vl,vr);\n    }\n\n    //range[l,r) return [l,r] search\
    \ max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n    \
    \    assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode ret\
    \ = Monoid::unit_node;\n        size_t off = l;\n        for(size_t idx = l+length;\
    \ idx < 2*length && off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,node[idx]),var))\
    \ {\n                ret = Monoid::func_fold(ret,node[idx]);\n               \
    \ off = range[idx++].second;\n                if(!(idx&1)) idx >>= 1;\n      \
    \      }\n            else{\n                idx <<=1;\n            }\n      \
    \  }\n        return off;\n    }\n\n    //range(l,r] return [l,r] search max left\n\
    \    int suffix_binary_search(const int l, const int r, const TypeNode var) {\n\
    \        assert(-1 <= l && l < (int)length-1 && 0 <= r && r < length);\n     \
    \   TypeNode ret = Monoid::unit_node;\n        int off = r;\n        for(size_t\
    \ idx = r+length; idx < 2*length && l < off; ){\n            if(l < range[idx].first\
    \ && !Monoid::func_check(Monoid::func_fold(node[idx],ret),var)) {\n          \
    \      ret = Monoid::func_fold(node[idx],ret);\n                off = range[idx--].first-1;\n\
    \                if(idx&1) idx >>= 1;\n            }\n            else{\n    \
    \            idx = (idx<<1)+1;\n            }\n        }\n        return off;\n\
    \    }\n\n    void print(){\n        // cout << \"node\" << endl;\n        //\
    \ for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << node[i] << \"\
    \ \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n   \
    \     cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n    \
    \    for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n        cout\
    \ << \" }\" << endl;\n    }\n};\n#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title\
    \ ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt\
    \ {\npublic:\n    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr\
    \ ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    constexpr\
    \ ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n\
    \    constexpr ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x)\
    \ >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator+=(const int\
    \ y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    constexpr\
    \ ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return\
    \ *this;}\n    constexpr ModInt &operator-=(const long long y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n  \
    \  constexpr ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n\
    \    constexpr ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x\
    \ % mod);return *this;}\n    constexpr ModInt &operator*=(const int y) {ModInt\
    \ p(y);x = (x * p.x % mod);return *this;}\n    constexpr ModInt &operator^=(const\
    \ ModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const\
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
    constexpr long long MOD_1000000007 = 1'000'000'000LL + 7; //'\n#line 1 \"lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n/*\n * @title MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\
    \u6570, \u70B9\u66F4\u65B0]\n * @docs md/operator/monoid/MonoidRangeCompositePointUpdate.md\n\
    \ */\ntemplate<class T> struct MonoidRangeCompositePointUpdate {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unit_node = make_pair(1,0);\n   \
    \ inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    \    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return\
    \ r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n#line 10 \"test/data-structure/segment-tree/SegmentTree-rcq.test.cpp\"\
    \n\nusing modint = ModInt<998244353>;\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<pair<modint,modint>> A(N);\n    for(int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].first >> A[i].second;\n    }\n   \
    \ SegmentTree<MonoidRangeCompositePointUpdate<pair<modint,modint>>> seg(A);\n\
    \    while(Q--){\n        long long q,l,r,x; cin >> q >> l >> r >> x;\n      \
    \  if(q) {\n\t\t\tauto p = seg.fold(l,r);\n\t\t\tcout << p.first*x+p.second <<\
    \ endl;\n\t\t}\n        else seg.operate(l,{r,x});\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../../lib/data-structure/segment-tree/SegmentTree.cpp\"\n\
    #include \"../../../lib/util/ModInt.cpp\"\n#include \"../../../lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n\nusing modint = ModInt<998244353>;\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<pair<modint,modint>> A(N);\n    for(int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].first >> A[i].second;\n    }\n   \
    \ SegmentTree<MonoidRangeCompositePointUpdate<pair<modint,modint>>> seg(A);\n\
    \    while(Q--){\n        long long q,l,r,x; cin >> q >> l >> r >> x;\n      \
    \  if(q) {\n\t\t\tauto p = seg.fold(l,r);\n\t\t\tcout << p.first*x+p.second <<\
    \ endl;\n\t\t}\n        else seg.operate(l,{r,x});\n    }\n}\n\n"
  dependsOn:
  - lib/data-structure/segment-tree/SegmentTree.cpp
  - lib/util/ModInt.cpp
  - lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp
  isVerificationFile: true
  path: test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
  requiredBy: []
  timestamp: '2023-05-18 00:39:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
- /verify/test/data-structure/segment-tree/SegmentTree-rcq.test.cpp.html
title: test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
---
