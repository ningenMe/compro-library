---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/util/FastI.cpp
    title: FastI
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"test/util/FastI-readint.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/util/FastI.cpp\"\n\
    /*\n * @title FastI\n * @docs md/util/FastI.md\n */\nclass FastI{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    template<typename T> inline static void readint(T &x) {\n        int neg=0;\
    \ char ch=getchar(); x=0;\n        if(ch=='-') neg=1,ch=getchar();\n        for(;(ch_0\
    \ <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0); \n        if(neg)\
    \ x*=-1;\n    }\npublic:\n    inline static void read(int &x) {readint<int>(x);}\n\
    \    inline static void read(long long &x) {readint<long long>(x);}\n};\n#line\
    \ 6 \"test/util/FastI-readint.test.cpp\"\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int t; FastI::read(t);\n    while(t--) {\n        long long x,y; FastI::read(x);FastI::read(y);\n\
    \        cout << x+y << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ <iostream>\nusing namespace std;\n#include \"../../lib/util/FastI.cpp\"\n\n\
    int main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int t; FastI::read(t);\n\
    \    while(t--) {\n        long long x,y; FastI::read(x);FastI::read(y);\n   \
    \     cout << x+y << \"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/util/FastI.cpp
  isVerificationFile: true
  path: test/util/FastI-readint.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:31:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/util/FastI-readint.test.cpp
layout: document
redirect_from:
- /verify/test/util/FastI-readint.test.cpp
- /verify/test/util/FastI-readint.test.cpp.html
title: test/util/FastI-readint.test.cpp
---
