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
    path: lib/15-queue/SwagQueue.cpp
    title: SwagQueue
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/queue/SwagQueue-composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#line\
    \ 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
    \ */\nclass FastIO{\nprivate:\n    inline static constexpr int ch_0='0';\n   \
    \ inline static constexpr int ch_9='9';\n    inline static constexpr int ch_n='-';\n\
    \    inline static constexpr int ch_s=' ';\n    inline static constexpr int ch_l='\\\
    n';\n    inline static void endline_skip(char& ch) {\n        while(ch==ch_l)\
    \ ch=getchar();\n    }\n    template<typename T> inline static void read_integer(T\
    \ &x) {\n        int neg=0; char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        if(ch==ch_n) neg=1,ch=getchar();\n        for(;(ch_0 <= ch && ch <= ch_9);\
    \ ch = getchar()) x = x*10 + (ch-ch_0);\n        if(neg) x*=-1;\n    }\n    template<typename\
    \ T> inline static void read_unsigned_integer(T &x) {\n        char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        for(;(ch_0 <= ch &&\
    \ ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        endline_skip(ch);\n        for(;(ch != ch_s && ch!=ch_l); ch = getchar())\
    \ x.push_back(ch);\n    }\n    inline static char ar[40];\n    inline static char\
    \ *ch_ar;\n    template<typename T> inline static void write_integer(T x) {\n\
    \        ch_ar=ar;\n        if(x< 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n\
    \        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n\
    \    }\npublic:\n    inline static void read(int &x) {read_integer<int>(x);}\n\
    \    inline static void read(long long &x) {read_integer<long long>(x);}\n   \
    \ inline static void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n\
    \    inline static void read(unsigned long long &x) {read_unsigned_integer<unsigned\
    \ long long>(x);}\n    inline static void read(string &x) {read_string(x);}\n\
    \    inline static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n \
    \   inline static void write(__int128_t x) {write_integer<__int128_t>(x);}\n \
    \   inline static void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n#line 1 \"lib/00-util/ModInt.cpp\"\n/*\n\
    \ * @title ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class\
    \ ModInt {\npublic:\n    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr\
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
    constexpr long long MOD_1000000007 = 1'000'000'000LL + 7; //'\n#line 1 \"lib/15-queue/SwagQueue.cpp\"\
    \n/*\n * @title SwagQueue\n * @docs md/data-structure/SwagQueue.md\n */\ntemplate<class\
    \ Operator> class SwagQueue{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    stack<pair<TypeNode,TypeNode>> pre,suf;\n\n    SwagQueue() {\n        //\
    \ do nothing\n    }\n    TypeNode fold() {\n        TypeNode res = Operator::unit_node;\n\
    \        if(pre.size()) res = Operator::func_node(pre.top().second,res);\n   \
    \     if(suf.size()) res = Operator::func_node(res,suf.top().second);\n      \
    \  return res;\n    }\n    void push(TypeNode val) {\n        TypeNode acc = val;\n\
    \        if(suf.size()) acc = Operator::func_node(suf.top().second,val);\n   \
    \     suf.emplace(val,acc);\n    }\n    void pop() {\n        if(pre.empty())\
    \ {\n            TypeNode acc = Operator::unit_node;\n            while(suf.size())\
    \ {\n                auto [val,_] = suf.top();\n                suf.pop();\n \
    \               acc = Operator::func_node(val,acc);\n                pre.emplace(val,acc);\n\
    \            }\n        }\n        if(pre.size()) pre.pop();\n    }\n    size_t\
    \ size(){\n        return pre.size()+suf.size();\n    }\n};\n\ntemplate<class\
    \ T> struct NodeGcd {\n    using TypeNode = T;\n    inline static constexpr TypeNode\
    \ unit_node = 0;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return r?func_node(r,l%r):l;}\n};\n\ntemplate<class T> struct NodeComposite\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ {1,0};\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ {r.first*l.first,r.first*l.second+r.second};}\n};\n#line 10 \"test/queue/SwagQueue-composite.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int Q; read(Q);\n\
    \    using modint = ModInt<MOD_998244353>;\n    SwagQueue<NodeComposite<pair<modint,modint>>>\
    \ swag;\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n     \
    \       int a,b; read(a); read(b);\n            swag.push({a,b});\n        }\n\
    \        if(q==1) {\n            swag.pop();\n        }\n        if(q==2) {\n\
    \            int x; read(x);\n            auto [a,b] = swag.fold();\n        \
    \    cout << a*x+b << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\nusing namespace\
    \ std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\
    \n#include \"../../lib/15-queue/SwagQueue.cpp\"\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int Q; read(Q);\n    using modint = ModInt<MOD_998244353>;\n    SwagQueue<NodeComposite<pair<modint,modint>>>\
    \ swag;\n    while(Q--) {\n        int q; read(q);\n        if(q==0) {\n     \
    \       int a,b; read(a); read(b);\n            swag.push({a,b});\n        }\n\
    \        if(q==1) {\n            swag.pop();\n        }\n        if(q==2) {\n\
    \            int x; read(x);\n            auto [a,b] = swag.fold();\n        \
    \    cout << a*x+b << \"\\n\";\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/15-queue/SwagQueue.cpp
  isVerificationFile: true
  path: test/queue/SwagQueue-composite.test.cpp
  requiredBy: []
  timestamp: '2023-06-06 01:28:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/queue/SwagQueue-composite.test.cpp
layout: document
redirect_from:
- /verify/test/queue/SwagQueue-composite.test.cpp
- /verify/test/queue/SwagQueue-composite.test.cpp.html
title: test/queue/SwagQueue-composite.test.cpp
---
