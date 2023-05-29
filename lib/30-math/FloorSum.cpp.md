---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FloorSum.test.cpp
    title: test/math/FloorSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/FloorSum.md
    document_title: "FloorSum - \u76F4\u7DDA\u9818\u57DF\u306E\u683C\u5B50\u70B9\u6570"
    links: []
  bundledCode: "#line 1 \"lib/30-math/FloorSum.cpp\"\n/**\n * @title FloorSum - \u76F4\
    \u7DDA\u9818\u57DF\u306E\u683C\u5B50\u70B9\u6570\n * @docs md/math/FloorSum.md\n\
    \ */\ninline static long long FloorSum(long long n, long long m, long long a,\
    \ long long b) {\n    long long ret=0;\n    while(1) {\n        if(a >= m) ret\
    \ += ((n-1)*n*(a/m))>>1,a%=m;\n        if(b >= m) ret += n*(b / m),b%=m;\n   \
    \     long long y=(a*n+b)/m, x=(y*m-b);\n        if(y==0) return ret;\n      \
    \  ret += (n-(x+a-1)/a)*y;\n        b=(a-x%a)%a; swap(a,m); n=y;\n    }\n}\n"
  code: "/**\n * @title FloorSum - \u76F4\u7DDA\u9818\u57DF\u306E\u683C\u5B50\u70B9\
    \u6570\n * @docs md/math/FloorSum.md\n */\ninline static long long FloorSum(long\
    \ long n, long long m, long long a, long long b) {\n    long long ret=0;\n   \
    \ while(1) {\n        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;\n        if(b\
    \ >= m) ret += n*(b / m),b%=m;\n        long long y=(a*n+b)/m, x=(y*m-b);\n  \
    \      if(y==0) return ret;\n        ret += (n-(x+a-1)/a)*y;\n        b=(a-x%a)%a;\
    \ swap(a,m); n=y;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/FloorSum.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/FloorSum.test.cpp
documentation_of: lib/30-math/FloorSum.cpp
layout: document
redirect_from:
- /library/lib/30-math/FloorSum.cpp
- /library/lib/30-math/FloorSum.cpp.html
title: "FloorSum - \u76F4\u7DDA\u9818\u57DF\u306E\u683C\u5B50\u70B9\u6570"
---
### FloorSum
- Σi:[0,n) floor((a*i+b)/m)を計算する  

### メソッド
- long long FloorSum(long long n, long long m, long long a, long long b)
  - O(log(n+m+a+b))
  - n,m,a,b:はそれぞれ下記に対応
    - $\sum_{i=0}^{n-1} \floor {a*i+b}/m $  

### 参考資料
- [Scary Sum - memo](https://min-25.hatenablog.com/entry/2018/04/27/225535)
- [格子点の数え上げの高速化 - memo](https://min-25.hatenablog.com/entry/2018/05/03/145505)
