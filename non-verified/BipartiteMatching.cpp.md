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
  bundledCode: "#line 1 \"non-verified/BipartiteMatching.cpp\"\n\nclass BipartiteMatching\
    \ {\n\tvector<vector<int>> edge;\n\tvector<int> match, used;\n    size_t N;\n\n\
    \    int dfs(int prev) {\n        used[prev] = 1;\n        for(int curr:edge[prev]){\n\
    \            int next = match[curr];\n            if(next < 0 || (!used[next]\
    \ && dfs(next)) ) {\n                match[prev] = curr;\n                match[curr]\
    \ = prev;\n                return 1;\n            }\n        }\n        return\
    \ 0;\n    }\n\npublic:\n\n\tBipartiteMatching(int N) : N(N), edge(N), match(N,-1),\
    \ used(N) {\n\t\t// do nothing\n\t}\n\n\tvoid makeEdge(int from, int to) {\n\t\
    \tedge[from].push_back(to);\n\t}\n\n\tint maxFlow() {\n\t\tint res = 0;\n    \
    \    for(int i = 0; i < N; ++i) {\n            if(match[i] < 0) {\n          \
    \      for(int j = 0; j < N; ++j) used[j] = 0;\n                if(dfs(i)) res++;\n\
    \            }\n        }\n        return res;\n\t}\n\n    vector<pair<int,int>>\
    \ restoration(){\n        vector<pair<int,int>> vp;\n        for(int i = 0; i\
    \ < N; ++i) {\n            if(match[i] < 0) continue;\n            if(i < match[i])\
    \ vp.push_back({i,match[i]});\n        }\n        return vp;\n    }\n};\n"
  code: "\nclass BipartiteMatching {\n\tvector<vector<int>> edge;\n\tvector<int> match,\
    \ used;\n    size_t N;\n\n    int dfs(int prev) {\n        used[prev] = 1;\n \
    \       for(int curr:edge[prev]){\n            int next = match[curr];\n     \
    \       if(next < 0 || (!used[next] && dfs(next)) ) {\n                match[prev]\
    \ = curr;\n                match[curr] = prev;\n                return 1;\n  \
    \          }\n        }\n        return 0;\n    }\n\npublic:\n\n\tBipartiteMatching(int\
    \ N) : N(N), edge(N), match(N,-1), used(N) {\n\t\t// do nothing\n\t}\n\n\tvoid\
    \ makeEdge(int from, int to) {\n\t\tedge[from].push_back(to);\n\t}\n\n\tint maxFlow()\
    \ {\n\t\tint res = 0;\n        for(int i = 0; i < N; ++i) {\n            if(match[i]\
    \ < 0) {\n                for(int j = 0; j < N; ++j) used[j] = 0;\n          \
    \      if(dfs(i)) res++;\n            }\n        }\n        return res;\n\t}\n\
    \n    vector<pair<int,int>> restoration(){\n        vector<pair<int,int>> vp;\n\
    \        for(int i = 0; i < N; ++i) {\n            if(match[i] < 0) continue;\n\
    \            if(i < match[i]) vp.push_back({i,match[i]});\n        }\n       \
    \ return vp;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/BipartiteMatching.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/BipartiteMatching.cpp
layout: document
redirect_from:
- /library/non-verified/BipartiteMatching.cpp
- /library/non-verified/BipartiteMatching.cpp.html
title: non-verified/BipartiteMatching.cpp
---
