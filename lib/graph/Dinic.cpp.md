---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Dinic.test.cpp
    title: test/graph/Dinic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/graph/Dinic.md
    document_title: Dinic
    links:
    - https://atcoder.jp/contests/arc085/tasks/arc085_c
  bundledCode: "#line 1 \"lib/graph/Dinic.cpp\"\n/*\n * @title Dinic\n * @docs md/graph/Dinic.md\n\
    \ */\ntemplate <class T> class Dinic {\n\tstruct info {\n\t\tint to, rev;\n\t\t\
    T cap;\n\t};\n\tT ini, inf;\n\tvector<vector<info>> edge;\n\tvector<int> level,\
    \ iter;\n\n\tinline void bfs(int start) {\n\t\tfor (int i = 0; i < level.size();\
    \ ++i) level[i] = -1;\n\t\tqueue<int> q;\n\t\tlevel[start] = 0;\n\t\tq.push(start);\n\
    \t\twhile (q.size()) {\n\t\t\tint from = q.front();\n\t\t\tq.pop();\n\t\t\tfor\
    \ (auto& e : edge[from]) {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\
    \t\tlevel[e.to] = level[from] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tinline T dfs(int from, int goal, T flow) {\n\t\tif (from ==\
    \ goal) return flow;\n\t\tfor (int& i = iter[from]; i < edge[from].size(); ++i)\
    \ {\n\t\t\tauto& e = edge[from][i];\n\t\t\tif (e.cap <= 0 || level[from] >= level[e.to])\
    \ continue;\n\t\t\tT dflow = dfs(e.to, goal, min(flow, e.cap));\n\t\t\tif (dflow\
    \ <= 0) continue;\n\t\t\te.cap -= dflow;\n\t\t\tedge[e.to][e.rev].cap += dflow;\n\
    \t\t\treturn dflow;\n\t\t}\n\t\treturn ini;\n\t}\n\npublic:\n\tDinic(int N, T\
    \ ini, T inf) : edge(N), level(N), iter(N), ini(ini), inf(inf) {\n\t\t// do nothing\n\
    \t}\n\n\tinline void make_edge(int from, int to, T cap) {\n\t\tedge[from].push_back({\
    \ to, (int)edge[to].size(), cap });\n\t\tedge[to].push_back({ from, (int)edge[from].size()\
    \ - 1, ini });\n\t}\n\n\tinline T maxflow(int start, int goal) {\n\t\tT maxflow\
    \ = ini;\n\t\twhile (1) {\n\t\t\tbfs(start);\n\t\t\tif (level[goal] < 0) return\
    \ maxflow;\n\t\t\tfor (int i = 0; i < iter.size(); ++i) iter[i] = 0;\n\t\t\tT\
    \ flow;\n\t\t\twhile ((flow = dfs(start, goal, inf))>0) maxflow += flow;\n\t\t\
    }\n\t}\n};\n\n//verify https://atcoder.jp/contests/arc085/tasks/arc085_c\n\n"
  code: "/*\n * @title Dinic\n * @docs md/graph/Dinic.md\n */\ntemplate <class T>\
    \ class Dinic {\n\tstruct info {\n\t\tint to, rev;\n\t\tT cap;\n\t};\n\tT ini,\
    \ inf;\n\tvector<vector<info>> edge;\n\tvector<int> level, iter;\n\n\tinline void\
    \ bfs(int start) {\n\t\tfor (int i = 0; i < level.size(); ++i) level[i] = -1;\n\
    \t\tqueue<int> q;\n\t\tlevel[start] = 0;\n\t\tq.push(start);\n\t\twhile (q.size())\
    \ {\n\t\t\tint from = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : edge[from])\
    \ {\n\t\t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\tlevel[e.to] = level[from]\
    \ + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tinline T\
    \ dfs(int from, int goal, T flow) {\n\t\tif (from == goal) return flow;\n\t\t\
    for (int& i = iter[from]; i < edge[from].size(); ++i) {\n\t\t\tauto& e = edge[from][i];\n\
    \t\t\tif (e.cap <= 0 || level[from] >= level[e.to]) continue;\n\t\t\tT dflow =\
    \ dfs(e.to, goal, min(flow, e.cap));\n\t\t\tif (dflow <= 0) continue;\n\t\t\t\
    e.cap -= dflow;\n\t\t\tedge[e.to][e.rev].cap += dflow;\n\t\t\treturn dflow;\n\t\
    \t}\n\t\treturn ini;\n\t}\n\npublic:\n\tDinic(int N, T ini, T inf) : edge(N),\
    \ level(N), iter(N), ini(ini), inf(inf) {\n\t\t// do nothing\n\t}\n\n\tinline\
    \ void make_edge(int from, int to, T cap) {\n\t\tedge[from].push_back({ to, (int)edge[to].size(),\
    \ cap });\n\t\tedge[to].push_back({ from, (int)edge[from].size() - 1, ini });\n\
    \t}\n\n\tinline T maxflow(int start, int goal) {\n\t\tT maxflow = ini;\n\t\twhile\
    \ (1) {\n\t\t\tbfs(start);\n\t\t\tif (level[goal] < 0) return maxflow;\n\t\t\t\
    for (int i = 0; i < iter.size(); ++i) iter[i] = 0;\n\t\t\tT flow;\n\t\t\twhile\
    \ ((flow = dfs(start, goal, inf))>0) maxflow += flow;\n\t\t}\n\t}\n};\n\n//verify\
    \ https://atcoder.jp/contests/arc085/tasks/arc085_c\n\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/Dinic.cpp
  requiredBy: []
  timestamp: '2020-05-13 02:18:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Dinic.test.cpp
documentation_of: lib/graph/Dinic.cpp
layout: document
redirect_from:
- /library/lib/graph/Dinic.cpp
- /library/lib/graph/Dinic.cpp.html
title: Dinic
---
##### api
- Dinic(int N, T ini, T inf)  
    - コンストラクタ  
- inline void make_edge(int from, int to, T cap)  
    - from から to に容量 cap の辺を張る  
- inline T maxflow(int start, int goal)  
    - start から goal への最大流  