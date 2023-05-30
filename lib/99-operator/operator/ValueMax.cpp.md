---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convex-hull-trick/ConvexHullTrick-max.test.cpp
    title: test/convex-hull-trick/ConvexHullTrick-max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
    title: test/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/99-operator/operator/ValueMax.cpp\"\n//\u6700\u5927\u5024\
    \u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMax {\n\tusing TypeValue = T;\n\
    \tinline static constexpr TypeValue unit_value = -3e18;\n\tinline static constexpr\
    \ bool func_compare(TypeValue l,TypeValue r){return l>r;}\n};\n"
  code: "//\u6700\u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMax\
    \ {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue unit_value =\
    \ -3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue r){return\
    \ l>r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/99-operator/operator/ValueMax.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convex-hull-trick/ConvexHullTrickMonotone-max.test.cpp
  - test/convex-hull-trick/ConvexHullTrick-max.test.cpp
documentation_of: lib/99-operator/operator/ValueMax.cpp
layout: document
redirect_from:
- /library/lib/99-operator/operator/ValueMax.cpp
- /library/lib/99-operator/operator/ValueMax.cpp.html
title: lib/99-operator/operator/ValueMax.cpp
---
