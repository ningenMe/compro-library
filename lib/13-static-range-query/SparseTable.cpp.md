---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static-range-query/SparseTable.test.cpp
    title: test/static-range-query/SparseTable.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: md/static-range-query/SparseTable.md
    document_title: SparseTable
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/SparseTable.cpp\"\n/*\n * @title\
    \ SparseTable\n * @docs md/static-range-query/SparseTable.md\n */\ntemplate<class\
    \ Operator> class SparseTable{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    vector<TypeNode> node;\n    vector<size_t> idx;\n    size_t depth;\n    size_t\
    \ length;\n\n    SparseTable(const vector<TypeNode>& vec) {\n        for(depth\
    \ = 0;(1<<depth)<=vec.size();++depth);\n        length = (1<<depth);\n       \
    \ node.resize(depth*length);\n        for(int i = 0; i < vec.size(); ++i) node[i]\
    \ = vec[i];\n        for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i)\
    \ < (1<<depth); ++j) node[i*length+j] = Operator::func_fold(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n        idx.resize(vec.size()+1);\n        for(int i = 2;\
    \ i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;\n    }\n\n    //[l,r)\n    TypeNode\
    \ fold(const int l,const int r) {\n        size_t bit = idx[r-l];\n        return\
    \ Operator::func_fold(node[bit*length+l],node[bit*length+r - (1<<bit)]);\n   \
    \ }\n};\n\ntemplate<class T> struct NodeMin {\n    using TypeNode = T;\n    inline\
    \ static constexpr TypeNode unitNode = 1LL<<31;\n    inline static constexpr TypeNode\
    \ func_fold(TypeNode l,TypeNode r){return min(l,r);}\n};\n"
  code: "/*\n * @title SparseTable\n * @docs md/static-range-query/SparseTable.md\n\
    \ */\ntemplate<class Operator> class SparseTable{\npublic:\n    using TypeNode\
    \ = typename Operator::TypeNode;\n    vector<TypeNode> node;\n    vector<size_t>\
    \ idx;\n    size_t depth;\n    size_t length;\n\n    SparseTable(const vector<TypeNode>&\
    \ vec) {\n        for(depth = 0;(1<<depth)<=vec.size();++depth);\n        length\
    \ = (1<<depth);\n        node.resize(depth*length);\n        for(int i = 0; i\
    \ < vec.size(); ++i) node[i] = vec[i];\n        for(int i = 1; i < depth; ++i)\
    \ for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Operator::func_fold(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n        idx.resize(vec.size()+1);\n        for(int i = 2;\
    \ i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;\n    }\n\n    //[l,r)\n    TypeNode\
    \ fold(const int l,const int r) {\n        size_t bit = idx[r-l];\n        return\
    \ Operator::func_fold(node[bit*length+l],node[bit*length+r - (1<<bit)]);\n   \
    \ }\n};\n\ntemplate<class T> struct NodeMin {\n    using TypeNode = T;\n    inline\
    \ static constexpr TypeNode unitNode = 1LL<<31;\n    inline static constexpr TypeNode\
    \ func_fold(TypeNode l,TypeNode r){return min(l,r);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/SparseTable.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static-range-query/SparseTable.test.cpp
documentation_of: lib/13-static-range-query/SparseTable.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/SparseTable.cpp
- /library/lib/13-static-range-query/SparseTable.cpp.html
title: SparseTable
---
