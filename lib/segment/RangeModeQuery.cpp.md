---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment/RangeModeQuery.md
    document_title: "RangeModeQuery - \u533A\u9593\u6700\u983B\u5024"
    links: []
  bundledCode: "#line 1 \"lib/segment/RangeModeQuery.cpp\"\n/*\n * @title RangeModeQuery\
    \ - \u533A\u9593\u6700\u983B\u5024\n * @docs md/segment/RangeModeQuery.md\n */\n\
    template<class T> class RangeModeQuery {\n    vector<size_t> compressed;\n\tvector<T>\
    \ origin;\n\tvector<size_t> sqrt_bucket_freq;\n\tvector<size_t> sqrt_bucket_mode;\n\
    \tvector<vector<size_t>> idx;\n\tvector<int> pos;\n\tsize_t N,B;\npublic:\n\t\
    RangeModeQuery(const vector<T>& ar, T pre=-1)\n\t: compressed(ar.size()), origin(ar.size()),\
    \ idx(ar.size()), pos(ar.size()) {\n\t\tN = ar.size();\n\t\tB = sqrt(N) + 1;\n\
    \t\t//zarts\n\t\t{\n\t\t\tvector<pair<T,size_t>> ord(N);\n\t\t\tfor(size_t i=0;i<N;++i)\
    \ ord[i]={ar[i],i};\n\t\t\tsort(ord.begin(),ord.end());\n\t\t\tint inc=-1;\n\t\
    \t\tfor(size_t i=0;i<N;++i) {\n\t\t\t\tif(pre < ord[i].first) inc++;\n\t\t\t\t\
    compressed[ord[i].second] = inc;\n\t\t\t\tpre = ord[i].first;\n\t\t\t}\n\t\t\t\
    for(size_t i=0;i<N;++i) origin[compressed[i]] = ar[i];\n\t\t}\n\t\t//sqrt bucket\n\
    \t\t{\n\t\t\tsqrt_bucket_freq.resize(B+1,vector<size_t>(B+1));\n\t\t\tsqrt_bucket_mode.resize(B+1,vector<size_t>(B+1));\n\
    \t\t\tfor(size_t bl=0;bl*B<=N;++bl) {\n\t\t\t\tvector<size_t> tmp(N,0);\n\t\t\t\
    \tsize_t maxi_freq = 0;\n\t\t\t\tsize_t maxi_mode = 0;\n\t\t\t\tfor(size_t br\
    \ = bl+1; br*B<=N;++br) {\n\t\t\t\t\tsize_t l = (br-1)*B, r = br*B;\n\t\t\t\t\t\
    for(size_t i=l;i<r;++i) {\n\t\t\t\t\t\tsize_t a = compressed[i];\n\t\t\t\t\t\t\
    ++tmp[a];\n\t\t\t\t\t\tif(maxi_freq < tmp[a]) {\n\t\t\t\t\t\t\tmaxi_freq = tmp[a];\n\
    \t\t\t\t\t\t\tmaxi_mode = a;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tsqrt_bucket_freq[bl][br]\
    \ = maxi_freq;\n\t\t\t\t\tsqrt_bucket_mode[bl][br] = maxi_mode;\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\t//idx,pos\n\t\t{\n\t\t\tfor(size_t i=0;i<N;++i) {\n\t\t\t\t\
    const size_t& key = compressed[i];\n\t\t\t\tpos[i] = idx[key].size();\n\t\t\t\t\
    idx[key].push_back(i);\n\t\t\t}\n\t\t}\n\t}\n\t//query [l,r)\n\t//return {freq,mode}\
    \ ({\u983B\u5EA6,\u5143\u306E\u914D\u5217\u306B\u304A\u3051\u308B\u5024}) \n\t\
    pair<size_t,T> get(int l, int r) {\n\t\tint bl = l / B + !!(l%B), br = r / B;\n\
    \t\tint ml = bl * B, mr = br * B;\n\t\tml = min(ml,r); mr = max(l,mr);\n\t\tsize_t\
    \ maxi_freq = sqrt_bucket_freq[bl][br];\n\t\tsize_t maxi_mode = sqrt_bucket_mode[bl][br];\n\
    \t\tfor(int i = l; i < ml; ++i) {\n\t\t\tconst size_t& key = compressed[i];\n\t\
    \t\tint freq = maxi_freq;\n\t\t\tfor(int j = pos[i] + freq; j < idx[key].size();\
    \ ++j) {\n\t\t\t\tif(idx[key][j] < r) {\n\t\t\t\t\tmaxi_freq = j - pos[i] + 1;\n\
    \t\t\t\t\tmaxi_mode = key;\n\t\t\t\t}\n\t\t\t\telse break;\n\t\t\t}\n\t\t}\n\t\
    \tfor(int i = r-1; mr <= i; --i) {\n\t\t\tconst size_t& key = compressed[i];\n\
    \t\t\tint freq = maxi_freq;\n\t\t\tfor(int j = pos[i] - freq; 0 <= j; --j) {\n\
    \t\t\t\tif(l <= idx[key][j]) {\n\t\t\t\t\tmaxi_freq = pos[i] - j + 1;\n\t\t\t\t\
    \tmaxi_mode = key;\n\t\t\t\t}\n\t\t\t\telse break;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ {maxi_freq,origin[maxi_mode]};\n\t}\n}; \n"
  code: "/*\n * @title RangeModeQuery - \u533A\u9593\u6700\u983B\u5024\n * @docs md/segment/RangeModeQuery.md\n\
    \ */\ntemplate<class T> class RangeModeQuery {\n    vector<size_t> compressed;\n\
    \tvector<T> origin;\n\tvector<size_t> sqrt_bucket_freq;\n\tvector<size_t> sqrt_bucket_mode;\n\
    \tvector<vector<size_t>> idx;\n\tvector<int> pos;\n\tsize_t N,B;\npublic:\n\t\
    RangeModeQuery(const vector<T>& ar, T pre=-1)\n\t: compressed(ar.size()), origin(ar.size()),\
    \ idx(ar.size()), pos(ar.size()) {\n\t\tN = ar.size();\n\t\tB = sqrt(N) + 1;\n\
    \t\t//zarts\n\t\t{\n\t\t\tvector<pair<T,size_t>> ord(N);\n\t\t\tfor(size_t i=0;i<N;++i)\
    \ ord[i]={ar[i],i};\n\t\t\tsort(ord.begin(),ord.end());\n\t\t\tint inc=-1;\n\t\
    \t\tfor(size_t i=0;i<N;++i) {\n\t\t\t\tif(pre < ord[i].first) inc++;\n\t\t\t\t\
    compressed[ord[i].second] = inc;\n\t\t\t\tpre = ord[i].first;\n\t\t\t}\n\t\t\t\
    for(size_t i=0;i<N;++i) origin[compressed[i]] = ar[i];\n\t\t}\n\t\t//sqrt bucket\n\
    \t\t{\n\t\t\tsqrt_bucket_freq.resize(B+1,vector<size_t>(B+1));\n\t\t\tsqrt_bucket_mode.resize(B+1,vector<size_t>(B+1));\n\
    \t\t\tfor(size_t bl=0;bl*B<=N;++bl) {\n\t\t\t\tvector<size_t> tmp(N,0);\n\t\t\t\
    \tsize_t maxi_freq = 0;\n\t\t\t\tsize_t maxi_mode = 0;\n\t\t\t\tfor(size_t br\
    \ = bl+1; br*B<=N;++br) {\n\t\t\t\t\tsize_t l = (br-1)*B, r = br*B;\n\t\t\t\t\t\
    for(size_t i=l;i<r;++i) {\n\t\t\t\t\t\tsize_t a = compressed[i];\n\t\t\t\t\t\t\
    ++tmp[a];\n\t\t\t\t\t\tif(maxi_freq < tmp[a]) {\n\t\t\t\t\t\t\tmaxi_freq = tmp[a];\n\
    \t\t\t\t\t\t\tmaxi_mode = a;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tsqrt_bucket_freq[bl][br]\
    \ = maxi_freq;\n\t\t\t\t\tsqrt_bucket_mode[bl][br] = maxi_mode;\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\t//idx,pos\n\t\t{\n\t\t\tfor(size_t i=0;i<N;++i) {\n\t\t\t\t\
    const size_t& key = compressed[i];\n\t\t\t\tpos[i] = idx[key].size();\n\t\t\t\t\
    idx[key].push_back(i);\n\t\t\t}\n\t\t}\n\t}\n\t//query [l,r)\n\t//return {freq,mode}\
    \ ({\u983B\u5EA6,\u5143\u306E\u914D\u5217\u306B\u304A\u3051\u308B\u5024}) \n\t\
    pair<size_t,T> get(int l, int r) {\n\t\tint bl = l / B + !!(l%B), br = r / B;\n\
    \t\tint ml = bl * B, mr = br * B;\n\t\tml = min(ml,r); mr = max(l,mr);\n\t\tsize_t\
    \ maxi_freq = sqrt_bucket_freq[bl][br];\n\t\tsize_t maxi_mode = sqrt_bucket_mode[bl][br];\n\
    \t\tfor(int i = l; i < ml; ++i) {\n\t\t\tconst size_t& key = compressed[i];\n\t\
    \t\tint freq = maxi_freq;\n\t\t\tfor(int j = pos[i] + freq; j < idx[key].size();\
    \ ++j) {\n\t\t\t\tif(idx[key][j] < r) {\n\t\t\t\t\tmaxi_freq = j - pos[i] + 1;\n\
    \t\t\t\t\tmaxi_mode = key;\n\t\t\t\t}\n\t\t\t\telse break;\n\t\t\t}\n\t\t}\n\t\
    \tfor(int i = r-1; mr <= i; --i) {\n\t\t\tconst size_t& key = compressed[i];\n\
    \t\t\tint freq = maxi_freq;\n\t\t\tfor(int j = pos[i] - freq; 0 <= j; --j) {\n\
    \t\t\t\tif(l <= idx[key][j]) {\n\t\t\t\t\tmaxi_freq = pos[i] - j + 1;\n\t\t\t\t\
    \tmaxi_mode = key;\n\t\t\t\t}\n\t\t\t\telse break;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ {maxi_freq,origin[maxi_mode]};\n\t}\n}; "
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/RangeModeQuery.cpp
  requiredBy: []
  timestamp: '2021-04-20 21:10:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/segment/RangeModeQuery.cpp
