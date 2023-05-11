---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment/RangeMexQuery.md
    document_title: "RangeMexQuery - \u533A\u9593mex"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/range-query/RangeMexQuery.cpp\"\n/*\n\
    \ * @title RangeMexQuery - \u533A\u9593mex\n * @docs md/segment/RangeMexQuery.md\n\
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
  code: "/*\n * @title RangeMexQuery - \u533A\u9593mex\n * @docs md/segment/RangeMexQuery.md\n\
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
  path: lib/data-structure/range-query/RangeMexQuery.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/range-query/RangeMexQuery.cpp
layout: document
redirect_from:
- /library/lib/data-structure/range-query/RangeMexQuery.cpp
- /library/lib/data-structure/range-query/RangeMexQuery.cpp.html
title: "RangeMexQuery - \u533A\u9593mex"
---
