---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc016/tasks/abc016_4
  bundledCode: "#line 1 \"non-verified/Line_Intersection_Judge.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//Line Intersection Judge\ntemplate<class T> bool Line_Intersection_Judge(T\
    \ ax, T ay, T bx, T by, T cx, T cy, T dx, T dy) {\n    T ta = (cx - dx) * (ay\
    \ - cy) + (cy - dy) * (cx - ax);\n    T tb = (cx - dx) * (by - cy) + (cy - dy)\
    \ * (cx - bx);\n    T tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);\n  \
    \  T td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);\n    return tc * td <\
    \ 0 && ta * tb < 0;\n}\n\n//verify https://atcoder.jp/contests/abc016/tasks/abc016_4\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//Line Intersection Judge\n\
    template<class T> bool Line_Intersection_Judge(T ax, T ay, T bx, T by, T cx, T\
    \ cy, T dx, T dy) {\n    T ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);\n\
    \    T tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);\n    T tc = (ax - bx)\
    \ * (cy - ay) + (ay - by) * (ax - cx);\n    T td = (ax - bx) * (dy - ay) + (ay\
    \ - by) * (ax - dx);\n    return tc * td < 0 && ta * tb < 0;\n}\n\n//verify https://atcoder.jp/contests/abc016/tasks/abc016_4"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Line_Intersection_Judge.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Line_Intersection_Judge.cpp
layout: document
redirect_from:
- /library/non-verified/Line_Intersection_Judge.cpp
- /library/non-verified/Line_Intersection_Judge.cpp.html
title: non-verified/Line_Intersection_Judge.cpp
---
