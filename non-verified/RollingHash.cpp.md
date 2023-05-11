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
    - https://atcoder.jp/contests/abc141/tasks/abc141_e
  bundledCode: "#line 1 \"non-verified/RollingHash.cpp\"\nclass RollingHash {\nprivate:\n\
    \    long long base1,base2;\n    long long mod1,mod2;\n    vector<long long> hash1,hash2,pow1,pow2;\n\
    \ \npublic: \n    RollingHash(const string& S) : base1(1009), base2(1007), mod1(1000000007),\
    \ mod2(1000000009) {\n        int N = S.size();\n        hash1.resize(N+1,0);\n\
    \        hash2.resize(N+1,0);\n        pow1.resize(N+1,1);\n        pow2.resize(N+1,1);\n\
    \ \n        for(int i=1; i<=N; ++i) {\n            hash1[i] = ((hash1[i-1]+S[i-1])\
    \ * base1) % mod1;\n            hash2[i] = ((hash2[i-1]+S[i-1]) * base2) % mod2;\n\
    \            pow1[i] = (pow1[i-1] * base1) % mod1;\n            pow2[i] = (pow2[i-1]\
    \ * base2) % mod2;\n        }\n    }\n\n\t//[l,r)\n    pair<long long, long long>\
    \ get(int l,int r) {\n        long long t1 = ((hash1[r] - hash1[l] * pow1[r-l])\
    \ % mod1 + mod1) % mod1;\n        long long t2 = ((hash2[r] - hash2[l] * pow2[r-l])\
    \ % mod2 + mod2) % mod2;\n        return {t1,t2};\n    }\n};\n\n//verify\n//https://atcoder.jp/contests/abc141/tasks/abc141_e\n"
  code: "class RollingHash {\nprivate:\n    long long base1,base2;\n    long long\
    \ mod1,mod2;\n    vector<long long> hash1,hash2,pow1,pow2;\n \npublic: \n    RollingHash(const\
    \ string& S) : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {\n\
    \        int N = S.size();\n        hash1.resize(N+1,0);\n        hash2.resize(N+1,0);\n\
    \        pow1.resize(N+1,1);\n        pow2.resize(N+1,1);\n \n        for(int\
    \ i=1; i<=N; ++i) {\n            hash1[i] = ((hash1[i-1]+S[i-1]) * base1) % mod1;\n\
    \            hash2[i] = ((hash2[i-1]+S[i-1]) * base2) % mod2;\n            pow1[i]\
    \ = (pow1[i-1] * base1) % mod1;\n            pow2[i] = (pow2[i-1] * base2) % mod2;\n\
    \        }\n    }\n\n\t//[l,r)\n    pair<long long, long long> get(int l,int r)\
    \ {\n        long long t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1)\
    \ % mod1;\n        long long t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 +\
    \ mod2) % mod2;\n        return {t1,t2};\n    }\n};\n\n//verify\n//https://atcoder.jp/contests/abc141/tasks/abc141_e"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/RollingHash.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/RollingHash.cpp
layout: document
redirect_from:
- /library/non-verified/RollingHash.cpp
- /library/non-verified/RollingHash.cpp.html
title: non-verified/RollingHash.cpp
---
