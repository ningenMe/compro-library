---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/DinicMaxFlow-1.test.cpp
    title: test/graph/DinicMaxFlow-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/DinicMaxFlow-2.test.cpp
    title: test/graph/DinicMaxFlow-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/DinicMaxFlow.md
    document_title: "DinicMaxFlow - Dinic\u30D5\u30ED\u30FC"
    links: []
  bundledCode: "#line 1 \"lib/40-graph/DinicMaxFlow.cpp\"\n\n/*\n * @title DinicMaxFlow\
    \ - Dinic\u30D5\u30ED\u30FC\n * @docs md/graph/DinicMaxFlow.md\n */\ntemplate\
    \ <class TypeFlow> class DinicMaxFlow {\n\tstruct Edge {\n\t\tsize_t to, rev;\n\
    \t\tTypeFlow cap;\n\t};\n\tvector<vector<Edge>> edge;\n\tvector<int> level, iter;\n\
    \    TypeFlow inf_flow;\n\n\tinline void bfs(const size_t start) {\n\t\tfor (int\
    \ i = 0; i < level.size(); ++i) level[i] = -1;\n\t\tqueue<size_t> q;\n\t\tlevel[start]\
    \ = 0;\n\t\tq.push(start);\n\t\twhile (q.size()) {\n\t\t\tauto from = q.front();\n\
    \t\t\tq.pop();\n\t\t\tfor (auto& e : edge[from]) {\n\t\t\t\tif (e.cap > 0 && level[e.to]\
    \ < 0) {\n\t\t\t\t\tlevel[e.to] = level[from] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tinline TypeFlow dfs(size_t from, size_t goal,\
    \ TypeFlow flow) {\n\t\tif (from == goal) return flow;\n\t\tfor (int& i = iter[from];\
    \ i < edge[from].size(); ++i) {\n            //TODO \u53C2\u7167\u304C\u52B9\u3044\
    \u3066\u306A\u304F\u3066\u5197\u9577\n\t\t\tauto& e = edge[from][i];\n\t\t\tif\
    \ (e.cap <= 0 || level[from] >= level[e.to]) continue;\n\t\t\tTypeFlow dflow =\
    \ dfs(e.to, goal, min(flow, e.cap));\n\t\t\tif (dflow <= 0) continue;\n\t\t\t\
    e.cap -= dflow;\n\t\t\tedge[e.to][e.rev].cap += dflow;\n\t\t\treturn dflow;\n\t\
    \t}\n\t\treturn 0;\n\t}\n\npublic:\n\tDinicMaxFlow(const size_t N) : edge(N),\
    \ level(N), iter(N), inf_flow(0) {\n\t\t// do nothing\n\t}\n\n\tinline void make_edge(const\
    \ size_t from,const size_t to, TypeFlow cap) {\n\t\tedge[from].push_back({ to,\
    \ edge[to].size(), cap });\n\t\tedge[to].push_back({ from, edge[from].size() -\
    \ 1, 0});\n        inf_flow += cap;\n\t}\n\n\tinline TypeFlow flow(const size_t\
    \ start,const size_t goal) {\n\t\tTypeFlow max_flow = 0;\n\t\twhile (1) {\n\t\t\
    \tbfs(start);\n\t\t\tif (level[goal] < 0) return max_flow;\n\t\t\tfor (int i =\
    \ 0; i < iter.size(); ++i) iter[i] = 0;\n\t\t\tTypeFlow flow;\n\t\t\twhile ((flow\
    \ = dfs(start, goal, inf_flow))>0) max_flow += flow;\n\t\t}\n\t}\n};\n"
  code: "\n/*\n * @title DinicMaxFlow - Dinic\u30D5\u30ED\u30FC\n * @docs md/graph/DinicMaxFlow.md\n\
    \ */\ntemplate <class TypeFlow> class DinicMaxFlow {\n\tstruct Edge {\n\t\tsize_t\
    \ to, rev;\n\t\tTypeFlow cap;\n\t};\n\tvector<vector<Edge>> edge;\n\tvector<int>\
    \ level, iter;\n    TypeFlow inf_flow;\n\n\tinline void bfs(const size_t start)\
    \ {\n\t\tfor (int i = 0; i < level.size(); ++i) level[i] = -1;\n\t\tqueue<size_t>\
    \ q;\n\t\tlevel[start] = 0;\n\t\tq.push(start);\n\t\twhile (q.size()) {\n\t\t\t\
    auto from = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : edge[from]) {\n\t\
    \t\t\tif (e.cap > 0 && level[e.to] < 0) {\n\t\t\t\t\tlevel[e.to] = level[from]\
    \ + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tinline TypeFlow\
    \ dfs(size_t from, size_t goal, TypeFlow flow) {\n\t\tif (from == goal) return\
    \ flow;\n\t\tfor (int& i = iter[from]; i < edge[from].size(); ++i) {\n       \
    \     //TODO \u53C2\u7167\u304C\u52B9\u3044\u3066\u306A\u304F\u3066\u5197\u9577\
    \n\t\t\tauto& e = edge[from][i];\n\t\t\tif (e.cap <= 0 || level[from] >= level[e.to])\
    \ continue;\n\t\t\tTypeFlow dflow = dfs(e.to, goal, min(flow, e.cap));\n\t\t\t\
    if (dflow <= 0) continue;\n\t\t\te.cap -= dflow;\n\t\t\tedge[e.to][e.rev].cap\
    \ += dflow;\n\t\t\treturn dflow;\n\t\t}\n\t\treturn 0;\n\t}\n\npublic:\n\tDinicMaxFlow(const\
    \ size_t N) : edge(N), level(N), iter(N), inf_flow(0) {\n\t\t// do nothing\n\t\
    }\n\n\tinline void make_edge(const size_t from,const size_t to, TypeFlow cap)\
    \ {\n\t\tedge[from].push_back({ to, edge[to].size(), cap });\n\t\tedge[to].push_back({\
    \ from, edge[from].size() - 1, 0});\n        inf_flow += cap;\n\t}\n\n\tinline\
    \ TypeFlow flow(const size_t start,const size_t goal) {\n\t\tTypeFlow max_flow\
    \ = 0;\n\t\twhile (1) {\n\t\t\tbfs(start);\n\t\t\tif (level[goal] < 0) return\
    \ max_flow;\n\t\t\tfor (int i = 0; i < iter.size(); ++i) iter[i] = 0;\n\t\t\t\
    TypeFlow flow;\n\t\t\twhile ((flow = dfs(start, goal, inf_flow))>0) max_flow +=\
    \ flow;\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/40-graph/DinicMaxFlow.cpp
  requiredBy: []
  timestamp: '2023-07-18 04:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/DinicMaxFlow-1.test.cpp
  - test/graph/DinicMaxFlow-2.test.cpp
documentation_of: lib/40-graph/DinicMaxFlow.cpp
layout: document
redirect_from:
- /library/lib/40-graph/DinicMaxFlow.cpp
- /library/lib/40-graph/DinicMaxFlow.cpp.html
title: "DinicMaxFlow - Dinic\u30D5\u30ED\u30FC"
---
### DinicMaxFlow
- 最大流