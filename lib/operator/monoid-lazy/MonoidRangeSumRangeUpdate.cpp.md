---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/LazySegmentTree-rsqruq.test.cpp
    title: test/data-structure/segment-tree/LazySegmentTree-rsqruq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp\"\
    \n//node:\u7DCF\u548C\u3000lazy:\u66F4\u65B0\ntemplate<class T, class U> struct\
    \ MonoidRangeSumRangeUpdate {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\t\
    inline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeLazy\
    \ unit_lazy = -2000;\n\tinline static constexpr TypeNode fucn_fold(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy\
    \ new_lazy){return new_lazy;}\n\tinline static constexpr TypeNode fucn_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline\
    \ static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <=\
    \ nodeVal;}\n};\n"
  code: "//node:\u7DCF\u548C\u3000lazy:\u66F4\u65B0\ntemplate<class T, class U> struct\
    \ MonoidRangeSumRangeUpdate {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\t\
    inline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeLazy\
    \ unit_lazy = -2000;\n\tinline static constexpr TypeNode fucn_fold(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy\
    \ new_lazy){return new_lazy;}\n\tinline static constexpr TypeNode fucn_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline\
    \ static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <=\
    \ nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:33:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/LazySegmentTree-rsqruq.test.cpp
documentation_of: lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp.html
title: lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp
---
