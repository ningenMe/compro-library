---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Eratosthenes.test.cpp
    title: test/math/Eratosthenes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/math/Eratosthenes.md
    document_title: Eratosthenes
    links: []
  bundledCode: "#line 1 \"lib/math/Eratosthenes.cpp\"\n/*\n * @title Eratosthenes\n\
    \ * @docs md/math/Eratosthenes.md\n */\ninline static vector<int> Eratosthenes(int\
    \ N) {\n    vector<int> res(N + 1, 1);\n    res[0] = res[1%(N+1)] = 0;\n    for\
    \ (int i = 1; i*i <= N; i++) if (res[i]) for (int j = 2 * i; j <= N; j += i) res[j]\
    \ = 0;\n    return res;\n}\n"
  code: "/*\n * @title Eratosthenes\n * @docs md/math/Eratosthenes.md\n */\ninline\
    \ static vector<int> Eratosthenes(int N) {\n    vector<int> res(N + 1, 1);\n \
    \   res[0] = res[1%(N+1)] = 0;\n    for (int i = 1; i*i <= N; i++) if (res[i])\
    \ for (int j = 2 * i; j <= N; j += i) res[j] = 0;\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Eratosthenes.cpp
  requiredBy: []
  timestamp: '2020-05-24 02:56:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Eratosthenes.test.cpp
documentation_of: lib/math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/lib/math/Eratosthenes.cpp
- /library/lib/math/Eratosthenes.cpp.html
title: Eratosthenes
---
##### api
- Eratosthenes(int N)  
    - コンストラクタ [1,N]の篩を生成  