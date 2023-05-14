---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/UnionFindTree.cpp
    title: "UnionFindTree - Union Find \u6728"
  - icon: ':heavy_check_mark:'
    path: lib/util/RangeIndex.cpp
    title: "RangeIndex - \u533A\u9593index"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1170
    links:
    - https://yukicoder.me/problems/no/1170
  bundledCode: "#line 1 \"test/util/RangeIndex.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1170\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <numeric>\nusing namespace std;\n#line 1 \"lib/util/RangeIndex.cpp\"\n\
    /*\n * @title RangeIndex - \u533A\u9593index\n * @docs md/util/RangeIndex.md\n\
    \ */\nclass RangeIndex{\n\tint length;\npublic:\n\tRangeIndex(const int N) {\n\
    \t\tfor (length = 1; length <= N; length *= 2);\n\t}\n\t//[l,r)\n\tvector<int>\
    \ range(int l,int r) {\n\t\tvector<int> res;\n\t\tfor(l += length, r += length;\
    \ l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) res.push_back(l++);\n\t\t\tif(r&1) res.push_back(--r);\n\
    \t\t}\n\t\treturn res;\n\t}\n\t// ranges that include x\n\tvector<int> include_range(int\
    \ x) {\n\t\tvector<int> res;\n        for(int i=x+length; i; i >>= 1) res.push_back(i);\n\
    \t\treturn res;\n\t}\n\tinline int operator[](int idx) {\n\t\treturn idx+length;\n\
    \t}\n\tinline size_t size(void){\n\t\treturn 2*length;\n\t}\n};\n#line 1 \"lib/graph/UnionFindTree.cpp\"\
    \n/*\n * @title UnionFindTree - Union Find \u6728\n * @docs md/graph/UnionFindTree.md\n\
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
    \ << root(i) << \" \";\n        cout << endl;\n    }\n};\n#line 11 \"test/util/RangeIndex.test.cpp\"\
    \n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    long long\
    \ N,A,B; cin >> N >> A >> B;\n    vector<long long> X(N);\n    for(int i = 0;\
    \ i < N; ++i) cin >> X[i];\n    X.push_back(1e10);\n    RangeIndex ri(N);\n  \
    \  UnionFindTree uf(ri.size());\n    vector<int> st(ri.size(),0);\n    for(int\
    \ i = 0; i < N; ++i) {\n        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();\n\
    \        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();\n        for(auto&\
    \ e:ri.range(l,r)) {\n            st[e]=1;\n            uf.merge(ri[i],e);\n \
    \       }\n    }\n    for(int i = 0; i < N; ++i) {\n        for(auto& e:ri.include_range(i))\
    \ if(st[e]) uf.merge(ri[i],e);\n    }\n    vector<int> cnt(ri.size(),0);\n   \
    \ for(int i = 0; i < N; ++i) {\n        cnt[uf[ri[i]]]++;\n    }\n    for(int\
    \ i = 0; i < N; ++i) {\n        cout << cnt[uf[ri[i]]] << endl;\n    }\n\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1170\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    using namespace std;\n#include \"../../lib/util/RangeIndex.cpp\"\n#include \"\
    ../../lib/graph/UnionFindTree.cpp\"\n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    long long N,A,B; cin >> N >> A >> B;\n    vector<long long> X(N);\n    for(int\
    \ i = 0; i < N; ++i) cin >> X[i];\n    X.push_back(1e10);\n    RangeIndex ri(N);\n\
    \    UnionFindTree uf(ri.size());\n    vector<int> st(ri.size(),0);\n    for(int\
    \ i = 0; i < N; ++i) {\n        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();\n\
    \        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();\n        for(auto&\
    \ e:ri.range(l,r)) {\n            st[e]=1;\n            uf.merge(ri[i],e);\n \
    \       }\n    }\n    for(int i = 0; i < N; ++i) {\n        for(auto& e:ri.include_range(i))\
    \ if(st[e]) uf.merge(ri[i],e);\n    }\n    vector<int> cnt(ri.size(),0);\n   \
    \ for(int i = 0; i < N; ++i) {\n        cnt[uf[ri[i]]]++;\n    }\n    for(int\
    \ i = 0; i < N; ++i) {\n        cout << cnt[uf[ri[i]]] << endl;\n    }\n\n   \
    \ return 0;\n}\n"
  dependsOn:
  - lib/util/RangeIndex.cpp
  - lib/graph/UnionFindTree.cpp
  isVerificationFile: true
  path: test/util/RangeIndex.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 02:35:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/util/RangeIndex.test.cpp
layout: document
redirect_from:
- /verify/test/util/RangeIndex.test.cpp
- /verify/test/util/RangeIndex.test.cpp.html
title: test/util/RangeIndex.test.cpp
---
