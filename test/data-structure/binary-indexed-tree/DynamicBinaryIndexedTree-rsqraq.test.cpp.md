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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <unordered_map>\nusing namespace\
    \ std;\n#include \"../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n#include\
    \ \"../../../lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicBinaryIndexedTree<AbelPrefixSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.operate(l,r);\n\
    \        else ans += seg.fold(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0; \n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
- /verify/test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp.html
title: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
---
