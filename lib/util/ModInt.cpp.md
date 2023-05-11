---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/ModInt.test.cpp
    title: test/util/ModInt.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/util/ModInt.md
    document_title: ModInt
    links: []
  bundledCode: "#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title ModInt\n * @docs md/util/ModInt.md\n\
    \ */\ntemplate<long long mod> class ModInt {\npublic:\n    long long x;\n    constexpr\
    \ ModInt():x(0) {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod -\
    \ (-y)%mod)%mod) {}\n    ModInt &operator+=(const ModInt &p) {if((x += p.x) >=\
    \ mod) x -= mod;return *this;}\n    ModInt &operator+=(const long long y) {ModInt\
    \ p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const\
    \ int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt\
    \ &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >=\
    \ mod) x -= mod;return *this;}\n    ModInt &operator-=(const int y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator*=(const\
    \ ModInt &p) {x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const\
    \ long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const\
    \ int y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator^=(const\
    \ ModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator^=(const\
    \ long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator^=(const\
    \ int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator/=(const\
    \ ModInt &p) {*this *= p.inv();return *this;}\n    ModInt &operator/=(const long\
    \ long y) {ModInt p(y);*this *= p.inv();return *this;}\n    ModInt &operator/=(const\
    \ int y) {ModInt p(y);*this *= p.inv();return *this;}\n    ModInt operator=(const\
    \ int y) {ModInt p(y);*this = p;return *this;}\n    ModInt operator=(const long\
    \ long y) {ModInt p(y);*this = p;return *this;}\n    ModInt operator-() const\
    \ {return ModInt(-x); }\n    ModInt operator++() {x++;if(x>=mod) x-=mod;return\
    \ *this;}\n    ModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n    ModInt\
    \ operator+(const ModInt &p) const { return ModInt(*this) += p; }\n    ModInt\
    \ operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt\
    \ operator*(const ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt\
    \ operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n    ModInt\
    \ operator^(const ModInt &p) const { return ModInt(*this) ^= p; }\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    //using modint = ModInt<MOD>;\n"
  code: "/*\n * @title ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long\
    \ mod> class ModInt {\npublic:\n    long long x;\n    constexpr ModInt():x(0)\
    \ {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod)\
    \ {}\n    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x)\
    \ >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const int y) {ModInt\
    \ p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator-=(const\
    \ ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt\
    \ &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -=\
    \ mod;return *this;}\n    ModInt &operator-=(const int y) {ModInt p(y);if((x +=\
    \ mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator*=(const ModInt\
    \ &p) {x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const long long\
    \ y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const\
    \ int y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator^=(const\
    \ ModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator^=(const\
    \ long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator^=(const\
    \ int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator/=(const\
    \ ModInt &p) {*this *= p.inv();return *this;}\n    ModInt &operator/=(const long\
    \ long y) {ModInt p(y);*this *= p.inv();return *this;}\n    ModInt &operator/=(const\
    \ int y) {ModInt p(y);*this *= p.inv();return *this;}\n    ModInt operator=(const\
    \ int y) {ModInt p(y);*this = p;return *this;}\n    ModInt operator=(const long\
    \ long y) {ModInt p(y);*this = p;return *this;}\n    ModInt operator-() const\
    \ {return ModInt(-x); }\n    ModInt operator++() {x++;if(x>=mod) x-=mod;return\
    \ *this;}\n    ModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n    ModInt\
    \ operator+(const ModInt &p) const { return ModInt(*this) += p; }\n    ModInt\
    \ operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt\
    \ operator*(const ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt\
    \ operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n    ModInt\
    \ operator^(const ModInt &p) const { return ModInt(*this) ^= p; }\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    //using modint = ModInt<MOD>;"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/ModInt.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/ModInt.test.cpp
documentation_of: lib/util/ModInt.cpp
layout: document
redirect_from:
- /library/lib/util/ModInt.cpp
- /library/lib/util/ModInt.cpp.html
title: ModInt
---
### ModInt
- 常にModを取り続ける値オブジェクト
- 実行前に決まる定数modである必要がある
- 入出力はそのまま行えるように定義している

### コンストラクタ
- int,long longなどのプリミティブ型と同様

### メソッド
- int x
  - ModInt<mod> 型であるaに対して、a.xでint型のaの値を取得できる。
- int,long long型との四則演算はModInt型を左辺にしないとエラーになる。
- ModInt型との四則演算はプリミティブ型と同じ。
  - 和,差,積: $O(1)$
  - 商: $O(\log mod)$
- ModInt inv()
  - 逆元を返す
  - $O(\log N)$
- ModInt pow(long long n)
  - n乗した値を返す。