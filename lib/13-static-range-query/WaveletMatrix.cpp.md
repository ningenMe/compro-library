---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static-range-query/WaveletMatrix-range-freq.test.cpp
    title: test/static-range-query/WaveletMatrix-range-freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static-range-query/WaveletMatrix-range-kth-1.test.cpp
    title: test/static-range-query/WaveletMatrix-range-kth-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
    title: test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/static-range-query/WaveletMatrix.md
    document_title: WaveletMatrix
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/WaveletMatrix.cpp\"\n/*\n * @title\
    \ WaveletMatrix\n * @docs md/static-range-query/WaveletMatrix.md\n */\ntemplate<class\
    \ T> class WaveletMatrix{\n    using u64 = unsigned long long;\n    using u32\
    \ = unsigned int;\n\n    class BitVector{\n        inline static constexpr size_t\
    \ BIT_BLOCK_SIZE = 5;\n        inline static constexpr size_t BIT_BLOCK_NUM  =\
    \ (1<<BIT_BLOCK_SIZE) - 1; //31\n        vector<u32> ar, acc;\n        u32 popcount(u32\
    \ x) const {return __builtin_popcount(x);}\n        u32 length;\n    public:\n\
    \        u32 sum_bit0;\n        BitVector(const u32 N): length(N) {\n        \
    \    u32 tmp = (N + BIT_BLOCK_NUM) / (BIT_BLOCK_NUM+1);\n            ar.assign(tmp,\
    \ 0);\n            acc.assign(tmp, 0);\n        }\n        void build() { \n \
    \           for (size_t i = 0,sum = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(ar[i])\
    \ );\n            sum_bit0 = rank(length, 0);\n        }\n        //[0,r) count\
    \ of bit\n        u32 rank(const u32 r, const bool bit) const {\n            u32\
    \ bit_r = r >> BIT_BLOCK_SIZE; \n            u32 sum = (bit_r ? acc[bit_r - 1]\
    \ : 0) + popcount(ar[bit_r] & ((1U << (r & BIT_BLOCK_NUM)) - 1));\n          \
    \  return bit ? sum : r - sum;\n        }\n        //[l,l+1) = bit\n        void\
    \ update(const u32 l, const bool bit) {\n            u32 bit_l = l >> BIT_BLOCK_SIZE;\n\
    \            if (bit) ar[bit_l] |=   1U << (l & BIT_BLOCK_NUM);\n            else\
    \     ar[bit_l] &= ~(1U << (l & BIT_BLOCK_NUM));\n        }\n        //[l,l+1)\n\
    \        bool operator[](const u32 l) const {\n            return ((ar[l >> BIT_BLOCK_SIZE]\
    \ >> (l & BIT_BLOCK_NUM)) & 1);\n        }\n    };\n    size_t length;\n    size_t\
    \ depth;\n    vector<BitVector> bit_vector;\n    vector<T> ar;\n    void build()\
    \ {\n        length = ar.size();    \n        if(!length) return;\n        vector<u32>\
    \ ord(ar.size()),compressed(ar.size());\n        iota(ord.begin(),ord.end(),0);\n\
    \        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});\n\
    \        u32 cnt = 0;\n        compressed.front() = 0;\n        T pre = ar[ord.front()];\n\
    \        for(size_t i=1;i<ord.size();++i) {\n            size_t j=ord[i];\n  \
    \          if(pre < ar[j]) ++cnt;\n            compressed[j] = cnt;\n        \
    \    pre = ar[j];\n        }\n        sort(ar.begin(),ar.end());\n        ar.erase(unique(ar.begin(),ar.end()),ar.end());\n\
    \n        for(depth=0; (1<<depth) <= cnt+2; ++depth );\n        bit_vector.assign(depth,\
    \ BitVector(length));\n        vector<u32> prev = compressed, next = prev;\n \
    \       for(u32 d = 0; d < depth; ++d,swap(prev,next)) {\n            u32 bit\
    \ = 1UL << (depth - d - 1);\n            u32 idx_bit0 = 0, idx_bit1 = 0;\n   \
    \         for(u32 i = 0; i < length; ++i) idx_bit1 += !(prev[i] & bit);\n    \
    \        for(u32 i = 0; i < length; ++i) {\n                if (prev[i] & bit)\
    \ bit_vector[d].update(i,1), next[idx_bit1++] = prev[i];\n                else\
    \ next[idx_bit0++] = prev[i];\n            }\n            bit_vector[d].build();\n\
    \        }\n    }\n    inline T get_impl(u32 l) const {\n        u32 key = 0;\n\
    \        for (u32 d = 0; d < depth; ++d) {\n            const bool bit = bit_vector[d][l];\n\
    \            key = ((key << 1) | bit);\n            l = bit_vector[d].rank(l,\
    \ bit);\n            if(bit) l += bit_vector[d].sum_bit0;\n        }\n       \
    \ return ar[key];\n    }\n    inline T range_kth_smallest_impl(u32 l, u32 r, u32\
    \ k) const {\n        u32 key = 0;\n        for (u32 d = 0; d < depth; ++d) {\n\
    \            u32 cnt_bit_off = bit_vector[d].rank(r, 0) - bit_vector[d].rank(l,\
    \ 0);\n            const bool bit = (k >= cnt_bit_off);\n            key = ((key\
    \ << 1) | bit);\n            l = bit_vector[d].rank(l, bit);\n            r =\
    \ bit_vector[d].rank(r, bit);\n            if (bit) l += bit_vector[d].sum_bit0,\
    \ r += bit_vector[d].sum_bit0, k -= cnt_bit_off;\n        }\n        return ar[key];\n\
    \    }\n    inline u32 range_freq_upper_impl(u32 l, u32 r, T upper) const {\n\
    \        if(!length) return 0;\n        if(ar.back() < upper) return (r-l);\n\
    \        if(r-l<=0) return 0;\n        auto itr = lower_bound(ar.begin(),ar.end(),upper);\n\
    \        u32 key = (itr - ar.begin());\n        u32 cnt=0;\n        for (u32 d\
    \ = 0; d < depth; ++d) {\n            u32 bit = (key >> (depth - d - 1)) & 1U;\n\
    \            u32 tl = bit_vector[d].rank(l,0);\n            u32 tr = bit_vector[d].rank(r,0);\n\
    \            if(bit) {\n                cnt += tr-tl;\n                l += bit_vector[d].sum_bit0-tl;\n\
    \                r += bit_vector[d].sum_bit0-tr;\n            }\n            else\
    \ {\n                l = tl;\n                r = tr;\n            }\n       \
    \ }\n        return cnt;\n    }\n\npublic:\n    WaveletMatrix(const vector<T>\
    \ &ar): ar(ar) { build(); }\n    //[l,l+1) element\n    inline T get(const u32\
    \ l) const {return get_impl(l);}\n    //[l,r) range k (0-indexed) th smallest\
    \ number\n    T range_kth_smallest(const u32 l, const u32 r, const u32 k) const\
    \ {return range_kth_smallest_impl(l,r,k);}\n    //[l,r) range k (0-indexed) th\
    \ largest number\n    T range_kth_largest(const u32 l, const u32 r, const u32\
    \ k) const {return range_kth_smallest_impl(l,r,(r-l)-(k+1));}\n    //[l,r) range\
    \ freq of val (val < upper)\n    u32 range_freq_upper(const u32 l, const u32 r,\
    \ const T upper) const {return range_freq_upper_impl(l,r,upper);}\n    //[l,r)\
    \ range freq of val (lower <= val < upper)\n    u32 range_freq_lower_upper(const\
    \ u32 l, const u32 r, const T lower, const T upper) const {return range_freq_upper_impl(l,r,upper)\
    \ - range_freq_upper_impl(l,r,lower);}\n    //[l,r) range freq of val\n    u32\
    \ range_freq(const u32 l, const u32 r, const T val) const {return range_freq_lower_upper(l,r,val,val+1);}\n\
    };\n"
  code: "/*\n * @title WaveletMatrix\n * @docs md/static-range-query/WaveletMatrix.md\n\
    \ */\ntemplate<class T> class WaveletMatrix{\n    using u64 = unsigned long long;\n\
    \    using u32 = unsigned int;\n\n    class BitVector{\n        inline static\
    \ constexpr size_t BIT_BLOCK_SIZE = 5;\n        inline static constexpr size_t\
    \ BIT_BLOCK_NUM  = (1<<BIT_BLOCK_SIZE) - 1; //31\n        vector<u32> ar, acc;\n\
    \        u32 popcount(u32 x) const {return __builtin_popcount(x);}\n        u32\
    \ length;\n    public:\n        u32 sum_bit0;\n        BitVector(const u32 N):\
    \ length(N) {\n            u32 tmp = (N + BIT_BLOCK_NUM) / (BIT_BLOCK_NUM+1);\n\
    \            ar.assign(tmp, 0);\n            acc.assign(tmp, 0);\n        }\n\
    \        void build() { \n            for (size_t i = 0,sum = 0; i < acc.size();\
    \ ++i) acc[i] = (sum += popcount(ar[i]) );\n            sum_bit0 = rank(length,\
    \ 0);\n        }\n        //[0,r) count of bit\n        u32 rank(const u32 r,\
    \ const bool bit) const {\n            u32 bit_r = r >> BIT_BLOCK_SIZE; \n   \
    \         u32 sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(ar[bit_r] & ((1U <<\
    \ (r & BIT_BLOCK_NUM)) - 1));\n            return bit ? sum : r - sum;\n     \
    \   }\n        //[l,l+1) = bit\n        void update(const u32 l, const bool bit)\
    \ {\n            u32 bit_l = l >> BIT_BLOCK_SIZE;\n            if (bit) ar[bit_l]\
    \ |=   1U << (l & BIT_BLOCK_NUM);\n            else     ar[bit_l] &= ~(1U << (l\
    \ & BIT_BLOCK_NUM));\n        }\n        //[l,l+1)\n        bool operator[](const\
    \ u32 l) const {\n            return ((ar[l >> BIT_BLOCK_SIZE] >> (l & BIT_BLOCK_NUM))\
    \ & 1);\n        }\n    };\n    size_t length;\n    size_t depth;\n    vector<BitVector>\
    \ bit_vector;\n    vector<T> ar;\n    void build() {\n        length = ar.size();\
    \    \n        if(!length) return;\n        vector<u32> ord(ar.size()),compressed(ar.size());\n\
    \        iota(ord.begin(),ord.end(),0);\n        sort(ord.begin(),ord.end(),[&](size_t\
    \ l, size_t r){return ar[l]<ar[r];});\n        u32 cnt = 0;\n        compressed.front()\
    \ = 0;\n        T pre = ar[ord.front()];\n        for(size_t i=1;i<ord.size();++i)\
    \ {\n            size_t j=ord[i];\n            if(pre < ar[j]) ++cnt;\n      \
    \      compressed[j] = cnt;\n            pre = ar[j];\n        }\n        sort(ar.begin(),ar.end());\n\
    \        ar.erase(unique(ar.begin(),ar.end()),ar.end());\n\n        for(depth=0;\
    \ (1<<depth) <= cnt+2; ++depth );\n        bit_vector.assign(depth, BitVector(length));\n\
    \        vector<u32> prev = compressed, next = prev;\n        for(u32 d = 0; d\
    \ < depth; ++d,swap(prev,next)) {\n            u32 bit = 1UL << (depth - d - 1);\n\
    \            u32 idx_bit0 = 0, idx_bit1 = 0;\n            for(u32 i = 0; i < length;\
    \ ++i) idx_bit1 += !(prev[i] & bit);\n            for(u32 i = 0; i < length; ++i)\
    \ {\n                if (prev[i] & bit) bit_vector[d].update(i,1), next[idx_bit1++]\
    \ = prev[i];\n                else next[idx_bit0++] = prev[i];\n            }\n\
    \            bit_vector[d].build();\n        }\n    }\n    inline T get_impl(u32\
    \ l) const {\n        u32 key = 0;\n        for (u32 d = 0; d < depth; ++d) {\n\
    \            const bool bit = bit_vector[d][l];\n            key = ((key << 1)\
    \ | bit);\n            l = bit_vector[d].rank(l, bit);\n            if(bit) l\
    \ += bit_vector[d].sum_bit0;\n        }\n        return ar[key];\n    }\n    inline\
    \ T range_kth_smallest_impl(u32 l, u32 r, u32 k) const {\n        u32 key = 0;\n\
    \        for (u32 d = 0; d < depth; ++d) {\n            u32 cnt_bit_off = bit_vector[d].rank(r,\
    \ 0) - bit_vector[d].rank(l, 0);\n            const bool bit = (k >= cnt_bit_off);\n\
    \            key = ((key << 1) | bit);\n            l = bit_vector[d].rank(l,\
    \ bit);\n            r = bit_vector[d].rank(r, bit);\n            if (bit) l +=\
    \ bit_vector[d].sum_bit0, r += bit_vector[d].sum_bit0, k -= cnt_bit_off;\n   \
    \     }\n        return ar[key];\n    }\n    inline u32 range_freq_upper_impl(u32\
    \ l, u32 r, T upper) const {\n        if(!length) return 0;\n        if(ar.back()\
    \ < upper) return (r-l);\n        if(r-l<=0) return 0;\n        auto itr = lower_bound(ar.begin(),ar.end(),upper);\n\
    \        u32 key = (itr - ar.begin());\n        u32 cnt=0;\n        for (u32 d\
    \ = 0; d < depth; ++d) {\n            u32 bit = (key >> (depth - d - 1)) & 1U;\n\
    \            u32 tl = bit_vector[d].rank(l,0);\n            u32 tr = bit_vector[d].rank(r,0);\n\
    \            if(bit) {\n                cnt += tr-tl;\n                l += bit_vector[d].sum_bit0-tl;\n\
    \                r += bit_vector[d].sum_bit0-tr;\n            }\n            else\
    \ {\n                l = tl;\n                r = tr;\n            }\n       \
    \ }\n        return cnt;\n    }\n\npublic:\n    WaveletMatrix(const vector<T>\
    \ &ar): ar(ar) { build(); }\n    //[l,l+1) element\n    inline T get(const u32\
    \ l) const {return get_impl(l);}\n    //[l,r) range k (0-indexed) th smallest\
    \ number\n    T range_kth_smallest(const u32 l, const u32 r, const u32 k) const\
    \ {return range_kth_smallest_impl(l,r,k);}\n    //[l,r) range k (0-indexed) th\
    \ largest number\n    T range_kth_largest(const u32 l, const u32 r, const u32\
    \ k) const {return range_kth_smallest_impl(l,r,(r-l)-(k+1));}\n    //[l,r) range\
    \ freq of val (val < upper)\n    u32 range_freq_upper(const u32 l, const u32 r,\
    \ const T upper) const {return range_freq_upper_impl(l,r,upper);}\n    //[l,r)\
    \ range freq of val (lower <= val < upper)\n    u32 range_freq_lower_upper(const\
    \ u32 l, const u32 r, const T lower, const T upper) const {return range_freq_upper_impl(l,r,upper)\
    \ - range_freq_upper_impl(l,r,lower);}\n    //[l,r) range freq of val\n    u32\
    \ range_freq(const u32 l, const u32 r, const T val) const {return range_freq_lower_upper(l,r,val,val+1);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/WaveletMatrix.cpp
  requiredBy: []
  timestamp: '2023-06-10 18:11:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static-range-query/WaveletMatrix-range-kth-1.test.cpp
  - test/static-range-query/WaveletMatrix-range-freq.test.cpp
  - test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
