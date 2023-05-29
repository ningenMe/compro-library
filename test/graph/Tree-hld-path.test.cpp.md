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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid/MonoidRangeMulPointUpdate.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/650\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/30-math/Matrix.cpp\"\
    \n#include \"../../lib/40-graph/Tree.cpp\"\n#include \"../../lib/data-structure/segment-tree/SegmentTree.cpp\"\
    \n#include \"../../lib/operator/monoid/MonoidRangeMulPointUpdate.cpp\"\n#include\
    \ \"../../lib/00-util/ModInt.cpp\"\n\nconstexpr long long MOD = 1'000'000'007LL;\n\
    using modint = ModInt<MOD>;\nusing matrix = Matrix<modint,2,2>;\n\nint main(void){\n\
    \tint N; cin >> N;\n\tGraph<int> g(N);\n\tvector<pair<size_t,size_t>> vp(N-1);\n\
    \tfor(int i = 0; i < N-1; ++i) {\n\t\tint u,v; cin >> u >> v;\n\t\tg.make_bidirectional_edge(u,v,1);\n\
    \t\tvp[i]={u,v};\n\t}\n\tauto tree = Tree<TreeOperator<int>>::builder(g).root(0).child().subtree_size().parent().heavy_light_decomposition().build();\n\
    \    SegmentTree<MonoidRangeMulPointUpdate<matrix>> seg(N);\n    int Q; cin >>\
    \ Q;\n    while(Q--) {\n        char c; cin >> c;\n        if(c == 'x'){\n   \
    \         int i; cin >> i;\n            modint a,b,c,d; cin >> a >> b >> c >>\
    \ d;\n            matrix x;\n\t\t\tx[0]={a,b};\n\t\t\tx[1]={c,d};\n\t\t\tint l\
    \ = vp[i].first, r = vp[i].second;\n            l = tree.hld[l],r = tree.hld[r];\n\
    \            seg.operate(max(l,r),x);\n        }\n        else{\n            int\
    \ l,r; cin >> l >> r;\n            auto vp = tree.edge_set_on_path(l,r);\n   \
    \         matrix ans = matrix::E();\n            for(auto p:vp){\n           \
    \     ans *= seg.fold(p.first,p.second+1);\n            }\n            cout <<\
    \ ans[0][0] << \" \" << ans[0][1] << \" \" << ans[1][0] << \" \" << ans[1][1]\
    \ << endl;\n        }\n    }\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tree-hld-path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tree-hld-path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-hld-path.test.cpp
- /verify/test/graph/Tree-hld-path.test.cpp.html
title: test/graph/Tree-hld-path.test.cpp
---
