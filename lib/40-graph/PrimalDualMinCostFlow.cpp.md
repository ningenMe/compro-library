---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/PrimalDualMinCostFlow.test.cpp
    title: test/graph/PrimalDualMinCostFlow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/PrimalDualMinCostFlow.md
    document_title: PrimalDualMinCostFlow
    links: []
  bundledCode: "#line 1 \"lib/40-graph/PrimalDualMinCostFlow.cpp\"\n/*\n * @title\
    \ PrimalDualMinCostFlow\n * @docs md/graph/PrimalDualMinCostFlow.md\n */\ntemplate<class\
    \ TypeFlow, class TypeCost> class PrimalDualMinCostFlow {\n    using Pair = pair<TypeCost,size_t>;\n\
    \    struct Edge {\n        size_t to;\n        size_t rev;\n        TypeFlow\
    \ cap;\n        TypeCost cost; \n    };\n    vector<vector<Edge>> edge;\n    const\
    \ size_t N;\n    const TypeCost inf_cost;\n    vector<TypeCost> min_cost;\n  \
    \  vector<TypeCost> potential;\n    vector<size_t> prev_vertex,prev_edge;\npublic:\n\
    \    PrimalDualMinCostFlow(const size_t N, const TypeCost inf_cost) \n       \
    \ : N(N), edge(N), min_cost(N), potential(N), prev_vertex(N), prev_edge(N), inf_cost(inf_cost)\
    \ {}\n    // cost\u306F\u5358\u4F4D\u6D41\u91CF\u3042\u305F\u308A\u306E\u30B3\u30B9\
    \u30C8\n    inline void make_edge(const size_t from, const size_t to, const TypeFlow\
    \ cap, const TypeCost cost) {\n        edge[from].push_back({ to, edge[to].size(),\
    \ cap, cost });\n        edge[to].push_back({ from, edge[from].size() - 1, 0,\
    \ -cost });\n    }\n    pair<TypeFlow,TypeCost> min_cost_flow(const size_t s,\
    \ const size_t g, const TypeFlow max_flow) {\n        assert(0 <= s && s < N &&\
    \ 0 <= g && g < N && s != g);\n        priority_queue<Pair,vector<Pair>,greater<Pair>>\
    \ pq;\n        potential.assign(N, 0);\n        prev_edge.assign(N, N);\n    \
    \    prev_vertex.assign(N, N);\n\n        TypeCost sum_cost=0;\n        TypeFlow\
    \ sum_flow = 0;\n        while(sum_flow < max_flow) {\n            min_cost.assign(N,\
    \ inf_cost);\n            {\n                pq.emplace(0,s);\n              \
    \  min_cost[s]=0;\n            }\n            while(pq.size()) {\n           \
    \     auto [from_cost, from] = pq.top(); pq.pop();\n                if(min_cost[from]\
    \ < from_cost) continue;\n\n                for(int i=0; i < edge[from].size();\
    \ ++i) {\n                    auto [to, rev, cap, cost] = edge[from][i];\n   \
    \                 TypeCost to_cost = from_cost + cost + (potential[from] - potential[to]);\n\
    \                    if(cap > 0 && min_cost[to] > to_cost) {\n               \
    \         pq.emplace(to_cost, to);\n                        prev_vertex[to] =\
    \ from;\n                        prev_edge[to] = i;\n                        min_cost[to]\
    \ = to_cost;\n                    }\n                }\n            }\n      \
    \      if(min_cost[g]==inf_cost) break;\n            for(size_t i=0; i<N; ++i)\
    \ potential[i] += min_cost[i];\n\n            TypeFlow diff_flow = max_flow -\
    \ sum_flow;\n            for(size_t i=g; i!=s; i = prev_vertex[i]) {\n       \
    \         diff_flow = min(diff_flow, edge[prev_vertex[i]][prev_edge[i]].cap);\n\
    \            }\n            sum_flow += diff_flow;\n            sum_cost += diff_flow\
    \ * potential[g];\n            for(size_t i=g; i!=s; i = prev_vertex[i]) {\n \
    \               auto& [_to,rev,cap,_cost] = edge[prev_vertex[i]][prev_edge[i]];\n\
    \                auto& [_r_to,_r_rev,r_cap,_r_cost] = edge[i][rev];\n\n      \
    \          cap -= diff_flow;\n                r_cap += diff_flow;\n          \
    \  }\n        }\n        return {sum_flow, sum_cost};\n    }\n\n};\n"
  code: "/*\n * @title PrimalDualMinCostFlow\n * @docs md/graph/PrimalDualMinCostFlow.md\n\
    \ */\ntemplate<class TypeFlow, class TypeCost> class PrimalDualMinCostFlow {\n\
    \    using Pair = pair<TypeCost,size_t>;\n    struct Edge {\n        size_t to;\n\
    \        size_t rev;\n        TypeFlow cap;\n        TypeCost cost; \n    };\n\
    \    vector<vector<Edge>> edge;\n    const size_t N;\n    const TypeCost inf_cost;\n\
    \    vector<TypeCost> min_cost;\n    vector<TypeCost> potential;\n    vector<size_t>\
    \ prev_vertex,prev_edge;\npublic:\n    PrimalDualMinCostFlow(const size_t N, const\
    \ TypeCost inf_cost) \n        : N(N), edge(N), min_cost(N), potential(N), prev_vertex(N),\
    \ prev_edge(N), inf_cost(inf_cost) {}\n    // cost\u306F\u5358\u4F4D\u6D41\u91CF\
    \u3042\u305F\u308A\u306E\u30B3\u30B9\u30C8\n    inline void make_edge(const size_t\
    \ from, const size_t to, const TypeFlow cap, const TypeCost cost) {\n        edge[from].push_back({\
    \ to, edge[to].size(), cap, cost });\n        edge[to].push_back({ from, edge[from].size()\
    \ - 1, 0, -cost });\n    }\n    pair<TypeFlow,TypeCost> min_cost_flow(const size_t\
    \ s, const size_t g, const TypeFlow max_flow) {\n        assert(0 <= s && s <\
    \ N && 0 <= g && g < N && s != g);\n        priority_queue<Pair,vector<Pair>,greater<Pair>>\
    \ pq;\n        potential.assign(N, 0);\n        prev_edge.assign(N, N);\n    \
    \    prev_vertex.assign(N, N);\n\n        TypeCost sum_cost=0;\n        TypeFlow\
    \ sum_flow = 0;\n        while(sum_flow < max_flow) {\n            min_cost.assign(N,\
    \ inf_cost);\n            {\n                pq.emplace(0,s);\n              \
    \  min_cost[s]=0;\n            }\n            while(pq.size()) {\n           \
    \     auto [from_cost, from] = pq.top(); pq.pop();\n                if(min_cost[from]\
    \ < from_cost) continue;\n\n                for(int i=0; i < edge[from].size();\
    \ ++i) {\n                    auto [to, rev, cap, cost] = edge[from][i];\n   \
    \                 TypeCost to_cost = from_cost + cost + (potential[from] - potential[to]);\n\
    \                    if(cap > 0 && min_cost[to] > to_cost) {\n               \
    \         pq.emplace(to_cost, to);\n                        prev_vertex[to] =\
    \ from;\n                        prev_edge[to] = i;\n                        min_cost[to]\
    \ = to_cost;\n                    }\n                }\n            }\n      \
    \      if(min_cost[g]==inf_cost) break;\n            for(size_t i=0; i<N; ++i)\
    \ potential[i] += min_cost[i];\n\n            TypeFlow diff_flow = max_flow -\
    \ sum_flow;\n            for(size_t i=g; i!=s; i = prev_vertex[i]) {\n       \
    \         diff_flow = min(diff_flow, edge[prev_vertex[i]][prev_edge[i]].cap);\n\
    \            }\n            sum_flow += diff_flow;\n            sum_cost += diff_flow\
    \ * potential[g];\n            for(size_t i=g; i!=s; i = prev_vertex[i]) {\n \
    \               auto& [_to,rev,cap,_cost] = edge[prev_vertex[i]][prev_edge[i]];\n\
    \                auto& [_r_to,_r_rev,r_cap,_r_cost] = edge[i][rev];\n\n      \
    \          cap -= diff_flow;\n                r_cap += diff_flow;\n          \
    \  }\n        }\n        return {sum_flow, sum_cost};\n    }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/40-graph/PrimalDualMinCostFlow.cpp
  requiredBy: []
  timestamp: '2023-07-18 02:34:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/PrimalDualMinCostFlow.test.cpp
documentation_of: lib/40-graph/PrimalDualMinCostFlow.cpp
layout: document
redirect_from:
- /library/lib/40-graph/PrimalDualMinCostFlow.cpp
- /library/lib/40-graph/PrimalDualMinCostFlow.cpp.html
title: PrimalDualMinCostFlow
---
