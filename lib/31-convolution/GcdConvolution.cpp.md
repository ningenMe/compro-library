---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/GcdConvolution.test.cpp
    title: test/convolution/GcdConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/31-convolution/GcdConvolution.md
    document_title: "GcdConvolution - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 1 \"lib/31-convolution/GcdConvolution.cpp\"\n/*\n * @title GcdConvolution\
    \ - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\n * @docs md/31-convolution/GcdConvolution.md\n\
    \ */\nclass GcdConvolution {\n    template<class T> inline static void zeta(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size());\n        int\
    \ N = v.size();\n        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p;\
    \ i; --i) v[i] += v[i*p];\n    }\n    template<class T> inline static void mobius(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size());\n        int\
    \ N = v.size();\n        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N;\
    \ ++i) v[i] -= v[i*p];\n    }\npublic:\n    template<class T> inline static vector<T>\
    \ convolution(const vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes)\
    \ {\n        int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta(f,eratosthenes);zeta(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius(f,eratosthenes);\n\
    \        return f;\n    }\n};\n"
  code: "/*\n * @title GcdConvolution - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\n\
    \ * @docs md/31-convolution/GcdConvolution.md\n */\nclass GcdConvolution {\n \
    \   template<class T> inline static void zeta(vector<T>& v, const Eratosthenes&\
    \ eratosthenes) {\n        assert(v.size());\n        int N = v.size();\n    \
    \    for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) v[i] += v[i*p];\n\
    \    }\n    template<class T> inline static void mobius(vector<T>& v, const Eratosthenes&\
    \ eratosthenes) {\n        assert(v.size());\n        int N = v.size();\n    \
    \    for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) v[i] -= v[i*p];\n\
    \    }\npublic:\n    template<class T> inline static vector<T> convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta(f,eratosthenes);zeta(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius(f,eratosthenes);\n\
    \        return f;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/31-convolution/GcdConvolution.cpp
  requiredBy: []
  timestamp: '2023-06-18 04:35:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/GcdConvolution.test.cpp
documentation_of: lib/31-convolution/GcdConvolution.cpp
layout: document
redirect_from:
- /library/lib/31-convolution/GcdConvolution.cpp
- /library/lib/31-convolution/GcdConvolution.cpp.html
title: "GcdConvolution - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F"
---
