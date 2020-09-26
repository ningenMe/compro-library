---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/SparseTable.test.cpp
    title: test/segment/SparseTable.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/segment/SparseTable.md
    document_title: SparseTable
    links: []
  bundledCode: "#line 1 \"lib/segment/SparseTable.cpp\"\n/*\n * @title SparseTable\n\
    \ * @docs md/segment/SparseTable.md\n */\ntemplate<class Operator> class SparseTable{\n\
    public:\n\tusing TypeNode = typename Operator::TypeNode;\n\tvector<TypeNode> node;\n\
    \tvector<int> idx;\n\tsize_t depth;\n\tsize_t length;\n\n\tSparseTable(const vector<TypeNode>&\
    \ vec) {\n\t\tfor(depth = 0;(1<<depth)<=vec.size();++depth);\n\t\tlength = (1<<depth);\n\
    \t\tnode.resize(depth*length);\n\t\tfor(int i = 0; i < vec.size(); ++i) node[i]\
    \ = vec[i];\n\t\tfor(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth);\
    \ ++j) node[i*length+j] = Operator::func_node(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n\t\tidx.resize(vec.size()+1);\n\t\tfor(int i = 2; i < vec.size()+1;\
    \ ++i) idx[i] = idx[i>>1] + 1;\n\t}\n\n\t//[l,r)\n\tTypeNode get(int l,int r)\
    \ {\n\t\tint bit = idx[r-l];\n\t\treturn Operator::func_node(node[bit*length+l],node[bit*length+r\
    \ - (1<<bit)]);\n\t}\n};\n\ntemplate<class T> struct NodeMin {\n\tusing TypeNode\
    \ = T;\n\tinline static constexpr TypeNode unitNode = 1LL<<31;\n\tinline static\
    \ constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n};\n"
  code: "/*\n * @title SparseTable\n * @docs md/segment/SparseTable.md\n */\ntemplate<class\
    \ Operator> class SparseTable{\npublic:\n\tusing TypeNode = typename Operator::TypeNode;\n\
    \tvector<TypeNode> node;\n\tvector<int> idx;\n\tsize_t depth;\n\tsize_t length;\n\
    \n\tSparseTable(const vector<TypeNode>& vec) {\n\t\tfor(depth = 0;(1<<depth)<=vec.size();++depth);\n\
    \t\tlength = (1<<depth);\n\t\tnode.resize(depth*length);\n\t\tfor(int i = 0; i\
    \ < vec.size(); ++i) node[i] = vec[i];\n\t\tfor(int i = 1; i < depth; ++i) for(int\
    \ j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Operator::func_node(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n\t\tidx.resize(vec.size()+1);\n\t\tfor(int i = 2; i < vec.size()+1;\
    \ ++i) idx[i] = idx[i>>1] + 1;\n\t}\n\n\t//[l,r)\n\tTypeNode get(int l,int r)\
    \ {\n\t\tint bit = idx[r-l];\n\t\treturn Operator::func_node(node[bit*length+l],node[bit*length+r\
    \ - (1<<bit)]);\n\t}\n};\n\ntemplate<class T> struct NodeMin {\n\tusing TypeNode\
    \ = T;\n\tinline static constexpr TypeNode unitNode = 1LL<<31;\n\tinline static\
    \ constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/SparseTable.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/SparseTable.test.cpp
documentation_of: lib/segment/SparseTable.cpp
layout: document
redirect_from:
- /library/lib/segment/SparseTable.cpp
- /library/lib/segment/SparseTable.cpp.html
title: SparseTable
---
