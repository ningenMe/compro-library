---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/30-math/CombinationMod.cpp
    title: "CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/741
    links:
    - https://yukicoder.me/problems/no/741
  bundledCode: "#line 1 \"test/math/CombinationMod-binom.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/741\"\n\n#include <vector>\n#include <iostream>\n\
    using namespace std;\n#line 1 \"lib/30-math/CombinationMod.cpp\"\n/*\n * @title\
    \ CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57\n\
    \ * @docs md/math/CombinationMod.md\n */\ntemplate<long long mod> class CombinationMod\
    \ {\n    vector<long long> fac,finv,inv;\npublic:\n    CombinationMod(int N) :\
    \ fac(N + 1), finv(N + 1), inv(N + 1) {\n        fac[0] = fac[1] = finv[0] = finv[1]\
    \ = inv[1] = 1;\n        for (int i = 2; i <= N; ++i) {\n            fac[i] =\
    \ fac[i - 1] * i % mod;\n            inv[i] = mod - inv[mod%i] * (mod / i) % mod;\n\
    \            finv[i] = finv[i - 1] * inv[i] % mod;\n        }\n    }\n    inline\
    \ long long binom(int n, int k) {\n        return ((n < 0 || k < 0 || n < k) ?\
    \ 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);\n    }\n    inline long long\
    \ factorial(int n) {\n        return fac[n];\n    }\n};\n\n//verify https://atcoder.jp/contests/abc021/tasks/abc021_d\n\
    #line 7 \"test/math/CombinationMod-binom.test.cpp\"\nconstexpr long long MOD =\
    \ 1000'000'007;\n\nint main(void){\n    int N; cin >> N;\n    CombinationMod<MOD>\
    \ CM(N+10);\n    cout << CM.binom(N+9,9) << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/741\"\n\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n#include \"../../lib/30-math/CombinationMod.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\n\nint main(void){\n    int N; cin >>\
    \ N;\n    CombinationMod<MOD> CM(N+10);\n    cout << CM.binom(N+9,9) << endl;\n\
    \treturn 0;\n}"
  dependsOn:
  - lib/30-math/CombinationMod.cpp
  isVerificationFile: true
  path: test/math/CombinationMod-binom.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/CombinationMod-binom.test.cpp
layout: document
redirect_from:
- /verify/test/math/CombinationMod-binom.test.cpp
- /verify/test/math/CombinationMod-binom.test.cpp.html
title: test/math/CombinationMod-binom.test.cpp
---
