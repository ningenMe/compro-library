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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/operator/operator/ValueMin.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <vector>\n#include <queue>\nusing namespace std;\n\
    #include \"../../../lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n#include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"../../../lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n\tConvexHullTrick<ValueMin<__int128_t>> cht;\n\twhile(N--){\n\t\t\
    long long a,b; cin >> a >> b;\n\t\tcht.insert(a,b);\n\t}\n\twhile(Q--){\n\t\t\
    int q; cin >> q;\n\t\tif(q){\n\t\t\tlong long p; cin >> p;\n\t\t\tlong long ans\
    \ = cht.get(p);\n\t\t\tcout << ans << endl;\n\t\t}\n\t\telse{\n\t\t\tlong long\
    \ a,b; cin >> a >> b;\n\t\t\tcht.insert(a,b);\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp.html
title: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
---
