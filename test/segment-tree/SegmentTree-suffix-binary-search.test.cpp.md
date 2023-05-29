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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/4072\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\n#include \"../../lib/10-segment-tree/SegmentTree.cpp\"\
    \n#include \"../../lib/30-math/Gcd.cpp\"\n#include \"../../../lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp\"\
    \n\n// solution by binary search in prefix range on segment tree \nint main()\
    \ {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tlong long N; cin >> N;\n\tvector<long\
    \ long> A(N);\n\tfor(int i = 0; i < N; ++i) cin >> A[i];\n\tSegmentTree<MonoidRangeGcdPointUpdate<long\
    \ long>> seg(A);\n\tlong long ans = 0;\n\tfor(int i = N-1; 0 <= i; --i) {\n\t\t\
    ans += seg.suffix_binary_search(-1,i,1) + 1;\n\t}\n\tcout << ans << endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
- /verify/test/segment-tree/SegmentTree-suffix-binary-search.test.cpp.html
title: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
---
