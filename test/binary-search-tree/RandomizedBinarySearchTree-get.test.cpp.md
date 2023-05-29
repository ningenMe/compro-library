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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/649\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#include \"../../lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n#include \"../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\nint main(){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n\tRandomizedBinarySearchTree<MonoidRangeSumPointAdd<long\
    \ long>> st;\n\tint Q,K; cin >> Q >> K;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\
    \t\tif(q==1){\n\t\t\tlong long x; cin >> x;\n\t\t\tst.insert(x);\n\t\t}\n\t\t\
    else{\n\t\t\tlong long x=-1;\n\t\t\tif(st.size()>=K){\n\t\t\t\tx=st.get(K-1);\n\
    \t\t\t\tst.erase(x);\n\t\t\t}\n\t\t\tcout << x << endl;\n\t\t}\n\t}\n\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp.html
title: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
---
