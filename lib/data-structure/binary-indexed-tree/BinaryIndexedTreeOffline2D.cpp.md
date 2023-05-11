---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-1.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.md
    document_title: "BinaryIndexedTreeOffline2D - \u30AA\u30D5\u30E9\u30A4\u30F32\u6B21\
      \u5143BIT"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp\"\
    \n/*\n * @title BinaryIndexedTreeOffline2D - \u30AA\u30D5\u30E9\u30A4\u30F32\u6B21\
    \u5143BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTreeOffline2D {\n    using TypeNode\
    \ = typename Abel::TypeNode;\n    using i64 = long long;\n\n    class InternalBinaryIndexedTree\
    \ {\n        size_t length;\n        vector<TypeNode> node;\n    public:\n   \
    \     InternalBinaryIndexedTree() {}\n        InternalBinaryIndexedTree(const\
    \ size_t num) {\n            for (length = 1; length < num; length *= 2);\n  \
    \          node.resize(length+1, Abel::unit_node);\n        }\n        void operate(size_t\
    \ idx, TypeNode var) {\n            for (++idx; idx <= length; idx += idx & -idx)\
    \ node[idx] = Abel::func_fold(node[idx],var);\n        }\n        TypeNode fold(size_t\
    \ idx) {\n            TypeNode ret = Abel::unit_node;\n            for (idx =\
    \ min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \            return ret;\n        }\n    };\n    size_t length;\n    vector<InternalBinaryIndexedTree>\
    \ node;\n    vector<i64> ox;\n    vector<vector<i64>> oy;\n\npublic:\n\n    BinaryIndexedTreeOffline2D(const\
    \ vector<i64>& operator_x,const vector<i64>& operator_y):ox(operator_x) {\n  \
    \      sort(ox.begin(),ox.end());\n        ox.erase(unique(ox.begin(),ox.end()),ox.end());\n\
    \        size_t num = ox.size();\n        for (length = 1; length < num; length\
    \ *= 2);\n        node.resize(length+1);\n        oy.resize(length+1);\n     \
    \   int n = operator_x.size();\n        for(int i=0;i<n;++i) {\n            size_t\
    \ x = (lower_bound(ox.begin(),ox.end(),operator_x[i])-ox.begin());\n         \
    \   for (++x;x<=length; x += x & -x) {\n                oy[x].push_back(operator_y[i]);\n\
    \            }\n        }\n        for(int i=0;i<length+1;++i) {\n           \
    \ sort(oy[i].begin(),oy[i].end());\n            oy[i].erase(unique(oy[i].begin(),oy[i].end()),oy[i].end());\n\
    \            node[i]=InternalBinaryIndexedTree(oy[i].size());\n        }\n   \
    \ }\n\n    //[l,l+1),[d,d+1) operate\n    void operate(i64 l, i64 d, TypeNode\
    \ var) {\n        size_t x = (lower_bound(ox.begin(),ox.end(),l)-ox.begin());\n\
    \        for (++x; x <= length; x += x & -x) {\n            size_t y = (lower_bound(oy[x].begin(),oy[x].end(),d)-oy[x].begin());\n\
    \            node[x].operate(y,var);\n        }\n    }\n\n    //[0,r),[0,u) fold\n\
    \    TypeNode fold(i64 l, i64 u) {\n        TypeNode ret = Abel::unit_node;\n\
    \        size_t x = (lower_bound(ox.begin(),ox.end(),l)-ox.begin());\n       \
    \ for (x = min(length,x); x > 0; x -= x & -x) {\n            size_t y = (lower_bound(oy[x].begin(),oy[x].end(),u)-oy[x].begin());\n\
    \            ret = Abel::func_fold(ret,node[x].fold(y));\n        }\n        return\
    \ ret;\n    }\n\n    // [l,r),[d,u) fold\n    TypeNode fold(i64 l, i64 r, i64\
    \ d, i64 u) {\n        return Abel::func_fold_inv(Abel::func_fold(fold(r,u),fold(l,d)),Abel::func_fold(fold(r,d),fold(l,u)));\n\
    \    }\n};\n"
  code: "/*\n * @title BinaryIndexedTreeOffline2D - \u30AA\u30D5\u30E9\u30A4\u30F3\
    2\u6B21\u5143BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTreeOffline2D {\n    using TypeNode\
    \ = typename Abel::TypeNode;\n    using i64 = long long;\n\n    class InternalBinaryIndexedTree\
    \ {\n        size_t length;\n        vector<TypeNode> node;\n    public:\n   \
    \     InternalBinaryIndexedTree() {}\n        InternalBinaryIndexedTree(const\
    \ size_t num) {\n            for (length = 1; length < num; length *= 2);\n  \
    \          node.resize(length+1, Abel::unit_node);\n        }\n        void operate(size_t\
    \ idx, TypeNode var) {\n            for (++idx; idx <= length; idx += idx & -idx)\
    \ node[idx] = Abel::func_fold(node[idx],var);\n        }\n        TypeNode fold(size_t\
    \ idx) {\n            TypeNode ret = Abel::unit_node;\n            for (idx =\
    \ min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \            return ret;\n        }\n    };\n    size_t length;\n    vector<InternalBinaryIndexedTree>\
    \ node;\n    vector<i64> ox;\n    vector<vector<i64>> oy;\n\npublic:\n\n    BinaryIndexedTreeOffline2D(const\
    \ vector<i64>& operator_x,const vector<i64>& operator_y):ox(operator_x) {\n  \
    \      sort(ox.begin(),ox.end());\n        ox.erase(unique(ox.begin(),ox.end()),ox.end());\n\
    \        size_t num = ox.size();\n        for (length = 1; length < num; length\
    \ *= 2);\n        node.resize(length+1);\n        oy.resize(length+1);\n     \
    \   int n = operator_x.size();\n        for(int i=0;i<n;++i) {\n            size_t\
    \ x = (lower_bound(ox.begin(),ox.end(),operator_x[i])-ox.begin());\n         \
    \   for (++x;x<=length; x += x & -x) {\n                oy[x].push_back(operator_y[i]);\n\
    \            }\n        }\n        for(int i=0;i<length+1;++i) {\n           \
    \ sort(oy[i].begin(),oy[i].end());\n            oy[i].erase(unique(oy[i].begin(),oy[i].end()),oy[i].end());\n\
    \            node[i]=InternalBinaryIndexedTree(oy[i].size());\n        }\n   \
    \ }\n\n    //[l,l+1),[d,d+1) operate\n    void operate(i64 l, i64 d, TypeNode\
    \ var) {\n        size_t x = (lower_bound(ox.begin(),ox.end(),l)-ox.begin());\n\
    \        for (++x; x <= length; x += x & -x) {\n            size_t y = (lower_bound(oy[x].begin(),oy[x].end(),d)-oy[x].begin());\n\
    \            node[x].operate(y,var);\n        }\n    }\n\n    //[0,r),[0,u) fold\n\
    \    TypeNode fold(i64 l, i64 u) {\n        TypeNode ret = Abel::unit_node;\n\
    \        size_t x = (lower_bound(ox.begin(),ox.end(),l)-ox.begin());\n       \
    \ for (x = min(length,x); x > 0; x -= x & -x) {\n            size_t y = (lower_bound(oy[x].begin(),oy[x].end(),u)-oy[x].begin());\n\
    \            ret = Abel::func_fold(ret,node[x].fold(y));\n        }\n        return\
    \ ret;\n    }\n\n    // [l,r),[d,u) fold\n    TypeNode fold(i64 l, i64 r, i64\
    \ d, i64 u) {\n        return Abel::func_fold_inv(Abel::func_fold(fold(r,u),fold(l,d)),Abel::func_fold(fold(r,d),fold(l,u)));\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp
  requiredBy: []
  timestamp: '2021-09-21 03:30:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-1.test.cpp
  - test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
documentation_of: lib/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp
layout: document
redirect_from:
- /library/lib/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp
- /library/lib/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp.html
title: "BinaryIndexedTreeOffline2D - \u30AA\u30D5\u30E9\u30A4\u30F32\u6B21\u5143BIT"
---
