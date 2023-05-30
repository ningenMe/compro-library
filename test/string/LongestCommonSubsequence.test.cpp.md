---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/50-string/LongestCommonSubsequence.cpp
    title: LongestCommonSubsequence - LCS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/string/LongestCommonSubsequence.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <vector>\n#include <iostream>\n#include <string>\n#include <algorithm>\n\
    using namespace std;\n#line 1 \"lib/50-string/LongestCommonSubsequence.cpp\"\n\
    /*\n * @title LongestCommonSubsequence - LCS\n * @docs md/string/LongestCommonSubsequence.md\n\
    \ */\nstring LongestCommonSubsequence(const string& S, const string& T){\n\tint\
    \ N = S.size(), M = T.size();\n\tvector<int> dp((N+1)*(M+1),0);\n    for(size_t\
    \ i = 0; i < N; i++) {\n        for(size_t j = 0; j < M; j++) {\n            dp[(i+1)*(M+1)+j+1]\
    \ = (S[i] == T[j] ? dp[i*(M+1)+j] + 1 : max(dp[i*(M+1)+j + 1],dp[(i+1)*(M+1)+j])\
    \ );\n        }\n    }\n    int a=N,b=M;\n\tstring res = \"\";\n\twhile(dp[a*(M+1)+b]>0)\
    \ {\n\t\tif(S[a-1]==T[b-1]) res.push_back(S[a-1]),a--,b--;\n\t\telse (dp[(a-1)*(M+1)+b]>dp[a*(M+1)+b-1]?a:b)--;\n\
    \t}\n    reverse(res.begin(),res.end());\n\treturn res;\n}\n#line 9 \"test/string/LongestCommonSubsequence.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int Q; cin\
    \ >> Q;\n    while(Q--) {\n        string S,T; cin >> S >> T;\n        cout <<\
    \ LongestCommonSubsequence(S,T).size() << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <vector>\n#include <iostream>\n#include <string>\n#include <algorithm>\n\
    using namespace std;\n#include \"../../lib/50-string/LongestCommonSubsequence.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int Q; cin\
    \ >> Q;\n    while(Q--) {\n        string S,T; cin >> S >> T;\n        cout <<\
    \ LongestCommonSubsequence(S,T).size() << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/50-string/LongestCommonSubsequence.cpp
  isVerificationFile: true
  path: test/string/LongestCommonSubsequence.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/LongestCommonSubsequence.test.cpp
layout: document
redirect_from:
- /verify/test/string/LongestCommonSubsequence.test.cpp
- /verify/test/string/LongestCommonSubsequence.test.cpp.html
title: test/string/LongestCommonSubsequence.test.cpp
---
