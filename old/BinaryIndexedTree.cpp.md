---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/abc130/tasks/abc130_d
    - https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j
  bundledCode: "#line 1 \"old/BinaryIndexedTree.cpp\"\n\n//Binary Indexed Tree\ntemplate<class\
    \ Operator> class BinaryIndexedTree {\n\tOperator Op;                        \
    \                 \n\tusing typeNode = decltype(Op.unitNode);\n\tsize_t depth;\
    \         \n\tsize_t length;\n\tsize_t num;\n\tvector<typeNode> node;\n\npublic:\n\
    \tBinaryIndexedTree(const size_t num) : num(num) {\n\t\tfor (depth = 1,length\
    \ = 1; length < num; depth++,length *= 2);\n\t\tnode.resize(length+1, Op.unitNode);\n\
    \t}\n \n\t//[idx,idx+1) update\n\tvoid update(size_t idx, typeNode var) {\n\t\t\
    assert(0 <= idx && idx < length);\n\t\tfor (++idx; idx <= length; idx += idx &\
    \ -idx) node[idx] = Op.funcNode(node[idx],var);\n\t}\n\n\t//[0,idx) get\n\ttypeNode\
    \ get(size_t idx) {\n\t\ttypeNode ret = Op.unitNode;\n\t\tfor (idx = min(length,idx);\
    \ idx > 0; idx -= idx & -idx) ret = Op.funcNode(ret,node[idx]);\n\t\treturn ret;\n\
    \t}\n\n\t//return [0,length]\n\tint BinarySearch(typeNode var) {\n\t\tif(!Op.funcCheck(node.back(),var))\
    \ return num;\n\t\ttypeNode ret = Op.unitNode;\n\t\tsize_t off = 0;\n\t\tfor(size_t\
    \ idx = length; idx; idx >>= 1){\n\t\t\tif(off + idx <= length && !Op.funcCheck(Op.funcNode(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Op.funcNode(ret,node[off]);\n\t\t\t}\n\
    \t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \" <<\
    \ get(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n\t\
    \tcout << \" }\" << endl;\n\t}\n};\n\ntemplate<class typeNode> struct nodeAddPrefixSum\
    \ {\n\ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return\
    \ l+r;}\n\t// Binary Search for first index where funcCheck is true\n\tbool funcCheck(typeNode\
    \ nodeVal,typeNode val){return val <= nodeVal;}\n};\n\ntemplate<class typeNode>\
    \ struct nodeUpdatePrefixGCD {\n\ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode\
    \ l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}\n\t// Binary Search\
    \ for first index at where funcCheck is true\n\tbool funcCheck(typeNode nodeVal,typeNode\
    \ var){return var == nodeVal;}\n};\n\n//verify https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j\n\
    //verify https://atcoder.jp/contests/abc130/tasks/abc130_d\n"
  code: "\n//Binary Indexed Tree\ntemplate<class Operator> class BinaryIndexedTree\
    \ {\n\tOperator Op;                                         \n\tusing typeNode\
    \ = decltype(Op.unitNode);\n\tsize_t depth;         \n\tsize_t length;\n\tsize_t\
    \ num;\n\tvector<typeNode> node;\n\npublic:\n\tBinaryIndexedTree(const size_t\
    \ num) : num(num) {\n\t\tfor (depth = 1,length = 1; length < num; depth++,length\
    \ *= 2);\n\t\tnode.resize(length+1, Op.unitNode);\n\t}\n \n\t//[idx,idx+1) update\n\
    \tvoid update(size_t idx, typeNode var) {\n\t\tassert(0 <= idx && idx < length);\n\
    \t\tfor (++idx; idx <= length; idx += idx & -idx) node[idx] = Op.funcNode(node[idx],var);\n\
    \t}\n\n\t//[0,idx) get\n\ttypeNode get(size_t idx) {\n\t\ttypeNode ret = Op.unitNode;\n\
    \t\tfor (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Op.funcNode(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint BinarySearch(typeNode var)\
    \ {\n\t\tif(!Op.funcCheck(node.back(),var)) return num;\n\t\ttypeNode ret = Op.unitNode;\n\
    \t\tsize_t off = 0;\n\t\tfor(size_t idx = length; idx; idx >>= 1){\n\t\t\tif(off\
    \ + idx <= length && !Op.funcCheck(Op.funcNode(ret,node[off+idx]),var)) {\n\t\t\
    \t\toff += idx;\n\t\t\t\tret = Op.funcNode(ret,node[off]);\n\t\t\t}\n\t\t}\n\t\
    \treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \" << get(1);\n\
    \t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n\t\tcout << \"\
    \ }\" << endl;\n\t}\n};\n\ntemplate<class typeNode> struct nodeAddPrefixSum {\n\
    \ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return l+r;}\n\
    \t// Binary Search for first index where funcCheck is true\n\tbool funcCheck(typeNode\
    \ nodeVal,typeNode val){return val <= nodeVal;}\n};\n\ntemplate<class typeNode>\
    \ struct nodeUpdatePrefixGCD {\n\ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode\
    \ l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}\n\t// Binary Search\
    \ for first index at where funcCheck is true\n\tbool funcCheck(typeNode nodeVal,typeNode\
    \ var){return var == nodeVal;}\n};\n\n//verify https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j\n\
    //verify https://atcoder.jp/contests/abc130/tasks/abc130_d"
  dependsOn: []
  isVerificationFile: false
  path: old/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2020-04-28 05:55:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/old/BinaryIndexedTree.cpp
- /library/old/BinaryIndexedTree.cpp.html
title: old/BinaryIndexedTree.cpp
---
