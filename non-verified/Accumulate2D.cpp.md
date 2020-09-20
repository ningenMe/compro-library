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
  bundledCode: "#line 1 \"non-verified/Accumulate2D.cpp\"\ntemplate<class T> class\
    \ Accumulate2D {\n\tvector<vector<T>> acc;\npublic:\n\t//arg grid is 0-indexed\
    \ \n\tAccumulate2D(const vector<vector<T>>& grid)\n\t: acc(grid.size()+1,vector<T>(grid.front().size()+1)){\n\
    \t\tfor(int i = 1; i < acc.size(); ++i) {\n\t\t\tfor(int j = 1; j < acc[i].size();\
    \ ++j) {\n\t\t\t\tacc[i][j]+=grid[i-1][j-1]+acc[i][j-1]+acc[i-1][j]-acc[i-1][j-1];\n\
    \t\t\t}\n\t\t}\n\t}\n\t// \u5DE6\u4E0A[y1,x1] \u53F3\u4E0B[y2,x2] 0-indexed\n\t\
    inline T get(int y1,int x1,int y2,int x2) {\n\t\ty2++,x2++;\n\t\treturn acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];\n\
    \t}\n};\n"
  code: "template<class T> class Accumulate2D {\n\tvector<vector<T>> acc;\npublic:\n\
    \t//arg grid is 0-indexed \n\tAccumulate2D(const vector<vector<T>>& grid)\n\t\
    : acc(grid.size()+1,vector<T>(grid.front().size()+1)){\n\t\tfor(int i = 1; i <\
    \ acc.size(); ++i) {\n\t\t\tfor(int j = 1; j < acc[i].size(); ++j) {\n\t\t\t\t\
    acc[i][j]+=grid[i-1][j-1]+acc[i][j-1]+acc[i-1][j]-acc[i-1][j-1];\n\t\t\t}\n\t\t\
    }\n\t}\n\t// \u5DE6\u4E0A[y1,x1] \u53F3\u4E0B[y2,x2] 0-indexed\n\tinline T get(int\
    \ y1,int x1,int y2,int x2) {\n\t\ty2++,x2++;\n\t\treturn acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];\n\
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Accumulate2D.cpp
  requiredBy: []
  timestamp: '2020-08-14 03:16:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Accumulate2D.cpp
layout: document
redirect_from:
- /library/non-verified/Accumulate2D.cpp
- /library/non-verified/Accumulate2D.cpp.html
title: non-verified/Accumulate2D.cpp
---
