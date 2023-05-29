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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <map>\n\
    #include <algorithm>\n#include <stack>\n#include <numeric>\n#include <array>\n\
    using namespace std;\n#include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/40-graph/Tree.cpp\"\
    \n#include \"../../lib/00-util/ModInt.cpp\"\n#include \"../../lib/data-structure/segment-tree/SegmentTree.cpp\"\
    \n#include \"../../lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\n\
    \n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct MonoidRangeRevCompositePointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ make_pair(1,0);\n    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode\
    \ r){return {l.first*r.first,l.first*r.second+l.second};}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}\n};\n\
    \nusing modint = ModInt<998244353>;\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    SegmentTree<MonoidRangeCompositePointUpdate<pair<modint,modint>>>\
    \ segLtoR(N,{1,0});\n    SegmentTree<MonoidRangeRevCompositePointUpdate<pair<modint,modint>>>\
    \ segRtoL(N,{1,0});\n    vector<int> A(N),B(N);\n    for(int i=0;i<N;++i) cin\
    \ >> A[i] >> B[i];\n    Graph<int> g(N);\n    for(int i=0;i+1<N;++i) {\n     \
    \   int u,v; cin >> u >> v;\n        g.make_bidirectional_edge(u,v,1);\n    }\n\
    \    auto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();\n\
    \    for(int i=0;i<N;++i) {\n        int j = tree.hld[i];\n        segLtoR.operate(j,{A[i],B[i]});\n\
    \        segRtoL.operate(j,{A[i],B[i]});\n    }\n    while(Q--) {\n        int\
    \ q; cin >> q;\n        if(q==0) {\n            int i,a,b; cin >> i >> a >> b;\n\
    \            int j = tree.hld[i];\n            segLtoR.operate(j,{a,b});\n   \
    \         segRtoL.operate(j,{a,b});\n        }\n        else {\n            int\
    \ l,r,x; cin >> l >> r >> x;\n            auto tp = tree.vertex_ordered_set_on_path(l,r);\n\
    \n            pair<modint,modint> line = {1,0};\n            for(auto& p:tp.first)\
    \ {\n                auto tmp = segRtoL.fold(p.first,p.second+1);\n          \
    \      line = {tmp.first*line.first,tmp.first*line.second+tmp.second};\n     \
    \       }\n            for(auto& p:tp.second) {\n                auto tmp = segLtoR.fold(p.first,p.second+1);\n\
    \                line = {tmp.first*line.first,tmp.first*line.second+tmp.second};\n\
    \            }\n            cout << line.first*x+line.second << \"\\n\";\n   \
    \     }\n    }\n    return 0; \n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tree-hld-vertex-3.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tree-hld-vertex-3.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-hld-vertex-3.test.cpp
- /verify/test/graph/Tree-hld-vertex-3.test.cpp.html
title: test/graph/Tree-hld-vertex-3.test.cpp
---
