---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometory/Argument-sort-by-atan2l.test.cpp
    title: test/geometory/Argument-sort-by-atan2l.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/geometory/Argument.md
    document_title: "Argument - \u504F\u89D2"
    links: []
  bundledCode: "#line 1 \"lib/geometory/Argument.cpp\"\n/*\n * @title Argument - \u504F\
    \u89D2\n * @docs md/geometory/Argument.md\n */\nclass Argument {\npublic:\n  \
    \  template<class T> inline static vector<int> sort_by_atan2l(vector<pair<T,T>>\
    \ points){\n        int N = points.size();\n        vector<long double> arg(N);\n\
    \        for(int i = 0; i < N; ++i) arg[i] = atan2l(points[i].second,points[i].first);\n\
    \        vector<int> res(N);\n        iota(res.begin(),res.end(),0);\n       \
    \ sort(res.begin(),res.end(),[&](int l,int r){return arg[l] < arg[r];});\n   \
    \     return res;\n    }\n};\n"
  code: "/*\n * @title Argument - \u504F\u89D2\n * @docs md/geometory/Argument.md\n\
    \ */\nclass Argument {\npublic:\n    template<class T> inline static vector<int>\
    \ sort_by_atan2l(vector<pair<T,T>> points){\n        int N = points.size();\n\
    \        vector<long double> arg(N);\n        for(int i = 0; i < N; ++i) arg[i]\
    \ = atan2l(points[i].second,points[i].first);\n        vector<int> res(N);\n \
    \       iota(res.begin(),res.end(),0);\n        sort(res.begin(),res.end(),[&](int\
    \ l,int r){return arg[l] < arg[r];});\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/geometory/Argument.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:13:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometory/Argument-sort-by-atan2l.test.cpp
documentation_of: lib/geometory/Argument.cpp
layout: document
redirect_from:
- /library/lib/geometory/Argument.cpp
- /library/lib/geometory/Argument.cpp.html
title: "Argument - \u504F\u89D2"
---
