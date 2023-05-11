---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/range-query/RangeInversionQuery.test.cpp
    title: test/data-structure/range-query/RangeInversionQuery.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/range-query/RangeInversionQuery.md
    document_title: "RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/range-query/RangeInversionQuery.cpp\"\
    \n/*\n * @title RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570\n * @docs\
    \ md/data-structure/range-query/RangeInversionQuery.md\n */\ntemplate<class T>\
    \ class RangeInversionQuery {\n    vector<size_t> compressed;\n    vector<long\
    \ long> prefix_inv;\n    vector<long long> suffix_inv;\n    vector<vector<long\
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
    \ inv += sum;\n            }\n        }\n        return inv;\n    }\n};\n"
  code: "/*\n * @title RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570\n * @docs\
    \ md/data-structure/range-query/RangeInversionQuery.md\n */\ntemplate<class T>\
    \ class RangeInversionQuery {\n    vector<size_t> compressed;\n    vector<long\
    \ long> prefix_inv;\n    vector<long long> suffix_inv;\n    vector<vector<long\
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
    \ inv += sum;\n            }\n        }\n        return inv;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/range-query/RangeInversionQuery.cpp
  requiredBy: []
  timestamp: '2021-09-21 03:50:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/range-query/RangeInversionQuery.test.cpp
documentation_of: lib/data-structure/range-query/RangeInversionQuery.cpp
layout: document
redirect_from:
- /library/lib/data-structure/range-query/RangeInversionQuery.cpp
- /library/lib/data-structure/range-query/RangeInversionQuery.cpp.html
title: "RangeInversionQuery - \u533A\u9593\u8EE2\u5012\u6570"
---
### RangeInversionQuery
- 区間転倒数
  - 半開区間[l,r)に対する転倒数を求める。
  - クエリはオンラインでも可。
  - 列の更新は出来ない。

### コンストラクタ
- RangeInversionQuery(const vector<T>& ar, T pre=-1)
  - 列と、列に含まれない最小値preを渡す必要がある。
  - これは座圧を内部的に行うため、最小を定義する必要がある。
  - ソートできる列であれば何でも渡せる
  - $O(N\sqrt(N))$

### メソッド
- long long get(int l, int r)
  - 半開区間[l,r)に対する転倒数を返す
  - $O(\sqrt(N))$

### 参考資料
- なし
- 軽い理論は下記
- 前計算パート
  - 座圧
  - バケット内で、prefix,suffixの転倒数を求める(これはBITでリセットしながらやるだけ)
  - 各数のfreqを、バケットごとに区切って求めて累積和をとっておく(ここややこしい)
    - 感覚的には、O(N)のfreqのメモがsqrt(N)個ある感じ。
    - これを小さい数から累積和取っておく(ある数以下の分布の総和をO(1)で求めたいため)
  - 平方分割して、各バケット連続区間の転倒数を求める
    - 区間数O(sqrt(N)* sqrt(N)) = O(N)のやつ
    - うまくやると、1区間 O(sqrt(N)) で求まるので、全体でO(N \sqrt(N))
    - 転倒数のマージを思い出して、区間dpチックにやろう。
- クエリパート
  - 中側のバケット部分は雑に取得
  - 左右のバケットからはみ出た部分を、処理する。
  - 左側から、中側のバケット部分への寄与はO(\sqrt(N))
  - 右側から、中側のバケット部分への寄与もO(\sqrt(N))
  - 左側から右側、ここが難しいけどちゃんと考えるとO(\sqrt(N))
  - バケット内で値でソートしたindexの列を前計算しておく
    - 左右の列両方見ながら、値が小さいやつを処理していって、indexで区間[l,r)に入ってるか確認すると転倒数寄与が出せる。
- [l,r)の転倒数 = [l,c)の転倒数 + [c,r)の転倒数 + [l,c)の[c,r)に対する寄与
  - 基本的にはこれだけ。