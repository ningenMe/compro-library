---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/BinaryIndexedTree.cpp
    title: BinaryIndexedTree
  - icon: ':heavy_check_mark:'
    path: lib/segment/RangeInversionQuery.cpp
    title: "RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570"
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
  bundledCode: "#line 1 \"test/segment/RangeInversionQuery.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n#include\
    \ <cmath>\nusing namespace std;\n#line 1 \"lib/segment/BinaryIndexedTree.cpp\"\
    \n/*\n * @title BinaryIndexedTree\n * @docs md/segment/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Operator> class BinaryIndexedTree {\n\tusing TypeNode = typename\
    \ Operator::TypeNode;\n\tsize_t depth;         \n\tsize_t length;\n\tsize_t num;\n\
    \tvector<TypeNode> node;\npublic:\n\t\n\t//[0,N) constructed, inplace [0,1) +\
    \ [1,N+1)\n\t//you can ignore inplace offset\n\tBinaryIndexedTree(const size_t\
    \ num) : num(num) {\n\t\tfor (depth = 1,length = 1; length < num; depth++,length\
    \ *= 2);\n\t\tnode.resize(length+1, Operator::unit_node);\n\t}\n \n\t//[idx,idx+1)\
    \ update \n\tvoid update(size_t idx, TypeNode var) {\n\t\tassert(0 <= idx && idx\
    \ < length);\n\t\tfor (++idx; idx <= length; idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);\n\
    \t}\n\n\t//[0,idx) get\n\tTypeNode get(size_t idx) {\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tfor (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint binary_search(TypeNode var)\
    \ {\n\t\tif(!Operator::func_check(node.back(),var)) return num;\n\t\tTypeNode\
    \ ret = Operator::unit_node;\n\t\tsize_t off = 0;\n\t\tfor(size_t idx = length;\
    \ idx; idx >>= 1){\n\t\t\tif(off + idx <= length && !Operator::func_check(Operator::func_node(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Operator::func_node(ret,node[off]);\n\t\
    \t\t}\n\t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"\
    { \" << get(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n\
    \t\tcout << \" }\" << endl;\n\t}\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd\
    \ {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\
    \tinline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return l+r;}\n\t// Binary Search for first index where func_check is true\n\
    \tinline static constexpr bool func_check(const TypeNode nodeVal,const TypeNode&\
    \ val){return val <= nodeVal;}\n};\n\ntemplate<class TypeNode> struct NodeUpdatePrefixGcd\
    \ {\n\tTypeNode unit_node = 0;\n\tTypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return ((r == 0) ? l : func_node(r, l % r));}\n\t// Binary Search for first\
    \ index at where func_check is true\n\tbool func_check(const TypeNode nodeVal,const\
    \ TypeNode& var){return var == nodeVal;}\n};\n#line 1 \"lib/segment/RangeInversionQuery.cpp\"\
    \n/*\n * @title RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570\n * @docs\
    \ md/segment/RangeInversionQuery.md\n */\ntemplate<class T> class RangeInversionQuery\
    \ {\n    vector<size_t> compressed;\n    vector<long long> prefix_inv;\n    vector<long\
    \ long> suffix_inv;\n    vector<vector<long long>> sqrt_bucket_freq;\n    vector<long\
    \ long> sqrt_bucket_inv;\n    vector<vector<size_t>> sqrt_bucket_sort_index;\n\
    \    vector<long long> sqrt_bucket_size;\n    size_t N,B,M;\npublic:\n    RangeInversionQuery(const\
    \ vector<T>& ar, T pre=-1)\n    : compressed(ar.size()),prefix_inv(ar.size()),suffix_inv(ar.size())\
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
    \  BinaryIndexedTree<NodePrefixSumPointAdd<long long>> bit(N+1);\n           \
    \ for(size_t i=0;i<M;++i) {\n                int l = i*B, r = min((i+1)*B,N);\n\
    \                //prefix\n                {\n                    long long inv\
    \ = 0;\n                    for(size_t j=l;j<r;++j) {\n                      \
    \  inv += bit.get(N+1)-bit.get(compressed[j]+1);\n                        prefix_inv[j]=inv;\n\
    \                        bit.update(compressed[j],1);\n                    }\n\
    \                    for(size_t j=l;j<r;++j) {\n                        bit.update(compressed[j],-1);\n\
    \                    }\n                }\n                //suffix\n        \
    \        {\n                    long long inv = 0;\n                    for(int\
    \ j=r-1;l<=j;--j) {\n                        inv += bit.get(compressed[j]);\n\
    \                        suffix_inv[j]=inv;\n                        bit.update(compressed[j],1);\n\
    \                    }\n                    for(size_t j=l;j<r;++j) {\n      \
    \                  bit.update(compressed[j],-1);\n                    }\n    \
    \            }\n            }\n        }\n        //sqrt bucket inv\n        {\n\
    \            sqrt_bucket_inv.resize(M*M,0);\n            for(size_t i=0;i<M;++i)\
    \ {\n                size_t l = i*B, r = min((i+1)*B,N);\n                if(l<r)\
    \ sqrt_bucket_inv[i*M+i] = prefix_inv[r-1];\n            }\n            for(size_t\
    \ k=1;k<M;++k) {\n                for(size_t i=0;i+k<M;++i) {\n              \
    \      sqrt_bucket_inv[i*M+i+k] += sqrt_bucket_inv[i*M+i]+sqrt_bucket_inv[(i+1)*M+i+k];\n\
    \                    size_t l = i*B, r = min((i+1)*B,N);\n                   \
    \ for(size_t j=l;j<r;++j) {\n                        size_t& c = compressed[j];\
    \ \n                        sqrt_bucket_inv[i*M+i+k] += (sqrt_bucket_freq[i+k][c-1]-sqrt_bucket_freq[i][c-1]);\n\
    \                    }\n                }\n            }\n        }\n        //sort\n\
    \        {\n            sqrt_bucket_sort_index.resize(M);\n            sqrt_bucket_size.resize(M,0);\n\
    \            size_t sz = 0;\n            for(size_t i=0;i<M;++i) {\n         \
    \       int l = i*B, r = min((i+1)*B,N);\n                sz += max(0,(r-l));\n\
    \                sqrt_bucket_size[i] = sz;\n                if(r-l<1) continue;\n\
    \                sqrt_bucket_sort_index[i].resize(r-l);\n                for(size_t\
    \ j=l;j<r;++j) sqrt_bucket_sort_index[i][j-l]=j;\n                sort(sqrt_bucket_sort_index[i].begin(),sqrt_bucket_sort_index[i].end(),\n\
    \                [&](size_t l,size_t r){return compressed[l]==compressed[r]?l<r:compressed[l]<compressed[r];});\n\
    \            }\n        }\n    }\n    //query [l,r)\n    //return {freq,mode}\
    \ ({\u983B\u5EA6,\u5143\u306E\u914D\u5217\u306B\u304A\u3051\u308B\u5024}) \n \
    \   long long get(int l, int r) {\n        int bl = l/B + 1, br = (r-1)/B - 1;\n\
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
    \ inv += sum;\n            }\n        }\n        return inv;\n    }\n}; \n#line\
    \ 11 \"test/segment/RangeInversionQuery.test.cpp\"\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\
    \ \n    int N,Q; cin >> N >> Q;\n    vector<long long> A(N);\n    for(int i=0;i<N;++i)\
    \ cin >> A[i];\n    RangeInversionQuery<long long> riq(A);\n    while(Q--) {\n\
    \        int l,r; cin >> l >> r;\n        long long inv = riq.get(l,r);\n    \
    \    cout << inv << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <cmath>\nusing namespace std;\n#include \"../../lib/segment/BinaryIndexedTree.cpp\"\
    \n#include \"../../lib/segment/RangeInversionQuery.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false); \n    int N,Q; cin >> N >> Q;\n \
    \   vector<long long> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    RangeInversionQuery<long\
    \ long> riq(A);\n    while(Q--) {\n        int l,r; cin >> l >> r;\n        long\
    \ long inv = riq.get(l,r);\n        cout << inv << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/segment/BinaryIndexedTree.cpp
  - lib/segment/RangeInversionQuery.cpp
  isVerificationFile: true
  path: test/segment/RangeInversionQuery.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 18:33:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/RangeInversionQuery.test.cpp
layout: document
redirect_from:
- /verify/test/segment/RangeInversionQuery.test.cpp
- /verify/test/segment/RangeInversionQuery.test.cpp.html
title: test/segment/RangeInversionQuery.test.cpp
---
