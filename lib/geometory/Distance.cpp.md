---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/geometory/Distance.md
    document_title: "Distance - \u8DDD\u96E2"
    links: []
  bundledCode: "#line 1 \"lib/geometory/Distance.cpp\"\n/*\n * @title Distance - \u8DDD\
    \u96E2\n * @docs md/geometory/Distance.md\n */\ntemplate<class T> class Distance{\n\
    public:\n    //Euclidean distance\n    inline static constexpr T euclid(const\
    \ T& x1, const T& y1, const T& x2, const T& y2) {\n        return sqrt((x1 - x2)*(x1\
    \ - x2) + (y1 - y2)*(y1 - y2));\n    }\n    //Chebyshev distance\n    inline static\
    \ constexpr T chebyshev(T x1, T y1, T x2, T y2) {\n        return max(abs(x1 -\
    \ x2),abs(y1 - y2));\n    }\n    //Manhattan distance\n    inline static constexpr\
    \ T manhattan(T x1, T y1, T x2, T y2) {\n        return abs(x1 - x2)+abs(y1 -\
    \ y2);\n    }\n    inline static constexpr T between_point_and_line(const T& x,const\
    \ T& y,const T& x1,const T& y1,const T& x2,const T& y2){\n        return abs((y2\
    \ - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2 - y1)*(y2 - y1)+(x1 - x2)*(x1\
    \ - x2));\n    }\n};\n"
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
  path: lib/geometory/Distance.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometory/Distance.cpp
layout: document
redirect_from:
- /library/lib/geometory/Distance.cpp
- /library/lib/geometory/Distance.cpp.html
title: "Distance - \u8DDD\u96E2"
---
