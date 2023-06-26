---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/30-math/Quotient.cpp
    title: "Quotient - \u5546\u306E\u96C6\u5408"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/math/Quotient.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cmath>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n#line 1 \"lib/30-math/Quotient.cpp\"\
    \n/*\n * @title Quotient - \u5546\u306E\u96C6\u5408\n * @docs md/math/Quotient.md\n\
    \ */\ninline static vector<pair<long long,long long>> Quotient(long long n) {\n\
    \    assert(n > 0);\n    long long b = sqrtl(n);\n    long long l = b;\n    while(n\
    \ / l != b) ++l;\n    vector<pair<long long,long long>> res = {{0,0}};\n    for(long\
    \ long i = 1; i <= l; ++i) {\n        long long k = n / i;\n        if(res.back().first\
    \ == k) res.back().second++;\n        else res.emplace_back(k,1);\n    }\n   \
    \ for(long long i = b, r; 1 <= i; --i, l = r+1) {\n        r = n / i;\n      \
    \  long long k = n / l;\n        if(res.back().first == k) res.back().second =\
    \ (r-l+1);\n        else res.emplace_back(k,r-l+1);\n    }\n    reverse(res.begin(),res.end());\n\
    \    res.pop_back();\n    return res;\n}\n#line 10 \"test/math/Quotient.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    long long\
    \ N; cin >> N;\n    auto vp = Quotient(N);\n    int M = vp.size();\n    cout <<\
    \ M << \"\\n\";\n    for(int i = 0; i<M; ++i) cout << vp[i].first << \" \\n\"\
    [i==M-1];\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cmath>\n#include <algorithm>\n\
    #include <cassert>\nusing namespace std;\n#include \"../../lib/30-math/Quotient.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    long long\
    \ N; cin >> N;\n    auto vp = Quotient(N);\n    int M = vp.size();\n    cout <<\
    \ M << \"\\n\";\n    for(int i = 0; i<M; ++i) cout << vp[i].first << \" \\n\"\
    [i==M-1];\n\treturn 0;\n}"
  dependsOn:
  - lib/30-math/Quotient.cpp
  isVerificationFile: true
  path: test/math/Quotient.test.cpp
  requiredBy: []
  timestamp: '2023-06-26 21:08:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Quotient.test.cpp
layout: document
redirect_from:
- /verify/test/math/Quotient.test.cpp
- /verify/test/math/Quotient.test.cpp.html
title: test/math/Quotient.test.cpp
---
