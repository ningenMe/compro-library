---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/00-util/RuntimeModInt.cpp
    title: "RuntimeModInt - \u5B9F\u884C\u6642ModInt"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1161
    links:
    - https://yukicoder.me/problems/no/1161
  bundledCode: "#line 1 \"test/00-util/RuntimeModInt.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1161\"\n\n#include <vector>\n#include <iostream>\n\
    #include <array>\n#include <numeric>\nusing namespace std;\n#line 1 \"lib/00-util/RuntimeModInt.cpp\"\
    \n/*\n * @title RuntimeModInt - \u5B9F\u884C\u6642ModInt\n * @docs md/00-util/RuntimeModInt.md\n\
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
    \ (is);}\n};\nlong long runtime_mod;\n// using modint = RuntimeModInt<mod>;\n\
    #line 9 \"test/00-util/RuntimeModInt.test.cpp\"\n\nusing modint = RuntimeModInt<runtime_mod>;\n\
    \nint main() {\n\tlong long A,B,C;\n\tcin >> A >> B >> C;\n\truntime_mod = C;\n\
    \tmodint ans = 0;\n\tarray<modint,100001> cnt;\n\tfor(long long i = 1; i <= C;\
    \ ++i) {\n\t\tcnt[i] = modint(i).pow(B);\n\t}\n\tfor(long long i = 1; i <= A%C;\
    \ ++i) {\n\t\tans += cnt[i];\n\t}\n\tans += accumulate(cnt.begin(),cnt.begin()+C,modint(0))*(A/C);\n\
    \tcout << ans << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1161\"\n\n#include <vector>\n\
    #include <iostream>\n#include <array>\n#include <numeric>\nusing namespace std;\n\
    #include \"../../lib/00-util/RuntimeModInt.cpp\"\n\nusing modint = RuntimeModInt<runtime_mod>;\n\
    \nint main() {\n\tlong long A,B,C;\n\tcin >> A >> B >> C;\n\truntime_mod = C;\n\
    \tmodint ans = 0;\n\tarray<modint,100001> cnt;\n\tfor(long long i = 1; i <= C;\
    \ ++i) {\n\t\tcnt[i] = modint(i).pow(B);\n\t}\n\tfor(long long i = 1; i <= A%C;\
    \ ++i) {\n\t\tans += cnt[i];\n\t}\n\tans += accumulate(cnt.begin(),cnt.begin()+C,modint(0))*(A/C);\n\
    \tcout << ans << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - lib/00-util/RuntimeModInt.cpp
  isVerificationFile: true
  path: test/00-util/RuntimeModInt.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:03:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/00-util/RuntimeModInt.test.cpp
layout: document
redirect_from:
- /verify/test/00-util/RuntimeModInt.test.cpp
- /verify/test/00-util/RuntimeModInt.test.cpp.html
title: test/00-util/RuntimeModInt.test.cpp
---
