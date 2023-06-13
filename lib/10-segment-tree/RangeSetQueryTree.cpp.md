---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment-tree/RangeSetQueryTree.md
    document_title: "RangeSetQueryTree - \u533A\u9593set\u30AF\u30A8\u30EA\u7528Tree"
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/RangeSetQueryTree.cpp\"\n/*\n * @title\
    \ RangeSetQueryTree - \u533A\u9593set\u30AF\u30A8\u30EA\u7528Tree\n * @docs md/segment-tree/RangeSetQueryTree.md\n\
    \ */\ntemplate<class T> class RangeSetQueryTree {\n    using size_t = unsigned\
    \ int;\n    RangeFrequencyQueryTree<size_t> tree;\n    unordered_map<T,set<size_t>>\
    \ mp;\n    vector<T> ar;\n    size_t length;\n    size_t range_set_size_impl(const\
    \ int l, const int r) const {\n        if (l < 0 || length <= l || r < 0 || length\
    \ < r) return 0;\n        return (r-l) - tree.range_freq_upper(l,r,r);\n    }\n\
    \    void update_impl(const size_t idx, const T next) {\n        T prev = ar[idx];\n\
    \        queue<pair<size_t,size_t>> q;\n        //\u66F4\u65B0\u524D\u306E1\u3064\
    \u5DE6\u306B\u5F71\u97FF\u304C\u3042\u308B\u304B\u78BA\u8A8D\n        {\n    \
    \        auto itr_l = mp[prev].find(idx);\n            auto itr_r = mp[prev].upper_bound(idx);\n\
    \            if(itr_l != mp[prev].begin()) {\n                --itr_l;\n     \
    \           q.emplace((*itr_l),(*itr_r));\n            }\n            mp[prev].erase(idx);\n\
    \        }\n        {\n            if(mp[next].size()==0) mp[next].insert(length);\n\
    \            auto itr_r = mp[next].upper_bound(idx);\n            q.emplace(idx,(*itr_r));\n\
    \            //\u66F4\u65B0\u5F8C\u306E1\u3064\u5DE6\u306B\u5F71\u97FF\u304C\u3042\
    \u308B\u304B\u78BA\u8A8D\n            if(itr_r != mp[next].begin()) {\n      \
    \          --itr_r;\n                q.emplace((*itr_r),idx);\n            }\n\
    \            mp[next].insert(idx);\n        }\n        ar[idx] = next;\n     \
    \   while(q.size()) {\n            auto [l,r]=q.front(); q.pop();\n          \
    \  tree.update(l,r);\n        }\n    }\npublic:\n    RangeSetQueryTree(const vector<T>\
    \ & vec):ar(vec),tree(vec.size()) {\n        length = vec.size();\n        for(size_t\
    \ i = 0; i<length; ++i) mp[ar[i]].insert(i);\n        for(auto& [_,st]: mp) {\n\
    \            st.insert(length);\n            int cnt=0;\n            size_t l=length,r=length;\
    \ //\u3053\u306El,r\u306F\u9589\u533A\u9593 [l,r]\n            for(size_t idx:\
    \ st) {\n                r=idx;\n                if(cnt) {\n                 \
    \   tree.update(l,r);\n                }\n                l=r;\n             \
    \   cnt++;\n            }\n        }\n    }\n    //idx\u756A\u76EE\u306E\u8981\
    \u7D20\u3092update\n    void update(const size_t idx, const T val) { update_impl(idx,val);\
    \ }\n    //[l,r) range set size \n    size_t range_set_size(const int l, const\
    \ int r) const {return range_set_size_impl(l,r);}\n};\n"
  code: "/*\n * @title RangeSetQueryTree - \u533A\u9593set\u30AF\u30A8\u30EA\u7528\
    Tree\n * @docs md/segment-tree/RangeSetQueryTree.md\n */\ntemplate<class T> class\
    \ RangeSetQueryTree {\n    using size_t = unsigned int;\n    RangeFrequencyQueryTree<size_t>\
    \ tree;\n    unordered_map<T,set<size_t>> mp;\n    vector<T> ar;\n    size_t length;\n\
    \    size_t range_set_size_impl(const int l, const int r) const {\n        if\
    \ (l < 0 || length <= l || r < 0 || length < r) return 0;\n        return (r-l)\
    \ - tree.range_freq_upper(l,r,r);\n    }\n    void update_impl(const size_t idx,\
    \ const T next) {\n        T prev = ar[idx];\n        queue<pair<size_t,size_t>>\
    \ q;\n        //\u66F4\u65B0\u524D\u306E1\u3064\u5DE6\u306B\u5F71\u97FF\u304C\u3042\
    \u308B\u304B\u78BA\u8A8D\n        {\n            auto itr_l = mp[prev].find(idx);\n\
    \            auto itr_r = mp[prev].upper_bound(idx);\n            if(itr_l !=\
    \ mp[prev].begin()) {\n                --itr_l;\n                q.emplace((*itr_l),(*itr_r));\n\
    \            }\n            mp[prev].erase(idx);\n        }\n        {\n     \
    \       if(mp[next].size()==0) mp[next].insert(length);\n            auto itr_r\
    \ = mp[next].upper_bound(idx);\n            q.emplace(idx,(*itr_r));\n       \
    \     //\u66F4\u65B0\u5F8C\u306E1\u3064\u5DE6\u306B\u5F71\u97FF\u304C\u3042\u308B\
    \u304B\u78BA\u8A8D\n            if(itr_r != mp[next].begin()) {\n            \
    \    --itr_r;\n                q.emplace((*itr_r),idx);\n            }\n     \
    \       mp[next].insert(idx);\n        }\n        ar[idx] = next;\n        while(q.size())\
    \ {\n            auto [l,r]=q.front(); q.pop();\n            tree.update(l,r);\n\
    \        }\n    }\npublic:\n    RangeSetQueryTree(const vector<T> & vec):ar(vec),tree(vec.size())\
    \ {\n        length = vec.size();\n        for(size_t i = 0; i<length; ++i) mp[ar[i]].insert(i);\n\
    \        for(auto& [_,st]: mp) {\n            st.insert(length);\n           \
    \ int cnt=0;\n            size_t l=length,r=length; //\u3053\u306El,r\u306F\u9589\
    \u533A\u9593 [l,r]\n            for(size_t idx: st) {\n                r=idx;\n\
    \                if(cnt) {\n                    tree.update(l,r);\n          \
    \      }\n                l=r;\n                cnt++;\n            }\n      \
    \  }\n    }\n    //idx\u756A\u76EE\u306E\u8981\u7D20\u3092update\n    void update(const\
    \ size_t idx, const T val) { update_impl(idx,val); }\n    //[l,r) range set size\
    \ \n    size_t range_set_size(const int l, const int r) const {return range_set_size_impl(l,r);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/RangeSetQueryTree.cpp
  requiredBy: []
  timestamp: '2023-06-13 08:51:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/10-segment-tree/RangeSetQueryTree.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/RangeSetQueryTree.cpp
- /library/lib/10-segment-tree/RangeSetQueryTree.cpp.html
title: "RangeSetQueryTree - \u533A\u9593set\u30AF\u30A8\u30EA\u7528Tree"
---
### RangeSetQueryTree
- 区間内のユニークのサイズを求めるクラス
- 更新もできるはずだがかなり遅い
- [提出](https://atcoder.jp/contests/abc157/submissions/42226836)
