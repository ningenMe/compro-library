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
    path: lib/10-segment-tree/DualSegmentTree.cpp
    title: "DualSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u53CC\u5BFE\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/segment-tree/DualSegmentTree-pcq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\
    \n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
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
    \ = 1'000'000'000LL + 7; //'\n#line 1 \"lib/10-segment-tree/DualSegmentTree.cpp\"\
    \n/*\n * @title DualSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/DualSegmentTree.md\n\
    \ */\ntemplate<class Monoid> class DualSegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n    size_t\
    \ length;\n    size_t height;\n    vector<TypeNode> node;\n    vector<TypeLazy>\
    \ lazy;\n\n    void propagate(int k) {\n        if(lazy[k] == Monoid::unit_lazy)\
    \ return;\n        if(k >=length) node[k-length] = Monoid::func_operate(node[k-length],lazy[k],k-length,k-length+1);\n\
    \        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\
    \        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\
    \        lazy[k] = Monoid::unit_lazy;\n    }\n    void build(const size_t num)\
    \ {\n        for (length = 1,height = 0; length <= num; length *= 2, height++);\n\
    \        node.resize(1 * length, Monoid::unit_node);\n        lazy.resize(2 *\
    \ length, Monoid::unit_lazy);\n    }\n\npublic:\n\n    //unit\u3067\u521D\u671F\
    \u5316\n    DualSegmentTree(const size_t num) {\n        build(num);\n    }\n\
    \    // //\u540C\u3058init\u3067\u521D\u671F\u5316\n    DualSegmentTree(const\
    \ size_t num, const TypeNode init) {\n        build(num);\n        for (int i\
    \ = 0; i < num; ++i) node[i] = init;\n    }\n    //vector\u3067\u521D\u671F\u5316\
    \n    DualSegmentTree(const vector<TypeNode>& vec) {\n        build(vec.size());\n\
    \        for (int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n    }\n\n   \
    \ //operate [a,b)\n    void operate(int a, int b, TypeLazy x) {\n        int l\
    \ = a + length, r = b + length - 1;\n        for (int i = height; 0 < i; --i)\
    \ propagate(l >> i), propagate(r >> i);\n        for(r++; l < r; l >>=1, r >>=1)\
    \ {\n            if(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x), propagate(l),l++;\n\
    \            if(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x), propagate(r);\n\
    \        }\n    }\n\n    //fold [a,a+1)\n    TypeNode fold(int a) {\n        int\
    \ l = a + length;\n        for (int i = height; 0 <= i; --i) propagate(l >> i);\n\
    \        return node[a];\n    }\n\n    void print(){\n        cout << \"lazy\"\
    \ << endl;\n        for(int i = 1,j = 1; i < 2*length; ++i) {\n        \tcout\
    \ << lazy[i] << \" \";\n        \tif(i==((1<<j)-1) && ++j) cout << endl;\n   \
    \     }\n        cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0);\n\
    \        for(int i = 1; i < length; ++i) cout << \", \" << fold(i);\n        cout\
    \ << \" }\" << endl;\n    }\n};\n#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
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
    #line 10 \"test/segment-tree/DualSegmentTree-pcq.test.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    using Mint = ModInt<MOD_998244353>;\n\
    \    int N,Q;\n    read(N),read(Q);\n    DualSegmentTree<MonoidRangeFoldSumRangeOperateAffine<Mint,pair<Mint,Mint>>>\
    \ seg(N);\n    for(int i=0;i<N;++i) {\n        int a; read(a);\n        seg.operate(i,i+1,{0,a});\n\
    \    }\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n      \
    \      int l,r,b,c;\n            read(l),read(r),read(b),read(c);\n          \
    \  seg.operate(l,r,{b,c});\n        }\n        if(q==1) {\n            int i;\
    \ read(i);\n            cout << seg.fold(i) << \"\\n\";\n        }\n    }\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include <vector>\n#include <iostream>\nusing namespace std;\n#include \"\
    ../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\n#include\
    \ \"../../lib/10-segment-tree/DualSegmentTree.cpp\"\n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    using Mint\
    \ = ModInt<MOD_998244353>;\n    int N,Q;\n    read(N),read(Q);\n    DualSegmentTree<MonoidRangeFoldSumRangeOperateAffine<Mint,pair<Mint,Mint>>>\
    \ seg(N);\n    for(int i=0;i<N;++i) {\n        int a; read(a);\n        seg.operate(i,i+1,{0,a});\n\
    \    }\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n      \
    \      int l,r,b,c;\n            read(l),read(r),read(b),read(c);\n          \
    \  seg.operate(l,r,{b,c});\n        }\n        if(q==1) {\n            int i;\
    \ read(i);\n            cout << seg.fold(i) << \"\\n\";\n        }\n    }\n  \
    \  return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/10-segment-tree/DualSegmentTree.cpp
  - lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
  isVerificationFile: true
  path: test/segment-tree/DualSegmentTree-pcq.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 02:09:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree/DualSegmentTree-pcq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/DualSegmentTree-pcq.test.cpp
- /verify/test/segment-tree/DualSegmentTree-pcq.test.cpp.html
title: test/segment-tree/DualSegmentTree-pcq.test.cpp
---
