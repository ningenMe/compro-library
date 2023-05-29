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
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp\"\
    \n\n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    LazyRandomizedBinarySearchTreeSequence<MonoidRangeFoldMinRangeOperateUpdate<long\
    \ long,long long>> lbst;\n    int N,Q; cin >> N >> Q;\n    for(int i=0;i<N;++i)\
    \ {\n        int a; cin >> a;\n        lbst.insert(i,a);\n    }\n    while(Q--)\
    \ {\n        int x,y,z; cin >> x >> y >> z;\n        if(x==0) {\n            auto\
    \ w = lbst.get(z);\n            lbst.erase(z);\n            lbst.insert(y,w);\n\
    \        }\n        if(x==1) {\n            cout << lbst.fold(y,z+1) << \"\\n\"\
    ;\n        }\n        if(x==2) {\n            lbst.operate(y,y+1,z);\n       \
    \ }\n    }\n    return 0; \n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
- /verify/test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp.html
title: test/binary-search-tree/LazyRandomizedBinarySearchTreeSequence-insert-erase.test.cpp
---
