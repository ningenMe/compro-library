---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/30-math/Gcd.cpp
    title: "Gcd - \u9AD8\u901FGCD"
  - icon: ':x:'
    path: lib/30-math/Prime.cpp
    title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\
      \u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/3030
    links:
    - https://yukicoder.me/problems/no/3030
  bundledCode: "#line 1 \"test/math/Prime-miller-rabin.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/3030\"\n\n#include <iostream>\n#include <vector>\n\
    #include <algorithm>\nusing namespace std;\n#line 1 \"lib/30-math/Gcd.cpp\"\n\
    /*\n * @title Gcd - \u9AD8\u901FGCD\n * @docs md/math/Gcd.md\n */\nclass Gcd{\n\
    public:\n    inline static long long impl(long long n, long long m) {\n      \
    \  static constexpr long long K = 5;\n        long long t,s;\n        for(int\
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
    \ long d = extGcd(b, a%b, y, x);\n        return y -= a / b * x, d;\n    }\n};\n\
    #line 1 \"lib/30-math/Prime.cpp\"\n/*\n * @title Prime - \u9AD8\u901F\u7D20\u56E0\
    \u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\
    \u5B9A\n * @docs md/math/Prime.md\n */\nclass Prime{\n    using int128 = __int128_t;\n\
    \    using int64  = long long;\n    long long pow(long long x, long long n, long\
    \ long mod) {\n        long long res = 1;\n        for (x %= mod; n > 0; n >>=\
    \ 1, x=(int128(x)*x)%mod) if (n & 1) res = (int128(res)*x)%mod;\n        return\
    \ res;\n    }\n    int64 rho(int64 n){\n        if(miller_rabin(n)) return n;\n\
    \        if(n%2 == 0) return 2;\n        for(int64 c=1,x=2,y=2,d;;c++){\n    \
    \        do{\n                x=(int128(x)*x+c)%n;\n                y=(int128(y)*y+c)%n;\n\
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
    \    return vp;\n    }\n};\n#line 9 \"test/math/Prime-miller-rabin.test.cpp\"\n\
    \nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    long long\
    \ N; cin >> N;\n\tPrime p;\n    for(int i = 0; i < N; ++i) {\n\t\tlong long A;\
    \ cin >> A;\n\t\tcout << A << \" \" << p.miller_rabin(A) << \"\\n\";\n\t}\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/3030\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\nusing namespace std;\n#include \"../../lib/30-math/Gcd.cpp\"\
    \n#include \"../../lib/30-math/Prime.cpp\"\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    long long N; cin >> N;\n\tPrime p;\n    for(int i = 0; i < N; ++i) {\n\t\t\
    long long A; cin >> A;\n\t\tcout << A << \" \" << p.miller_rabin(A) << \"\\n\"\
    ;\n\t}\n\treturn 0;\n}"
  dependsOn:
  - lib/30-math/Gcd.cpp
  - lib/30-math/Prime.cpp
  isVerificationFile: true
  path: test/math/Prime-miller-rabin.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Prime-miller-rabin.test.cpp
layout: document
redirect_from:
- /verify/test/math/Prime-miller-rabin.test.cpp
- /verify/test/math/Prime-miller-rabin.test.cpp.html
title: test/math/Prime-miller-rabin.test.cpp
---
