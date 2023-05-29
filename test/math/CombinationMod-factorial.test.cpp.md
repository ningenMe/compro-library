---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/30-math/CombinationMod.cpp
    title: "CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/916
    links:
    - https://yukicoder.me/problems/no/916
  bundledCode: "#line 1 \"test/math/CombinationMod-factorial.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/916\"\n\n#include <vector>\n#include <iostream>\n\
    using namespace std;\n#line 1 \"lib/30-math/CombinationMod.cpp\"\n/*\n * @title\
    \ CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57\n\
    \ * @docs md/math/CombinationMod.md\n */\ntemplate<long long mod> class CombinationMod\
    \ {\n    vector<long long> fac,finv,inv;\npublic:\n    CombinationMod(int N) :\
    \ fac(N + 1), finv(N + 1), inv(N + 1) {\n        fac[0] = fac[1] = finv[0] = finv[1]\
    \ = inv[1] = 1;\n        for (int i = 2; i <= N; ++i) {\n            fac[i] =\
    \ fac[i - 1] * i % mod;\n            inv[i] = mod - inv[mod%i] * (mod / i) % mod;\n\
    \            finv[i] = finv[i - 1] * inv[i] % mod;\n        }\n    }\n    inline\
    \ long long binom(int n, int k) {\n        return ((n < 0 || k < 0 || n < k) ?\
    \ 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);\n    }\n    inline long long\
    \ factorial(int n) {\n        return fac[n];\n    }\n};\n\n//verify https://atcoder.jp/contests/abc021/tasks/abc021_d\n\
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
    \ = 1'000'000'000LL + 7; //'\n#line 8 \"test/math/CombinationMod-factorial.test.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\nusing modint = ModInt<MOD>;\n\nint\
    \ main(void){\n\tint d, l, r, k;\n    int MAX_d = 20;\n\tcin >> d >> l >> r >>\
    \ k;\n    CombinationMod<MOD> CM((1<<MAX_d));\n    vector<int> sum(MAX_d + 1,\
    \ 0);\n\tvector<long long> pow2(MAX_d + 1,1);\n\tfor (int i = 2; i <= MAX_d; ++i)\
    \ pow2[i] = (pow2[i - 1] * 2) % MOD;\n\tfor (int i = 1; i < MAX_d + 1; ++i) sum[i]\
    \ = sum[i - 1] + pow2[i];\n\tl = lower_bound(sum.begin(), sum.end(), l) - sum.begin();\n\
    \tr = lower_bound(sum.begin(), sum.end(), r) - sum.begin();\n\n\tint lca = -1;\n\
    \tif ((l + r - k) > 1 && (l + r - k) % 2 == 0) lca = (l + r - k) / 2;\n\tif(lca\
    \ == -1 || lca > l || lca > r){\n\t\tcout << 0 << endl;\n\t\treturn 0;\n\t}\n\t\
    modint ans = 1;\n\tfor (int i = 1; i <= d; ++i) {\n\t\tint cnt = pow2[i];\n\t\t\
    if (i == l) cnt--;\n\t\tif (i == r) cnt--;\n\t\tans *= CM.factorial(cnt);\n\t\
    }\n\tans *= pow2[lca];\n\tans *= pow2[l - lca];\n\tans *= pow2[r - lca];\n\tans\
    \ *= 2;\n\n\tcout << ans << endl;\n\treturn 0;}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/916\"\n\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n#include \"../../lib/30-math/CombinationMod.cpp\"\
    \n#include \"../../lib/00-util/ModInt.cpp\"\nconstexpr long long MOD = 1000'000'007;\n\
    using modint = ModInt<MOD>;\n\nint main(void){\n\tint d, l, r, k;\n    int MAX_d\
    \ = 20;\n\tcin >> d >> l >> r >> k;\n    CombinationMod<MOD> CM((1<<MAX_d));\n\
    \    vector<int> sum(MAX_d + 1, 0);\n\tvector<long long> pow2(MAX_d + 1,1);\n\t\
    for (int i = 2; i <= MAX_d; ++i) pow2[i] = (pow2[i - 1] * 2) % MOD;\n\tfor (int\
    \ i = 1; i < MAX_d + 1; ++i) sum[i] = sum[i - 1] + pow2[i];\n\tl = lower_bound(sum.begin(),\
    \ sum.end(), l) - sum.begin();\n\tr = lower_bound(sum.begin(), sum.end(), r) -\
    \ sum.begin();\n\n\tint lca = -1;\n\tif ((l + r - k) > 1 && (l + r - k) % 2 ==\
    \ 0) lca = (l + r - k) / 2;\n\tif(lca == -1 || lca > l || lca > r){\n\t\tcout\
    \ << 0 << endl;\n\t\treturn 0;\n\t}\n\tmodint ans = 1;\n\tfor (int i = 1; i <=\
    \ d; ++i) {\n\t\tint cnt = pow2[i];\n\t\tif (i == l) cnt--;\n\t\tif (i == r) cnt--;\n\
    \t\tans *= CM.factorial(cnt);\n\t}\n\tans *= pow2[lca];\n\tans *= pow2[l - lca];\n\
    \tans *= pow2[r - lca];\n\tans *= 2;\n\n\tcout << ans << endl;\n\treturn 0;}"
  dependsOn:
  - lib/30-math/CombinationMod.cpp
  - lib/00-util/ModInt.cpp
  isVerificationFile: true
  path: test/math/CombinationMod-factorial.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/CombinationMod-factorial.test.cpp
layout: document
redirect_from:
- /verify/test/math/CombinationMod-factorial.test.cpp
- /verify/test/math/CombinationMod-factorial.test.cpp.html
title: test/math/CombinationMod-factorial.test.cpp
---
