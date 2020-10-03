---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"non-verified/MinimumUndirectedClosedCircuit.cpp\"\n\n//\u91CD\
    \u307F\u306A\u3057\u7121\u52B9\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u9589\u8DEF\
    \u3092\u6C42\u3081\u308B\u30AF\u30E9\u30B9\nclass MinimumUndirectedClosedCircuit\
    \ {\n\tvector<vector<int>> edge;\n\tvector<int> dist;\n\tsize_t N;\npublic:\n\t\
    MinimumUndirectedClosedCircuit(size_t N) : N(N),edge(N),dist(N) {\n\t\t//do nothing\n\
    \t}\n\tvoid makeEdge(int from,int to){\n\t\tedge[from].push_back(to);\n\t}\n\t\
    //root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u9577\u3055\u3092\u8FD4\
    \u3059 O(N) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\u96C6\u5408\
    \n\tvector<int> solve(int root,int inf = 123456789){\n\t\tint mini = inf;\n\t\t\
    for(int i = 0; i < N; ++i) dist[i] = -1;\n\t\tqueue<pair<int,int>> q;\n\t\tq.push({root,-1});\n\
    \t\tdist[root] = 0;\n\t\tpair<int,int> last = make_pair(-1,-1);\n\t\twhile (q.size())\
    \ {\n\t\t\tint curr = q.front().first;\n\t\t\tint prev = q.front().second;\n\t\
    \t\tq.pop();\n\t\t\tfor(int next:edge[curr]){\n\t\t\t\tif(next==prev) continue;\n\
    \t\t\t\tif(dist[next]==-1) {\n\t\t\t\t\tdist[next] = dist[curr] + 1;\n\t\t\t\t\
    \tq.push({next,curr});\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\tif(mini > dist[curr]+dist[next]+1){\n\
    \t\t\t\t\t\tmini = dist[curr]+dist[next]+1;\n\t\t\t\t\t\tlast = make_pair(curr,next);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> idxl,idxr,res;\n\t\tif(last\
    \ != make_pair(-1,-1)){\n\t\t\tqueue<int> l;\n\t\t\tstack<int> r;\n\t\t\tint curr;\n\
    \t\t\tcurr = last.first;\n\t\t\twhile(curr != root){\n\t\t\t\tl.push(curr);\n\t\
    \t\t\tfor(int next:edge[curr]){\n\t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\
    \t\t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tcurr = last.second;\n\t\t\twhile(curr != root){\n\t\t\t\tr.push(curr);\n\t\t\
    \t\tfor(int next:edge[curr]){\n\t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\t\
    \t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    while (l.size()) {\n\t\t\t\tres.push_back(l.front());\n\t\t\t\tl.pop();\n\t\t\t\
    }\n\t\t\tres.push_back(root);\t\t\t\n\t\t\twhile (r.size()) {\n\t\t\t\tres.push_back(r.top());\n\
    \t\t\t\tr.pop();\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "\n//\u91CD\u307F\u306A\u3057\u7121\u52B9\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\
    \u9589\u8DEF\u3092\u6C42\u3081\u308B\u30AF\u30E9\u30B9\nclass MinimumUndirectedClosedCircuit\
    \ {\n\tvector<vector<int>> edge;\n\tvector<int> dist;\n\tsize_t N;\npublic:\n\t\
    MinimumUndirectedClosedCircuit(size_t N) : N(N),edge(N),dist(N) {\n\t\t//do nothing\n\
    \t}\n\tvoid makeEdge(int from,int to){\n\t\tedge[from].push_back(to);\n\t}\n\t\
    //root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u9577\u3055\u3092\u8FD4\
    \u3059 O(N) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\u96C6\u5408\
    \n\tvector<int> solve(int root,int inf = 123456789){\n\t\tint mini = inf;\n\t\t\
    for(int i = 0; i < N; ++i) dist[i] = -1;\n\t\tqueue<pair<int,int>> q;\n\t\tq.push({root,-1});\n\
    \t\tdist[root] = 0;\n\t\tpair<int,int> last = make_pair(-1,-1);\n\t\twhile (q.size())\
    \ {\n\t\t\tint curr = q.front().first;\n\t\t\tint prev = q.front().second;\n\t\
    \t\tq.pop();\n\t\t\tfor(int next:edge[curr]){\n\t\t\t\tif(next==prev) continue;\n\
    \t\t\t\tif(dist[next]==-1) {\n\t\t\t\t\tdist[next] = dist[curr] + 1;\n\t\t\t\t\
    \tq.push({next,curr});\n\t\t\t\t}\n\t\t\t\telse{\n\t\t\t\t\tif(mini > dist[curr]+dist[next]+1){\n\
    \t\t\t\t\t\tmini = dist[curr]+dist[next]+1;\n\t\t\t\t\t\tlast = make_pair(curr,next);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tvector<int> idxl,idxr,res;\n\t\tif(last\
    \ != make_pair(-1,-1)){\n\t\t\tqueue<int> l;\n\t\t\tstack<int> r;\n\t\t\tint curr;\n\
    \t\t\tcurr = last.first;\n\t\t\twhile(curr != root){\n\t\t\t\tl.push(curr);\n\t\
    \t\t\tfor(int next:edge[curr]){\n\t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\
    \t\t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tcurr = last.second;\n\t\t\twhile(curr != root){\n\t\t\t\tr.push(curr);\n\t\t\
    \t\tfor(int next:edge[curr]){\n\t\t\t\t\tif(dist[next]+1==dist[curr]) {\n\t\t\t\
    \t\t\tcurr = next;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    while (l.size()) {\n\t\t\t\tres.push_back(l.front());\n\t\t\t\tl.pop();\n\t\t\t\
    }\n\t\t\tres.push_back(root);\t\t\t\n\t\t\twhile (r.size()) {\n\t\t\t\tres.push_back(r.top());\n\
    \t\t\t\tr.pop();\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/MinimumUndirectedClosedCircuit.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/MinimumUndirectedClosedCircuit.cpp
layout: document
redirect_from:
- /library/non-verified/MinimumUndirectedClosedCircuit.cpp
- /library/non-verified/MinimumUndirectedClosedCircuit.cpp.html
title: non-verified/MinimumUndirectedClosedCircuit.cpp
---
