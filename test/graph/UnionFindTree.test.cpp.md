---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/UnionFindTree.cpp
    title: "UnionFindTree - Union Find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/graph/UnionFindTree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#include <vector>\n#include <iostream>\n\
    #include <numeric>\nusing namespace std;\n#line 1 \"lib/graph/UnionFindTree.cpp\"\
    \n/*\n * @title UnionFindTree - Union Find \u6728\n * @docs md/graph/UnionFindTree.md\n\
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
    \ << root(i) << \" \";\n\t\tcout << endl;\n\t}\n};\n#line 8 \"test/graph/UnionFindTree.test.cpp\"\
    \n\nint main(){\n    int N,Q; cin >> N >> Q;\n    UnionFindTree uf(N);\n    while(Q--){\n\
    \        int q,a,b; cin >> q >> a >> b;\n        if(q) cout << uf.connected(a,b)\
    \ << endl;\n        else uf.merge(a,b);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <numeric>\nusing namespace std;\n#include\
    \ \"../../lib/graph/UnionFindTree.cpp\"\n\nint main(){\n    int N,Q; cin >> N\
    \ >> Q;\n    UnionFindTree uf(N);\n    while(Q--){\n        int q,a,b; cin >>\
    \ q >> a >> b;\n        if(q) cout << uf.connected(a,b) << endl;\n        else\
    \ uf.merge(a,b);\n    }\n}\n"
  dependsOn:
  - lib/graph/UnionFindTree.cpp
  isVerificationFile: true
  path: test/graph/UnionFindTree.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:13:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/UnionFindTree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/UnionFindTree.test.cpp
- /verify/test/graph/UnionFindTree.test.cpp.html
title: test/graph/UnionFindTree.test.cpp
---
