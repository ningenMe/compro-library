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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/13\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <cassert>\n#include <set>\n\
    #include <queue>\n#include <map>\n#include <stack>\n#include <array>\n\nusing\
    \ namespace std;\n#include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/15-heap/RadixHeap.cpp\"\
    \n#include \"../../lib/40-graph/MinimumUndirectedClosedCircuit.cpp\"\n\nint main(){\n\
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
  dependsOn: []
  isVerificationFile: true
  path: test/graph/MinimumUndirectedClosedCircuit.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/MinimumUndirectedClosedCircuit.test.cpp
layout: document
redirect_from:
- /verify/test/graph/MinimumUndirectedClosedCircuit.test.cpp
- /verify/test/graph/MinimumUndirectedClosedCircuit.test.cpp.html
title: test/graph/MinimumUndirectedClosedCircuit.test.cpp
---
