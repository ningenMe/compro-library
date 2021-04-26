---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n\n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct MonoidRangeCompositePointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ make_pair(1,0);\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return {r.first*l.first,r.first*l.second+r.second};}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}\n};\n"
  code: "\n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct MonoidRangeCompositePointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ make_pair(1,0);\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return {r.first*l.first,r.first*l.second+r.second};}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:03:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/SegmentTree-rcq.test.cpp
documentation_of: lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp
- /library/lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp.html
title: lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp
---
