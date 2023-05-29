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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <map>\n\
    #include <algorithm>\n#include <stack>\n#include <numeric>\n#include <array>\n\
    using namespace std;\n#include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/40-graph/Tree.cpp\"\
    \n#include \"../../lib/data-structure/segment-tree/SegmentTree.cpp\"\n#include\
    \ \"../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin >> N >> Q;\n\tGraph<int>\
    \ g(N);\n\tvector<long long> a(N);\n\tfor(int i=0;i<N;++i) cin >> a[i];\n\tfor(int\
    \ i=0;i<(N-1);++i){\n\t\tint u,v; cin >> u >> v;\n\t\tg.make_bidirectional_edge(u,v,1);\n\
    \t}\n\tauto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();\n\
    \tSegmentTree<MonoidRangeSumPointAdd<long long>> seg(N);\n\tfor(int i=0;i<N;++i)\
    \ seg.operate(tree.hld[i],a[i]);\n\twhile(Q--){\n\t\tint q,s,t; cin >> q >> s\
    \ >> t;\n\t\tif(q) {\n\t\t\tlong long ans=0;\n\t\t\tauto v = tree.vertex_set_on_path(s,t);\n\
    \t\t\tfor(auto& e:v) ans += seg.fold(e.first,e.second+1);\n\t\t\tcout << ans <<\
    \ endl;\n\t\t}\n\t\telse {\n\t\t\tseg.operate(tree.hld[s],t);\n\t\t}\n\t}\n  \
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tree-hld-vertex-2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tree-hld-vertex-2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-hld-vertex-2.test.cpp
- /verify/test/graph/Tree-hld-vertex-2.test.cpp.html
title: test/graph/Tree-hld-vertex-2.test.cpp
---
