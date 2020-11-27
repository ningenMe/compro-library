---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: md/graph/MinimumDirectedClosedCircuit.md
    document_title: "MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\
      \u306E\u6700\u5C0F\u9589\u8DEF\u691C\u51FA"
    links: []
  bundledCode: "#line 1 \"lib/graph/MinimumDirectedClosedCircuit.cpp\"\n/*\n * @title\
    \ MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\
    \u9589\u8DEF\u691C\u51FA\n * @docs md/graph/MinimumDirectedClosedCircuit.md\n\
    \ */\ntemplate<class T> class MinimumDirectedClosedCircuit {\n    //T\u306F\u6574\
    \u6570\u578B\u306E\u307F\n    static_assert(std::is_integral<T>::value, \"template\
    \ parameter T must be integral type\");\n    Graph<T>& graph;\n    vector<int>\
    \ dist,parent;\n    size_t N;\n    bool is_same_weighted;\n    T inf;\n    int\
    \ last,root;\nprivate:\n    T solve_same_weighted() {\n        T mini = inf;\n\
    \        last = -1;\n        queue<int> q;\n        q.push(root);\n        dist[root]\
    \ = 0;\n        while (q.size()) {\n            size_t curr = q.front(); q.pop();\n\
    \            for(auto& edge:graph.edges[curr]){\n                size_t next =\
    \ edge.first;\n                T w  = edge.second;\n                \n       \
    \         //\u6839\u306B\u8FD4\u3063\u3066\u6765\u3066\u308B\u306A\u3089\u9589\
    \u8DEF\n                if(next == root && mini > dist[curr]+w) {\n          \
    \          mini = dist[curr]+w;\n                    last = curr;\n          \
    \      }\n                //\u305D\u3046\u3058\u3083\u306A\u3044\u306A\u3089\u63A2\
    \u7D22\u6728\u3092\u5E83\u3052\u308B\n                else if(dist[next]==-1)\
    \ {\n                    dist[next]   = dist[curr] + w;\n                    parent[next]\
    \ = curr;\n                    q.push(next);\n                }\n            }\n\
    \        }\n        return mini;\n    }\n    T solve_diff_weighted() {\n     \
    \   T mini = inf;\n        last = -1;\n        RadixHeap<int> q(0);\n        q.push({0,root});\n\
    \        dist[root] = 0;\n        while (q.size()) {\n            auto top = \
    \ q.pop();\n            size_t curr = top.second;\n            for(auto& edge:graph.edges[curr]){\n\
    \                size_t next = edge.first;\n                T w  = edge.second;\n\
    \                \n                //\u6839\u306B\u8FD4\u3063\u3066\u6765\u3066\
    \u308B\u306A\u3089\u9589\u8DEF\n                if(next == root && mini > dist[curr]+w)\
    \ {\n                    mini = dist[curr]+w;\n                    last = curr;\n\
    \                }\n                //\u305D\u3046\u3058\u3083\u306A\u3044\u306A\
    \u3089\u63A2\u7D22\u6728\u3092\u5E83\u3052\u308B\n                else if(dist[next]==-1)\
    \ {\n                    dist[next]   = dist[curr] + w;\n                    parent[next]\
    \ = curr;\n                    q.push({dist[next],next});\n                }\n\
    \            }\n        }\n        return mini;\n    }\npublic:\n    MinimumDirectedClosedCircuit(Graph<T>&\
    \ graph, T inf)\n     : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),inf(inf)\
    \ {\n        assert(!graph.edges.empty());\n        //\u91CD\u307F\u304C\u4E00\
    \u5F8B\u304B\u3069\u3046\u304B\u5224\u5B9A \u9762\u5012\u3060\u304B\u3089\u3053\
    \u3053\u306Flog\u3064\u304D\n        set<T> st;\n        for(int i=0;i<N;++i)\
    \ for(auto& edge:graph.edges[i]) st.insert(edge.second);        \n        is_same_weighted\
    \ = (st.size() == 1);\n    }\n    //root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\
    \u306E\u96C6\u5408\u3092\u8FD4\u3059 O(NlogN) \u9589\u8DEF\u304C\u306A\u3044\u3068\
    \u304D\u306F\u7A7A\u96C6\u5408\n    inline T solve(size_t rt, int restore = 0){\n\
    \        root = rt;\n        //\u521D\u671F\u5316\n        for(int i = 0; i <\
    \ N; ++i) dist[i] = parent[i] = -1;\n        //\u6700\u5C0F\u9589\u8DEF\u306E\u5927\
    \u304D\u3055\u3092\u6C7A\u3081\u308B\n        T mini;\n        if(is_same_weighted)\
    \ mini=solve_same_weighted(); //\u91CD\u307F\u4E00\u5F8B\n        else mini=solve_diff_weighted();\
    \ //\u91CD\u307F\u304C\u30D0\u30E9\u30D0\u30E9\n        return mini;\n    }\n\
    \    vector<int> restore() {\n        vector<int> res;\n        if(last == -1)\
    \ return res;\n        res.push_back(last);\n        int curr = last;\n      \
    \  while(curr != root) res.push_back(curr = parent[curr]);\n        reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n};\n"
  code: "/*\n * @title MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\
    \u306E\u6700\u5C0F\u9589\u8DEF\u691C\u51FA\n * @docs md/graph/MinimumDirectedClosedCircuit.md\n\
    \ */\ntemplate<class T> class MinimumDirectedClosedCircuit {\n    //T\u306F\u6574\
    \u6570\u578B\u306E\u307F\n    static_assert(std::is_integral<T>::value, \"template\
    \ parameter T must be integral type\");\n    Graph<T>& graph;\n    vector<int>\
    \ dist,parent;\n    size_t N;\n    bool is_same_weighted;\n    T inf;\n    int\
    \ last,root;\nprivate:\n    T solve_same_weighted() {\n        T mini = inf;\n\
    \        last = -1;\n        queue<int> q;\n        q.push(root);\n        dist[root]\
    \ = 0;\n        while (q.size()) {\n            size_t curr = q.front(); q.pop();\n\
    \            for(auto& edge:graph.edges[curr]){\n                size_t next =\
    \ edge.first;\n                T w  = edge.second;\n                \n       \
    \         //\u6839\u306B\u8FD4\u3063\u3066\u6765\u3066\u308B\u306A\u3089\u9589\
    \u8DEF\n                if(next == root && mini > dist[curr]+w) {\n          \
    \          mini = dist[curr]+w;\n                    last = curr;\n          \
    \      }\n                //\u305D\u3046\u3058\u3083\u306A\u3044\u306A\u3089\u63A2\
    \u7D22\u6728\u3092\u5E83\u3052\u308B\n                else if(dist[next]==-1)\
    \ {\n                    dist[next]   = dist[curr] + w;\n                    parent[next]\
    \ = curr;\n                    q.push(next);\n                }\n            }\n\
    \        }\n        return mini;\n    }\n    T solve_diff_weighted() {\n     \
    \   T mini = inf;\n        last = -1;\n        RadixHeap<int> q(0);\n        q.push({0,root});\n\
    \        dist[root] = 0;\n        while (q.size()) {\n            auto top = \
    \ q.pop();\n            size_t curr = top.second;\n            for(auto& edge:graph.edges[curr]){\n\
    \                size_t next = edge.first;\n                T w  = edge.second;\n\
    \                \n                //\u6839\u306B\u8FD4\u3063\u3066\u6765\u3066\
    \u308B\u306A\u3089\u9589\u8DEF\n                if(next == root && mini > dist[curr]+w)\
    \ {\n                    mini = dist[curr]+w;\n                    last = curr;\n\
    \                }\n                //\u305D\u3046\u3058\u3083\u306A\u3044\u306A\
    \u3089\u63A2\u7D22\u6728\u3092\u5E83\u3052\u308B\n                else if(dist[next]==-1)\
    \ {\n                    dist[next]   = dist[curr] + w;\n                    parent[next]\
    \ = curr;\n                    q.push({dist[next],next});\n                }\n\
    \            }\n        }\n        return mini;\n    }\npublic:\n    MinimumDirectedClosedCircuit(Graph<T>&\
    \ graph, T inf)\n     : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),inf(inf)\
    \ {\n        assert(!graph.edges.empty());\n        //\u91CD\u307F\u304C\u4E00\
    \u5F8B\u304B\u3069\u3046\u304B\u5224\u5B9A \u9762\u5012\u3060\u304B\u3089\u3053\
    \u3053\u306Flog\u3064\u304D\n        set<T> st;\n        for(int i=0;i<N;++i)\
    \ for(auto& edge:graph.edges[i]) st.insert(edge.second);        \n        is_same_weighted\
    \ = (st.size() == 1);\n    }\n    //root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\
    \u306E\u96C6\u5408\u3092\u8FD4\u3059 O(NlogN) \u9589\u8DEF\u304C\u306A\u3044\u3068\
    \u304D\u306F\u7A7A\u96C6\u5408\n    inline T solve(size_t rt, int restore = 0){\n\
    \        root = rt;\n        //\u521D\u671F\u5316\n        for(int i = 0; i <\
    \ N; ++i) dist[i] = parent[i] = -1;\n        //\u6700\u5C0F\u9589\u8DEF\u306E\u5927\
    \u304D\u3055\u3092\u6C7A\u3081\u308B\n        T mini;\n        if(is_same_weighted)\
    \ mini=solve_same_weighted(); //\u91CD\u307F\u4E00\u5F8B\n        else mini=solve_diff_weighted();\
    \ //\u91CD\u307F\u304C\u30D0\u30E9\u30D0\u30E9\n        return mini;\n    }\n\
    \    vector<int> restore() {\n        vector<int> res;\n        if(last == -1)\
    \ return res;\n        res.push_back(last);\n        int curr = last;\n      \
    \  while(curr != root) res.push_back(curr = parent[curr]);\n        reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/MinimumDirectedClosedCircuit.cpp
  requiredBy: []
  timestamp: '2020-11-27 16:35:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
documentation_of: lib/graph/MinimumDirectedClosedCircuit.cpp
layout: document
redirect_from:
- /library/lib/graph/MinimumDirectedClosedCircuit.cpp
- /library/lib/graph/MinimumDirectedClosedCircuit.cpp.html
title: "MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\
  \u9589\u8DEF\u691C\u51FA"
---
