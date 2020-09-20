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
    - https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_a
  bundledCode: "#line 1 \"non-verified/Longest_Common_Subsequence_Size.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint Longest_Common_Subsequence_Size(const\
    \ string& S, const string& T){\n\tvector<vector<int>> res(S.size()+1,vector<int>(T.size()+1,0));\n\
    \    for(size_t i = 0; i < S.size(); i++)\n    for(size_t j = 0; j < T.size();\
    \ j++)\n    res[i+1][j+1] = (S[i] == T[j] ? res[i][j] + 1 : max(res[i][j + 1],res[i\
    \ + 1][j]) );\n    return res[S.size()][T.size()];\n}\n\n//verify https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_a\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nint Longest_Common_Subsequence_Size(const\
    \ string& S, const string& T){\n\tvector<vector<int>> res(S.size()+1,vector<int>(T.size()+1,0));\n\
    \    for(size_t i = 0; i < S.size(); i++)\n    for(size_t j = 0; j < T.size();\
    \ j++)\n    res[i+1][j+1] = (S[i] == T[j] ? res[i][j] + 1 : max(res[i][j + 1],res[i\
    \ + 1][j]) );\n    return res[S.size()][T.size()];\n}\n\n//verify https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_a"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Longest_Common_Subsequence_Size.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Longest_Common_Subsequence_Size.cpp
layout: document
redirect_from:
- /library/non-verified/Longest_Common_Subsequence_Size.cpp
- /library/non-verified/Longest_Common_Subsequence_Size.cpp.html
title: non-verified/Longest_Common_Subsequence_Size.cpp
---
