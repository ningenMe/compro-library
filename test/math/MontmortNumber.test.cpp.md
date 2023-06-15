---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/00-util/RuntimeModInt.cpp
    title: "RuntimeModInt - \u5B9F\u884C\u6642ModInt"
  - icon: ':heavy_check_mark:'
    path: lib/30-math/MontmortNumber.cpp
    title: "MontmortNumber - \u5B8C\u5168\u9806\u5217,\u64B9\u4E71\u9806\u5217\u306E\
      \u500B\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"test/math/MontmortNumber.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/montmort_number_mod\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <array>\nusing namespace std;\n\
    #line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
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
    #define write(arg) FastIO::write(arg)\n#line 1 \"lib/00-util/RuntimeModInt.cpp\"\
    \n/*\n * @title RuntimeModInt - \u5B9F\u884C\u6642ModInt\n * @docs md/util/RuntimeModInt.md\n\
    \ */\ntemplate<long long& mod> class RuntimeModInt {\npublic:\n    long long x;\n\
    \    constexpr RuntimeModInt():x(0) {}\n    constexpr RuntimeModInt(long long\
    \ y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    RuntimeModInt &operator+=(const\
    \ RuntimeModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt\
    \ &operator+=(const long long y) {RuntimeModInt p(y);if((x += p.x) >= mod) x -=\
    \ mod;return *this;}\n    RuntimeModInt &operator+=(const int y) {RuntimeModInt\
    \ p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt &operator-=(const\
    \ RuntimeModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n   \
    \ RuntimeModInt &operator-=(const long long y) {RuntimeModInt p(y);if((x += mod\
    \ - p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt &operator-=(const\
    \ int y) {RuntimeModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    RuntimeModInt &operator*=(const RuntimeModInt &p) {x = (x * p.x % mod);return\
    \ *this;}\n    RuntimeModInt &operator*=(const long long y) {RuntimeModInt p(y);x\
    \ = (x * p.x % mod);return *this;}\n    RuntimeModInt &operator*=(const int y)\
    \ {RuntimeModInt p(y);x = (x * p.x % mod);return *this;}\n    RuntimeModInt &operator^=(const\
    \ RuntimeModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    RuntimeModInt &operator^=(const\
    \ long long y) {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    RuntimeModInt\
    \ &operator^=(const int y) {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}\n\
    \    RuntimeModInt &operator/=(const RuntimeModInt &p) {*this *= p.inv();return\
    \ *this;}\n    RuntimeModInt &operator/=(const long long y) {RuntimeModInt p(y);*this\
    \ *= p.inv();return *this;}\n    RuntimeModInt &operator/=(const int y) {RuntimeModInt\
    \ p(y);*this *= p.inv();return *this;}\n    RuntimeModInt operator=(const int\
    \ y) {RuntimeModInt p(y);*this = p;return *this;}\n    RuntimeModInt operator=(const\
    \ long long y) {RuntimeModInt p(y);*this = p;return *this;}\n    RuntimeModInt\
    \ operator-() const {return RuntimeModInt(-x); }\n    RuntimeModInt operator++()\
    \ {x++;if(x>=mod) x-=mod;return *this;}\n    RuntimeModInt operator--() {x--;if(x<0)\
    \ x+=mod;return *this;}\n    RuntimeModInt operator+(const RuntimeModInt &p) const\
    \ { return RuntimeModInt(*this) += p; }\n    RuntimeModInt operator-(const RuntimeModInt\
    \ &p) const { return RuntimeModInt(*this) -= p; }\n    RuntimeModInt operator*(const\
    \ RuntimeModInt &p) const { return RuntimeModInt(*this) *= p; }\n    RuntimeModInt\
    \ operator/(const RuntimeModInt &p) const { return RuntimeModInt(*this) /= p;\
    \ }\n    RuntimeModInt operator^(const RuntimeModInt &p) const { return RuntimeModInt(*this)\
    \ ^= p; }\n    bool operator==(const RuntimeModInt &p) const { return x == p.x;\
    \ }\n    bool operator!=(const RuntimeModInt &p) const { return x != p.x; }\n\
    \    RuntimeModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a /\
    \ b;swap(a -= t * b, b);swap(u -= t * v, v);} return RuntimeModInt(u);}\n    RuntimeModInt\
    \ pow(long long n) const {RuntimeModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const RuntimeModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, RuntimeModInt &a) {long long t;is >> t;a = RuntimeModInt<mod>(t);return\
    \ (is);}\n};\nlong long runtime_mod;\n// using modint = RuntimeModInt<runtime_mod>;\n\
    #line 1 \"lib/30-math/MontmortNumber.cpp\"\n/*\n * @title MontmortNumber - \u5B8C\
    \u5168\u9806\u5217,\u64B9\u4E71\u9806\u5217\u306E\u500B\u6570\n * @docs md/math/MontmortNumber.md\n\
    \ */\ntemplate <class T> class MontmortNumber{\npublic:\n    inline static vector<T>\
    \ get(const size_t N) {\n        vector<T> res(N+1,0);\n        if(N>=2) res[2]=1;\n\
    \        for(int i = 3; i <= N; ++i) res[i]=(res[i-1]+res[i-2])*(i-1);\n     \
    \   return res;\n    }\n};\n#line 11 \"test/math/MontmortNumber.test.cpp\"\n\n\
    int main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,M; read(N),\
    \ read(M);\n    runtime_mod = M;\n    auto ar = MontmortNumber<RuntimeModInt<runtime_mod>>::get(N);\n\
    \    for(int i=1;i<=N;++i) cout << ar[i] << \" \\n\"[i==N];\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <array>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/00-util/RuntimeModInt.cpp\"\
    \n#include \"../../lib/30-math/MontmortNumber.cpp\"\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,M; read(N), read(M);\n    runtime_mod = M;\n    auto ar = MontmortNumber<RuntimeModInt<runtime_mod>>::get(N);\n\
    \    for(int i=1;i<=N;++i) cout << ar[i] << \" \\n\"[i==N];\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/RuntimeModInt.cpp
  - lib/30-math/MontmortNumber.cpp
  isVerificationFile: true
  path: test/math/MontmortNumber.test.cpp
  requiredBy: []
  timestamp: '2023-06-16 04:11:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/MontmortNumber.test.cpp
layout: document
redirect_from:
- /verify/test/math/MontmortNumber.test.cpp
- /verify/test/math/MontmortNumber.test.cpp.html
title: test/math/MontmortNumber.test.cpp
---
