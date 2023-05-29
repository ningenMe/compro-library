---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Garner.test.cpp
    title: test/math/Garner.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: md/math/Garner.md
    document_title: "Garner - \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Garner.cpp\"\n/*\n * @title Garner - \u4E2D\u56FD\
    \u5270\u4F59\u5B9A\u7406\n * @docs md/math/Garner.md\n */\nclass Garner{\n   \
    \ inline static constexpr long long gcd(long long a, long long b) {\n        return\
    \ (b ? gcd(b, a % b):a);\n    }\n    inline static long long ext_gcd(long long\
    \ a, long long b, long long &x, long long &y) {\n        long long res;\n    \
    \    if (b == 0) res = a,x = 1,y = 0;\n        else res = ext_gcd(b, a%b, y, x),\
    \ y -= a/b * x;\n        return res;\n    }\n    inline static long long inv_mod(long\
    \ long a, long long b) {\n        long long x, y;\n        ext_gcd(a, b, x, y);\n\
    \        return (x%b+b)%b;\n    }\npublic:\n    // O(N^2) x mod m_i = b_i \u306A\
    \u308B x \u3092\u8FD4\u5374\u3000, b_i\u304C\u3059\u3079\u30660\u306E\u3068\u304D\
    \u306F0\u3067\u306F\u306A\u304Fm_i\u306Elcm\u3092\u8FD4\u3059\n    // return x\n\
    \    inline static long long garner(vector<long long> b, vector<long long> m,\
    \ long long mod){\n        int N=b.size();\n        vector<long long> coe(N+1,1),val(N+1,0);\n\
    \        long long g,gl,gr,sum=accumulate(b.begin(),b.end(),0LL);\n        //\u4E92\
    \u3044\u306B\u7D20\u306B\u306A\u308B\u3088\u3046\u306B\u51E6\u7406\n        for\
    \ (int l = 0; l < N; ++l) {\n            for (int r = l+1; r < N; ++r) {\n   \
    \             g = gcd(m[l], m[r]);\n                if (sum && (b[l] - b[r]) %\
    \ g != 0) return -1;\n                m[l] /= g, m[r] /= g;\n                gl\
    \ = gcd(m[l], g), gr = g/gl;\n                do {\n                    g = gcd(gl,\
    \ gr);\n                    gl *= g, gr /= g;\n                } while (g != 1);\n\
    \                m[l] *= gl, m[r] *= gr;\n                b[l] %= m[l], b[r] %=\
    \ m[r];\n            }\n        }\n        if(!sum) {\n            long long lcm\
    \ = 1;\n            for(auto& e:m) (lcm*=e)%=mod;\n            return lcm;\n \
    \       }\n        m.push_back(mod);\n        for(int i = 0; i < N; ++i) {\n \
    \           long long t = (b[i] - val[i]) * inv_mod(coe[i], m[i]);\n         \
    \   ((t %= m[i]) += m[i]) %= m[i];\n            for (int j = i+1; j <= N; ++j)\
    \ {\n                (val[j] += t * coe[j]) %= m[j];\n                (coe[j]\
    \ *= m[i]) %= m[j];\n            }\n        }\n        return val.back();\n  \
    \  }\n};\n"
  code: "/*\n * @title Garner - \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n * @docs md/math/Garner.md\n\
    \ */\nclass Garner{\n    inline static constexpr long long gcd(long long a, long\
    \ long b) {\n        return (b ? gcd(b, a % b):a);\n    }\n    inline static long\
    \ long ext_gcd(long long a, long long b, long long &x, long long &y) {\n     \
    \   long long res;\n        if (b == 0) res = a,x = 1,y = 0;\n        else res\
    \ = ext_gcd(b, a%b, y, x), y -= a/b * x;\n        return res;\n    }\n    inline\
    \ static long long inv_mod(long long a, long long b) {\n        long long x, y;\n\
    \        ext_gcd(a, b, x, y);\n        return (x%b+b)%b;\n    }\npublic:\n   \
    \ // O(N^2) x mod m_i = b_i \u306A\u308B x \u3092\u8FD4\u5374\u3000, b_i\u304C\
    \u3059\u3079\u30660\u306E\u3068\u304D\u306F0\u3067\u306F\u306A\u304Fm_i\u306E\
    lcm\u3092\u8FD4\u3059\n    // return x\n    inline static long long garner(vector<long\
    \ long> b, vector<long long> m, long long mod){\n        int N=b.size();\n   \
    \     vector<long long> coe(N+1,1),val(N+1,0);\n        long long g,gl,gr,sum=accumulate(b.begin(),b.end(),0LL);\n\
    \        //\u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u3088\u3046\u306B\u51E6\u7406\
    \n        for (int l = 0; l < N; ++l) {\n            for (int r = l+1; r < N;\
    \ ++r) {\n                g = gcd(m[l], m[r]);\n                if (sum && (b[l]\
    \ - b[r]) % g != 0) return -1;\n                m[l] /= g, m[r] /= g;\n      \
    \          gl = gcd(m[l], g), gr = g/gl;\n                do {\n             \
    \       g = gcd(gl, gr);\n                    gl *= g, gr /= g;\n            \
    \    } while (g != 1);\n                m[l] *= gl, m[r] *= gr;\n            \
    \    b[l] %= m[l], b[r] %= m[r];\n            }\n        }\n        if(!sum) {\n\
    \            long long lcm = 1;\n            for(auto& e:m) (lcm*=e)%=mod;\n \
    \           return lcm;\n        }\n        m.push_back(mod);\n        for(int\
    \ i = 0; i < N; ++i) {\n            long long t = (b[i] - val[i]) * inv_mod(coe[i],\
    \ m[i]);\n            ((t %= m[i]) += m[i]) %= m[i];\n            for (int j =\
    \ i+1; j <= N; ++j) {\n                (val[j] += t * coe[j]) %= m[j];\n     \
    \           (coe[j] *= m[i]) %= m[j];\n            }\n        }\n        return\
    \ val.back();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Garner.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/Garner.test.cpp
documentation_of: lib/30-math/Garner.cpp
layout: document
redirect_from:
- /library/lib/30-math/Garner.cpp
- /library/lib/30-math/Garner.cpp.html
title: "Garner - \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
