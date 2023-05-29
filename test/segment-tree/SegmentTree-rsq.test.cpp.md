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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/10-segment-tree/SegmentTree.cpp\"\n#include \"../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin\
    \ >> N >> Q;\n\tSegmentTree<MonoidRangeSumPointAdd<long long>> Seg(N,0);\n\twhile(Q--){\n\
    \t\tint q; cin >> q;\n\t\tif(q==0){\n\t\t\tint x,y; cin >> x >> y;\n\t\t\tx--;\n\
    \t\t\tSeg.operate(x,y);\n\t\t}\n\t\telse{\n\t\t\tint x,y; cin >> x >> y;\n\t\t\
    \tx--;\n\t\t\tcout << Seg.fold(x,y) << endl;\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/segment-tree/SegmentTree-rsq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment-tree/SegmentTree-rsq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SegmentTree-rsq.test.cpp
- /verify/test/segment-tree/SegmentTree-rsq.test.cpp.html
title: test/segment-tree/SegmentTree-rsq.test.cpp
---
