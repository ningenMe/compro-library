---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
    title: test/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeMinRangeUpdate.md
    document_title: "MonoidRangeMinRangeUpdate - [\u533A\u9593min, \u533A\u9593\u66F4\
      \u65B0]"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeMinRangeUpdate.cpp\"\
    \n/*\n * @title MonoidRangeMinRangeUpdate - [\u533A\u9593min, \u533A\u9593\u66F4\
    \u65B0]\n * @docs md/operator/monoid-lazy/MonoidRangeMinRangeUpdate.md\n */\n\
    template<class T, class U> struct MonoidRangeMinRangeUpdate {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ 123456789;\n\tinline static constexpr TypeLazy unit_lazy = 123456789;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeMinRangeUpdate - [\u533A\u9593min, \u533A\u9593\u66F4\
    \u65B0]\n * @docs md/operator/monoid-lazy/MonoidRangeMinRangeUpdate.md\n */\n\
    template<class T, class U> struct MonoidRangeMinRangeUpdate {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ 123456789;\n\tinline static constexpr TypeLazy unit_lazy = 123456789;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeMinRangeUpdate.cpp
  requiredBy: []
  timestamp: '2021-05-02 12:04:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
documentation_of: lib/operator/monoid-lazy/MonoidRangeMinRangeUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeMinRangeUpdate.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeMinRangeUpdate.cpp.html
title: "MonoidRangeMinRangeUpdate - [\u533A\u9593min, \u533A\u9593\u66F4\u65B0]"
---