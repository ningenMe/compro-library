---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/LazySegmentTree-rsqruq.test.cpp
    title: test/segment-tree/LazySegmentTree-rsqruq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeSumRangeUpdate.md
    document_title: "MonoidRangeSumRangeUpdate - [\u533A\u9593\u548C, \u533A\u9593\
      \u66F4\u65B0]"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp\"\
    \n/*\n * @title MonoidRangeSumRangeUpdate - [\u533A\u9593\u548C, \u533A\u9593\u66F4\
    \u65B0]\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeUpdate.md\n */\n\
    template<class T, class U> struct MonoidRangeSumRangeUpdate {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ 0;\n\tinline static constexpr TypeLazy unit_lazy = -2000;\n\tinline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\tinline static constexpr\
    \ TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}\n\t\
    inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline static constexpr bool\
    \ func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeSumRangeUpdate - [\u533A\u9593\u548C, \u533A\u9593\
    \u66F4\u65B0]\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeUpdate.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeSumRangeUpdate {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ 0;\n\tinline static constexpr TypeLazy unit_lazy = -2000;\n\tinline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\tinline static constexpr\
    \ TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}\n\t\
    inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline static constexpr bool\
    \ func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree/LazySegmentTree-rsqruq.test.cpp
documentation_of: lib/99-operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
- /library/lib/99-operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp.html
title: "MonoidRangeSumRangeUpdate - [\u533A\u9593\u548C, \u533A\u9593\u66F4\u65B0]"
---
