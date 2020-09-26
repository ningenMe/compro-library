---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/Garner.cpp
    title: "Garner - \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/448
    links:
    - https://yukicoder.me/problems/448
  bundledCode: "#line 1 \"test/math/Garner.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/448\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\nusing namespace\
    \ std;\n#line 1 \"lib/math/Garner.cpp\"\n/*\n * @title Garner - \u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\n * @docs md/math/Garner.md\n */\nclass Garner{\n\tinline static\
    \ constexpr long long gcd(long long a, long long b) {\n\t\treturn (b ? gcd(b,\
    \ a % b):a);\n\t}\n\tinline static long long ext_gcd(long long a, long long b,\
    \ long long &x, long long &y) {\n\t\tlong long res;\n\t\tif (b == 0) res = a,x\
    \ = 1,y = 0;\n\t\telse res = ext_gcd(b, a%b, y, x), y -= a/b * x;\n\t\treturn\
    \ res;\n\t}\n\tinline static long long inv_mod(long long a, long long b) {\n\t\
    \tlong long x, y;\n\t\text_gcd(a, b, x, y);\n\t\treturn (x%b+b)%b;\n\t}\npublic:\n\
    \t// O(N^2) x mod m_i = b_i \u306A\u308B x \u3092\u8FD4\u5374\u3000, b_i\u304C\
    \u3059\u3079\u30660\u306E\u3068\u304D\u306F0\u3067\u306F\u306A\u304Fm_i\u306E\
    lcm\u3092\u8FD4\u3059\n\t// return x\n\tinline static long long garner(vector<long\
    \ long> b, vector<long long> m, long long mod){\n\t\tint N=b.size();\n\t\tvector<long\
    \ long> coe(N+1,1),val(N+1,0);\n\t\tlong long g,gl,gr,sum=accumulate(b.begin(),b.end(),0LL);\n\
    \t\t//\u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u3088\u3046\u306B\u51E6\u7406\
    \n\t\tfor (int l = 0; l < N; ++l) {\n\t\t\tfor (int r = l+1; r < N; ++r) {\n\t\
    \t\t\tg = gcd(m[l], m[r]);\n\t\t\t\tif (sum && (b[l] - b[r]) % g != 0) return\
    \ -1;\n\t\t\t\tm[l] /= g, m[r] /= g;\n\t\t\t\tgl = gcd(m[l], g), gr = g/gl;\n\t\
    \t\t\tdo {\n\t\t\t\t\tg = gcd(gl, gr);\n\t\t\t\t\tgl *= g, gr /= g;\n\t\t\t\t\
    } while (g != 1);\n\t\t\t\tm[l] *= gl, m[r] *= gr;\n\t\t\t\tb[l] %= m[l], b[r]\
    \ %= m[r];\n\t\t\t}\n\t\t}\n\t\tif(!sum) {\n\t\t\tlong long lcm = 1;\n\t\t\tfor(auto&\
    \ e:m) (lcm*=e)%=mod;\n\t\t\treturn lcm;\n\t\t}\n\t\tm.push_back(mod);\n\t\tfor(int\
    \ i = 0; i < N; ++i) {\n\t\t\tlong long t = (b[i] - val[i]) * inv_mod(coe[i],\
    \ m[i]);\n\t\t\t((t %= m[i]) += m[i]) %= m[i];\n\t\t\tfor (int j = i+1; j <= N;\
    \ ++j) {\n\t\t\t\t(val[j] += t * coe[j]) %= m[j];\n\t\t\t\t(coe[j] *= m[i]) %=\
    \ m[j];\n\t\t\t}\n\t\t}\n\t\treturn val.back();\n\t}\n};\n#line 8 \"test/math/Garner.test.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\n\nint main(void){\n    int N; cin >>\
    \ N;\n\tvector<long long> b(N), m(N);\n\tfor(int i = 0; i < N; ++i){\n\t\tcin\
    \ >> b[i] >> m[i];\n\t}\n\tcout << Garner::garner(b,m,MOD) << endl;\n\treturn\
    \ 0;\n}\n"
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
  timestamp: '2020-09-26 16:29:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Garner.test.cpp
layout: document
redirect_from:
- /verify/test/math/Garner.test.cpp
- /verify/test/math/Garner.test.cpp.html
title: test/math/Garner.test.cpp
---
