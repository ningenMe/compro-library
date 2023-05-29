---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/optimize/LongestIncreasingSubsequence.test.cpp
    title: test/optimize/LongestIncreasingSubsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/optimize/LongestIncreasingSubsequence.md
    document_title: LongestIncreasingSubsequence - LIS
    links: []
  bundledCode: "#line 1 \"lib/60-optimize/LongestIncreasingSubsequence.cpp\"\n/*\n\
    \ * @title LongestIncreasingSubsequence - LIS\n * @docs md/optimize/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> inline static int LongestIncreasingSubsequence(const vector<T>\
    \ & ar, T inf=3e18) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0; i <\
    \ ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n"
  code: "/*\n * @title LongestIncreasingSubsequence - LIS\n * @docs md/optimize/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> inline static int LongestIncreasingSubsequence(const vector<T>\
    \ & ar, T inf=3e18) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0; i <\
    \ ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/60-optimize/LongestIncreasingSubsequence.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/optimize/LongestIncreasingSubsequence.test.cpp
documentation_of: lib/60-optimize/LongestIncreasingSubsequence.cpp
layout: document
redirect_from:
- /library/lib/60-optimize/LongestIncreasingSubsequence.cpp
- /library/lib/60-optimize/LongestIncreasingSubsequence.cpp.html
title: LongestIncreasingSubsequence - LIS
---
