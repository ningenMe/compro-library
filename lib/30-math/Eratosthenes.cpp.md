---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Eratosthenes.test.cpp
    title: test/math/Eratosthenes.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/Eratosthenes.md
    document_title: "Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Eratosthenes.cpp\"\n/*\n * @title Eratosthenes\
    \ - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n * @docs md/math/Eratosthenes.md\n\
    \ */\ninline static vector<int> Eratosthenes(int N) {\n    vector<int> res(N +\
    \ 1, 1);\n    res[0] = res[1%(N+1)] = 0;\n    for (int i = 1; i*i <= N; i++) if\
    \ (res[i]) for (int j = 2 * i; j <= N; j += i) res[j] = 0;\n    return res;\n\
    }\n"
  code: "/*\n * @title Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9\n * @docs md/math/Eratosthenes.md\n */\ninline static vector<int> Eratosthenes(int\
    \ N) {\n    vector<int> res(N + 1, 1);\n    res[0] = res[1%(N+1)] = 0;\n    for\
    \ (int i = 1; i*i <= N; i++) if (res[i]) for (int j = 2 * i; j <= N; j += i) res[j]\
    \ = 0;\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Eratosthenes.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Eratosthenes.test.cpp
documentation_of: lib/30-math/Eratosthenes.cpp
layout: document
redirect_from:
- /library/lib/30-math/Eratosthenes.cpp
- /library/lib/30-math/Eratosthenes.cpp.html
title: "Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
##### api
- Eratosthenes(int N)  
    - コンストラクタ [1,N]の篩を生成  