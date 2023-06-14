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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <numeric>\n#include <cmath>\n#include <stack>\nusing namespace std;\n\
    \n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    IntegerRangeFrequencyQuerySqrtTree<30> rfq(N);\n    for(int i=0;i<N;++i)\
    \ {\n        int a; read(a);\n        rfq.update(i,a);\n    }\n    while(Q--)\
    \ {\n        int l,r,x;\n        read(l); read(r); read(x);\n        cout << rfq.range_freq(l,r,x)\
    \ << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
- /verify/test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp.html
title: test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
---
