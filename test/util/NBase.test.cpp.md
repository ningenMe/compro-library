---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/00-util/NBase.cpp
    title: "NBase - N\u9032\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/699
    links:
    - https://yukicoder.me/problems/no/699
  bundledCode: "#line 1 \"test/util/NBase.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/699\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n#line 1 \"lib/00-util/NBase.cpp\"\n/*\n * @title NBase -\
    \ N\u9032\u6570\n * @docs md/util/NBase.md\n */\nclass NBase{\npublic:\n\tinline\
    \ static vector<long long> translate(long long X,long long N) {\n\t\tassert(abs(N)>1);\n\
    \t\tvector<long long> res;\n\t\twhile(1) {\n\t\t\tlong long b = (X%abs(N)+abs(N))\
    \ % abs(N);\n\t\t\tres.push_back(b);\n\t\t\t(X -= b) /= N;\n\t\t\tif(X==0) break;\n\
    \t\t}\n\t\treturn res;\n\t}\n\t//Digit Sum\n\tinline static constexpr long long\
    \ digit_sum(long long N, long long K) {\n\t\tlong long sum = 0;\n\t\tfor (; N\
    \ > 0; N /= K) sum += N % K;\n\t\treturn sum;\n\t}\n};\n#line 9 \"test/util/NBase.test.cpp\"\
    \n\nint main(void){\n\tint N; cin >> N;\n    vector<long long> A(N);\n    for(int\
    \ i = 0; i < N; ++i) cin >> A[i];\n    sort(A.begin(),A.end());\n    vector<long\
    \ long> B(N/2),C(N/2);\n    long long ans = 0;\n    for(int i = 0; i < (1<<N);\
    \ ++i) {\n        if(i&1 || NBase::digit_sum(i,2)!=N/2) continue;\n        int\
    \ b=0,c=0;\n        for(int j = 0; j < N; ++j) {\n            if(i&(1<<j)) B[b++]=A[j];\n\
    \            else C[c++]=A[j];\n        }\n        do{\n            long long\
    \ sum = 0;\n            for(int j = 0; j < N/2; ++j) {\n                sum ^=\
    \ (B[j]+C[j]);\n            }\n\t\t\tans = max(ans,sum);\n        }while (next_permutation(B.begin(),B.end()));\n\
    \    }\n    cout << ans << endl;\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/699\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/00-util/NBase.cpp\"\n\nint main(void){\n\tint N;\
    \ cin >> N;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) cin >>\
    \ A[i];\n    sort(A.begin(),A.end());\n    vector<long long> B(N/2),C(N/2);\n\
    \    long long ans = 0;\n    for(int i = 0; i < (1<<N); ++i) {\n        if(i&1\
    \ || NBase::digit_sum(i,2)!=N/2) continue;\n        int b=0,c=0;\n        for(int\
    \ j = 0; j < N; ++j) {\n            if(i&(1<<j)) B[b++]=A[j];\n            else\
    \ C[c++]=A[j];\n        }\n        do{\n            long long sum = 0;\n     \
    \       for(int j = 0; j < N/2; ++j) {\n                sum ^= (B[j]+C[j]);\n\
    \            }\n\t\t\tans = max(ans,sum);\n        }while (next_permutation(B.begin(),B.end()));\n\
    \    }\n    cout << ans << endl;\n\n\treturn 0;\n}"
  dependsOn:
  - lib/00-util/NBase.cpp
  isVerificationFile: true
  path: test/util/NBase.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:54:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/util/NBase.test.cpp
layout: document
redirect_from:
- /verify/test/util/NBase.test.cpp
- /verify/test/util/NBase.test.cpp.html
title: test/util/NBase.test.cpp
---
