---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/Prime.md
    document_title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\
      \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 1 \"lib/math/Prime.cpp\"\n/*\n * @title Prime - \u9AD8\u901F\
    \u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\n * @docs md/math/Prime.md\n */\nclass Prime{\n    using int128\
    \ = __int128_t;\n    using int64  = long long;\n    long long pow(long long x,\
    \ long long n, long long mod) {\n        long long res = 1;\n        for (x %=\
    \ mod; n > 0; n >>= 1, x=(int128(x)*x)%mod) if (n & 1) res = (int128(res)*x)%mod;\n\
    \        return res;\n    }\n    int64 rho(int64 n){\n        if(miller_rabin(n))\
    \ return n;\n        if(n%2 == 0) return 2;\n        for(int64 c=1,x=2,y=2,d;;c++){\n\
    \            do{\n                x=(int128(x)*x+c)%n;\n                y=(int128(y)*y+c)%n;\n\
    \                y=(int128(y)*y+c)%n;\n                d=Gcd::gcd(x-y+n,n);\n\
    \            }while(d==1);\n            if(d<n) return d;\n        }\n    }\n\
    \    vector<int64> factor(int64 n) {\n        if(n <= 1) return {};\n        int64\
    \ p = rho(n);\n        if(p == n) return {p};\n        auto l = factor(p);\n \
    \       auto r = factor(n / p);\n        copy(r.begin(), r.end(), back_inserter(l));\n\
    \        return l;\n    }\npublic:\n    int miller_rabin(const int64 n) {\n  \
    \      if(n == 2) return 1;\n        if(n < 2 || n%2 == 0) return 0;\n       \
    \ int64 m = n - 1;\n        for (;!(m&1);m>>=1);\n        for (int64 a: {2,325,9375,28178,450775,9780504,1795265022})\
    \ {\n            if(a>=n) break;\n            int64 x=m,r=pow(a,x,n);\n      \
    \      for(;x != n-1 && r != 1 && r != n-1;x <<= 1) r = (int128(r)*r)%n;\n   \
    \         if(r!=n-1 && x%2==0) return 0;\n        }\n        return 1;\n    }\n\
    \    vector<pair<int64,int64>> factorization(int64 n) {\n        auto v = factor(n);\n\
    \        vector<pair<int64,int64>> vp;\n        sort(v.begin(),v.end());\n   \
    \     int64 prev = 0;\n        for(int64 p:v) {\n            if(p == prev) vp.back().second++;\n\
    \            else vp.emplace_back(p,1);\n            prev=p;\n        }\n    \
    \    return vp;\n    }\n};\n"
  code: "/*\n * @title Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\
    \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\n * @docs md/math/Prime.md\n\
    \ */\nclass Prime{\n    using int128 = __int128_t;\n    using int64  = long long;\n\
    \    long long pow(long long x, long long n, long long mod) {\n        long long\
    \ res = 1;\n        for (x %= mod; n > 0; n >>= 1, x=(int128(x)*x)%mod) if (n\
    \ & 1) res = (int128(res)*x)%mod;\n        return res;\n    }\n    int64 rho(int64\
    \ n){\n        if(miller_rabin(n)) return n;\n        if(n%2 == 0) return 2;\n\
    \        for(int64 c=1,x=2,y=2,d;;c++){\n            do{\n                x=(int128(x)*x+c)%n;\n\
    \                y=(int128(y)*y+c)%n;\n                y=(int128(y)*y+c)%n;\n\
    \                d=Gcd::gcd(x-y+n,n);\n            }while(d==1);\n           \
    \ if(d<n) return d;\n        }\n    }\n    vector<int64> factor(int64 n) {\n \
    \       if(n <= 1) return {};\n        int64 p = rho(n);\n        if(p == n) return\
    \ {p};\n        auto l = factor(p);\n        auto r = factor(n / p);\n       \
    \ copy(r.begin(), r.end(), back_inserter(l));\n        return l;\n    }\npublic:\n\
    \    int miller_rabin(const int64 n) {\n        if(n == 2) return 1;\n       \
    \ if(n < 2 || n%2 == 0) return 0;\n        int64 m = n - 1;\n        for (;!(m&1);m>>=1);\n\
    \        for (int64 a: {2,325,9375,28178,450775,9780504,1795265022}) {\n     \
    \       if(a>=n) break;\n            int64 x=m,r=pow(a,x,n);\n            for(;x\
    \ != n-1 && r != 1 && r != n-1;x <<= 1) r = (int128(r)*r)%n;\n            if(r!=n-1\
    \ && x%2==0) return 0;\n        }\n        return 1;\n    }\n    vector<pair<int64,int64>>\
    \ factorization(int64 n) {\n        auto v = factor(n);\n        vector<pair<int64,int64>>\
    \ vp;\n        sort(v.begin(),v.end());\n        int64 prev = 0;\n        for(int64\
    \ p:v) {\n            if(p == prev) vp.back().second++;\n            else vp.emplace_back(p,1);\n\
    \            prev=p;\n        }\n        return vp;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Prime.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Prime.cpp
layout: document
redirect_from:
- /library/lib/math/Prime.cpp
- /library/lib/math/Prime.cpp.html
title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\
  \u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A"
---
