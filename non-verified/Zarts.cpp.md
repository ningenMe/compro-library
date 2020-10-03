---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc036/tasks/abc036_c
  bundledCode: "#line 1 \"non-verified/Zarts.cpp\"\n//Seat Pressure O(NlogN)\ntemplate<class\
    \ T> vector<int> Zarts(const vector<T> & ar, int cnt = 0) {\n    vector<int> res;\n\
    \    map<T, int> mp;\n    for (auto &e : ar) mp[e] = 0;\n    for (auto &e : mp)\
    \ e.second = cnt++;\n    for (auto &e : ar) res.push_back(mp[e]);\n    return\
    \ res;\n}\n\n\n//verify https://atcoder.jp/contests/abc036/tasks/abc036_c\n"
  code: "//Seat Pressure O(NlogN)\ntemplate<class T> vector<int> Zarts(const vector<T>\
    \ & ar, int cnt = 0) {\n    vector<int> res;\n    map<T, int> mp;\n    for (auto\
    \ &e : ar) mp[e] = 0;\n    for (auto &e : mp) e.second = cnt++;\n    for (auto\
    \ &e : ar) res.push_back(mp[e]);\n    return res;\n}\n\n\n//verify https://atcoder.jp/contests/abc036/tasks/abc036_c"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Zarts.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Zarts.cpp
layout: document
redirect_from:
- /library/non-verified/Zarts.cpp
- /library/non-verified/Zarts.cpp.html
title: non-verified/Zarts.cpp
---
