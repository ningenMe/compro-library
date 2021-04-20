---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"non-verified/PrimeFactorization.cpp\"\n\n//Prime Factorization\
    \ O(sqrt(N))\nvector<pair<long long,long long>> PrimeFactorization(long long N)\
    \ {\n    vector<pair<long long,long long>> ret;\n    if (N == 1) ret.push_back({1,0});\n\
    \    for (long long i = 2,M = N; i*i <= M; ++i) {\n        if (N%i == 0) {\n \
    \           long long cnt = 0;\n            while (N%i == 0) N /= i, cnt++;\n\
    \            ret.push_back({i,cnt});\n        }\n    }\n    if (N != 1) ret.push_back({N,1});\n\
    \    return ret;\n}\n"
  code: "\n//Prime Factorization O(sqrt(N))\nvector<pair<long long,long long>> PrimeFactorization(long\
    \ long N) {\n    vector<pair<long long,long long>> ret;\n    if (N == 1) ret.push_back({1,0});\n\
    \    for (long long i = 2,M = N; i*i <= M; ++i) {\n        if (N%i == 0) {\n \
    \           long long cnt = 0;\n            while (N%i == 0) N /= i, cnt++;\n\
    \            ret.push_back({i,cnt});\n        }\n    }\n    if (N != 1) ret.push_back({N,1});\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/PrimeFactorization.cpp
  requiredBy: []
  timestamp: '2021-04-21 01:33:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/PrimeFactorization.cpp
layout: document
redirect_from:
- /library/non-verified/PrimeFactorization.cpp
- /library/non-verified/PrimeFactorization.cpp.html
title: non-verified/PrimeFactorization.cpp
---
