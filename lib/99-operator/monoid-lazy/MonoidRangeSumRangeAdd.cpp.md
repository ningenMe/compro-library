---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md
    document_title: "MonoidRangeSumRangeAdd - [\u533A\u9593\u548C, \u533A\u9593\u52A0\
      \u7B97]"
    links: []
  bundledCode: "#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp\"\
    \n/*\n * @title MonoidRangeSumRangeAdd - [\u533A\u9593\u548C, \u533A\u9593\u52A0\
    \u7B97]\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md\n */\ntemplate<class\
    \ T, class U> struct MonoidRangeSumRangeAdd {\n\tusing TypeNode = T;\n\tusing\
    \ TypeLazy = U;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline static\
    \ constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr\
    \ TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeSumRangeAdd - [\u533A\u9593\u548C, \u533A\u9593\u52A0\
    \u7B97]\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md\n */\ntemplate<class\
    \ T, class U> struct MonoidRangeSumRangeAdd {\n\tusing TypeNode = T;\n\tusing\
    \ TypeLazy = U;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline static\
    \ constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr\
    \ TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
layout: document
redirect_from:
- /library/lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
- /library/lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp.html
title: "MonoidRangeSumRangeAdd - [\u533A\u9593\u548C, \u533A\u9593\u52A0\u7B97]"
---
