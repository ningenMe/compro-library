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
  bundledCode: "#line 1 \"non-verified/MontmortNumber.cpp\"\ntemplate <long long mod>\
    \ class MontmortNumber{\n    vector<long long> res;\npublic:\n    MontmortNumber(long\
    \ long N):res(N+1,0) {\n        if(N>=2) res[2]=1;\n        for(int i = 3; i <=\
    \ N; ++i) res[i]=(i-1)*((res[i-1]+res[i-2])%mod) % mod;\n    }\n\tinline long\
    \ long num(int N) {\n\t\treturn res[N];\n\t}   \n};\n"
  code: "template <long long mod> class MontmortNumber{\n    vector<long long> res;\n\
    public:\n    MontmortNumber(long long N):res(N+1,0) {\n        if(N>=2) res[2]=1;\n\
    \        for(int i = 3; i <= N; ++i) res[i]=(i-1)*((res[i-1]+res[i-2])%mod) %\
    \ mod;\n    }\n\tinline long long num(int N) {\n\t\treturn res[N];\n\t}   \n};"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/MontmortNumber.cpp
  requiredBy: []
  timestamp: '2020-07-12 22:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/MontmortNumber.cpp
layout: document
redirect_from:
- /library/non-verified/MontmortNumber.cpp
- /library/non-verified/MontmortNumber.cpp.html
title: non-verified/MontmortNumber.cpp
---
