---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/static-range-query/StaticRangeModeQuery.md
    document_title: "StaticRangeModeQuery - \u9759\u7684\u533A\u9593\u6700\u983B\u5024\
      \u30AF\u30A8\u30EA"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/StaticRangeModeQuery.cpp\"\n/*\n\
    \ * @title StaticRangeModeQuery - \u9759\u7684\u533A\u9593\u6700\u983B\u5024\u30AF\
    \u30A8\u30EA\n * @docs md/static-range-query/StaticRangeModeQuery.md\n */\ntemplate<class\
    \ T> class StaticRangeModeQuery {\n    vector<size_t> compressed;\n    vector<T>\
    \ origin;\n    vector<vector<size_t>> sqrt_bucket_freq;\n    vector<vector<size_t>>\
    \ sqrt_bucket_mode;\n    vector<vector<size_t>> idx;\n    vector<int> pos;\n \
    \   size_t N,B;\npublic:\n    StaticRangeModeQuery(const vector<T>& ar, T pre=-1)\n\
    \            : compressed(ar.size()), origin(ar.size()), idx(ar.size()), pos(ar.size())\
    \ {\n        N = ar.size();\n        B = sqrt(N) + 1;\n        //zarts\n     \
    \   {\n            vector<pair<T,size_t>> ord(N);\n            for(size_t i=0;i<N;++i)\
    \ ord[i]={ar[i],i};\n            sort(ord.begin(),ord.end());\n            int\
    \ inc=-1;\n            for(size_t i=0;i<N;++i) {\n                if(pre < ord[i].first)\
    \ inc++;\n                compressed[ord[i].second] = inc;\n                pre\
    \ = ord[i].first;\n            }\n            for(size_t i=0;i<N;++i) origin[compressed[i]]\
    \ = ar[i];\n        }\n        //sqrt bucket\n        {\n            sqrt_bucket_freq.resize(B+1,vector<size_t>(B+1));\n\
    \            sqrt_bucket_mode.resize(B+1,vector<size_t>(B+1));\n            for(size_t\
    \ bl=0;bl*B<=N;++bl) {\n                vector<size_t> tmp(N,0);\n           \
    \     size_t maxi_freq = 0;\n                size_t maxi_mode = 0;\n         \
    \       for(size_t br = bl+1; br*B<=N;++br) {\n                    size_t l =\
    \ (br-1)*B, r = br*B;\n                    for(size_t i=l;i<r;++i) {\n       \
    \                 size_t a = compressed[i];\n                        ++tmp[a];\n\
    \                        if(maxi_freq < tmp[a]) {\n                          \
    \  maxi_freq = tmp[a];\n                            maxi_mode = a;\n         \
    \               }\n                    }\n                    sqrt_bucket_freq[bl][br]\
    \ = maxi_freq;\n                    sqrt_bucket_mode[bl][br] = maxi_mode;\n  \
    \              }\n            }\n        }\n        //idx,pos\n        {\n   \
    \         for(size_t i=0;i<N;++i) {\n                const size_t& key = compressed[i];\n\
    \                pos[i] = idx[key].size();\n                idx[key].push_back(i);\n\
    \            }\n        }\n    }\n    //query [l,r)\n    //return {freq,mode}\
    \ ({\u983B\u5EA6,\u5143\u306E\u914D\u5217\u306B\u304A\u3051\u308B\u5024})\n  \
    \  pair<size_t,T> get(int l, int r) {\n        int bl = l / B + !!(l%B), br =\
    \ r / B;\n        int ml = bl * B, mr = br * B;\n        ml = min(ml,r); mr =\
    \ max(l,mr);\n        size_t maxi_freq = sqrt_bucket_freq[bl][br];\n        size_t\
    \ maxi_mode = sqrt_bucket_mode[bl][br];\n        for(int i = l; i < ml; ++i) {\n\
    \            const size_t& key = compressed[i];\n            int freq = maxi_freq;\n\
    \            for(int j = pos[i] + freq; j < idx[key].size(); ++j) {\n        \
    \        if(idx[key][j] < r) {\n                    maxi_freq = j - pos[i] + 1;\n\
    \                    maxi_mode = key;\n                }\n                else\
    \ break;\n            }\n        }\n        for(int i = r-1; mr <= i; --i) {\n\
    \            const size_t& key = compressed[i];\n            int freq = maxi_freq;\n\
    \            for(int j = pos[i] - freq; 0 <= j; --j) {\n                if(l <=\
    \ idx[key][j]) {\n                    maxi_freq = pos[i] - j + 1;\n          \
    \          maxi_mode = key;\n                }\n                else break;\n\
    \            }\n        }\n        return {maxi_freq,origin[maxi_mode]};\n   \
    \ }\n};\n"
  code: "/*\n * @title StaticRangeModeQuery - \u9759\u7684\u533A\u9593\u6700\u983B\
    \u5024\u30AF\u30A8\u30EA\n * @docs md/static-range-query/StaticRangeModeQuery.md\n\
    \ */\ntemplate<class T> class StaticRangeModeQuery {\n    vector<size_t> compressed;\n\
    \    vector<T> origin;\n    vector<vector<size_t>> sqrt_bucket_freq;\n    vector<vector<size_t>>\
    \ sqrt_bucket_mode;\n    vector<vector<size_t>> idx;\n    vector<int> pos;\n \
    \   size_t N,B;\npublic:\n    StaticRangeModeQuery(const vector<T>& ar, T pre=-1)\n\
    \            : compressed(ar.size()), origin(ar.size()), idx(ar.size()), pos(ar.size())\
    \ {\n        N = ar.size();\n        B = sqrt(N) + 1;\n        //zarts\n     \
    \   {\n            vector<pair<T,size_t>> ord(N);\n            for(size_t i=0;i<N;++i)\
    \ ord[i]={ar[i],i};\n            sort(ord.begin(),ord.end());\n            int\
    \ inc=-1;\n            for(size_t i=0;i<N;++i) {\n                if(pre < ord[i].first)\
    \ inc++;\n                compressed[ord[i].second] = inc;\n                pre\
    \ = ord[i].first;\n            }\n            for(size_t i=0;i<N;++i) origin[compressed[i]]\
    \ = ar[i];\n        }\n        //sqrt bucket\n        {\n            sqrt_bucket_freq.resize(B+1,vector<size_t>(B+1));\n\
    \            sqrt_bucket_mode.resize(B+1,vector<size_t>(B+1));\n            for(size_t\
    \ bl=0;bl*B<=N;++bl) {\n                vector<size_t> tmp(N,0);\n           \
    \     size_t maxi_freq = 0;\n                size_t maxi_mode = 0;\n         \
    \       for(size_t br = bl+1; br*B<=N;++br) {\n                    size_t l =\
    \ (br-1)*B, r = br*B;\n                    for(size_t i=l;i<r;++i) {\n       \
    \                 size_t a = compressed[i];\n                        ++tmp[a];\n\
    \                        if(maxi_freq < tmp[a]) {\n                          \
    \  maxi_freq = tmp[a];\n                            maxi_mode = a;\n         \
    \               }\n                    }\n                    sqrt_bucket_freq[bl][br]\
    \ = maxi_freq;\n                    sqrt_bucket_mode[bl][br] = maxi_mode;\n  \
    \              }\n            }\n        }\n        //idx,pos\n        {\n   \
    \         for(size_t i=0;i<N;++i) {\n                const size_t& key = compressed[i];\n\
    \                pos[i] = idx[key].size();\n                idx[key].push_back(i);\n\
    \            }\n        }\n    }\n    //query [l,r)\n    //return {freq,mode}\
    \ ({\u983B\u5EA6,\u5143\u306E\u914D\u5217\u306B\u304A\u3051\u308B\u5024})\n  \
    \  pair<size_t,T> get(int l, int r) {\n        int bl = l / B + !!(l%B), br =\
    \ r / B;\n        int ml = bl * B, mr = br * B;\n        ml = min(ml,r); mr =\
    \ max(l,mr);\n        size_t maxi_freq = sqrt_bucket_freq[bl][br];\n        size_t\
    \ maxi_mode = sqrt_bucket_mode[bl][br];\n        for(int i = l; i < ml; ++i) {\n\
    \            const size_t& key = compressed[i];\n            int freq = maxi_freq;\n\
    \            for(int j = pos[i] + freq; j < idx[key].size(); ++j) {\n        \
    \        if(idx[key][j] < r) {\n                    maxi_freq = j - pos[i] + 1;\n\
    \                    maxi_mode = key;\n                }\n                else\
    \ break;\n            }\n        }\n        for(int i = r-1; mr <= i; --i) {\n\
    \            const size_t& key = compressed[i];\n            int freq = maxi_freq;\n\
    \            for(int j = pos[i] - freq; 0 <= j; --j) {\n                if(l <=\
    \ idx[key][j]) {\n                    maxi_freq = pos[i] - j + 1;\n          \
    \          maxi_mode = key;\n                }\n                else break;\n\
    \            }\n        }\n        return {maxi_freq,origin[maxi_mode]};\n   \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/StaticRangeModeQuery.cpp
  requiredBy: []
  timestamp: '2023-07-12 04:26:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/13-static-range-query/StaticRangeModeQuery.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/StaticRangeModeQuery.cpp
