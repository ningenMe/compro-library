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
    #include <set>\n#include <queue>\n#include <map>\n\nusing namespace std;\n#line\
    \ 1 \"lib/graph/Graph.cpp\"\n/*\n * @title Graph\n * @docs md/graph/Graph.md\n\
    \ */\ntemplate<class T> class Graph{\nprivate:\n    const size_t N;\npublic:\n\
    \    vector<vector<pair<size_t,T>>> edges;\n    Graph(const size_t N):N(N), edges(N)\
    \ {}\n    void make_edge(size_t from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n\
    \    }\n    size_t size(){return N;}\n};\n#line 1 \"lib/heap/RadixHeap.cpp\"\n\
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
    \ parameter T must be integral type\");\n    Graph<T>& graph;\n\tvector<int> dist,parent;\n\
    \tsize_t N;\n    bool is_same_weighted;\n    T inf;\nprivate:\n    pair<T,int>\
    \ solve_same_weighted(size_t root) {\n\t\tT mini = inf, last = -1;\n        queue<int>\
    \ q;\n        q.push(root);\n        dist[root] = 0;\n        while (q.size())\
    \ {\n            size_t curr = q.front(); q.pop();\n            for(auto& edge:graph.edges[curr]){\n\
    \                size_t next = edge.first;\n                T w  = edge.second;\n\
    \                \n                //\u6839\u306B\u8FD4\u3063\u3066\u6765\u3066\
    \u308B\u306A\u3089\u9589\u8DEF\n                if(next == root && mini > dist[curr]+w)\
    \ {\n                    mini = dist[curr]+w;\n                    last = curr;\n\
    \                }\n                //\u305D\u3046\u3058\u3083\u306A\u3044\u306A\
    \u3089\u63A2\u7D22\u6728\u3092\u5E83\u3052\u308B\n                else if(dist[next]==-1)\
    \ {\n                    dist[next]   = dist[curr] + w;\n                    parent[next]\
    \ = curr;\n                    q.push(next);\n                }\n            }\n\
    \        }\n        return {mini,last};\n    }\n    pair<T,int> solve_diff_weighted(size_t\
    \ root) {\n\t\tT mini = inf, last = -1;\n        RadixHeap<int> q(0);\n      \
    \  q.push({0,root});\n        dist[root] = 0;\n        while (q.size()) {\n  \
    \          auto top =  q.pop();\n            size_t curr = top.second;\n     \
    \       for(auto& edge:graph.edges[curr]){\n                size_t next = edge.first;\n\
    \                T w  = edge.second;\n                \n                //\u6839\
    \u306B\u8FD4\u3063\u3066\u6765\u3066\u308B\u306A\u3089\u9589\u8DEF\n         \
    \       if(next == root && mini > dist[curr]+w) {\n                    mini =\
    \ dist[curr]+w;\n                    last = curr;\n                }\n       \
    \         //\u305D\u3046\u3058\u3083\u306A\u3044\u306A\u3089\u63A2\u7D22\u6728\
    \u3092\u5E83\u3052\u308B\n                else if(dist[next]==-1) {\n        \
    \            dist[next]   = dist[curr] + w;\n                    parent[next]\
    \ = curr;\n                    q.push({dist[next],next});\n                }\n\
    \            }\n        }\n        return {mini,last};\n    }\npublic:\n\tMinimumDirectedClosedCircuit(Graph<T>&\
    \ graph, T inf)\n     : graph(graph),N(graph.size()),dist(graph.size()),parent(graph.size()),inf(inf)\
    \ {\n        assert(!graph.edges.empty());\n        //\u91CD\u307F\u304C\u4E00\
    \u5F8B\u304B\u3069\u3046\u304B\u5224\u5B9A \u9762\u5012\u3060\u304B\u3089\u3053\
    \u3053\u306Flog\u3064\u304D\n        set<T> st;\n        for(int i=0;i<N;++i)\
    \ for(auto& edge:graph.edges[i]) st.insert(edge.second);        \n        is_same_weighted\
    \ = (st.size() == 1);\n\t}\n\t//root\u3092\u542B\u3080\u6700\u5C0F\u9589\u8DEF\
    \u306E\u96C6\u5408\u3092\u8FD4\u3059 O(NlogN) \u9589\u8DEF\u304C\u306A\u3044\u3068\
    \u304D\u306F\u7A7A\u96C6\u5408\n\tinline pair<T,vector<int>> solve(size_t root,\
    \ int restore = 0){\n        //\u521D\u671F\u5316\n\t\tfor(int i = 0; i < N; ++i)\
    \ dist[i] = parent[i] = -1;\n\n        //\u6700\u5C0F\u9589\u8DEF\u306E\u5927\u304D\
    \u3055\u3092\u6C7A\u3081\u308B\n        pair<T,int> p;\n        if(is_same_weighted)\
    \ p=solve_same_weighted(root); //\u91CD\u307F\u4E00\u5F8B\n        else p=solve_diff_weighted(root);\
    \ //\u91CD\u307F\u304C\u30D0\u30E9\u30D0\u30E9\n\n        //\u5FA9\u5143\n   \
    \     T mini = p.first;\n        int last = p.second;\n\t\tvector<int> res;\n\t\
    \tif(restore == 1 && last != -1){\n\t\t\tres.push_back(last);\n\t\t\tint curr\
    \ = last;\n\t\t\twhile(curr != root) res.push_back(curr = parent[curr]);\n\t\t\
    \treverse(res.begin(),res.end());\n\t\t}\n\t\treturn {mini,res};\n\t}\n};\n#line\
    \ 15 \"test/graph/MinimumDirectedClosedCircuit.test.cpp\"\n\nint main(){\n   \
    \ int N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int i = 0; i < M;\
    \ ++i){\n        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n  \
    \  }\n    MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans\
    \ = 0;\n    int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        auto\
    \ tmp = mdcc.solve(i,1);\n        if(!tmp.second.empty()) ans = 1;\n    }\n  \
    \  cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <queue>\n#include <map>\n\nusing namespace std;\n#include\
    \ \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/heap/RadixHeap.cpp\"\n#include\
    \ \"../../lib/graph/MinimumDirectedClosedCircuit.cpp\"\n\nint main(){\n    int\
    \ N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int i = 0; i < M; ++i){\n\
    \        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n    }\n   \
    \ MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans = 0;\n \
    \   int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        auto tmp = mdcc.solve(i,1);\n\
    \        if(!tmp.second.empty()) ans = 1;\n    }\n    cout << ans << endl;\n\t\
    return 0;\n}\n"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/heap/RadixHeap.cpp
  - lib/graph/MinimumDirectedClosedCircuit.cpp
  isVerificationFile: true
  path: test/graph/MinimumDirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '2020-11-27 07:59:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/MinimumDirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumDirectedClosedCircuit.test.cpp
---
