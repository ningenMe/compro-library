---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1130/problem/C
  bundledCode: "#line 1 \"old/Grid_Translation.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nclass Grid_Translation {\n\tint H,W;\npublic:\n\tGrid_Translation(const\
    \ int& H,const int& W):H(H),W(W){\n\t\t// do nothing\n\t}\n\n\tint YXtoN(const\
    \ int& y,const int& x){\n\t\treturn y*W+x;\n\t}\n\n\tint NtoY(const int& N){\n\
    \t\treturn N/W;\n\t}\n\n\tint NtoX(const int& N){\n\t\treturn N%W;\n\t}\n};\n\n\
    //verify https://codeforces.com/contest/1130/problem/C\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nclass Grid_Translation\
    \ {\n\tint H,W;\npublic:\n\tGrid_Translation(const int& H,const int& W):H(H),W(W){\n\
    \t\t// do nothing\n\t}\n\n\tint YXtoN(const int& y,const int& x){\n\t\treturn\
    \ y*W+x;\n\t}\n\n\tint NtoY(const int& N){\n\t\treturn N/W;\n\t}\n\n\tint NtoX(const\
    \ int& N){\n\t\treturn N%W;\n\t}\n};\n\n//verify https://codeforces.com/contest/1130/problem/C"
  dependsOn: []
  isVerificationFile: false
  path: old/Grid_Translation.cpp
  requiredBy: []
  timestamp: '2020-01-09 00:30:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Grid_Translation.cpp
layout: document
redirect_from:
- /library/old/Grid_Translation.cpp
- /library/old/Grid_Translation.cpp.html
title: old/Grid_Translation.cpp
---