layout: document
redirect_from:
- /library/lib/segment/RangeModeQuery.cpp
- /library/lib/segment/RangeModeQuery.cpp.html
title: "RangeModeQuery - \u533A\u9593\u6700\u983B\u5024"
---
### Polynomial
- 区間最瀕値
  - 半開区間[l,r)に対する最瀕値となる頻度(freq)とその値(mode)が求まる。
  - クエリはオンラインでも可能。
  - 列の更新は出来ない。

### コンストラクタ
- RangeModeQuery(const vector<T>& ar, T pre=-1)
  - 列と、列に含まれない最小値preを渡す必要がある。
  - これは座圧を内部的に行うため、最小を定義する必要がある。
  - ソートできる列であれば何でも渡せる
  - $O(N\sqrt(N))$

### メソッド
- pair<size_t,T> get(int l, int r)
  - 半開区間[l,r)に対する最瀕値となる頻度(freq)とその値(mode)を返す

### 参考資料
- [Range Mode Query](https://scrapbox.io/data-structures/Range_Mode_Query)
- [Range Mode Query 空間 Θ(n) 構築 Θ(n√n) クエリ Θ(√n)](https://noshi91.hatenablog.com/entry/2020/10/26/140105)
- [range_mode_query.cpp](https://github.com/noshi91/Library/blob/master/data_structure/range_mode_query.cpp)
- [D. Cut and Stick](https://codeforces.com/contest/1514/problem/D)