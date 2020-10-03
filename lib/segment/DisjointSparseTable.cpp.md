---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/DisjointSparseTable.test.cpp
    title: test/segment/DisjointSparseTable.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/DisjointSparseTable.md
    document_title: DisjointSparseTable
    links: []
  bundledCode: "#line 1 \"lib/segment/DisjointSparseTable.cpp\"\n/*\n * @title DisjointSparseTable\n\
    \ * @docs md/segment/DisjointSparseTable.md\n */\ntemplate<class Operator> class\
    \ DisjointSparseTable{\npublic:\n\tusing TypeNode = typename Operator::TypeNode;\n\
    \tsize_t depth;\n\tsize_t length;\n\tvector<TypeNode> node;\n\tvector<size_t>\
    \ msb;\n\n\tDisjointSparseTable(const vector<TypeNode>& vec) {\n\t\tfor(depth\
    \ = 0;(1<<depth)<=vec.size();++depth);\n\t\tlength = (1<<depth);\n\t\t\n\t\t//msb\n\
    \t\tmsb.resize(length,0);\n\t\tfor(int i = 0; i < length; ++i) for(int j = 0;\
    \ j < depth; ++j) if(i>>j) msb[i] = j;\n\n\t\t//init value\n\t\tnode.resize(depth*length,Operator::unit_node);\n\
    \t\tfor(int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n\n\t\tfor(int i = 1;\
    \ i < depth; ++i) {\n\t\t\tfor(int r = (1<<i),l = r-1; r < length; r += (2<<i),l\
    \ = r-1){\n\t\t\t\t//init accumulate\n\t\t\t\tnode[i*length+l] = node[l];\n\t\t\
    \t\tnode[i*length+r] = node[r];\n\t\t\t\t//accumulate\n\t\t\t\tfor(int k = 1;\
    \ k < (1<<i); ++k) {\n\t\t\t\t\tnode[i*length+l-k] = Operator::func_node(node[i*length+l-k+1],node[l-k]);\n\
    \t\t\t\t\tnode[i*length+r+k] = Operator::func_node(node[i*length+r+k-1],node[r+k]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t//[l,r)\n\tTypeNode get(int l,int r) {\n\t\
    \tr--;\n\t\treturn (l>r||l<0||length<=r) ? Operator::unit_node: (l==r ? node[l]\
    \ : Operator::func_node(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));\n\t\
    }\n};\n\n//sum\ntemplate<class T> struct NodeSum {\n\tusing TypeNode = T;\n\t\
    inline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode r){return l+r;}\n};\n"
  code: "/*\n * @title DisjointSparseTable\n * @docs md/segment/DisjointSparseTable.md\n\
    \ */\ntemplate<class Operator> class DisjointSparseTable{\npublic:\n\tusing TypeNode\
    \ = typename Operator::TypeNode;\n\tsize_t depth;\n\tsize_t length;\n\tvector<TypeNode>\
    \ node;\n\tvector<size_t> msb;\n\n\tDisjointSparseTable(const vector<TypeNode>&\
    \ vec) {\n\t\tfor(depth = 0;(1<<depth)<=vec.size();++depth);\n\t\tlength = (1<<depth);\n\
    \t\t\n\t\t//msb\n\t\tmsb.resize(length,0);\n\t\tfor(int i = 0; i < length; ++i)\
    \ for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;\n\n\t\t//init value\n\t\t\
    node.resize(depth*length,Operator::unit_node);\n\t\tfor(int i = 0; i < vec.size();\
    \ ++i) node[i] = vec[i];\n\n\t\tfor(int i = 1; i < depth; ++i) {\n\t\t\tfor(int\
    \ r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){\n\t\t\t\t//init accumulate\n\
    \t\t\t\tnode[i*length+l] = node[l];\n\t\t\t\tnode[i*length+r] = node[r];\n\t\t\
    \t\t//accumulate\n\t\t\t\tfor(int k = 1; k < (1<<i); ++k) {\n\t\t\t\t\tnode[i*length+l-k]\
    \ = Operator::func_node(node[i*length+l-k+1],node[l-k]);\n\t\t\t\t\tnode[i*length+r+k]\
    \ = Operator::func_node(node[i*length+r+k-1],node[r+k]);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\t//[l,r)\n\tTypeNode get(int l,int r) {\n\t\tr--;\n\t\treturn (l>r||l<0||length<=r)\
    \ ? Operator::unit_node: (l==r ? node[l] : Operator::func_node(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));\n\
    \t}\n};\n\n//sum\ntemplate<class T> struct NodeSum {\n\tusing TypeNode = T;\n\t\
    inline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode r){return l+r;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/DisjointSparseTable.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/DisjointSparseTable.test.cpp
documentation_of: lib/segment/DisjointSparseTable.cpp
layout: document
redirect_from:
- /library/lib/segment/DisjointSparseTable.cpp
- /library/lib/segment/DisjointSparseTable.cpp.html
title: DisjointSparseTable
---
