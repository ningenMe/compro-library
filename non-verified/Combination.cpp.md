---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3
  bundledCode: "#line 1 \"non-verified/Combination.cpp\"\ntemplate<class T> class\
    \ Combination{\n\tvector<vector<T>> num;\npublic:    \n    //O(N^2)\n    Combination(int\
    \ N):num(N+1,vector<T>(N+1,(T)0)){\n\t\tnum[0][0] = 1;\n\t\tfor (int n = 1; n\
    \ <= N; n++) {\n\t\t\tfor (int k = 0; k <= n; k++) {\n\t\t\t\tnum[n][k] = (num[n\
    \ - 1][k]+(k?num[n - 1][k - 1]:0));\n\t\t\t}\n\t\t}\n    } \n\tinline T binom(int\
    \ n, int k) {\n\t\treturn ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);\n\t}\n\
    \    //nCk mod p (p is prime & p <= N)\n    inline T lucas(int n, int k, long\
    \ long p) {\n        long long res=1;\n        for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p])\
    \ %= p;\n        return res;\n    }\n};\n//https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3\n"
  code: "template<class T> class Combination{\n\tvector<vector<T>> num;\npublic: \
    \   \n    //O(N^2)\n    Combination(int N):num(N+1,vector<T>(N+1,(T)0)){\n\t\t\
    num[0][0] = 1;\n\t\tfor (int n = 1; n <= N; n++) {\n\t\t\tfor (int k = 0; k <=\
    \ n; k++) {\n\t\t\t\tnum[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0));\n\t\t\
    \t}\n\t\t}\n    } \n\tinline T binom(int n, int k) {\n\t\treturn ((n < 0 || k\
    \ < 0 || n < k) ? 0 : num[n][k]);\n\t}\n    //nCk mod p (p is prime & p <= N)\n\
    \    inline T lucas(int n, int k, long long p) {\n        long long res=1;\n \
    \       for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p]) %= p;\n        return res;\n\
    \    }\n};\n//https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Combination.cpp
  requiredBy: []
  timestamp: '2020-07-24 12:36:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Combination.cpp
layout: document
redirect_from:
- /library/non-verified/Combination.cpp
- /library/non-verified/Combination.cpp.html
title: non-verified/Combination.cpp
---
