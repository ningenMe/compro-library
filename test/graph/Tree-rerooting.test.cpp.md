---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/40-graph/UnionFindTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/922\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <algorithm>\n#include <stack>\n\
    #include <numeric>\n#include <array>\nusing namespace std;\n#include \"../../lib/40-graph/UnionFindTree.cpp\"\
    \n#include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/40-graph/StaticTree.cpp\"\
    \n\nint main(void){\n    int N,M,Q; cin >> N >> M >> Q;\n    UnionFindTree uf(N);\n\
    \    Graph<long long> g(N);\n    for(int i=0;i<M;++i) {\n        int u,v; cin\
    \ >> u >> v;\n        u--,v--;\n\t\tuf.merge(u,v);\n        g.make_bidirectional_edge(u,v,1);\n\
    \    }\n    auto tree = StaticTree<StaticTreeOperator<long long>>::builder(g).root().parent().ancestor().child().build();\n\
    \tlong long ans = 0;\n\tvector<pair<long long,long long>> cnt(N,{0,0}),par(N,{0,0});\n\
    \tfor(int i = 0; i < Q; ++i){\n        int a,b; cin >> a >> b;\n        a--,b--;\n\
    \        if(uf.connected(a,b)){\n\t\t\tans += tree.lca(a,b).second;\n        }\n\
    \        else{\n            cnt[a].second++;\n            cnt[b].second++;\n \
    \       }\n    }\n\tfor(int i = 0; i < N; ++i) if(tree.depth[i]) par[i] = cnt[tree.parent[i].first];\n\
    \tauto dp = tree.rerooting<pair<long long,long long>>(cnt,par);\n\tconst long\
    \ long inf = 1e15;\n\tvector<long long> sum(N,inf);\n\tfor(int i = 0,j; i < N;\
    \ ++i) j = uf[i],sum[j] = min(sum[j],dp[i].first);\n    for(int i = 0; i < N;\
    \ ++i) if(sum[i] != inf) ans += sum[i];\n\tcout << ans << endl;\t\n\treturn 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tree-rerooting.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tree-rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-rerooting.test.cpp
- /verify/test/graph/Tree-rerooting.test.cpp.html
title: test/graph/Tree-rerooting.test.cpp
---
