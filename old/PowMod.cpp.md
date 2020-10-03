---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/PowMod.cpp\"\n//Pow_Mod O(log(n))\nlong long PowMod(long\
    \ long x, long long n, long long mod) {\n    long long res = 1;\n    for (; n\
    \ > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;\n    return res;\n\
    }\n\n//Inv_Mod O(log(mod))\nlong long InvMod(long long x, long long mod){\n\t\
    return PowMod(x,mod-2,mod); \n}\n"
  code: "//Pow_Mod O(log(n))\nlong long PowMod(long long x, long long n, long long\
    \ mod) {\n    long long res = 1;\n    for (; n > 0; n >>= 1, (x *= x) %= mod)\
    \ if (n & 1) (res *= x) %= mod;\n    return res;\n}\n\n//Inv_Mod O(log(mod))\n\
    long long InvMod(long long x, long long mod){\n\treturn PowMod(x,mod-2,mod); \n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: old/PowMod.cpp
  requiredBy: []
  timestamp: '2020-08-15 06:33:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/PowMod.cpp
layout: document
redirect_from:
- /library/old/PowMod.cpp
- /library/old/PowMod.cpp.html
title: old/PowMod.cpp
---
