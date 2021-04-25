---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-1.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
    title: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
    title: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
  - icon: ':x:'
    path: test/data-structure/range-query/RangeInversionQuery.test.cpp
    title: test/data-structure/range-query/RangeInversionQuery.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/math/AbelPrefixSumPointAdd.md
    document_title: AbelPrefixSumPointAdd
    links: []
  bundledCode: "#line 1 \"lib/operator/AbelPrefixSumPointAdd.cpp\"\n/*\n * @title\
    \ AbelPrefixSumPointAdd\n * @docs md/math/AbelPrefixSumPointAdd.md\n */\ntemplate<class\
    \ T> struct AbelPrefixSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(const\
    \ TypeNode& l,const TypeNode& r){return l+r;}\n    inline static constexpr TypeNode\
    \ func_fold_inv(const TypeNode& l,const TypeNode& r){return l-r;}\n};\n"
  code: "/*\n * @title AbelPrefixSumPointAdd\n * @docs md/math/AbelPrefixSumPointAdd.md\n\
    \ */\ntemplate<class T> struct AbelPrefixSumPointAdd {\n    using TypeNode = T;\n\
    \    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n    inline\
    \ static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return\
    \ l-r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/AbelPrefixSumPointAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 08:34:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data-structure/range-query/RangeInversionQuery.test.cpp
  - test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-1.test.cpp
  - test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
  - test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
  - test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
documentation_of: lib/operator/AbelPrefixSumPointAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/AbelPrefixSumPointAdd.cpp
- /library/lib/operator/AbelPrefixSumPointAdd.cpp.html
title: AbelPrefixSumPointAdd
---
