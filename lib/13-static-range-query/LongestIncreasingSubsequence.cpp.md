---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static-range-query/LongestIncreasingSubsequence-index.test.cpp
    title: test/static-range-query/LongestIncreasingSubsequence-index.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
    title: test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/13-static-range-query/LongestIncreasingSubsequence.md
    document_title: LongestIncreasingSubsequence - LIS
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/LongestIncreasingSubsequence.cpp\"\
    \n/*\n * @title LongestIncreasingSubsequence - LIS\n * @docs md/13-static-range-query/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> class LongestIncreasingSubsequence {\n    size_t length;\n\
    \    size_t sz;\n    vector<size_t> dp_key;\n    vector<T> dp_val;\n    vector<size_t>\
    \ pre;\npublic:\n    LongestIncreasingSubsequence(const vector<T> & ar, T inf=3e18)\
    \ {\n        length = ar.size();\n        dp_key.resize(length, length);\n   \
    \     dp_val.resize(length, inf);\n        pre.resize(length);\n        for (int\
    \ i = 0; i < length; ++i) {\n            int key = lower_bound(dp_val.begin(),\
    \ dp_val.end(), ar[i]) - dp_val.begin();\n            dp_val[key] = ar[i];\n \
    \           dp_key[key] = i;\n            pre[i] = (key ? dp_key[key-1] : length);\n\
    \        };\n        sz = lower_bound(dp_val.begin(), dp_val.end(), inf) - dp_val.begin();\n\
    \    }\n\n    int size() {\n        return sz;\n    }\n\n    vector<int> index()\
    \ {\n        vector<int> res;\n        for(size_t idx = dp_key[sz-1]; idx != length;\
    \ idx = pre[idx]) {\n            res.push_back(idx);\n        }\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n \n};\n"
  code: "/*\n * @title LongestIncreasingSubsequence - LIS\n * @docs md/13-static-range-query/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> class LongestIncreasingSubsequence {\n    size_t length;\n\
    \    size_t sz;\n    vector<size_t> dp_key;\n    vector<T> dp_val;\n    vector<size_t>\
    \ pre;\npublic:\n    LongestIncreasingSubsequence(const vector<T> & ar, T inf=3e18)\
    \ {\n        length = ar.size();\n        dp_key.resize(length, length);\n   \
    \     dp_val.resize(length, inf);\n        pre.resize(length);\n        for (int\
    \ i = 0; i < length; ++i) {\n            int key = lower_bound(dp_val.begin(),\
    \ dp_val.end(), ar[i]) - dp_val.begin();\n            dp_val[key] = ar[i];\n \
    \           dp_key[key] = i;\n            pre[i] = (key ? dp_key[key-1] : length);\n\
    \        };\n        sz = lower_bound(dp_val.begin(), dp_val.end(), inf) - dp_val.begin();\n\
    \    }\n\n    int size() {\n        return sz;\n    }\n\n    vector<int> index()\
    \ {\n        vector<int> res;\n        for(size_t idx = dp_key[sz-1]; idx != length;\
    \ idx = pre[idx]) {\n            res.push_back(idx);\n        }\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/LongestIncreasingSubsequence.cpp
  requiredBy: []
  timestamp: '2023-07-09 01:40:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static-range-query/LongestIncreasingSubsequence-size.test.cpp
  - test/static-range-query/LongestIncreasingSubsequence-index.test.cpp
documentation_of: lib/13-static-range-query/LongestIncreasingSubsequence.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/LongestIncreasingSubsequence.cpp
- /library/lib/13-static-range-query/LongestIncreasingSubsequence.cpp.html
title: LongestIncreasingSubsequence - LIS
---
