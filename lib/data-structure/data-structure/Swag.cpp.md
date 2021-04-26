---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/data-structure/Swag.test.cpp
    title: test/data-structure/data-structure/Swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/Swag.md
    document_title: Swag
    links: []
  bundledCode: "#line 1 \"lib/data-structure/data-structure/Swag.cpp\"\n/*\n * @title\
    \ Swag\n * @docs md/segment/Swag.md\n */\ntemplate<class Operator> class Swag{\n\
    public:\n\tusing TypeNode = typename Operator::TypeNode;\n\tstack<pair<TypeNode,TypeNode>>\
    \ pre,suf;\n\n\tSwag() {\n\t\t// do nothing\n\t}\n\tTypeNode fold() {\n\t\tTypeNode\
    \ res = Operator::unit_node;\n\t\tif(pre.size()) res = Operator::func_node(pre.top().second,res);\n\
    \t\tif(suf.size()) res = Operator::func_node(res,suf.top().second);\n\t\treturn\
    \ res;\n\t}\n\tvoid push(TypeNode val) {\n\t\tTypeNode acc = val;\n\t\tif(suf.size())\
    \ acc = Operator::func_node(suf.top().second,acc);\n\t\tsuf.emplace(val,acc);\n\
    \t}\n\tvoid pop() {\n\t\tif(pre.empty()) {\n\t\t\tTypeNode acc = Operator::unit_node;\n\
    \t\t\twhile(suf.size()) {\n\t\t\t\tauto [val,_] = suf.top();\n\t\t\t\tsuf.pop();\n\
    \t\t\t\tacc = Operator::func_node(val,acc);\n\t\t\t\tpre.emplace(val,acc);\n\t\
    \t\t}\n\t\t}\n\t\tif(pre.size()) pre.pop();\t\t\t\n\t}\n\tsize_t size(){\n\t\t\
    return pre.size()+suf.size();\n\t}\n};\n\ntemplate<class T> struct NodeGcd {\n\
    \tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return r?func_node(r,l%r):l;}\n\
    };\n\ntemplate<class T> struct NodeComposite {\n\tusing TypeNode = T;\n\tinline\
    \ static constexpr TypeNode unit_node = {1,0};\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    };\n"
  code: "/*\n * @title Swag\n * @docs md/segment/Swag.md\n */\ntemplate<class Operator>\
    \ class Swag{\npublic:\n\tusing TypeNode = typename Operator::TypeNode;\n\tstack<pair<TypeNode,TypeNode>>\
    \ pre,suf;\n\n\tSwag() {\n\t\t// do nothing\n\t}\n\tTypeNode fold() {\n\t\tTypeNode\
    \ res = Operator::unit_node;\n\t\tif(pre.size()) res = Operator::func_node(pre.top().second,res);\n\
    \t\tif(suf.size()) res = Operator::func_node(res,suf.top().second);\n\t\treturn\
    \ res;\n\t}\n\tvoid push(TypeNode val) {\n\t\tTypeNode acc = val;\n\t\tif(suf.size())\
    \ acc = Operator::func_node(suf.top().second,acc);\n\t\tsuf.emplace(val,acc);\n\
    \t}\n\tvoid pop() {\n\t\tif(pre.empty()) {\n\t\t\tTypeNode acc = Operator::unit_node;\n\
    \t\t\twhile(suf.size()) {\n\t\t\t\tauto [val,_] = suf.top();\n\t\t\t\tsuf.pop();\n\
    \t\t\t\tacc = Operator::func_node(val,acc);\n\t\t\t\tpre.emplace(val,acc);\n\t\
    \t\t}\n\t\t}\n\t\tif(pre.size()) pre.pop();\t\t\t\n\t}\n\tsize_t size(){\n\t\t\
    return pre.size()+suf.size();\n\t}\n};\n\ntemplate<class T> struct NodeGcd {\n\
    \tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return r?func_node(r,l%r):l;}\n\
    };\n\ntemplate<class T> struct NodeComposite {\n\tusing TypeNode = T;\n\tinline\
    \ static constexpr TypeNode unit_node = {1,0};\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/data-structure/Swag.cpp
  requiredBy: []
  timestamp: '2021-04-26 18:11:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/data-structure/Swag.test.cpp
documentation_of: lib/data-structure/data-structure/Swag.cpp
layout: document
redirect_from:
- /library/lib/data-structure/data-structure/Swag.cpp
- /library/lib/data-structure/data-structure/Swag.cpp.html
title: Swag
---
