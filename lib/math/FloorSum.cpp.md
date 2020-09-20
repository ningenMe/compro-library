---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FloorSum.test.cpp
    title: test/math/FloorSum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: FloorSum
    links:
    - https://min-25.hatenablog.com/entry/2018/04/27/225535
    - https://min-25.hatenablog.com/entry/2018/05/03/145505
  bundledCode: "#line 1 \"lib/math/FloorSum.cpp\"\n/**\n * @title FloorSum\n * O(log(n+m+a+b))\n\
    \ * \u03A3i:[0,N) floor((a*i+b)/m)\u3092\u8A08\u7B97\u3059\u308B\n * @see \"https://min-25.hatenablog.com/entry/2018/04/27/225535\"\
    \n * @see \"https://min-25.hatenablog.com/entry/2018/05/03/145505\"\n */\ninline\
    \ static long long FloorSum(long long n, long long m, long long a, long long b)\
    \ {\n    long long ret=0;\n    while(1) {\n        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;\n\
    \        if(b >= m) ret += n*(b / m),b%=m;\n        long long y=(a*n+b)/m, x=(y*m-b);\n\
    \        if(y==0) return ret;\n        ret += (n-(x+a-1)/a)*y;\n        b=(a-x%a)%a;\
    \ swap(a,m); n=y;\n    }\n}\n"
  code: "/**\n * @title FloorSum\n * O(log(n+m+a+b))\n * \u03A3i:[0,N) floor((a*i+b)/m)\u3092\
    \u8A08\u7B97\u3059\u308B\n * @see \"https://min-25.hatenablog.com/entry/2018/04/27/225535\"\
    \n * @see \"https://min-25.hatenablog.com/entry/2018/05/03/145505\"\n */\ninline\
    \ static long long FloorSum(long long n, long long m, long long a, long long b)\
    \ {\n    long long ret=0;\n    while(1) {\n        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;\n\
    \        if(b >= m) ret += n*(b / m),b%=m;\n        long long y=(a*n+b)/m, x=(y*m-b);\n\
    \        if(y==0) return ret;\n        ret += (n-(x+a-1)/a)*y;\n        b=(a-x%a)%a;\
    \ swap(a,m); n=y;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/FloorSum.cpp
  requiredBy: []
  timestamp: '2020-09-08 05:45:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/FloorSum.test.cpp
documentation_of: lib/math/FloorSum.cpp
layout: document
redirect_from:
- /library/lib/math/FloorSum.cpp
- /library/lib/math/FloorSum.cpp.html
title: FloorSum
---
