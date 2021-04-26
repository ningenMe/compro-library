---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeMinPointUpdate.cpp\"\n//\u4E00\
    \u70B9\u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct MonoidRangeMinPointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ (1LL<<31)-1;\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n};\n"
  code: "//\u4E00\u70B9\u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct\
    \ MonoidRangeMinPointUpdate {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = (1LL<<31)-1;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return min(l,r);}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:03:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
documentation_of: lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
- /library/lib/operator/monoid/MonoidRangeMinPointUpdate.cpp.html
title: lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
---
