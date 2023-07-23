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
    PROBLEM: https://yukicoder.me/problems/no/919
    links:
    - https://yukicoder.me/problems/no/919
  bundledCode: "#line 1 \"test/static-range-query/WaveletMatrix-range-kth-2.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <algorithm>\n#include <numeric>\n\
    using namespace std;\n\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n\
    \ * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n    inline static constexpr\
    \ int ch_0='0';\n    inline static constexpr int ch_9='9';\n    inline static\
    \ constexpr int ch_n='-';\n    inline static constexpr int ch_s=' ';\n    inline\
    \ static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
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
    \ int;\n\n    class BitVector{\n        inline static constexpr size_t BIT_BLOCK_SIZE\
    \ = 5;\n        inline static constexpr size_t BIT_BLOCK_NUM  = (1<<BIT_BLOCK_SIZE)\
    \ - 1; //31\n        vector<u32> ar, acc;\n        u32 popcount(u32 x) const {return\
    \ __builtin_popcount(x);}\n        u32 length;\n    public:\n        u32 sum_bit0;\n\
    \        BitVector(const u32 N): length(N) {\n            u32 tmp = (N + BIT_BLOCK_NUM)\
    \ / (BIT_BLOCK_NUM+1);\n            ar.assign(tmp, 0);\n            acc.assign(tmp,\
    \ 0);\n        }\n        void build() { \n            for (size_t i = 0,sum =\
    \ 0; i < acc.size(); ++i) acc[i] = (sum += popcount(ar[i]) );\n            sum_bit0\
    \ = rank(length, 0);\n        }\n        //[0,r) count of bit\n        u32 rank(const\
    \ u32 r, const bool bit) const {\n            u32 bit_r = r >> BIT_BLOCK_SIZE;\
    \ \n            u32 sum = (bit_r ? acc[bit_r - 1] : 0) + popcount(ar[bit_r] &\
    \ ((1U << (r & BIT_BLOCK_NUM)) - 1));\n            return bit ? sum : r - sum;\n\
    \        }\n        //[l,l+1) = bit\n        void update(const u32 l, const bool\
    \ bit) {\n            u32 bit_l = l >> BIT_BLOCK_SIZE;\n            if (bit) ar[bit_l]\
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
    };\n#line 12 \"test/static-range-query/WaveletMatrix-range-kth-2.test.cpp\"\n\n\
    void chmax(long long& a,long long b){a=max(a,b);}\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \tint N; read(N);\n    vector<long long> A(N);\n\tfor(int i = 0; i < N; ++i) read(A[i]);\n\
    \    WaveletMatrix<long long> wm(A);\n\n\t//\u30AF\u30A8\u30EA\u533A\u9593\u3092\
    \u5217\u6319\u3001\u8ABF\u548C\u7D1A\u6570\u306A\u306E\u3067O(N*logN)\n\tvector<pair<int,int>>\
    \ range;\n\tfor(int j = 1; j <= N; ++j) {\n\t\tint M = N/j;\n\t\tfor(int i = 0;\
    \     i+j <= N; i+=j) range.push_back({i,i+j});\n\t\tfor(int i = N-M*j; i+j <=\
    \ N; i+=j) range.push_back({i,i+j});\n\t}\n\n\tlong long ans = 0;\n\tint cnt =\
    \ 0;\n\t//\u533A\u9593\u9577\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22O(N*logN)\n\
    \tfor(long long n = 1; n <= N; ++n) {\n\t\tint M = N/n;\n\t\tvector<long long>\
    \ lSum(M,0),rSum(M,0);\n\t\tvector<pair<int, int>> l_range(M),r_range(M);\n\t\t\
    //\u533A\u9593\u53D6\u5F97 O(M)\n\t\tfor(int i = 0; i < M; ++i) {\n\t\t\tl_range[i]\
    \ = range[cnt + i];\n\t\t\tlSum[i]   = n*wm.range_kth_smallest(l_range[i].first,l_range[i].second,(l_range[i].second-l_range[i].first-1)/2)\
    \ ;\n\t\t\tr_range[i] = range[cnt + i + M];\n\t\t\trSum[i]   = n*wm.range_kth_smallest(r_range[i].first,r_range[i].second,(r_range[i].second-r_range[i].first-1)/2);\n\
    \t\t}\n\t\t//\u7D2F\u7A4D\u548C O(M)\n\t\tfor(int i = 1;    i < M; ++i) lSum[i]\
    \  += lSum[i-1];\n\t\tfor(int i = M-2; 0 <= i; --i) rSum[i]  += rSum[i+1];\n\t\
    \t//\u7D2F\u7A4Dmax O(M)\n\t\tfor(int i = 1;    i < M; ++i) chmax(lSum[i],lSum[i-1]);\n\
    \t\tfor(int i = M-2; 0 <= i; --i) chmax(rSum[i],rSum[i+1]);\n\n\t\tchmax(ans,lSum[M-1]);\n\
    \t\tchmax(ans,rSum[0]);\n\n\t\t//\u5C3A\u53D6\u308A\u3057\u306A\u304C\u3089\u5DE6\
    \u53F3\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22 O(M)\n\t\tint j = 0;\n\t\tfor(int\
    \ i = 0; i < M; ++i) {\n\t\t\twhile(j < M && l_range[i].second-1 >= r_range[j].first)\
    \ j++;\n\t\t\tif(j<M && l_range[i].second-1 < r_range[j].first) {\n\t\t\t\tchmax(ans,lSum[i]+rSum[j]);\n\
    \t\t\t}\n\t\t}\n\t\tcnt += 2*M;\n\t}\n\tcout << ans << endl;\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <algorithm>\n#include <numeric>\n\
    using namespace std;\n\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"\
    ../../lib/13-static-range-query/WaveletMatrix.cpp\"\n\nvoid chmax(long long& a,long\
    \ long b){a=max(a,b);}\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \tint N; read(N);\n    vector<long long> A(N);\n\tfor(int i = 0; i < N; ++i) read(A[i]);\n\
    \    WaveletMatrix<long long> wm(A);\n\n\t//\u30AF\u30A8\u30EA\u533A\u9593\u3092\
    \u5217\u6319\u3001\u8ABF\u548C\u7D1A\u6570\u306A\u306E\u3067O(N*logN)\n\tvector<pair<int,int>>\
    \ range;\n\tfor(int j = 1; j <= N; ++j) {\n\t\tint M = N/j;\n\t\tfor(int i = 0;\
    \     i+j <= N; i+=j) range.push_back({i,i+j});\n\t\tfor(int i = N-M*j; i+j <=\
    \ N; i+=j) range.push_back({i,i+j});\n\t}\n\n\tlong long ans = 0;\n\tint cnt =\
    \ 0;\n\t//\u533A\u9593\u9577\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22O(N*logN)\n\
    \tfor(long long n = 1; n <= N; ++n) {\n\t\tint M = N/n;\n\t\tvector<long long>\
    \ lSum(M,0),rSum(M,0);\n\t\tvector<pair<int, int>> l_range(M),r_range(M);\n\t\t\
    //\u533A\u9593\u53D6\u5F97 O(M)\n\t\tfor(int i = 0; i < M; ++i) {\n\t\t\tl_range[i]\
    \ = range[cnt + i];\n\t\t\tlSum[i]   = n*wm.range_kth_smallest(l_range[i].first,l_range[i].second,(l_range[i].second-l_range[i].first-1)/2)\
    \ ;\n\t\t\tr_range[i] = range[cnt + i + M];\n\t\t\trSum[i]   = n*wm.range_kth_smallest(r_range[i].first,r_range[i].second,(r_range[i].second-r_range[i].first-1)/2);\n\
    \t\t}\n\t\t//\u7D2F\u7A4D\u548C O(M)\n\t\tfor(int i = 1;    i < M; ++i) lSum[i]\
    \  += lSum[i-1];\n\t\tfor(int i = M-2; 0 <= i; --i) rSum[i]  += rSum[i+1];\n\t\
    \t//\u7D2F\u7A4Dmax O(M)\n\t\tfor(int i = 1;    i < M; ++i) chmax(lSum[i],lSum[i-1]);\n\
    \t\tfor(int i = M-2; 0 <= i; --i) chmax(rSum[i],rSum[i+1]);\n\n\t\tchmax(ans,lSum[M-1]);\n\
    \t\tchmax(ans,rSum[0]);\n\n\t\t//\u5C3A\u53D6\u308A\u3057\u306A\u304C\u3089\u5DE6\
    \u53F3\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22 O(M)\n\t\tint j = 0;\n\t\tfor(int\
    \ i = 0; i < M; ++i) {\n\t\t\twhile(j < M && l_range[i].second-1 >= r_range[j].first)\
    \ j++;\n\t\t\tif(j<M && l_range[i].second-1 < r_range[j].first) {\n\t\t\t\tchmax(ans,lSum[i]+rSum[j]);\n\
    \t\t\t}\n\t\t}\n\t\tcnt += 2*M;\n\t}\n\tcout << ans << endl;\n\n    return 0;\n\
    }\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/13-static-range-query/WaveletMatrix.cpp
  isVerificationFile: true
  path: test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
  requiredBy: []
  timestamp: '2023-06-10 18:11:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
layout: document
redirect_from:
- /verify/test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
- /verify/test/static-range-query/WaveletMatrix-range-kth-2.test.cpp.html
title: test/static-range-query/WaveletMatrix-range-kth-2.test.cpp
---