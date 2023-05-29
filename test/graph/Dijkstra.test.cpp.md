---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/70-geometory/Distance.cpp
    title: "Distance - \u8DDD\u96E2"
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
    ERROR: '0.0001'
    PROBLEM: https://yukicoder.me/problems/no/1065
    links:
    - https://yukicoder.me/problems/no/1065
  bundledCode: "#line 1 \"test/graph/Dijkstra.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\
    \n#define ERROR 0.0001\n#include <vector>\n#include <iostream>\n#include <queue>\n\
    #include <cmath>\n#include <algorithm>\nusing namespace std;\n#line 1 \"lib/graph/Dijkstra.cpp\"\
    \n/*\n * @title Dijkstra - \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \n * @docs md/graph/Dijkstra.md\n */\ntemplate<class T> class Dijkstra {\n   \
    \ vector<long long> num_list;\n    vector<long long> sum;\n    int N;\n    T inf;\n\
    \    vector<vector<pair<T,int>>> edge;\n    vector<T> cost;\n    vector<int> dp;\n\
    \    void resize(const int N) {\n        edge.resize(N);\n        cost.resize(N);\n\
    \        dp.resize(N);\n    }\npublic:\n    Dijkstra(int N,T inf):inf(inf),num_list(1,N),sum(1,1),N(N){\n\
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
    \ }\n};\n#line 1 \"lib/70-geometory/Distance.cpp\"\n/*\n * @title Distance - \u8DDD\
    \u96E2\n * @docs md/geometory/Distance.md\n */\ntemplate<class T> class Distance{\n\
    public:\n    //Euclidean distance\n    inline static constexpr T euclid(const\
    \ T& x1, const T& y1, const T& x2, const T& y2) {\n        return sqrt((x1 - x2)*(x1\
    \ - x2) + (y1 - y2)*(y1 - y2));\n    }\n    //Chebyshev distance\n    inline static\
    \ constexpr T chebyshev(T x1, T y1, T x2, T y2) {\n        return max(abs(x1 -\
    \ x2),abs(y1 - y2));\n    }\n    //Manhattan distance\n    inline static constexpr\
    \ T manhattan(T x1, T y1, T x2, T y2) {\n        return abs(x1 - x2)+abs(y1 -\
    \ y2);\n    }\n    inline static constexpr T between_point_and_line(const T& x,const\
    \ T& y,const T& x1,const T& y1,const T& x2,const T& y2){\n        return abs((y2\
    \ - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2 - y1)*(y2 - y1)+(x1 - x2)*(x1\
    \ - x2));\n    }\n};\n#line 11 \"test/graph/Dijkstra.test.cpp\"\n\nint main()\
    \ {\n    int N,M; cin >> N >> M;\n    Dijkstra<double> dij(N,1e15);\n    int s,t;\
    \ cin >> s >> t; s--,t--;\n    vector<double> p(N),q(N); \n    for(int i = 0;\
    \ i < N; ++i) {\n        cin >> p[i] >> q[i];\n    }\n    for(int i = 0; i < M;\
    \ ++i) {\n        int u,v; cin >> u >> v;\n        u--,v--;\n        double cost\
    \ = Distance<double>::euclid(p[u],q[u],p[v],q[v]);\n        dij.make_edge(u,v,cost);\n\
    \        dij.make_edge(v,u,cost);\n    }\n    dij.solve(s);\n    printf(\"%.10f\\\
    n\",dij.get(t));    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1065\"\n#define ERROR\
    \ 0.0001\n#include <vector>\n#include <iostream>\n#include <queue>\n#include <cmath>\n\
    #include <algorithm>\nusing namespace std;\n#include \"../../lib/graph/Dijkstra.cpp\"\
    \n#include \"../../lib/70-geometory/Distance.cpp\"\n\nint main() {\n    int N,M;\
    \ cin >> N >> M;\n    Dijkstra<double> dij(N,1e15);\n    int s,t; cin >> s >>\
    \ t; s--,t--;\n    vector<double> p(N),q(N); \n    for(int i = 0; i < N; ++i)\
    \ {\n        cin >> p[i] >> q[i];\n    }\n    for(int i = 0; i < M; ++i) {\n \
    \       int u,v; cin >> u >> v;\n        u--,v--;\n        double cost = Distance<double>::euclid(p[u],q[u],p[v],q[v]);\n\
    \        dij.make_edge(u,v,cost);\n        dij.make_edge(v,u,cost);\n    }\n \
    \   dij.solve(s);\n    printf(\"%.10f\\n\",dij.get(t));    \n    return 0;\n}"
  dependsOn:
  - lib/graph/Dijkstra.cpp
  - lib/70-geometory/Distance.cpp
  isVerificationFile: true
  path: test/graph/Dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Dijkstra.test.cpp
- /verify/test/graph/Dijkstra.test.cpp.html
title: test/graph/Dijkstra.test.cpp
---
