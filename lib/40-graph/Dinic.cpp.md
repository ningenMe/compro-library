---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Dinic.test.cpp
    title: test/graph/Dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/Dinic.md
    document_title: "Dinic - Dinic\u30D5\u30ED\u30FC"
    links:
    - https://atcoder.jp/contests/arc085/tasks/arc085_c
  bundledCode: "#line 1 \"lib/40-graph/Dinic.cpp\"\n/*\n * @title Dinic - Dinic\u30D5\
    \u30ED\u30FC\n * @docs md/graph/Dinic.md\n */\ntemplate <class T> class Dinic\
    \ {\n    struct info {\n        int to, rev;\n        T cap;\n    };\n    T ini,\
    \ inf;\n    vector<vector<info>> edge;\n    vector<int> level, iter;\n\n    inline\
    \ void bfs(int start) {\n        for (int i = 0; i < level.size(); ++i) level[i]\
    \ = -1;\n        queue<int> q;\n        level[start] = 0;\n        q.push(start);\n\
    \        while (q.size()) {\n            int from = q.front();\n            q.pop();\n\
    \            for (auto& e : edge[from]) {\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\n                    level[e.to] = level[from] + 1;\n               \
    \     q.push(e.to);\n                }\n            }\n        }\n    }\n\n  \
    \  inline T dfs(int from, int goal, T flow) {\n        if (from == goal) return\
    \ flow;\n        for (int& i = iter[from]; i < edge[from].size(); ++i) {\n   \
    \         auto& e = edge[from][i];\n            if (e.cap <= 0 || level[from]\
    \ >= level[e.to]) continue;\n            T dflow = dfs(e.to, goal, min(flow, e.cap));\n\
    \            if (dflow <= 0) continue;\n            e.cap -= dflow;\n        \
    \    edge[e.to][e.rev].cap += dflow;\n            return dflow;\n        }\n \
    \       return ini;\n    }\n\npublic:\n    Dinic(int N, T ini, T inf) : edge(N),\
    \ level(N), iter(N), ini(ini), inf(inf) {\n        // do nothing\n    }\n\n  \
    \  inline void make_edge(int from, int to, T cap) {\n        edge[from].push_back({\
    \ to, (int)edge[to].size(), cap });\n        edge[to].push_back({ from, (int)edge[from].size()\
    \ - 1, ini });\n    }\n\n    inline T maxflow(int start, int goal) {\n       \
    \ T maxflow = ini;\n        while (1) {\n            bfs(start);\n           \
    \ if (level[goal] < 0) return maxflow;\n            for (int i = 0; i < iter.size();\
    \ ++i) iter[i] = 0;\n            T flow;\n            while ((flow = dfs(start,\
    \ goal, inf))>0) maxflow += flow;\n        }\n    }\n};\n\n//verify https://atcoder.jp/contests/arc085/tasks/arc085_c\n\
    \n"
  code: "/*\n * @title Dinic - Dinic\u30D5\u30ED\u30FC\n * @docs md/graph/Dinic.md\n\
    \ */\ntemplate <class T> class Dinic {\n    struct info {\n        int to, rev;\n\
    \        T cap;\n    };\n    T ini, inf;\n    vector<vector<info>> edge;\n   \
    \ vector<int> level, iter;\n\n    inline void bfs(int start) {\n        for (int\
    \ i = 0; i < level.size(); ++i) level[i] = -1;\n        queue<int> q;\n      \
    \  level[start] = 0;\n        q.push(start);\n        while (q.size()) {\n   \
    \         int from = q.front();\n            q.pop();\n            for (auto&\
    \ e : edge[from]) {\n                if (e.cap > 0 && level[e.to] < 0) {\n   \
    \                 level[e.to] = level[from] + 1;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    inline T dfs(int from,\
    \ int goal, T flow) {\n        if (from == goal) return flow;\n        for (int&\
    \ i = iter[from]; i < edge[from].size(); ++i) {\n            auto& e = edge[from][i];\n\
    \            if (e.cap <= 0 || level[from] >= level[e.to]) continue;\n       \
    \     T dflow = dfs(e.to, goal, min(flow, e.cap));\n            if (dflow <= 0)\
    \ continue;\n            e.cap -= dflow;\n            edge[e.to][e.rev].cap +=\
    \ dflow;\n            return dflow;\n        }\n        return ini;\n    }\n\n\
    public:\n    Dinic(int N, T ini, T inf) : edge(N), level(N), iter(N), ini(ini),\
    \ inf(inf) {\n        // do nothing\n    }\n\n    inline void make_edge(int from,\
    \ int to, T cap) {\n        edge[from].push_back({ to, (int)edge[to].size(), cap\
    \ });\n        edge[to].push_back({ from, (int)edge[from].size() - 1, ini });\n\
    \    }\n\n    inline T maxflow(int start, int goal) {\n        T maxflow = ini;\n\
    \        while (1) {\n            bfs(start);\n            if (level[goal] < 0)\
    \ return maxflow;\n            for (int i = 0; i < iter.size(); ++i) iter[i] =\
    \ 0;\n            T flow;\n            while ((flow = dfs(start, goal, inf))>0)\
    \ maxflow += flow;\n        }\n    }\n};\n\n//verify https://atcoder.jp/contests/arc085/tasks/arc085_c\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: lib/40-graph/Dinic.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Dinic.test.cpp
documentation_of: lib/40-graph/Dinic.cpp
layout: document
redirect_from:
- /library/lib/40-graph/Dinic.cpp
- /library/lib/40-graph/Dinic.cpp.html
title: "Dinic - Dinic\u30D5\u30ED\u30FC"
---
##### api
- Dinic(int N, T ini, T inf)  
    - コンストラクタ  
- inline void make_edge(int from, int to, T cap)  
    - from から to に容量 cap の辺を張る  
- inline T maxflow(int start, int goal)  
    - start から goal への最大流  