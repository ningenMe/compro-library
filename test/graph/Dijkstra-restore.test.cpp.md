---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Dijkstra.cpp
    title: "Dijkstra - \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
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
    \ */\ntemplate<class T> class Dijkstra {\n    vector<long long> num_list;\n  \
    \  vector<long long> sum;\n    int N;\n    T inf;\n    vector<vector<pair<T,int>>>\
    \ edge;\n    vector<T> cost;\n    vector<int> dp;\n    void resize(const int N)\
    \ {\n        edge.resize(N);\n        cost.resize(N);\n        dp.resize(N);\n\
    \    }\npublic:\n    Dijkstra(int N,T inf):inf(inf),num_list(1,N),sum(1,1),N(N){\n\
    \        resize(N);\n    }\n    Dijkstra(initializer_list<long long> size_list,T\
    \ inf):num_list(size_list),inf(inf),N(1){\n        for(long long& e:num_list)\
    \ N *= e;\n        sum.resize(num_list.size(),1);\n        for(int i = 0; i <\
    \ num_list.size(); ++i) {\n            for(int j = i + 1; j < num_list.size();\
    \ ++j) {\n                sum[i] *= num_list[j];\n            }\n        }\n \
    \       resize(N);\n    }\n    void make_edge(int from, int to, T w) {\n     \
    \   if(from < 0 || N <= from || to < 0 || N <= to) return;\n        edge[from].push_back({\
    \ w,to });\n    }\n    void make_edge(initializer_list<long long> from_list, initializer_list<long\
    \ long> to_list, T w) {\n        int from = 0, to = 0;\n        auto from_itr\
    \ = from_list.begin(),to_itr = to_list.begin();\n        for(int i = 0; i < num_list.size();\
    \ ++i) {\n            if(*from_itr < 0 || num_list[i] <= *from_itr || *to_itr\
    \ < 0 || num_list[i] <= *to_itr) return;\n            from += (*from_itr)*sum[i];\n\
    \            to   += (*to_itr)*sum[i];\n            from_itr++;\n            to_itr++;\n\
    \        }\n        edge[from].push_back({ w,to });\n    }\n    void solve(initializer_list<long\
    \ long> start_list) {\n        int start = 0;\n        auto start_itr = start_list.begin();\n\
    \        for(int i = 0; i < num_list.size(); ++i) {\n            start += (*start_itr)*sum[i];\n\
    \            start_itr++;\n        }\n        solve(start);\n    }\n    void solve(int\
    \ start) {\n        for(int i = 0; i < N; ++i) cost[i] = inf, dp[i] = -1;\n  \
    \      priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ pq;\n        cost[start] = 0;\n        pq.push({ 0,start });\n        while\
    \ (!pq.empty()) {\n            auto [v,from] = pq.top();\n            pq.pop();\n\
    \            if(cost[from] < v) continue;\n            for (auto [u,to] : edge[from])\
    \ {\n                T w = v + u;\n                if (w < cost[to]) {\n     \
    \               cost[to] = w;\n                    dp[to] = from;\n          \
    \          pq.push({ w,to });\n                }\n            }\n        }\n \
    \       return;\n    }\n    T get(int idx){\n        return cost[idx];\n    }\n\
    \    T get(initializer_list<long long> idx_list){\n        int idx = 0;\n    \
    \    auto idx_itr = idx_list.begin();\n        for(int i = 0; i < num_list.size();\
    \ ++i) {\n            idx += (*idx_itr)*sum[i];\n            idx_itr++;\n    \
    \    }\n        return get(idx);\n    }\n    //vertex [start->node1->node2->...->idx]\n\
    \    vector<int> restore(int idx) {\n        vector<int> res = {idx};\n      \
    \  while(dp[idx] != -1) {\n            idx = dp[idx];\n            res.push_back(idx);\n\
    \        }\n        reverse(res.begin(),res.end());\n        return res;\n   \
    \ }\n};\n#line 9 \"test/graph/Dijkstra-restore.test.cpp\"\n\nint main() {\n  \
    \  cin.tie(0);ios::sync_with_stdio(false);\n\tint N,M,s,t;\n\tcin >> N >> M >>\
    \ s >> t;\n\tlong long inf = 1e15;\n\tDijkstra<long long> dijk(N,inf);\n\twhile(M--)\
    \ {\n\t\tint u,v,w; cin >> u >> v >> w;\n\t\tdijk.make_edge(u,v,w);\n\t}\n\tdijk.solve(s);\n\
    \tlong long cost = dijk.get(t);\n\tif(cost == inf) {\n\t\tcout << -1 << endl;\n\
    \t\treturn 0;\n\t}\n\tauto v = dijk.restore(t);\n\tcout << cost << \" \" << (int)v.size()-1\
    \ << endl;\n\tfor(int i = 0; i+1 < v.size(); ++i) {\n\t\tcout << v[i] << \" \"\
    \ << v[i+1] << endl;\n\t}\n    return 0;\n}\n"
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
  timestamp: '2023-05-12 02:35:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Dijkstra-restore.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Dijkstra-restore.test.cpp
- /verify/test/graph/Dijkstra-restore.test.cpp.html
title: test/graph/Dijkstra-restore.test.cpp
---