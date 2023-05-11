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
    - https://atcoder.jp/contests/abc135/tasks/abc135_f
  bundledCode: "#line 1 \"non-verified/ZAlgorithm.cpp\"\n// O(N)\nvector<int> ZAlgorithm(const\
    \ string str) {\n\tint N = str.size();\n\tvector<int> res(N);\n\tfor(int i = 1,\
    \ j = 0; i < N; i++) {\n\t\tif(i + res[i - j] < j + res[j]) {\n\t\t\tres[i] =\
    \ res[i - j];\n\t\t} \n\t\telse {\n\t\t\tint k = max(0, j + res[j] - i);\n\t\t\
    \twhile(i + k < N && str[k] == str[i + k]) ++k;\n\t\t\tres[j = i] = k;\n\t\t}\n\
    \t}\n\tres[0] = N;\n\treturn res;\n}\n//verify https://atcoder.jp/contests/abc135/tasks/abc135_f\n"
  code: "// O(N)\nvector<int> ZAlgorithm(const string str) {\n\tint N = str.size();\n\
    \tvector<int> res(N);\n\tfor(int i = 1, j = 0; i < N; i++) {\n\t\tif(i + res[i\
    \ - j] < j + res[j]) {\n\t\t\tres[i] = res[i - j];\n\t\t} \n\t\telse {\n\t\t\t\
    int k = max(0, j + res[j] - i);\n\t\t\twhile(i + k < N && str[k] == str[i + k])\
    \ ++k;\n\t\t\tres[j = i] = k;\n\t\t}\n\t}\n\tres[0] = N;\n\treturn res;\n}\n//verify\
    \ https://atcoder.jp/contests/abc135/tasks/abc135_f"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/ZAlgorithm.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/ZAlgorithm.cpp
layout: document
redirect_from:
- /library/non-verified/ZAlgorithm.cpp
- /library/non-verified/ZAlgorithm.cpp.html
title: non-verified/ZAlgorithm.cpp
---
