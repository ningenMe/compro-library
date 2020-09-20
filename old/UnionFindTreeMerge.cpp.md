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
    - https://atcoder.jp/contests/abc097/tasks/arc097_b
  bundledCode: "#line 1 \"old/UnionFindTreeMerge.cpp\"\n\n\n//Union Find Tree\ntemplate<class\
    \ T> class UnionFindTreeMerge {\npublic:\n\tvector<int> parent;\n    vector<int>\
    \ rank;\n    vector<T> value;\n\n    UnionFindTreeMerge(int N) : parent(N), rank(N,0),\
    \ value(N){\n\t\tfor (int i = 0; i < N; ++i) parent[i] = i;\n\t}\n\n\tvoid setValue(int\
    \ n, T v) {\n\t\tvalue[n] = v;\n\t}\n\n\tT rootValue(int n) {\n\t\treturn value[root(n)];\n\
    \t}\n\n\tint root(int n) {\n\t\treturn (parent[n] == n ? n : parent[n] = root(parent[n]));\n\
    \t}\n\n    int same(int n, int m) {\n\t\treturn root(n) == root(m);\n\t}\n \n\t\
    void unite(int n, int m) {\n\t\tn = root(n);\n\t\tm = root(m);\n\t\tif (n == m)\
    \ return;\n\t\tif(rank[n]<rank[m]) {\n            parent[n] = m;\n\t\t\tvalue[m]\
    \ += value[n];\n        }\n        else{\n            parent[m] = n;\n\t\t\tvalue[n]\
    \ += value[m];\n            if(rank[n] == rank[m]) rank[n]++;\n        }\n\t}\n\
    };\n\n//verify https://atcoder.jp/contests/abc097/tasks/arc097_b\n"
  code: "\n\n//Union Find Tree\ntemplate<class T> class UnionFindTreeMerge {\npublic:\n\
    \tvector<int> parent;\n    vector<int> rank;\n    vector<T> value;\n\n    UnionFindTreeMerge(int\
    \ N) : parent(N), rank(N,0), value(N){\n\t\tfor (int i = 0; i < N; ++i) parent[i]\
    \ = i;\n\t}\n\n\tvoid setValue(int n, T v) {\n\t\tvalue[n] = v;\n\t}\n\n\tT rootValue(int\
    \ n) {\n\t\treturn value[root(n)];\n\t}\n\n\tint root(int n) {\n\t\treturn (parent[n]\
    \ == n ? n : parent[n] = root(parent[n]));\n\t}\n\n    int same(int n, int m)\
    \ {\n\t\treturn root(n) == root(m);\n\t}\n \n\tvoid unite(int n, int m) {\n\t\t\
    n = root(n);\n\t\tm = root(m);\n\t\tif (n == m) return;\n\t\tif(rank[n]<rank[m])\
    \ {\n            parent[n] = m;\n\t\t\tvalue[m] += value[n];\n        }\n    \
    \    else{\n            parent[m] = n;\n\t\t\tvalue[n] += value[m];\n        \
    \    if(rank[n] == rank[m]) rank[n]++;\n        }\n\t}\n};\n\n//verify https://atcoder.jp/contests/abc097/tasks/arc097_b\n"
  dependsOn: []
  isVerificationFile: false
  path: old/UnionFindTreeMerge.cpp
  requiredBy: []
  timestamp: '2020-08-15 06:33:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/UnionFindTreeMerge.cpp
layout: document
redirect_from:
- /library/old/UnionFindTreeMerge.cpp
- /library/old/UnionFindTreeMerge.cpp.html
title: old/UnionFindTreeMerge.cpp
---
