---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/AbelNodePrefixSumPointAdd.md
    document_title: AbelNodePrefixSumPointAdd
    links: []
  bundledCode: "#line 1 \"lib/operator/AbelNodePrefixSumPointAdd.cpp\"\n/*\n * @title\
    \ AbelNodePrefixSumPointAdd\n * @docs md/math/AbelNodePrefixSumPointAdd.md\n */\n\
    template<class T> struct AbelNodePrefixSumPointAdd {\n    using TypeNode = T;\n\
    \    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n    inline\
    \ static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return\
    \ l-r;}\n};\n"
  code: "/*\n * @title AbelNodePrefixSumPointAdd\n * @docs md/math/AbelNodePrefixSumPointAdd.md\n\
    \ */\ntemplate<class T> struct AbelNodePrefixSumPointAdd {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline static\
    \ constexpr TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n\
    \    inline static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode&\
    \ r){return l-r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/AbelNodePrefixSumPointAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 07:42:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/AbelNodePrefixSumPointAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/AbelNodePrefixSumPointAdd.cpp
- /library/lib/operator/AbelNodePrefixSumPointAdd.cpp.html
title: AbelNodePrefixSumPointAdd
---
