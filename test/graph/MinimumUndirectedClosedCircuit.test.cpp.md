---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/15-heap/RadixHeap.cpp
    title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
  - icon: ':heavy_check_mark:'
    path: lib/graph/Graph.cpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: lib/graph/MinimumUndirectedClosedCircuit.cpp
    title: "MinimumUndirectedClosedCircuit - \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\
      \u5C0F\u9589\u8DEF\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/13
    links:
    - https://yukicoder.me/problems/no/13
  bundledCode: "#line 1 \"test/graph/MinimumUndirectedClosedCircuit.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/13\"\n\n#include <vector>\n#include\
    \ <iostream>\n#include <algorithm>\n#include <cassert>\n#include <set>\n#include\
    \ <queue>\n#include <map>\n#include <stack>\n#include <array>\n\nusing namespace\
    \ std;\n#line 1 \"lib/graph/Graph.cpp\"\n/*\n * @title Graph\n * @docs md/graph/Graph.md\n\
    \ */\ntemplate<class T> class Graph{\nprivate:\n    const size_t N,H,W;\npublic:\n\
    \    vector<vector<pair<size_t,T>>> edges;\n    Graph(const size_t N):H(-1),W(-1),N(N),\
    \ edges(N) {}\n    Graph(const size_t H, const size_t W):H(H),W(W),N(H*W), edges(H*W)\
    \ {}\n    inline void make_edge(size_t from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n\
    \    }\n    //{from_y,from_x} -> {to_y,to_x} \n    inline void make_edge(pair<size_t,size_t>\
    \ from, pair<size_t,size_t> to, T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \    }\n    inline void make_bidirectional_edge(size_t from, size_t to, T w) {\n\
    \        make_edge(from,to,w);\n        make_edge(to,from,w);\n    }\n    inline\
    \ void make_bidirectional_edge(pair<size_t,size_t> from, pair<size_t,size_t> to,\
    \ T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \        make_edge(to.first*W+to.second,from.first*W+from.second,w);\n    }\n\
    \    inline size_t size(){return N;}\n    inline size_t idx(pair<size_t,size_t>\
    \ yx){return yx.first*W+yx.second;}\n};\n#line 1 \"lib/15-heap/RadixHeap.cpp\"\
    \n/*\n * @title RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs\
    \ md/heap/RadixHeap.md\n */\ntemplate<class T> class RadixHeap{\n    using TypeNode\
    \ = pair<unsigned long long, T>;\n    array<vector<TypeNode>,65> vq;\n    unsigned\
    \ long long size_num;\n    TypeNode last;\n    inline int bit(unsigned long long\
    \ a) {\n        return a ? 64 - __builtin_clzll(a) : 0;\n    }\npublic:\n    RadixHeap(T\
    \ mini) : size_num(0), last(make_pair(0,mini)) {\n        // do nothing\n    }\n\
    \    inline bool empty() {\n        return size_num == 0;\n    }\n    inline size_t\
    \ size(){\n        return size_num;\n    }\n    inline void push(TypeNode x){\n\
    \        ++size_num;\n        vq[bit(x.first^last.first)].push_back(x);\n    }\n\
    \    inline void emplace(unsigned long long key,T val){\n        ++size_num;\n\
    \        vq[bit(key^last.first)].emplace_back(key,val);\n    }\n    inline TypeNode\
    \ pop() {\n        if(vq[0].empty()) {\n            int i = 1;\n            while(vq[i].empty())\
    \ ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n        \
    \    for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n      \
    \      vq[i].clear();\n        }\n        --size_num;\n        auto res = vq[0].back();\n\
    \        vq[0].pop_back();\n        return res;\n    }\n};\n#line 1 \"lib/graph/MinimumUndirectedClosedCircuit.cpp\"\
    \n\n/*\n * @title MinimumUndirectedClosedCircuit - \u7121\u5411\u30B0\u30E9\u30D5\
    \u306E\u6700\u5C0F\u9589\u8DEF\u691C\u51FA\n * @docs md/graph/MinimumUndirectedClosedCircuit.md\n\
    \ */\ntemplate<class T> class MinimumUndirectedClosedCircuit {\n    //T\u306F\u6574\
    \u6570\u578B\u306E\u307F\n    static_assert(std::is_integral<T>::value, \"template\
    \ parameter T must be integral type\");\n    Graph<T> graph;\n    vector<T> dist;\n\
    \    vector<int> parent,label;\n    size_t N;\n    T inf;\n    int last_l,last_r,root;\n\
    private:\n    void solve_impl() {\n        RadixHeap<int> q(0);\n        q.push({0,root});\n\
    \        dist[root] = 0;\n        while (q.size()) {\n            auto top = \
    \ q.pop();\n            size_t curr = top.second;\n            if(top.first >\
    \ dist[curr]) continue;\n            for(auto& edge:graph.edges[curr]){\n    \
    \            size_t next = edge.first;\n                T w  = edge.second;\n\
    \                if(parent[curr] == next) continue;\n                if(dist[next]\
    \ > dist[curr] + w) {\n                    dist[next]   = dist[curr] + w;\n  \
    \                  parent[next] = curr;\n                    label[next]  = (curr==root?next:label[curr]);\n\
    \                    q.push({dist[next],next});\n                }\n         \
    \   }\n        }\n    }\n    T solve_cycle() {\n        T mini = inf;\n      \
    \  last_l=-1,last_r=-1;\n        for(int l=0;l<N;++l) {\n            if(l==root)\
    \ continue;\n            for(auto& edge:graph.edges[l]){\n                int\
    \ r = edge.first;\n                T   w = edge.second;\n                if(mini\
    \ <= dist[l] + dist[r] + w) continue;\n                if( (r==root && l!=label[l])\
    \ || (r!=root && label[l]!=label[r]) ) {\n                    mini = dist[l] +\
    \ dist[r] + w;\n                    last_l = l;\n                    last_r =\
    \ r;\n                }\n            }\n        }\n        return mini;\n    }\n\
    public:\n    MinimumUndirectedClosedCircuit(Graph<T>& graph, T inf)\n        \
    \    : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),label(graph.size()),inf(inf)\
    \ {\n    }\n    //root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u96C6\u5408\
    \u3092\u8FD4\u3059 O(NlogN) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\
    \u96C6\u5408\n    inline T solve(size_t rt){\n        root = rt;\n        //\u521D\
    \u671F\u5316\n        for(int i = 0; i < N; ++i) dist[i] = inf, parent[i] = -1;\n\
    \        solve_impl();\n        T mini=solve_cycle();\n        return mini;\n\
    \    }\n    //\u5FA9\u5143\n    vector<int> restore() {\n        stack<int> s;\n\
    \        queue<int> q;\n        vector<int> res;\n        if(last_l != -1 && last_r\
    \ != -1){\n            for(int curr = last_l; curr != -1; curr = parent[curr])\
    \ s.push(curr);\n            for(int curr = last_r; curr != root; curr = parent[curr])\
    \ q.push(curr);\n            while(s.size()) res.push_back(s.top())  ,s.pop();\n\
    \            while(q.size()) res.push_back(q.front()),q.pop();\n        }\n  \
    \      return res;\n    }\n};\n#line 17 \"test/graph/MinimumUndirectedClosedCircuit.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int W,H; cin\
    \ >> W >> H;\n    Graph<int> g(H,W);\n    vector<int> a(W),b(W);\n    {\n    \
    \    for(int j=0;j  <W;++j) cin >> a[j];\n        for(int j=0;j+1<W;++j) if(a[j]==a[j+1])\
    \ g.make_bidirectional_edge({0,j},{0,j+1},1);        \n    }\n    for(int i=1;i<H;++i)\
    \ {\n        b=a;\n        for(int j=0;j  <W;++j) cin >> a[j];\n        for(int\
    \ j=0;j  <W;++j) if(b[j]==a[j]) g.make_bidirectional_edge({i,j},{i-1,j},1);\n\
    \        for(int j=0;j+1<W;++j) if(a[j]==a[j+1]) g.make_bidirectional_edge({i,j},{i,j+1},1);\n\
    \    }\n    int inf = 12345678;\n    MinimumUndirectedClosedCircuit<int> mucc(g,inf);\n\
    \    int flg = 0;\n    for(int i=0;i<H;++i) for(int j=0;j<W;++j) {\n        int\
    \ sz = mucc.solve(g.idx({i,j}));\n        if(sz < inf) flg = 1;\n    }\n    cout\
    \ << (flg?\"possible\":\"impossible\") << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/13\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <cassert>\n#include <set>\n\
    #include <queue>\n#include <map>\n#include <stack>\n#include <array>\n\nusing\
    \ namespace std;\n#include \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/15-heap/RadixHeap.cpp\"\
    \n#include \"../../lib/graph/MinimumUndirectedClosedCircuit.cpp\"\n\nint main(){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int W,H; cin >> W >> H;\n  \
    \  Graph<int> g(H,W);\n    vector<int> a(W),b(W);\n    {\n        for(int j=0;j\
    \  <W;++j) cin >> a[j];\n        for(int j=0;j+1<W;++j) if(a[j]==a[j+1]) g.make_bidirectional_edge({0,j},{0,j+1},1);\
    \        \n    }\n    for(int i=1;i<H;++i) {\n        b=a;\n        for(int j=0;j\
    \  <W;++j) cin >> a[j];\n        for(int j=0;j  <W;++j) if(b[j]==a[j]) g.make_bidirectional_edge({i,j},{i-1,j},1);\n\
    \        for(int j=0;j+1<W;++j) if(a[j]==a[j+1]) g.make_bidirectional_edge({i,j},{i,j+1},1);\n\
    \    }\n    int inf = 12345678;\n    MinimumUndirectedClosedCircuit<int> mucc(g,inf);\n\
    \    int flg = 0;\n    for(int i=0;i<H;++i) for(int j=0;j<W;++j) {\n        int\
    \ sz = mucc.solve(g.idx({i,j}));\n        if(sz < inf) flg = 1;\n    }\n    cout\
    \ << (flg?\"possible\":\"impossible\") << endl;\n\treturn 0;\n}\n"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/15-heap/RadixHeap.cpp
  - lib/graph/MinimumUndirectedClosedCircuit.cpp
  isVerificationFile: true
  path: test/graph/MinimumUndirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/MinimumUndirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumUndirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumUndirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumUndirectedClosedCircuit.test.cpp
---
