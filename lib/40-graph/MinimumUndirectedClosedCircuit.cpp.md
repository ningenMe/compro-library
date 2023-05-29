---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/MinimumUndirectedClosedCircuit.test.cpp
    title: test/graph/MinimumUndirectedClosedCircuit.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/MinimumUndirectedClosedCircuit.md
    document_title: "MinimumUndirectedClosedCircuit - \u7121\u5411\u30B0\u30E9\u30D5\
      \u306E\u6700\u5C0F\u9589\u8DEF\u691C\u51FA"
    links: []
  bundledCode: "#line 1 \"lib/40-graph/MinimumUndirectedClosedCircuit.cpp\"\n\n/*\n\
    \ * @title MinimumUndirectedClosedCircuit - \u7121\u5411\u30B0\u30E9\u30D5\u306E\
    \u6700\u5C0F\u9589\u8DEF\u691C\u51FA\n * @docs md/graph/MinimumUndirectedClosedCircuit.md\n\
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
    \      return res;\n    }\n};\n"
  code: "\n/*\n * @title MinimumUndirectedClosedCircuit - \u7121\u5411\u30B0\u30E9\
    \u30D5\u306E\u6700\u5C0F\u9589\u8DEF\u691C\u51FA\n * @docs md/graph/MinimumUndirectedClosedCircuit.md\n\
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
    \      return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/40-graph/MinimumUndirectedClosedCircuit.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/MinimumUndirectedClosedCircuit.test.cpp
documentation_of: lib/40-graph/MinimumUndirectedClosedCircuit.cpp
layout: document
redirect_from:
- /library/lib/40-graph/MinimumUndirectedClosedCircuit.cpp
- /library/lib/40-graph/MinimumUndirectedClosedCircuit.cpp.html
title: "MinimumUndirectedClosedCircuit - \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\
  \u5C0F\u9589\u8DEF\u691C\u51FA"
---
