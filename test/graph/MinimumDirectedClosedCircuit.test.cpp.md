---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/Graph.cpp
    title: Graph
  - icon: ':x:'
    path: lib/graph/MinimumDirectedClosedCircuit.cpp
    title: "MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6700\
      \u5C0F\u9589\u8DEF\u691C\u51FA"
  - icon: ':question:'
    path: lib/heap/RadixHeap.cpp
    title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
  bundledCode: "#line 1 \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <queue>\n#include <map>\n\nusing namespace std;\n#line\
    \ 1 \"lib/graph/Graph.cpp\"\n/*\n * @title Graph\n * @docs md/graph/Graph.md\n\
    \ */\ntemplate<class T> class Graph{\nprivate:\n    const size_t N,H,W;\npublic:\n\
    \    vector<vector<pair<size_t,T>>> edges;\n    Graph(const size_t N):N(N), edges(N)\
    \ {}\n    Graph(const size_t H, const size_t W):H(H),W(W),N(H*W), edges(H*W) {}\n\
    \    inline void make_edge(size_t from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n\
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
    \ */\ntemplate<class T> class RadixHeap{\n\tusing TypeNode = pair<unsigned long\
    \ long, T>;\n\tarray<vector<TypeNode>,65> vq;\n\tunsigned long long size_num;\n\
    \tTypeNode last;\n\tinline int bit(unsigned long long a) {\n\t\treturn a ? 64\
    \ - __builtin_clzll(a) : 0;\n\t}\npublic:\n\tRadixHeap(T mini) : size_num(0),\
    \ last(make_pair(0,mini)) {\n\t\t// do nothing\n\t}\n\tinline bool empty() {\n\
    \t\treturn size_num == 0;\n\t}\n\tinline size_t size(){\n\t\treturn size_num;\n\
    \t}\n\tinline void push(TypeNode x){\n\t\t++size_num;\n\t\tvq[bit(x.first^last.first)].push_back(x);\n\
    \t}\n\tinline void emplace(unsigned long long key,T val){\n\t\t++size_num;\n\t\
    \tvq[bit(key^last.first)].emplace_back(key,val);\n\t}\n\tinline TypeNode pop()\
    \ {\n\t\tif(vq[0].empty()) {\n\t\t\tint i = 1;\n\t\t\twhile(vq[i].empty()) ++i;\n\
    \t\t\tlast = *min_element(vq[i].begin(),vq[i].end());\n\t\t\tfor(auto &p : vq[i])\
    \ vq[bit(p.first ^ last.first)].push_back(p);\n\t\t\tvq[i].clear();\n\t\t}\n\t\
    \t--size_num;\n\t\tauto res = vq[0].back();\n\t\tvq[0].pop_back();\n\t\treturn\
    \ res;\n\t}\n};\n#line 1 \"lib/graph/MinimumDirectedClosedCircuit.cpp\"\n/*\n\
    \ * @title MinimumDirectedClosedCircuit - \u6709\u5411\u30B0\u30E9\u30D5\u306E\
    \u6700\u5C0F\u9589\u8DEF\u691C\u51FA\n * @docs md/graph/MinimumDirectedClosedCircuit.md\n\
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
    \        return res;\n    }\n};\n#line 15 \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\
    \n\nint main(){\n    int N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int\
    \ i = 0; i < M; ++i){\n        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n\
    \    }\n    MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans\
    \ = 0;\n    int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        mdcc.solve(i);\n\
    \        auto tmp = mdcc.restore();\n        if(!tmp.empty()) ans = 1;\n    }\n\
    \    cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <queue>\n#include <map>\n\nusing namespace std;\n#include\
    \ \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/heap/RadixHeap.cpp\"\n#include\
    \ \"../../lib/graph/MinimumDirectedClosedCircuit.cpp\"\n\nint main(){\n    int\
    \ N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int i = 0; i < M; ++i){\n\
    \        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n    }\n   \
    \ MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans = 0;\n \
    \   int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        mdcc.solve(i);\n\
    \        auto tmp = mdcc.restore();\n        if(!tmp.empty()) ans = 1;\n    }\n\
    \    cout << ans << endl;\n\treturn 0;\n}\n"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/heap/RadixHeap.cpp
  - lib/graph/MinimumDirectedClosedCircuit.cpp
  isVerificationFile: true
  path: test/graph/MinimumDirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '2020-11-27 17:11:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/MinimumDirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumDirectedClosedCircuit.test.cpp
---
