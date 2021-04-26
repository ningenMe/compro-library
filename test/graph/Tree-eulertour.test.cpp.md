---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/segment/LazySegmentTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/900\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/graph/Tree.cpp\"\n\
    #include \"../../lib/segment/LazySegmentTree.cpp\"\n\n\n//node:\u7DCF\u548C\u3000\
    lazy:\u52A0\u7B97\ntemplate<class T, class U> struct NodeEulerTourSumRangeAdd\
    \ {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = {0,0};\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n\t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n\
    };\n\n\nint main(void){\n\tint N; cin >> N;\n\tGraph<long long> g(N);\n\tfor(int\
    \ i=0;i<N-1;++i) {\n\t\tint u,v,w; cin >> u >> v >> w;\n\t\tg.make_bidirectional_edge(u,v,w);\n\
    \t}\n\tauto tree = Tree<TreeOperator<long long>>::builder(g).root(0).parent().child().eulertour().build();\n\
    \tint M = tree.eulertour.size();\n\tvector<pair<long long,long long>> init(M,{0,0});\n\
    \tfor(int i=1;i<M;++i) {\n\t\tint l=tree.eulertour[i-1], r = tree.eulertour[i],\
    \ sgn;\n\t\tlong long w;\n\t\tif(tree.depth[l]<tree.depth[r]) {\n\t\t\tw = tree.parent[r].second;\n\
    \t\t\tsgn = 1;\n\t\t}\n\t\telse {\n\t\t\tw = tree.parent[l].second;\n\t\t\tsgn\
    \ = -1;\n\t\t}\n\t\tinit[i] = {w*sgn,sgn};\n\t}\n\tLazySegmentTree<NodeEulerTourSumRangeAdd<pair<long\
    \ long,long long>,long long>> seg(init);\n\tint Q; cin >> Q;\n\twhile(Q--) {\n\
    \t\tint q; cin >> q;\n\t\tint a; cin >> a;\n\t\tint l = tree.eulertour_range[a].first;\n\
    \t\tint r = tree.eulertour_range[a].second;\n\t\tif(q==1) {\n\t\t\tlong long x;\
    \ cin >> x;\n\t\t\tseg.update(l+1,r,x);\n\t\t}\n\t\telse {\n\t\t\tcout << seg.get(0,l+1).first\
    \ << endl;\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/Tree-eulertour.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/Tree-eulertour.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-eulertour.test.cpp
- /verify/test/graph/Tree-eulertour.test.cpp.html
title: test/graph/Tree-eulertour.test.cpp
---
