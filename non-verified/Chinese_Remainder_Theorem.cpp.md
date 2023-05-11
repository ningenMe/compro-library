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
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"non-verified/Chinese_Remainder_Theorem.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nlong long extGCD(long long a, long long b, long long &x,\
    \ long long &y) {\n    if (b == 0) {\n\t\tx = 1, y = 0;\n\t\treturn a;\n\t}\n\t\
    else {\n\t\tlong long d = extGCD(b, a%b, y, x);\n\t\ty -= a / b * x;\n\t\treturn\
    \ d;\n\t}\n}\n\n// r mod m_i = b_i, M = lcm(m_i)\npair<long long, long long> Chinese_Remainder_Theorem(const\
    \ vector<long long> &b, const vector<long long> &m) {\n    long long r = 0, M\
    \ = 1;\n    for (int i = 0; i < b.size(); ++i) {\n        long long p, q;\n  \
    \      long long d = extGCD(M, m[i], p, q);\n        if ((b[i] - r) % d != 0)\
    \ return {0, -1};\n        long long tmp = (b[i] - r) / d * p % (m[i]/d);\n  \
    \      r += M * tmp;\n        M *= m[i]/d;\n    }\n    return {(r%M+M)%M, M};\n\
    }\n\n//verify https://yukicoder.me/problems/no/186\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long extGCD(long long\
    \ a, long long b, long long &x, long long &y) {\n    if (b == 0) {\n\t\tx = 1,\
    \ y = 0;\n\t\treturn a;\n\t}\n\telse {\n\t\tlong long d = extGCD(b, a%b, y, x);\n\
    \t\ty -= a / b * x;\n\t\treturn d;\n\t}\n}\n\n// r mod m_i = b_i, M = lcm(m_i)\n\
    pair<long long, long long> Chinese_Remainder_Theorem(const vector<long long> &b,\
    \ const vector<long long> &m) {\n    long long r = 0, M = 1;\n    for (int i =\
    \ 0; i < b.size(); ++i) {\n        long long p, q;\n        long long d = extGCD(M,\
    \ m[i], p, q);\n        if ((b[i] - r) % d != 0) return {0, -1};\n        long\
    \ long tmp = (b[i] - r) / d * p % (m[i]/d);\n        r += M * tmp;\n        M\
    \ *= m[i]/d;\n    }\n    return {(r%M+M)%M, M};\n}\n\n//verify https://yukicoder.me/problems/no/186"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Chinese_Remainder_Theorem.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Chinese_Remainder_Theorem.cpp
layout: document
redirect_from:
- /library/non-verified/Chinese_Remainder_Theorem.cpp
- /library/non-verified/Chinese_Remainder_Theorem.cpp.html
title: non-verified/Chinese_Remainder_Theorem.cpp
---
