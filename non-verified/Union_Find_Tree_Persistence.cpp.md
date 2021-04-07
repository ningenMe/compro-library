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
    - https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
  bundledCode: "#line 1 \"non-verified/Union_Find_Tree_Persistence.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nclass  Union_Find_Tree_Persistence{\n\
    public:\n    vector<map<int,int>> parent;\n    vector<int> rank,last;\n    int\
    \ cnt = 0;\n\n    Union_Find_Tree_Persistence(int N):parent(N),rank(N,1),last(N,0){\n\
    \        for(int i = 0; i < N; ++i) parent[i][0] = i;\n    }\n\n    //O(logN)\n\
    \    int root(int n, int t) {\n        return ( (t >= last[n] && parent[n][last[n]]\
    \ != n) ? root(parent[n][last[n]], t) : n);\n    }\n \n    //O(logN)\n    void\
    \ unite(int n, int m) {\n        n = root(n, cnt);\n        m = root(m, cnt);\n\
    \        cnt++;\n        if(n == m) return;\n        \n        if(rank[n] < rank[m])\
    \ {\n            parent[n][cnt] = m;\n            last[n] = cnt;\n        }\n\
    \        else {\n        parent[m][cnt] = n;\n        last[m] = cnt;\n       \
    \ if(rank[n] == rank[m]) rank[n]++;\n        }\n    }\n \n    bool same(int n,\
    \ int m, int t) { \n        return root(n, t) == root(m, t);\n    }\n};\n\n//verify\
    \ https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nclass  Union_Find_Tree_Persistence{\n\
    public:\n    vector<map<int,int>> parent;\n    vector<int> rank,last;\n    int\
    \ cnt = 0;\n\n    Union_Find_Tree_Persistence(int N):parent(N),rank(N,1),last(N,0){\n\
    \        for(int i = 0; i < N; ++i) parent[i][0] = i;\n    }\n\n    //O(logN)\n\
    \    int root(int n, int t) {\n        return ( (t >= last[n] && parent[n][last[n]]\
    \ != n) ? root(parent[n][last[n]], t) : n);\n    }\n \n    //O(logN)\n    void\
    \ unite(int n, int m) {\n        n = root(n, cnt);\n        m = root(m, cnt);\n\
    \        cnt++;\n        if(n == m) return;\n        \n        if(rank[n] < rank[m])\
    \ {\n            parent[n][cnt] = m;\n            last[n] = cnt;\n        }\n\
    \        else {\n        parent[m][cnt] = n;\n        last[m] = cnt;\n       \
    \ if(rank[n] == rank[m]) rank[n]++;\n        }\n    }\n \n    bool same(int n,\
    \ int m, int t) { \n        return root(n, t) == root(m, t);\n    }\n};\n\n//verify\
    \ https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Union_Find_Tree_Persistence.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Union_Find_Tree_Persistence.cpp
layout: document
redirect_from:
- /library/non-verified/Union_Find_Tree_Persistence.cpp
- /library/non-verified/Union_Find_Tree_Persistence.cpp.html
title: non-verified/Union_Find_Tree_Persistence.cpp
---
