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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/399\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/40-graph/Tree.cpp\"\
    \n#include \"../../lib/data-structure/segment-tree/LazySegmentTree.cpp\"\n#include\
    \ \"../../lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp\"\n\nint main(void){\n\
    \tint N; cin >> N;\n\tGraph<int> g(N);\n\tfor(int i=0;i<N-1;++i) {\n\t\tint u,v;\
    \ cin >> u >> v;\n\t\tu--,v--;\n\t\tg.make_bidirectional_edge(u,v,1);\n\t}\n\t\
    auto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();\n\
    \tLazySegmentTree<MonoidRangeSumRangeAdd<long long,long long>> seg(N);\n\tint\
    \ Q; cin >> Q;\n\tlong long ans = 0;\n\twhile(Q--) {\n\t\tint a,b; cin >> a >>\
    \ b;\n\t\ta--,b--;\n\t\tauto vp = tree.vertex_set_on_path(a,b);\n\t\tfor(auto&\
    \ p:vp) {\n\t\t\tint l = p.first, r = p.second+1;\n\t\t\tint n = r-l;\n\t\t\t\
    ans += seg.fold(l,r)+n;\n\t\t\tseg.operate(l,r,1);\n\t\t}\n\t}\n\tcout << ans\
    \ << endl;\n   return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tree-hld-vertex-1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tree-hld-vertex-1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-hld-vertex-1.test.cpp
- /verify/test/graph/Tree-hld-vertex-1.test.cpp.html
title: test/graph/Tree-hld-vertex-1.test.cpp
---
