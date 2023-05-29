---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.md
    document_title: "MonoidRangeEulerTourSumRangeAdd - fold:\u533A\u9593\u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u548C, operate:\u533A\u9593\u52A0\u7B97"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp\"\
    \n/*\n * @title MonoidRangeEulerTourSumRangeAdd - fold:\u533A\u9593\u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\u548C, operate:\u533A\u9593\u52A0\u7B97\n * @docs\
    \ md/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.md\n */\ntemplate<class\
    \ T, class U> struct MonoidRangeFoldEulerTourSumRangeOperateAdd {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ {0,0};\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n\t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n\
    };\n"
  code: "/*\n * @title MonoidRangeEulerTourSumRangeAdd - fold:\u533A\u9593\u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\u548C, operate:\u533A\u9593\u52A0\u7B97\n * @docs\
    \ md/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.md\n */\ntemplate<class\
    \ T, class U> struct MonoidRangeFoldEulerTourSumRangeOperateAdd {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ {0,0};\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n\t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp
  requiredBy: []
  timestamp: '2023-05-30 03:43:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-eulertour.test.cpp
documentation_of: lib/operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp.html
title: "MonoidRangeEulerTourSumRangeAdd - fold:\u533A\u9593\u30AA\u30A4\u30E9\u30FC\
  \u30C4\u30A2\u30FC\u548C, operate:\u533A\u9593\u52A0\u7B97"
---