- /library/lib/13-static-range-query/StaticRangeModeQuery.cpp.html
title: "StaticRangeModeQuery - \u9759\u7684\u533A\u9593\u6700\u983B\u5024\u30AF\u30A8\
  \u30EA"
---
### StaticRangeModeQuery
- 区間最瀕値
  - 半開区間[l,r)に対する最瀕値となる頻度(freq)とその値(mode)が求まる。
  - クエリはオンラインでも可能。
  - 列の更新は出来ない。

### コンストラクタ
- StaticRangeModeQuery(const vector<T>& ar, T pre=-1)
  - 列と、列に含まれない最小値preを渡す必要がある。
  - これは座圧を内部的に行うため、最小を定義する必要がある。
  - ソートできる列であれば何でも渡せる
  - $O(N\sqrt(N))$

### メソッド
- pair<size_t,T> get(int l, int r)
  - 半開区間[l,r)に対する最瀕値となる頻度(freq)とその値(mode)を返す
  - $O(\sqrt(N))$

### 参考資料
- [Range Mode Query](https://scrapbox.io/data-structures/Range_Mode_Query)
- [Range Mode Query 空間 Θ(n) 構築 Θ(n√n) クエリ Θ(√n)](https://noshi91.hatenablog.com/entry/2020/10/26/140105)
- [range_mode_query.cpp](https://github.com/noshi91/Library/blob/master/data_structure/range_mode_query.cpp)
- [D. Cut and Stick](https://codeforces.com/contest/1514/problem/D)