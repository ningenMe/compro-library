---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid/MonoidRangeGcdPointUpdate.md
    document_title: "MonoidRangeGcdPointUpdate - [\u533A\u9593gcd, \u70B9\u66F4\u65B0\
      ]"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp\"\n/*\n\
    \ * @title MonoidRangeGcdPointUpdate - [\u533A\u9593gcd, \u70B9\u66F4\u65B0]\n\
    \ * @docs md/operator/monoid/MonoidRangeGcdPointUpdate.md\n */\ntemplate<class\
    \ T> struct MonoidRangeGcdPointUpdate {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return Gcd::gcd(l,r);}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeGcdPointUpdate - [\u533A\u9593gcd, \u70B9\u66F4\u65B0\
    ]\n * @docs md/operator/monoid/MonoidRangeGcdPointUpdate.md\n */\ntemplate<class\
    \ T> struct MonoidRangeGcdPointUpdate {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return Gcd::gcd(l,r);}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp
- /library/lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp.html
title: "MonoidRangeGcdPointUpdate - [\u533A\u9593gcd, \u70B9\u66F4\u65B0]"
---
