---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeSumRangeUpdate.md
    document_title: "MonoidRangeSumRangeUpdate - [\u533A\u9593\u548C, \u533A\u9593\
      \u66F4\u65B0]"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp\"\
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
  path: lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
  requiredBy: []
  timestamp: '2021-05-02 12:04:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp.html
title: "MonoidRangeSumRangeUpdate - [\u533A\u9593\u548C, \u533A\u9593\u66F4\u65B0]"
---
