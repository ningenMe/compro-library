---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/PotentializedUnionFindTree.test.cpp
    title: test/graph/PotentializedUnionFindTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/PotentializedUnionFindTree.md
    document_title: "PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
      \u4ED8\u304DUnionFind\u6728"
    links: []
  bundledCode: "#line 1 \"lib/graph/PotentializedUnionFindTree.cpp\"\n/*\n * @title\
    \ PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
    UnionFind\u6728\n * @docs md/graph/PotentializedUnionFindTree.md\n */\ntemplate<class\
    \ T> class PotentializedUnionFindTree {\n\tvector<int> parent,rank;\n\tvector<T>\
    \ potential;\n\tinline int root(int n) {\n\t\tif (parent[n] == n) {\n        \
    \    return n;\n        }\n\t\telse {\n\t\t\tint r = root(parent[n]);\n\t\t\t\
    potential[n] += potential[parent[n]];\n\t\t\treturn parent[n] = r;\n\t\t}\n\t\
    }\n    inline T updated_dist(int x) {\n\t\troot(x);\n\t\treturn potential[x];\n\
    \t}\npublic:\n\tPotentializedUnionFindTree(int N = 1, T ini = 0) : parent(N),rank(N,1),potential(N,ini)\
    \ {\n        iota(parent.begin(),parent.end(),0);\n    }\n\tinline bool connected(int\
    \ n, int m) {\n\t\treturn root(n) == root(m);\n\t}\n    /*\n    * potential[m]\
    \ = potential[n] + d\u3068\u306A\u308B\u3088\u3046\u306B\u30DE\u30FC\u30B8\u3059\
    \u308B\n    */\n\tbool merge(int n, int m, T d=0) {\n\t\td += updated_dist(n);\n\
    \t\td -= updated_dist(m);\n\t\tn = root(n); m = root(m);\n\t\tif (n == m) return\
    \ false;\n\t\tif (rank[n] < rank[m]) {\n\t\t\tswap(n, m);\n\t\t\td = -d;\n\t\t\
    }\n\t\tif (rank[n] == rank[m]) ++rank[n];\n\t\tparent[m] = n;\n\t\tpotential[m]\
    \ = d;\n\t\treturn true;\n\t}\n    /*\n    * potential[m] - potential[n]\n   \
    \ */\n\tT diff(int n, int m) {\n\t\treturn updated_dist(m) - updated_dist(n);\n\
    \t}\n\tinline int operator[](int n) {\n\t\treturn root(n);\n\t}\n\tinline void\
    \ print() {\n\t\tfor(int i = 0; i < parent.size(); ++i) cout << root(i) << \"\
    \ \";\n\t\tcout << endl;\n\t}\n};\n"
  code: "/*\n * @title PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\
    \u30EB\u4ED8\u304DUnionFind\u6728\n * @docs md/graph/PotentializedUnionFindTree.md\n\
    \ */\ntemplate<class T> class PotentializedUnionFindTree {\n\tvector<int> parent,rank;\n\
    \tvector<T> potential;\n\tinline int root(int n) {\n\t\tif (parent[n] == n) {\n\
    \            return n;\n        }\n\t\telse {\n\t\t\tint r = root(parent[n]);\n\
    \t\t\tpotential[n] += potential[parent[n]];\n\t\t\treturn parent[n] = r;\n\t\t\
    }\n\t}\n    inline T updated_dist(int x) {\n\t\troot(x);\n\t\treturn potential[x];\n\
    \t}\npublic:\n\tPotentializedUnionFindTree(int N = 1, T ini = 0) : parent(N),rank(N,1),potential(N,ini)\
    \ {\n        iota(parent.begin(),parent.end(),0);\n    }\n\tinline bool connected(int\
    \ n, int m) {\n\t\treturn root(n) == root(m);\n\t}\n    /*\n    * potential[m]\
    \ = potential[n] + d\u3068\u306A\u308B\u3088\u3046\u306B\u30DE\u30FC\u30B8\u3059\
    \u308B\n    */\n\tbool merge(int n, int m, T d=0) {\n\t\td += updated_dist(n);\n\
    \t\td -= updated_dist(m);\n\t\tn = root(n); m = root(m);\n\t\tif (n == m) return\
    \ false;\n\t\tif (rank[n] < rank[m]) {\n\t\t\tswap(n, m);\n\t\t\td = -d;\n\t\t\
    }\n\t\tif (rank[n] == rank[m]) ++rank[n];\n\t\tparent[m] = n;\n\t\tpotential[m]\
    \ = d;\n\t\treturn true;\n\t}\n    /*\n    * potential[m] - potential[n]\n   \
    \ */\n\tT diff(int n, int m) {\n\t\treturn updated_dist(m) - updated_dist(n);\n\
    \t}\n\tinline int operator[](int n) {\n\t\treturn root(n);\n\t}\n\tinline void\
    \ print() {\n\t\tfor(int i = 0; i < parent.size(); ++i) cout << root(i) << \"\
    \ \";\n\t\tcout << endl;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/PotentializedUnionFindTree.cpp
  requiredBy: []
  timestamp: '2020-10-25 03:59:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/PotentializedUnionFindTree.test.cpp
documentation_of: lib/graph/PotentializedUnionFindTree.cpp
layout: document
redirect_from:
- /library/lib/graph/PotentializedUnionFindTree.cpp
- /library/lib/graph/PotentializedUnionFindTree.cpp.html
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