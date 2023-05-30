---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/LongestCommonSubsequence.test.cpp
    title: test/string/LongestCommonSubsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/string/LongestCommonSubsequence.md
    document_title: LongestCommonSubsequence - LCS
    links: []
  bundledCode: "#line 1 \"lib/50-string/LongestCommonSubsequence.cpp\"\n/*\n * @title\
    \ LongestCommonSubsequence - LCS\n * @docs md/string/LongestCommonSubsequence.md\n\
    \ */\nstring LongestCommonSubsequence(const string& S, const string& T){\n\tint\
    \ N = S.size(), M = T.size();\n\tvector<int> dp((N+1)*(M+1),0);\n    for(size_t\
    \ i = 0; i < N; i++) {\n        for(size_t j = 0; j < M; j++) {\n            dp[(i+1)*(M+1)+j+1]\
    \ = (S[i] == T[j] ? dp[i*(M+1)+j] + 1 : max(dp[i*(M+1)+j + 1],dp[(i+1)*(M+1)+j])\
    \ );\n        }\n    }\n    int a=N,b=M;\n\tstring res = \"\";\n\twhile(dp[a*(M+1)+b]>0)\
    \ {\n\t\tif(S[a-1]==T[b-1]) res.push_back(S[a-1]),a--,b--;\n\t\telse (dp[(a-1)*(M+1)+b]>dp[a*(M+1)+b-1]?a:b)--;\n\
    \t}\n    reverse(res.begin(),res.end());\n\treturn res;\n}\n"
  code: "/*\n * @title LongestCommonSubsequence - LCS\n * @docs md/string/LongestCommonSubsequence.md\n\
    \ */\nstring LongestCommonSubsequence(const string& S, const string& T){\n\tint\
    \ N = S.size(), M = T.size();\n\tvector<int> dp((N+1)*(M+1),0);\n    for(size_t\
    \ i = 0; i < N; i++) {\n        for(size_t j = 0; j < M; j++) {\n            dp[(i+1)*(M+1)+j+1]\
    \ = (S[i] == T[j] ? dp[i*(M+1)+j] + 1 : max(dp[i*(M+1)+j + 1],dp[(i+1)*(M+1)+j])\
    \ );\n        }\n    }\n    int a=N,b=M;\n\tstring res = \"\";\n\twhile(dp[a*(M+1)+b]>0)\
    \ {\n\t\tif(S[a-1]==T[b-1]) res.push_back(S[a-1]),a--,b--;\n\t\telse (dp[(a-1)*(M+1)+b]>dp[a*(M+1)+b-1]?a:b)--;\n\
    \t}\n    reverse(res.begin(),res.end());\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/50-string/LongestCommonSubsequence.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/LongestCommonSubsequence.test.cpp
documentation_of: lib/50-string/LongestCommonSubsequence.cpp
layout: document
redirect_from:
- /library/lib/50-string/LongestCommonSubsequence.cpp
- /library/lib/50-string/LongestCommonSubsequence.cpp.html
title: LongestCommonSubsequence - LCS
---
### LongestCommonSubsequence
- 文字列Sと文字列Tの最小共通部分列を求める
- 

### メソッド
- string LongestCommonSubsequence(const string& S, const string& T)
  - SのサイズをN,TのサイズをMとして $O(NM)$