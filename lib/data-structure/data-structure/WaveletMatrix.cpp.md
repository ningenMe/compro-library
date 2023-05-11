---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/data-structure/data-structure/WaveletMatrix.md
    document_title: WaveletMatrix
    links: []
  bundledCode: "#line 1 \"lib/data-structure/data-structure/WaveletMatrix.cpp\"\n\
    /*\n * @title WaveletMatrix\n * @docs md/data-structure/data-structure/WaveletMatrix.md\n\
    \ */\ntemplate<class T> class WaveletMatrix{\n    size_t length;\n    size_t depth;\n\
    \    vector<BitVector> multi_bit_vector;\n    vector<uint32> sum_bit_off;\n  \
    \  vector<T> vec;\n    vector<uint32> zarts(const vector<T>& ar) {\n        vector<uint32>\
    \ ord(ar.size()),compressed(ar.size());\n        iota(ord.begin(),ord.end(),0);\n\
    \        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});\n\
    \        uint32 cnt = 0;\n        compressed.front() = 0;\n        T pre = ar[ord.front()];\n\
    \        for(size_t i=1;i<ord.size();++i) {\n            size_t j=ord[i];\n  \
    \          if(pre < ar[j]) ++cnt;\n            compressed[j] = cnt;\n        \
    \    pre = ar[j];\n        }\n        return compressed;\n    }\npublic:\n   \
    \ WaveletMatrix(const vector<T> &arg_vec): vec(arg_vec) {\n        length = vec.size();\n\
    \        auto compressed = zarts(vec);\n        sort(vec.begin(),vec.end());\n\
    \        vec.erase(unique(vec.begin(),vec.end()),vec.end());\n        uint32 maxi\
    \ = *max_element(compressed.begin(),compressed.end()) + 1;\n        for(depth=0;\
    \ (1<<depth) <= maxi; ++depth );\n\n        multi_bit_vector.assign(depth, BitVector(length));\n\
    \        sum_bit_off.assign(depth, 0UL);\n        vector<uint32> prev = compressed,\
    \ next = prev;\n        for(uint32 j = 0; j < depth; ++j,swap(prev,next)) {\n\
    \            uint32 bit = 1UL << (depth - j - 1);\n            for(uint32 i =\
    \ 0; i < length; ++i) sum_bit_off[j] += !(prev[i] & bit);\n\n            uint32\
    \ idx_bit_off = 0, idx_bit_on = sum_bit_off[j];\n            for(uint32 i = 0;\
    \ i < length; ++i) {\n                if (prev[i] & bit) multi_bit_vector[j].update(i,1),\
    \ next[idx_bit_on++] = prev[i];\n                else next[idx_bit_off++] = prev[i];\n\
    \            }\n            multi_bit_vector[j].build();\n        }\n    }\n \
    \   //[l,l+1) element\n    T operator[](uint32 l) const {\n        uint32 val\
    \ = 0;\n        for (uint32 j = 0; j < depth; ++j) {\n            const bool bit\
    \ = multi_bit_vector[j][l];\n            val = ((val << 1) | bit);\n         \
    \   l = multi_bit_vector[j].rank(l, bit);\n            if(bit) l += sum_bit_off[j];\n\
    \        }\n        return vec[val];\n    }\n\n    //[l,r) range count of more\
    \ and less than c (c'<c, c'=c, c<c')\n    // tuple<uint32, uint32, uint32> rank_all(T\
    \ c, uint32 l, uint32 r) const\n    // {\n    // \tif (c > vec.back()) return\
    \ make_tuple(r - l, 0U, 0U);\n    // \tarray<uint32,2> more_and_less = {0,0};\n\
    \    // \tfor (uint32 j = 0; j < depth; ++j) {\n    // \t\tconst bool bit = (c\
    \ >> (depth - j - 1)) & 1;\n    // \t\tmore_and_less[bit] += r - l;\n    // \t\
    \tl = multi_bit_vector[j].rank(l, bit);\n    // \t\tr = multi_bit_vector[j].rank(r,\
    \ bit);\n    // \t\tif (bit) l += sum_bit_off[j], r += sum_bit_off[j];\n    //\
    \ \t\tmore_and_less[bit] -= r - l;\n    // \t}\n    // \treturn make_tuple(more_and_less[1],\
    \ r - l, more_and_less[0]);\n    // }\n\n    //[l,r) range k (0-indexed) th smallest\
    \ number\n    T quantile(uint32 l, uint32 r, uint32 k) const {\n        uint32\
    \ val = 0;\n        for (uint32 j = 0; j < depth; ++j) {\n            uint32 cnt_bit_off\
    \ = multi_bit_vector[j].rank(r, 0) - multi_bit_vector[j].rank(l, 0);\n       \
    \     const bool bit = (k >= cnt_bit_off);\n            val = ((val << 1) | bit);\n\
    \            l = multi_bit_vector[j].rank(l, bit);\n            r = multi_bit_vector[j].rank(r,\
    \ bit);\n            if (bit) l += sum_bit_off[j], r += sum_bit_off[j], k -= cnt_bit_off;\n\
    \        }\n        return vec[val];\n    }\n};\n"
  code: "/*\n * @title WaveletMatrix\n * @docs md/data-structure/data-structure/WaveletMatrix.md\n\
    \ */\ntemplate<class T> class WaveletMatrix{\n    size_t length;\n    size_t depth;\n\
    \    vector<BitVector> multi_bit_vector;\n    vector<uint32> sum_bit_off;\n  \
    \  vector<T> vec;\n    vector<uint32> zarts(const vector<T>& ar) {\n        vector<uint32>\
    \ ord(ar.size()),compressed(ar.size());\n        iota(ord.begin(),ord.end(),0);\n\
    \        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});\n\
    \        uint32 cnt = 0;\n        compressed.front() = 0;\n        T pre = ar[ord.front()];\n\
    \        for(size_t i=1;i<ord.size();++i) {\n            size_t j=ord[i];\n  \
    \          if(pre < ar[j]) ++cnt;\n            compressed[j] = cnt;\n        \
    \    pre = ar[j];\n        }\n        return compressed;\n    }\npublic:\n   \
    \ WaveletMatrix(const vector<T> &arg_vec): vec(arg_vec) {\n        length = vec.size();\n\
    \        auto compressed = zarts(vec);\n        sort(vec.begin(),vec.end());\n\
    \        vec.erase(unique(vec.begin(),vec.end()),vec.end());\n        uint32 maxi\
    \ = *max_element(compressed.begin(),compressed.end()) + 1;\n        for(depth=0;\
    \ (1<<depth) <= maxi; ++depth );\n\n        multi_bit_vector.assign(depth, BitVector(length));\n\
    \        sum_bit_off.assign(depth, 0UL);\n        vector<uint32> prev = compressed,\
    \ next = prev;\n        for(uint32 j = 0; j < depth; ++j,swap(prev,next)) {\n\
    \            uint32 bit = 1UL << (depth - j - 1);\n            for(uint32 i =\
    \ 0; i < length; ++i) sum_bit_off[j] += !(prev[i] & bit);\n\n            uint32\
    \ idx_bit_off = 0, idx_bit_on = sum_bit_off[j];\n            for(uint32 i = 0;\
    \ i < length; ++i) {\n                if (prev[i] & bit) multi_bit_vector[j].update(i,1),\
    \ next[idx_bit_on++] = prev[i];\n                else next[idx_bit_off++] = prev[i];\n\
    \            }\n            multi_bit_vector[j].build();\n        }\n    }\n \
    \   //[l,l+1) element\n    T operator[](uint32 l) const {\n        uint32 val\
    \ = 0;\n        for (uint32 j = 0; j < depth; ++j) {\n            const bool bit\
    \ = multi_bit_vector[j][l];\n            val = ((val << 1) | bit);\n         \
    \   l = multi_bit_vector[j].rank(l, bit);\n            if(bit) l += sum_bit_off[j];\n\
    \        }\n        return vec[val];\n    }\n\n    //[l,r) range count of more\
    \ and less than c (c'<c, c'=c, c<c')\n    // tuple<uint32, uint32, uint32> rank_all(T\
    \ c, uint32 l, uint32 r) const\n    // {\n    // \tif (c > vec.back()) return\
    \ make_tuple(r - l, 0U, 0U);\n    // \tarray<uint32,2> more_and_less = {0,0};\n\
    \    // \tfor (uint32 j = 0; j < depth; ++j) {\n    // \t\tconst bool bit = (c\
    \ >> (depth - j - 1)) & 1;\n    // \t\tmore_and_less[bit] += r - l;\n    // \t\
    \tl = multi_bit_vector[j].rank(l, bit);\n    // \t\tr = multi_bit_vector[j].rank(r,\
    \ bit);\n    // \t\tif (bit) l += sum_bit_off[j], r += sum_bit_off[j];\n    //\
    \ \t\tmore_and_less[bit] -= r - l;\n    // \t}\n    // \treturn make_tuple(more_and_less[1],\
    \ r - l, more_and_less[0]);\n    // }\n\n    //[l,r) range k (0-indexed) th smallest\
    \ number\n    T quantile(uint32 l, uint32 r, uint32 k) const {\n        uint32\
    \ val = 0;\n        for (uint32 j = 0; j < depth; ++j) {\n            uint32 cnt_bit_off\
    \ = multi_bit_vector[j].rank(r, 0) - multi_bit_vector[j].rank(l, 0);\n       \
    \     const bool bit = (k >= cnt_bit_off);\n            val = ((val << 1) | bit);\n\
    \            l = multi_bit_vector[j].rank(l, bit);\n            r = multi_bit_vector[j].rank(r,\
    \ bit);\n            if (bit) l += sum_bit_off[j], r += sum_bit_off[j], k -= cnt_bit_off;\n\
    \        }\n        return vec[val];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/data-structure/WaveletMatrix.cpp
  requiredBy: []
  timestamp: '2021-04-26 22:51:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/data-structure/WaveletMatrix.cpp
layout: document
redirect_from:
- /library/lib/data-structure/data-structure/WaveletMatrix.cpp
- /library/lib/data-structure/data-structure/WaveletMatrix.cpp.html
title: WaveletMatrix
---
