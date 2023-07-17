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
  - icon: ':heavy_check_mark:'
    path: test/math/Eratosthenes.test.cpp
    title: test/math/Eratosthenes.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/Eratosthenes.md
    document_title: "Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Eratosthenes.cpp\"\n/*\n * @title Eratosthenes\
    \ - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n * @docs md/math/Eratosthenes.md\n\
    \ */\nclass Eratosthenes {\n    unsigned int sz;\npublic:\n    vector<unsigned\
    \ int> sieve;\n    vector<long long> prime;\n    Eratosthenes(unsigned int N):sz(N+1),sieve(N+1,\
    \ 1) {\n        sieve[0]=sieve[1]=0;\n        for(int i=1; i <= N/i; ++i) if(sieve[i])\
    \ for(int j=2*i;j<=N;j+=i) sieve[j]=0;\n        for(int i=1; i <= N  ; ++i) if(sieve[i])\
    \ prime.push_back(i);\n    }\n    size_t size() const {\n        return sz;\n\
    \    }\n};\n"
  code: "/*\n * @title Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9\n * @docs md/math/Eratosthenes.md\n */\nclass Eratosthenes {\n    unsigned\
    \ int sz;\npublic:\n    vector<unsigned int> sieve;\n    vector<long long> prime;\n\
    \    Eratosthenes(unsigned int N):sz(N+1),sieve(N+1, 1) {\n        sieve[0]=sieve[1]=0;\n\
    \        for(int i=1; i <= N/i; ++i) if(sieve[i]) for(int j=2*i;j<=N;j+=i) sieve[j]=0;\n\
    \        for(int i=1; i <= N  ; ++i) if(sieve[i]) prime.push_back(i);\n    }\n\
    \    size_t size() const {\n        return sz;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Eratosthenes.cpp
  requiredBy: []
  timestamp: '2023-06-18 04:36:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/DivisorZetaMoebiusTransform-gcd-convolution.test.cpp
  - test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
  - test/math/Eratosthenes.test.cpp
documentation_of: lib/30-math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/lib/30-math/Eratosthenes.cpp
- /library/lib/30-math/Eratosthenes.cpp.html
title: "Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
##### api
- Eratosthenes(int N)  
    - コンストラクタ [1,N]の篩を生成  