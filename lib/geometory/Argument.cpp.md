---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometory/Argument.cpp
layout: document
redirect_from:
- /library/lib/geometory/Argument.cpp
- /library/lib/geometory/Argument.cpp.html
title: "Argument - \u504F\u89D2"
---
