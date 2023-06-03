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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp\"\
    \n\nint main(void){\n    int N,Q;\n\tscanf(\"%d %d\",&N,&Q);\n    LazyRandomizedBinarySearchTreeSequence<MonoidRangeSumRangeAdd<long\
    \ long,long long>> A;\n    for(int i=0;i<N;++i) {\n\t\tA.insert(i,0);\n    }\n\
    \    while(Q--) {\n        int q;\n\t\tscanf(\"%d\",&q);\n\t\tif(q==0) {\n\t\t\
    \tint l,r,x;\n\t\t\tscanf(\"%d %d %d\",&l,&r,&x);\n\t\t\tl--;\n\t\t\tA.operate(l,r,x);\n\
    \t\t}\n\t\telse {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\tl--;\n\
    \t\t\tprintf(\"%lld\\n\",A.fold(l,r));\n\t\t}\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp.html
title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-rsqraq.test.cpp
---
