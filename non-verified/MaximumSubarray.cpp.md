---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"non-verified/MaximumSubarray.cpp\"\ntemplate<class T> vector<T>\
    \ MaximumSubarray(const vector<T>& vec, T unit=0) {\n\tassert(!vec.empty());\n\
    \tvector<T> dp(vec.size());\n\tdp[0] = max(vec[0],unit);\n\tfor(int i = 1; i <\
    \ vec.size(); ++i) dp[i] = max(dp[i-1]+vec[i],unit);\n\treturn dp;\n}\n"
  code: "template<class T> vector<T> MaximumSubarray(const vector<T>& vec, T unit=0)\
    \ {\n\tassert(!vec.empty());\n\tvector<T> dp(vec.size());\n\tdp[0] = max(vec[0],unit);\n\
    \tfor(int i = 1; i < vec.size(); ++i) dp[i] = max(dp[i-1]+vec[i],unit);\n\treturn\
    \ dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/MaximumSubarray.cpp
  requiredBy: []
  timestamp: '2020-08-14 03:16:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/MaximumSubarray.cpp
layout: document
redirect_from:
- /library/non-verified/MaximumSubarray.cpp
- /library/non-verified/MaximumSubarray.cpp.html
title: non-verified/MaximumSubarray.cpp
---
