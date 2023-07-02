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
    path: lib/10-segment-tree/DynamicSegmentTree.cpp
    title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <stack>\n\
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
    \ = 1'000'000'000LL + 7; //'\n#line 1 \"lib/10-segment-tree/DynamicSegmentTree.cpp\"\
    \n/*\n * @title DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/DynamicSegmentTree.md\n\
    \ */\ntemplate<class Monoid> class DynamicSegmentTree {\n    using TypeNode =\
    \ typename Monoid::TypeNode;\n    using i64 = long long;\n\n    struct Node{\n\
    \        Node *left, *right;\n        TypeNode val;\n        Node():left(nullptr),right(nullptr),val(Monoid::unit_node)\
    \ {}\n    };\n\n    TypeNode dfs(i64 l,i64 r,i64 nl,i64 nr,Node* node) {\n   \
    \     if(l <= nl && nr <= r) return node->val;\n        if(nr <= l || r <= nl)\
    \ return Monoid::unit_node;\n        TypeNode vl=Monoid::unit_node, vr=Monoid::unit_node;\n\
    \        i64 m = (nl+nr)>>1;\n        if(node->left)  vl = dfs(l,r,nl,m,node->left);\n\
    \        if(node->right) vr = dfs(l,r,m,nr,node->right);\n        return Monoid::func_fold(vl,vr);\n\
    \    }\n\n    i64 length;\n    Node *root;\npublic:\n    //unit\u3067\u521D\u671F\
    \u5316\n    DynamicSegmentTree() : length(1) {\n        root = new Node();\n \
    \   }\n    //[idx,idx+1)\n    void operate(i64 idx, const TypeNode val) {\n  \
    \      if(idx < 0) return;\n        for (;length <= idx; length *= 2) {\n    \
    \        Node *new_root = new Node();\n            TypeNode val = root->val;\n\
    \            new_root->left = root;\n            root = new_root;\n          \
    \  root->val = val;\n        }\n        Node* node = root;\n        i64 l = 0,\
    \ r = length, m;\n\t\tstack<Node*> st;\n\n        while(r-l>1) {\n\t\t\tst.push(node);\n\
    \            m = (r+l)>>1;\n            if(idx<m) {\n                r = m;\n\
    \                if(!node->left) node->left=new Node();\n                node\
    \ = node->left;\n            }\n            else {\n                l = m;\n \
    \               if(!node->right) node->right = new Node();\n                node\
    \ = node->right;\n            }\n        }\n        node->val = Monoid::func_operate(node->val,val);\n\
    \t\twhile(st.size()) {\n\t\t\tnode = st.top(); st.pop();\n\t\t\tTypeNode vl=Monoid::unit_node,\
    \ vr=Monoid::unit_node;\n\t\t\tif(node->left)  vl = node->left->val;\n\t\t\tif(node->right)\
    \ vr = node->right->val;\n\t\t\tnode->val = Monoid::func_fold(vl,vr);\n\t\t}\n\
    \    }\n\n    //[l,r)\n    TypeNode fold(i64 l, i64 r) {\n        if (l < 0 ||\
    \ length <= l || r < 0) return Monoid::unit_node;\n        return dfs(l,r,0,length,root);\n\
    \    }\n};\n#line 1 \"lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n/*\n * @title MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\
    \u6570, \u70B9\u66F4\u65B0]\n * @docs md/operator/monoid/MonoidRangeCompositePointUpdate.md\n\
    \ */\ntemplate<class T> struct MonoidRangeCompositePointUpdate {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unit_node = make_pair(1,0);\n   \
    \ inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    \    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return\
    \ r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n#line 12 \"test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    using Mint\
    \ = ModInt<MOD_998244353>;\n    int N,Q; \n    read(N), read(Q);\n    DynamicSegmentTree<MonoidRangeCompositePointUpdate<pair<Mint,Mint>>>\
    \ seg;\n    for(int i = 0; i < N; ++i) {\n\t\tint a,b; read(a), read(b);\n\t\t\
    seg.operate(i,{a,b});\n    }\n    while(Q--){\n        long long q,l,r,x; \n\t\
    \tread(q),read(l),read(r),read(x);\n        if(q) {\n\t\t\tauto p = seg.fold(l,r);\n\
    \t\t\tcout << p.first*x+p.second << \"\\n\";\n\t\t}\n        else seg.operate(l,{r,x});\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <stack>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\
    \n#include \"../../lib/10-segment-tree/DynamicSegmentTree.cpp\"\n#include \"../../lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    using Mint\
    \ = ModInt<MOD_998244353>;\n    int N,Q; \n    read(N), read(Q);\n    DynamicSegmentTree<MonoidRangeCompositePointUpdate<pair<Mint,Mint>>>\
    \ seg;\n    for(int i = 0; i < N; ++i) {\n\t\tint a,b; read(a), read(b);\n\t\t\
    seg.operate(i,{a,b});\n    }\n    while(Q--){\n        long long q,l,r,x; \n\t\
    \tread(q),read(l),read(r),read(x);\n        if(q) {\n\t\t\tauto p = seg.fold(l,r);\n\
    \t\t\tcout << p.first*x+p.second << \"\\n\";\n\t\t}\n        else seg.operate(l,{r,x});\n\
    \    }\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/10-segment-tree/DynamicSegmentTree.cpp
  - lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp
  isVerificationFile: true
  path: test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 23:40:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
- /verify/test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp.html
title: test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
---
