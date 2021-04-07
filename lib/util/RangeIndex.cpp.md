---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/RangeIndex.test.cpp
    title: test/util/RangeIndex.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/util/RangeIndex.md
    document_title: "RangeIndex - \u533A\u9593index"
    links: []
  bundledCode: "#line 1 \"lib/util/RangeIndex.cpp\"\n/*\n * @title RangeIndex - \u533A\
    \u9593index\n * @docs md/util/RangeIndex.md\n */\nclass RangeIndex{\n\tint length;\n\
    public:\n\tRangeIndex(const int N) {\n\t\tfor (length = 1; length <= N; length\
    \ *= 2);\n\t}\n\t//[l,r)\n\tvector<int> range(int l,int r) {\n\t\tvector<int>\
    \ res;\n\t\tfor(l += length, r += length; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1)\
    \ res.push_back(l++);\n\t\t\tif(r&1) res.push_back(--r);\n\t\t}\n\t\treturn res;\n\
    \t}\n\t// ranges that include x\n\tvector<int> include_range(int x) {\n\t\tvector<int>\
    \ res;\n        for(int i=x+length; i; i >>= 1) res.push_back(i);\n\t\treturn\
    \ res;\n\t}\n\tinline int operator[](int idx) {\n\t\treturn idx+length;\n\t}\n\
    \tinline size_t size(void){\n\t\treturn 2*length;\n\t}\n};\n"
  code: "/*\n * @title RangeIndex - \u533A\u9593index\n * @docs md/util/RangeIndex.md\n\
    \ */\nclass RangeIndex{\n\tint length;\npublic:\n\tRangeIndex(const int N) {\n\
    \t\tfor (length = 1; length <= N; length *= 2);\n\t}\n\t//[l,r)\n\tvector<int>\
    \ range(int l,int r) {\n\t\tvector<int> res;\n\t\tfor(l += length, r += length;\
    \ l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) res.push_back(l++);\n\t\t\tif(r&1) res.push_back(--r);\n\
    \t\t}\n\t\treturn res;\n\t}\n\t// ranges that include x\n\tvector<int> include_range(int\
    \ x) {\n\t\tvector<int> res;\n        for(int i=x+length; i; i >>= 1) res.push_back(i);\n\
    \t\treturn res;\n\t}\n\tinline int operator[](int idx) {\n\t\treturn idx+length;\n\
    \t}\n\tinline size_t size(void){\n\t\treturn 2*length;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/RangeIndex.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/RangeIndex.test.cpp
documentation_of: lib/util/RangeIndex.cpp
layout: document
redirect_from:
- /library/lib/util/RangeIndex.cpp
- /library/lib/util/RangeIndex.cpp.html
title: "RangeIndex - \u533A\u9593index"
---
