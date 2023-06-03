---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqrafq.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqrafq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-998244353-1.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-998244353-2.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-998244353-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-fft.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-fft.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-path.test.cpp
    title: test/graph/Tree-hld-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-3.test.cpp
    title: test/graph/Tree-hld-vertex-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/CombinationMod-factorial.test.cpp
    title: test/math/CombinationMod-factorial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Matrix-det.test.cpp
    title: test/math/Matrix-det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Matrix-pow.test.cpp
    title: test/math/Matrix-pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-exp.test.cpp
    title: test/polynomial/FormalPowerSeries-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-interpolation.test.cpp
    title: test/polynomial/FormalPowerSeries-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-inv.test.cpp
    title: test/polynomial/FormalPowerSeries-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-log.test.cpp
    title: test/polynomial/FormalPowerSeries-log.test.cpp
  - icon: ':x:'
    path: test/polynomial/FormalPowerSeries-multi-eval.test.cpp
    title: test/polynomial/FormalPowerSeries-multi-eval.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-nth.test.cpp
    title: test/polynomial/FormalPowerSeries-nth.test.cpp
  - icon: ':x:'
    path: test/polynomial/FormalPowerSeries-pow.test.cpp
    title: test/polynomial/FormalPowerSeries-pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/SegmentTree-rcq.test.cpp
    title: test/segment-tree/SegmentTree-rcq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/util/ModInt.test.cpp
    title: test/util/ModInt.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/util/ModInt.md
    document_title: ModInt
    links: []
  bundledCode: "#line 1 \"lib/00-util/ModInt.cpp\"\n/*\n * @title ModInt\n * @docs\
    \ md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt {\npublic:\n  \
    \  long long x;\n    constexpr ModInt():x(0) {}\n    constexpr ModInt(long long\
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
    constexpr long long MOD_1000000007 = 1'000'000'000LL + 7; //'\n"
  code: "/*\n * @title ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long\
    \ mod> class ModInt {\npublic:\n    long long x;\n    constexpr ModInt():x(0)\
    \ {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod)\
    \ {}\n    constexpr ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod)\
    \ x -= mod;return *this;}\n    constexpr ModInt &operator+=(const long long y)\
    \ {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt\
    \ &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    constexpr ModInt &operator-=(const ModInt &p) {if((x += mod - p.x)\
    \ >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const long\
    \ long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n \
    \   constexpr ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x)\
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
    \ = 1'000'000'000LL + 7; //'\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/00-util/ModInt.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:32:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/convolution/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
  - test/convolution/NumberTheoreticalTransform-conv-998244353-2.test.cpp
  - test/convolution/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  - test/convolution/NumberTheoreticalTransform-conv-fft.test.cpp
  - test/math/Matrix-pow.test.cpp
  - test/math/CombinationMod-factorial.test.cpp
  - test/math/Matrix-det.test.cpp
  - test/segment-tree/SegmentTree-rcq.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqrafq.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
  - test/polynomial/FormalPowerSeries-inv.test.cpp
  - test/polynomial/FormalPowerSeries-nth.test.cpp
  - test/polynomial/FormalPowerSeries-interpolation.test.cpp
  - test/polynomial/FormalPowerSeries-multi-eval.test.cpp
  - test/polynomial/FormalPowerSeries-log.test.cpp
  - test/polynomial/FormalPowerSeries-exp.test.cpp
  - test/polynomial/FormalPowerSeries-pow.test.cpp
  - test/util/ModInt.test.cpp
  - test/graph/Tree-hld-path.test.cpp
  - test/graph/Tree-hld-vertex-3.test.cpp
documentation_of: lib/00-util/ModInt.cpp
layout: document
redirect_from:
- /library/lib/00-util/ModInt.cpp
- /library/lib/00-util/ModInt.cpp.html
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