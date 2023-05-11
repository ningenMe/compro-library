---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/Combination.md
    document_title: "Combination - \u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "#line 1 \"lib/math/Combination.cpp\"\n/*\n * @title Combination -\
    \ \u4E8C\u9805\u4FC2\u6570\n * @docs md/math/Combination.md\n */\ntemplate<class\
    \ T> class Combination{\n    vector<vector<T>> num;\npublic:\n    //O(N^2)\n \
    \   Combination(int N):num(N+1,vector<T>(N+1,(T)0)){\n        num[0][0] = 1;\n\
    \        for (int n = 1; n <= N; n++) {\n            for (int k = 0; k <= n; k++)\
    \ {\n                num[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0));\n  \
    \          }\n        }\n    }\n    inline T binom(int n, int k) {\n        return\
    \ ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);\n    }\n    //nCk mod p (p is prime\
    \ & p <= N)\n    inline T lucas(int n, int k, long long p) {\n        long long\
    \ res=1;\n        for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p]) %= p;\n        return\
    \ res;\n    }\n};\n"
  code: "/*\n * @title Combination - \u4E8C\u9805\u4FC2\u6570\n * @docs md/math/Combination.md\n\
    \ */\ntemplate<class T> class Combination{\n    vector<vector<T>> num;\npublic:\n\
    \    //O(N^2)\n    Combination(int N):num(N+1,vector<T>(N+1,(T)0)){\n        num[0][0]\
    \ = 1;\n        for (int n = 1; n <= N; n++) {\n            for (int k = 0; k\
    \ <= n; k++) {\n                num[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0));\n\
    \            }\n        }\n    }\n    inline T binom(int n, int k) {\n       \
    \ return ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);\n    }\n    //nCk mod p\
    \ (p is prime & p <= N)\n    inline T lucas(int n, int k, long long p) {\n   \
    \     long long res=1;\n        for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p]) %=\
    \ p;\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Combination.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Combination.cpp
layout: document
redirect_from:
- /library/lib/math/Combination.cpp
- /library/lib/math/Combination.cpp.html
title: "Combination - \u4E8C\u9805\u4FC2\u6570"
---
### Combination
- 二項係数を返す

### コンストラクタ
- Combination(int N)
  - binom(N,K)を愚直に前計算する 

### メソッド
- T binom(int n, int k)
  - 二項係数nCkを返す
  - $O(1)$

- T lucas(int n, int k, long long p)
  - ルーカスの定理によって、nCk mod pを返す。
  - コンストラクタで渡したNに対して、p <= Nである必要がある
  - n,kの値はなんでもよい。(p < n, p < kでもok）
  - $O(\log(n))$

### 参考資料
- [C - ゲーマーじゃんけん](https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3)
- [B - 123 Triangle](https://atcoder.jp/contests/agc043/tasks/agc043_b)
- [C - Tricolor Pyramid](https://atcoder.jp/contests/arc117/tasks/arc117_c)
