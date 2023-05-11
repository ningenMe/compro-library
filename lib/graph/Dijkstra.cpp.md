---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/graph/Dijkstra.md
    document_title: "Dijkstra - \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9"
    links: []
  bundledCode: "#line 1 \"lib/graph/Dijkstra.cpp\"\n/*\n * @title Dijkstra - \u591A\
    \u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\n * @docs md/graph/Dijkstra.md\n\
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
    \ }\n};\n"
  code: "/*\n * @title Dijkstra - \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9\n * @docs md/graph/Dijkstra.md\n */\ntemplate<class T> class Dijkstra {\n\
    \    vector<long long> num_list;\n    vector<long long> sum;\n    int N;\n   \
    \ T inf;\n    vector<vector<pair<T,int>>> edge;\n    vector<T> cost;\n    vector<int>\
    \ dp;\n    void resize(const int N) {\n        edge.resize(N);\n        cost.resize(N);\n\
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
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-09-21 09:57:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/lib/graph/Dijkstra.cpp
- /library/lib/graph/Dijkstra.cpp.html
title: "Dijkstra - \u591A\u6B21\u5143\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9"
---
