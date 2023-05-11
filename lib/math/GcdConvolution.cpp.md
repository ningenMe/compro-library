---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/GcdConvolution.md
    document_title: "GcdConvolution - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 1 \"lib/math/GcdConvolution.cpp\"\n/*\n * @title GcdConvolution\
    \ - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\n * @docs md/math/GcdConvolution.md\n\
    \ */\nclass GcdConvolution {\n    inline static vector<int> primes;\n    inline\
    \ static vector<int> eratosthenes(int N) {\n        vector<int> sieve(N+1,1),primes;\n\
    \        sieve[0]=sieve[1]=0;\n        for(int i=1; i <= N/i; ++i) if(sieve[i])\
    \ for(int j=2*i;j<=N;j+=i) sieve[j]=0;\n        for(int i=1; i <= N  ; ++i) if(sieve[i])\
    \ primes.push_back(i);\n        return primes;\n    };\n    template<class T>\
    \ inline static void zeta(vector<T>& v) {\n        assert(v.size());\n       \
    \ int N = v.size();\n        for(const int& p:primes) for(int i=(N-1)/p; i; --i)\
    \ v[i] += v[i*p];\n    }\n    template<class T> inline static void mobius(vector<T>&\
    \ v) {\n        assert(v.size());\n        int N = v.size();\n        for(const\
    \ int& p:primes) for(int i=1; i*p<N; ++i) v[i] -= v[i*p];\n    }\npublic:\n  \
    \  template<class T> inline static vector<T> convolution(const vector<T>& a,const\
    \ vector<T>& b) {\n        int N = max(a.size(),b.size());\n        vector<T>\
    \ f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n        for(int i=0;i<N;++i)\
    \ g[i] = b[i];\n        if(primes.empty()) primes = eratosthenes(N);\n       \
    \ zeta(f);zeta(g);\n        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius(f);\n\
    \        return f;\n    }\n};\n"
  code: "/*\n * @title GcdConvolution - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\n\
    \ * @docs md/math/GcdConvolution.md\n */\nclass GcdConvolution {\n    inline static\
    \ vector<int> primes;\n    inline static vector<int> eratosthenes(int N) {\n \
    \       vector<int> sieve(N+1,1),primes;\n        sieve[0]=sieve[1]=0;\n     \
    \   for(int i=1; i <= N/i; ++i) if(sieve[i]) for(int j=2*i;j<=N;j+=i) sieve[j]=0;\n\
    \        for(int i=1; i <= N  ; ++i) if(sieve[i]) primes.push_back(i);\n     \
    \   return primes;\n    };\n    template<class T> inline static void zeta(vector<T>&\
    \ v) {\n        assert(v.size());\n        int N = v.size();\n        for(const\
    \ int& p:primes) for(int i=(N-1)/p; i; --i) v[i] += v[i*p];\n    }\n    template<class\
    \ T> inline static void mobius(vector<T>& v) {\n        assert(v.size());\n  \
    \      int N = v.size();\n        for(const int& p:primes) for(int i=1; i*p<N;\
    \ ++i) v[i] -= v[i*p];\n    }\npublic:\n    template<class T> inline static vector<T>\
    \ convolution(const vector<T>& a,const vector<T>& b) {\n        int N = max(a.size(),b.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        if(primes.empty()) primes\
    \ = eratosthenes(N);\n        zeta(f);zeta(g);\n        for(int i=0;i<N;++i) f[i]\
    \ = f[i]*g[i];\n        mobius(f);\n        return f;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/GcdConvolution.cpp
  requiredBy: []
  timestamp: '2021-09-21 19:35:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/GcdConvolution.cpp
layout: document
redirect_from:
- /library/lib/math/GcdConvolution.cpp
- /library/lib/math/GcdConvolution.cpp.html
title: "GcdConvolution - \u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F"
---
### Polynomial
- Gcd添字畳み込み

### コンストラクタ
- なし

### メソッド
- vector<T> convolution(const vector<T>& a,const vector<T>& b) 
  - N = max(a.size(),b.size())として、$O(N\log\log N)$
  - c_n = Σ {n=gcd(i,j)} a_i*b_i を計算できる
  
### 参考資料
- [ゼータ変換・メビウス変換を理解する](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)
- [AtCoder AGC 038 C - LCMs (黄色, 700 点)](https://drken1215.hatenablog.com/entry/2020/11/06/031600)