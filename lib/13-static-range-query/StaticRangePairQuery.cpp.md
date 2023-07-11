---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/static-range-query/StaticRangePairQuery.md
    document_title: "StaticRangePairQuery - \u9759\u7684\u533A\u9593pair\u30AF\u30A8\
      \u30EA"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/StaticRangePairQuery.cpp\"\n/*\n\
    \ * @title StaticRangePairQuery - \u9759\u7684\u533A\u9593pair\u30AF\u30A8\u30EA\
    \n * @docs md/static-range-query/StaticRangePairQuery.md\n */\ntemplate<class\
    \ T> class StaticRangePairQuery {\n    vector<int> compressed;\n    vector<vector<size_t>>\
    \ sqrt_bucket_count;\n    vector<vector<int>> acc;\n    size_t length,bucket_size,val_size;\n\
    \    vector<size_t> tmp;\npublic:\n    StaticRangePairQuery(const vector<T>& ar,\
    \ T pre=-1) : compressed(ar.size()) {\n        length = ar.size();\n        bucket_size\
    \ = sqrt(length) + 1;\n        //zarts\n        {\n            vector<pair<T,size_t>>\
    \ ord(length);\n            for(size_t i=0;i<length;++i) ord[i]={ar[i],i};\n \
    \           sort(ord.begin(),ord.end());\n            int inc=-1;\n          \
    \  for(size_t i=0;i<length;++i) {\n                if(pre < ord[i].first) inc++;\n\
    \                compressed[ord[i].second] = inc;\n                pre = ord[i].first;\n\
    \            }\n            val_size = inc + 1;\n            tmp.resize(val_size);\n\
    \        }\n        //sqrt bucket\n        {\n            sqrt_bucket_count.resize(bucket_size+1,vector<size_t>(bucket_size+1));\n\
    \            for(size_t l = 0; l < length; l += bucket_size) {\n             \
    \   for(size_t i = 0; i < val_size; ++i) tmp[i]=0;\n\n                size_t bl\
    \ = l/bucket_size;\n                for(size_t r = l; r < length; ++r) {\n   \
    \                 int val=compressed[r];\n                    tmp[val]++;\n  \
    \                  if(tmp[val]==2) {\n                        tmp[val]=0;\n  \
    \                      size_t br = r/bucket_size + 1;\n                      \
    \  sqrt_bucket_count[bl][br]++;\n                    }\n                }\n  \
    \              for(size_t r = l+bucket_size; r < length; r += bucket_size) {\n\
    \                    size_t br = r/bucket_size + 1;\n                    sqrt_bucket_count[bl][br]\
    \ += sqrt_bucket_count[bl][br-1];\n                }\n            }\n        \
    \    //query\u3067\u4F7F\u3044\u56DE\u3059\u304B\u30890\u306B\u3057\u3066\u304A\
    \u304F\n            for(size_t i = 0; i < val_size; ++i) tmp[i]=0;\n        }\n\
    \        \n        //acc\n        {\n            acc.resize(val_size, vector<int>(bucket_size+1,\
    \ 0));\n            for(size_t i = 0; i < length; ++i) acc[compressed[i]][i/bucket_size\
    \ + 1]++;\n            for(size_t i = 0; i < val_size; ++i) {\n              \
    \  for(size_t j = 0; j+1 < bucket_size+1; ++j) acc[i][j+1] += acc[i][j];\n   \
    \         }\n        }\n    }\n    //[l,r) \u306B\u304A\u3051\u308BA[i]\u306E\u30DA\
    \u30A2\u306E\u6570\n    int get(int l, int r) {\n        stack<size_t> st;\n \
    \       int res = 0;\n\n        //naive\n        if(r - l <= bucket_size) {\n\
    \            for(int i = l; i < r; ++i) {\n                size_t val = compressed[i];\n\
    \                st.push(val);\n                tmp[val]++;\n                if(tmp[val]==2)\
    \ {\n                    tmp[val]=0;\n                    res++;\n           \
    \     }\n            }\n            while(st.size()) {\n                auto val\
    \ = st.top(); st.pop();\n                tmp[val]=0;\n            }\n        \
    \    return res;\n        }\n\n        int bl = l/bucket_size + !!(l%bucket_size),\
    \ br = r/bucket_size;\n\n        int ml = bl * bucket_size, mr = br * bucket_size;\n\
    \        ml = min(ml,r); mr = max(l,mr);\n        res += sqrt_bucket_count[bl][br];\
    \    \n\n        //\u5DE6\u5074\u306E\u63A2\u7D22\n        for(int i = l; i <\
    \ ml; ++i) {\n            size_t val = compressed[i];\n            st.push(val);\n\
    \            tmp[val]++;\n            if(tmp[val]==2) {\n                tmp[val]=0;\n\
    \                res++;\n            }\n        }\n        //\u53F3\u5074\u306E\
    \u63A2\u7D22\n        for(int i = mr; i < r; ++i) {\n            size_t val =\
    \ compressed[i];\n            st.push(val);\n            tmp[val]++;\n       \
    \     if(tmp[val]==2) {\n                tmp[val]=0;\n                res++;\n\
    \            }\n        }\n        //1\u500B\u4F59\u3063\u3066\u308B\u3082\u306E\
    \u3068\u3001[ml,mr) \u3067\u63A2\u7D22\n        while(st.size()) {\n         \
    \   auto val = st.top(); st.pop();\n            if(tmp[val]==0) continue;\n  \
    \          tmp[val]=0;\n            int cnt = acc[val][br] - acc[val][bl];\n \
    \           //\u5408\u8A08\u304C\u5947\u6570\u3060\u3063\u305F\u30891\u500B\u4F59\
    \u3063\u3066\u308B\u304B\u3089\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\n   \
    \         if(cnt&1) res++;\n        }\n\n        return res;\n    }\n};\n"
  code: "/*\n * @title StaticRangePairQuery - \u9759\u7684\u533A\u9593pair\u30AF\u30A8\
    \u30EA\n * @docs md/static-range-query/StaticRangePairQuery.md\n */\ntemplate<class\
    \ T> class StaticRangePairQuery {\n    vector<int> compressed;\n    vector<vector<size_t>>\
    \ sqrt_bucket_count;\n    vector<vector<int>> acc;\n    size_t length,bucket_size,val_size;\n\
    \    vector<size_t> tmp;\npublic:\n    StaticRangePairQuery(const vector<T>& ar,\
    \ T pre=-1) : compressed(ar.size()) {\n        length = ar.size();\n        bucket_size\
    \ = sqrt(length) + 1;\n        //zarts\n        {\n            vector<pair<T,size_t>>\
    \ ord(length);\n            for(size_t i=0;i<length;++i) ord[i]={ar[i],i};\n \
    \           sort(ord.begin(),ord.end());\n            int inc=-1;\n          \
    \  for(size_t i=0;i<length;++i) {\n                if(pre < ord[i].first) inc++;\n\
    \                compressed[ord[i].second] = inc;\n                pre = ord[i].first;\n\
    \            }\n            val_size = inc + 1;\n            tmp.resize(val_size);\n\
    \        }\n        //sqrt bucket\n        {\n            sqrt_bucket_count.resize(bucket_size+1,vector<size_t>(bucket_size+1));\n\
    \            for(size_t l = 0; l < length; l += bucket_size) {\n             \
    \   for(size_t i = 0; i < val_size; ++i) tmp[i]=0;\n\n                size_t bl\
    \ = l/bucket_size;\n                for(size_t r = l; r < length; ++r) {\n   \
    \                 int val=compressed[r];\n                    tmp[val]++;\n  \
    \                  if(tmp[val]==2) {\n                        tmp[val]=0;\n  \
    \                      size_t br = r/bucket_size + 1;\n                      \
    \  sqrt_bucket_count[bl][br]++;\n                    }\n                }\n  \
    \              for(size_t r = l+bucket_size; r < length; r += bucket_size) {\n\
    \                    size_t br = r/bucket_size + 1;\n                    sqrt_bucket_count[bl][br]\
    \ += sqrt_bucket_count[bl][br-1];\n                }\n            }\n        \
    \    //query\u3067\u4F7F\u3044\u56DE\u3059\u304B\u30890\u306B\u3057\u3066\u304A\
    \u304F\n            for(size_t i = 0; i < val_size; ++i) tmp[i]=0;\n        }\n\
    \        \n        //acc\n        {\n            acc.resize(val_size, vector<int>(bucket_size+1,\
    \ 0));\n            for(size_t i = 0; i < length; ++i) acc[compressed[i]][i/bucket_size\
    \ + 1]++;\n            for(size_t i = 0; i < val_size; ++i) {\n              \
    \  for(size_t j = 0; j+1 < bucket_size+1; ++j) acc[i][j+1] += acc[i][j];\n   \
    \         }\n        }\n    }\n    //[l,r) \u306B\u304A\u3051\u308BA[i]\u306E\u30DA\
    \u30A2\u306E\u6570\n    int get(int l, int r) {\n        stack<size_t> st;\n \
    \       int res = 0;\n\n        //naive\n        if(r - l <= bucket_size) {\n\
    \            for(int i = l; i < r; ++i) {\n                size_t val = compressed[i];\n\
    \                st.push(val);\n                tmp[val]++;\n                if(tmp[val]==2)\
    \ {\n                    tmp[val]=0;\n                    res++;\n           \
    \     }\n            }\n            while(st.size()) {\n                auto val\
    \ = st.top(); st.pop();\n                tmp[val]=0;\n            }\n        \
    \    return res;\n        }\n\n        int bl = l/bucket_size + !!(l%bucket_size),\
    \ br = r/bucket_size;\n\n        int ml = bl * bucket_size, mr = br * bucket_size;\n\
    \        ml = min(ml,r); mr = max(l,mr);\n        res += sqrt_bucket_count[bl][br];\
    \    \n\n        //\u5DE6\u5074\u306E\u63A2\u7D22\n        for(int i = l; i <\
    \ ml; ++i) {\n            size_t val = compressed[i];\n            st.push(val);\n\
    \            tmp[val]++;\n            if(tmp[val]==2) {\n                tmp[val]=0;\n\
    \                res++;\n            }\n        }\n        //\u53F3\u5074\u306E\
    \u63A2\u7D22\n        for(int i = mr; i < r; ++i) {\n            size_t val =\
    \ compressed[i];\n            st.push(val);\n            tmp[val]++;\n       \
    \     if(tmp[val]==2) {\n                tmp[val]=0;\n                res++;\n\
    \            }\n        }\n        //1\u500B\u4F59\u3063\u3066\u308B\u3082\u306E\
    \u3068\u3001[ml,mr) \u3067\u63A2\u7D22\n        while(st.size()) {\n         \
    \   auto val = st.top(); st.pop();\n            if(tmp[val]==0) continue;\n  \
    \          tmp[val]=0;\n            int cnt = acc[val][br] - acc[val][bl];\n \
    \           //\u5408\u8A08\u304C\u5947\u6570\u3060\u3063\u305F\u30891\u500B\u4F59\
    \u3063\u3066\u308B\u304B\u3089\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\n   \
    \         if(cnt&1) res++;\n        }\n\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/StaticRangePairQuery.cpp
  requiredBy: []
  timestamp: '2023-07-12 04:26:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/13-static-range-query/StaticRangePairQuery.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/StaticRangePairQuery.cpp
- /library/lib/13-static-range-query/StaticRangePairQuery.cpp.html
title: "StaticRangePairQuery - \u9759\u7684\u533A\u9593pair\u30AF\u30A8\u30EA"
---
### StaticRangePairQuery
- 静的区間pairクエリ
  - 半開区間[l,r)に対するpairの数を求める
  - 列の更新は出来ない。
  - [提出](https://atcoder.jp/contests/abc242/submissions/43492117)
  - [提出](https://atcoder.jp/contests/abc295/submissions/43492103)
