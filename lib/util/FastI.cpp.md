---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/FastI-readint.test.cpp
    title: test/util/FastI-readint.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/util/FastI.md
    document_title: FastI
    links: []
  bundledCode: "#line 1 \"lib/util/FastI.cpp\"\n/*\n * @title FastI\n * @docs md/util/FastI.md\n\
    \ */\nclass FastI{\nprivate:\n    inline static constexpr int ch_0='0';\n    inline\
    \ static constexpr int ch_9='9';\n    template<typename T> inline static void\
    \ readint(T &x) {\n        int neg=0; char ch=getchar(); x=0;\n        if(ch=='-')\
    \ neg=1,ch=getchar();\n        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar())\
    \ x = x*10 + (ch-ch_0); \n        if(neg) x*=-1;\n    }\npublic:\n    inline static\
    \ void read(int &x) {readint<int>(x);}\n    inline static void read(long long\
    \ &x) {readint<long long>(x);}\n};\n"
  code: "/*\n * @title FastI\n * @docs md/util/FastI.md\n */\nclass FastI{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    template<typename T> inline static void readint(T &x) {\n        int neg=0;\
    \ char ch=getchar(); x=0;\n        if(ch=='-') neg=1,ch=getchar();\n        for(;(ch_0\
    \ <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0); \n        if(neg)\
    \ x*=-1;\n    }\npublic:\n    inline static void read(int &x) {readint<int>(x);}\n\
    \    inline static void read(long long &x) {readint<long long>(x);}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/FastI.cpp
  requiredBy: []
  timestamp: '2023-05-11 03:51:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/FastI-readint.test.cpp
documentation_of: lib/util/FastI.cpp
layout: document
redirect_from:
- /library/lib/util/FastI.cpp
- /library/lib/util/FastI.cpp.html
title: FastI
---
### ModInt
- 自作の高速Input
- cinより速いはずだけど、上位層に比べると全然速くない

### TODO
- char, string, double, unsinged int などを受け取れるようにする