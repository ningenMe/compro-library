---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/Swag.test.cpp
    title: test/data-structure/Swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/Swag.md
    document_title: Swag
    links: []
  bundledCode: "#line 1 \"lib/14-data-structure/Swag.cpp\"\n/*\n * @title Swag\n *\
    \ @docs md/data-structure/Swag.md\n */\ntemplate<class Operator> class Swag{\n\
    public:\n    using TypeNode = typename Operator::TypeNode;\n    stack<pair<TypeNode,TypeNode>>\
    \ pre,suf;\n\n    Swag() {\n        // do nothing\n    }\n    TypeNode fold()\
    \ {\n        TypeNode res = Operator::unit_node;\n        if(pre.size()) res =\
    \ Operator::func_node(pre.top().second,res);\n        if(suf.size()) res = Operator::func_node(res,suf.top().second);\n\
    \        return res;\n    }\n    void push(TypeNode val) {\n        TypeNode acc\
    \ = val;\n        if(suf.size()) acc = Operator::func_node(suf.top().second,acc);\n\
    \        suf.emplace(val,acc);\n    }\n    void pop() {\n        if(pre.empty())\
    \ {\n            TypeNode acc = Operator::unit_node;\n            while(suf.size())\
    \ {\n                auto [val,_] = suf.top();\n                suf.pop();\n \
    \               acc = Operator::func_node(val,acc);\n                pre.emplace(val,acc);\n\
    \            }\n        }\n        if(pre.size()) pre.pop();\n    }\n    size_t\
    \ size(){\n        return pre.size()+suf.size();\n    }\n};\n\ntemplate<class\
    \ T> struct NodeGcd {\n    using TypeNode = T;\n    inline static constexpr TypeNode\
    \ unit_node = 0;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return r?func_node(r,l%r):l;}\n};\n\ntemplate<class T> struct NodeComposite\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ {1,0};\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ {r.first*l.first,r.first*l.second+r.second};}\n};\n"
  code: "/*\n * @title Swag\n * @docs md/data-structure/Swag.md\n */\ntemplate<class\
    \ Operator> class Swag{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    stack<pair<TypeNode,TypeNode>> pre,suf;\n\n    Swag() {\n        // do nothing\n\
    \    }\n    TypeNode fold() {\n        TypeNode res = Operator::unit_node;\n \
    \       if(pre.size()) res = Operator::func_node(pre.top().second,res);\n    \
    \    if(suf.size()) res = Operator::func_node(res,suf.top().second);\n       \
    \ return res;\n    }\n    void push(TypeNode val) {\n        TypeNode acc = val;\n\
    \        if(suf.size()) acc = Operator::func_node(suf.top().second,acc);\n   \
    \     suf.emplace(val,acc);\n    }\n    void pop() {\n        if(pre.empty())\
    \ {\n            TypeNode acc = Operator::unit_node;\n            while(suf.size())\
    \ {\n                auto [val,_] = suf.top();\n                suf.pop();\n \
    \               acc = Operator::func_node(val,acc);\n                pre.emplace(val,acc);\n\
    \            }\n        }\n        if(pre.size()) pre.pop();\n    }\n    size_t\
    \ size(){\n        return pre.size()+suf.size();\n    }\n};\n\ntemplate<class\
    \ T> struct NodeGcd {\n    using TypeNode = T;\n    inline static constexpr TypeNode\
    \ unit_node = 0;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return r?func_node(r,l%r):l;}\n};\n\ntemplate<class T> struct NodeComposite\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ {1,0};\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ {r.first*l.first,r.first*l.second+r.second};}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/14-data-structure/Swag.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/Swag.test.cpp
documentation_of: lib/14-data-structure/Swag.cpp
layout: document
redirect_from:
- /library/lib/14-data-structure/Swag.cpp
- /library/lib/14-data-structure/Swag.cpp.html
title: Swag
---