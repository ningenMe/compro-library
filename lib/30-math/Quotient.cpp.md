---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Quotient.test.cpp
    title: test/math/Quotient.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/Quotient.md
    document_title: "Quotient - \u5546\u306E\u96C6\u5408"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Quotient.cpp\"\n/*\n * @title Quotient - \u5546\
    \u306E\u96C6\u5408\n * @docs md/math/Quotient.md\n */\ninline static vector<pair<long\
    \ long,long long>> Quotient(long long n) {\n    assert(n > 0);\n    long long\
    \ b = sqrtl(n);\n    long long l = b;\n    while(n / l != b) ++l;\n    vector<pair<long\
    \ long,long long>> res = {{0,0}};\n    for(long long i = 1; i <= l; ++i) {\n \
    \       long long k = n / i;\n        if(res.back().first == k) res.back().second++;\n\
    \        else res.emplace_back(k,1);\n    }\n    for(long long i = b, r; 1 <=\
    \ i; --i, l = r+1) {\n        r = n / i;\n        long long k = n / l;\n     \
    \   if(res.back().first == k) res.back().second = (r-l+1);\n        else res.emplace_back(k,r-l+1);\n\
    \    }\n    reverse(res.begin(),res.end());\n    res.pop_back();\n    return res;\n\
    }\n"
  code: "/*\n * @title Quotient - \u5546\u306E\u96C6\u5408\n * @docs md/math/Quotient.md\n\
    \ */\ninline static vector<pair<long long,long long>> Quotient(long long n) {\n\
    \    assert(n > 0);\n    long long b = sqrtl(n);\n    long long l = b;\n    while(n\
    \ / l != b) ++l;\n    vector<pair<long long,long long>> res = {{0,0}};\n    for(long\
    \ long i = 1; i <= l; ++i) {\n        long long k = n / i;\n        if(res.back().first\
    \ == k) res.back().second++;\n        else res.emplace_back(k,1);\n    }\n   \
    \ for(long long i = b, r; 1 <= i; --i, l = r+1) {\n        r = n / i;\n      \
    \  long long k = n / l;\n        if(res.back().first == k) res.back().second =\
    \ (r-l+1);\n        else res.emplace_back(k,r-l+1);\n    }\n    reverse(res.begin(),res.end());\n\
    \    res.pop_back();\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Quotient.cpp
  requiredBy: []
  timestamp: '2023-06-26 06:47:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Quotient.test.cpp
documentation_of: lib/30-math/Quotient.cpp
layout: document
redirect_from:
- /library/lib/30-math/Quotient.cpp
- /library/lib/30-math/Quotient.cpp.html
title: "Quotient - \u5546\u306E\u96C6\u5408"
---
- Quotient
- N/i の集合と個数を返す
- [提出](https://atcoder.jp/contests/abc230/tasks/abc230_e)