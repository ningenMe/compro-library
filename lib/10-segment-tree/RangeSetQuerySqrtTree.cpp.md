---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/RangeSetQuerySqrtTree.cpp\"\ntemplate<class\
    \ T, unsigned int bit_length=20> class RangeSetQuerySqrtTree {\n    using size_t\
    \ = unsigned int;\n    RangeIntegerFrequencyQuerySqrtTree<bit_length> tree;\n\
    \    unordered_map<T,set<size_t>> mp;\n    vector<T> ar;\n    size_t length;\n\
    \    size_t range_set_size_impl(const int l, const int r) const {\n        if\
    \ (l < 0 || length <= l || r < 0 || length < r) return 0;\n        return (r-l)\
    \ - tree.range_freq_upper(l,r,r);\n    }\n    void update_impl(const size_t idx,\
    \ const T next) {\n        T prev = ar[idx];\n        //\u66F4\u65B0\u524D\u306E\
    1\u3064\u5DE6\u306B\u5F71\u97FF\u304C\u3042\u308B\u304B\u78BA\u8A8D\n        {\n\
    \            auto itr_r = mp[prev].lower_bound(idx);\n            //\u5DE6\u304C\
    \u5B58\u5728\u3059\u308B\u306A\u3089\u5F71\u97FF\u3042\u308A\n            if(itr_r\
    \ != mp[prev].begin()) {\n                auto itr_l=itr_r;\n                itr_l--;\n\
    \                itr_r++;\n                if(itr_r==mp[prev].end()) tree.erase((*itr_l));\n\
    \                else tree.update((*itr_l),(*itr_r));\n            }\n       \
    \     mp[prev].erase(idx);\n        }\n        //\u66F4\u65B0\u5F8C\u306E1\u3064\
    \u5DE6\u306B\u5F71\u97FF\u304C\u3042\u308B\u304B\u78BA\u8A8D\n        {\n    \
    \        mp[next].insert(idx);\n            auto itr_r = mp[next].upper_bound(idx);\n\
    \            if(itr_r==mp[next].end()) tree.erase(idx);\n            else tree.update(idx,(*itr_r));\n\
    \n            //\u5DE6\u304C\u5B58\u5728\u3059\u308B\u306A\u3089\u5F71\u97FF\u3042\
    \u308A\n            auto itr_l = mp[next].lower_bound(idx);\n            if(itr_l\
    \ != mp[next].begin()) {\n                itr_l--;\n                tree.update((*itr_l),idx);\n\
    \            }\n        }\n        ar[idx] = next;\n    }\npublic:\n    RangeSetQuerySqrtTree(const\
    \ vector<T> & vec):ar(vec),tree(vec.size()) {\n        length = vec.size();\n\
    \        for(size_t i = 0; i<length; ++i) mp[ar[i]].insert(i);\n        for(auto&\
    \ [_,st]: mp) {\n            size_t l=length,r=length; //\u3053\u306El,r\u306F\
    \u9589\u533A\u9593 [l,r]\n            for(size_t idx: st) {\n                r=idx;\n\
    \                if(l<length && r<length) tree.update(l,r);\n                l=r;\
    \ \n            }\n        }\n    }\n    //idx\u756A\u76EE\u306E\u8981\u7D20\u3092\
    update\n    void update(const size_t idx, const T val) { update_impl(idx,val);\
    \ }\n    //[l,r) range set size \n    size_t range_set_size(const int l, const\
    \ int r) const {return range_set_size_impl(l,r);}\n};\n"
  code: "template<class T, unsigned int bit_length=20> class RangeSetQuerySqrtTree\
    \ {\n    using size_t = unsigned int;\n    RangeIntegerFrequencyQuerySqrtTree<bit_length>\
    \ tree;\n    unordered_map<T,set<size_t>> mp;\n    vector<T> ar;\n    size_t length;\n\
    \    size_t range_set_size_impl(const int l, const int r) const {\n        if\
    \ (l < 0 || length <= l || r < 0 || length < r) return 0;\n        return (r-l)\
    \ - tree.range_freq_upper(l,r,r);\n    }\n    void update_impl(const size_t idx,\
    \ const T next) {\n        T prev = ar[idx];\n        //\u66F4\u65B0\u524D\u306E\
    1\u3064\u5DE6\u306B\u5F71\u97FF\u304C\u3042\u308B\u304B\u78BA\u8A8D\n        {\n\
    \            auto itr_r = mp[prev].lower_bound(idx);\n            //\u5DE6\u304C\
    \u5B58\u5728\u3059\u308B\u306A\u3089\u5F71\u97FF\u3042\u308A\n            if(itr_r\
    \ != mp[prev].begin()) {\n                auto itr_l=itr_r;\n                itr_l--;\n\
    \                itr_r++;\n                if(itr_r==mp[prev].end()) tree.erase((*itr_l));\n\
    \                else tree.update((*itr_l),(*itr_r));\n            }\n       \
    \     mp[prev].erase(idx);\n        }\n        //\u66F4\u65B0\u5F8C\u306E1\u3064\
    \u5DE6\u306B\u5F71\u97FF\u304C\u3042\u308B\u304B\u78BA\u8A8D\n        {\n    \
    \        mp[next].insert(idx);\n            auto itr_r = mp[next].upper_bound(idx);\n\
    \            if(itr_r==mp[next].end()) tree.erase(idx);\n            else tree.update(idx,(*itr_r));\n\
    \n            //\u5DE6\u304C\u5B58\u5728\u3059\u308B\u306A\u3089\u5F71\u97FF\u3042\
    \u308A\n            auto itr_l = mp[next].lower_bound(idx);\n            if(itr_l\
    \ != mp[next].begin()) {\n                itr_l--;\n                tree.update((*itr_l),idx);\n\
    \            }\n        }\n        ar[idx] = next;\n    }\npublic:\n    RangeSetQuerySqrtTree(const\
    \ vector<T> & vec):ar(vec),tree(vec.size()) {\n        length = vec.size();\n\
    \        for(size_t i = 0; i<length; ++i) mp[ar[i]].insert(i);\n        for(auto&\
    \ [_,st]: mp) {\n            size_t l=length,r=length; //\u3053\u306El,r\u306F\
    \u9589\u533A\u9593 [l,r]\n            for(size_t idx: st) {\n                r=idx;\n\
    \                if(l<length && r<length) tree.update(l,r);\n                l=r;\
    \ \n            }\n        }\n    }\n    //idx\u756A\u76EE\u306E\u8981\u7D20\u3092\
    update\n    void update(const size_t idx, const T val) { update_impl(idx,val);\
    \ }\n    //[l,r) range set size \n    size_t range_set_size(const int l, const\
    \ int r) const {return range_set_size_impl(l,r);}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/RangeSetQuerySqrtTree.cpp
  requiredBy: []
  timestamp: '2023-06-15 04:19:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/10-segment-tree/RangeSetQuerySqrtTree.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/RangeSetQuerySqrtTree.cpp
- /library/lib/10-segment-tree/RangeSetQuerySqrtTree.cpp.html
title: lib/10-segment-tree/RangeSetQuerySqrtTree.cpp
---
