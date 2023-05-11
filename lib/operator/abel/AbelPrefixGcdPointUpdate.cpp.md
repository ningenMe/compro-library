---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/abel/AbelPrefixGcdPointUpdate.md
    document_title: AbelPrefixGcdPointUpdate
    links: []
  bundledCode: "#line 1 \"lib/operator/abel/AbelPrefixGcdPointUpdate.cpp\"\n/*\n *\
    \ @title AbelPrefixGcdPointUpdate\n * @docs md/operator/abel/AbelPrefixGcdPointUpdate.md\n\
    \ */\ntemplate<class TypeNode> struct AbelPrefixGcdPointUpdate {\n\tTypeNode unit_node\
    \ = 0;\n\tTypeNode func_node(const TypeNode& l,const TypeNode& r){return ((r ==\
    \ 0) ? l : func_node(r, l % r));}\n\t// Binary Search for first index at where\
    \ func_check is true\n\tbool func_check(const TypeNode nodeVal,const TypeNode&\
    \ var){return var == nodeVal;}\n};\n"
  code: "/*\n * @title AbelPrefixGcdPointUpdate\n * @docs md/operator/abel/AbelPrefixGcdPointUpdate.md\n\
    \ */\ntemplate<class TypeNode> struct AbelPrefixGcdPointUpdate {\n\tTypeNode unit_node\
    \ = 0;\n\tTypeNode func_node(const TypeNode& l,const TypeNode& r){return ((r ==\
    \ 0) ? l : func_node(r, l % r));}\n\t// Binary Search for first index at where\
    \ func_check is true\n\tbool func_check(const TypeNode nodeVal,const TypeNode&\
    \ var){return var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/abel/AbelPrefixGcdPointUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/abel/AbelPrefixGcdPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/abel/AbelPrefixGcdPointUpdate.cpp
- /library/lib/operator/abel/AbelPrefixGcdPointUpdate.cpp.html
title: AbelPrefixGcdPointUpdate
---
