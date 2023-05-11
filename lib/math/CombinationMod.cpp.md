---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/CombinationMod.md
    document_title: "CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\
      \u968E\u4E57"
    links:
    - https://atcoder.jp/contests/abc021/tasks/abc021_d
  bundledCode: "#line 1 \"lib/math/CombinationMod.cpp\"\n/*\n * @title CombinationMod\
    \ - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57\n * @docs md/math/CombinationMod.md\n\
    \ */\ntemplate<long long mod> class CombinationMod {\n    vector<long long> fac,finv,inv;\n\
    public:\n    CombinationMod(int N) : fac(N + 1), finv(N + 1), inv(N + 1) {\n \
    \       fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;\n        for (int i\
    \ = 2; i <= N; ++i) {\n            fac[i] = fac[i - 1] * i % mod;\n          \
    \  inv[i] = mod - inv[mod%i] * (mod / i) % mod;\n            finv[i] = finv[i\
    \ - 1] * inv[i] % mod;\n        }\n    }\n    inline long long binom(int n, int\
    \ k) {\n        return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n\
    \ - k] % mod) % mod);\n    }\n    inline long long factorial(int n) {\n      \
    \  return fac[n];\n    }\n};\n\n//verify https://atcoder.jp/contests/abc021/tasks/abc021_d\n"
  code: "/*\n * @title CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\
    \u968E\u4E57\n * @docs md/math/CombinationMod.md\n */\ntemplate<long long mod>\
    \ class CombinationMod {\n    vector<long long> fac,finv,inv;\npublic:\n    CombinationMod(int\
    \ N) : fac(N + 1), finv(N + 1), inv(N + 1) {\n        fac[0] = fac[1] = finv[0]\
    \ = finv[1] = inv[1] = 1;\n        for (int i = 2; i <= N; ++i) {\n          \
    \  fac[i] = fac[i - 1] * i % mod;\n            inv[i] = mod - inv[mod%i] * (mod\
    \ / i) % mod;\n            finv[i] = finv[i - 1] * inv[i] % mod;\n        }\n\
    \    }\n    inline long long binom(int n, int k) {\n        return ((n < 0 ||\
    \ k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);\n    }\n\
    \    inline long long factorial(int n) {\n        return fac[n];\n    }\n};\n\n\
    //verify https://atcoder.jp/contests/abc021/tasks/abc021_d"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/CombinationMod.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/CombinationMod.cpp
layout: document
redirect_from:
- /library/lib/math/CombinationMod.cpp
- /library/lib/math/CombinationMod.cpp.html
title: "CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57"
---
