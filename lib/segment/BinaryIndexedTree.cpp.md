---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/BinaryIndexedTree-rsqraq.test.cpp
    title: test/segment/BinaryIndexedTree-rsqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/RangeInversionQuery.test.cpp
    title: test/segment/RangeInversionQuery.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/BinaryIndexedTree.md
    document_title: BinaryIndexedTree
    links: []
  bundledCode: "#line 1 \"lib/segment/BinaryIndexedTree.cpp\"\n/*\n * @title BinaryIndexedTree\n\
    \ * @docs md/segment/BinaryIndexedTree.md\n */\ntemplate<class Operator> class\
    \ BinaryIndexedTree {\n\tusing TypeNode = typename Operator::TypeNode;\n\tsize_t\
    \ depth;         \n\tsize_t length;\n\tsize_t num;\n\tvector<TypeNode> node;\n\
    public:\n\t\n\t//[0,N) constructed, inplace [0,1) + [1,N+1)\n\t//you can ignore\
    \ inplace offset\n\tBinaryIndexedTree(const size_t num) : num(num) {\n\t\tfor\
    \ (depth = 1,length = 1; length < num; depth++,length *= 2);\n\t\tnode.resize(length+1,\
    \ Operator::unit_node);\n\t}\n \n\t//[idx,idx+1) update \n\tvoid update(size_t\
    \ idx, TypeNode var) {\n\t\tassert(0 <= idx && idx < length);\n\t\tfor (++idx;\
    \ idx <= length; idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);\n\
    \t}\n\n\t//[0,idx) get\n\tTypeNode get(size_t idx) {\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tfor (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint binary_search(TypeNode var)\
    \ {\n\t\tif(!Operator::func_check(node.back(),var)) return num;\n\t\tTypeNode\
    \ ret = Operator::unit_node;\n\t\tsize_t off = 0;\n\t\tfor(size_t idx = length;\
    \ idx; idx >>= 1){\n\t\t\tif(off + idx <= length && !Operator::func_check(Operator::func_node(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Operator::func_node(ret,node[off]);\n\t\
    \t\t}\n\t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"\
    { \" << get(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n\
    \t\tcout << \" }\" << endl;\n\t}\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd\
    \ {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\
    \tinline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return l+r;}\n\t// Binary Search for first index where func_check is true\n\
    \tinline static constexpr bool func_check(const TypeNode nodeVal,const TypeNode&\
    \ val){return val <= nodeVal;}\n};\n\ntemplate<class TypeNode> struct NodeUpdatePrefixGcd\
    \ {\n\tTypeNode unit_node = 0;\n\tTypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return ((r == 0) ? l : func_node(r, l % r));}\n\t// Binary Search for first\
    \ index at where func_check is true\n\tbool func_check(const TypeNode nodeVal,const\
    \ TypeNode& var){return var == nodeVal;}\n};\n"
  code: "/*\n * @title BinaryIndexedTree\n * @docs md/segment/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Operator> class BinaryIndexedTree {\n\tusing TypeNode = typename\
    \ Operator::TypeNode;\n\tsize_t depth;         \n\tsize_t length;\n\tsize_t num;\n\
    \tvector<TypeNode> node;\npublic:\n\t\n\t//[0,N) constructed, inplace [0,1) +\
    \ [1,N+1)\n\t//you can ignore inplace offset\n\tBinaryIndexedTree(const size_t\
    \ num) : num(num) {\n\t\tfor (depth = 1,length = 1; length < num; depth++,length\
    \ *= 2);\n\t\tnode.resize(length+1, Operator::unit_node);\n\t}\n \n\t//[idx,idx+1)\
    \ update \n\tvoid update(size_t idx, TypeNode var) {\n\t\tassert(0 <= idx && idx\
    \ < length);\n\t\tfor (++idx; idx <= length; idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);\n\
    \t}\n\n\t//[0,idx) get\n\tTypeNode get(size_t idx) {\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tfor (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint binary_search(TypeNode var)\
    \ {\n\t\tif(!Operator::func_check(node.back(),var)) return num;\n\t\tTypeNode\
    \ ret = Operator::unit_node;\n\t\tsize_t off = 0;\n\t\tfor(size_t idx = length;\
    \ idx; idx >>= 1){\n\t\t\tif(off + idx <= length && !Operator::func_check(Operator::func_node(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Operator::func_node(ret,node[off]);\n\t\
    \t\t}\n\t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"\
    { \" << get(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n\
    \t\tcout << \" }\" << endl;\n\t}\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd\
    \ {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\
    \tinline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return l+r;}\n\t// Binary Search for first index where func_check is true\n\
    \tinline static constexpr bool func_check(const TypeNode nodeVal,const TypeNode&\
    \ val){return val <= nodeVal;}\n};\n\ntemplate<class TypeNode> struct NodeUpdatePrefixGcd\
    \ {\n\tTypeNode unit_node = 0;\n\tTypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return ((r == 0) ? l : func_node(r, l % r));}\n\t// Binary Search for first\
    \ index at where func_check is true\n\tbool func_check(const TypeNode nodeVal,const\
    \ TypeNode& var){return var == nodeVal;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/RangeInversionQuery.test.cpp
  - test/segment/BinaryIndexedTree-rsqraq.test.cpp
documentation_of: lib/segment/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/lib/segment/BinaryIndexedTree.cpp
- /library/lib/segment/BinaryIndexedTree.cpp.html
title: BinaryIndexedTree
---
