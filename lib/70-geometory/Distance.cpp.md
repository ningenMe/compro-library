---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometory/Distance-line.test.cpp
    title: test/geometory/Distance-line.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Dijkstra.test.cpp
    title: test/graph/Dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/geometory/Distance.md
    document_title: "Distance - \u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"lib/70-geometory/Distance.cpp\"\n/*\n * @title Distance\
    \ - \u8DDD\u96E2\n * @docs md/geometory/Distance.md\n */\ntemplate<class T> class\
    \ Distance{\npublic:\n    //Euclidean distance\n    inline static constexpr T\
    \ euclid(const T& x1, const T& y1, const T& x2, const T& y2) {\n        return\
    \ sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));\n    }\n    //Chebyshev distance\n\
    \    inline static constexpr T chebyshev(T x1, T y1, T x2, T y2) {\n        return\
    \ max(abs(x1 - x2),abs(y1 - y2));\n    }\n    //Manhattan distance\n    inline\
    \ static constexpr T manhattan(T x1, T y1, T x2, T y2) {\n        return abs(x1\
    \ - x2)+abs(y1 - y2);\n    }\n    inline static constexpr T between_point_and_line(const\
    \ T& x,const T& y,const T& x1,const T& y1,const T& x2,const T& y2){\n        return\
    \ abs((y2 - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2 - y1)*(y2 - y1)+(x1\
    \ - x2)*(x1 - x2));\n    }\n};\n"
  code: "/*\n * @title Distance - \u8DDD\u96E2\n * @docs md/geometory/Distance.md\n\
    \ */\ntemplate<class T> class Distance{\npublic:\n    //Euclidean distance\n \
    \   inline static constexpr T euclid(const T& x1, const T& y1, const T& x2, const\
    \ T& y2) {\n        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));\n\
    \    }\n    //Chebyshev distance\n    inline static constexpr T chebyshev(T x1,\
    \ T y1, T x2, T y2) {\n        return max(abs(x1 - x2),abs(y1 - y2));\n    }\n\
    \    //Manhattan distance\n    inline static constexpr T manhattan(T x1, T y1,\
    \ T x2, T y2) {\n        return abs(x1 - x2)+abs(y1 - y2);\n    }\n    inline\
    \ static constexpr T between_point_and_line(const T& x,const T& y,const T& x1,const\
    \ T& y1,const T& x2,const T& y2){\n        return abs((y2 - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2\
    \ - y1)*(y2 - y1)+(x1 - x2)*(x1 - x2));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/70-geometory/Distance.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Dijkstra.test.cpp
  - test/geometory/Distance-line.test.cpp
documentation_of: lib/70-geometory/Distance.cpp
layout: document
redirect_from:
- /library/lib/70-geometory/Distance.cpp
- /library/lib/70-geometory/Distance.cpp.html
title: "Distance - \u8DDD\u96E2"
---
