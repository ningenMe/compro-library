---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.cpp\"\
    \n//node:\u7DCF\u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct\
    \ MonoidRangeEulerTourSumRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy =\
    \ U;\n\tinline static constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr\
    \ TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\tinline static\
    \ constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\
    \tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return {node.first+node.second*lazy,node.second};}\n\tinline static\
    \ constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\
    \t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n"
  code: "//node:\u7DCF\u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct\
    \ MonoidRangeEulerTourSumRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy =\
    \ U;\n\tinline static constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr\
    \ TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\tinline static\
    \ constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\
    \tinline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return {node.first+node.second*lazy,node.second};}\n\tinline static\
    \ constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\
    \t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:56:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/Tree-eulertour.test.cpp
documentation_of: lib/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.cpp.html
title: lib/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.cpp
---
