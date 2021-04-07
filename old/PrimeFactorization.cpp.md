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
  bundledCode: "#line 1 \"old/PrimeFactorization.cpp\"\n\n//Prime Factorization O(sqrt(N))\n\
    vector<pair<long long,long long>> PrimeFactorization(long long N) {\n    vector<pair<long\
    \ long,long long>> ret;\n    if (N == 1) ret.push_back({1,0});\n    for (long\
    \ long i = 2,M = N; i*i <= M; ++i) {\n        if (N%i == 0) {\n            long\
    \ long cnt = 0;\n            while (N%i == 0) N /= i, cnt++;\n            ret.push_back({i,cnt});\n\
    \        }\n    }\n    if (N != 1) ret.push_back({N,1});\n    return ret;\n}\n"
  code: "\n//Prime Factorization O(sqrt(N))\nvector<pair<long long,long long>> PrimeFactorization(long\
    \ long N) {\n    vector<pair<long long,long long>> ret;\n    if (N == 1) ret.push_back({1,0});\n\
    \    for (long long i = 2,M = N; i*i <= M; ++i) {\n        if (N%i == 0) {\n \
    \           long long cnt = 0;\n            while (N%i == 0) N /= i, cnt++;\n\
    \            ret.push_back({i,cnt});\n        }\n    }\n    if (N != 1) ret.push_back({N,1});\n\
    \    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/PrimeFactorization.cpp
  requiredBy: []
  timestamp: '2020-09-06 00:15:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/PrimeFactorization.cpp
layout: document
redirect_from:
- /library/old/PrimeFactorization.cpp
- /library/old/PrimeFactorization.cpp.html
title: old/PrimeFactorization.cpp
---
