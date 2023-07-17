---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/40-graph/PrimalDualMinCostFlow.cpp
    title: PrimalDualMinCostFlow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/graph/PrimalDualMinCostFlow.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <queue>\n#include <cassert>\nusing namespace\
    \ std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
    \ */\nclass FastIO{\nprivate:\n    inline static constexpr int ch_0='0';\n   \
    \ inline static constexpr int ch_9='9';\n    inline static constexpr int ch_n='-';\n\
    \    inline static constexpr int ch_s=' ';\n    inline static constexpr int ch_l='\\\
    n';\n    inline static void endline_skip(char& ch) {\n        while(ch==ch_l)\
    \ ch=getchar();\n    }\n    template<typename T> inline static void read_integer(T\
    \ &x) {\n        int neg=0; char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        if(ch==ch_n) neg=1,ch=getchar();\n        for(;(ch_0 <= ch && ch <= ch_9);\
    \ ch = getchar()) x = x*10 + (ch-ch_0);\n        if(neg) x*=-1;\n    }\n    template<typename\
    \ T> inline static void read_unsigned_integer(T &x) {\n        char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        for(;(ch_0 <= ch &&\
    \ ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        endline_skip(ch);\n        for(;(ch != ch_s && ch!=ch_l); ch = getchar())\
    \ x.push_back(ch);\n    }\n    inline static char ar[40];\n    inline static char\
    \ *ch_ar;\n    template<typename T> inline static void write_integer(T x) {\n\
    \        ch_ar=ar;\n        if(x< 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n\
    \        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n\
    \    }\npublic:\n    inline static void read(int &x) {read_integer<int>(x);}\n\
    \    inline static void read(long long &x) {read_integer<long long>(x);}\n   \
    \ inline static void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n\
    \    inline static void read(unsigned long long &x) {read_unsigned_integer<unsigned\
    \ long long>(x);}\n    inline static void read(string &x) {read_string(x);}\n\
    \    inline static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n \
    \   inline static void write(__int128_t x) {write_integer<__int128_t>(x);}\n \
    \   inline static void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n#line 1 \"lib/40-graph/PrimalDualMinCostFlow.cpp\"\
    \n/*\n * @title PrimalDualMinCostFlow\n * @docs md/graph/PrimalDualMinCostFlow.md\n\
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
    \  }\n        }\n        return {sum_flow, sum_cost};\n    }\n\n};\n#line 10 \"\
    test/graph/PrimalDualMinCostFlow.test.cpp\"\n\nint main() {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,M,F;\n    read(N),read(M),read(F);\n    PrimalDualMinCostFlow<int,int>\
    \ pdmcf(N, 123456789);\n    for(int i=0;i<M;++i) {\n        int u,v,c,d;\n   \
    \     read(u),read(v),read(c),read(d);\n        pdmcf.make_edge(u,v,c,d);\n  \
    \  }\n    auto [flow,cost] = pdmcf.min_cost_flow(0,N-1,F);\n    if(flow < F) cost\
    \ = -1;\n    cout << cost << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <queue>\n#include <cassert>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/40-graph/PrimalDualMinCostFlow.cpp\"\
    \n\nint main() {\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,M,F;\n\
    \    read(N),read(M),read(F);\n    PrimalDualMinCostFlow<int,int> pdmcf(N, 123456789);\n\
    \    for(int i=0;i<M;++i) {\n        int u,v,c,d;\n        read(u),read(v),read(c),read(d);\n\
    \        pdmcf.make_edge(u,v,c,d);\n    }\n    auto [flow,cost] = pdmcf.min_cost_flow(0,N-1,F);\n\
    \    if(flow < F) cost = -1;\n    cout << cost << endl;\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/40-graph/PrimalDualMinCostFlow.cpp
  isVerificationFile: true
  path: test/graph/PrimalDualMinCostFlow.test.cpp
  requiredBy: []
  timestamp: '2023-07-18 02:34:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/PrimalDualMinCostFlow.test.cpp
layout: document
redirect_from:
- /verify/test/graph/PrimalDualMinCostFlow.test.cpp
- /verify/test/graph/PrimalDualMinCostFlow.test.cpp.html
title: test/graph/PrimalDualMinCostFlow.test.cpp
---
