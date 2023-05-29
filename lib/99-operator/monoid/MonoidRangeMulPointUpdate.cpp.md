---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid/MonoidRangeMulPointUpdate.md
    document_title: "MonoidRangeMulPointUpdate - [\u533A\u9593\u7A4D, \u4E00\u70B9\
      \u66F4\u65B0]"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid/MonoidRangeMulPointUpdate.cpp\"\n\
    /*\n * @title MonoidRangeMulPointUpdate - [\u533A\u9593\u7A4D, \u4E00\u70B9\u66F4\
    \u65B0]\n * @docs md/operator/monoid/MonoidRangeMulPointUpdate.md\n */\ntemplate<class\
    \ T> struct MonoidRangeMulPointUpdate {\n    using TypeNode = T;\n    inline static\
    \ TypeNode unit_node = TypeNode::E();\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l*r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeMulPointUpdate - [\u533A\u9593\u7A4D, \u4E00\u70B9\
    \u66F4\u65B0]\n * @docs md/operator/monoid/MonoidRangeMulPointUpdate.md\n */\n\
    template<class T> struct MonoidRangeMulPointUpdate {\n    using TypeNode = T;\n\
    \    inline static TypeNode unit_node = TypeNode::E();\n    inline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l*r;}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid/MonoidRangeMulPointUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/99-operator/monoid/MonoidRangeMulPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid/MonoidRangeMulPointUpdate.cpp
- /library/lib/99-operator/monoid/MonoidRangeMulPointUpdate.cpp.html
title: "MonoidRangeMulPointUpdate - [\u533A\u9593\u7A4D, \u4E00\u70B9\u66F4\u65B0]"
---
