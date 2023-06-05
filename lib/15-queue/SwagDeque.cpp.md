---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/queue/SwagDeque-deque-composite.test.cpp
    title: test/queue/SwagDeque-deque-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue/SwagDeque-queue-composite.test.cpp
    title: test/queue/SwagDeque-queue-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/Swag.md
    document_title: SwagDeque
    links: []
  bundledCode: "#line 1 \"lib/15-queue/SwagDeque.cpp\"\n/*\n * @title SwagDeque\n\
    \ * @docs md/data-structure/Swag.md\n */\ntemplate<class Operator> class SwagDeque{\n\
    public:\n    using TypeNode = typename Operator::TypeNode;\n    stack<pair<TypeNode,TypeNode>>\
    \ pre,suf;\n    stack<TypeNode> tmp;\n\n    SwagDeque() {\n        // do nothing\n\
    \    }\n    TypeNode fold() {\n        TypeNode res = Operator::unit_node;\n \
    \       if(pre.size()) res = Operator::func_node(pre.top().second,res);\n    \
    \    if(suf.size()) res = Operator::func_node(res,suf.top().second);\n       \
    \ return res;\n    }\n    void push_back(const TypeNode val) {\n        TypeNode\
    \ acc = val;\n        if(suf.size()) acc = Operator::func_node(suf.top().second,val);\n\
    \        suf.emplace(val,acc);\n    }\n    void push_front(const TypeNode val)\
    \ {\n        TypeNode acc = val;\n        if(pre.size()) acc = Operator::func_node(val,pre.top().second);\n\
    \        pre.emplace(val,acc);\n    }\n    void pop_back() {\n        if(suf.empty())\
    \ {\n            while(pre.size()>tmp.size()+1) {\n                tmp.push(pre.top().first);\
    \ pre.pop();\n            }\n            {\n                TypeNode acc = Operator::unit_node;\n\
    \                while(pre.size()) {\n                    auto [val,_] = pre.top();\
    \ pre.pop();\n                    acc = Operator::func_node(acc,val);\n      \
    \              suf.emplace(val,acc);\n                }\n            }\n     \
    \       {\n                TypeNode acc = Operator::unit_node;\n             \
    \   while(tmp.size()) {\n                    TypeNode val = tmp.top(); tmp.pop();\n\
    \                    acc = Operator::func_node(val,acc);\n                   \
    \ pre.emplace(val,acc);\n                }\n            }\n        }\n       \
    \ suf.pop();\n    }\n    void pop_front() {\n        if(pre.empty()) {\n     \
    \       while(suf.size()>tmp.size()+1) {\n                tmp.push(suf.top().first);\
    \ suf.pop();\n            }\n            {\n                TypeNode acc = Operator::unit_node;\n\
    \                while(suf.size()) {\n                    auto [val,_] = suf.top();\
    \ suf.pop();\n                    acc = Operator::func_node(val,acc);\n      \
    \              pre.emplace(val,acc);\n                }\n            }\n     \
    \       {\n                TypeNode acc = Operator::unit_node;\n             \
    \   while(tmp.size()) {\n                    TypeNode val = tmp.top(); tmp.pop();\n\
    \                    acc = Operator::func_node(acc,val);\n                   \
    \ suf.emplace(val,acc);\n                }\n            }\n        }\n       \
    \ pre.pop();\n    }\n    size_t size() const {\n        return pre.size()+suf.size();\n\
    \    }\n    bool empty() const {\n        return pre.empty() && suf.empty();\n\
    \    }\n    void print() {\n        stack<pair<TypeNode,TypeNode>> ls,rs;\n  \
    \      vector<pair<TypeNode,TypeNode>> lv,rv;\n        while(pre.size()) {\n \
    \           auto p=pre.top(); pre.pop();\n            lv.push_back(p);\n     \
    \       ls.push(p);\n        }\n        while(suf.size()) {\n            rs.emplace(suf.top());\
    \ suf.pop();\n        }\n        while(ls.size()) {\n            pre.push(ls.top());\
    \ ls.pop();\n        }\n        while(rs.size()) {\n            auto p=rs.top();\
    \ rs.pop();\n            rv.push_back(p);\n            suf.push(p);\n        }\n\
    \        cout << \"{\";\n        for(int i=0;i<lv.size();++i) {\n            cout\
    \ << \"{\" << lv[i].first << \":\" << lv[i].second << \"} \";\n        }\n   \
    \     cout << \"} , {\";\n        for(int i=0;i<rv.size();++i) {\n           \
    \ cout << \"{\" << rv[i].first << \":\" << rv[i].second << \"} \";\n        }\n\
    \        cout << \"}\" << endl;\n    }\n};\n\ntemplate<class T> struct NodeGcd\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ 0;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ r?func_node(r,l%r):l;}\n};\n\ntemplate<class T> struct NodeComposite {\n   \
    \ using TypeNode = T;\n    inline static constexpr TypeNode unit_node = {1,0};\n\
    \    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ {l.first*r.first, r.first*l.second+r.second};}\n};\n"
  code: "/*\n * @title SwagDeque\n * @docs md/data-structure/Swag.md\n */\ntemplate<class\
    \ Operator> class SwagDeque{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    stack<pair<TypeNode,TypeNode>> pre,suf;\n    stack<TypeNode> tmp;\n\n   \
    \ SwagDeque() {\n        // do nothing\n    }\n    TypeNode fold() {\n       \
    \ TypeNode res = Operator::unit_node;\n        if(pre.size()) res = Operator::func_node(pre.top().second,res);\n\
    \        if(suf.size()) res = Operator::func_node(res,suf.top().second);\n   \
    \     return res;\n    }\n    void push_back(const TypeNode val) {\n        TypeNode\
    \ acc = val;\n        if(suf.size()) acc = Operator::func_node(suf.top().second,val);\n\
    \        suf.emplace(val,acc);\n    }\n    void push_front(const TypeNode val)\
    \ {\n        TypeNode acc = val;\n        if(pre.size()) acc = Operator::func_node(val,pre.top().second);\n\
    \        pre.emplace(val,acc);\n    }\n    void pop_back() {\n        if(suf.empty())\
    \ {\n            while(pre.size()>tmp.size()+1) {\n                tmp.push(pre.top().first);\
    \ pre.pop();\n            }\n            {\n                TypeNode acc = Operator::unit_node;\n\
    \                while(pre.size()) {\n                    auto [val,_] = pre.top();\
    \ pre.pop();\n                    acc = Operator::func_node(acc,val);\n      \
    \              suf.emplace(val,acc);\n                }\n            }\n     \
    \       {\n                TypeNode acc = Operator::unit_node;\n             \
    \   while(tmp.size()) {\n                    TypeNode val = tmp.top(); tmp.pop();\n\
    \                    acc = Operator::func_node(val,acc);\n                   \
    \ pre.emplace(val,acc);\n                }\n            }\n        }\n       \
    \ suf.pop();\n    }\n    void pop_front() {\n        if(pre.empty()) {\n     \
    \       while(suf.size()>tmp.size()+1) {\n                tmp.push(suf.top().first);\
    \ suf.pop();\n            }\n            {\n                TypeNode acc = Operator::unit_node;\n\
    \                while(suf.size()) {\n                    auto [val,_] = suf.top();\
    \ suf.pop();\n                    acc = Operator::func_node(val,acc);\n      \
    \              pre.emplace(val,acc);\n                }\n            }\n     \
    \       {\n                TypeNode acc = Operator::unit_node;\n             \
    \   while(tmp.size()) {\n                    TypeNode val = tmp.top(); tmp.pop();\n\
    \                    acc = Operator::func_node(acc,val);\n                   \
    \ suf.emplace(val,acc);\n                }\n            }\n        }\n       \
    \ pre.pop();\n    }\n    size_t size() const {\n        return pre.size()+suf.size();\n\
    \    }\n    bool empty() const {\n        return pre.empty() && suf.empty();\n\
    \    }\n    void print() {\n        stack<pair<TypeNode,TypeNode>> ls,rs;\n  \
    \      vector<pair<TypeNode,TypeNode>> lv,rv;\n        while(pre.size()) {\n \
    \           auto p=pre.top(); pre.pop();\n            lv.push_back(p);\n     \
    \       ls.push(p);\n        }\n        while(suf.size()) {\n            rs.emplace(suf.top());\
    \ suf.pop();\n        }\n        while(ls.size()) {\n            pre.push(ls.top());\
    \ ls.pop();\n        }\n        while(rs.size()) {\n            auto p=rs.top();\
    \ rs.pop();\n            rv.push_back(p);\n            suf.push(p);\n        }\n\
    \        cout << \"{\";\n        for(int i=0;i<lv.size();++i) {\n            cout\
    \ << \"{\" << lv[i].first << \":\" << lv[i].second << \"} \";\n        }\n   \
    \     cout << \"} , {\";\n        for(int i=0;i<rv.size();++i) {\n           \
    \ cout << \"{\" << rv[i].first << \":\" << rv[i].second << \"} \";\n        }\n\
    \        cout << \"}\" << endl;\n    }\n};\n\ntemplate<class T> struct NodeGcd\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ 0;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ r?func_node(r,l%r):l;}\n};\n\ntemplate<class T> struct NodeComposite {\n   \
    \ using TypeNode = T;\n    inline static constexpr TypeNode unit_node = {1,0};\n\
    \    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ {l.first*r.first, r.first*l.second+r.second};}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/15-queue/SwagDeque.cpp
  requiredBy: []
  timestamp: '2023-06-06 01:09:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue/SwagDeque-deque-composite.test.cpp
  - test/queue/SwagDeque-queue-composite.test.cpp
documentation_of: lib/15-queue/SwagDeque.cpp
layout: document
redirect_from:
- /library/lib/15-queue/SwagDeque.cpp
- /library/lib/15-queue/SwagDeque.cpp.html
title: SwagDeque
---
