---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union-find-tree/UndoUnionFindTree.test.cpp
    title: test/union-find-tree/UndoUnionFindTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/union-find-tree/UndoUnionFindTree.md
    document_title: "UndoUnionFindTree - Undo\u3064\u304D Union Find Tree"
    links: []
  bundledCode: "#line 1 \"lib/41-union-find-tree/UndoUnionFindTree.cpp\"\n/*\n * @title\
    \ UndoUnionFindTree - Undo\u3064\u304D Union Find Tree\n * @docs md/union-find-tree/UndoUnionFindTree.md\n\
    \ */\nclass UndoUnionFindTree {\n    vector<int> parent;\n    stack<array<int,2>>\
    \ history;\n    inline int root(int n) {\n        return (parent[n]<0?n:root(parent[n]));\n\
    \    }\npublic:\n    UndoUnionFindTree(const int N = 1) : parent(N,-1){\n    }\n\
    \    inline bool connected(const int n, const int m) {\n        return root(n)\
    \ == root(m);\n    }\n    inline void merge(int n,int m) {\n        n = root(n);\n\
    \        m = root(m);\n        history.push({n,parent[n]});\n        history.push({m,parent[m]});\n\
    \        if (n == m) return;\n        if(parent[n]>parent[m]) swap(n, m);\n  \
    \      parent[n] += parent[m];\n        parent[m] = n;\n    }\n    inline int\
    \ size(const int n){\n        return (-parent[root(n)]);\n    }\n    inline int\
    \ operator[](const int n) {\n        return root(n);\n    }\n    inline void print()\
    \ {\n        for(int i = 0; i < parent.size(); ++i) cout << root(i) << \" \";\n\
    \        cout << endl;\n    }\n    inline void undo() {\n        for(int i=0;i<2;++i)\
    \ {\n            auto ar=history.top(); history.pop();\n            parent[ar[0]]=ar[1];\n\
    \        }\n    }\n};\n"
  code: "/*\n * @title UndoUnionFindTree - Undo\u3064\u304D Union Find Tree\n * @docs\
    \ md/union-find-tree/UndoUnionFindTree.md\n */\nclass UndoUnionFindTree {\n  \
    \  vector<int> parent;\n    stack<array<int,2>> history;\n    inline int root(int\
    \ n) {\n        return (parent[n]<0?n:root(parent[n]));\n    }\npublic:\n    UndoUnionFindTree(const\
    \ int N = 1) : parent(N,-1){\n    }\n    inline bool connected(const int n, const\
    \ int m) {\n        return root(n) == root(m);\n    }\n    inline void merge(int\
    \ n,int m) {\n        n = root(n);\n        m = root(m);\n        history.push({n,parent[n]});\n\
    \        history.push({m,parent[m]});\n        if (n == m) return;\n        if(parent[n]>parent[m])\
    \ swap(n, m);\n        parent[n] += parent[m];\n        parent[m] = n;\n    }\n\
    \    inline int size(const int n){\n        return (-parent[root(n)]);\n    }\n\
    \    inline int operator[](const int n) {\n        return root(n);\n    }\n  \
    \  inline void print() {\n        for(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n        cout << endl;\n    }\n    inline void undo() {\n\
    \        for(int i=0;i<2;++i) {\n            auto ar=history.top(); history.pop();\n\
    \            parent[ar[0]]=ar[1];\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/41-union-find-tree/UndoUnionFindTree.cpp
  requiredBy: []
  timestamp: '2023-06-19 01:52:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union-find-tree/UndoUnionFindTree.test.cpp
documentation_of: lib/41-union-find-tree/UndoUnionFindTree.cpp
layout: document
redirect_from:
- /library/lib/41-union-find-tree/UndoUnionFindTree.cpp
- /library/lib/41-union-find-tree/UndoUnionFindTree.cpp.html
title: "UndoUnionFindTree - Undo\u3064\u304D Union Find Tree"
---
### UndoUnionFindTree
- Undo付きunion find
- 経路圧縮をせず、mergeの履歴を持つことで、undoができるunion find

### コンストラクタ
- UndoUnionFindTree(int N = 1, T ini = 0)
  - Nは頂点数 
  
### メソッド
- inline bool connected(int n, int m)
  - 連結判定
  - $O(\log N)$
- bool merge(int n, int m)
  - $O(\log N)$
- inline int operator[](int n)
  - 頂点nの根を返す
- inline void print()
  - デバッグ用