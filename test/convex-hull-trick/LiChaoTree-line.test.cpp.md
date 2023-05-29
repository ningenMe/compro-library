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
    #include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n\n#include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"\
    ../../lib/16-convex-hull-trick/LiChaoTree.cpp\"\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tint N,Q; cin >> N >> Q;\n\tvector<long long> A(N),B(N),C(Q),D(Q),E(Q);\n\tfor(int\
    \ i = 0; i < N; ++i) cin >> A[i] >> B[i];\n\tLiChaoTree<ValueMin<long long>> lct;\n\
    \tfor(int i = 0; i < Q; ++i) {\n\t\tcin >> C[i];\n\t\tif(C[i]) {\n\t\t\tcin >>\
    \ D[i];\n\t\t\tlct.x_push_back(D[i]);\n\t\t}\n\t\telse {\n\t\t\tcin >> D[i] >>\
    \ E[i];\n\t\t}\n\t}\n\tlct.build();\n\tfor(int i = 0; i < N; ++i) lct.update({A[i],B[i]});\n\
    \tlong long inf = 3e18;\n\tfor(int i = 0; i < Q; ++i) {\n\t\tif(C[i]) {\n\t\t\t\
    long long ans = lct.get(D[i]);\n\t\t\tif(ans!=inf) cout << ans << endl;\n\t\t\t\
    else cout << \"INFINITY\" << endl;\n\t\t}\n\t\telse {\n\t\t\tlct.update({D[i],E[i]});\n\
    \t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/convex-hull-trick/LiChaoTree-line.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/convex-hull-trick/LiChaoTree-line.test.cpp
layout: document
redirect_from:
- /verify/test/convex-hull-trick/LiChaoTree-line.test.cpp
- /verify/test/convex-hull-trick/LiChaoTree-line.test.cpp.html
title: test/convex-hull-trick/LiChaoTree-line.test.cpp
---
