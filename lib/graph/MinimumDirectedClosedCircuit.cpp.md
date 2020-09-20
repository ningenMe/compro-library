---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/graph/MinimumDirectedClosedCircuit.md
    document_title: MinimumDirectedClosedCircuit
    links: []
  bundledCode: "#line 1 \"lib/graph/MinimumDirectedClosedCircuit.cpp\"\n/*\n * @title\
    \ MinimumDirectedClosedCircuit\n * @docs md/graph/MinimumDirectedClosedCircuit.md\n\
    \ */\nclass MinimumDirectedClosedCircuit {\n\tvector<vector<int>> edge,redge;\
    \  \n\tvector<int> dist;\n\tsize_t N;\npublic:\n\tMinimumDirectedClosedCircuit(size_t\
    \ N) : N(N),edge(N),redge(N),dist(N) {\n\t\t//do nothing\n\t}\n\tinline void make_edge(int\
    \ from,int to){\n\t\tedge[from].push_back(to);\n\t\tredge[to].push_back(from);\n\
    \t}\n\t//root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u96C6\u5408\u3092\
    \u8FD4\u3059 O(N) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\u96C6\
    \u5408\n\tinline vector<int> solve(int root,int inf = 123456789){\n\t\tint mini\
    \ = inf, last = -1;\n\t\tfor(int i = 0; i < N; ++i) dist[i] = -1;\n\t\tqueue<int>\
    \ q;\n\t\tq.push(root);\n\t\tdist[root] = 0;\n\t\twhile (q.size()) {\n\t\t\tint\
    \ curr = q.front();\n\t\t\tq.pop();\n\t\t\tfor(int next:edge[curr]){\n\t\t\t\t\
    if(next == root && mini > dist[curr]+1) mini = dist[curr]+1,last = curr;\n\t\t\
    \t\tif(dist[next]==-1) {\n\t\t\t\t\tdist[next] = dist[curr] + 1;\n\t\t\t\t\tq.push(next);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> res;\n\t\tif(last != -1){\n\t\t\tres.push_back(last);\n\
    \t\t\tint curr = last;\n\t\t\twhile(curr != root){\n\t\t\t\tfor(int next:redge[curr]){\n\
    \t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\t\t\t\tres.push_back(next);\n\t\
    \t\t\t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\treverse(res.begin(),res.end());\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/*\n * @title MinimumDirectedClosedCircuit\n * @docs md/graph/MinimumDirectedClosedCircuit.md\n\
    \ */\nclass MinimumDirectedClosedCircuit {\n\tvector<vector<int>> edge,redge;\
    \  \n\tvector<int> dist;\n\tsize_t N;\npublic:\n\tMinimumDirectedClosedCircuit(size_t\
    \ N) : N(N),edge(N),redge(N),dist(N) {\n\t\t//do nothing\n\t}\n\tinline void make_edge(int\
    \ from,int to){\n\t\tedge[from].push_back(to);\n\t\tredge[to].push_back(from);\n\
    \t}\n\t//root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u96C6\u5408\u3092\
    \u8FD4\u3059 O(N) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\u96C6\
    \u5408\n\tinline vector<int> solve(int root,int inf = 123456789){\n\t\tint mini\
    \ = inf, last = -1;\n\t\tfor(int i = 0; i < N; ++i) dist[i] = -1;\n\t\tqueue<int>\
    \ q;\n\t\tq.push(root);\n\t\tdist[root] = 0;\n\t\twhile (q.size()) {\n\t\t\tint\
    \ curr = q.front();\n\t\t\tq.pop();\n\t\t\tfor(int next:edge[curr]){\n\t\t\t\t\
    if(next == root && mini > dist[curr]+1) mini = dist[curr]+1,last = curr;\n\t\t\
    \t\tif(dist[next]==-1) {\n\t\t\t\t\tdist[next] = dist[curr] + 1;\n\t\t\t\t\tq.push(next);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> res;\n\t\tif(last != -1){\n\t\t\tres.push_back(last);\n\
    \t\t\tint curr = last;\n\t\t\twhile(curr != root){\n\t\t\t\tfor(int next:redge[curr]){\n\
    \t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\t\t\t\tres.push_back(next);\n\t\
    \t\t\t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\treverse(res.begin(),res.end());\n\t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/MinimumDirectedClosedCircuit.cpp
  requiredBy: []
  timestamp: '2020-07-14 23:48:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
documentation_of: lib/graph/MinimumDirectedClosedCircuit.cpp
layout: document
redirect_from:
- /library/lib/graph/MinimumDirectedClosedCircuit.cpp
- /library/lib/graph/MinimumDirectedClosedCircuit.cpp.html
title: MinimumDirectedClosedCircuit
---
