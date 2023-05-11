---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
    title: BinaryIndexedTree - BIT
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/range-query/RangeInversionQuery.cpp
    title: "RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: lib/operator/abel/AbelPrefixSumPointAdd.cpp
    title: AbelPrefixSumPointAdd
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/data-structure/range-query/RangeInversionQuery.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <cmath>\nusing namespace std;\n#line 1 \"lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n/*\n * @title BinaryIndexedTree - BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTree {\n    using TypeNode = typename\
    \ Abel::TypeNode;\n    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n\
    public:\n\n    //[0,N) constructed, inplace [0,1) + [1,N+1)\n    //you can ignore\
    \ inplace offset\n    BinaryIndexedTree(const size_t num) : num(num) {\n     \
    \   for (length = 1; length < num; length *= 2);\n        node.resize(length+1,\
    \ Abel::unit_node);\n    }\n\n    //[idx,idx+1) operate\n    void operate(size_t\
    \ idx, TypeNode var) {\n        assert(0 <= idx && idx < length);\n        for\
    \ (++idx; idx <= length; idx += idx & -idx) node[idx] = Abel::func_fold(node[idx],var);\n\
    \    }\n\n    //[0,idx) fold\n    TypeNode fold(size_t idx) {\n        TypeNode\
    \ ret = Abel::unit_node;\n        for (idx = min(length,idx); idx > 0; idx -=\
    \ idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n        return ret;\n   \
    \ }\n\n    //return [0,length]\n    int binary_search(TypeNode var) {\n      \
    \  if(!Abel::func_check(node.back(),var)) return num;\n        TypeNode ret =\
    \ Abel::unit_node;\n        size_t off = 0;\n        for(size_t idx = length;\
    \ idx; idx >>= 1){\n            if(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var))\
    \ {\n                off += idx;\n                ret = Abel::func_fold(ret,node[off]);\n\
    \            }\n        }\n        return min(off,num);\n    }\n\n    void print()\
    \ {\n        cout << \"{ \" << fold(1);\n        for(int i = 1; i < length; ++i)\
    \ cout << \", \" << fold(i+1);\n        cout << \" }\" << endl;\n    }\n};\n#line\
    \ 1 \"lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n/*\n * @title AbelPrefixSumPointAdd\n\
    \ * @docs md/operator/abel/AbelPrefixSumPointAdd.md\n */\ntemplate<class T> struct\
    \ AbelPrefixSumPointAdd {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(const\
    \ TypeNode& l,const TypeNode& r){return l+r;}\n    inline static constexpr TypeNode\
    \ func_fold_inv(const TypeNode& l,const TypeNode& r){return l-r;}\n};\n#line 1\
    \ \"lib/data-structure/range-query/RangeInversionQuery.cpp\"\n/*\n * @title RangeInversionQuery\
    \ - \u533A\u9593\u8EE2\u5012\u6570\n * @docs md/data-structure/range-query/RangeInversionQuery.md\n\
    \ */\ntemplate<class T> class RangeInversionQuery {\n    vector<size_t> compressed;\n\
    \    vector<long long> prefix_inv;\n    vector<long long> suffix_inv;\n    vector<vector<long\
    \ long>> sqrt_bucket_freq;\n    vector<long long> sqrt_bucket_inv;\n    vector<vector<size_t>>\
    \ sqrt_bucket_sort_index;\n    vector<long long> sqrt_bucket_size;\n    size_t\
    \ N,B,M;\npublic:\n    RangeInversionQuery(const vector<T>& ar, T pre=-1)\n  \
    \          : compressed(ar.size()),prefix_inv(ar.size()),suffix_inv(ar.size())\
    \ {\n        N = ar.size();\n        B = sqrt(N) + 1; // bucket size\n       \
    \ M = N / B + 1;   // bucket num\n        //zarts\n        {\n            vector<pair<T,size_t>>\
    \ ord(N);\n            for(size_t i=0;i<N;++i) ord[i]={ar[i],i};\n           \
    \ sort(ord.begin(),ord.end());\n            size_t inc=0;\n            for(size_t\
    \ i=0;i<N;++i) {\n                if(pre < ord[i].first) inc++;\n            \
    \    compressed[ord[i].second] = inc;\n                pre = ord[i].first;\n \
    \           }\n        }\n        //freq\n        {\n            sqrt_bucket_freq.resize(M);\n\
    \            vector<long long> freq(N+1,0);\n            for(size_t i=0;i<M;++i)\
    \ {\n                size_t l = i*B, r = min((i+1)*B,N);\n                for(size_t\
    \ j=l;j<r;++j) freq[compressed[j]]++;\n                sqrt_bucket_freq[i] = freq;\n\
    \                for(size_t j=1;j<=N;++j) sqrt_bucket_freq[i][j]+=sqrt_bucket_freq[i][j-1];\n\
    \            }\n        }\n        //prefix,suffix inv\n        {\n          \
    \  BinaryIndexedTree<AbelPrefixSumPointAdd<long long>> bit(N+1);\n           \
    \ for(size_t i=0;i<M;++i) {\n                int l = i*B, r = min((i+1)*B,N);\n\
    \                //prefix\n                {\n                    long long inv\
    \ = 0;\n                    for(size_t j=l;j<r;++j) {\n                      \
    \  inv += bit.fold(N+1)-bit.fold(compressed[j]+1);\n                        prefix_inv[j]=inv;\n\
    \                        bit.operate(compressed[j],1);\n                    }\n\
    \                    for(size_t j=l;j<r;++j) {\n                        bit.operate(compressed[j],-1);\n\
    \                    }\n                }\n                //suffix\n        \
    \        {\n                    long long inv = 0;\n                    for(int\
    \ j=r-1;l<=j;--j) {\n                        inv += bit.fold(compressed[j]);\n\
    \                        suffix_inv[j]=inv;\n                        bit.operate(compressed[j],1);\n\
    \                    }\n                    for(size_t j=l;j<r;++j) {\n      \
    \                  bit.operate(compressed[j],-1);\n                    }\n   \
    \             }\n            }\n        }\n        //sqrt bucket inv\n       \
    \ {\n            sqrt_bucket_inv.resize(M*M,0);\n            for(size_t i=0;i<M;++i)\
    \ {\n                size_t l = i*B, r = min((i+1)*B,N);\n                if(l<r)\
    \ sqrt_bucket_inv[i*M+i] = prefix_inv[r-1];\n            }\n            for(size_t\
    \ k=1;k<M;++k) {\n                for(size_t i=0;i+k<M;++i) {\n              \
    \      sqrt_bucket_inv[i*M+i+k] += sqrt_bucket_inv[i*M+i]+sqrt_bucket_inv[(i+1)*M+i+k];\n\
    \                    size_t l = i*B, r = min((i+1)*B,N);\n                   \
    \ for(size_t j=l;j<r;++j) {\n                        size_t& c = compressed[j];\n\
    \                        sqrt_bucket_inv[i*M+i+k] += (sqrt_bucket_freq[i+k][c-1]-sqrt_bucket_freq[i][c-1]);\n\
    \                    }\n                }\n            }\n        }\n        //sort\n\
    \        {\n            sqrt_bucket_sort_index.resize(M);\n            sqrt_bucket_size.resize(M,0);\n\
    \            size_t sz = 0;\n            for(size_t i=0;i<M;++i) {\n         \
    \       int l = i*B, r = min((i+1)*B,N);\n                sz += max(0,(r-l));\n\
    \                sqrt_bucket_size[i] = sz;\n                if(r-l<1) continue;\n\
    \                sqrt_bucket_sort_index[i].resize(r-l);\n                for(size_t\
    \ j=l;j<r;++j) sqrt_bucket_sort_index[i][j-l]=j;\n                sort(sqrt_bucket_sort_index[i].begin(),sqrt_bucket_sort_index[i].end(),\n\
    \                     [&](size_t l,size_t r){return compressed[l]==compressed[r]?l<r:compressed[l]<compressed[r];});\n\
    \            }\n        }\n    }\n    //query [l,r)\n    //return {freq,mode}\
    \ ({\u983B\u5EA6,\u5143\u306E\u914D\u5217\u306B\u304A\u3051\u308B\u5024})\n  \
    \  long long fold(int l, int r) {\n        int bl = l/B + 1, br = (r-1)/B - 1;\n\
    \        long long inv = 0;\n        //\u540C\u3058bucket\u306Bl,r\u304C\u3042\
    \u308B\u3068\u304D\n        if(bl > br + 1) {\n            inv += prefix_inv[r-1];\n\
    \            if(l%B) inv -= prefix_inv[l-1];\n            long long sum = 0;\n\
    \            for(size_t i: sqrt_bucket_sort_index[l/B]) {\n                if(r\
    \ <= i) continue;\n                if(l <= i) sum++;\n                else inv\
    \ -= sum;\n            }\n        }\n        else {\n            inv += sqrt_bucket_inv[bl*M+br];\n\
    \            inv += suffix_inv[l];\n            inv += prefix_inv[r-1];\n    \
    \        size_t ml = bl*B;\n            for(size_t i=l;i<ml;++i) {\n         \
    \       size_t& c = compressed[i];\n                inv += sqrt_bucket_freq[br][c-1]-sqrt_bucket_freq[bl-1][c-1];\n\
    \            }\n            size_t mr = (br+1)*B;\n            for(size_t i=mr;i<r;++i)\
    \ {\n                size_t& c = compressed[i];\n                inv += (sqrt_bucket_size[br]-sqrt_bucket_freq[br][c])-(sqrt_bucket_size[bl-1]-sqrt_bucket_freq[bl-1][c]);\n\
    \            }\n            int ir = 0, nr = sqrt_bucket_sort_index[br+1].size();\n\
    \            long long sum = 0;\n            for(auto& xl:sqrt_bucket_sort_index[bl-1])\
    \ {\n                if(xl < l) continue;\n                for(;ir<nr;++ir) {\n\
    \                    auto& xr = sqrt_bucket_sort_index[br+1][ir];\n          \
    \          if(xr >= r) continue;\n                    if(compressed[xl] > compressed[xr])\
    \ sum++;\n                    else break;\n                }\n               \
    \ inv += sum;\n            }\n        }\n        return inv;\n    }\n};\n#line\
    \ 12 \"test/data-structure/range-query/RangeInversionQuery.test.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false); \n    int N,Q; cin >> N >> Q;\n \
    \   vector<long long> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    RangeInversionQuery<long\
    \ long> riq(A);\n    while(Q--) {\n        int l,r; cin >> l >> r;\n        long\
    \ long inv = riq.fold(l,r);\n        cout << inv << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <cmath>\nusing namespace std;\n#include \"../../../lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n#include \"../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n#include\
    \ \"../../../lib/data-structure/range-query/RangeInversionQuery.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false); \n    int N,Q; cin >> N >> Q;\n \
    \   vector<long long> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    RangeInversionQuery<long\
    \ long> riq(A);\n    while(Q--) {\n        int l,r; cin >> l >> r;\n        long\
    \ long inv = riq.fold(l,r);\n        cout << inv << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
  - lib/operator/abel/AbelPrefixSumPointAdd.cpp
  - lib/data-structure/range-query/RangeInversionQuery.cpp
  isVerificationFile: true
  path: test/data-structure/range-query/RangeInversionQuery.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:44:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/range-query/RangeInversionQuery.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/range-query/RangeInversionQuery.test.cpp
- /verify/test/data-structure/range-query/RangeInversionQuery.test.cpp.html
title: test/data-structure/range-query/RangeInversionQuery.test.cpp
---
