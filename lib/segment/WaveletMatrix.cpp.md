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
    _deprecated_at_docs: md/segment/WaveletMatrix.md
    document_title: WaveletMatrix
    links: []
  bundledCode: "#line 1 \"lib/segment/WaveletMatrix.cpp\"\n/*\n * @title WaveletMatrix\n\
    \ * @docs md/segment/WaveletMatrix.md\n */\ntemplate<class T> class WaveletMatrix{\n\
    \tsize_t length;\n    size_t depth;\n\tvector<BitVector> multi_bit_vector;\n\t\
    vector<uint32> sum_bit_off;\n    vector<T> vec;\n    vector<uint32> zarts(const\
    \ vector<T>& ar) {\n        vector<uint32> ord(ar.size()),compressed(ar.size());\n\
    \        iota(ord.begin(),ord.end(),0);\n        sort(ord.begin(),ord.end(),[&](size_t\
    \ l, size_t r){return ar[l]<ar[r];});\n        uint32 cnt = 0;\n        compressed.front()\
    \ = 0;\n        T pre = ar[ord.front()];\n        for(size_t i=1;i<ord.size();++i)\
    \ {\n            size_t j=ord[i];\n            if(pre < ar[j]) ++cnt;\n      \
    \      compressed[j] = cnt;\n            pre = ar[j];\n        }\n        return\
    \ compressed;\n    }\npublic:\n\tWaveletMatrix(const vector<T> &arg_vec): vec(arg_vec)\
    \ {\n        length = vec.size();\n        auto compressed = zarts(vec);\n   \
    \     sort(vec.begin(),vec.end());\n        vec.erase(unique(vec.begin(),vec.end()),vec.end());\n\
    \        uint32 maxi = *max_element(compressed.begin(),compressed.end()) + 1;\n\
    \        for(depth=0; (1<<depth) <= maxi; ++depth );\n\n\t\tmulti_bit_vector.assign(depth,\
    \ BitVector(length));\n\t\tsum_bit_off.assign(depth, 0UL);\n\t\tvector<uint32>\
    \ prev = compressed, next = prev;\n\t\tfor(uint32 j = 0; j < depth; ++j,swap(prev,next))\
    \ {\n\t\t\tuint32 bit = 1UL << (depth - j - 1);\n\t\t\tfor(uint32 i = 0; i < length;\
    \ ++i) sum_bit_off[j] += !(prev[i] & bit);\n\n\t\t\tuint32 idx_bit_off = 0, idx_bit_on\
    \ = sum_bit_off[j];\n\t\t\tfor(uint32 i = 0; i < length; ++i) {\n\t\t\t\tif (prev[i]\
    \ & bit) multi_bit_vector[j].update(i,1), next[idx_bit_on++] = prev[i];\n\t\t\t\
    \telse next[idx_bit_off++] = prev[i];\n            }\n\t\t\tmulti_bit_vector[j].build();\n\
    \t\t}\n\t}\n    //[l,l+1) element\n\tT operator[](uint32 l) const {\n\t\tuint32\
    \ val = 0;\n\t\tfor (uint32 j = 0; j < depth; ++j) {\n\t\t\tconst bool bit = multi_bit_vector[j][l];\n\
    \t\t\tval = ((val << 1) | bit);\n\t\t\tl = multi_bit_vector[j].rank(l, bit);\n\
    \t\t\tif(bit) l += sum_bit_off[j];\n\t\t}\n\t\treturn vec[val];\n\t}\n\n    //[l,r)\
    \ range count of more and less than c (c'<c, c'=c, c<c')\n\t// tuple<uint32, uint32,\
    \ uint32> rank_all(T c, uint32 l, uint32 r) const\n\t// {\n\t// \tif (c > vec.back())\
    \ return make_tuple(r - l, 0U, 0U);\n\t// \tarray<uint32,2> more_and_less = {0,0};\n\
    \t// \tfor (uint32 j = 0; j < depth; ++j) {\n\t// \t\tconst bool bit = (c >> (depth\
    \ - j - 1)) & 1;\n\t// \t\tmore_and_less[bit] += r - l;\n\t// \t\tl = multi_bit_vector[j].rank(l,\
    \ bit);\n\t// \t\tr = multi_bit_vector[j].rank(r, bit);\n\t// \t\tif (bit) l +=\
    \ sum_bit_off[j], r += sum_bit_off[j];\n\t// \t\tmore_and_less[bit] -= r - l;\n\
    \t// \t}\n\t// \treturn make_tuple(more_and_less[1], r - l, more_and_less[0]);\n\
    \t// }\n\n    //[l,r) range k (0-indexed) th smallest number\n\tT quantile(uint32\
    \ l, uint32 r, uint32 k) const {\n\t\tuint32 val = 0;\n\t\tfor (uint32 j = 0;\
    \ j < depth; ++j) {\n\t\t\tuint32 cnt_bit_off = multi_bit_vector[j].rank(r, 0)\
    \ - multi_bit_vector[j].rank(l, 0);\n\t\t\tconst bool bit = (k >= cnt_bit_off);\n\
    \t\t\tval = ((val << 1) | bit);\n\t\t\tl = multi_bit_vector[j].rank(l, bit);\n\
    \t\t\tr = multi_bit_vector[j].rank(r, bit);\n\t\t\tif (bit) l += sum_bit_off[j],\
    \ r += sum_bit_off[j], k -= cnt_bit_off;\n\t\t}\n\t\treturn vec[val];\n\t}\n};\n"
  code: "/*\n * @title WaveletMatrix\n * @docs md/segment/WaveletMatrix.md\n */\n\
    template<class T> class WaveletMatrix{\n\tsize_t length;\n    size_t depth;\n\t\
    vector<BitVector> multi_bit_vector;\n\tvector<uint32> sum_bit_off;\n    vector<T>\
    \ vec;\n    vector<uint32> zarts(const vector<T>& ar) {\n        vector<uint32>\
    \ ord(ar.size()),compressed(ar.size());\n        iota(ord.begin(),ord.end(),0);\n\
    \        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});\n\
    \        uint32 cnt = 0;\n        compressed.front() = 0;\n        T pre = ar[ord.front()];\n\
    \        for(size_t i=1;i<ord.size();++i) {\n            size_t j=ord[i];\n  \
    \          if(pre < ar[j]) ++cnt;\n            compressed[j] = cnt;\n        \
    \    pre = ar[j];\n        }\n        return compressed;\n    }\npublic:\n\tWaveletMatrix(const\
    \ vector<T> &arg_vec): vec(arg_vec) {\n        length = vec.size();\n        auto\
    \ compressed = zarts(vec);\n        sort(vec.begin(),vec.end());\n        vec.erase(unique(vec.begin(),vec.end()),vec.end());\n\
    \        uint32 maxi = *max_element(compressed.begin(),compressed.end()) + 1;\n\
    \        for(depth=0; (1<<depth) <= maxi; ++depth );\n\n\t\tmulti_bit_vector.assign(depth,\
    \ BitVector(length));\n\t\tsum_bit_off.assign(depth, 0UL);\n\t\tvector<uint32>\
    \ prev = compressed, next = prev;\n\t\tfor(uint32 j = 0; j < depth; ++j,swap(prev,next))\
    \ {\n\t\t\tuint32 bit = 1UL << (depth - j - 1);\n\t\t\tfor(uint32 i = 0; i < length;\
    \ ++i) sum_bit_off[j] += !(prev[i] & bit);\n\n\t\t\tuint32 idx_bit_off = 0, idx_bit_on\
    \ = sum_bit_off[j];\n\t\t\tfor(uint32 i = 0; i < length; ++i) {\n\t\t\t\tif (prev[i]\
    \ & bit) multi_bit_vector[j].update(i,1), next[idx_bit_on++] = prev[i];\n\t\t\t\
    \telse next[idx_bit_off++] = prev[i];\n            }\n\t\t\tmulti_bit_vector[j].build();\n\
    \t\t}\n\t}\n    //[l,l+1) element\n\tT operator[](uint32 l) const {\n\t\tuint32\
    \ val = 0;\n\t\tfor (uint32 j = 0; j < depth; ++j) {\n\t\t\tconst bool bit = multi_bit_vector[j][l];\n\
    \t\t\tval = ((val << 1) | bit);\n\t\t\tl = multi_bit_vector[j].rank(l, bit);\n\
    \t\t\tif(bit) l += sum_bit_off[j];\n\t\t}\n\t\treturn vec[val];\n\t}\n\n    //[l,r)\
    \ range count of more and less than c (c'<c, c'=c, c<c')\n\t// tuple<uint32, uint32,\
    \ uint32> rank_all(T c, uint32 l, uint32 r) const\n\t// {\n\t// \tif (c > vec.back())\
    \ return make_tuple(r - l, 0U, 0U);\n\t// \tarray<uint32,2> more_and_less = {0,0};\n\
    \t// \tfor (uint32 j = 0; j < depth; ++j) {\n\t// \t\tconst bool bit = (c >> (depth\
    \ - j - 1)) & 1;\n\t// \t\tmore_and_less[bit] += r - l;\n\t// \t\tl = multi_bit_vector[j].rank(l,\
    \ bit);\n\t// \t\tr = multi_bit_vector[j].rank(r, bit);\n\t// \t\tif (bit) l +=\
    \ sum_bit_off[j], r += sum_bit_off[j];\n\t// \t\tmore_and_less[bit] -= r - l;\n\
    \t// \t}\n\t// \treturn make_tuple(more_and_less[1], r - l, more_and_less[0]);\n\
    \t// }\n\n    //[l,r) range k (0-indexed) th smallest number\n\tT quantile(uint32\
    \ l, uint32 r, uint32 k) const {\n\t\tuint32 val = 0;\n\t\tfor (uint32 j = 0;\
    \ j < depth; ++j) {\n\t\t\tuint32 cnt_bit_off = multi_bit_vector[j].rank(r, 0)\
    \ - multi_bit_vector[j].rank(l, 0);\n\t\t\tconst bool bit = (k >= cnt_bit_off);\n\
    \t\t\tval = ((val << 1) | bit);\n\t\t\tl = multi_bit_vector[j].rank(l, bit);\n\
    \t\t\tr = multi_bit_vector[j].rank(r, bit);\n\t\t\tif (bit) l += sum_bit_off[j],\
    \ r += sum_bit_off[j], k -= cnt_bit_off;\n\t\t}\n\t\treturn vec[val];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/WaveletMatrix.cpp
  requiredBy: []
  timestamp: '2021-01-04 03:34:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segment/WaveletMatrix-quantile.test.cpp
documentation_of: lib/segment/WaveletMatrix.cpp
layout: document
redirect_from:
- /library/lib/segment/WaveletMatrix.cpp
- /library/lib/segment/WaveletMatrix.cpp.html
title: WaveletMatrix
---
