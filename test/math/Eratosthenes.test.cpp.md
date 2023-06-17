---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/30-math/Eratosthenes.cpp
    title: "Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1058
    links:
    - https://yukicoder.me/problems/no/1058
  bundledCode: "#line 1 \"test/math/Eratosthenes.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1058\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n#line 1 \"lib/30-math/Eratosthenes.cpp\"\n/*\n * @title Eratosthenes -\
    \ \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n * @docs md/math/Eratosthenes.md\n\
    \ */\nclass Eratosthenes {\n    unsigned int sz;\npublic:\n    vector<unsigned\
    \ int> sieve;\n    vector<long long> prime;\n    Eratosthenes(unsigned int N):sz(N+1),sieve(N+1,\
    \ 1) {\n        sieve[0]=sieve[1]=0;\n        for(int i=1; i <= N/i; ++i) if(sieve[i])\
    \ for(int j=2*i;j<=N;j+=i) sieve[j]=0;\n        for(int i=1; i <= N  ; ++i) if(sieve[i])\
    \ prime.push_back(i);\n    }\n    size_t size() const {\n        return sz;\n\
    \    }\n};\n#line 8 \"test/math/Eratosthenes.test.cpp\"\n\nint main() {\n    long\
    \ long N;\n    cin >> N;\n    auto E = Eratosthenes(200000);\n    vector<long\
    \ long> A;\n    for(int i = 100001; i < 100100; ++i) {\n        if(E.sieve[i])\
    \ A.push_back(i);\n    }\n    vector<long long> B={1};\n    for(auto& e1:A) for(auto&\
    \ e2:A) B.push_back(e1*e2);\n    sort(B.begin(),B.end());\n    unique(B.begin(),B.end());\n\
    \    cout << B[N-1] << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1058\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\nusing namespace std;\n#include \"../../lib/30-math/Eratosthenes.cpp\"\
    \n\nint main() {\n    long long N;\n    cin >> N;\n    auto E = Eratosthenes(200000);\n\
    \    vector<long long> A;\n    for(int i = 100001; i < 100100; ++i) {\n      \
    \  if(E.sieve[i]) A.push_back(i);\n    }\n    vector<long long> B={1};\n    for(auto&\
    \ e1:A) for(auto& e2:A) B.push_back(e1*e2);\n    sort(B.begin(),B.end());\n  \
    \  unique(B.begin(),B.end());\n    cout << B[N-1] << endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/30-math/Eratosthenes.cpp
  isVerificationFile: true
  path: test/math/Eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 04:36:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/test/math/Eratosthenes.test.cpp
- /verify/test/math/Eratosthenes.test.cpp.html
title: test/math/Eratosthenes.test.cpp
---
