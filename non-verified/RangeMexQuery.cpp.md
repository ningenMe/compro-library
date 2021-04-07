---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1436/problem/E
    - https://twitter.com/noshi91/status/1279594849826533377?s=20
  bundledCode: "#line 1 \"non-verified/RangeMexQuery.cpp\"\n/*\n * \u533A\u9593mex\n\
    \ * @params A vector\n * @params ranges \u534A\u958B\u533A\u9593[l,r)\u306Evector\
    \ 0-indexed\n * @params offset mex\u306E\u6700\u5C0F\u5024\n * @params ret range\u306B\
    \u5BFE\u3059\u308Bmex\u306E\u5024\n * @see https://codeforces.com/contest/1436/problem/E\n\
    \ * @see https://twitter.com/noshi91/status/1279594849826533377?s=20\n */\ntemplate<class\
    \ T> map<pair<int,int>,int> static_range_mex_query(const vector<T>& A, const vector<pair<int,int>>&\
    \ ranges, T offset = 0) {\n    int N = A.size();\n    vector<vector<int>> r_to_l(N+1);\n\
    \    for(int i=0;i<ranges.size();++i) {\n        const int& l=ranges[i].first;\n\
    \        const int& r=ranges[i].second;\n        r_to_l[r].push_back(l);\n   \
    \ }\n    SegmentTree<NodeMinPointUpdate<int>> seg(offset+N+1,-1);\n    for(int\
    \ i=0;i<offset;++i) seg.update(i,offset+N+1);\n    map<pair<int,int>,int> ret;\n\
    \    for(int r=0;r<N;++r) {\n        if(A[r]<=offset+N) seg.update(A[r],r);\n\
    \        for(int& l:r_to_l[r+1]) {\n            ret[{l,r+1}] = seg.prefix_binary_search(offset,offset+N+1,l);\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "/*\n * \u533A\u9593mex\n * @params A vector\n * @params ranges \u534A\u958B\
    \u533A\u9593[l,r)\u306Evector 0-indexed\n * @params offset mex\u306E\u6700\u5C0F\
    \u5024\n * @params ret range\u306B\u5BFE\u3059\u308Bmex\u306E\u5024\n * @see https://codeforces.com/contest/1436/problem/E\n\
    \ * @see https://twitter.com/noshi91/status/1279594849826533377?s=20\n */\ntemplate<class\
    \ T> map<pair<int,int>,int> static_range_mex_query(const vector<T>& A, const vector<pair<int,int>>&\
    \ ranges, T offset = 0) {\n    int N = A.size();\n    vector<vector<int>> r_to_l(N+1);\n\
    \    for(int i=0;i<ranges.size();++i) {\n        const int& l=ranges[i].first;\n\
    \        const int& r=ranges[i].second;\n        r_to_l[r].push_back(l);\n   \
    \ }\n    SegmentTree<NodeMinPointUpdate<int>> seg(offset+N+1,-1);\n    for(int\
    \ i=0;i<offset;++i) seg.update(i,offset+N+1);\n    map<pair<int,int>,int> ret;\n\
    \    for(int r=0;r<N;++r) {\n        if(A[r]<=offset+N) seg.update(A[r],r);\n\
    \        for(int& l:r_to_l[r+1]) {\n            ret[{l,r+1}] = seg.prefix_binary_search(offset,offset+N+1,l);\n\
    \        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/RangeMexQuery.cpp
  requiredBy: []
  timestamp: '2020-10-25 02:58:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/RangeMexQuery.cpp
layout: document
redirect_from:
- /library/non-verified/RangeMexQuery.cpp
- /library/non-verified/RangeMexQuery.cpp.html
title: non-verified/RangeMexQuery.cpp
---
