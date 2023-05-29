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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/742\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\n#include \"../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\
    \n#include \"../../../lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<int> A(N+1,0);\n    for(int\
    \ i = 1; i <= N; ++i) {\n        cin >> A[i];\n    }\n    BinaryIndexedTree<AbelPrefixSumPointAdd<int>>\
    \ bit(N+1);\n    int ans = 0;\n    for(int i = N; 1 <= i; --i) {\n        ans\
    \ += bit.fold(A[i]);\n        bit.operate(A[i],1);\n    }\n    cout << ans <<\
    \ endl;\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
- /verify/test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp.html
title: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
---
