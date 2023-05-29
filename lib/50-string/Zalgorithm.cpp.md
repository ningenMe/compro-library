---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/50-string/Zalgorithm.test.cpp
    title: test/50-string/Zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/string/Zalgorithm.md
    document_title: Zalgorithm
    links: []
  bundledCode: "#line 1 \"lib/50-string/Zalgorithm.cpp\"\n/*\n * @title Zalgorithm\n\
    \ * @docs md/string/Zalgorithm.md\n */\nclass Zalgorithm{\n    vector<int> zarray;\n\
    \    template<class T> void init(const vector<T>& ar) {\n        int N = ar.size();\n\
    \        for(int i = 1, j = 0; i < N; ++i) {\n            if(i + zarray[i - j]\
    \ < j + zarray[j]) {\n                zarray[i] = zarray[i - j];\n           \
    \ } \n            else {\n                int k = max(0, j + zarray[j] - i);\n\
    \                while(i + k < N && ar[k] == ar[i + k]) ++k;\n               \
    \ zarray[j = i] = k;\n            }\n        }\n        zarray[0] = N;\n    }\n\
    public:\n    template<class T> Zalgorithm(const vector<T>& ar) : zarray(ar.size())\
    \ {\n        init(ar);\n    }\n    Zalgorithm(const string& s) : zarray(s.size())\
    \ {\n        vector<char> ar(s.size());\n        for(int i=0; i<s.size(); ++i)\
    \ ar[i]=s[i];\n        init(ar);\n    }\n\tinline int operator[](int idx) {\n\t\
    \treturn zarray[idx];\n\t}\n};\n"
  code: "/*\n * @title Zalgorithm\n * @docs md/string/Zalgorithm.md\n */\nclass Zalgorithm{\n\
    \    vector<int> zarray;\n    template<class T> void init(const vector<T>& ar)\
    \ {\n        int N = ar.size();\n        for(int i = 1, j = 0; i < N; ++i) {\n\
    \            if(i + zarray[i - j] < j + zarray[j]) {\n                zarray[i]\
    \ = zarray[i - j];\n            } \n            else {\n                int k\
    \ = max(0, j + zarray[j] - i);\n                while(i + k < N && ar[k] == ar[i\
    \ + k]) ++k;\n                zarray[j = i] = k;\n            }\n        }\n \
    \       zarray[0] = N;\n    }\npublic:\n    template<class T> Zalgorithm(const\
    \ vector<T>& ar) : zarray(ar.size()) {\n        init(ar);\n    }\n    Zalgorithm(const\
    \ string& s) : zarray(s.size()) {\n        vector<char> ar(s.size());\n      \
    \  for(int i=0; i<s.size(); ++i) ar[i]=s[i];\n        init(ar);\n    }\n\tinline\
    \ int operator[](int idx) {\n\t\treturn zarray[idx];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/50-string/Zalgorithm.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/50-string/Zalgorithm.test.cpp
documentation_of: lib/50-string/Zalgorithm.cpp
layout: document
redirect_from:
- /library/lib/50-string/Zalgorithm.cpp
- /library/lib/50-string/Zalgorithm.cpp.html
title: Zalgorithm
---
