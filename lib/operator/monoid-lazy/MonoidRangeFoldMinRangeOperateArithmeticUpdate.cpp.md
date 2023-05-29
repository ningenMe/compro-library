---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/operator/monoid-lazy/MonoidRangeMinRangeArithmeticUpdate.md
    document_title: "MonoidRangeMinRangeArithmeticUpdate - [\u533A\u9593min, \u533A\
      \u9593\u7B49\u5DEE\u6570\u5217\u66F4\u65B0]"
    links: []
  bundledCode: "#line 1 \"lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateArithmeticUpdate.cpp\"\
    \n/*\n * @title MonoidRangeMinRangeArithmeticUpdate - [\u533A\u9593min, \u533A\
    \u9593\u7B49\u5DEE\u6570\u5217\u66F4\u65B0]\n * @docs md/operator/monoid-lazy/MonoidRangeMinRangeArithmeticUpdate.md\n\
    \ */template<class T, class U> struct MonoidRangeMinRangeArithmeticUpdate {\n\
    \    using TypeNode = T;\n    using TypeLazy = U;\n    inline static constexpr\
    \ TypeNode unit_node = 1234567;\n    inline static constexpr TypeLazy unit_lazy\
    \ = {-2000,-2000};\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n    inline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return new_lazy;}\n    inline static constexpr TypeNode\
    \ func_operate(TypeNode node,TypeLazy lazy,int l,int r){ return (lazy.first==-2000?node:lazy.first\
    \ + (l-lazy.second));}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode\
    \ var){return var <= nodeVal;}\n};\n"
  code: "/*\n * @title MonoidRangeMinRangeArithmeticUpdate - [\u533A\u9593min, \u533A\
    \u9593\u7B49\u5DEE\u6570\u5217\u66F4\u65B0]\n * @docs md/operator/monoid-lazy/MonoidRangeMinRangeArithmeticUpdate.md\n\
    \ */template<class T, class U> struct MonoidRangeMinRangeArithmeticUpdate {\n\
    \    using TypeNode = T;\n    using TypeLazy = U;\n    inline static constexpr\
    \ TypeNode unit_node = 1234567;\n    inline static constexpr TypeLazy unit_lazy\
    \ = {-2000,-2000};\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n    inline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return new_lazy;}\n    inline static constexpr TypeNode\
    \ func_operate(TypeNode node,TypeLazy lazy,int l,int r){ return (lazy.first==-2000?node:lazy.first\
    \ + (l-lazy.second));}\n    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode\
    \ var){return var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateArithmeticUpdate.cpp
  requiredBy: []
  timestamp: '2023-05-30 03:18:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateArithmeticUpdate.cpp
layout: document
redirect_from:
- /library/lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateArithmeticUpdate.cpp
- /library/lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateArithmeticUpdate.cpp.html
title: "MonoidRangeMinRangeArithmeticUpdate - [\u533A\u9593min, \u533A\u9593\u7B49\
  \u5DEE\u6570\u5217\u66F4\u65B0]"
---
