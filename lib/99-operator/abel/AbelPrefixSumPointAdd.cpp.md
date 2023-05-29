---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/abel/AbelPrefixSumPointAdd.md
    document_title: AbelPrefixSumPointAdd
    links: []
  bundledCode: "#line 1 \"lib/99-operator/abel/AbelPrefixSumPointAdd.cpp\"\n/*\n *\
    \ @title AbelPrefixSumPointAdd\n * @docs md/operator/abel/AbelPrefixSumPointAdd.md\n\
    \ */\ntemplate<class T> struct AbelPrefixSumPointAdd {\n    using TypeNode = T;\n\
    \    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n    inline\
    \ static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return\
    \ l-r;}\n};\n"
  code: "/*\n * @title AbelPrefixSumPointAdd\n * @docs md/operator/abel/AbelPrefixSumPointAdd.md\n\
    \ */\ntemplate<class T> struct AbelPrefixSumPointAdd {\n    using TypeNode = T;\n\
    \    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n    inline\
    \ static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return\
    \ l-r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/abel/AbelPrefixSumPointAdd.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/99-operator/abel/AbelPrefixSumPointAdd.cpp
layout: document
redirect_from:
- /library/lib/99-operator/abel/AbelPrefixSumPointAdd.cpp
- /library/lib/99-operator/abel/AbelPrefixSumPointAdd.cpp.html
title: AbelPrefixSumPointAdd
---
