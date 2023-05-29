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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <vector>\n#include <iostream>\n#include <algorithm>\nusing namespace\
    \ std;\n#include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"\
    ../../lib/16-convex-hull-trick/LiChaoTree.cpp\"\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tint length,Q; cin >> length >> Q;\n\tvector<long long> A(length),B(length),L(length),R(length),E(Q),F(Q),C(Q),D(Q),S(Q),TypeValue(Q);\n\
    \tfor(int i = 0; i < length; ++i) {\n\t\tcin >> L[i] >> R[i] >> A[i] >> B[i];\n\
    \t}\n\tLiChaoTree<ValueMin<long long>> lct;\n\tfor(int i = 0; i < length; ++i)\
    \ lct.x_push_back(L[i]),lct.x_push_back(R[i]);\n\tfor(int i = 0; i < Q; ++i) {\n\
    \t\tcin >> E[i];\n\t\tif(E[i]) {\n\t\t\tcin >> F[i];\n\t\t\tlct.x_push_back(F[i]);\n\
    \t\t}\n\t\telse {\n\t\t\tcin >> S[i] >> TypeValue[i] >> C[i] >> D[i];\n\t\t\t\
    lct.x_push_back(S[i]);\n\t\t\tlct.x_push_back(TypeValue[i]);\n\t\t}\n\t}\n\tlct.build();\n\
    \tlong long inf = 3e18;\n\tfor(int i = 0; i < length; ++i) lct.update({A[i],B[i]},L[i],R[i]);\n\
    \tfor(int i = 0; i < Q; ++i) {\n\t\tif(E[i]) {\n\t\t\tlong long ans = lct.get(F[i]);\n\
    \t\t\tif(ans!=inf) cout << ans << endl;\n\t\t\telse cout << \"INFINITY\" << endl;\n\
    \t\t}\n\t\telse {\n\t\t\tlct.update({C[i],D[i]},S[i],TypeValue[i]);\n\t\t}\n\t\
    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/convex-hull-trick/LiChaoTree-segment.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/convex-hull-trick/LiChaoTree-segment.test.cpp
layout: document
redirect_from:
- /verify/test/convex-hull-trick/LiChaoTree-segment.test.cpp
- /verify/test/convex-hull-trick/LiChaoTree-segment.test.cpp.html
title: test/convex-hull-trick/LiChaoTree-segment.test.cpp
---
