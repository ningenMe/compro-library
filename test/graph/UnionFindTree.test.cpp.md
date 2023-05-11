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
    \ */\nclass UnionFindTree {\n    vector<int> parent,maxi,mini;\n    inline int\
    \ root(int n) {\n        return (parent[n]<0?n:parent[n] = root(parent[n]));\n\
    \    }\npublic:\n    UnionFindTree(int N = 1) : parent(N,-1),maxi(N),mini(N){\n\
    \        iota(maxi.begin(),maxi.end(),0);\n        iota(mini.begin(),mini.end(),0);\n\
    \    }\n    inline bool connected(int n, int m) {\n        return root(n) == root(m);\n\
    \    }\n    inline void merge(int n, int m) {\n        n = root(n);\n        m\
    \ = root(m);\n        if (n == m) return;\n        if(parent[n]>parent[m]) swap(n,\
    \ m);\n        parent[n] += parent[m];\n        parent[m] = n;\n        maxi[n]\
    \ = std::max(maxi[n],maxi[m]);\n        mini[n] = std::min(mini[n],mini[m]);\n\
    \    }\n    inline int min(int n) {\n        return mini[root(n)];\n    }\n  \
    \  inline int max(int n) {\n        return maxi[root(n)];\n    }\n    inline int\
    \ size(int n){\n        return (-parent[root(n)]);\n    }\n    inline int operator[](int\
    \ n) {\n        return root(n);\n    }\n    inline void print() {\n        for(int\
    \ i = 0; i < parent.size(); ++i) cout << root(i) << \" \";\n        cout << endl;\n\
    \    }\n};\n#line 8 \"test/graph/UnionFindTree.test.cpp\"\n\nint main(){\n   \
    \ int N,Q; cin >> N >> Q;\n    UnionFindTree uf(N);\n    while(Q--){\n       \
    \ int q,a,b; cin >> q >> a >> b;\n        if(q) cout << uf.connected(a,b) << endl;\n\
    \        else uf.merge(a,b);\n    }\n}\n"
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
  timestamp: '2023-05-12 02:35:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/UnionFindTree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/UnionFindTree.test.cpp
- /verify/test/graph/UnionFindTree.test.cpp.html
title: test/graph/UnionFindTree.test.cpp
---
