---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static-range-query/SlideMost.test.cpp
    title: test/static-range-query/SlideMost.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/SlideMost.md
    document_title: "SlideMost - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024/\u6700\
      \u5927\u5024"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/SlideMost.cpp\"\n/*\n * @title\
    \ SlideMost - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024/\u6700\u5927\u5024\n\
    \ * @docs md/data-structure/SlideMost.md\n */\ntemplate<class Operator> class\
    \ SlideMost {\n    using TypeValue = typename Operator::TypeValue;\npublic:\n\
    \    SlideMost(void){\n    }\n    vector<TypeValue> window(vector<TypeValue>&\
    \ vec, const int& width){\n        vector<TypeValue> res(vec.size());\n      \
    \  deque<TypeValue> deq;\n        for(int i = 0; i < vec.size(); ++i) {\n    \
    \        while(deq.size() && Operator::func_compare(vec[deq.back()],vec[i]) )\
    \ deq.pop_back();\n            deq.push_back(i);\n            res[i] = vec[deq.front()];\n\
    \            if(i+1>=width && deq.front()==i+1-width) deq.pop_front();\n     \
    \   }\n        return res;\n    }\n};\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n\
    template<class T> struct ValueMin {\n    using TypeValue = T;\n    inline static\
    \ constexpr bool func_compare(TypeValue l,TypeValue r){return l>=r;}\n};\n//\u6700\
    \u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMax {\n    using\
    \ TypeValue = T;\n    inline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<=r;}\n};\n"
  code: "/*\n * @title SlideMost - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024/\u6700\
    \u5927\u5024\n * @docs md/data-structure/SlideMost.md\n */\ntemplate<class Operator>\
    \ class SlideMost {\n    using TypeValue = typename Operator::TypeValue;\npublic:\n\
    \    SlideMost(void){\n    }\n    vector<TypeValue> window(vector<TypeValue>&\
    \ vec, const int& width){\n        vector<TypeValue> res(vec.size());\n      \
    \  deque<TypeValue> deq;\n        for(int i = 0; i < vec.size(); ++i) {\n    \
    \        while(deq.size() && Operator::func_compare(vec[deq.back()],vec[i]) )\
    \ deq.pop_back();\n            deq.push_back(i);\n            res[i] = vec[deq.front()];\n\
    \            if(i+1>=width && deq.front()==i+1-width) deq.pop_front();\n     \
    \   }\n        return res;\n    }\n};\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\n\
    template<class T> struct ValueMin {\n    using TypeValue = T;\n    inline static\
    \ constexpr bool func_compare(TypeValue l,TypeValue r){return l>=r;}\n};\n//\u6700\
    \u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class T> struct ValueMax {\n    using\
    \ TypeValue = T;\n    inline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<=r;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/SlideMost.cpp
  requiredBy: []
  timestamp: '2023-06-08 02:51:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static-range-query/SlideMost.test.cpp
documentation_of: lib/13-static-range-query/SlideMost.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/SlideMost.cpp
- /library/lib/13-static-range-query/SlideMost.cpp.html
title: "SlideMost - \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024/\u6700\u5927\u5024"
---
