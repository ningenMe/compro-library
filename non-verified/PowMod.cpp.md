---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"non-verified/PowMod.cpp\"\n//Pow_Mod O(log(n))\nlong long\
    \ PowMod(long long x, long long n, long long mod) {\n    long long res = 1;\n\
    \    for (; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;\n \
    \   return res;\n}\n\n//Inv_Mod O(log(mod))\nlong long InvMod(long long x, long\
    \ long mod){\n\treturn PowMod(x,mod-2,mod); \n}\n"
  code: "//Pow_Mod O(log(n))\nlong long PowMod(long long x, long long n, long long\
    \ mod) {\n    long long res = 1;\n    for (; n > 0; n >>= 1, (x *= x) %= mod)\
    \ if (n & 1) (res *= x) %= mod;\n    return res;\n}\n\n//Inv_Mod O(log(mod))\n\
    long long InvMod(long long x, long long mod){\n\treturn PowMod(x,mod-2,mod); \n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/PowMod.cpp
  requiredBy: []
  timestamp: '2021-04-21 01:33:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/PowMod.cpp
layout: document
redirect_from:
- /library/non-verified/PowMod.cpp
- /library/non-verified/PowMod.cpp.html
title: non-verified/PowMod.cpp
---
