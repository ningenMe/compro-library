---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents-1.test.cpp
    title: test/graph/StronglyConnectedComponents-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-rerooting.test.cpp
    title: test/graph/Tree-rerooting.test.cpp
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
    \ {\n    vector<int> parent,maxi,mini;\n    inline int root(int n) {\n       \
    \ return (parent[n]<0?n:parent[n] = root(parent[n]));\n    }\npublic:\n    UnionFindTree(const\
    \ int N = 1) : parent(N,-1),maxi(N),mini(N){\n        iota(maxi.begin(),maxi.end(),0);\n\
    \        iota(mini.begin(),mini.end(),0);\n    }\n    inline bool connected(const\
    \ int n, const int m) {\n        return root(n) == root(m);\n    }\n    inline\
    \ void merge(int n,int m) {\n        n = root(n);\n        m = root(m);\n    \
    \    if (n == m) return;\n        if(parent[n]>parent[m]) swap(n, m);\n      \
    \  parent[n] += parent[m];\n        parent[m] = n;\n        maxi[n] = std::max(maxi[n],maxi[m]);\n\
    \        mini[n] = std::min(mini[n],mini[m]);\n    }\n    inline int min(const\
    \ int n) {\n        return mini[root(n)];\n    }\n    inline int max(const int\
    \ n) {\n        return maxi[root(n)];\n    }\n    inline int size(const int n){\n\
    \        return (-parent[root(n)]);\n    }\n    inline int operator[](const int\
    \ n) {\n        return root(n);\n    }\n    inline void print() {\n        for(int\
    \ i = 0; i < parent.size(); ++i) cout << root(i) << \" \";\n        cout << endl;\n\
    \    }\n};\n"
  code: "/*\n * @title UnionFindTree - Union Find \u6728\n * @docs md/graph/UnionFindTree.md\n\
    \ */\nclass UnionFindTree {\n    vector<int> parent,maxi,mini;\n    inline int\
    \ root(int n) {\n        return (parent[n]<0?n:parent[n] = root(parent[n]));\n\
    \    }\npublic:\n    UnionFindTree(const int N = 1) : parent(N,-1),maxi(N),mini(N){\n\
    \        iota(maxi.begin(),maxi.end(),0);\n        iota(mini.begin(),mini.end(),0);\n\
    \    }\n    inline bool connected(const int n, const int m) {\n        return\
    \ root(n) == root(m);\n    }\n    inline void merge(int n,int m) {\n        n\
    \ = root(n);\n        m = root(m);\n        if (n == m) return;\n        if(parent[n]>parent[m])\
    \ swap(n, m);\n        parent[n] += parent[m];\n        parent[m] = n;\n     \
    \   maxi[n] = std::max(maxi[n],maxi[m]);\n        mini[n] = std::min(mini[n],mini[m]);\n\
    \    }\n    inline int min(const int n) {\n        return mini[root(n)];\n   \
    \ }\n    inline int max(const int n) {\n        return maxi[root(n)];\n    }\n\
    \    inline int size(const int n){\n        return (-parent[root(n)]);\n    }\n\
    \    inline int operator[](const int n) {\n        return root(n);\n    }\n  \
    \  inline void print() {\n        for(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n        cout << endl;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/UnionFindTree.cpp
  requiredBy: []
  timestamp: '2023-05-15 02:35:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/StronglyConnectedComponents-1.test.cpp
  - test/graph/Tree-rerooting.test.cpp
  - test/graph/UnionFindTree.test.cpp
  - test/util/RangeIndex.test.cpp
documentation_of: lib/graph/UnionFindTree.cpp
layout: document
redirect_from:
- /library/lib/graph/UnionFindTree.cpp
- /library/lib/graph/UnionFindTree.cpp.html
title: "UnionFindTree - Union Find \u6728"
---
