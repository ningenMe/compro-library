---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/Mod.test.cpp
    title: test/util/Mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Mod
    links: []
  bundledCode: "#line 1 \"lib/util/Mod.cpp\"\n/*\n * @title Mod\n */\nclass Mod{\n\
    public:\n\t//Pow_Mod O(log(n))\n\tinline static long long pow(long long x, long\
    \ long n, long long mod) {\n\t\tlong long res = 1;\n\t\tfor (x %= mod; n > 0;\
    \ n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;\n\t\treturn res;\n\t\
    }\n\t//Inv_Mod O(log(mod))\n\tinline static long long inv(long long x, long long\
    \ mod){\n\t\treturn pow(x,mod-2,mod); \n\t}\n};\n"
  code: "/*\n * @title Mod\n */\nclass Mod{\npublic:\n\t//Pow_Mod O(log(n))\n\tinline\
    \ static long long pow(long long x, long long n, long long mod) {\n\t\tlong long\
    \ res = 1;\n\t\tfor (x %= mod; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res\
    \ *= x) %= mod;\n\t\treturn res;\n\t}\n\t//Inv_Mod O(log(mod))\n\tinline static\
    \ long long inv(long long x, long long mod){\n\t\treturn pow(x,mod-2,mod); \n\t\
    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/Mod.cpp
  requiredBy: []
  timestamp: '2020-08-15 06:33:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/Mod.test.cpp
documentation_of: lib/util/Mod.cpp
layout: document
redirect_from:
- /library/lib/util/Mod.cpp
- /library/lib/util/Mod.cpp.html
title: Mod
---
