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
    - https://atcoder.jp/contests/abc087/tasks/arc090_b
  bundledCode: "#line 1 \"non-verified/Union_Find_Tree_With_Potential.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n//Union Find Tree With Potential\n\
    template<class T> class Union_Find_Tree_With_Potential {\npublic:\n\tvector<int>\
    \ parent;\n\tvector<int> rank;\n\tvector<T> dist;\n\n\tUnion_Find_Tree_With_Potential(int\
    \ N = 1, T ini = 0) :parent(N), rank(N,0), dist(N, ini) {\n\t\tfor (int i = 0;\
    \ i < N; ++i) parent[i] = i;\n\t}\n\n\tint root(int x) {\n\t\tif (parent[x] ==\
    \ x) return x;\n\t\telse {\n\t\t\tint r = root(parent[x]);\n\t\t\tdist[x] += dist[parent[x]];\n\
    \t\t\treturn parent[x] = r;\n\t\t}\n\t}\n\n\tT updated_dist(int x) {\n\t\troot(x);\n\
    \t\treturn dist[x];\n\t}\n\n\tbool same(int x, int y) {\n\t\treturn root(x) ==\
    \ root(y);\n\t}\n\n\tbool merge(int x, int y, T d = 0) {\n\t\td += updated_dist(x);\n\
    \t\td -= updated_dist(y);\n\t\tx = root(x); y = root(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (rank[x] < rank[y]) {\n\t\t\tswap(x, y);\n\t\t\td = -d;\n\t\t\
    }\n\t\tif (rank[x] == rank[y]) ++rank[x];\n\t\tparent[y] = x;\n\t\tdist[y] = d;\n\
    \t\treturn true;\n\t}\n\n\tT diff(int x, int y) {\n\t\treturn updated_dist(y)\
    \ - updated_dist(x);\n\t}\n};\n\n//verify https://atcoder.jp/contests/abc087/tasks/arc090_b\
    \ \n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//Union Find Tree With\
    \ Potential\ntemplate<class T> class Union_Find_Tree_With_Potential {\npublic:\n\
    \tvector<int> parent;\n\tvector<int> rank;\n\tvector<T> dist;\n\n\tUnion_Find_Tree_With_Potential(int\
    \ N = 1, T ini = 0) :parent(N), rank(N,0), dist(N, ini) {\n\t\tfor (int i = 0;\
    \ i < N; ++i) parent[i] = i;\n\t}\n\n\tint root(int x) {\n\t\tif (parent[x] ==\
    \ x) return x;\n\t\telse {\n\t\t\tint r = root(parent[x]);\n\t\t\tdist[x] += dist[parent[x]];\n\
    \t\t\treturn parent[x] = r;\n\t\t}\n\t}\n\n\tT updated_dist(int x) {\n\t\troot(x);\n\
    \t\treturn dist[x];\n\t}\n\n\tbool same(int x, int y) {\n\t\treturn root(x) ==\
    \ root(y);\n\t}\n\n\tbool merge(int x, int y, T d = 0) {\n\t\td += updated_dist(x);\n\
    \t\td -= updated_dist(y);\n\t\tx = root(x); y = root(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (rank[x] < rank[y]) {\n\t\t\tswap(x, y);\n\t\t\td = -d;\n\t\t\
    }\n\t\tif (rank[x] == rank[y]) ++rank[x];\n\t\tparent[y] = x;\n\t\tdist[y] = d;\n\
    \t\treturn true;\n\t}\n\n\tT diff(int x, int y) {\n\t\treturn updated_dist(y)\
    \ - updated_dist(x);\n\t}\n};\n\n//verify https://atcoder.jp/contests/abc087/tasks/arc090_b "
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Union_Find_Tree_With_Potential.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Union_Find_Tree_With_Potential.cpp
layout: document
redirect_from:
- /library/non-verified/Union_Find_Tree_With_Potential.cpp
- /library/non-verified/Union_Find_Tree_With_Potential.cpp.html
title: non-verified/Union_Find_Tree_With_Potential.cpp
---
