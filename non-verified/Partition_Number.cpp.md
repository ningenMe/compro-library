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
    - https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c
  bundledCode: "#line 1 \"non-verified/Partition_Number.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//Partition_Number\nclass Partition_Number {\npublic:\n\
    \tvector<vector<long long>> num;\t//n\u3092k\u500B\u306B\u5206\u3051\u308B\u5206\
    \u5272\u6570\n\tPartition_Number(int N, int K, long long mod) :num(vector<vector<long\
    \ long>>(N + 1, vector<long long>(K + 1, 0))) {\n\t\tnum[0][0] = 1;\n\t\tfor (int\
    \ i = 0; i <= N; ++i) for (int j = 1; j <= K; ++j) num[i][j] = (num[i][j - 1]\
    \ + ((i >= j) ? num[i - j][j] : 0)) % mod;\n\t}\n};\n\n\n//verify https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//Partition_Number\nclass\
    \ Partition_Number {\npublic:\n\tvector<vector<long long>> num;\t//n\u3092k\u500B\
    \u306B\u5206\u3051\u308B\u5206\u5272\u6570\n\tPartition_Number(int N, int K, long\
    \ long mod) :num(vector<vector<long long>>(N + 1, vector<long long>(K + 1, 0)))\
    \ {\n\t\tnum[0][0] = 1;\n\t\tfor (int i = 0; i <= N; ++i) for (int j = 1; j <=\
    \ K; ++j) num[i][j] = (num[i][j - 1] + ((i >= j) ? num[i - j][j] : 0)) % mod;\n\
    \t}\n};\n\n\n//verify https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Partition_Number.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Partition_Number.cpp
layout: document
redirect_from:
- /library/non-verified/Partition_Number.cpp
- /library/non-verified/Partition_Number.cpp.html
title: non-verified/Partition_Number.cpp
---
