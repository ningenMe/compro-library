---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-prefix-binary-search.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/SegmentTree-suffix-binary-search.test.cpp
    title: test/data-structure/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-miller-rabin.test.cpp
    title: test/math/Prime-miller-rabin.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-rho.test.cpp
    title: test/math/Prime-rho.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/Gcd.md
    document_title: "Gcd - \u9AD8\u901FGCD"
    links: []
  bundledCode: "#line 1 \"lib/math/Gcd.cpp\"\n/*\n * @title Gcd - \u9AD8\u901FGCD\n\
    \ * @docs md/math/Gcd.md\n */\nclass Gcd{\npublic:\n\tinline static long long\
    \ impl(long long n, long long m) {\n\t\tstatic constexpr long long K = 5;\n\t\t\
    long long t,s;\n\t\tfor(int i = 0; t = n - m, s = n - m * K, i < 80; ++i) {\n\t\
    \t\tif(t<m){\n\t\t\t\tif(!t) return m;\n\t\t\t\tn = m, m = t;\n\t\t\t}\n\t\t\t\
    else{\n\t\t\t\tif(!m) return t;\n\t\t\t\tn=t;\n\t\t\t\tif(t >= m * K) n = s;\n\
    \t\t\t}\n\t\t}\n\t\treturn impl(m, n % m);\n\t}\n\tinline static long long pre(long\
    \ long n, long long m) {\n\t\tlong long t;\n\t\tfor(int i = 0; t = n - m, i <\
    \ 4; ++i) {\n\t\t\t(t < m ? n=m,m=t : n=t);\n\t\t\tif(!m) return n;\n\t\t}\n\t\
    \treturn impl(n, m);\n\t}\n\tinline static long long gcd(long long n, long long\
    \ m) {\n\t\treturn (n>m ? pre(n,m) : pre(m,n));\n\t}\n\tinline static constexpr\
    \ long long pureGcd(long long a, long long b) {\n\t\treturn (b ? pureGcd(b, a\
    \ % b):a);\n\t}\n\tinline static constexpr long long lcm(long long a, long long\
    \ b) {\n\t\treturn (a*b ? (a / gcd(a, b)*b): 0);\n\t}\n\tinline static constexpr\
    \ long long extGcd(long long a, long long b, long long &x, long long &y) {\n\t\
    \tif (b == 0) return x = 1, y = 0, a;\n\t\tlong long d = extGcd(b, a%b, y, x);\n\
    \t\treturn y -= a / b * x, d;\n\t}\n};\n"
  code: "/*\n * @title Gcd - \u9AD8\u901FGCD\n * @docs md/math/Gcd.md\n */\nclass\
    \ Gcd{\npublic:\n\tinline static long long impl(long long n, long long m) {\n\t\
    \tstatic constexpr long long K = 5;\n\t\tlong long t,s;\n\t\tfor(int i = 0; t\
    \ = n - m, s = n - m * K, i < 80; ++i) {\n\t\t\tif(t<m){\n\t\t\t\tif(!t) return\
    \ m;\n\t\t\t\tn = m, m = t;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tif(!m) return t;\n\t\
    \t\t\tn=t;\n\t\t\t\tif(t >= m * K) n = s;\n\t\t\t}\n\t\t}\n\t\treturn impl(m,\
    \ n % m);\n\t}\n\tinline static long long pre(long long n, long long m) {\n\t\t\
    long long t;\n\t\tfor(int i = 0; t = n - m, i < 4; ++i) {\n\t\t\t(t < m ? n=m,m=t\
    \ : n=t);\n\t\t\tif(!m) return n;\n\t\t}\n\t\treturn impl(n, m);\n\t}\n\tinline\
    \ static long long gcd(long long n, long long m) {\n\t\treturn (n>m ? pre(n,m)\
    \ : pre(m,n));\n\t}\n\tinline static constexpr long long pureGcd(long long a,\
    \ long long b) {\n\t\treturn (b ? pureGcd(b, a % b):a);\n\t}\n\tinline static\
    \ constexpr long long lcm(long long a, long long b) {\n\t\treturn (a*b ? (a /\
    \ gcd(a, b)*b): 0);\n\t}\n\tinline static constexpr long long extGcd(long long\
    \ a, long long b, long long &x, long long &y) {\n\t\tif (b == 0) return x = 1,\
    \ y = 0, a;\n\t\tlong long d = extGcd(b, a%b, y, x);\n\t\treturn y -= a / b *\
    \ x, d;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Gcd.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:29:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Prime-rho.test.cpp
  - test/math/Prime-miller-rabin.test.cpp
  - test/data-structure/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  - test/data-structure/segment-tree/SegmentTree-prefix-binary-search.test.cpp
documentation_of: lib/math/Gcd.cpp
layout: document
redirect_from:
- /library/lib/math/Gcd.cpp
- /library/lib/math/Gcd.cpp.html
title: "Gcd - \u9AD8\u901FGCD"
---
