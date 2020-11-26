---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/Graph.md
    document_title: Graph
    links: []
  bundledCode: "#line 1 \"lib/graph/Graph.cpp\"\n/*\n * @title Graph\n * @docs md/graph/Graph.md\n\
    \ */\ntemplate<class T> class Graph{\nprivate:\n    const size_t N;\npublic:\n\
    \    vector<vector<pair<size_t,T>>> edges;\n    Graph(const size_t N):N(N), edges(N)\
    \ {}\n    void make_edge(size_t from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n\
    \    }\n    size_t size(){return N;}\n};\n"
  code: "/*\n * @title Graph\n * @docs md/graph/Graph.md\n */\ntemplate<class T> class\
    \ Graph{\nprivate:\n    const size_t N;\npublic:\n    vector<vector<pair<size_t,T>>>\
    \ edges;\n    Graph(const size_t N):N(N), edges(N) {}\n    void make_edge(size_t\
    \ from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n    }\n  \
    \  size_t size(){return N;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/Graph.cpp
  requiredBy: []
  timestamp: '2020-11-27 07:59:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
documentation_of: lib/graph/Graph.cpp
layout: document
redirect_from:
- /library/lib/graph/Graph.cpp
- /library/lib/graph/Graph.cpp.html
title: Graph
---
