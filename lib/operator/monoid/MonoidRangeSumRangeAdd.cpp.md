---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeSumRangeAdd.cpp\"\n//node:\u7DCF\
    \u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct MonoidRangeSumRangeAdd\
    \ {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode fucn_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode fucn_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "//node:\u7DCF\u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct\
    \ MonoidRangeSumRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline\
    \ static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeLazy\
    \ unit_lazy = 0;\n\tinline static constexpr TypeNode fucn_fold(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy\
    \ new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr TypeNode fucn_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeSumRangeAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:23:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/monoid/MonoidRangeSumRangeAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeSumRangeAdd.cpp
- /library/lib/operator/monoid/MonoidRangeSumRangeAdd.cpp.html
title: lib/operator/monoid/MonoidRangeSumRangeAdd.cpp
---
