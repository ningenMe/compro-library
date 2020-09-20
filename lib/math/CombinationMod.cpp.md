---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/CombinationMod-binom.test.cpp
    title: test/math/CombinationMod-binom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/CombinationMod-factorial.test.cpp
    title: test/math/CombinationMod-factorial.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: CombinationMod
    links:
    - https://atcoder.jp/contests/abc021/tasks/abc021_d
  bundledCode: "#line 1 \"lib/math/CombinationMod.cpp\"\n/*\n * @title CombinationMod\n\
    \ */\ntemplate<long long mod> class CombinationMod {\n\tvector<long long> fac,finv,inv;\n\
    public:\n\tCombinationMod(int N) : fac(N + 1), finv(N + 1), inv(N + 1) {\n\t\t\
    fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;\n\t\tfor (int i = 2; i <= N;\
    \ ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % mod;\n\t\t\tinv[i] = mod - inv[mod%i]\
    \ * (mod / i) % mod;\n\t\t\tfinv[i] = finv[i - 1] * inv[i] % mod;\n\t\t}\n\t}\n\
    \tinline long long binom(int n, int k) {\n\t\treturn ((n < 0 || k < 0 || n < k)\
    \ ? 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);\n\t}\n\tinline long long\
    \ factorial(int n) {\n\t\treturn fac[n];\n\t}\n};\n\n//verify https://atcoder.jp/contests/abc021/tasks/abc021_d\n"
  code: "/*\n * @title CombinationMod\n */\ntemplate<long long mod> class CombinationMod\
    \ {\n\tvector<long long> fac,finv,inv;\npublic:\n\tCombinationMod(int N) : fac(N\
    \ + 1), finv(N + 1), inv(N + 1) {\n\t\tfac[0] = fac[1] = finv[0] = finv[1] = inv[1]\
    \ = 1;\n\t\tfor (int i = 2; i <= N; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % mod;\n\
    \t\t\tinv[i] = mod - inv[mod%i] * (mod / i) % mod;\n\t\t\tfinv[i] = finv[i - 1]\
    \ * inv[i] % mod;\n\t\t}\n\t}\n\tinline long long binom(int n, int k) {\n\t\t\
    return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % mod)\
    \ % mod);\n\t}\n\tinline long long factorial(int n) {\n\t\treturn fac[n];\n\t\
    }\n};\n\n//verify https://atcoder.jp/contests/abc021/tasks/abc021_d"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/CombinationMod.cpp
  requiredBy: []
  timestamp: '2020-05-24 03:14:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/CombinationMod-binom.test.cpp
  - test/math/CombinationMod-factorial.test.cpp
documentation_of: lib/math/CombinationMod.cpp
layout: document
redirect_from:
- /library/lib/math/CombinationMod.cpp
- /library/lib/math/CombinationMod.cpp.html
title: CombinationMod
---
