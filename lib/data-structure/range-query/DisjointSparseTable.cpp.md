---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range-query/DisjointSparseTable.test.cpp
    title: test/data-structure/range-query/DisjointSparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/range-query/DisjointSparseTable.md
    document_title: DisjointSparseTable
    links: []
  bundledCode: "#line 1 \"lib/data-structure/range-query/DisjointSparseTable.cpp\"\
    \n/*\n * @title DisjointSparseTable\n * @docs md/data-structure/range-query/DisjointSparseTable.md\n\
    \ */\ntemplate<class Operator> class DisjointSparseTable{\npublic:\n    using\
    \ TypeNode = typename Operator::TypeNode;\n    size_t depth;\n    size_t length;\n\
    \    vector<TypeNode> node;\n    vector<size_t> msb;\n\n    DisjointSparseTable(const\
    \ vector<TypeNode>& vec) {\n        for(depth = 0;(1<<depth)<=vec.size();++depth);\n\
    \        length = (1<<depth);\n\n        //msb\n        msb.resize(length,0);\n\
    \        for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j)\
    \ msb[i] = j;\n\n        //init value\n        node.resize(depth*length,Operator::unit_node);\n\
    \        for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n\n        for(int\
    \ i = 1; i < depth; ++i) {\n            for(int r = (1<<i),l = r-1; r < length;\
    \ r += (2<<i),l = r-1){\n                //init accumulate\n                node[i*length+l]\
    \ = node[l];\n                node[i*length+r] = node[r];\n                //accumulate\n\
    \                for(int k = 1; k < (1<<i); ++k) {\n                    node[i*length+l-k]\
    \ = Operator::func_fold(node[i*length+l-k+1],node[l-k]);\n                   \
    \ node[i*length+r+k] = Operator::func_fold(node[i*length+r+k-1],node[r+k]);\n\
    \                }\n            }\n        }\n    }\n\n    //[l,r)\n    TypeNode\
    \ fold(int l,int r) {\n        r--;\n        return (l>r||l<0||length<=r) ? Operator::unit_node:\
    \ (l==r ? node[l] : Operator::func_fold(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));\n\
    \    }\n};\n\n//sum\ntemplate<class T> struct NodeSum {\n    using TypeNode =\
    \ T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n};\n"
  code: "/*\n * @title DisjointSparseTable\n * @docs md/data-structure/range-query/DisjointSparseTable.md\n\
    \ */\ntemplate<class Operator> class DisjointSparseTable{\npublic:\n    using\
    \ TypeNode = typename Operator::TypeNode;\n    size_t depth;\n    size_t length;\n\
    \    vector<TypeNode> node;\n    vector<size_t> msb;\n\n    DisjointSparseTable(const\
    \ vector<TypeNode>& vec) {\n        for(depth = 0;(1<<depth)<=vec.size();++depth);\n\
    \        length = (1<<depth);\n\n        //msb\n        msb.resize(length,0);\n\
    \        for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j)\
    \ msb[i] = j;\n\n        //init value\n        node.resize(depth*length,Operator::unit_node);\n\
    \        for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n\n        for(int\
    \ i = 1; i < depth; ++i) {\n            for(int r = (1<<i),l = r-1; r < length;\
    \ r += (2<<i),l = r-1){\n                //init accumulate\n                node[i*length+l]\
    \ = node[l];\n                node[i*length+r] = node[r];\n                //accumulate\n\
    \                for(int k = 1; k < (1<<i); ++k) {\n                    node[i*length+l-k]\
    \ = Operator::func_fold(node[i*length+l-k+1],node[l-k]);\n                   \
    \ node[i*length+r+k] = Operator::func_fold(node[i*length+r+k-1],node[r+k]);\n\
    \                }\n            }\n        }\n    }\n\n    //[l,r)\n    TypeNode\
    \ fold(int l,int r) {\n        r--;\n        return (l>r||l<0||length<=r) ? Operator::unit_node:\
    \ (l==r ? node[l] : Operator::func_fold(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));\n\
    \    }\n};\n\n//sum\ntemplate<class T> struct NodeSum {\n    using TypeNode =\
    \ T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/range-query/DisjointSparseTable.cpp
  requiredBy: []
  timestamp: '2023-05-15 02:45:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range-query/DisjointSparseTable.test.cpp
documentation_of: lib/data-structure/range-query/DisjointSparseTable.cpp
layout: document
redirect_from:
- /library/lib/data-structure/range-query/DisjointSparseTable.cpp
- /library/lib/data-structure/range-query/DisjointSparseTable.cpp.html
title: DisjointSparseTable
---
