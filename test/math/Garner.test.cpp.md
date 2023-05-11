---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/math/Garner.cpp
    title: "Garner - \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/448
    links:
    - https://yukicoder.me/problems/448
  bundledCode: "#line 1 \"test/math/Garner.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/448\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\nusing namespace\
    \ std;\n#line 1 \"lib/math/Garner.cpp\"\n/*\n * @title Garner - \u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\n * @docs md/math/Garner.md\n */\nclass Garner{\n    inline\
    \ static constexpr long long gcd(long long a, long long b) {\n        return (b\
    \ ? gcd(b, a % b):a);\n    }\n    inline static long long ext_gcd(long long a,\
    \ long long b, long long &x, long long &y) {\n        long long res;\n       \
    \ if (b == 0) res = a,x = 1,y = 0;\n        else res = ext_gcd(b, a%b, y, x),\
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
    \  }\n};\n#line 8 \"test/math/Garner.test.cpp\"\nconstexpr long long MOD = 1000'000'007;\n\
    \nint main(void){\n    int N; cin >> N;\n\tvector<long long> b(N), m(N);\n\tfor(int\
    \ i = 0; i < N; ++i){\n\t\tcin >> b[i] >> m[i];\n\t}\n\tcout << Garner::garner(b,m,MOD)\
    \ << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/448\"\n\n#include <vector>\n\
    #include <iostream>\n#include <numeric>\nusing namespace std;\n#include \"../../lib/math/Garner.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\n\nint main(void){\n    int N; cin >>\
    \ N;\n\tvector<long long> b(N), m(N);\n\tfor(int i = 0; i < N; ++i){\n\t\tcin\
    \ >> b[i] >> m[i];\n\t}\n\tcout << Garner::garner(b,m,MOD) << endl;\n\treturn\
    \ 0;\n}"
  dependsOn:
  - lib/math/Garner.cpp
  isVerificationFile: true
  path: test/math/Garner.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:44:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Garner.test.cpp
layout: document
redirect_from:
- /verify/test/math/Garner.test.cpp
- /verify/test/math/Garner.test.cpp.html
title: test/math/Garner.test.cpp
---
