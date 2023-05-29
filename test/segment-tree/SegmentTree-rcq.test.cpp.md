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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/10-segment-tree/SegmentTree.cpp\"\n#include \"../../lib/00-util/ModInt.cpp\"\
    \n#include \"../../../lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp\"\
    \n\nusing modint = ModInt<998244353>;\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<pair<modint,modint>> A(N);\n    for(int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].first >> A[i].second;\n    }\n   \
    \ SegmentTree<MonoidRangeCompositePointUpdate<pair<modint,modint>>> seg(A);\n\
    \    while(Q--){\n        long long q,l,r,x; cin >> q >> l >> r >> x;\n      \
    \  if(q) {\n\t\t\tauto p = seg.fold(l,r);\n\t\t\tcout << p.first*x+p.second <<\
    \ endl;\n\t\t}\n        else seg.operate(l,{r,x});\n    }\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/segment-tree/SegmentTree-rcq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment-tree/SegmentTree-rcq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SegmentTree-rcq.test.cpp
- /verify/test/segment-tree/SegmentTree-rcq.test.cpp.html
title: test/segment-tree/SegmentTree-rcq.test.cpp
---
