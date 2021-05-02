---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqraq.test.cpp
    title: test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-1.test.cpp
    title: test/graph/Tree-hld-vertex-1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp\"\n\
    //node:\u7DCF\u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct\
    \ MonoidRangeSumRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline\
    \ static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeLazy\
    \ unit_lazy = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy\
    \ new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n"
  code: "//node:\u7DCF\u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct\
    \ MonoidRangeSumRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline\
    \ static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeLazy\
    \ unit_lazy = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy\
    \ new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 18:07:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqraq.test.cpp
  - test/graph/Tree-hld-vertex-1.test.cpp
documentation_of: lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp.html
title: lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp
---
