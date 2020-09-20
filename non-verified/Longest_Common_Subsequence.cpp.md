---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_f
  bundledCode: "#line 1 \"non-verified/Longest_Common_Subsequence.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nstring Longest_Common_Subsequence(const\
    \ string& S, const string& T){\n\tint N = S.size(), M = T.size();\n\tvector<vector<int>>\
    \ ar(N+1,vector<int>(M+1,0));\n    for(size_t i = 0; i < N; i++)\n    for(size_t\
    \ j = 0; j < M; j++)\n    ar[i+1][j+1] = (S[i] == T[j] ? ar[i][j] + 1 : max(ar[i][j\
    \ + 1],ar[i + 1][j]) );\n\n\tstring res = \"\";\n\twhile(ar[N][M]>0){\n\t\tif(S[N-1]==T[M-1]){\n\
    \t\t\tres.push_back(S[N-1]);\n\t\t\tN--,M--;\n\t\t}\n\t\telse{\n\t\t\t(ar[N-1][M]>ar[N][M-1]?N:M)--;\n\
    \t\t}\n\t}\n\n    reverse(res.begin(),res.end());\n\treturn res;\n}\n//verify\
    \ https://atcoder.jp/contests/dp/tasks/dp_f\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstring Longest_Common_Subsequence(const\
    \ string& S, const string& T){\n\tint N = S.size(), M = T.size();\n\tvector<vector<int>>\
    \ ar(N+1,vector<int>(M+1,0));\n    for(size_t i = 0; i < N; i++)\n    for(size_t\
    \ j = 0; j < M; j++)\n    ar[i+1][j+1] = (S[i] == T[j] ? ar[i][j] + 1 : max(ar[i][j\
    \ + 1],ar[i + 1][j]) );\n\n\tstring res = \"\";\n\twhile(ar[N][M]>0){\n\t\tif(S[N-1]==T[M-1]){\n\
    \t\t\tres.push_back(S[N-1]);\n\t\t\tN--,M--;\n\t\t}\n\t\telse{\n\t\t\t(ar[N-1][M]>ar[N][M-1]?N:M)--;\n\
    \t\t}\n\t}\n\n    reverse(res.begin(),res.end());\n\treturn res;\n}\n//verify\
    \ https://atcoder.jp/contests/dp/tasks/dp_f"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Longest_Common_Subsequence.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Longest_Common_Subsequence.cpp
layout: document
redirect_from:
- /library/non-verified/Longest_Common_Subsequence.cpp
- /library/non-verified/Longest_Common_Subsequence.cpp.html
title: non-verified/Longest_Common_Subsequence.cpp
---
