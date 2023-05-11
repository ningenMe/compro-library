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
  bundledCode: "#line 1 \"non-verified/Mo.cpp\"\ntemplate<class T> class Mo{\n   \
    \ unordered_map<long long,int> mp;\n    long long N;\n    int bucket;\n    vector<pair<int,int>>\
    \ range;\n\tvector<int> idx;\npublic:\n\n    Mo(long long N, const vector<pair<int,int>>&\
    \ range) : N(N),range(range),idx(range.size()),bucket(sqrt(N)) {\n        iota(idx.begin(),idx.end(),0);\n\
    \        sort(idx.begin(),idx.end(),[&](int a, int b){\n            auto  al =\
    \ range[a].first/bucket;\n            auto  ar = range[a].second;\n          \
    \  auto  bl = range[b].first/bucket;\n            auto  br = range[b].second;\n\
    \            return (al != bl) ? (al < bl) : ((al%2)?(ar > br):(ar < br));\n \
    \       });\n    }\n    \n    //\u53C2\u7167\u3067vector\u3092\u6E21\u3057\u305F\
    \u308A\u3059\u308B\u3068\u826F\u3044\n    void solve(){\n        int l = 0, r\
    \ = 0;\n        for(int& i:idx){\n            auto& xl = range[i].first;\n   \
    \         auto& xr = range[i].second;\n            \n            //\u5DE6\u7AEF\
    \u3092\u5E83\u3052\u308B\n            while(xl < l){\n                l--;\n \
    \               extend(l);\n            }\n            //\u53F3\u7AEF\u3092\u5E83\
    \u3052\u308B\n            while(r < xr){\n                r++;\n             \
    \   extend(r);\n            }\n            //\u5DE6\u7AEF\u3092\u72ED\u3081\u308B\
    \n            while(l < xl){\n                shrink(l);\n                l++;\n\
    \            }\n            //\u53F3\u7AEF\u3092\u72ED\u3081\u308B\n         \
    \   while(xr < r){\n                shrink(r);\n                r--;\n       \
    \     }\n            mp[xl*N+xr] = get();\n        }\n    }\n\n    T operator\
    \ [] (pair<int,int> p) {\n        return mp[p.first*N+p.second];\n    }\n\nprivate:\n\
    \    \n    //\u4F38\u3073\u308B\u3068\u304D\n    void extend(int k){\n    }\n\n\
    \    //\u7E2E\u3080\u3068\u304D\n    void shrink(int k){\n    }\n\n    //\u30AF\
    \u30A8\u30EA\u7D50\u679C\n    T get(){\n        return;\n    }\n};\n"
  code: "template<class T> class Mo{\n    unordered_map<long long,int> mp;\n    long\
    \ long N;\n    int bucket;\n    vector<pair<int,int>> range;\n\tvector<int> idx;\n\
    public:\n\n    Mo(long long N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N))\
    \ {\n        iota(idx.begin(),idx.end(),0);\n        sort(idx.begin(),idx.end(),[&](int\
    \ a, int b){\n            auto  al = range[a].first/bucket;\n            auto\
    \  ar = range[a].second;\n            auto  bl = range[b].first/bucket;\n    \
    \        auto  br = range[b].second;\n            return (al != bl) ? (al < bl)\
    \ : ((al%2)?(ar > br):(ar < br));\n        });\n    }\n    \n    //\u53C2\u7167\
    \u3067vector\u3092\u6E21\u3057\u305F\u308A\u3059\u308B\u3068\u826F\u3044\n   \
    \ void solve(){\n        int l = 0, r = 0;\n        for(int& i:idx){\n       \
    \     auto& xl = range[i].first;\n            auto& xr = range[i].second;\n  \
    \          \n            //\u5DE6\u7AEF\u3092\u5E83\u3052\u308B\n            while(xl\
    \ < l){\n                l--;\n                extend(l);\n            }\n   \
    \         //\u53F3\u7AEF\u3092\u5E83\u3052\u308B\n            while(r < xr){\n\
    \                r++;\n                extend(r);\n            }\n           \
    \ //\u5DE6\u7AEF\u3092\u72ED\u3081\u308B\n            while(l < xl){\n       \
    \         shrink(l);\n                l++;\n            }\n            //\u53F3\
    \u7AEF\u3092\u72ED\u3081\u308B\n            while(xr < r){\n                shrink(r);\n\
    \                r--;\n            }\n            mp[xl*N+xr] = get();\n     \
    \   }\n    }\n\n    T operator [] (pair<int,int> p) {\n        return mp[p.first*N+p.second];\n\
    \    }\n\nprivate:\n    \n    //\u4F38\u3073\u308B\u3068\u304D\n    void extend(int\
    \ k){\n    }\n\n    //\u7E2E\u3080\u3068\u304D\n    void shrink(int k){\n    }\n\
    \n    //\u30AF\u30A8\u30EA\u7D50\u679C\n    T get(){\n        return;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Mo.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Mo.cpp
layout: document
redirect_from:
- /library/non-verified/Mo.cpp
- /library/non-verified/Mo.cpp.html
title: non-verified/Mo.cpp
---
