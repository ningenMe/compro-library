---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/00-util/Zarts.cpp
    title: "Zarts - \u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"test/00-util/Zarts.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <map>\nusing namespace std;\n#line 1 \"lib/00-util/Zarts.cpp\"\n/*\n\
    \ * @title Zarts - \u5EA7\u6A19\u5727\u7E2E\n * @docs md/00-util/Zarts.md\n */\n\
    template<class T> class Zarts{\n    vector<T> value;\n    map<T,int> key;\n  \
    \  size_t sz;\npublic:\n    vector<int> compressed;\n    Zarts(const vector<T>\
    \ & ar, int light_flag = 0, T pre=-1) : compressed(ar.size()) {\n        if(!light_flag)\
    \ {\n            for (auto &e : ar) key[e];\n            int cnt=0;\n        \
    \    for (auto &e : key) e.second = cnt++;\n            for (int i=0;i<ar.size();++i)\
    \ compressed[i]=key[ar[i]];\n            value.resize(key.size());\n         \
    \   for (auto &e : key) value[e.second] = e.first;\n            sz = cnt;\n  \
    \      }\n        else {\n            vector<pair<int,int>> ord(ar.size());\n\
    \            for(int i=0;i<ar.size();++i) ord[i]={ar[i],i};\n            sort(ord.begin(),ord.end());\n\
    \            int cnt=-1;\n            for(int i=0;i<ar.size();++i) {\n       \
    \         if(pre < ord[i].first) cnt++;\n                compressed[ord[i].second]\
    \ = cnt;\n                pre = ord[i].first;\n            }\n            sz =\
    \ cnt+1;\n        }\n    }\n    T get_value(int key) {\n        return value[key];\n\
    \    }\n    int get_key(T value) {\n        assert(key.count(value));\n      \
    \  return key[value];\n    }\n    size_t size() {\n        return sz;\n    }\n\
    };\n#line 10 \"test/00-util/Zarts.test.cpp\"\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N; cin >> N;\n    vector<long long> x(N*2),y(N*2);\n    for(int i=0;i<N;++i)\
    \ {\n        cin >> x[i*2+0];\n        cin >> y[i*2+0];\n        cin >> x[i*2+1];\n\
    \        cin >> y[i*2+1];\n    }\n    Zarts<long long> Zx(x),Zy(y);\n    vector<vector<long\
    \ long>> grid(Zy.size(),vector<long long>(Zx.size(),0));\n    for(int i=0;i<N;++i)\
    \ {\n        long long x1=Zx.compressed[i*2+0],y1=Zy.compressed[i*2+0],x2=Zx.compressed[i*2+1],y2=Zy.compressed[i*2+1];\n\
    \        grid[y1][x1]++;\n        grid[y1][x2]--;\n        grid[y2][x1]--;\n \
    \       grid[y2][x2]++;\n    }    \n    for(int i=0;i<Zy.size();++i) {\n     \
    \   for(int j=1;j<Zx.size();++j) {\n            grid[i][j] += grid[i][j-1];\n\
    \        }\n    }\n    for(int j=0;j<Zx.size();++j) {\n        for(int i=1;i<Zy.size();++i)\
    \ {\n            grid[i][j] += grid[i-1][j];\n        }\n    }\n    long long\
    \ ans = 0;\n    for(int i=0;i+1<Zy.size();++i) {\n        for(int j=0;j+1<Zx.size();++j)\
    \ {\n            if(grid[i][j]) ans += (Zy.get_value(i+1)-Zy.get_value(i))*(Zx.get_value(j+1)-Zx.get_value(j));\n\
    \        }\n    }\n    cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <map>\nusing namespace std;\n#include \"../../lib/00-util/Zarts.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin\
    \ >> N;\n    vector<long long> x(N*2),y(N*2);\n    for(int i=0;i<N;++i) {\n  \
    \      cin >> x[i*2+0];\n        cin >> y[i*2+0];\n        cin >> x[i*2+1];\n\
    \        cin >> y[i*2+1];\n    }\n    Zarts<long long> Zx(x),Zy(y);\n    vector<vector<long\
    \ long>> grid(Zy.size(),vector<long long>(Zx.size(),0));\n    for(int i=0;i<N;++i)\
    \ {\n        long long x1=Zx.compressed[i*2+0],y1=Zy.compressed[i*2+0],x2=Zx.compressed[i*2+1],y2=Zy.compressed[i*2+1];\n\
    \        grid[y1][x1]++;\n        grid[y1][x2]--;\n        grid[y2][x1]--;\n \
    \       grid[y2][x2]++;\n    }    \n    for(int i=0;i<Zy.size();++i) {\n     \
    \   for(int j=1;j<Zx.size();++j) {\n            grid[i][j] += grid[i][j-1];\n\
    \        }\n    }\n    for(int j=0;j<Zx.size();++j) {\n        for(int i=1;i<Zy.size();++i)\
    \ {\n            grid[i][j] += grid[i-1][j];\n        }\n    }\n    long long\
    \ ans = 0;\n    for(int i=0;i+1<Zy.size();++i) {\n        for(int j=0;j+1<Zx.size();++j)\
    \ {\n            if(grid[i][j]) ans += (Zy.get_value(i+1)-Zy.get_value(i))*(Zx.get_value(j+1)-Zx.get_value(j));\n\
    \        }\n    }\n    cout << ans << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/00-util/Zarts.cpp
  isVerificationFile: true
  path: test/00-util/Zarts.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:03:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/00-util/Zarts.test.cpp
layout: document
redirect_from:
- /verify/test/00-util/Zarts.test.cpp
- /verify/test/00-util/Zarts.test.cpp.html
title: test/00-util/Zarts.test.cpp
---
