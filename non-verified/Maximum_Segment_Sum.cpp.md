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
  bundledCode: "#line 1 \"non-verified/Maximum_Segment_Sum.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//Maximum Segment Sum O(N)\ntemplate<class T> T Maximum_Segment_Sum(const\
    \ vector<T> & ar, T inf) {\n    T res = -inf, sum = 0;\n    for (int i = 0; i\
    \ < ar.size(); ++i) {\n        sum = max(sum + ar[i], ar[i]);\n        res = max(res,\
    \ sum);\n    }\n    return res;\n}\n\n//verify \n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//Maximum Segment Sum O(N)\n\
    template<class T> T Maximum_Segment_Sum(const vector<T> & ar, T inf) {\n    T\
    \ res = -inf, sum = 0;\n    for (int i = 0; i < ar.size(); ++i) {\n        sum\
    \ = max(sum + ar[i], ar[i]);\n        res = max(res, sum);\n    }\n    return\
    \ res;\n}\n\n//verify "
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Maximum_Segment_Sum.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Maximum_Segment_Sum.cpp
layout: document
redirect_from:
- /library/non-verified/Maximum_Segment_Sum.cpp
- /library/non-verified/Maximum_Segment_Sum.cpp.html
title: non-verified/Maximum_Segment_Sum.cpp
---
