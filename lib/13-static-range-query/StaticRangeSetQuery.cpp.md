---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/static-range-query/StaticRangeSetQuery.md
    document_title: "StaticRangeSetQuery - \u9759\u7684\u533A\u9593set\u30AF\u30A8\
      \u30EA"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/StaticRangeSetQuery.cpp\"\n/*\n\
    \ * @title StaticRangeSetQuery - \u9759\u7684\u533A\u9593set\u30AF\u30A8\u30EA\
    \n * @docs md/static-range-query/StaticRangeSetQuery.md\n */\ntemplate<class T>\
    \ class StaticRangeSetQuery {\n    using size_t = unsigned int;\n    WaveletMatrix<size_t>\
    \ wm;\n    size_t length;\n    size_t range_set_size_impl(const int l, const int\
    \ r) const {\n        if (l < 0 || length <= l || r < 0 || length < r) return\
    \ 0;\n        return (r-l) - wm.range_freq_upper(l,r,r);\n    }\n    inline static\
    \ vector<size_t> init(const vector<T> & vec) {\n        size_t n = vec.size();\n\
    \        unordered_map<T,set<size_t>> mp;\n        for(size_t i = 0; i<n; ++i)\
    \ mp[vec[i]].insert(i);\n        vector<size_t> ar(n);\n        for(auto& [_,st]:\
    \ mp) {\n            st.insert(n);\n            int cnt=0;\n            size_t\
    \ l=n,r=n; //\u3053\u306El,r\u306F\u9589\u533A\u9593 [l,r]\n            for(size_t\
    \ idx: st) {\n                r=idx;\n                if(cnt) ar[l]=r;\n     \
    \           l=r; cnt++;\n            }\n        }\n        return ar;\n    }\n\
    public:\n    StaticRangeSetQuery(const vector<T> & vec): wm(init(vec)), length(vec.size())\
    \ {}\n    //[l,r) range set size \n    size_t range_set_size(const int l, const\
    \ int r) const {return range_set_size_impl(l,r);}\n};\n\n"
  code: "/*\n * @title StaticRangeSetQuery - \u9759\u7684\u533A\u9593set\u30AF\u30A8\
    \u30EA\n * @docs md/static-range-query/StaticRangeSetQuery.md\n */\ntemplate<class\
    \ T> class StaticRangeSetQuery {\n    using size_t = unsigned int;\n    WaveletMatrix<size_t>\
    \ wm;\n    size_t length;\n    size_t range_set_size_impl(const int l, const int\
    \ r) const {\n        if (l < 0 || length <= l || r < 0 || length < r) return\
    \ 0;\n        return (r-l) - wm.range_freq_upper(l,r,r);\n    }\n    inline static\
    \ vector<size_t> init(const vector<T> & vec) {\n        size_t n = vec.size();\n\
    \        unordered_map<T,set<size_t>> mp;\n        for(size_t i = 0; i<n; ++i)\
    \ mp[vec[i]].insert(i);\n        vector<size_t> ar(n);\n        for(auto& [_,st]:\
    \ mp) {\n            st.insert(n);\n            int cnt=0;\n            size_t\
    \ l=n,r=n; //\u3053\u306El,r\u306F\u9589\u533A\u9593 [l,r]\n            for(size_t\
    \ idx: st) {\n                r=idx;\n                if(cnt) ar[l]=r;\n     \
    \           l=r; cnt++;\n            }\n        }\n        return ar;\n    }\n\
    public:\n    StaticRangeSetQuery(const vector<T> & vec): wm(init(vec)), length(vec.size())\
    \ {}\n    //[l,r) range set size \n    size_t range_set_size(const int l, const\
    \ int r) const {return range_set_size_impl(l,r);}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/StaticRangeSetQuery.cpp
  requiredBy: []
  timestamp: '2023-06-13 08:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/13-static-range-query/StaticRangeSetQuery.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/StaticRangeSetQuery.cpp
- /library/lib/13-static-range-query/StaticRangeSetQuery.cpp.html
title: "StaticRangeSetQuery - \u9759\u7684\u533A\u9593set\u30AF\u30A8\u30EA"
---
### StaticRangeSetQuery
- 区間内のユニークのサイズを求めるクラス
- [提出](https://atcoder.jp/contests/abc210/submissions/42226500)
- [提出](https://atcoder.jp/contests/abc174/submissions/42226531)