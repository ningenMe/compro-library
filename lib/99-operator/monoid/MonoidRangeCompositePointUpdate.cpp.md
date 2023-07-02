---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-3.test.cpp
    title: test/graph/Tree-hld-vertex-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
    title: test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/SegmentTree-rcq.test.cpp
    title: test/segment-tree/SegmentTree-rcq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid/MonoidRangeCompositePointUpdate.md
    document_title: "MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\
      \u6570, \u70B9\u66F4\u65B0]"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n/*\n * @title MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\
    \u6570, \u70B9\u66F4\u65B0]\n * @docs md/operator/monoid/MonoidRangeCompositePointUpdate.md\n\
    \ */\ntemplate<class T> struct MonoidRangeCompositePointUpdate {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unit_node = make_pair(1,0);\n   \
    \ inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    \    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return\
    \ r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\
    \u95A2\u6570, \u70B9\u66F4\u65B0]\n * @docs md/operator/monoid/MonoidRangeCompositePointUpdate.md\n\
    \ */\ntemplate<class T> struct MonoidRangeCompositePointUpdate {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unit_node = make_pair(1,0);\n   \
    \ inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    \    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return\
    \ r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-hld-vertex-3.test.cpp
  - test/segment-tree/DynamicSegmentTree-rcq-1.test.cpp
  - test/segment-tree/SegmentTree-rcq.test.cpp
documentation_of: lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp
- /library/lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp.html
title: "MonoidRangeCompositePointUpdate - [\u533A\u9593\u4E00\u6B21\u95A2\u6570, \u70B9\
  \u66F4\u65B0]"
---
