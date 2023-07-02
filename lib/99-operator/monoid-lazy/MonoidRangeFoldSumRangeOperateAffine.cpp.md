---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqrafq.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqrafq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/DualSegmentTree-pcq.test.cpp
    title: test/segment-tree/DualSegmentTree-pcq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeSumRangeAffine.md
    document_title: "MonoidRangeFoldSumRangeOperateAffine - fold:\u533A\u9593\u548C\
      , operate:\u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp\"\
    \n/*\n * @title MonoidRangeFoldSumRangeOperateAffine - fold:\u533A\u9593\u548C\
    , operate:\u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAffine.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateAffine {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = {1,0};\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ {new_lazy.first*old_lazy.first,new_lazy.first*old_lazy.second+new_lazy.second};}\n\
    \tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return {node*lazy.first+lazy.second*(r-l)};}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeFoldSumRangeOperateAffine - fold:\u533A\u9593\u548C\
    , operate:\u533A\u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAffine.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateAffine {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = {1,0};\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ {new_lazy.first*old_lazy.first,new_lazy.first*old_lazy.second+new_lazy.second};}\n\
    \tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return {node*lazy.first+lazy.second*(r-l)};}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
  requiredBy: []
  timestamp: '2023-06-03 10:08:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqrafq.test.cpp
  - test/segment-tree/DualSegmentTree-pcq.test.cpp
documentation_of: lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp
- /library/lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp.html
title: "MonoidRangeFoldSumRangeOperateAffine - fold:\u533A\u9593\u548C, operate:\u533A\
  \u9593\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
---
