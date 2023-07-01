---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/queue/SwagQueue-composite.test.cpp
    title: test/queue/SwagQueue-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue/SwagQueue-gcd.test.cpp
    title: test/queue/SwagQueue-gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/SwagQueue.md
    document_title: SwagQueue
    links: []
  bundledCode: "#line 1 \"lib/15-queue/SwagQueue.cpp\"\n/*\n * @title SwagQueue\n\
    \ * @docs md/data-structure/SwagQueue.md\n */\ntemplate<class Operator> class\
    \ SwagQueue{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n   \
    \ stack<pair<TypeNode,TypeNode>> pre,suf;\n\n    SwagQueue() {\n        // do\
    \ nothing\n    }\n    TypeNode fold() {\n        TypeNode res = Operator::unit_node;\n\
    \        if(pre.size()) res = Operator::func_node(pre.top().second,res);\n   \
    \     if(suf.size()) res = Operator::func_node(res,suf.top().second);\n      \
    \  return res;\n    }\n    void push(TypeNode val) {\n        TypeNode acc = val;\n\
    \        if(suf.size()) acc = Operator::func_node(suf.top().second,val);\n   \
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
    \ {r.first*l.first,r.first*l.second+r.second};}\n};\n"
  code: "/*\n * @title SwagQueue\n * @docs md/data-structure/SwagQueue.md\n */\ntemplate<class\
    \ Operator> class SwagQueue{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    stack<pair<TypeNode,TypeNode>> pre,suf;\n\n    SwagQueue() {\n        //\
    \ do nothing\n    }\n    TypeNode fold() {\n        TypeNode res = Operator::unit_node;\n\
    \        if(pre.size()) res = Operator::func_node(pre.top().second,res);\n   \
    \     if(suf.size()) res = Operator::func_node(res,suf.top().second);\n      \
    \  return res;\n    }\n    void push(TypeNode val) {\n        TypeNode acc = val;\n\
    \        if(suf.size()) acc = Operator::func_node(suf.top().second,val);\n   \
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
  path: lib/15-queue/SwagQueue.cpp
  requiredBy: []
  timestamp: '2023-06-06 01:28:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue/SwagQueue-gcd.test.cpp
  - test/queue/SwagQueue-composite.test.cpp
documentation_of: lib/15-queue/SwagQueue.cpp
layout: document
redirect_from:
- /library/lib/15-queue/SwagQueue.cpp
- /library/lib/15-queue/SwagQueue.cpp.html
title: SwagQueue
---
