---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
    title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-insert-erase.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-insert-erase.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md
    document_title: "MonoidRangeFoldMinRangeOperateUpdate - fold:\u533A\u9593min,\
      \ operate:\u533A\u9593\u66F4\u65B0"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp\"\
    \n/*\n * @title MonoidRangeFoldMinRangeOperateUpdate - fold:\u533A\u9593min, operate:\u533A\
    \u9593\u66F4\u65B0\n * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldMinRangeOperateUpdate {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 1000'000'001LL;\n\tinline static constexpr TypeLazy unit_lazy =\
    \ 1000'000'001LL;\n\tinline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return new_lazy;}\n\tinline static constexpr TypeNode\
    \ func_operate(TypeNode node,TypeLazy lazy,int l, int r){return lazy==unit_lazy?node:lazy;}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};\n\n"
  code: "/*\n * @title MonoidRangeFoldMinRangeOperateUpdate - fold:\u533A\u9593min,\
    \ operate:\u533A\u9593\u66F4\u65B0\n * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldMinRangeOperateUpdate {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 1000'000'001LL;\n\tinline static constexpr TypeLazy unit_lazy =\
    \ 1000'000'001LL;\n\tinline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return new_lazy;}\n\tinline static constexpr TypeNode\
    \ func_operate(TypeNode node,TypeLazy lazy,int l, int r){return lazy==unit_lazy?node:lazy;}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
  - test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-insert-erase.test.cpp
documentation_of: lib/99-operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp
- /library/lib/99-operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp.html
title: "MonoidRangeFoldMinRangeOperateUpdate - fold:\u533A\u9593min, operate:\u533A\
  \u9593\u66F4\u65B0"
---
