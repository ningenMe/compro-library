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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/operator/monoid/MonoidRangeMinPointUpdate.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../../lib/data-structure/segment-tree/SegmentTree.cpp\"\n\
    #include \"../../../lib/operator/monoid/MonoidRangeMinPointUpdate.cpp\"\n\nint\
    \ main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin >> N\
    \ >> Q;\n\tSegmentTree<MonoidRangeMinPointUpdate<long long>> Seg(N);\n\twhile(Q--){\n\
    \t\tlong long q,a,b;\n\t\tcin >> q >> a >> b;\n\t\tif(q) cout << Seg.fold(a,b+1)\
    \ << endl;\n\t\telse Seg.operate(a,b);\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
- /verify/test/data-structure/segment-tree/SegmentTree-rmq.test.cpp.html
title: test/data-structure/segment-tree/SegmentTree-rmq.test.cpp
---
