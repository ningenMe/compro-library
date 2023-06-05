---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.11/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/15-heap/RadixHeap.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n#include <queue>\n#include <map>\n#include <array>\n\nusing namespace\
    \ std;\n#include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/15-heap/RadixHeap.cpp\"\
    \n#include \"../../lib/40-graph/MinimumDirectedClosedCircuit.cpp\"\n\nint main(){\n\
    \    int N,M; cin >> N >> M;\n    Graph<int> graph(N);\n    for(int i = 0; i <\
    \ M; ++i){\n        int u,v; cin >> u >> v;\n        graph.make_edge(u,v,1);\n\
    \    }\n    MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);\n    int ans\
    \ = 0;\n    int inf = 1234567;\n    for(int i = 0; i < N; ++i){\n        mdcc.solve(i);\n\
    \        auto tmp = mdcc.restore();\n        if(!tmp.empty()) ans = 1;\n    }\n\
    \    cout << ans << endl;\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/MinimumDirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/MinimumDirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumDirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumDirectedClosedCircuit.test.cpp
---
