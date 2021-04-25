---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
    title: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/DynamicBinaryIndexedTree.md
    document_title: "DynamicBinaryIndexedTree - \u52D5\u7684BIT"
    links: []
  bundledCode: "#line 1 \"lib/segment/DynamicBinaryIndexedTree.cpp\"\n/*\n * @title\
    \ DynamicBinaryIndexedTree - \u52D5\u7684BIT\n * @docs md/segment/DynamicBinaryIndexedTree.md\n\
    \ */\ntemplate<class Operator> class DynamicBinaryIndexedTree {\n    using TypeNode\
    \ = typename Operator::TypeNode;\n    using i64 = long long;\n    size_t depth;\
    \         \n    i64 length;\n    i64 num;\n\n    unordered_map<i64,TypeNode> node;\n\
    public:\n    \n    //[0,N) constructed, inplace [0,1) + [1,N+1)\n    //you can\
    \ ignore inplace offset\n    DynamicBinaryIndexedTree(const i64 num) : num(num)\
    \ {\n        for (depth = 1,length = 1; length < num; depth++,length *= 2);\n\
    \    }\n \n    //[idx,idx+1) update \n    void update(i64 idx, TypeNode var) {\n\
    \        assert(0 <= idx && idx < length);\n        for (++idx; idx <= length;\
    \ idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);\n    }\n\n\
    \    //[0,idx) get\n    TypeNode get(i64 idx) {\n        TypeNode ret = Operator::unit_node;\n\
    \        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \        return ret;\n    }\n\n    //[l,r) get\n    TypeNode get(i64 l, i64 r)\
    \ {\n        TypeNode val = get(r);\n        if(l>0) val = Operator::func_node_inv(val,get(l));\n\
    \        return val;\n    }\n\n    void print() {\n        cout << \"{ \" << get(1);\n\
    \        for(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n       \
    \ cout << \" }\" << endl;\n    }\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ 0;\n    inline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return l+r;}\n    inline static constexpr TypeNode func_node_inv(const TypeNode&\
    \ l,const TypeNode& r){return l-r;}\n};\n"
  code: "/*\n * @title DynamicBinaryIndexedTree - \u52D5\u7684BIT\n * @docs md/segment/DynamicBinaryIndexedTree.md\n\
    \ */\ntemplate<class Operator> class DynamicBinaryIndexedTree {\n    using TypeNode\
    \ = typename Operator::TypeNode;\n    using i64 = long long;\n    size_t depth;\
    \         \n    i64 length;\n    i64 num;\n\n    unordered_map<i64,TypeNode> node;\n\
    public:\n    \n    //[0,N) constructed, inplace [0,1) + [1,N+1)\n    //you can\
    \ ignore inplace offset\n    DynamicBinaryIndexedTree(const i64 num) : num(num)\
    \ {\n        for (depth = 1,length = 1; length < num; depth++,length *= 2);\n\
    \    }\n \n    //[idx,idx+1) update \n    void update(i64 idx, TypeNode var) {\n\
    \        assert(0 <= idx && idx < length);\n        for (++idx; idx <= length;\
    \ idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);\n    }\n\n\
    \    //[0,idx) get\n    TypeNode get(i64 idx) {\n        TypeNode ret = Operator::unit_node;\n\
    \        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \        return ret;\n    }\n\n    //[l,r) get\n    TypeNode get(i64 l, i64 r)\
    \ {\n        TypeNode val = get(r);\n        if(l>0) val = Operator::func_node_inv(val,get(l));\n\
    \        return val;\n    }\n\n    void print() {\n        cout << \"{ \" << get(1);\n\
    \        for(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n       \
    \ cout << \" }\" << endl;\n    }\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ 0;\n    inline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return l+r;}\n    inline static constexpr TypeNode func_node_inv(const TypeNode&\
    \ l,const TypeNode& r){return l-r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/DynamicBinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2021-04-25 16:58:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
documentation_of: lib/segment/DynamicBinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/lib/segment/DynamicBinaryIndexedTree.cpp
- /library/lib/segment/DynamicBinaryIndexedTree.cpp.html
title: "DynamicBinaryIndexedTree - \u52D5\u7684BIT"
---
