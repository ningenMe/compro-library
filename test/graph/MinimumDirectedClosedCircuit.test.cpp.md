---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Graph.cpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: lib/graph/MinimumDirectedClosedCircuit.cpp
    title: "MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6700\
      \u5C0F\u9589\u8DEF\u691C\u51FA"
  - icon: ':heavy_check_mark:'
    path: lib/heap/RadixHeap.cpp
    title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
  bundledCode: "#line 1 \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <queue>\n#include <map>\n#include <array>\n\nusing namespace\
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
    \ yx){return yx.first*W+yx.second;}\n};\n#line 1 \"lib/heap/RadixHeap.cpp\"\n\
    /*\n * @title RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs md/heap/RadixHeap.md\n\
    \ */\ntemplate<class T> class RadixHeap{\n    using TypeNode = pair<unsigned long\
    \ long, T>;\n    array<vector<TypeNode>,65> vq;\n    unsigned long long size_num;\n\
    \    TypeNode last;\n    inline int bit(unsigned long long a) {\n        return\
    \ a ? 64 - __builtin_clzll(a) : 0;\n    }\npublic:\n    RadixHeap(T mini) : size_num(0),\
    \ last(make_pair(0,mini)) {\n        // do nothing\n    }\n    inline bool empty()\
    \ {\n        return size_num == 0;\n    }\n    inline size_t size(){\n       \
    \ return size_num;\n    }\n    inline void push(TypeNode x){\n        ++size_num;\n\
    \        vq[bit(x.first^last.first)].push_back(x);\n    }\n    inline void emplace(unsigned\
    \ long long key,T val){\n        ++size_num;\n        vq[bit(key^last.first)].emplace_back(key,val);\n\
    \    }\n    inline TypeNode pop() {\n        if(vq[0].empty()) {\n           \
    \ int i = 1;\n            while(vq[i].empty()) ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n\
    \            for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n\
    \            vq[i].clear();\n        }\n        --size_num;\n        auto res\
    \ = vq[0].back();\n        vq[0].pop_back();\n        return res;\n    }\n};\n\
    #line 1 \"lib/graph/MinimumDirectedClosedCircuit.cpp\"\n/*\n * @title MinimumDirectedClosedCircuit\
    \ - \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u9589\u8DEF\u691C\u51FA\n\
    \ * @docs md/graph/MinimumDirectedClosedCircuit.md\n */\ntemplate<class T> class\
    \ MinimumDirectedClosedCircuit {\n    //T\u306F\u6574\u6570\u578B\u306E\u307F\n\
    \    static_assert(std::is_integral<T>::value, \"template parameter T must be\
    \ integral type\");\n    Graph<T>& graph;\n    vector<T> dist;\n    vector<int>\
    \ parent;\n    size_t N;\n    T inf;\n    int last,root;\nprivate:\n\n    T solve_impl()\
    \ {\n        T mini = inf;\n        last = -1;\n        RadixHeap<int> q(0);\n\
    \        q.push({0,root});\n        dist[root] = 0;\n        while (q.size())\
    \ {\n            auto top =  q.pop();\n            size_t curr = top.second;\n\
    \            if(top.first > dist[curr]) continue;\n            for(auto& edge:graph.edges[curr]){\n\
    \                size_t next = edge.first;\n                T w  = edge.second;\n\
    \                if(dist[next] > dist[curr]+w) {\n                    dist[next]\
    \   = dist[curr] + w;\n                    parent[next] = curr;\n            \
    \        q.push({dist[next],next});\n                }\n                //\u6839\
    \u306B\u8FD4\u3063\u3066\u6765\u3066\u308B\u306A\u3089\u9589\u8DEF\u5019\u88DC\
    \n                if(next == root && mini > dist[curr]+w) {\n                \
    \    mini = dist[curr]+w;\n                    last = curr;\n                }\n\
    \            }\n        }\n        return mini;\n    }\npublic:\n    MinimumDirectedClosedCircuit(Graph<T>&\
    \ graph, T inf)\n            : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),inf(inf)\
    \ {\n    }\n    //root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\u306E\u96C6\u5408\
    \u3092\u8FD4\u3059 O(NlogN) \u9589\u8DEF\u304C\u306A\u3044\u3068\u304D\u306F\u7A7A\
    \u96C6\u5408\n    inline T solve(size_t rt){\n        root = rt;\n        //\u521D\
    \u671F\u5316\n        for(int i = 0; i < N; ++i) dist[i] = inf, parent[i] = -1;\n\
    \        //\u6700\u5C0F\u9589\u8DEF\u306E\u5927\u304D\u3055\u3092\u6C7A\u3081\u308B\
    \n        T mini = solve_impl();\n        return mini;\n    }\n    vector<int>\
    \ restore() {\n        vector<int> res;\n        if(last == -1) return res;\n\
    \        int curr = last;\n        res.push_back(curr);\n        while(curr !=\
    \ root) res.push_back(curr = parent[curr]);\n        reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n};\n#line 16 \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\
    \n\nint main(){\n    int N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int\
    \ i = 0; i < M; ++i){\n        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n\
    \    }\n    MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans\
    \ = 0;\n    int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        mdcc.solve(i);\n\
    \        auto tmp = mdcc.restore();\n        if(!tmp.empty()) ans = 1;\n    }\n\
    \    cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <queue>\n#include <map>\n#include <array>\n\nusing namespace\
    \ std;\n#include \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/heap/RadixHeap.cpp\"\
    \n#include \"../../lib/graph/MinimumDirectedClosedCircuit.cpp\"\n\nint main(){\n\
    \    int N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int i = 0; i <\
    \ M; ++i){\n        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n\
    \    }\n    MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans\
    \ = 0;\n    int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        mdcc.solve(i);\n\
    \        auto tmp = mdcc.restore();\n        if(!tmp.empty()) ans = 1;\n    }\n\
    \    cout << ans << endl;\n\treturn 0;\n}\n"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/heap/RadixHeap.cpp
  - lib/graph/MinimumDirectedClosedCircuit.cpp
  isVerificationFile: true
  path: test/graph/MinimumDirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 02:16:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/MinimumDirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumDirectedClosedCircuit.test.cpp
---
