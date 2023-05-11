---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range-query/RangeInversionQuery.test.cpp
    title: test/data-structure/range-query/RangeInversionQuery.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/abel/AbelPrefixSumPointAdd.md
    document_title: AbelPrefixSumPointAdd
    links: []
  bundledCode: "#line 1 \"lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n/*\n * @title\
    \ AbelPrefixSumPointAdd\n * @docs md/operator/abel/AbelPrefixSumPointAdd.md\n\
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
  path: lib/operator/abel/AbelPrefixSumPointAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 09:09:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range-query/RangeInversionQuery.test.cpp
documentation_of: lib/operator/abel/AbelPrefixSumPointAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/abel/AbelPrefixSumPointAdd.cpp
- /library/lib/operator/abel/AbelPrefixSumPointAdd.cpp.html
title: AbelPrefixSumPointAdd
---
