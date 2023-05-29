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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/operator/monoid-lazy/MonoidRangeSumRangeAffine.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/00-util/ModInt.cpp\"\n#include \"../../lib/operator/monoid-lazy/MonoidRangeSumRangeAffine.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp\"\
    \n\nusing modint = ModInt<998244353>;\n\nint main(void){\n    int N,Q;\n\tscanf(\"\
    %d %d\",&N,&Q);\n\tLazyRandomizedBinarySearchTreeSequence<MonoidRangeSumRangeAffine<modint,pair<modint,modint>>\
    \ > rbst;\n    for(int i=0;i<N;++i) {\n\t\tint a; cin >> a;\n\t\trbst.insert(i,a);\n\
    \    }\n    while(Q--) {\n        int q;\n\t\tscanf(\"%d\",&q);\n\t\tif(q==0)\
    \ {\n\t\t\tint i,x;\n\t\t\tscanf(\"%d %d\",&i,&x);\n\t\t\trbst.insert(i,x);\n\t\
    \t}\n\t\tif(q==1) {\n\t\t\tint i;\n\t\t\tscanf(\"%d\",&i);\n\t\t\trbst.erase(i);\n\
    \t\t}\n\t\tif(q==2) {\n\t\t\tint l,r;\n\t\t\tscanf(\"%d %d\",&l,&r);\n\t\t\trbst.reverse(l,r);\n\
    \t\t}\n\t\tif(q==3) {\n\t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d %d %d %d\",&l,&r,&b,&c);\n\
    \t\t\trbst.operate(l,r,{b,c});\n\t\t}\n\t\tif(q==4) {\n\t\t\tint l,r;\n\t\t\t\
    scanf(\"%d %d\",&l,&r);\n\t\t\tprintf(\"%lld\\n\",rbst.fold(l,r).x);\n\t\t}\n\
    \    }\n    return 0; \n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp.html
title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-reverse.test.cpp
---
