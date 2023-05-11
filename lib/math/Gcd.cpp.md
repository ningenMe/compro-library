---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/Gcd.md
    document_title: "Gcd - \u9AD8\u901FGCD"
    links: []
  bundledCode: "#line 1 \"lib/math/Gcd.cpp\"\n/*\n * @title Gcd - \u9AD8\u901FGCD\n\
    \ * @docs md/math/Gcd.md\n */\nclass Gcd{\npublic:\n    inline static long long\
    \ impl(long long n, long long m) {\n        static constexpr long long K = 5;\n\
    \        long long t,s;\n        for(int i = 0; t = n - m, s = n - m * K, i <\
    \ 80; ++i) {\n            if(t<m){\n                if(!t) return m;\n       \
    \         n = m, m = t;\n            }\n            else{\n                if(!m)\
    \ return t;\n                n=t;\n                if(t >= m * K) n = s;\n   \
    \         }\n        }\n        return impl(m, n % m);\n    }\n    inline static\
    \ long long pre(long long n, long long m) {\n        long long t;\n        for(int\
    \ i = 0; t = n - m, i < 4; ++i) {\n            (t < m ? n=m,m=t : n=t);\n    \
    \        if(!m) return n;\n        }\n        return impl(n, m);\n    }\n    inline\
    \ static long long gcd(long long n, long long m) {\n        return (n>m ? pre(n,m)\
    \ : pre(m,n));\n    }\n    inline static constexpr long long pureGcd(long long\
    \ a, long long b) {\n        return (b ? pureGcd(b, a % b):a);\n    }\n    inline\
    \ static constexpr long long lcm(long long a, long long b) {\n        return (a*b\
    \ ? (a / gcd(a, b)*b): 0);\n    }\n    inline static constexpr long long extGcd(long\
    \ long a, long long b, long long &x, long long &y) {\n        if (b == 0) return\
    \ x = 1, y = 0, a;\n        long long d = extGcd(b, a%b, y, x);\n        return\
    \ y -= a / b * x, d;\n    }\n};\n"
  code: "/*\n * @title Gcd - \u9AD8\u901FGCD\n * @docs md/math/Gcd.md\n */\nclass\
    \ Gcd{\npublic:\n    inline static long long impl(long long n, long long m) {\n\
    \        static constexpr long long K = 5;\n        long long t,s;\n        for(int\
    \ i = 0; t = n - m, s = n - m * K, i < 80; ++i) {\n            if(t<m){\n    \
    \            if(!t) return m;\n                n = m, m = t;\n            }\n\
    \            else{\n                if(!m) return t;\n                n=t;\n \
    \               if(t >= m * K) n = s;\n            }\n        }\n        return\
    \ impl(m, n % m);\n    }\n    inline static long long pre(long long n, long long\
    \ m) {\n        long long t;\n        for(int i = 0; t = n - m, i < 4; ++i) {\n\
    \            (t < m ? n=m,m=t : n=t);\n            if(!m) return n;\n        }\n\
    \        return impl(n, m);\n    }\n    inline static long long gcd(long long\
    \ n, long long m) {\n        return (n>m ? pre(n,m) : pre(m,n));\n    }\n    inline\
    \ static constexpr long long pureGcd(long long a, long long b) {\n        return\
    \ (b ? pureGcd(b, a % b):a);\n    }\n    inline static constexpr long long lcm(long\
    \ long a, long long b) {\n        return (a*b ? (a / gcd(a, b)*b): 0);\n    }\n\
    \    inline static constexpr long long extGcd(long long a, long long b, long long\
    \ &x, long long &y) {\n        if (b == 0) return x = 1, y = 0, a;\n        long\
    \ long d = extGcd(b, a%b, y, x);\n        return y -= a / b * x, d;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Gcd.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Gcd.cpp
layout: document
redirect_from:
- /library/lib/math/Gcd.cpp
- /library/lib/math/Gcd.cpp.html
title: "Gcd - \u9AD8\u901FGCD"
---
