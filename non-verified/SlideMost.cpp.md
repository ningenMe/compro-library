---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/agc038/tasks/agc038_b
    - https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d
  bundledCode: "#line 1 \"non-verified/SlideMost.cpp\"\n\n//O(N) N: vec.size();\n\
    template<class T> vector<T> SlideMost(vector<T>& vec, const int& width, function<int(T,T)>\
    \ funcCompare){\n    vector<T> res(vec.size());\n    deque<T> deq;\n    for(int\
    \ i = 0; i < vec.size(); ++i) {\n        while(deq.size() && funcCompare(vec[deq.back()],vec[i])\
    \ ) deq.pop_back();\n        deq.push_back(i);\n        res[i] = vec[deq.front()];\n\
    \        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();\n    }\n  \
    \  return res;\n}\n\n\t// auto Amax = SlideMost<int>(A,K,[&](ll l,ll r){return\
    \ l <= r;});\n\t// auto Amin = SlideMost<int>(A,K,[&](ll l,ll r){return l >= r;});\n\
    \n//verify https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d\n\
    //verify https://atcoder.jp/contests/agc038/tasks/agc038_b\n"
  code: "\n//O(N) N: vec.size();\ntemplate<class T> vector<T> SlideMost(vector<T>&\
    \ vec, const int& width, function<int(T,T)> funcCompare){\n    vector<T> res(vec.size());\n\
    \    deque<T> deq;\n    for(int i = 0; i < vec.size(); ++i) {\n        while(deq.size()\
    \ && funcCompare(vec[deq.back()],vec[i]) ) deq.pop_back();\n        deq.push_back(i);\n\
    \        res[i] = vec[deq.front()];\n        if(i+1>=width && deq.front()==i+1-width)\
    \ deq.pop_front();\n    }\n    return res;\n}\n\n\t// auto Amax = SlideMost<int>(A,K,[&](ll\
    \ l,ll r){return l <= r;});\n\t// auto Amin = SlideMost<int>(A,K,[&](ll l,ll r){return\
    \ l >= r;});\n\n//verify https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d\n\
    //verify https://atcoder.jp/contests/agc038/tasks/agc038_b"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/SlideMost.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/SlideMost.cpp
layout: document
redirect_from:
- /library/non-verified/SlideMost.cpp
- /library/non-verified/SlideMost.cpp.html
title: non-verified/SlideMost.cpp
---
