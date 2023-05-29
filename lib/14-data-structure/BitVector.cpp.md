---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/WaveletMatrix-quantile-1.test.cpp
    title: test/data-structure/WaveletMatrix-quantile-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/WaveletMatrix-quantile-2.test.cpp
    title: test/data-structure/WaveletMatrix-quantile-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/BitVector.md
    document_title: BitVector
    links: []
  bundledCode: "#line 1 \"lib/14-data-structure/BitVector.cpp\"\n/*\n * @title BitVector\n\
    \ * @docs md/data-structure/BitVector.md\n */\nclass BitVector{\n    inline static\
    \ constexpr size_t BIT_BLOCK_SIZE = 5;\n    inline static constexpr size_t BIT_BLOCK_NUM\
    \  = 1<<BIT_BLOCK_SIZE;\n    inline static constexpr uint32 popcount(uint32 x)\
    \ {return __builtin_popcount(x);}\n    inline static constexpr uint32 popcount(uint64\
    \ x) {return __builtin_popcountll(x);}\n\n    vector<uint32> vec, acc;\n    bool\
    \ is_builded = false;\npublic:\n    BitVector(uint32 N) {\n        uint32 tmp\
    \ = (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;\n        vec.assign(tmp, 0);\n    \
    \    acc.assign(tmp, 0);\n    }\n    void build() {\n        for (size_t i = 0,sum\
    \ = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(vec[i]) );\n        is_builded\
    \ = true;\n    }\n    //[0,r) count of bit\n    uint32 rank(uint32 r, const bool\
    \ bit) const {\n        assert(is_builded);\n        uint32 bit_r = r >> BIT_BLOCK_SIZE;\n\
    \        uint32 sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(vec[bit_r] & ((1U\
    \ << (r & (BIT_BLOCK_NUM-1))) - 1));\n        return bit ? sum : r - sum;\n  \
    \  }\n    //[l,l+1) = bit\n    void update(uint32 l, const bool bit) {\n     \
    \   uint32 bit_l = l >> BIT_BLOCK_SIZE;\n        if (bit) vec[bit_l] |=   1U <<\
    \ (l & (BIT_BLOCK_NUM-1));\n        else     vec[bit_l] &= ~(1U << (l & (BIT_BLOCK_NUM-1)));\n\
    \    }\n    //[l,l+1)\n    bool operator[](uint32 l) const {\n        assert(is_builded);\n\
    \        return ((vec[l >> BIT_BLOCK_SIZE] >> (l & (BIT_BLOCK_NUM-1))) & 1);\n\
    \    }\n};\n"
  code: "/*\n * @title BitVector\n * @docs md/data-structure/BitVector.md\n */\nclass\
    \ BitVector{\n    inline static constexpr size_t BIT_BLOCK_SIZE = 5;\n    inline\
    \ static constexpr size_t BIT_BLOCK_NUM  = 1<<BIT_BLOCK_SIZE;\n    inline static\
    \ constexpr uint32 popcount(uint32 x) {return __builtin_popcount(x);}\n    inline\
    \ static constexpr uint32 popcount(uint64 x) {return __builtin_popcountll(x);}\n\
    \n    vector<uint32> vec, acc;\n    bool is_builded = false;\npublic:\n    BitVector(uint32\
    \ N) {\n        uint32 tmp = (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;\n        vec.assign(tmp,\
    \ 0);\n        acc.assign(tmp, 0);\n    }\n    void build() {\n        for (size_t\
    \ i = 0,sum = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(vec[i]) );\n \
    \       is_builded = true;\n    }\n    //[0,r) count of bit\n    uint32 rank(uint32\
    \ r, const bool bit) const {\n        assert(is_builded);\n        uint32 bit_r\
    \ = r >> BIT_BLOCK_SIZE;\n        uint32 sum = (bit_r ? acc[bit_r - 1] : 0) +\
    \ popcount(vec[bit_r] & ((1U << (r & (BIT_BLOCK_NUM-1))) - 1));\n        return\
    \ bit ? sum : r - sum;\n    }\n    //[l,l+1) = bit\n    void update(uint32 l,\
    \ const bool bit) {\n        uint32 bit_l = l >> BIT_BLOCK_SIZE;\n        if (bit)\
    \ vec[bit_l] |=   1U << (l & (BIT_BLOCK_NUM-1));\n        else     vec[bit_l]\
    \ &= ~(1U << (l & (BIT_BLOCK_NUM-1)));\n    }\n    //[l,l+1)\n    bool operator[](uint32\
    \ l) const {\n        assert(is_builded);\n        return ((vec[l >> BIT_BLOCK_SIZE]\
    \ >> (l & (BIT_BLOCK_NUM-1))) & 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/14-data-structure/BitVector.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/WaveletMatrix-quantile-1.test.cpp
  - test/data-structure/WaveletMatrix-quantile-2.test.cpp
documentation_of: lib/14-data-structure/BitVector.cpp
layout: document
redirect_from:
- /library/lib/14-data-structure/BitVector.cpp
- /library/lib/14-data-structure/BitVector.cpp.html
title: BitVector
---
