---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range-query/RangeInversionQuery.test.cpp
    title: test/data-structure/range-query/RangeInversionQuery.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/binary-indexed-tree/BinaryIndexedTree.md
    document_title: BinaryIndexedTree - BIT
    links: []
  bundledCode: "#line 1 \"lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n/*\n * @title BinaryIndexedTree - BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTree {\n    using TypeNode = typename\
    \ Abel::TypeNode;\n    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n\
    public:\n\n    //[0,N) constructed, inplace [0,1) + [1,N+1)\n    //you can ignore\
    \ inplace offset\n    BinaryIndexedTree(const size_t num) : num(num) {\n     \
    \   for (length = 1; length < num; length *= 2);\n        node.resize(length+1,\
    \ Abel::unit_node);\n    }\n\n    //[idx,idx+1) operate\n    void operate(size_t\
    \ idx, TypeNode var) {\n        assert(0 <= idx && idx < length);\n        for\
    \ (++idx; idx <= length; idx += idx & -idx) node[idx] = Abel::func_fold(node[idx],var);\n\
    \    }\n\n    //[0,idx) fold\n    TypeNode fold(size_t idx) {\n        TypeNode\
    \ ret = Abel::unit_node;\n        for (idx = min(length,idx); idx > 0; idx -=\
    \ idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n        return ret;\n   \
    \ }\n\n    //return [0,length]\n    int binary_search(TypeNode var) {\n      \
    \  if(!Abel::func_check(node.back(),var)) return num;\n        TypeNode ret =\
    \ Abel::unit_node;\n        size_t off = 0;\n        for(size_t idx = length;\
    \ idx; idx >>= 1){\n            if(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var))\
    \ {\n                off += idx;\n                ret = Abel::func_fold(ret,node[off]);\n\
    \            }\n        }\n        return min(off,num);\n    }\n\n    void print()\
    \ {\n        cout << \"{ \" << fold(1);\n        for(int i = 1; i < length; ++i)\
    \ cout << \", \" << fold(i+1);\n        cout << \" }\" << endl;\n    }\n};\n"
  code: "/*\n * @title BinaryIndexedTree - BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTree {\n    using TypeNode = typename\
    \ Abel::TypeNode;\n    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n\
    public:\n\n    //[0,N) constructed, inplace [0,1) + [1,N+1)\n    //you can ignore\
    \ inplace offset\n    BinaryIndexedTree(const size_t num) : num(num) {\n     \
    \   for (length = 1; length < num; length *= 2);\n        node.resize(length+1,\
    \ Abel::unit_node);\n    }\n\n    //[idx,idx+1) operate\n    void operate(size_t\
    \ idx, TypeNode var) {\n        assert(0 <= idx && idx < length);\n        for\
    \ (++idx; idx <= length; idx += idx & -idx) node[idx] = Abel::func_fold(node[idx],var);\n\
    \    }\n\n    //[0,idx) fold\n    TypeNode fold(size_t idx) {\n        TypeNode\
    \ ret = Abel::unit_node;\n        for (idx = min(length,idx); idx > 0; idx -=\
    \ idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n        return ret;\n   \
    \ }\n\n    //return [0,length]\n    int binary_search(TypeNode var) {\n      \
    \  if(!Abel::func_check(node.back(),var)) return num;\n        TypeNode ret =\
    \ Abel::unit_node;\n        size_t off = 0;\n        for(size_t idx = length;\
    \ idx; idx >>= 1){\n            if(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var))\
    \ {\n                off += idx;\n                ret = Abel::func_fold(ret,node[off]);\n\
    \            }\n        }\n        return min(off,num);\n    }\n\n    void print()\
    \ {\n        cout << \"{ \" << fold(1);\n        for(int i = 1; i < length; ++i)\
    \ cout << \", \" << fold(i+1);\n        cout << \" }\" << endl;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-09-21 03:30:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range-query/RangeInversionQuery.test.cpp
  - test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
documentation_of: lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
- /library/lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp.html
title: BinaryIndexedTree - BIT
---