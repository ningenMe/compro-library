---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents-1.test.cpp
    title: test/graph/StronglyConnectedComponents-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/UnionFindTree.test.cpp
    title: test/graph/UnionFindTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/util/RangeIndex.test.cpp
    title: test/util/RangeIndex.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/UnionFindTree.md
    document_title: "UnionFindTree - Union Find \u6728"
    links: []
  bundledCode: "#line 1 \"lib/graph/UnionFindTree.cpp\"\n/*\n * @title UnionFindTree\
    \ - Union Find \u6728\n * @docs md/graph/UnionFindTree.md\n */\nclass UnionFindTree\
    \ {\n\tvector<int> parent,maxi,mini;\n\tinline int root(int n) {\n\t\treturn (parent[n]<0?n:parent[n]\
    \ = root(parent[n]));\n\t}\npublic:\n\tUnionFindTree(int N = 1) : parent(N,-1),maxi(N),mini(N){\n\
    \t\tiota(maxi.begin(),maxi.end(),0);\n\t\tiota(mini.begin(),mini.end(),0);\n\t\
    }\n\tinline bool connected(int n, int m) {\n\t\treturn root(n) == root(m);\n\t\
    }\n\tinline void merge(int n, int m) {\n\t\tn = root(n);\n\t\tm = root(m);\n\t\
    \tif (n == m) return;\n\t\tif(parent[n]>parent[m]) swap(n, m);\n\t\tparent[n]\
    \ += parent[m];\n\t\tparent[m] = n;\n\t\tmaxi[n] = std::max(maxi[n],maxi[m]);\n\
    \t\tmini[n] = std::min(mini[n],mini[m]);\n\t}\n\tinline int min(int n) {\n\t\t\
    return mini[root(n)];\n\t}\n\tinline int max(int n) {\n\t\treturn maxi[root(n)];\n\
    \t}\n\tinline int size(int n){\n\t\treturn (-parent[root(n)]);\n\t}\n\tinline\
    \ int operator[](int n) {\n\t\treturn root(n);\n\t}\n\tinline void print() {\n\
    \t\tfor(int i = 0; i < parent.size(); ++i) cout << root(i) << \" \";\n\t\tcout\
    \ << endl;\n\t}\n};\n"
  code: "/*\n * @title UnionFindTree - Union Find \u6728\n * @docs md/graph/UnionFindTree.md\n\
    \ */\nclass UnionFindTree {\n\tvector<int> parent,maxi,mini;\n\tinline int root(int\
    \ n) {\n\t\treturn (parent[n]<0?n:parent[n] = root(parent[n]));\n\t}\npublic:\n\
    \tUnionFindTree(int N = 1) : parent(N,-1),maxi(N),mini(N){\n\t\tiota(maxi.begin(),maxi.end(),0);\n\
    \t\tiota(mini.begin(),mini.end(),0);\n\t}\n\tinline bool connected(int n, int\
    \ m) {\n\t\treturn root(n) == root(m);\n\t}\n\tinline void merge(int n, int m)\
    \ {\n\t\tn = root(n);\n\t\tm = root(m);\n\t\tif (n == m) return;\n\t\tif(parent[n]>parent[m])\
    \ swap(n, m);\n\t\tparent[n] += parent[m];\n\t\tparent[m] = n;\n\t\tmaxi[n] =\
    \ std::max(maxi[n],maxi[m]);\n\t\tmini[n] = std::min(mini[n],mini[m]);\n\t}\n\t\
    inline int min(int n) {\n\t\treturn mini[root(n)];\n\t}\n\tinline int max(int\
    \ n) {\n\t\treturn maxi[root(n)];\n\t}\n\tinline int size(int n){\n\t\treturn\
    \ (-parent[root(n)]);\n\t}\n\tinline int operator[](int n) {\n\t\treturn root(n);\n\
    \t}\n\tinline void print() {\n\t\tfor(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n\t\tcout << endl;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/UnionFindTree.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:13:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/StronglyConnectedComponents-1.test.cpp
  - test/graph/UnionFindTree.test.cpp
  - test/util/RangeIndex.test.cpp
documentation_of: lib/graph/UnionFindTree.cpp
layout: document
redirect_from:
- /library/lib/graph/UnionFindTree.cpp
- /library/lib/graph/UnionFindTree.cpp.html
title: "UnionFindTree - Union Find \u6728"
---
