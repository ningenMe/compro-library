---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union-find-tree/PotentializedUnionFindTree.test.cpp
    title: test/union-find-tree/PotentializedUnionFindTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/union-find-tree/PotentializedUnionFindTree.md
    document_title: "PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
      \u4ED8\u304DUnionFind\u6728"
    links: []
  bundledCode: "#line 1 \"lib/41-union-find-tree/PotentializedUnionFindTree.cpp\"\n\
    /*\n * @title PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \u4ED8\u304DUnionFind\u6728\n * @docs md/union-find-tree/PotentializedUnionFindTree.md\n\
    \ */\ntemplate<class T> class PotentializedUnionFindTree {\n    vector<int> parent,rank;\n\
    \    vector<T> potential;\n    inline int root(int n) {\n        if (parent[n]\
    \ == n) {\n            return n;\n        }\n        else {\n            int r\
    \ = root(parent[n]);\n            potential[n] += potential[parent[n]];\n    \
    \        return parent[n] = r;\n        }\n    }\n    inline T updated_dist(int\
    \ x) {\n        root(x);\n        return potential[x];\n    }\npublic:\n    PotentializedUnionFindTree(int\
    \ N = 1, T ini = 0) : parent(N),rank(N,1),potential(N,ini) {\n        iota(parent.begin(),parent.end(),0);\n\
    \    }\n    inline bool connected(int n, int m) {\n        return root(n) == root(m);\n\
    \    }\n    /*\n    * potential[m] = potential[n] + d\u3068\u306A\u308B\u3088\u3046\
    \u306B\u30DE\u30FC\u30B8\u3059\u308B\n    */\n    bool merge(int n, int m, T d=0)\
    \ {\n        d += updated_dist(n);\n        d -= updated_dist(m);\n        n =\
    \ root(n); m = root(m);\n        if (n == m) return false;\n        if (rank[n]\
    \ < rank[m]) {\n            swap(n, m);\n            d = -d;\n        }\n    \
    \    if (rank[n] == rank[m]) ++rank[n];\n        parent[m] = n;\n        potential[m]\
    \ = d;\n        return true;\n    }\n    /*\n    * potential[m] - potential[n]\n\
    \    */\n    T diff(int n, int m) {\n        return updated_dist(m) - updated_dist(n);\n\
    \    }\n    inline int operator[](int n) {\n        return root(n);\n    }\n \
    \   inline void print() {\n        for(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n        cout << endl;\n    }\n};\n"
  code: "/*\n * @title PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u4ED8\u304DUnionFind\u6728\n * @docs md/union-find-tree/PotentializedUnionFindTree.md\n\
    \ */\ntemplate<class T> class PotentializedUnionFindTree {\n    vector<int> parent,rank;\n\
    \    vector<T> potential;\n    inline int root(int n) {\n        if (parent[n]\
    \ == n) {\n            return n;\n        }\n        else {\n            int r\
    \ = root(parent[n]);\n            potential[n] += potential[parent[n]];\n    \
    \        return parent[n] = r;\n        }\n    }\n    inline T updated_dist(int\
    \ x) {\n        root(x);\n        return potential[x];\n    }\npublic:\n    PotentializedUnionFindTree(int\
    \ N = 1, T ini = 0) : parent(N),rank(N,1),potential(N,ini) {\n        iota(parent.begin(),parent.end(),0);\n\
    \    }\n    inline bool connected(int n, int m) {\n        return root(n) == root(m);\n\
    \    }\n    /*\n    * potential[m] = potential[n] + d\u3068\u306A\u308B\u3088\u3046\
    \u306B\u30DE\u30FC\u30B8\u3059\u308B\n    */\n    bool merge(int n, int m, T d=0)\
    \ {\n        d += updated_dist(n);\n        d -= updated_dist(m);\n        n =\
    \ root(n); m = root(m);\n        if (n == m) return false;\n        if (rank[n]\
    \ < rank[m]) {\n            swap(n, m);\n            d = -d;\n        }\n    \
    \    if (rank[n] == rank[m]) ++rank[n];\n        parent[m] = n;\n        potential[m]\
    \ = d;\n        return true;\n    }\n    /*\n    * potential[m] - potential[n]\n\
    \    */\n    T diff(int n, int m) {\n        return updated_dist(m) - updated_dist(n);\n\
    \    }\n    inline int operator[](int n) {\n        return root(n);\n    }\n \
    \   inline void print() {\n        for(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n        cout << endl;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/41-union-find-tree/PotentializedUnionFindTree.cpp
  requiredBy: []
  timestamp: '2023-06-17 04:07:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union-find-tree/PotentializedUnionFindTree.test.cpp
documentation_of: lib/41-union-find-tree/PotentializedUnionFindTree.cpp
layout: document
redirect_from:
- /library/lib/41-union-find-tree/PotentializedUnionFindTree.cpp
- /library/lib/41-union-find-tree/PotentializedUnionFindTree.cpp.html
title: "PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
  UnionFind\u6728"
---
### PotentializedUnionFindTree
- ポテンシャル付きunion find

### コンストラクタ
- PotentializedUnionFindTree(int N = 1, T ini = 0)
  - Nは頂点数 
  - Tはポテンシャルの初期値
  
### メソッド
- inline bool connected(int n, int m)
  - 連結判定
  - そこそこ高速
- bool merge(int n, int m, T d=0)
  - $ potential[m] = potential[n] + d $ となるようにマージする
  - そこそこ高速
  - 既に連結のときは未定義 falseが返る
- T diff(int n, int m)
  - potential[m] - potential[n]を計算
  - 連結ではないときは未定義
- inline int operator[](int n)
  - 頂点nの根を返す
- inline void print()
  - デバッグ用

### 参考資料
- [重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
- [People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)