---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/segment/WaveletMatrix-quantile.test.cpp
    title: test/segment/WaveletMatrix-quantile.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: md/segment/BitVector.md
    document_title: BitVector
    links: []
  bundledCode: "#line 1 \"lib/segment/BitVector.cpp\"\n/*\n * @title BitVector\n *\
    \ @docs md/segment/BitVector.md\n */\nclass BitVector{\n    inline static constexpr\
    \ size_t BIT_BLOCK_SIZE = 5;\n    inline static constexpr size_t BIT_BLOCK_NUM\
    \  = 1<<BIT_BLOCK_SIZE;\n    inline static constexpr uint32 popcount(uint32 x)\
    \ {return __builtin_popcount(x);}\n    inline static constexpr uint32 popcount(uint64\
    \ x) {return __builtin_popcountll(x);}\n\n\tvector<uint32> vec, acc;\n    bool\
    \ is_builded = false;\npublic:\n\tBitVector(uint32 N) {\n        uint32 tmp =\
    \ (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;\n\t\tvec.assign(tmp, 0);\n\t\tacc.assign(tmp,\
    \ 0);\n\t}\n\tvoid build() {\n\t\tfor (size_t i = 0,sum = 0; i < acc.size(); ++i)\
    \ acc[i] = (sum += popcount(vec[i]) );\n        is_builded = true;\n\t}\n\t//[0,r)\
    \ count of bit\n\tuint32 rank(uint32 r, const bool bit) const {\n        assert(is_builded);\n\
    \t\tuint32 bit_r = r >> BIT_BLOCK_SIZE;\n\t\tuint32 sum = (bit_r ? acc[bit_r -\
    \ 1] : 0) + popcount(vec[bit_r] & ((1U << (r & (BIT_BLOCK_NUM-1))) - 1));\n\t\t\
    return bit ? sum : r - sum;\n\t}\n    //[l,l+1) = bit\n\tvoid update(uint32 l,\
    \ const bool bit) {\n\t\tuint32 bit_l = l >> BIT_BLOCK_SIZE;\n\t\tif (bit) vec[bit_l]\
    \ |=   1U << (l & (BIT_BLOCK_NUM-1));\n\t\telse     vec[bit_l] &= ~(1U << (l &\
    \ (BIT_BLOCK_NUM-1)));\n\t}\n    //[l,l+1)\n\tbool operator[](uint32 l) const\
    \ { \n        assert(is_builded);\n        return ((vec[l >> BIT_BLOCK_SIZE] >>\
    \ (l & (BIT_BLOCK_NUM-1))) & 1); \n    }\n};\n"
  code: "/*\n * @title BitVector\n * @docs md/segment/BitVector.md\n */\nclass BitVector{\n\
    \    inline static constexpr size_t BIT_BLOCK_SIZE = 5;\n    inline static constexpr\
    \ size_t BIT_BLOCK_NUM  = 1<<BIT_BLOCK_SIZE;\n    inline static constexpr uint32\
    \ popcount(uint32 x) {return __builtin_popcount(x);}\n    inline static constexpr\
    \ uint32 popcount(uint64 x) {return __builtin_popcountll(x);}\n\n\tvector<uint32>\
    \ vec, acc;\n    bool is_builded = false;\npublic:\n\tBitVector(uint32 N) {\n\
    \        uint32 tmp = (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;\n\t\tvec.assign(tmp,\
    \ 0);\n\t\tacc.assign(tmp, 0);\n\t}\n\tvoid build() {\n\t\tfor (size_t i = 0,sum\
    \ = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(vec[i]) );\n        is_builded\
    \ = true;\n\t}\n\t//[0,r) count of bit\n\tuint32 rank(uint32 r, const bool bit)\
    \ const {\n        assert(is_builded);\n\t\tuint32 bit_r = r >> BIT_BLOCK_SIZE;\n\
    \t\tuint32 sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(vec[bit_r] & ((1U <<\
    \ (r & (BIT_BLOCK_NUM-1))) - 1));\n\t\treturn bit ? sum : r - sum;\n\t}\n    //[l,l+1)\
    \ = bit\n\tvoid update(uint32 l, const bool bit) {\n\t\tuint32 bit_l = l >> BIT_BLOCK_SIZE;\n\
    \t\tif (bit) vec[bit_l] |=   1U << (l & (BIT_BLOCK_NUM-1));\n\t\telse     vec[bit_l]\
    \ &= ~(1U << (l & (BIT_BLOCK_NUM-1)));\n\t}\n    //[l,l+1)\n\tbool operator[](uint32\
    \ l) const { \n        assert(is_builded);\n        return ((vec[l >> BIT_BLOCK_SIZE]\
    \ >> (l & (BIT_BLOCK_NUM-1))) & 1); \n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/BitVector.cpp
  requiredBy: []
  timestamp: '2021-01-04 03:34:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segment/WaveletMatrix-quantile.test.cpp
documentation_of: lib/segment/BitVector.cpp
layout: document
redirect_from:
- /library/lib/segment/BitVector.cpp
- /library/lib/segment/BitVector.cpp.html
title: BitVector
---
