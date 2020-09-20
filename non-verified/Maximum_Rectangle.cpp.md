---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"non-verified/Maximum_Rectangle.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nlong long Maximum_Rectangle(vector<long long>& ar){\n\t\
    ar.push_back(0);\n\tstack<pair<long long,long long>> st;\n\tlong long res = 0;\n\
    \tfor(long long r = 0; r < ar.size(); ++r){\n\t\tlong long vr = ar[r];\n\t\tif(st.empty()){\n\
    \t\t\tst.push({vr,r});\n\t\t\tcontinue;\n\t\t}\n\n\t\tlong long vl = st.top().first,\
    \ l = st.top().second;\n\t\tif(vl < vr) st.push({vr,r});\n\t\tif(vl < vr || vl\
    \ == vr)\tcontinue;\n\t\t\n\t\twhile(vl > vr) {\n\t\t\tres = max(res,vl*(r - l));\n\
    \t\t\tst.pop();\n\n\t\t\tif(st.size() && st.top().first > vr) vl = st.top().first,\
    \ l = st.top().second;\n\t\t\telse break;\n\t\t}\n\t\tst.push({vr,l});\n\t}\n\t\
    ar.pop_back();\n\treturn res;\n}\n\n\n//verify\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long Maximum_Rectangle(vector<long\
    \ long>& ar){\n\tar.push_back(0);\n\tstack<pair<long long,long long>> st;\n\t\
    long long res = 0;\n\tfor(long long r = 0; r < ar.size(); ++r){\n\t\tlong long\
    \ vr = ar[r];\n\t\tif(st.empty()){\n\t\t\tst.push({vr,r});\n\t\t\tcontinue;\n\t\
    \t}\n\n\t\tlong long vl = st.top().first, l = st.top().second;\n\t\tif(vl < vr)\
    \ st.push({vr,r});\n\t\tif(vl < vr || vl == vr)\tcontinue;\n\t\t\n\t\twhile(vl\
    \ > vr) {\n\t\t\tres = max(res,vl*(r - l));\n\t\t\tst.pop();\n\n\t\t\tif(st.size()\
    \ && st.top().first > vr) vl = st.top().first, l = st.top().second;\n\t\t\telse\
    \ break;\n\t\t}\n\t\tst.push({vr,l});\n\t}\n\tar.pop_back();\n\treturn res;\n\
    }\n\n\n//verify"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Maximum_Rectangle.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Maximum_Rectangle.cpp
layout: document
redirect_from:
- /library/non-verified/Maximum_Rectangle.cpp
- /library/non-verified/Maximum_Rectangle.cpp.html
title: non-verified/Maximum_Rectangle.cpp
---
