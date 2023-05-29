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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#include\
    \ \"../../lib/14-data-structure/BinaryTrie.cpp\"\n#include \"../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tBinaryTrie<MonoidRangeSumPointAdd<int>,30>\
    \ trie;\n\tint Q; cin >> Q;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\t\tlong long\
    \ x; cin >> x;\n\t\tif(q==0) {\n\t\t\tlong long y=trie.fold(x);\n\t\t\tif(!y)\
    \ trie.operate(x,1);\n\t\t}\n\t\tif(q==1) {\n\t\t\tlong long y=trie.fold(x);\n\
    \t\t\tif(y) trie.operate(x,-1);\n\t\t}\n\t\tif(q==2) {\n\t\t\tcout << trie.min_bitwise_xor(x)\
    \ << endl;\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/BinaryTrie-set-xor-min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/BinaryTrie-set-xor-min.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/BinaryTrie-set-xor-min.test.cpp
- /verify/test/data-structure/BinaryTrie-set-xor-min.test.cpp.html
title: test/data-structure/BinaryTrie-set-xor-min.test.cpp
---
