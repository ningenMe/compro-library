---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc112/tasks/abc112_d
  bundledCode: "#line 1 \"non-verified/Divisor.cpp\"\n//divisor O(sqrt(N))\nset<long\
    \ long> Divisor(long long N) {\n    set<long long> ret;\n    for (long long i\
    \ = 1; i*i <= N; ++i) {\n        if (N%i == 0) {\n            ret.insert(i);\n\
    \            ret.insert(N / i);\n        }\n    }\n    return ret;\n}\n\n//verify\
    \ https://atcoder.jp/contests/abc112/tasks/abc112_d\n"
  code: "//divisor O(sqrt(N))\nset<long long> Divisor(long long N) {\n    set<long\
    \ long> ret;\n    for (long long i = 1; i*i <= N; ++i) {\n        if (N%i == 0)\
    \ {\n            ret.insert(i);\n            ret.insert(N / i);\n        }\n \
    \   }\n    return ret;\n}\n\n//verify https://atcoder.jp/contests/abc112/tasks/abc112_d"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Divisor.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Divisor.cpp
layout: document
redirect_from:
- /library/non-verified/Divisor.cpp
- /library/non-verified/Divisor.cpp.html
title: non-verified/Divisor.cpp
---
