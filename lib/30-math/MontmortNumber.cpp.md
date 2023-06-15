---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/MontmortNumber.test.cpp
    title: test/math/MontmortNumber.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/MontmortNumber.md
    document_title: "MontmortNumber - \u5B8C\u5168\u9806\u5217,\u64B9\u4E71\u9806\u5217\
      \u306E\u500B\u6570"
    links: []
  bundledCode: "#line 1 \"lib/30-math/MontmortNumber.cpp\"\n/*\n * @title MontmortNumber\
    \ - \u5B8C\u5168\u9806\u5217,\u64B9\u4E71\u9806\u5217\u306E\u500B\u6570\n * @docs\
    \ md/math/MontmortNumber.md\n */\ntemplate <class T> class MontmortNumber{\npublic:\n\
    \    inline static vector<T> get(const size_t N) {\n        vector<T> res(N+1,0);\n\
    \        if(N>=2) res[2]=1;\n        for(int i = 3; i <= N; ++i) res[i]=(res[i-1]+res[i-2])*(i-1);\n\
    \        return res;\n    }\n};\n"
  code: "/*\n * @title MontmortNumber - \u5B8C\u5168\u9806\u5217,\u64B9\u4E71\u9806\
    \u5217\u306E\u500B\u6570\n * @docs md/math/MontmortNumber.md\n */\ntemplate <class\
    \ T> class MontmortNumber{\npublic:\n    inline static vector<T> get(const size_t\
    \ N) {\n        vector<T> res(N+1,0);\n        if(N>=2) res[2]=1;\n        for(int\
    \ i = 3; i <= N; ++i) res[i]=(res[i-1]+res[i-2])*(i-1);\n        return res;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/MontmortNumber.cpp
  requiredBy: []
  timestamp: '2023-06-16 04:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/MontmortNumber.test.cpp
documentation_of: lib/30-math/MontmortNumber.cpp
layout: document
redirect_from:
- /library/lib/30-math/MontmortNumber.cpp
- /library/lib/30-math/MontmortNumber.cpp.html
title: "MontmortNumber - \u5B8C\u5168\u9806\u5217,\u64B9\u4E71\u9806\u5217\u306E\u500B\
  \u6570"
---