documentation_of: lib/13-static-range-query/WaveletMatrix.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/WaveletMatrix.cpp
- /library/lib/13-static-range-query/WaveletMatrix.cpp.html
title: WaveletMatrix
---
### WaveletMatrix
- 静的な列に対して、区間クエリを高速に処理するデータ構造

### コンストラクタ
- WaveletMatrix(const vector<T> &ar)
  - vectorを渡す。中で座圧するからlong longでもok

### メソッド
- T get(const u32 l)
  - [l,l+1) 番目の要素を返す。元の配列を保持してるなら使わないメソッド

    //[l,r) range k (0-indexed) th smallest number
- T range_kth_smallest(const u32 l, const u32 r, const u32 k) 
  - [l,r) の範囲の中で、k (0-indexed) 番目に小さい値を返す
- T range_kth_largest(const u32 l, const u32 r, const u32 k)
  - [l,r) の範囲の中で、k (0-indexed) 番目に大きい値を返す
- u32 range_freq_upper(const u32 l, const u32 r, const T upper) 
  - [l,r) の範囲の中で、upperより小さい要素の数を返す
- u32 range_freq_lower_upper(const u32 l, const u32 r, const T lower, const T upper) 
  - [l,r) の範囲の中で、lower以上、upperより小さい要素の数を返す [lower, upper)
- u32 range_freq(const u32 l, const u32 r, const T val) 
  - [l,r) の範囲の中で、valに等しい要素の数を返す