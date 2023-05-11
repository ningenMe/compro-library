---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid/MonoidRangeMinPointUpdate.md
    document_title: "MonoidRangeMinPointUpdate - [\u533A\u9593min, \u70B9\u66F4\u65B0\
      ]"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid/MonoidRangeMinPointUpdate.cpp\"\n/*\n\
    \ * @title MonoidRangeMinPointUpdate - [\u533A\u9593min, \u70B9\u66F4\u65B0]\n\
    \ * @docs md/operator/monoid/MonoidRangeMinPointUpdate.md\n */\ntemplate<class\
    \ T> struct MonoidRangeMinPointUpdate {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = (1LL<<31)-1;\n    inline static constexpr TypeNode\
    \ func_fold(TypeNode l,TypeNode r){return min(l,r);}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeMinPointUpdate - [\u533A\u9593min, \u70B9\u66F4\u65B0\
    ]\n * @docs md/operator/monoid/MonoidRangeMinPointUpdate.md\n */\ntemplate<class\
    \ T> struct MonoidRangeMinPointUpdate {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = (1LL<<31)-1;\n    inline static constexpr TypeNode\
    \ func_fold(TypeNode l,TypeNode r){return min(l,r);}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
- /library/lib/operator/monoid/MonoidRangeMinPointUpdate.cpp.html
title: "MonoidRangeMinPointUpdate - [\u533A\u9593min, \u70B9\u66F4\u65B0]"
---
