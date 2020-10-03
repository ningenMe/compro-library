---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc006/tasks/abc006_4
  bundledCode: "#line 1 \"non-verified/LongestIncreasingSubsequence.cpp\"\n//Longest\
    \ Increasing Subsequence O(NlogN)\ntemplate<class T> int LongestIncreasingSubsequence(const\
    \ vector<T> & ar, T inf) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0;\
    \ i < ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n\n//verify\
    \ https://atcoder.jp/contests/abc006/tasks/abc006_4\n"
  code: "//Longest Increasing Subsequence O(NlogN)\ntemplate<class T> int LongestIncreasingSubsequence(const\
    \ vector<T> & ar, T inf) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0;\
    \ i < ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n\n//verify\
    \ https://atcoder.jp/contests/abc006/tasks/abc006_4"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/LongestIncreasingSubsequence.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/LongestIncreasingSubsequence.cpp
layout: document
redirect_from:
- /library/non-verified/LongestIncreasingSubsequence.cpp
- /library/non-verified/LongestIncreasingSubsequence.cpp.html
title: non-verified/LongestIncreasingSubsequence.cpp
---
