---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
  bundledCode: "#line 1 \"non-verified/LowLink.cpp\"\n\nclass LowLink{\nprivate:\n\
    \    int N,inc;\n    vector<int> ord,low;\npublic:\n    vector<vector<int>> edge;\n\
    \    vector<int> articulation;\n    vector<pair<int,int>> bridge;\n\n    LowLink(int\
    \ N) : N(N),edge(N),ord(N,-1),low(N,0) {\n        // do nothing\n    }\n    void\
    \ make_edge(int from, int to) {\n\t\tedge[from].push_back(to);\n\t}\n    void\
    \ solve() {\n        inc = 0;\n        for(int i = 0; i < N; ++i) if(ord[i]==-1)\
    \ dfs(i,-1);\n    }\nprivate:\n    void dfs(int curr,int prev) {\n        ord[curr]\
    \ = inc++;\n        low[curr] = ord[curr];\n        int isArticulation = 0;\n\
    \        int cnt = 0;\n        for(int next:edge[curr]) {\n            if(next\
    \ == prev) continue;\n            if(ord[next]==-1){\n                cnt++;\n\
    \                dfs(next,curr);\n                low[curr] = min(low[curr],low[next]);\n\
    \                if(prev != -1 && low[next] >= ord[curr]) isArticulation = 1;\n\
    \                if(ord[curr]<low[next]) {\n                    bridge.push_back({curr,next});\n\
    \                    bridge.push_back({next,curr});\n                }\n     \
    \       }\n            else{\n                low[curr] = min(low[curr],ord[next]);\n\
    \            }\n        }\n        if(prev==-1 && cnt>1) isArticulation = 1;\n\
    \        if(isArticulation) articulation.push_back(curr);\n    }\n};\n\n//verify\
    \ https://atcoder.jp/contests/arc039/tasks/arc039_d\n"
  code: "\nclass LowLink{\nprivate:\n    int N,inc;\n    vector<int> ord,low;\npublic:\n\
    \    vector<vector<int>> edge;\n    vector<int> articulation;\n    vector<pair<int,int>>\
    \ bridge;\n\n    LowLink(int N) : N(N),edge(N),ord(N,-1),low(N,0) {\n        //\
    \ do nothing\n    }\n    void make_edge(int from, int to) {\n\t\tedge[from].push_back(to);\n\
    \t}\n    void solve() {\n        inc = 0;\n        for(int i = 0; i < N; ++i)\
    \ if(ord[i]==-1) dfs(i,-1);\n    }\nprivate:\n    void dfs(int curr,int prev)\
    \ {\n        ord[curr] = inc++;\n        low[curr] = ord[curr];\n        int isArticulation\
    \ = 0;\n        int cnt = 0;\n        for(int next:edge[curr]) {\n           \
    \ if(next == prev) continue;\n            if(ord[next]==-1){\n               \
    \ cnt++;\n                dfs(next,curr);\n                low[curr] = min(low[curr],low[next]);\n\
    \                if(prev != -1 && low[next] >= ord[curr]) isArticulation = 1;\n\
    \                if(ord[curr]<low[next]) {\n                    bridge.push_back({curr,next});\n\
    \                    bridge.push_back({next,curr});\n                }\n     \
    \       }\n            else{\n                low[curr] = min(low[curr],ord[next]);\n\
    \            }\n        }\n        if(prev==-1 && cnt>1) isArticulation = 1;\n\
    \        if(isArticulation) articulation.push_back(curr);\n    }\n};\n\n//verify\
    \ https://atcoder.jp/contests/arc039/tasks/arc039_d\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/LowLink.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/LowLink.cpp
layout: document
redirect_from:
- /library/non-verified/LowLink.cpp
- /library/non-verified/LowLink.cpp.html
title: non-verified/LowLink.cpp
---
