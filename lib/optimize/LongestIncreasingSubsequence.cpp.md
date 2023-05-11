---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/optimize/LongestIncreasingSubsequence.md
    document_title: LongestIncreasingSubsequence - LIS
    links: []
  bundledCode: "#line 1 \"lib/optimize/LongestIncreasingSubsequence.cpp\"\n/*\n *\
    \ @title LongestIncreasingSubsequence - LIS\n * @docs md/optimize/LongestIncreasingSubsequence.md\n\
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
  path: lib/optimize/LongestIncreasingSubsequence.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/optimize/LongestIncreasingSubsequence.cpp
layout: document
redirect_from:
- /library/lib/optimize/LongestIncreasingSubsequence.cpp
- /library/lib/optimize/LongestIncreasingSubsequence.cpp.html
title: LongestIncreasingSubsequence - LIS
---
