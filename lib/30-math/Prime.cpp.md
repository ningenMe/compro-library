---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Prime-miller-rabin-1.test.cpp
    title: test/math/Prime-miller-rabin-1.test.cpp
  - icon: ':x:'
    path: test/math/Prime-miller-rabin-2.test.cpp
    title: test/math/Prime-miller-rabin-2.test.cpp
  - icon: ':x:'
    path: test/math/Prime-rho.test.cpp
    title: test/math/Prime-rho.test.cpp
  - icon: ':x:'
    path: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
    title: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  - icon: ':x:'
    path: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
    title: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: md/math/Prime.md
    document_title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\
      \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Prime.cpp\"\n/*\n * @title Prime - \u9AD8\u901F\
    \u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\u30FBGcd\u30FBLcm\n * @docs md/math/Prime.md\n */\nclass Prime{\n\
    \    using int128 = __int128_t;\n    using int64  = long long;\n    using u64\
    \ = unsigned long long;\n    using u32 = unsigned int;\n    inline static long\
    \ long gcd_impl(long long n, long long m) {\n        static constexpr long long\
    \ K = 5;\n        long long t,s;\n        for(int i = 0; t = n - m, s = n - m\
    \ * K, i < 80; ++i) {\n            if(t<m){\n                if(!t) return m;\n\
    \                n = m, m = t;\n            }\n            else{\n           \
    \     if(!m) return t;\n                n=t;\n                if(t >= m * K) n\
    \ = s;\n            }\n        }\n        return gcd_impl(m, n % m);\n    }\n\
    \    inline static constexpr long long pre(long long n, long long m) {\n     \
    \   long long t = n - m;\n        for(int i = 0; t = n - m, i < 4; ++i) {\n  \
    \          (t < m ? n=m,m=t : n=t);\n            if(!m) return n;\n        }\n\
    \        return gcd_impl(n, m);\n    }\n    inline static constexpr long long\
    \ pow(long long x, long long n, long long mod) {\n        long long res = 1;\n\
    \        for (x %= mod; n > 0; n >>= 1, x=(int128(x)*x)%mod) if (n & 1) res =\
    \ (int128(res)*x)%mod;\n        return res;\n    }\n    inline static constexpr\
    \ array<u64,3> ar1={2ULL, 7ULL, 61ULL};\n    inline static constexpr array<u64,7>\
    \ ar2={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};\n   \
    \ inline static constexpr int64 rho(int64 n){\n        if(miller_rabin(n)) return\
    \ n;\n        if(n%2 == 0) return 2;\n        for(int64 c=1,x=2,y=2,d=0;;c++){\n\
    \            do{\n                x=(int128(x)*x+c)%n;\n                y=(int128(y)*y+c)%n;\n\
    \                y=(int128(y)*y+c)%n;\n                d=gcd(x-y+n,n);\n     \
    \       }while(d==1);\n            if(d<n) return d;\n        }\n    }\n    inline\
    \ static vector<int64> factor(const int64 n) {\n        if(n <= 1) return {};\n\
    \        int64 p = rho(n);\n        if(p == n) return {p};\n        auto l = factor(p);\n\
    \        auto r = factor(n / p);\n        copy(r.begin(), r.end(), back_inserter(l));\n\
    \        return l;\n    }\n    template<size_t sz> inline static constexpr bool\
    \ miller_rabin(const u64& n, const array<u64,sz>& ar) {\n        u32 i,s=0; \n\
    \        u64 m = n - 1;\n        for (;!(m&1);++s,m>>=1);\n        for (const\
    \ u64& a: ar) {\n            if(a>=n) break;\n            u64 r=pow(a,m,n);\n\
    \            if(r != 1) {\n                for(i=0; i<s; ++i) {\n            \
    \        if(r == n-1) break;\n                    r = (int128(r)*r)%n;\n     \
    \           }\n                if(i==s) return false;\n            }\n       \
    \ }\n        return true;\n    }\n    inline static constexpr bool miller_rabin(const\
    \ u64 n) {\n        if(n <= 1) return false;\n        if(n == 2) return true;\n\
    \        if(n%2 == 0) return false;\n        if(n == 3) return true;\n       \
    \ if(n%3 == 0) return false;\n        if(n < 4759123141LL) return miller_rabin(n,\
    \ ar1);\n        return miller_rabin(n, ar2);\n    }\n    inline static vector<pair<int64,int64>>\
    \ factorization_impl(const int64 n) {\n        auto v = factor(n);\n        vector<pair<int64,int64>>\
    \ vp;\n        sort(v.begin(),v.end());\n        int64 prev = 0;\n        for(int64\
    \ p:v) {\n            if(p == prev) vp.back().second++;\n            else vp.emplace_back(p,1);\n\
    \            prev=p;\n        }\n        return vp;\n    }\npublic:\n    inline\
    \ static constexpr bool is_prime(const u64 n) { return is_prime(n); }\n    inline\
    \ static vector<pair<int64,int64>> factorization(const int64 n) {return factorization_impl(n);}\n\
    \    inline static constexpr long long gcd(long long n, long long m) { return\
    \ (n>m ? pre(n,m) : pre(m,n));}\n    inline static constexpr long long naive_gcd(long\
    \ long a, long long b) { return (b ? naive_gcd(b, a % b):a);}\n    inline static\
    \ constexpr long long lcm(long long a, long long b) {return (a*b ? (a / gcd(a,\
    \ b)*b): 0);}\n    inline static constexpr long long ext_gcd(long long a, long\
    \ long b, long long &x, long long &y) {\n        if (b == 0) return x = 1, y =\
    \ 0, a; long long d = ext_gcd(b, a%b, y, x); return y -= a / b * x, d;\n    }\n\
    };\n"
  code: "/*\n * @title Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\
    \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm\n * @docs\
    \ md/math/Prime.md\n */\nclass Prime{\n    using int128 = __int128_t;\n    using\
    \ int64  = long long;\n    using u64 = unsigned long long;\n    using u32 = unsigned\
    \ int;\n    inline static long long gcd_impl(long long n, long long m) {\n   \
    \     static constexpr long long K = 5;\n        long long t,s;\n        for(int\
    \ i = 0; t = n - m, s = n - m * K, i < 80; ++i) {\n            if(t<m){\n    \
    \            if(!t) return m;\n                n = m, m = t;\n            }\n\
    \            else{\n                if(!m) return t;\n                n=t;\n \
    \               if(t >= m * K) n = s;\n            }\n        }\n        return\
    \ gcd_impl(m, n % m);\n    }\n    inline static constexpr long long pre(long long\
    \ n, long long m) {\n        long long t = n - m;\n        for(int i = 0; t =\
    \ n - m, i < 4; ++i) {\n            (t < m ? n=m,m=t : n=t);\n            if(!m)\
    \ return n;\n        }\n        return gcd_impl(n, m);\n    }\n    inline static\
    \ constexpr long long pow(long long x, long long n, long long mod) {\n       \
    \ long long res = 1;\n        for (x %= mod; n > 0; n >>= 1, x=(int128(x)*x)%mod)\
    \ if (n & 1) res = (int128(res)*x)%mod;\n        return res;\n    }\n    inline\
    \ static constexpr array<u64,3> ar1={2ULL, 7ULL, 61ULL};\n    inline static constexpr\
    \ array<u64,7> ar2={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};\n\
    \    inline static constexpr int64 rho(int64 n){\n        if(miller_rabin(n))\
    \ return n;\n        if(n%2 == 0) return 2;\n        for(int64 c=1,x=2,y=2,d=0;;c++){\n\
    \            do{\n                x=(int128(x)*x+c)%n;\n                y=(int128(y)*y+c)%n;\n\
    \                y=(int128(y)*y+c)%n;\n                d=gcd(x-y+n,n);\n     \
    \       }while(d==1);\n            if(d<n) return d;\n        }\n    }\n    inline\
    \ static vector<int64> factor(const int64 n) {\n        if(n <= 1) return {};\n\
    \        int64 p = rho(n);\n        if(p == n) return {p};\n        auto l = factor(p);\n\
    \        auto r = factor(n / p);\n        copy(r.begin(), r.end(), back_inserter(l));\n\
    \        return l;\n    }\n    template<size_t sz> inline static constexpr bool\
    \ miller_rabin(const u64& n, const array<u64,sz>& ar) {\n        u32 i,s=0; \n\
    \        u64 m = n - 1;\n        for (;!(m&1);++s,m>>=1);\n        for (const\
    \ u64& a: ar) {\n            if(a>=n) break;\n            u64 r=pow(a,m,n);\n\
    \            if(r != 1) {\n                for(i=0; i<s; ++i) {\n            \
    \        if(r == n-1) break;\n                    r = (int128(r)*r)%n;\n     \
    \           }\n                if(i==s) return false;\n            }\n       \
    \ }\n        return true;\n    }\n    inline static constexpr bool miller_rabin(const\
    \ u64 n) {\n        if(n <= 1) return false;\n        if(n == 2) return true;\n\
    \        if(n%2 == 0) return false;\n        if(n == 3) return true;\n       \
    \ if(n%3 == 0) return false;\n        if(n < 4759123141LL) return miller_rabin(n,\
    \ ar1);\n        return miller_rabin(n, ar2);\n    }\n    inline static vector<pair<int64,int64>>\
    \ factorization_impl(const int64 n) {\n        auto v = factor(n);\n        vector<pair<int64,int64>>\
    \ vp;\n        sort(v.begin(),v.end());\n        int64 prev = 0;\n        for(int64\
    \ p:v) {\n            if(p == prev) vp.back().second++;\n            else vp.emplace_back(p,1);\n\
    \            prev=p;\n        }\n        return vp;\n    }\npublic:\n    inline\
    \ static constexpr bool is_prime(const u64 n) { return is_prime(n); }\n    inline\
    \ static vector<pair<int64,int64>> factorization(const int64 n) {return factorization_impl(n);}\n\
    \    inline static constexpr long long gcd(long long n, long long m) { return\
    \ (n>m ? pre(n,m) : pre(m,n));}\n    inline static constexpr long long naive_gcd(long\
    \ long a, long long b) { return (b ? naive_gcd(b, a % b):a);}\n    inline static\
    \ constexpr long long lcm(long long a, long long b) {return (a*b ? (a / gcd(a,\
    \ b)*b): 0);}\n    inline static constexpr long long ext_gcd(long long a, long\
    \ long b, long long &x, long long &y) {\n        if (b == 0) return x = 1, y =\
    \ 0, a; long long d = ext_gcd(b, a%b, y, x); return y -= a / b * x, d;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Prime.cpp
  requiredBy: []
  timestamp: '2023-05-31 05:05:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  - test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  - test/math/Prime-miller-rabin-1.test.cpp
  - test/math/Prime-rho.test.cpp
  - test/math/Prime-miller-rabin-2.test.cpp
documentation_of: lib/30-math/Prime.cpp
layout: document
redirect_from:
- /library/lib/30-math/Prime.cpp
- /library/lib/30-math/Prime.cpp.html
title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\
  \u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm"
---
