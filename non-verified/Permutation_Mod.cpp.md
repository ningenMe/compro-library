---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc067/tasks/arc067_c
  bundledCode: "#line 1 \"non-verified/Permutation_Mod.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//Pow_Mod O(log(N))\nlong long Pow_Mod(long long x, long\
    \ long n, long long mod) {\n    long long res = 1;\n    for (; n > 0; n >>= 1,\
    \ (x *= x) %= mod) if (n & 1) (res *= x) %= mod;\n    return res;\n}\n\n//Permutation_Mod\
    \ O(N^2)\nvector<vector<long long>> Permutation_Mod(long long N, long long mod)\
    \ {\n    vector<long long> fac(N + 1, 1);\n    for (long long i = 1; i <= N; ++i)\
    \ fac[i] = (fac[i - 1] * i) % mod;\n    vector<long long> inv(N + 1, 1);\n   \
    \ for (long long i = 1; i <= N; ++i) inv[i] = Pow_Mod(fac[i], mod - 2, mod);\n\
    \    vector<vector<long long>> res(N + 1, vector<long long>(N + 1, 1));\n    for\
    \ (long long i = 1; i <= N; ++i) for (long long j = 1; j <= i; ++j) res[i][j]\
    \ = (fac[i] * inv[i - j]) % mod;\n    return res;\n}\n\n//verify https://atcoder.jp/contests/arc067/tasks/arc067_c\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//Pow_Mod O(log(N))\nlong\
    \ long Pow_Mod(long long x, long long n, long long mod) {\n    long long res =\
    \ 1;\n    for (; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;\n\
    \    return res;\n}\n\n//Permutation_Mod O(N^2)\nvector<vector<long long>> Permutation_Mod(long\
    \ long N, long long mod) {\n    vector<long long> fac(N + 1, 1);\n    for (long\
    \ long i = 1; i <= N; ++i) fac[i] = (fac[i - 1] * i) % mod;\n    vector<long long>\
    \ inv(N + 1, 1);\n    for (long long i = 1; i <= N; ++i) inv[i] = Pow_Mod(fac[i],\
    \ mod - 2, mod);\n    vector<vector<long long>> res(N + 1, vector<long long>(N\
    \ + 1, 1));\n    for (long long i = 1; i <= N; ++i) for (long long j = 1; j <=\
    \ i; ++j) res[i][j] = (fac[i] * inv[i - j]) % mod;\n    return res;\n}\n\n//verify\
    \ https://atcoder.jp/contests/arc067/tasks/arc067_c"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Permutation_Mod.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Permutation_Mod.cpp
layout: document
redirect_from:
- /library/non-verified/Permutation_Mod.cpp
- /library/non-verified/Permutation_Mod.cpp.html
title: non-verified/Permutation_Mod.cpp
---
