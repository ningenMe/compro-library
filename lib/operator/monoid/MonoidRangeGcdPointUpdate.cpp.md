---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-prefix-binary-search.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-suffix-binary-search.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp\"\ntemplate<class\
    \ T> struct MonoidRangeGcdPointUpdate {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return Gcd::gcd(l,r);}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n"
  code: "template<class T> struct MonoidRangeGcdPointUpdate {\n\tusing TypeNode =\
    \ T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}\n\tinline static\
    \ constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n\tinline\
    \ static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var ==\
    \ nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:03:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  - test/data-structure/segment-tree/SegmentTree-prefix-binary-search.test.cpp
documentation_of: lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
- /library/lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp.html
title: lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
---
