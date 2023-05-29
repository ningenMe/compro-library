---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/00-util/NBase.test.cpp
    title: test/00-util/NBase.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/00-util/NBase.md
    document_title: "NBase - N\u9032\u6570"
    links: []
  bundledCode: "#line 1 \"lib/00-util/NBase.cpp\"\n/*\n * @title NBase - N\u9032\u6570\
    \n * @docs md/00-util/NBase.md\n */\nclass NBase{\npublic:\n\tinline static vector<long\
    \ long> translate(long long X,long long N) {\n\t\tassert(abs(N)>1);\n\t\tvector<long\
    \ long> res;\n\t\twhile(1) {\n\t\t\tlong long b = (X%abs(N)+abs(N)) % abs(N);\n\
    \t\t\tres.push_back(b);\n\t\t\t(X -= b) /= N;\n\t\t\tif(X==0) break;\n\t\t}\n\t\
    \treturn res;\n\t}\n\t//Digit Sum\n\tinline static constexpr long long digit_sum(long\
    \ long N, long long K) {\n\t\tlong long sum = 0;\n\t\tfor (; N > 0; N /= K) sum\
    \ += N % K;\n\t\treturn sum;\n\t}\n};\n"
  code: "/*\n * @title NBase - N\u9032\u6570\n * @docs md/00-util/NBase.md\n */\n\
    class NBase{\npublic:\n\tinline static vector<long long> translate(long long X,long\
    \ long N) {\n\t\tassert(abs(N)>1);\n\t\tvector<long long> res;\n\t\twhile(1) {\n\
    \t\t\tlong long b = (X%abs(N)+abs(N)) % abs(N);\n\t\t\tres.push_back(b);\n\t\t\
    \t(X -= b) /= N;\n\t\t\tif(X==0) break;\n\t\t}\n\t\treturn res;\n\t}\n\t//Digit\
    \ Sum\n\tinline static constexpr long long digit_sum(long long N, long long K)\
    \ {\n\t\tlong long sum = 0;\n\t\tfor (; N > 0; N /= K) sum += N % K;\n\t\treturn\
    \ sum;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/00-util/NBase.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:03:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/00-util/NBase.test.cpp
documentation_of: lib/00-util/NBase.cpp
layout: document
redirect_from:
- /library/lib/00-util/NBase.cpp
- /library/lib/00-util/NBase.cpp.html
title: "NBase - N\u9032\u6570"
---
