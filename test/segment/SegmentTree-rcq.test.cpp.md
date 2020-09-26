---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/segment/SegmentTree.cpp
    title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':question:'
    path: lib/util/ModInt.cpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/segment/SegmentTree-rcq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\n#line 1 \"lib/segment/SegmentTree.cpp\"\
    \n/*\n * @title SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/segment/SegmentTree.md\n */\ntemplate<class\
    \ Operator> class SegmentTree {\n    using TypeNode = typename Operator::TypeNode;\
    \ \n    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n    vector<pair<int,int>>\
    \ range;\n    inline void build() {\n        for (int i = length - 1; i >= 0;\
    \ --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n       \
    \ range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t num): num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Operator::unit_node);\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode> & vec) : num(vec.size())\
    \ {\n        for (length = 1; length <= vec.size(); length *= 2);\n        node.resize(2\
    \ * length, Operator::unit_node);\n        for (int i = 0; i < vec.size(); ++i)\
    \ node[i + length] = vec[i];\n        build();\n    }\n \n    //\u540C\u3058init\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Operator::unit_node);\n        for (int i = 0; i < length; ++i) node[i+length]\
    \ = init;\n        build();\n    }\n    \n    //[idx,idx+1)\n    void update(size_t\
    \ idx, const TypeNode var) {\n        if(idx < 0 || length <= idx) return;\n \
    \       idx += length;\n        node[idx] = Operator::func_merge(node[idx],var);\n\
    \        while(idx >>= 1) node[idx] = Operator::func_node(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \    }\n\n    //[l,r)\n    TypeNode get(int l, int r) {\n        if (l < 0 ||\
    \ length <= l || r < 0 || length < r) return Operator::unit_node;\n        TypeNode\
    \ vl = Operator::unit_node, vr = Operator::unit_node;\n        for(l += length,\
    \ r += length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Operator::func_node(vl,node[l++]);\n\
    \            if(r&1) vr = Operator::func_node(node[--r],vr);\n        }\n    \
    \    return Operator::func_node(vl,vr);\n    }\n\n    //range[l,r) return [l,r]\
    \ search max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n\
    \        assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode\
    \ ret = Operator::unit_node;\n        size_t off = l;\n        for(size_t idx\
    \ = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,node[idx]),var)) {\n      \
    \          ret = Operator::func_node(ret,node[idx]);\n                off = range[idx++].second;\n\
    \                if(!(idx&1)) idx >>= 1;\t\t\t\n            }\n            else{\n\
    \                idx <<=1;\n            }\n        }\n        return off;\n  \
    \  }\n\n    //range(l,r] return [l,r] search max left\n    int suffix_binary_search(const\
    \ int l, const int r, const TypeNode var) {\n        assert(-1 <= l && l < (int)length-1\
    \ && 0 <= r && r < length);\n        TypeNode ret = Operator::unit_node;\n   \
    \     int off = r;\n        for(size_t idx = r+length; idx < 2*length && l < off;\
    \ ){\n            if(l < range[idx].first && !Operator::func_check(Operator::func_node(node[idx],ret),var))\
    \ {\n                ret = Operator::func_node(node[idx],ret);\n             \
    \   off = range[idx--].first-1;\n                if(idx&1) idx >>= 1;\n      \
    \      }\n            else{\n                idx = (idx<<1)+1;\n            }\n\
    \        }\n        return off;\n    }\n\n    void print(){\n        // cout <<\
    \ \"node\" << endl;\n        // for(int i = 1,j = 1; i < 2*length; ++i) {\n  \
    \      // \tcout << node[i] << \" \";\n        // \tif(i==((1<<j)-1) && ++j) cout\
    \ << endl;\n        // }\n        cout << \"vector\" << endl;\n        cout <<\
    \ \"{ \" << get(0,1);\n        for(int i = 1; i < length; ++i) cout << \", \"\
    \ << get(i,i+1);\n        cout << \" }\" << endl;\n    }\n};\n\n//\u4E00\u70B9\
    \u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct NodeMinPointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ (1LL<<31)-1;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n    inline static constexpr TypeNode func_merge(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n\n//\u4E00\u70B9\u52A0\u7B97\
    \ \u533A\u9593\u7DCF\u548C\ntemplate<class T> struct NodeSumPointAdd {\n    using\
    \ TypeNode = T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n  \
    \  inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n\
    \    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n\n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct\
    \ NodeCompositePointUpdate {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = make_pair(1,0);\n    inline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n    inline\
    \ static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}\n   \
    \ inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title ModInt\n\
    \ * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt {\npublic:\n\
    \    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr ModInt(long long\
    \ y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    ModInt &operator+=(const\
    \ ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const\
    \ long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n  \
    \  ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod)\
    \ x -= mod;return *this;}\n    ModInt &operator-=(const long long y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator-=(const\
    \ int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n  \
    \  ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n \
    \   ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    ModInt &operator^=(const long long y) {ModInt p(y);x = (x ^ p.x)\
    \ % mod;return *this;}\n    ModInt &operator^=(const int y) {ModInt p(y);x = (x\
    \ ^ p.x) % mod;return *this;}\n    ModInt &operator/=(const ModInt &p) {*this\
    \ *= p.inv();return *this;}\n    ModInt &operator/=(const long long y) {ModInt\
    \ p(y);*this *= p.inv();return *this;}\n    ModInt &operator/=(const int y) {ModInt\
    \ p(y);*this *= p.inv();return *this;}\n    ModInt operator=(const int y) {ModInt\
    \ p(y);*this = p;return *this;}\n    ModInt operator=(const long long y) {ModInt\
    \ p(y);*this = p;return *this;}\n    ModInt operator-() const {return ModInt(-x);\
    \ }\n    ModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}\n    ModInt\
    \ operator--() {x--;if(x<0) x+=mod;return *this;}\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    ModInt operator^(const\
    \ ModInt &p) const { return ModInt(*this) ^= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    //using modint = ModInt<MOD>;\n#line 9 \"test/segment/SegmentTree-rcq.test.cpp\"\
    \n\nusing modint = ModInt<998244353>;\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<pair<modint,modint>> A(N);\n    for(int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].first >> A[i].second;\n    }\n   \
    \ SegmentTree<NodeCompositePointUpdate<pair<modint,modint>>> seg(A);\n    while(Q--){\n\
    \        long long q,l,r,x; cin >> q >> l >> r >> x;\n        if(q) {\n\t\t\t\
    auto p = seg.get(l,r);\n\t\t\tcout << p.first*x+p.second << endl;\n\t\t}\n   \
    \     else seg.update(l,{r,x});\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/segment/SegmentTree.cpp\"\n#include \"../../lib/util/ModInt.cpp\"\
    \n\nusing modint = ModInt<998244353>;\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<pair<modint,modint>> A(N);\n    for(int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].first >> A[i].second;\n    }\n   \
    \ SegmentTree<NodeCompositePointUpdate<pair<modint,modint>>> seg(A);\n    while(Q--){\n\
    \        long long q,l,r,x; cin >> q >> l >> r >> x;\n        if(q) {\n\t\t\t\
    auto p = seg.get(l,r);\n\t\t\tcout << p.first*x+p.second << endl;\n\t\t}\n   \
    \     else seg.update(l,{r,x});\n    }\n}\n\n"
  dependsOn:
  - lib/segment/SegmentTree.cpp
  - lib/util/ModInt.cpp
  isVerificationFile: true
  path: test/segment/SegmentTree-rcq.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment/SegmentTree-rcq.test.cpp
layout: document
redirect_from:
- /verify/test/segment/SegmentTree-rcq.test.cpp
- /verify/test/segment/SegmentTree-rcq.test.cpp.html
title: test/segment/SegmentTree-rcq.test.cpp
---
