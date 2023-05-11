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
    - https://atcoder.jp/contests/agc039/tasks/agc039_a
  bundledCode: "#line 1 \"non-verified/Rarts.cpp\"\nvector<pair<char,long long>> Rarts(string\
    \ S){\n\tchar ch = S[0];\n\tint cnt = 1;\n\tvector<pair<char,long long>> res;\n\
    \ \tfor(int i = 1; i < S.size(); ++i){\n\t\t if(S[i]==ch) {\n\t\t\t cnt++;\n\t\
    \t }\n\t\t else{\n\t\t\t res.push_back({ch,cnt});\n\t\t\t ch = S[i];\n\t\t\t cnt\
    \ = 1;\n\t\t }\n\t}\n\tres.push_back({ch,cnt});\n\treturn res;\n}\n\n//verify\
    \ https://atcoder.jp/contests/agc039/tasks/agc039_a\n"
  code: "vector<pair<char,long long>> Rarts(string S){\n\tchar ch = S[0];\n\tint cnt\
    \ = 1;\n\tvector<pair<char,long long>> res;\n \tfor(int i = 1; i < S.size(); ++i){\n\
    \t\t if(S[i]==ch) {\n\t\t\t cnt++;\n\t\t }\n\t\t else{\n\t\t\t res.push_back({ch,cnt});\n\
    \t\t\t ch = S[i];\n\t\t\t cnt = 1;\n\t\t }\n\t}\n\tres.push_back({ch,cnt});\n\t\
    return res;\n}\n\n//verify https://atcoder.jp/contests/agc039/tasks/agc039_a\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Rarts.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Rarts.cpp
layout: document
redirect_from:
- /library/non-verified/Rarts.cpp
- /library/non-verified/Rarts.cpp.html
title: non-verified/Rarts.cpp
---
