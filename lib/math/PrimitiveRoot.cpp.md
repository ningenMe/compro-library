---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/PrimitiveRoot.md
    document_title: "PrimitiveRoot - \u539F\u59CB\u6839"
    links: []
  bundledCode: "#line 1 \"lib/math/PrimitiveRoot.cpp\"\n/*\n * @title PrimitiveRoot\
    \ - \u539F\u59CB\u6839\n * @docs md/math/PrimitiveRoot.md\n */\nclass PrimitiveRoot{\n\
    \    inline static constexpr long long pow_mod_constexpr(long long x, long long\
    \ n, int m) {\n        if (m == 1) return 0;\n        unsigned int _m = (unsigned\
    \ int)(m);\n        unsigned long long r = 1;\n        unsigned long long y =\
    \ x;\n        y %= m;\n        if(x < 0) x += m;\n        while (n) {\n      \
    \      if (n & 1) r = (r * y) % _m;\n            y = (y * y) % _m;\n         \
    \   n >>= 1;\n        }\n        return r;\n    }\npublic:\n    inline static\
    \ long long root(long long p) {\n        if(p == 2) return 1;\n        if(p ==\
    \ 167772161) return 3;\n        if(p == 469762049) return 3;\n        if(p ==\
    \ 754974721) return 11;\n        if(p == 998244353) return 3;\n        if(p ==\
    \ 1000000007) return 5;\n        if(p == 1004535809) return 3;\n        array<int,20>\
    \ divs;\n        divs[0] = 2;\n        int cnt = 1;\n        int x = (p - 1) >>\
    \ 1;\n        while (!(x&1)) x >>= 1;\n        for (long long i = 3; i*i <= x;\
    \ i += 2) {\n            if (x % i == 0) {\n                divs[cnt++] = i;\n\
    \                while (x % i == 0) x /= i;\n            }\n        }\n      \
    \  if (x > 1) {\n            divs[cnt++] = x;\n        }\n        for (int g =\
    \ 2;; ++g) {\n            bool ok = true;\n            for (int i = 0; i < cnt;\
    \ i++) {\n                if (pow_mod_constexpr(g, (p - 1) / divs[i], p) == 1)\
    \ {\n                    ok = false;\n                    break;\n           \
    \     }\n            }\n            if (ok) return g;\n        }\n    }\n};\n"
  code: "/*\n * @title PrimitiveRoot - \u539F\u59CB\u6839\n * @docs md/math/PrimitiveRoot.md\n\
    \ */\nclass PrimitiveRoot{\n    inline static constexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n        if (m == 1) return 0;\n        unsigned\
    \ int _m = (unsigned int)(m);\n        unsigned long long r = 1;\n        unsigned\
    \ long long y = x;\n        y %= m;\n        if(x < 0) x += m;\n        while\
    \ (n) {\n            if (n & 1) r = (r * y) % _m;\n            y = (y * y) % _m;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\npublic:\n    inline\
    \ static long long root(long long p) {\n        if(p == 2) return 1;\n       \
    \ if(p == 167772161) return 3;\n        if(p == 469762049) return 3;\n       \
    \ if(p == 754974721) return 11;\n        if(p == 998244353) return 3;\n      \
    \  if(p == 1000000007) return 5;\n        if(p == 1004535809) return 3;\n    \
    \    array<int,20> divs;\n        divs[0] = 2;\n        int cnt = 1;\n       \
    \ int x = (p - 1) >> 1;\n        while (!(x&1)) x >>= 1;\n        for (long long\
    \ i = 3; i*i <= x; i += 2) {\n            if (x % i == 0) {\n                divs[cnt++]\
    \ = i;\n                while (x % i == 0) x /= i;\n            }\n        }\n\
    \        if (x > 1) {\n            divs[cnt++] = x;\n        }\n        for (int\
    \ g = 2;; ++g) {\n            bool ok = true;\n            for (int i = 0; i <\
    \ cnt; i++) {\n                if (pow_mod_constexpr(g, (p - 1) / divs[i], p)\
    \ == 1) {\n                    ok = false;\n                    break;\n     \
    \           }\n            }\n            if (ok) return g;\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/PrimitiveRoot.cpp
  requiredBy: []
  timestamp: '2021-09-21 19:35:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/PrimitiveRoot.cpp
layout: document
redirect_from:
- /library/lib/math/PrimitiveRoot.cpp
- /library/lib/math/PrimitiveRoot.cpp.html
title: "PrimitiveRoot - \u539F\u59CB\u6839"
---
### PrimitiveRoot
- 原子根を返す

### コンストラクタ
- なし

### メソッド
- inline static long long root(long long p)
  - 素数pの原子根gを返す。
  - g^0,g^1,g^2,......,g^(p-2),の(p-1)個の数がユニークになる。
  - g^0 = g^(p-1) = 1 であることに注意。
  - gの冪乗の列にはg^x = 0になるようなxはないことに注意。

### 参考資料
- [primitive_root](https://qiita.com/R_olldIce/items/ff38ece900dd41d7178e#2-primitive_root)
- [C - Product Modulo](https://atcoder.jp/contests/agc047/submissions/21743413)
