---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
    title: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/DynamicBinaryIndexedTree.md
    document_title: "DynamicBinaryIndexedTree - \u52D5\u7684BIT"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp\"\
    \n/*\n * @title DynamicBinaryIndexedTree - \u52D5\u7684BIT\n * @docs md/segment/DynamicBinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class DynamicBinaryIndexedTree {\n    using TypeNode\
    \ = typename Abel::TypeNode;\n    using i64 = long long;\n    i64 length;\n\n\
    \    unordered_map<i64,TypeNode> node;\npublic:\n\n    //[0,N) constructed, inplace\
    \ [0,1) + [1,N+1)\n    //you can ignore inplace offset\n    DynamicBinaryIndexedTree(const\
    \ i64 num) {\n        for (length = 1; length < num; length *= 2);\n    }\n\n\
    \    //[idx,idx+1) operate\n    void operate(i64 idx, TypeNode var) {\n      \
    \  assert(0 <= idx && idx < length);\n        for (++idx; idx <= length; idx +=\
    \ idx & -idx) node[idx] = Abel::func_fold(node[idx],var);\n    }\n\n    //[0,idx)\
    \ fold\n    TypeNode fold(i64 idx) {\n        TypeNode ret = Abel::unit_node;\n\
    \        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \        return ret;\n    }\n\n    //[l,r) fold\n    TypeNode fold(i64 l, i64\
    \ r) {\n        return Abel::func_fold_inv(fold(r),fold(l));\n    }\n\n    void\
    \ print() {\n        cout << \"{ \" << fold(1);\n        for(int i = 1; i < length;\
    \ ++i) cout << \", \" << fold(i+1);\n        cout << \" }\" << endl;\n    }\n\
    };\n"
  code: "/*\n * @title DynamicBinaryIndexedTree - \u52D5\u7684BIT\n * @docs md/segment/DynamicBinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class DynamicBinaryIndexedTree {\n    using TypeNode\
    \ = typename Abel::TypeNode;\n    using i64 = long long;\n    i64 length;\n\n\
    \    unordered_map<i64,TypeNode> node;\npublic:\n\n    //[0,N) constructed, inplace\
    \ [0,1) + [1,N+1)\n    //you can ignore inplace offset\n    DynamicBinaryIndexedTree(const\
    \ i64 num) {\n        for (length = 1; length < num; length *= 2);\n    }\n\n\
    \    //[idx,idx+1) operate\n    void operate(i64 idx, TypeNode var) {\n      \
    \  assert(0 <= idx && idx < length);\n        for (++idx; idx <= length; idx +=\
    \ idx & -idx) node[idx] = Abel::func_fold(node[idx],var);\n    }\n\n    //[0,idx)\
    \ fold\n    TypeNode fold(i64 idx) {\n        TypeNode ret = Abel::unit_node;\n\
    \        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \        return ret;\n    }\n\n    //[l,r) fold\n    TypeNode fold(i64 l, i64\
    \ r) {\n        return Abel::func_fold_inv(fold(r),fold(l));\n    }\n\n    void\
    \ print() {\n        cout << \"{ \" << fold(1);\n        for(int i = 1; i < length;\
    \ ++i) cout << \", \" << fold(i+1);\n        cout << \" }\" << endl;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-09-21 03:30:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
documentation_of: lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp
- /library/lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp.html
title: "DynamicBinaryIndexedTree - \u52D5\u7684BIT"
---
