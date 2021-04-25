---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/binary-indexed-tree/BinaryIndexedTree.md
    document_title: BinaryIndexedTree - BIT
    links: []
  bundledCode: "#line 1 \"lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n/*\n * @title BinaryIndexedTree - BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTree {\n\tusing TypeNode = typename\
    \ Abel::TypeNode;\n\tsize_t length;\n\tsize_t num;\n\tvector<TypeNode> node;\n\
    public:\n\t\n\t//[0,N) constructed, inplace [0,1) + [1,N+1)\n\t//you can ignore\
    \ inplace offset\n\tBinaryIndexedTree(const size_t num) : num(num) {\n\t\tfor\
    \ (length = 1; length < num; length *= 2);\n\t\tnode.resize(length+1, Abel::unit_node);\n\
    \t}\n \n\t//[idx,idx+1) operate \n\tvoid operate(size_t idx, TypeNode var) {\n\
    \t\tassert(0 <= idx && idx < length);\n\t\tfor (++idx; idx <= length; idx += idx\
    \ & -idx) node[idx] = Abel::func_fold(node[idx],var);\n\t}\n\n\t//[0,idx) fold\n\
    \tTypeNode fold(size_t idx) {\n\t\tTypeNode ret = Abel::unit_node;\n\t\tfor (idx\
    \ = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint binary_search(TypeNode var)\
    \ {\n\t\tif(!Abel::func_check(node.back(),var)) return num;\n\t\tTypeNode ret\
    \ = Abel::unit_node;\n\t\tsize_t off = 0;\n\t\tfor(size_t idx = length; idx; idx\
    \ >>= 1){\n\t\t\tif(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Abel::func_fold(ret,node[off]);\n\t\t\t\
    }\n\t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \"\
    \ << fold(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << fold(i+1);\n\
    \t\tcout << \" }\" << endl;\n\t}\n};\n"
  code: "/*\n * @title BinaryIndexedTree - BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTree {\n\tusing TypeNode = typename\
    \ Abel::TypeNode;\n\tsize_t length;\n\tsize_t num;\n\tvector<TypeNode> node;\n\
    public:\n\t\n\t//[0,N) constructed, inplace [0,1) + [1,N+1)\n\t//you can ignore\
    \ inplace offset\n\tBinaryIndexedTree(const size_t num) : num(num) {\n\t\tfor\
    \ (length = 1; length < num; length *= 2);\n\t\tnode.resize(length+1, Abel::unit_node);\n\
    \t}\n \n\t//[idx,idx+1) operate \n\tvoid operate(size_t idx, TypeNode var) {\n\
    \t\tassert(0 <= idx && idx < length);\n\t\tfor (++idx; idx <= length; idx += idx\
    \ & -idx) node[idx] = Abel::func_fold(node[idx],var);\n\t}\n\n\t//[0,idx) fold\n\
    \tTypeNode fold(size_t idx) {\n\t\tTypeNode ret = Abel::unit_node;\n\t\tfor (idx\
    \ = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint binary_search(TypeNode var)\
    \ {\n\t\tif(!Abel::func_check(node.back(),var)) return num;\n\t\tTypeNode ret\
    \ = Abel::unit_node;\n\t\tsize_t off = 0;\n\t\tfor(size_t idx = length; idx; idx\
    \ >>= 1){\n\t\t\tif(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Abel::func_fold(ret,node[off]);\n\t\t\t\
    }\n\t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \"\
    \ << fold(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << fold(i+1);\n\
    \t\tcout << \" }\" << endl;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-04-26 08:34:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
documentation_of: lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
- /library/lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp.html
title: BinaryIndexedTree - BIT
---
