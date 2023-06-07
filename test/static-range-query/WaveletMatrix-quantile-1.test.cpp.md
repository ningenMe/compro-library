---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/13-static-range-query/WaveletMatrix.cpp
    title: WaveletMatrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/static-range-query/WaveletMatrix-quantile-1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n#include\
    \ <numeric>\nusing namespace std;\n\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n\
    \ * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/13-static-range-query/WaveletMatrix.cpp\"\n/*\n * @title WaveletMatrix\n\
    \ * @docs md/static-range-query/WaveletMatrix.md\n */\ntemplate<class T> class\
    \ WaveletMatrix{\n    using u64 = unsigned long long;\n    using u32 = unsigned\
    \ int;\n    class BitVector{\n        inline static constexpr size_t BIT_BLOCK_SIZE\
    \ = 5;\n        inline static constexpr size_t BIT_BLOCK_NUM  = 1<<BIT_BLOCK_SIZE;\n\
    \        inline static constexpr u32 popcount(u32 x) {return __builtin_popcount(x);}\n\
    \        inline static constexpr u32 popcount(u64 x) {return __builtin_popcountll(x);}\n\
    \        vector<u32> vec, acc;\n    public:\n        BitVector(const u32 N) {\n\
    \            u32 tmp = (N + BIT_BLOCK_NUM-1) / BIT_BLOCK_NUM;\n            vec.assign(tmp,\
    \ 0);\n            acc.assign(tmp, 0);\n        }\n        void build() { for\
    \ (size_t i = 0,sum = 0; i < acc.size(); ++i) acc[i] = (sum += popcount(vec[i])\
    \ );}\n        //[0,r) count of bit\n        u32 rank(const u32 r, const bool\
    \ bit) const {\n            u32 bit_r = r >> BIT_BLOCK_SIZE; \n            u32\
    \ sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(vec[bit_r] & ((1U << (r & (BIT_BLOCK_NUM-1)))\
    \ - 1));\n            return bit ? sum : r - sum;\n        }\n        //[l,l+1)\
    \ = bit\n        void update(const u32 l, const bool bit) {\n            u32 bit_l\
    \ = l >> BIT_BLOCK_SIZE;\n            if (bit) vec[bit_l] |=   1U << (l & (BIT_BLOCK_NUM-1));\n\
    \            else     vec[bit_l] &= ~(1U << (l & (BIT_BLOCK_NUM-1)));\n      \
    \  }\n        //[l,l+1)\n        bool operator[](const u32 l) const {\n      \
    \      return ((vec[l >> BIT_BLOCK_SIZE] >> (l & (BIT_BLOCK_NUM-1))) & 1);\n \
    \       }\n    };\n    vector<u32> Zarts(const vector<T>& ar) {\n        vector<u32>\
    \ ord(ar.size()),compressed(ar.size());\n        iota(ord.begin(),ord.end(),0);\n\
    \        sort(ord.begin(),ord.end(),[&](size_t l, size_t r){return ar[l]<ar[r];});\n\
    \        u32 cnt = 0;\n        compressed.front() = 0;\n        T pre = ar[ord.front()];\n\
    \        for(size_t i=1;i<ord.size();++i) {\n            size_t j=ord[i];\n  \
    \          if(pre < ar[j]) ++cnt;\n            compressed[j] = cnt;\n        \
    \    pre = ar[j];\n        }\n        return compressed;\n    }\n    size_t length;\n\
    \    size_t depth;\n    vector<BitVector> multi_bit_vector;\n    vector<u32> sum_bit_off;\n\
    \    vector<T> vec;\n\n    inline T get_impl(u32 l) const {\n        u32 val =\
    \ 0;\n        for (u32 j = 0; j < depth; ++j) {\n            const bool bit =\
    \ multi_bit_vector[j][l];\n            val = ((val << 1) | bit);\n           \
    \ l = multi_bit_vector[j].rank(l, bit);\n            if(bit) l += sum_bit_off[j];\n\
    \        }\n        return vec[val];\n    }\n    inline T range_kth_smallest_impl(u32\
    \ l, u32 r, u32 k) const {\n        u32 val = 0;\n        for (u32 j = 0; j <\
    \ depth; ++j) {\n            u32 cnt_bit_off = multi_bit_vector[j].rank(r, 0)\
    \ - multi_bit_vector[j].rank(l, 0);\n            const bool bit = (k >= cnt_bit_off);\n\
    \            val = ((val << 1) | bit);\n            l = multi_bit_vector[j].rank(l,\
    \ bit);\n            r = multi_bit_vector[j].rank(r, bit);\n            if (bit)\
    \ l += sum_bit_off[j], r += sum_bit_off[j], k -= cnt_bit_off;\n        }\n   \
    \     return vec[val];\n    }\n    void build() {\n        length = vec.size();\n\
    \        auto compressed = Zarts(vec);\n        sort(vec.begin(),vec.end());\n\
    \        vec.erase(unique(vec.begin(),vec.end()),vec.end());\n        u32 maxi\
    \ = *max_element(compressed.begin(),compressed.end()) + 1;\n        for(depth=0;\
    \ (1<<depth) <= maxi; ++depth );\n\n        multi_bit_vector.assign(depth, BitVector(length));\n\
    \        sum_bit_off.assign(depth, 0UL);\n        vector<u32> prev = compressed,\
    \ next = prev;\n        for(u32 j = 0; j < depth; ++j,swap(prev,next)) {\n   \
    \         u32 bit = 1UL << (depth - j - 1);\n            for(u32 i = 0; i < length;\
    \ ++i) sum_bit_off[j] += !(prev[i] & bit);\n            u32 idx_bit_off = 0, idx_bit_on\
    \ = sum_bit_off[j];\n            for(u32 i = 0; i < length; ++i) {\n         \
    \       if (prev[i] & bit) multi_bit_vector[j].update(i,1), next[idx_bit_on++]\
    \ = prev[i];\n                else next[idx_bit_off++] = prev[i];\n          \
    \  }\n            multi_bit_vector[j].build();\n        }\n    }\n    //[l,r)\
    \ range count of more and less than c (c'<c, c'=c, c<c')\n    // tuple<uint32,\
    \ uint32, uint32> rank_all(T c, uint32 l, uint32 r) const\n    // {\n    // \t\
    if (c > vec.back()) return make_tuple(r - l, 0U, 0U);\n    // \tarray<uint32,2>\
    \ more_and_less = {0,0};\n    // \tfor (uint32 j = 0; j < depth; ++j) {\n    //\
    \ \t\tconst bool bit = (c >> (depth - j - 1)) & 1;\n    // \t\tmore_and_less[bit]\
    \ += r - l;\n    // \t\tl = multi_bit_vector[j].rank(l, bit);\n    // \t\tr =\
    \ multi_bit_vector[j].rank(r, bit);\n    // \t\tif (bit) l += sum_bit_off[j],\
    \ r += sum_bit_off[j];\n    // \t\tmore_and_less[bit] -= r - l;\n    // \t}\n\
    \    // \treturn make_tuple(more_and_less[1], r - l, more_and_less[0]);\n    //\
    \ }\npublic:\n    WaveletMatrix(const vector<T> &vec): vec(vec) { build(); }\n\
    \    //[l,l+1) element\n    inline T get(const u32 l) const {return get_impl(l);}\n\
    \    //[l,r) range k (0-indexed) th smallest number\n    T range_kth_smallest(const\
    \ u32 l, const u32 r, const u32 k) const {return range_kth_smallest_impl(l,r,k);}\n\
    };\n#line 12 \"test/static-range-query/WaveletMatrix-quantile-1.test.cpp\"\n\n\
    int main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    vector<long long> A(N);\n    for(int i=0;i<N;++i) read(A[i]);\n\
    \    WaveletMatrix<long long> wm(A);\n    while(Q--) {\n        int l,r,k; read(l);\
    \ read(r); read(k);\n        cout << wm.range_kth_smallest(l,r,k) << \"\\n\";\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <numeric>\nusing namespace std;\n\n#include \"../../lib/00-util/FastIO.cpp\"\
    \n#include \"../../lib/13-static-range-query/WaveletMatrix.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N); read(Q);\n\
    \    vector<long long> A(N);\n    for(int i=0;i<N;++i) read(A[i]);\n    WaveletMatrix<long\
    \ long> wm(A);\n    while(Q--) {\n        int l,r,k; read(l); read(r); read(k);\n\
    \        cout << wm.range_kth_smallest(l,r,k) << \"\\n\";\n    }\n    return 0;\n\
    }"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/13-static-range-query/WaveletMatrix.cpp
  isVerificationFile: true
  path: test/static-range-query/WaveletMatrix-quantile-1.test.cpp
  requiredBy: []
  timestamp: '2023-06-08 03:48:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static-range-query/WaveletMatrix-quantile-1.test.cpp
layout: document
redirect_from:
- /verify/test/static-range-query/WaveletMatrix-quantile-1.test.cpp
- /verify/test/static-range-query/WaveletMatrix-quantile-1.test.cpp.html
title: test/static-range-query/WaveletMatrix-quantile-1.test.cpp
---
