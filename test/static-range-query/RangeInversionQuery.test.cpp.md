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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <cmath>\nusing namespace std;\n#include \"../../lib/11-binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n#include \"../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n#include\
    \ \"../../lib/13-static-range-query/RangeInversionQuery.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false); \n    int N,Q; cin >> N >> Q;\n \
    \   vector<long long> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    RangeInversionQuery<long\
    \ long> riq(A);\n    while(Q--) {\n        int l,r; cin >> l >> r;\n        long\
    \ long inv = riq.fold(l,r);\n        cout << inv << \"\\n\";\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/static-range-query/RangeInversionQuery.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/static-range-query/RangeInversionQuery.test.cpp
layout: document
redirect_from:
- /verify/test/static-range-query/RangeInversionQuery.test.cpp
- /verify/test/static-range-query/RangeInversionQuery.test.cpp.html
title: test/static-range-query/RangeInversionQuery.test.cpp
---
