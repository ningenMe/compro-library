---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-path.test.cpp
    title: test/graph/Tree-hld-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeMulPointUpdate.cpp\"\n//\u4E00\
    \u70B9\u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct MonoidRangeMulPointUpdate\
    \ {\n    using TypeNode = T;\n    inline static TypeNode unit_node = TypeNode::E();\n\
    \    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return\
    \ l*r;}\n    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode\
    \ r){return r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode\
    \ var){return var > nodeVal;}\n};\n"
  code: "//\u4E00\u70B9\u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct\
    \ MonoidRangeMulPointUpdate {\n    using TypeNode = T;\n    inline static TypeNode\
    \ unit_node = TypeNode::E();\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l*r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeMulPointUpdate.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:56:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-hld-path.test.cpp
documentation_of: lib/operator/monoid/MonoidRangeMulPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeMulPointUpdate.cpp
- /library/lib/operator/monoid/MonoidRangeMulPointUpdate.cpp.html
title: lib/operator/monoid/MonoidRangeMulPointUpdate.cpp
---
