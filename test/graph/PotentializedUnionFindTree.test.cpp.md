---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/PotentializedUnionFindTree.cpp
    title: "PotentializedUnionFindTree - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\
      \u304DUnionFind\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ std;\n#line 1 \"lib/graph/PotentializedUnionFindTree.cpp\"\n/*\n * @title PotentializedUnionFindTree\
    \ - \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind\u6728\n * @docs\
    \ md/graph/PotentializedUnionFindTree.md\n */\ntemplate<class T> class PotentializedUnionFindTree\
    \ {\n\tvector<int> parent,rank;\n\tvector<T> potential;\n\tinline int root(int\
    \ n) {\n\t\tif (parent[n] == n) {\n            return n;\n        }\n\t\telse\
    \ {\n\t\t\tint r = root(parent[n]);\n\t\t\tpotential[n] += potential[parent[n]];\n\
    \t\t\treturn parent[n] = r;\n\t\t}\n\t}\n    inline T updated_dist(int x) {\n\t\
    \troot(x);\n\t\treturn potential[x];\n\t}\npublic:\n\tPotentializedUnionFindTree(int\
    \ N = 1, T ini = 0) : parent(N),rank(N,1),potential(N,ini) {\n        iota(parent.begin(),parent.end(),0);\n\
    \    }\n\tinline bool connected(int n, int m) {\n\t\treturn root(n) == root(m);\n\
    \t}\n    /*\n    * potential[m] = potential[n] + d\u3068\u306A\u308B\u3088\u3046\
    \u306B\u30DE\u30FC\u30B8\u3059\u308B\n    */\n\tbool merge(int n, int m, T d=0)\
    \ {\n\t\td += updated_dist(n);\n\t\td -= updated_dist(m);\n\t\tn = root(n); m\
    \ = root(m);\n\t\tif (n == m) return false;\n\t\tif (rank[n] < rank[m]) {\n\t\t\
    \tswap(n, m);\n\t\t\td = -d;\n\t\t}\n\t\tif (rank[n] == rank[m]) ++rank[n];\n\t\
    \tparent[m] = n;\n\t\tpotential[m] = d;\n\t\treturn true;\n\t}\n    /*\n    *\
    \ potential[m] - potential[n]\n    */\n\tT diff(int n, int m) {\n\t\treturn updated_dist(m)\
    \ - updated_dist(n);\n\t}\n\tinline int operator[](int n) {\n\t\treturn root(n);\n\
    \t}\n\tinline void print() {\n\t\tfor(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n\t\tcout << endl;\n\t}\n};\n#line 8 \"test/graph/PotentializedUnionFindTree.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    PotentializedUnionFindTree<int> uf(N);\n    while(Q--) {\n \
    \       int q; cin >> q;\n        if(q) {\n            int x,y; cin >> x >> y;\n\
    \            if(uf.connected(y,x)) cout << uf.diff(x,y) << endl;\n           \
    \ else cout << \"?\" << endl;\n        }\n        else {\n            int x,y,z;\
    \ cin >> x >> y >> z;\n            uf.merge(x,y,z);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\nusing namespace\
    \ std;\n#include \"../../lib/graph/PotentializedUnionFindTree.cpp\"\n\nint main(){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin >> N >> Q;\n  \
    \  PotentializedUnionFindTree<int> uf(N);\n    while(Q--) {\n        int q; cin\
    \ >> q;\n        if(q) {\n            int x,y; cin >> x >> y;\n            if(uf.connected(y,x))\
    \ cout << uf.diff(x,y) << endl;\n            else cout << \"?\" << endl;\n   \
    \     }\n        else {\n            int x,y,z; cin >> x >> y >> z;\n        \
    \    uf.merge(x,y,z);\n        }\n    }\n}\n"
  dependsOn:
  - lib/graph/PotentializedUnionFindTree.cpp
  isVerificationFile: true
  path: test/graph/PotentializedUnionFindTree.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 03:59:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/PotentializedUnionFindTree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/PotentializedUnionFindTree.test.cpp
- /verify/test/graph/PotentializedUnionFindTree.test.cpp.html
title: test/graph/PotentializedUnionFindTree.test.cpp
---
