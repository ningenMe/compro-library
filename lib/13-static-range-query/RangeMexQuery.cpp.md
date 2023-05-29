---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/static-range-query/RangeMexQuery.md
    document_title: "RangeMexQuery - \u533A\u9593mex"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/RangeMexQuery.cpp\"\n/*\n * @title\
    \ RangeMexQuery - \u533A\u9593mex\n * @docs md/static-range-query/RangeMexQuery.md\n\
    \ */\ntemplate<class T> map<pair<int,int>,int> RangeMexQuery(const vector<T>&\
    \ A, const vector<pair<int,int>>& ranges, T offset = 0) {\n    int N = A.size();\n\
    \    vector<vector<int>> r_to_l(N+1);\n    for(int i=0;i<ranges.size();++i) {\n\
    \        const int& l=ranges[i].first;\n        const int& r=ranges[i].second;\n\
    \        r_to_l[r].push_back(l);\n    }\n    SegmentTree<NodeMinPointUpdate<int>>\
    \ seg(offset+N+1,-1);\n    for(int i=0;i<offset;++i) seg.update(i,offset+N+1);\n\
    \    map<pair<int,int>,int> ret;\n    for(int r=0;r<N;++r) {\n        if(A[r]<=offset+N)\
    \ seg.update(A[r],r);\n        for(int& l:r_to_l[r+1]) {\n            ret[{l,r+1}]\
    \ = seg.prefix_binary_search(offset,offset+N+1,l);\n        }\n    }\n    return\
    \ ret;\n}\n"
  code: "/*\n * @title RangeMexQuery - \u533A\u9593mex\n * @docs md/static-range-query/RangeMexQuery.md\n\
    \ */\ntemplate<class T> map<pair<int,int>,int> RangeMexQuery(const vector<T>&\
    \ A, const vector<pair<int,int>>& ranges, T offset = 0) {\n    int N = A.size();\n\
    \    vector<vector<int>> r_to_l(N+1);\n    for(int i=0;i<ranges.size();++i) {\n\
    \        const int& l=ranges[i].first;\n        const int& r=ranges[i].second;\n\
    \        r_to_l[r].push_back(l);\n    }\n    SegmentTree<NodeMinPointUpdate<int>>\
    \ seg(offset+N+1,-1);\n    for(int i=0;i<offset;++i) seg.update(i,offset+N+1);\n\
    \    map<pair<int,int>,int> ret;\n    for(int r=0;r<N;++r) {\n        if(A[r]<=offset+N)\
    \ seg.update(A[r],r);\n        for(int& l:r_to_l[r+1]) {\n            ret[{l,r+1}]\
    \ = seg.prefix_binary_search(offset,offset+N+1,l);\n        }\n    }\n    return\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/RangeMexQuery.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/13-static-range-query/RangeMexQuery.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/RangeMexQuery.cpp
- /library/lib/13-static-range-query/RangeMexQuery.cpp.html
title: "RangeMexQuery - \u533A\u9593mex"
---
### RangeMexQuery
- 区間Mex
  - 半開区間[l,r)に対するmexを求める。
  - クエリはオフライン。オンラインでは出来ない。
  - 列の更新は出来ない。

### コンストラクタ
- なし

### メソッド
- map<pair<int,int>,int> static_range_mex_query(const vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0)
  - A: 列
  - ranges: クエリの半区間。[l,r)を渡す必要がある
  - offset: mexの最小値。デフォルトは0

### 参考資料
- [E. Complicated Computations](https://codeforces.com/contest/1436/problem/E)
- [のしさんのツイート](https://twitter.com/noshi91/status/1279594849826533377?s=20) 
```
  セグ木を持って a を左から舐めます
管理するのは「seg[i] = 数字 i が最後に現れた index」です
[l, r] の答えは r まで読んだ時に計算します
「seg[i] > l となる最小の i」が mex なので、max のセグ木をセグ木内二分探索すると O(log(N)) です
```
