---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/util/Mod.test.cpp
    title: test/util/Mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/util/Mod.md
    document_title: Mod
    links: []
  bundledCode: "#line 1 \"lib/util/Mod.cpp\"\n/*\n * @title Mod\n * @docs md/util/Mod.md\n\
    \ */\nclass Mod{\npublic:\n\t//Pow_Mod O(log(n))\n\tinline static long long pow(long\
    \ long x, long long n, long long mod) {\n\t\tlong long res = 1;\n\t\tfor (x %=\
    \ mod; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;\n\t\treturn\
    \ res;\n\t}\n\t//Inv_Mod O(log(mod))\n\tinline static long long inv(long long\
    \ x, long long mod){\n\t\treturn pow(x,mod-2,mod); \n\t}\n};\n"
  code: "/*\n * @title Mod\n * @docs md/util/Mod.md\n */\nclass Mod{\npublic:\n\t\
    //Pow_Mod O(log(n))\n\tinline static long long pow(long long x, long long n, long\
    \ long mod) {\n\t\tlong long res = 1;\n\t\tfor (x %= mod; n > 0; n >>= 1, (x *=\
    \ x) %= mod) if (n & 1) (res *= x) %= mod;\n\t\treturn res;\n\t}\n\t//Inv_Mod\
    \ O(log(mod))\n\tinline static long long inv(long long x, long long mod){\n\t\t\
    return pow(x,mod-2,mod); \n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/Mod.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/util/Mod.test.cpp
documentation_of: lib/util/Mod.cpp
layout: document
redirect_from:
- /library/lib/util/Mod.cpp
- /library/lib/util/Mod.cpp.html
title: Mod
---
