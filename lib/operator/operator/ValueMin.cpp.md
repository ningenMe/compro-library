---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-min.test.cpp
    title: test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
    title: test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
    title: test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/operator/operator/ValueMin.cpp\"\n//\u6700\u5C0F\u5024\
    \u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMin {\n\tusing TypeValue = T;\n\
    \tinline static constexpr TypeValue unit_value = 3e18;\n\tinline static constexpr\
    \ bool func_compare(TypeValue l,TypeValue r){return l<r;}\n};\n"
  code: "//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMin\
    \ {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue unit_value =\
    \ 3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue r){return\
    \ l<r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/operator/ValueMin.cpp
  requiredBy: []
  timestamp: '2021-04-26 09:09:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/convex-hull-trick/ConvexHullTrickMonotone-min.test.cpp
  - test/data-structure/convex-hull-trick/LiChaoTree-line.test.cpp
  - test/data-structure/convex-hull-trick/LiChaoTree-segment.test.cpp
documentation_of: lib/operator/operator/ValueMin.cpp
layout: document
redirect_from:
- /library/lib/operator/operator/ValueMin.cpp
- /library/lib/operator/operator/ValueMin.cpp.html
title: lib/operator/operator/ValueMin.cpp
---
