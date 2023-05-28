---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/LazySegmentTree-rmqraq.test.cpp
    title: test/data-structure/segment-tree/LazySegmentTree-rmqraq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.md
    document_title: "MonoidRangeFoldMinRangeOperateAdd - fold:\u533A\u9593min, operate:\u533A\
      \u9593\u52A0\u7B97"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.cpp\"\
    \n/*\n * @title MonoidRangeFoldMinRangeOperateAdd - fold:\u533A\u9593min, operate:\u533A\
    \u9593\u52A0\u7B97\n * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldMinRangeOperateAdd {\n\t\
    using TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 1234567890;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\
    \tinline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy;}\n};\n"
  code: "/*\n * @title MonoidRangeFoldMinRangeOperateAdd - fold:\u533A\u9593min, operate:\u533A\
    \u9593\u52A0\u7B97\n * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldMinRangeOperateAdd {\n\t\
    using TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 1234567890;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\
    \tinline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.cpp
  requiredBy: []
  timestamp: '2023-05-29 04:11:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/LazySegmentTree-rmqraq.test.cpp
documentation_of: lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.cpp.html
title: "MonoidRangeFoldMinRangeOperateAdd - fold:\u533A\u9593min, operate:\u533A\u9593\
  \u52A0\u7B97"
---
