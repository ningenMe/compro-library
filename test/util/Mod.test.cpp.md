---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/util/Mod.cpp
    title: Mod
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1161
    links:
    - https://yukicoder.me/problems/no/1161
  bundledCode: "#line 1 \"test/util/Mod.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1161\"\
    \n\n#include <vector>\n#include <iostream>\n#include <array>\n#include <numeric>\n\
    using namespace std;\n#line 1 \"lib/util/Mod.cpp\"\n/*\n * @title Mod\n * @docs\
    \ md/util/Mod.md\n */\nclass Mod{\npublic:\n\t//Pow_Mod O(log(n))\n\tinline static\
    \ long long pow(long long x, long long n, long long mod) {\n\t\tlong long res\
    \ = 1;\n\t\tfor (x %= mod; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *=\
    \ x) %= mod;\n\t\treturn res;\n\t}\n\t//Inv_Mod O(log(mod))\n\tinline static long\
    \ long inv(long long x, long long mod){\n\t\treturn pow(x,mod-2,mod); \n\t}\n\
    };\n#line 9 \"test/util/Mod.test.cpp\"\n\nint main() {\n\tlong long A,B,C;\n\t\
    scanf(\"%lld%lld%lld\",&A,&B,&C);\n\tlong long ans = 0;\n\tarray<long long,100001>\
    \ cnt;\n\tfor(long long i = 1; i <= C; ++i) {\n\t\tcnt[i] = Mod::pow(i,B,C);\n\
    \t}\n\tfor(long long i = 1; i <= A%C; ++i) {\n\t\tans += cnt[i];\n\t}\n\tans +=\
    \ (accumulate(cnt.begin(),cnt.begin()+C,0LL)%C)*(A/C);\n\tprintf(\"%lld\\n\",ans%C);\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1161\"\n\n#include <vector>\n\
    #include <iostream>\n#include <array>\n#include <numeric>\nusing namespace std;\n\
    #include \"../../lib/util/Mod.cpp\"\n\nint main() {\n\tlong long A,B,C;\n\tscanf(\"\
    %lld%lld%lld\",&A,&B,&C);\n\tlong long ans = 0;\n\tarray<long long,100001> cnt;\n\
    \tfor(long long i = 1; i <= C; ++i) {\n\t\tcnt[i] = Mod::pow(i,B,C);\n\t}\n\t\
    for(long long i = 1; i <= A%C; ++i) {\n\t\tans += cnt[i];\n\t}\n\tans += (accumulate(cnt.begin(),cnt.begin()+C,0LL)%C)*(A/C);\n\
    \tprintf(\"%lld\\n\",ans%C);\n    return 0;\n}\n"
  dependsOn:
  - lib/util/Mod.cpp
  isVerificationFile: true
  path: test/util/Mod.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/util/Mod.test.cpp
layout: document
redirect_from:
- /verify/test/util/Mod.test.cpp
- /verify/test/util/Mod.test.cpp.html
title: test/util/Mod.test.cpp
---
