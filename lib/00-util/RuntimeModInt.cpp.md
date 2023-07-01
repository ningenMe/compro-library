---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/MontmortNumber.test.cpp
    title: test/math/MontmortNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/util/RuntimeModInt.test.cpp
    title: test/util/RuntimeModInt.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/util/RuntimeModInt.md
    document_title: "RuntimeModInt - \u5B9F\u884C\u6642ModInt"
    links: []
  bundledCode: "#line 1 \"lib/00-util/RuntimeModInt.cpp\"\n/*\n * @title RuntimeModInt\
    \ - \u5B9F\u884C\u6642ModInt\n * @docs md/util/RuntimeModInt.md\n */\ntemplate<long\
    \ long& mod> class RuntimeModInt {\npublic:\n    long long x;\n    constexpr RuntimeModInt():x(0)\
    \ {}\n    constexpr RuntimeModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod)\
    \ {}\n    RuntimeModInt &operator+=(const RuntimeModInt &p) {if((x += p.x) >=\
    \ mod) x -= mod;return *this;}\n    RuntimeModInt &operator+=(const long long\
    \ y) {RuntimeModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt\
    \ &operator+=(const int y) {RuntimeModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    RuntimeModInt &operator-=(const RuntimeModInt &p) {if((x += mod\
    \ - p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt &operator-=(const\
    \ long long y) {RuntimeModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return\
    \ *this;}\n    RuntimeModInt &operator-=(const int y) {RuntimeModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt &operator*=(const\
    \ RuntimeModInt &p) {x = (x * p.x % mod);return *this;}\n    RuntimeModInt &operator*=(const\
    \ long long y) {RuntimeModInt p(y);x = (x * p.x % mod);return *this;}\n    RuntimeModInt\
    \ &operator*=(const int y) {RuntimeModInt p(y);x = (x * p.x % mod);return *this;}\n\
    \    RuntimeModInt &operator^=(const RuntimeModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    RuntimeModInt &operator^=(const long long y) {RuntimeModInt p(y);x\
    \ = (x ^ p.x) % mod;return *this;}\n    RuntimeModInt &operator^=(const int y)\
    \ {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    RuntimeModInt &operator/=(const\
    \ RuntimeModInt &p) {*this *= p.inv();return *this;}\n    RuntimeModInt &operator/=(const\
    \ long long y) {RuntimeModInt p(y);*this *= p.inv();return *this;}\n    RuntimeModInt\
    \ &operator/=(const int y) {RuntimeModInt p(y);*this *= p.inv();return *this;}\n\
    \    RuntimeModInt operator=(const int y) {RuntimeModInt p(y);*this = p;return\
    \ *this;}\n    RuntimeModInt operator=(const long long y) {RuntimeModInt p(y);*this\
    \ = p;return *this;}\n    RuntimeModInt operator-() const {return RuntimeModInt(-x);\
    \ }\n    RuntimeModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}\n  \
    \  RuntimeModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n    RuntimeModInt\
    \ operator+(const RuntimeModInt &p) const { return RuntimeModInt(*this) += p;\
    \ }\n    RuntimeModInt operator-(const RuntimeModInt &p) const { return RuntimeModInt(*this)\
    \ -= p; }\n    RuntimeModInt operator*(const RuntimeModInt &p) const { return\
    \ RuntimeModInt(*this) *= p; }\n    RuntimeModInt operator/(const RuntimeModInt\
    \ &p) const { return RuntimeModInt(*this) /= p; }\n    RuntimeModInt operator^(const\
    \ RuntimeModInt &p) const { return RuntimeModInt(*this) ^= p; }\n    bool operator==(const\
    \ RuntimeModInt &p) const { return x == p.x; }\n    bool operator!=(const RuntimeModInt\
    \ &p) const { return x != p.x; }\n    RuntimeModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return RuntimeModInt(u);}\n\
    \    RuntimeModInt pow(long long n) const {RuntimeModInt ret(1), mul(x);for(;n\
    \ > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream\
    \ &operator<<(ostream &os, const RuntimeModInt &p) {return os << p.x;}\n    friend\
    \ istream &operator>>(istream &is, RuntimeModInt &a) {long long t;is >> t;a =\
    \ RuntimeModInt<mod>(t);return (is);}\n};\nlong long runtime_mod;\n// using modint\
    \ = RuntimeModInt<runtime_mod>;\n"
  code: "/*\n * @title RuntimeModInt - \u5B9F\u884C\u6642ModInt\n * @docs md/util/RuntimeModInt.md\n\
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
    \ (is);}\n};\nlong long runtime_mod;\n// using modint = RuntimeModInt<runtime_mod>;\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/00-util/RuntimeModInt.cpp
  requiredBy: []
  timestamp: '2023-06-16 04:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/RuntimeModInt.test.cpp
  - test/math/MontmortNumber.test.cpp
documentation_of: lib/00-util/RuntimeModInt.cpp
layout: document
redirect_from:
- /library/lib/00-util/RuntimeModInt.cpp
- /library/lib/00-util/RuntimeModInt.cpp.html
title: "RuntimeModInt - \u5B9F\u884C\u6642ModInt"
---
### ModInt
- 常にModを取り続ける値オブジェクト
- 実行してからmodを設定することができる
- 下記のようにruntime_modをすでにグローバルに配置しているので、これにmodを代入する。
```
long long runtime_mod;
```
### コンストラクタ
- ModIntと同じ

### メソッド
- ModIntと同じ
