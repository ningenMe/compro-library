---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/50-string/LevenshteinDistance-1.test.cpp
    title: test/50-string/LevenshteinDistance-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/50-string/LevenshteinDistance-2.test.cpp
    title: test/50-string/LevenshteinDistance-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/string/LevenshteinDistance.md
    document_title: "LevenshteinDistance - \u7DE8\u96C6\u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"lib/50-string/LevenshteinDistance.cpp\"\n/*\n * @title LevenshteinDistance\
    \ - \u7DE8\u96C6\u8DDD\u96E2\n * @docs md/string/LevenshteinDistance.md\n */\n\
    int LevenshteinDistance(string S, string T,char dummy='#') {\n    int N = S.size();\n\
    \    int M = T.size();\n    S.push_back(dummy);T.push_back(dummy);\n    vector<vector<int>>\
    \ dp(N+2, vector<int>(M+2,N+M));\n    dp[0][0]=0;\n    for(int i=0;i<=N;++i) {\n\
    \        for(int j=0;j<=M;++j) {\n            //change\n            dp[i+1][j+1]\
    \ = min(dp[i+1][j+1],dp[i][j]+(S[i]!=T[j]));            \n            //delete\n\
    \            dp[i+1][j]   = min(dp[i+1][j],dp[i][j]+1);            \n        \
    \    //insert\n            dp[i][j+1]   = min(dp[i][j+1],dp[i][j]+1);        \
    \    \n        }\n    }\n    return dp[N][M];\n}\n"
  code: "/*\n * @title LevenshteinDistance - \u7DE8\u96C6\u8DDD\u96E2\n * @docs md/string/LevenshteinDistance.md\n\
    \ */\nint LevenshteinDistance(string S, string T,char dummy='#') {\n    int N\
    \ = S.size();\n    int M = T.size();\n    S.push_back(dummy);T.push_back(dummy);\n\
    \    vector<vector<int>> dp(N+2, vector<int>(M+2,N+M));\n    dp[0][0]=0;\n   \
    \ for(int i=0;i<=N;++i) {\n        for(int j=0;j<=M;++j) {\n            //change\n\
    \            dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+(S[i]!=T[j]));         \
    \   \n            //delete\n            dp[i+1][j]   = min(dp[i+1][j],dp[i][j]+1);\
    \            \n            //insert\n            dp[i][j+1]   = min(dp[i][j+1],dp[i][j]+1);\
    \            \n        }\n    }\n    return dp[N][M];\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/50-string/LevenshteinDistance.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/50-string/LevenshteinDistance-2.test.cpp
  - test/50-string/LevenshteinDistance-1.test.cpp
documentation_of: lib/50-string/LevenshteinDistance.cpp
layout: document
redirect_from:
- /library/lib/50-string/LevenshteinDistance.cpp
- /library/lib/50-string/LevenshteinDistance.cpp.html
title: "LevenshteinDistance - \u7DE8\u96C6\u8DDD\u96E2"
---
### LevenshteinDistance
- 文字列Sを文字列Tに変換するときの編集距離を求める
- 

### メソッド
- int LevenshteinDistance(string S, string T,char dummy='#')
  - dummyはS,Tに含まれない文字列が良い。
  - SのサイズをN,TのサイズをMとして $O(NM)$