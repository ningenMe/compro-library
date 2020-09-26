---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Dijkstra.cpp
    title: "Dijkstra - \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/graph/Dijkstra-restore.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#include <vector>\n#include\
    \ <iostream>\n#include <queue>\n#include <cmath>\n#include <algorithm>\nusing\
    \ namespace std;\n#line 1 \"lib/graph/Dijkstra.cpp\"\n/*\n * @title Dijkstra -\
    \ \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\n * @docs md/graph/Dijkstra.md\n\
    \ */\ntemplate<class T> class Dijkstra {\n\tvector<long long> num_list;\n\tvector<long\
    \ long> sum;\n\tint N;\n\tT inf;\n\tvector<vector<pair<T,int>>> edge;\n\tvector<T>\
    \ cost;\n\tvector<int> dp;\n\tvoid resize(const int N) {\n\t\tedge.resize(N);\n\
    \t\tcost.resize(N);\n\t\tdp.resize(N);\n\t}\npublic:\n\tDijkstra(int N,T inf):inf(inf),num_list(1,N),sum(1,1),N(N){\n\
    \t\tresize(N);\n\t}\n\tDijkstra(initializer_list<long long> size_list,T inf):num_list(size_list),inf(inf),N(1){\n\
    \t\tfor(long long& e:num_list) N *= e;\n\t\tsum.resize(num_list.size(),1);\n\t\
    \tfor(int i = 0; i < num_list.size(); ++i) {\n\t\t\tfor(int j = i + 1; j < num_list.size();\
    \ ++j) {\n\t\t\t\tsum[i] *= num_list[j];\n\t\t\t}\n\t\t}\n\t\tresize(N);\n\t}\n\
    \tvoid make_edge(int from, int to, T w) {\n\t\tif(from < 0 || N <= from || to\
    \ < 0 || N <= to) return;\n\t\tedge[from].push_back({ w,to });\n\t}\n\tvoid make_edge(initializer_list<long\
    \ long> from_list, initializer_list<long long> to_list, T w) {\n\t\tint from =\
    \ 0, to = 0;\n\t\tauto from_itr = from_list.begin(),to_itr = to_list.begin();\n\
    \t\tfor(int i = 0; i < num_list.size(); ++i) {\n\t\t\tif(*from_itr < 0 || num_list[i]\
    \ <= *from_itr || *to_itr < 0 || num_list[i] <= *to_itr) return;\n\t\t\tfrom +=\
    \ (*from_itr)*sum[i];\n\t\t\tto   += (*to_itr)*sum[i];\n\t\t\tfrom_itr++;\n\t\t\
    \tto_itr++;\n\t\t}\n\t\tedge[from].push_back({ w,to });\n\t}\n\tvoid solve(initializer_list<long\
    \ long> start_list) {\n\t\tint start = 0;\n\t\tauto start_itr = start_list.begin();\n\
    \t\tfor(int i = 0; i < num_list.size(); ++i) {\n\t\t\tstart += (*start_itr)*sum[i];\n\
    \t\t\tstart_itr++;\n\t\t}\n\t\tsolve(start);\n\t}\n\tvoid solve(int start) {\n\
    \t\tfor(int i = 0; i < N; ++i) cost[i] = inf, dp[i] = -1;\n\t\tpriority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\t\tcost[start] = 0;\n\
    \t\tpq.push({ 0,start });\n\t\twhile (!pq.empty()) {\n\t\t\tauto [v,from] = pq.top();\n\
    \t\t\tpq.pop();\n\t\t\tif(cost[from] < v) continue;\n\t\t\tfor (auto [u,to] :\
    \ edge[from]) {\n\t\t\t\tT w = v + u;\n\t\t\t\tif (w < cost[to]) {\n\t\t\t\t\t\
    cost[to] = w;\n\t\t\t\t\tdp[to] = from;\n\t\t\t\t\tpq.push({ w,to });\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\treturn;\n\t}\n\tT get(int idx){\n\t\treturn cost[idx];\n\
    \t}\n\tT get(initializer_list<long long> idx_list){\n\t\tint idx = 0;\n\t\tauto\
    \ idx_itr = idx_list.begin();\n\t\tfor(int i = 0; i < num_list.size(); ++i) {\n\
    \t\t\tidx += (*idx_itr)*sum[i];\n\t\t\tidx_itr++;\n\t\t}\n\t\treturn get(idx);\n\
    \t}\n\t//vertex [start->node1->node2->...->idx]\n\tvector<int> restore(int idx)\
    \ {\n\t\tvector<int> res = {idx};\n\t\twhile(dp[idx] != -1) {\n\t\t\tidx = dp[idx];\n\
    \t\t\tres.push_back(idx);\n\t\t}\n\t\treverse(res.begin(),res.end());\n\t\treturn\
    \ res;\n\t}\n};\n#line 9 \"test/graph/Dijkstra-restore.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);ios::sync_with_stdio(false);\n\tint N,M,s,t;\n\tcin >> N >>\
    \ M >> s >> t;\n\tlong long inf = 1e15;\n\tDijkstra<long long> dijk(N,inf);\n\t\
    while(M--) {\n\t\tint u,v,w; cin >> u >> v >> w;\n\t\tdijk.make_edge(u,v,w);\n\
    \t}\n\tdijk.solve(s);\n\tlong long cost = dijk.get(t);\n\tif(cost == inf) {\n\t\
    \tcout << -1 << endl;\n\t\treturn 0;\n\t}\n\tauto v = dijk.restore(t);\n\tcout\
    \ << cost << \" \" << (int)v.size()-1 << endl;\n\tfor(int i = 0; i+1 < v.size();\
    \ ++i) {\n\t\tcout << v[i] << \" \" << v[i+1] << endl;\n\t}\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <vector>\n#include <iostream>\n#include <queue>\n#include <cmath>\n#include\
    \ <algorithm>\nusing namespace std;\n#include \"../../lib/graph/Dijkstra.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\tint N,M,s,t;\n\
    \tcin >> N >> M >> s >> t;\n\tlong long inf = 1e15;\n\tDijkstra<long long> dijk(N,inf);\n\
    \twhile(M--) {\n\t\tint u,v,w; cin >> u >> v >> w;\n\t\tdijk.make_edge(u,v,w);\n\
    \t}\n\tdijk.solve(s);\n\tlong long cost = dijk.get(t);\n\tif(cost == inf) {\n\t\
    \tcout << -1 << endl;\n\t\treturn 0;\n\t}\n\tauto v = dijk.restore(t);\n\tcout\
    \ << cost << \" \" << (int)v.size()-1 << endl;\n\tfor(int i = 0; i+1 < v.size();\
    \ ++i) {\n\t\tcout << v[i] << \" \" << v[i+1] << endl;\n\t}\n    return 0;\n}"
  dependsOn:
  - lib/graph/Dijkstra.cpp
  isVerificationFile: true
  path: test/graph/Dijkstra-restore.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:13:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Dijkstra-restore.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Dijkstra-restore.test.cpp
- /verify/test/graph/Dijkstra-restore.test.cpp.html
title: test/graph/Dijkstra-restore.test.cpp
---
