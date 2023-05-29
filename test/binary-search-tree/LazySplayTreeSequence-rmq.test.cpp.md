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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\nusing namespace\
    \ std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n\nint\
    \ main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; \n\tread(N);\
    \ read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldMinRangeOperateUpdate<int,int>>\
    \ st;\n    for(int i = 0; i < N; ++i) {\n        int a; read(a); st.insert(i,a);\n\
    \    }\n\n    while(Q--){\n        int l,r; \n\t\tread(l);read(r);\n        cout\
    \ << st.fold(l,r) << \"\\n\";\n    }\n    return 0; \n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
- /verify/test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp.html
title: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
---
