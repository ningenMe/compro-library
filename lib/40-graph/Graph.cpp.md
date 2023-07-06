---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/MinimumUndirectedClosedCircuit.test.cpp
    title: test/graph/MinimumUndirectedClosedCircuit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-diameter.test.cpp
    title: test/graph/Tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-path.test.cpp
    title: test/graph/Tree-hld-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-1.test.cpp
    title: test/graph/Tree-hld-vertex-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-2.test.cpp
    title: test/graph/Tree-hld-vertex-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-3.test.cpp
    title: test/graph/Tree-hld-vertex-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-lca-idx.test.cpp
    title: test/graph/Tree-lca-idx.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-lca.test.cpp
    title: test/graph/Tree-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-parent.test.cpp
    title: test/graph/Tree-parent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-rerooting.test.cpp
    title: test/graph/Tree-rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-size.test.cpp
    title: test/graph/Tree-size.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/Graph.md
    document_title: Graph
    links: []
  bundledCode: "#line 1 \"lib/40-graph/Graph.cpp\"\n/*\n * @title Graph\n * @docs\
    \ md/graph/Graph.md\n */\ntemplate<class T> class Graph{\nprivate:\n    const\
    \ size_t N,H,W;\npublic:\n    vector<vector<pair<size_t,T>>> edges;\n    Graph(const\
    \ size_t N):H(-1),W(-1),N(N), edges(N) {}\n    Graph(const size_t H, const size_t\
    \ W):H(H),W(W),N(H*W), edges(H*W) {}\n    inline void make_edge(size_t from, size_t\
    \ to, T w) {\n        edges[from].emplace_back(to,w);\n    }\n    //{from_y,from_x}\
    \ -> {to_y,to_x} \n    inline void make_edge(pair<size_t,size_t> from, pair<size_t,size_t>\
    \ to, T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \    }\n    inline void make_bidirectional_edge(size_t from, size_t to, T w) {\n\
    \        make_edge(from,to,w);\n        make_edge(to,from,w);\n    }\n    inline\
    \ void make_bidirectional_edge(pair<size_t,size_t> from, pair<size_t,size_t> to,\
    \ T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \        make_edge(to.first*W+to.second,from.first*W+from.second,w);\n    }\n\
    \    inline size_t size(){return N;}\n    inline size_t idx(pair<size_t,size_t>\
    \ yx){return yx.first*W+yx.second;}\n};\n"
  code: "/*\n * @title Graph\n * @docs md/graph/Graph.md\n */\ntemplate<class T> class\
    \ Graph{\nprivate:\n    const size_t N,H,W;\npublic:\n    vector<vector<pair<size_t,T>>>\
    \ edges;\n    Graph(const size_t N):H(-1),W(-1),N(N), edges(N) {}\n    Graph(const\
    \ size_t H, const size_t W):H(H),W(W),N(H*W), edges(H*W) {}\n    inline void make_edge(size_t\
    \ from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n    }\n  \
    \  //{from_y,from_x} -> {to_y,to_x} \n    inline void make_edge(pair<size_t,size_t>\
    \ from, pair<size_t,size_t> to, T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \    }\n    inline void make_bidirectional_edge(size_t from, size_t to, T w) {\n\
    \        make_edge(from,to,w);\n        make_edge(to,from,w);\n    }\n    inline\
    \ void make_bidirectional_edge(pair<size_t,size_t> from, pair<size_t,size_t> to,\
    \ T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \        make_edge(to.first*W+to.second,from.first*W+from.second,w);\n    }\n\
    \    inline size_t size(){return N;}\n    inline size_t idx(pair<size_t,size_t>\
    \ yx){return yx.first*W+yx.second;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/40-graph/Graph.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-hld-vertex-3.test.cpp
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
  - test/graph/Tree-rerooting.test.cpp
  - test/graph/MinimumUndirectedClosedCircuit.test.cpp
  - test/graph/Tree-eulertour.test.cpp
  - test/graph/Tree-hld-vertex-1.test.cpp
  - test/graph/Tree-size.test.cpp
  - test/graph/Tree-hld-path.test.cpp
  - test/graph/Tree-lca-idx.test.cpp
  - test/graph/Tree-hld-vertex-2.test.cpp
  - test/graph/Tree-diameter.test.cpp
  - test/graph/Tree-parent.test.cpp
  - test/graph/Tree-lca.test.cpp
documentation_of: lib/40-graph/Graph.cpp
layout: document
redirect_from:
- /library/lib/40-graph/Graph.cpp
- /library/lib/40-graph/Graph.cpp.html
title: Graph
---
