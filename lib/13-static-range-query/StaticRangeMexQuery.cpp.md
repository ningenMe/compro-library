---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/static-range-query/StaticRangeMexQuery.md
    document_title: "StaticRangeMexQuery - \u9759\u7684\u533A\u9593mex\u30AF\u30A8\
      \u30EA"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/StaticRangeMexQuery.cpp\"\n\n\
    /*\n * @title StaticRangeMexQuery - \u9759\u7684\u533A\u9593mex\u30AF\u30A8\u30EA\
    \n * @docs md/static-range-query/StaticRangeMexQuery.md\n */\ntemplate<class T>\
    \ class StaticRangeMexQuery {\n    struct MonoidRangeMinPointUpdate {\n      \
    \  using TypeNode = T;\n        inline static constexpr TypeNode unit_node = (1LL<<31)-1;\n\
    \        inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return\
    \ min(l,r);}\n        inline static constexpr TypeNode func_operate(TypeNode l,TypeNode\
    \ r){return r;}\n        inline static constexpr bool func_check(TypeNode nodeVal,TypeNode\
    \ var){return var > nodeVal;}\n    };\n    unordered_map<long long, long long>\
    \ res;\n    long long length;\npublic:\n    StaticRangeMexQuery(const vector<T>&\
    \ A, const vector<pair<int,int>>& ranges, T offset = 0) {\n        length = A.size();\n\
    \        vector<vector<int>> r_to_l(length+1);\n        for(int i=0;i<ranges.size();++i)\
    \ {\n            const int& l=ranges[i].first;\n            const int& r=ranges[i].second;\n\
    \            r_to_l[r].push_back(l);\n        }\n        SegmentTree<MonoidRangeMinPointUpdate>\
    \ seg(offset+length+1,-1);\n        for(int i=0;i<offset;++i) seg.operate(i,offset+length+1);\n\
    \        for(int r=0;r<length;++r) {\n            if(A[r]<=offset+length) seg.operate(A[r],r);\n\
    \            for(int& l:r_to_l[r+1]) {\n                res[l*(length+1)+r+1]\
    \ = seg.prefix_binary_search(offset,offset+length+1,l);\n            }\n     \
    \   }\n    }\n    //[l,r) \u306E mex (\u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u3057\
    \u305F\u3082\u306E\u306E\u307F)\n    long long fold(int l, int r) {\n        assert(res.count((length+1)*l\
    \ + r)>0);\n        return res[(length+1)*l+r];\n    }\n};\n"
  code: "\n/*\n * @title StaticRangeMexQuery - \u9759\u7684\u533A\u9593mex\u30AF\u30A8\
    \u30EA\n * @docs md/static-range-query/StaticRangeMexQuery.md\n */\ntemplate<class\
    \ T> class StaticRangeMexQuery {\n    struct MonoidRangeMinPointUpdate {\n   \
    \     using TypeNode = T;\n        inline static constexpr TypeNode unit_node\
    \ = (1LL<<31)-1;\n        inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return min(l,r);}\n        inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return r;}\n        inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n    };\n    unordered_map<long\
    \ long, long long> res;\n    long long length;\npublic:\n    StaticRangeMexQuery(const\
    \ vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0) {\n       \
    \ length = A.size();\n        vector<vector<int>> r_to_l(length+1);\n        for(int\
    \ i=0;i<ranges.size();++i) {\n            const int& l=ranges[i].first;\n    \
    \        const int& r=ranges[i].second;\n            r_to_l[r].push_back(l);\n\
    \        }\n        SegmentTree<MonoidRangeMinPointUpdate> seg(offset+length+1,-1);\n\
    \        for(int i=0;i<offset;++i) seg.operate(i,offset+length+1);\n        for(int\
    \ r=0;r<length;++r) {\n            if(A[r]<=offset+length) seg.operate(A[r],r);\n\
    \            for(int& l:r_to_l[r+1]) {\n                res[l*(length+1)+r+1]\
    \ = seg.prefix_binary_search(offset,offset+length+1,l);\n            }\n     \
    \   }\n    }\n    //[l,r) \u306E mex (\u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u3057\
    \u305F\u3082\u306E\u306E\u307F)\n    long long fold(int l, int r) {\n        assert(res.count((length+1)*l\
    \ + r)>0);\n        return res[(length+1)*l+r];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/StaticRangeMexQuery.cpp
  requiredBy: []
  timestamp: '2023-07-17 17:01:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/13-static-range-query/StaticRangeMexQuery.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/StaticRangeMexQuery.cpp
- /library/lib/13-static-range-query/StaticRangeMexQuery.cpp.html
title: "StaticRangeMexQuery - \u9759\u7684\u533A\u9593mex\u30AF\u30A8\u30EA"
---
### StaticRangeMexQuery
- 区間Mex
  - 半開区間[l,r)に対するmexを求める。
  - クエリはオフライン。オンラインでは出来ない。(TODO できるはず)
  - 列の更新は出来ない。

### コンストラクタ
- なし

### メソッド
- StaticRangeMexQuery(const vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0)
  - A: 列
  - ranges: クエリの半区間。[l,r)を渡す必要がある
  - offset: mexの最小値。デフォルトは0

### 参考資料
- [E. Complicated Computations](https://codeforces.com/contest/1436/problem/E)
- [のしさんのツイート](https://twitter.com/noshi91/status/1279594849826533377?s=20) 
- [提出](https://atcoder.jp/contests/abc245/submissions/43691044)
- [提出](https://codeforces.com/contest/1436/submission/214169617)
```
  セグ木を持って a を左から舐めます
管理するのは「seg[i] = 数字 i が最後に現れた index」です
[l, r] の答えは r まで読んだ時に計算します
「seg[i] > l となる最小の i」が mex なので、max のセグ木をセグ木内二分探索すると O(log(N)) です
```
