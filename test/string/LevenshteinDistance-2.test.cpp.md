---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/LevenshteinDistance.cpp
    title: "LevenshteinDistance - \u7DE8\u96C6\u8DDD\u96E2"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"test/string/LevenshteinDistance-2.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <string>\nusing namespace std;\n#line\
    \ 1 \"lib/string/LevenshteinDistance.cpp\"\n/*\n * @title LevenshteinDistance\
    \ - \u7DE8\u96C6\u8DDD\u96E2\n * @docs md/string/LevenshteinDistance.md\n */\n\
    int LevenshteinDistance(string S, string T,char dummy='#') {\n    int N = S.size();\n\
    \    int M = T.size();\n    S.push_back(dummy);T.push_back(dummy);\n    vector<vector<int>>\
    \ dp(N+2, vector<int>(M+2,N+M));\n    dp[0][0]=0;\n    for(int i=0;i<=N;++i) {\n\
    \        for(int j=0;j<=M;++j) {\n            //change\n            dp[i+1][j+1]\
    \ = min(dp[i+1][j+1],dp[i][j]+(S[i]!=T[j]));            \n            //delete\n\
    \            dp[i+1][j]   = min(dp[i+1][j],dp[i][j]+1);            \n        \
    \    //insert\n            dp[i][j+1]   = min(dp[i][j+1],dp[i][j]+1);        \
    \    \n        }\n    }\n    return dp[N][M];\n}\n#line 8 \"test/string/LevenshteinDistance-2.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    string S,T;\
    \ cin >> S >> T;\n    cout << LevenshteinDistance(S,T) << endl;\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <vector>\n#include <iostream>\n#include <string>\nusing namespace\
    \ std;\n#include \"../../lib/string/LevenshteinDistance.cpp\"\n\nint main() {\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    string S,T; cin >> S >> T;\n\
    \    cout << LevenshteinDistance(S,T) << endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/string/LevenshteinDistance.cpp
  isVerificationFile: true
  path: test/string/LevenshteinDistance-2.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:04:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/LevenshteinDistance-2.test.cpp
layout: document
redirect_from:
- /verify/test/string/LevenshteinDistance-2.test.cpp
- /verify/test/string/LevenshteinDistance-2.test.cpp.html
title: test/string/LevenshteinDistance-2.test.cpp
---
