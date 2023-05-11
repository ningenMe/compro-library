---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc150/tasks/abc150_f
  bundledCode: "#line 1 \"non-verified/ZArray.cpp\"\n\n// O(N)\ntemplate<class T>\
    \ vector<int> ZArray(const vector<T> arr) {\n\tint N = arr.size();\n\tvector<int>\
    \ res(N);\n\tfor(int i = 1, j = 0; i < N; i++) {\n\t\tif(i + res[i - j] < j +\
    \ res[j]) {\n\t\t\tres[i] = res[i - j];\n\t\t} \n\t\telse {\n\t\t\tint k = max(0,\
    \ j + res[j] - i);\n\t\t\twhile(i + k < N && arr[k] == arr[i + k]) ++k;\n\t\t\t\
    res[j = i] = k;\n\t\t}\n\t}\n\tres[0] = N;\n\treturn res;\n}\n//verify https://atcoder.jp/contests/abc150/tasks/abc150_f\n"
  code: "\n// O(N)\ntemplate<class T> vector<int> ZArray(const vector<T> arr) {\n\t\
    int N = arr.size();\n\tvector<int> res(N);\n\tfor(int i = 1, j = 0; i < N; i++)\
    \ {\n\t\tif(i + res[i - j] < j + res[j]) {\n\t\t\tres[i] = res[i - j];\n\t\t}\
    \ \n\t\telse {\n\t\t\tint k = max(0, j + res[j] - i);\n\t\t\twhile(i + k < N &&\
    \ arr[k] == arr[i + k]) ++k;\n\t\t\tres[j = i] = k;\n\t\t}\n\t}\n\tres[0] = N;\n\
    \treturn res;\n}\n//verify https://atcoder.jp/contests/abc150/tasks/abc150_f"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/ZArray.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/ZArray.cpp
layout: document
redirect_from:
- /library/non-verified/ZArray.cpp
- /library/non-verified/ZArray.cpp.html
title: non-verified/ZArray.cpp
---
