---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/LongestIncreasingSubsequence.test.cpp
    title: test/util/LongestIncreasingSubsequence.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/util/LongestIncreasingSubsequence.md
    document_title: LongestIncreasingSubsequence
    links: []
  bundledCode: "#line 1 \"lib/util/LongestIncreasingSubsequence.cpp\"\n/*\n * @title\
    \ LongestIncreasingSubsequence\n * @docs md/util/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> inline static int LongestIncreasingSubsequence(const vector<T>\
    \ & ar, T inf=3e18) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0; i <\
    \ ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n"
  code: "/*\n * @title LongestIncreasingSubsequence\n * @docs md/util/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> inline static int LongestIncreasingSubsequence(const vector<T>\
    \ & ar, T inf=3e18) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0; i <\
    \ ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/LongestIncreasingSubsequence.cpp
  requiredBy: []
  timestamp: '2020-10-25 05:50:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/LongestIncreasingSubsequence.test.cpp
documentation_of: lib/util/LongestIncreasingSubsequence.cpp
layout: document
redirect_from:
- /library/lib/util/LongestIncreasingSubsequence.cpp
- /library/lib/util/LongestIncreasingSubsequence.cpp.html
title: LongestIncreasingSubsequence
---
