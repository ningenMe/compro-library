---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-rsq.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-rsq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n//\u4E00\
    \u70B9\u52A0\u7B97 \u533A\u9593\u7DCF\u548C\ntemplate<class T> struct MonoidRangeSumPointAdd\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ 0;\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return\
    \ l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode\
    \ r){return l+r;}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode\
    \ var){return var == nodeVal;}\n};\n"
  code: "//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u7DCF\u548C\ntemplate<class T> struct\
    \ MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:03:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/SegmentTree-rsq.test.cpp
documentation_of: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeSumPointAdd.cpp
- /library/lib/operator/monoid/MonoidRangeSumPointAdd.cpp.html
title: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
---
