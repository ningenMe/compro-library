---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md
    document_title: "MonoidRangeFoldSumRangeOperateUpdate - fold:\u533A\u9593sum,\
      \ operate:\u533A\u9593\u66F4\u65B0"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeFoldSumRangeOperateUpdate.cpp\"\
    \n/*\n * @title MonoidRangeFoldSumRangeOperateUpdate - fold:\u533A\u9593sum, operate:\u533A\
    \u9593\u66F4\u65B0\n * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateUpdate {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = -1;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeFoldSumRangeOperateUpdate - fold:\u533A\u9593sum,\
    \ operate:\u533A\u9593\u66F4\u65B0\n * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateUpdate {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = -1;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeFoldSumRangeOperateUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-29 04:05:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/monoid-lazy/MonoidRangeFoldSumRangeOperateUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeFoldSumRangeOperateUpdate.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeFoldSumRangeOperateUpdate.cpp.html
title: "MonoidRangeFoldSumRangeOperateUpdate - fold:\u533A\u9593sum, operate:\u533A\
  \u9593\u66F4\u65B0"
---
