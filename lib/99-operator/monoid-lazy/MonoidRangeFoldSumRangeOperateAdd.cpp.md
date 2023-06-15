---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse2.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-1.test.cpp
    title: test/graph/Tree-hld-vertex-1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md
    document_title: "MonoidRangeSumRangeAdd - fold:\u533A\u9593\u548C, opearate:\u533A\
      \u9593\u52A0\u7B97"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp\"\
    \n/*\n * @title MonoidRangeSumRangeAdd - fold:\u533A\u9593\u548C, opearate:\u533A\
    \u9593\u52A0\u7B97\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateAdd {\n\t\
    using TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeSumRangeAdd - fold:\u533A\u9593\u548C, opearate:\u533A\
    \u9593\u52A0\u7B97\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateAdd {\n\t\
    using TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp
  requiredBy: []
  timestamp: '2023-06-03 16:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-hld-vertex-1.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse2.test.cpp
documentation_of: lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp
- /library/lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp.html
title: "MonoidRangeSumRangeAdd - fold:\u533A\u9593\u548C, opearate:\u533A\u9593\u52A0\
  \u7B97"
---
