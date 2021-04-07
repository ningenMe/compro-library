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
    - https://atcoder.jp/contests/arc085/tasks/arc085_c
  bundledCode: "#line 1 \"non-verified/Ford_Fulkerson.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//O(F|E|)\n\ntemplate <class T> class Ford_Fulkerson {\n\
    public:\n\tstruct info {\n\t\tint to, rev;\n\t\tT cap;\n\t};\n\tT ini, inf;\n\t\
    vector<vector<info>> edge;\n\tvector<bool> visit;\n\n\tFord_Fulkerson(int N, T\
    \ ini, T inf) : edge(N), visit(N), ini(ini), inf(inf) {\n\t\t// do nothing\n\t\
    }\n\n\tvoid make_edge(int from, int to, T cap) {\n\t\tedge[from].push_back({ to,\
    \ (int)edge[to].size(), cap });\n\t\tedge[to].push_back({ from, (int)edge[from].size()\
    \ - 1, ini });\n\t}\n\n\tT dfs(int from, int goal, T flow) {\n\t\tif (from ==\
    \ goal) return flow;\n\t\tvisit[from] = false;\n\t\tfor (int i = 0; i < edge[from].size();\
    \ ++i) {\n\t\t\tif (visit[edge[from][i].to] && edge[from][i].cap > ini) {\n\t\t\
    \t\tT dflow = dfs(edge[from][i].to, goal, min(flow, edge[from][i].cap));\n\t\t\
    \t\tif (dflow > 0) {\n\t\t\t\t\tedge[from][i].cap -= dflow;\n\t\t\t\t\tedge[edge[from][i].to][edge[from][i].rev].cap\
    \ += dflow;\n\t\t\t\t\treturn dflow;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ini;\n\
    \t}\n\n\tT maxflow(int start, int goal) {\n\t\tT maxflow = ini;\n\t\twhile (1)\
    \ {\n\t\t\tfor (int i = 0; i < edge.size(); ++i) visit[i] = true;\n\t\t\tT flow\
    \ = dfs(start, goal, inf);\n\t\t\tif (flow == ini) return maxflow;\n\t\t\tmaxflow\
    \ += flow;\n\t\t}\n\t}\n};\n\n//verify https://atcoder.jp/contests/arc085/tasks/arc085_c\n\
    \n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//O(F|E|)\n\ntemplate <class\
    \ T> class Ford_Fulkerson {\npublic:\n\tstruct info {\n\t\tint to, rev;\n\t\t\
    T cap;\n\t};\n\tT ini, inf;\n\tvector<vector<info>> edge;\n\tvector<bool> visit;\n\
    \n\tFord_Fulkerson(int N, T ini, T inf) : edge(N), visit(N), ini(ini), inf(inf)\
    \ {\n\t\t// do nothing\n\t}\n\n\tvoid make_edge(int from, int to, T cap) {\n\t\
    \tedge[from].push_back({ to, (int)edge[to].size(), cap });\n\t\tedge[to].push_back({\
    \ from, (int)edge[from].size() - 1, ini });\n\t}\n\n\tT dfs(int from, int goal,\
    \ T flow) {\n\t\tif (from == goal) return flow;\n\t\tvisit[from] = false;\n\t\t\
    for (int i = 0; i < edge[from].size(); ++i) {\n\t\t\tif (visit[edge[from][i].to]\
    \ && edge[from][i].cap > ini) {\n\t\t\t\tT dflow = dfs(edge[from][i].to, goal,\
    \ min(flow, edge[from][i].cap));\n\t\t\t\tif (dflow > 0) {\n\t\t\t\t\tedge[from][i].cap\
    \ -= dflow;\n\t\t\t\t\tedge[edge[from][i].to][edge[from][i].rev].cap += dflow;\n\
    \t\t\t\t\treturn dflow;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ini;\n\t}\n\n\t\
    T maxflow(int start, int goal) {\n\t\tT maxflow = ini;\n\t\twhile (1) {\n\t\t\t\
    for (int i = 0; i < edge.size(); ++i) visit[i] = true;\n\t\t\tT flow = dfs(start,\
    \ goal, inf);\n\t\t\tif (flow == ini) return maxflow;\n\t\t\tmaxflow += flow;\n\
    \t\t}\n\t}\n};\n\n//verify https://atcoder.jp/contests/arc085/tasks/arc085_c\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Ford_Fulkerson.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Ford_Fulkerson.cpp
layout: document
redirect_from:
- /library/non-verified/Ford_Fulkerson.cpp
- /library/non-verified/Ford_Fulkerson.cpp.html
title: non-verified/Ford_Fulkerson.cpp
---
