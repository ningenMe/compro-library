---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/DivisorZetaMoebiusTransform-gcd-convolution.test.cpp
    title: test/convolution/DivisorZetaMoebiusTransform-gcd-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
    title: test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/DivisorZetaMoebiusTransform.md
    document_title: "DivisorZetaMoebiusTransform - \u7D04\u6570\u306E\u30BC\u30FC\u30BF\
      \u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (gcd/lcm\u7573\u307F\u8FBC\u307F)"
    links: []
  bundledCode: "#line 1 \"lib/31-convolution/DivisorZetaMoebiusTransform.cpp\"\n/*\n\
    \ * @title DivisorZetaMoebiusTransform - \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u30FB\
    \u30E1\u30D3\u30A6\u30B9\u5909\u63DB (gcd/lcm\u7573\u307F\u8FBC\u307F)\n * @docs\
    \ md/math/DivisorZetaMoebiusTransform.md\n */\nclass DivisorZetaMoebiusTransform\
    \ {\n    template<class T> inline static void zeta_multiple(vector<T>& v, const\
    \ Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) v[i]\
    \ += v[i*p];\n    }\n    template<class T> inline static void mobius_multiple(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) v[i] -=\
    \ v[i*p];\n    }\n    template<class T> inline static void zeta_divisor(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) {v[i*p]\
    \ += v[i];}\n    }\n    template<class T> inline static void mobius_divisor(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) {v[i*p]\
    \ -= v[i];}\n    }\npublic:\n    template<class T> inline static vector<T> gcd_convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta_multiple(f,eratosthenes);zeta_multiple(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius_multiple(f,eratosthenes);\n\
    \        return f;\n    }\n    template<class T> inline static vector<T> lcm_convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta_divisor(f,eratosthenes);zeta_divisor(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius_divisor(f,eratosthenes);\n\
    \        return f;\n    }\n};\n"
  code: "/*\n * @title DivisorZetaMoebiusTransform - \u7D04\u6570\u306E\u30BC\u30FC\
    \u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (gcd/lcm\u7573\u307F\u8FBC\u307F\
    )\n * @docs md/math/DivisorZetaMoebiusTransform.md\n */\nclass DivisorZetaMoebiusTransform\
    \ {\n    template<class T> inline static void zeta_multiple(vector<T>& v, const\
    \ Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) v[i]\
    \ += v[i*p];\n    }\n    template<class T> inline static void mobius_multiple(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) v[i] -=\
    \ v[i*p];\n    }\n    template<class T> inline static void zeta_divisor(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) {v[i*p]\
    \ += v[i];}\n    }\n    template<class T> inline static void mobius_divisor(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) {v[i*p]\
    \ -= v[i];}\n    }\npublic:\n    template<class T> inline static vector<T> gcd_convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta_multiple(f,eratosthenes);zeta_multiple(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius_multiple(f,eratosthenes);\n\
    \        return f;\n    }\n    template<class T> inline static vector<T> lcm_convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta_divisor(f,eratosthenes);zeta_divisor(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius_divisor(f,eratosthenes);\n\
    \        return f;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/31-convolution/DivisorZetaMoebiusTransform.cpp
  requiredBy: []
  timestamp: '2023-06-18 05:25:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/DivisorZetaMoebiusTransform-gcd-convolution.test.cpp
  - test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
documentation_of: lib/31-convolution/DivisorZetaMoebiusTransform.cpp
layout: document
redirect_from:
- /library/lib/31-convolution/DivisorZetaMoebiusTransform.cpp
- /library/lib/31-convolution/DivisorZetaMoebiusTransform.cpp.html
title: "DivisorZetaMoebiusTransform - \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u30FB\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB (gcd/lcm\u7573\u307F\u8FBC\u307F)"
---
