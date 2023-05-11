---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/string/Zalgorithm.md
    document_title: Zalgorithm
    links: []
  bundledCode: "#line 1 \"lib/string/Zalgorithm.cpp\"\n/*\n * @title Zalgorithm\n\
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
  path: lib/string/Zalgorithm.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/Zalgorithm.cpp
layout: document
redirect_from:
- /library/lib/string/Zalgorithm.cpp
- /library/lib/string/Zalgorithm.cpp.html
title: Zalgorithm
---
