---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/UnionFindTreeSize.cpp\"\n\n//Union Find Tree\nclass\
    \ UnionFindTreeSize {\npublic:\n\tvector<int> parent;\n    vector<int> maxidx;\n\
    \    vector<int> minidx;\n\n    UnionFindTreeSize(int N = 1) : parent(N,-1),maxidx(N),minidx(N){\n\
    \        iota(maxidx.begin(),maxidx.end(),0);\n        iota(minidx.begin(),minidx.end(),0);\n\
    \t}\n \n\tint root(int n) {\n        return (parent[n]<0?n:parent[n] = root(parent[n]));\n\
    \t}\n\n    bool same(int n, int m) {\n\t\treturn root(n) == root(m);\n\t}\n\n\
    \    int mini(int n) {\n        return minidx[root(n)];\n    }\n\n    int maxi(int\
    \ n) {\n        return maxidx[root(n)];\n    }\n \n\tvoid unite(int n, int m)\
    \ {\n\t\tn = root(n);\n\t\tm = root(m);\n\t\tif (n == m) return;\n\t\tif(parent[n]>parent[m])\
    \ swap(n, m);\n        parent[n] += parent[m];\n        parent[m] = n;\n     \
    \   maxidx[n] = max(maxidx[n],maxidx[m]);\n        minidx[n] = min(minidx[n],minidx[m]);\n\
    \t}\n\n    int size(int n){\n        return (-parent[root(n)]);\n    }\n\n   \
    \ void print() {\n        for(int i = 0; i < parent.size(); ++i) cout << root(i)\
    \ << \" \";\n        cout << endl;\n    }\n};\n"
  code: "\n//Union Find Tree\nclass UnionFindTreeSize {\npublic:\n\tvector<int> parent;\n\
    \    vector<int> maxidx;\n    vector<int> minidx;\n\n    UnionFindTreeSize(int\
    \ N = 1) : parent(N,-1),maxidx(N),minidx(N){\n        iota(maxidx.begin(),maxidx.end(),0);\n\
    \        iota(minidx.begin(),minidx.end(),0);\n\t}\n \n\tint root(int n) {\n \
    \       return (parent[n]<0?n:parent[n] = root(parent[n]));\n\t}\n\n    bool same(int\
    \ n, int m) {\n\t\treturn root(n) == root(m);\n\t}\n\n    int mini(int n) {\n\
    \        return minidx[root(n)];\n    }\n\n    int maxi(int n) {\n        return\
    \ maxidx[root(n)];\n    }\n \n\tvoid unite(int n, int m) {\n\t\tn = root(n);\n\
    \t\tm = root(m);\n\t\tif (n == m) return;\n\t\tif(parent[n]>parent[m]) swap(n,\
    \ m);\n        parent[n] += parent[m];\n        parent[m] = n;\n        maxidx[n]\
    \ = max(maxidx[n],maxidx[m]);\n        minidx[n] = min(minidx[n],minidx[m]);\n\
    \t}\n\n    int size(int n){\n        return (-parent[root(n)]);\n    }\n\n   \
    \ void print() {\n        for(int i = 0; i < parent.size(); ++i) cout << root(i)\
    \ << \" \";\n        cout << endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: old/UnionFindTreeSize.cpp
  requiredBy: []
  timestamp: '2020-08-15 06:33:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/UnionFindTreeSize.cpp
layout: document
redirect_from:
- /library/old/UnionFindTreeSize.cpp
- /library/old/UnionFindTreeSize.cpp.html
title: old/UnionFindTreeSize.cpp
---
