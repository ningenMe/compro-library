---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/70-geometory/Argument.cpp
    title: "Argument - \u504F\u89D2"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/geometory/Argument-sort-by-atan2l.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <cmath>\n#include <algorithm>\n#include\
    \ <numeric>\n\nusing namespace std;\n#line 1 \"lib/70-geometory/Argument.cpp\"\
    \n/*\n * @title Argument - \u504F\u89D2\n * @docs md/geometory/Argument.md\n */\n\
    class Argument {\npublic:\n    template<class T> inline static vector<int> sort_by_atan2l(vector<pair<T,T>>\
    \ points){\n        int N = points.size();\n        vector<long double> arg(N);\n\
    \        for(int i = 0; i < N; ++i) arg[i] = atan2l(points[i].second,points[i].first);\n\
    \        vector<int> res(N);\n        iota(res.begin(),res.end(),0);\n       \
    \ sort(res.begin(),res.end(),[&](int l,int r){return arg[l] < arg[r];});\n   \
    \     return res;\n    }\n};\n#line 11 \"test/geometory/Argument-sort-by-atan2l.test.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<pair<long long,long long>>\
    \ points(N);\n    for(int i = 0; i < N; ++i) {\n        long long a,b; cin >>\
    \ a >> b;\n        points[i] = {a,b};\n    }\n    auto idx = Argument::sort_by_atan2l<long\
    \ long>(points);\n    for(int i = 0; i < N; ++i) {\n        cout << points[idx[i]].first\
    \ << \" \" << points[idx[i]].second << endl; \n    }\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <iostream>\n#include <vector>\n#include <cmath>\n#include <algorithm>\n\
    #include <numeric>\n\nusing namespace std;\n#include \"../../lib/70-geometory/Argument.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<pair<long long,long long>>\
    \ points(N);\n    for(int i = 0; i < N; ++i) {\n        long long a,b; cin >>\
    \ a >> b;\n        points[i] = {a,b};\n    }\n    auto idx = Argument::sort_by_atan2l<long\
    \ long>(points);\n    for(int i = 0; i < N; ++i) {\n        cout << points[idx[i]].first\
    \ << \" \" << points[idx[i]].second << endl; \n    }\n\treturn 0;\n}"
  dependsOn:
  - lib/70-geometory/Argument.cpp
  isVerificationFile: true
  path: test/geometory/Argument-sort-by-atan2l.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:39:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometory/Argument-sort-by-atan2l.test.cpp
layout: document
redirect_from:
- /verify/test/geometory/Argument-sort-by-atan2l.test.cpp
- /verify/test/geometory/Argument-sort-by-atan2l.test.cpp.html
title: test/geometory/Argument-sort-by-atan2l.test.cpp
---
