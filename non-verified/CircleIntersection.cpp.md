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
    - https://atcoder.jp/contests/abc157/tasks/abc157_f
  bundledCode: "#line 1 \"non-verified/CircleIntersection.cpp\"\ntemplate<class T>\
    \ inline vector<pair<T,T>> CircleIntersection(pair<T,T> p1, T r1, pair<T,T> p2,\
    \ T r2, T eps = 1e-6) {\n\tvector<pair<T,T>> res;\n\tT x1 = p1.first;\n\tT y1\
    \ = p1.second;\n\tT x2 = p2.first;\n\tT y2 = p2.second;\n\tif(abs(x1-x2) < eps\
    \ && abs(y1-y2) < eps && abs(r1-r2) < eps) return res;\n\tif(r1 + r2 + eps < sqrt((x1\
    \ - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))) return res;\n\tT a = 2*(x1-x2);\n\t\
    T b = 2*(y1-y2);\n\tT c = -(x1*x1-x2*x2) - (y1*y1-y2*y2) + (r1*r1 - r2*r2);\n\t\
    T d = a*x1+b*y1+c;\n\tT e = (a*a+b*b)*r1*r1-d*d;\n\tif(e<0) return res;\n\te =\
    \ sqrt(e);\n\tT x3 = (-a*d+b*e)/(a*a+b*b) + x1;\n\tT y3 = (-b*d-a*e)/(a*a+b*b)\
    \ + y1;\n\tT x4 = (-a*d-b*e)/(a*a+b*b) + x1;\n\tT y4 = (-b*d+a*e)/(a*a+b*b) +\
    \ y1;\n\tres.push_back({x3,y3});\n\tres.push_back({x4,y4});\n\treturn res;\n}\n\
    //verify https://atcoder.jp/contests/abc157/tasks/abc157_f\n"
  code: "template<class T> inline vector<pair<T,T>> CircleIntersection(pair<T,T> p1,\
    \ T r1, pair<T,T> p2, T r2, T eps = 1e-6) {\n\tvector<pair<T,T>> res;\n\tT x1\
    \ = p1.first;\n\tT y1 = p1.second;\n\tT x2 = p2.first;\n\tT y2 = p2.second;\n\t\
    if(abs(x1-x2) < eps && abs(y1-y2) < eps && abs(r1-r2) < eps) return res;\n\tif(r1\
    \ + r2 + eps < sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))) return res;\n\t\
    T a = 2*(x1-x2);\n\tT b = 2*(y1-y2);\n\tT c = -(x1*x1-x2*x2) - (y1*y1-y2*y2) +\
    \ (r1*r1 - r2*r2);\n\tT d = a*x1+b*y1+c;\n\tT e = (a*a+b*b)*r1*r1-d*d;\n\tif(e<0)\
    \ return res;\n\te = sqrt(e);\n\tT x3 = (-a*d+b*e)/(a*a+b*b) + x1;\n\tT y3 = (-b*d-a*e)/(a*a+b*b)\
    \ + y1;\n\tT x4 = (-a*d-b*e)/(a*a+b*b) + x1;\n\tT y4 = (-b*d+a*e)/(a*a+b*b) +\
    \ y1;\n\tres.push_back({x3,y3});\n\tres.push_back({x4,y4});\n\treturn res;\n}\n\
    //verify https://atcoder.jp/contests/abc157/tasks/abc157_f"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/CircleIntersection.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/CircleIntersection.cpp
layout: document
redirect_from:
- /library/non-verified/CircleIntersection.cpp
- /library/non-verified/CircleIntersection.cpp.html
title: non-verified/CircleIntersection.cpp
---
