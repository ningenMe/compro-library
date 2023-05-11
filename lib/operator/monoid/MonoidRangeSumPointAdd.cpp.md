---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
    title: test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
    title: test/data-structure/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-rsq.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-rsq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-2.test.cpp
    title: test/graph/Tree-hld-vertex-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid/MonoidRangeSumPointAdd.md
    document_title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\
      \u7B97]"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n/*\n *\
    \ @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
    ]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\
    \u7B97]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
  requiredBy: []
  timestamp: '2021-05-01 14:31:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
  - test/data-structure/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
  - test/data-structure/segment-tree/SegmentTree-rsq.test.cpp
  - test/graph/Tree-hld-vertex-2.test.cpp
documentation_of: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeSumPointAdd.cpp
- /library/lib/operator/monoid/MonoidRangeSumPointAdd.cpp.html
title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97]"
---
