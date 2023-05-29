---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/40-graph/PotentializedUnionFindTree.cpp
    title: "PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\
      \u304DUnionFind\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/graph/PotentializedUnionFindTree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\nusing namespace\
    \ std;\n#line 1 \"lib/40-graph/PotentializedUnionFindTree.cpp\"\n/*\n * @title\
    \ PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
    UnionFind\u6728\n * @docs md/graph/PotentializedUnionFindTree.md\n */\ntemplate<class\
    \ T> class PotentializedUnionFindTree {\n    vector<int> parent,rank;\n    vector<T>\
    \ potential;\n    inline int root(int n) {\n        if (parent[n] == n) {\n  \
    \          return n;\n        }\n        else {\n            int r = root(parent[n]);\n\
    \            potential[n] += potential[parent[n]];\n            return parent[n]\
    \ = r;\n        }\n    }\n    inline T updated_dist(int x) {\n        root(x);\n\
    \        return potential[x];\n    }\npublic:\n    PotentializedUnionFindTree(int\
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
    \ << root(i) << \" \";\n        cout << endl;\n    }\n};\n#line 8 \"test/graph/PotentializedUnionFindTree.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    PotentializedUnionFindTree<int> uf(N);\n    while(Q--) {\n \
    \       int q; cin >> q;\n        if(q) {\n            int x,y; cin >> x >> y;\n\
    \            if(uf.connected(y,x)) cout << uf.diff(x,y) << endl;\n           \
    \ else cout << \"?\" << endl;\n        }\n        else {\n            int x,y,z;\
    \ cin >> x >> y >> z;\n            uf.merge(x,y,z);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\nusing namespace\
    \ std;\n#include \"../../lib/40-graph/PotentializedUnionFindTree.cpp\"\n\nint\
    \ main(){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin >> N\
    \ >> Q;\n    PotentializedUnionFindTree<int> uf(N);\n    while(Q--) {\n      \
    \  int q; cin >> q;\n        if(q) {\n            int x,y; cin >> x >> y;\n  \
    \          if(uf.connected(y,x)) cout << uf.diff(x,y) << endl;\n            else\
    \ cout << \"?\" << endl;\n        }\n        else {\n            int x,y,z; cin\
    \ >> x >> y >> z;\n            uf.merge(x,y,z);\n        }\n    }\n}\n"
  dependsOn:
  - lib/40-graph/PotentializedUnionFindTree.cpp
  isVerificationFile: true
  path: test/graph/PotentializedUnionFindTree.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/PotentializedUnionFindTree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/PotentializedUnionFindTree.test.cpp
- /verify/test/graph/PotentializedUnionFindTree.test.cpp.html
title: test/graph/PotentializedUnionFindTree.test.cpp
---
