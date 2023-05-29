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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\n#include <algorithm>\n\
    using namespace std;\n#include \"../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\
    \n#include \"../../../lib/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp\"\
    \n\nint main(void){\n    int N,Q;\n    scanf(\"%d %d\",&N,&Q);\n    vector<long\
    \ long> X(N+Q,0),Y(N+Q,0),W(N+Q,0);\n    vector<int> A(Q),L(Q),D(Q),R(Q),U(Q);\n\
    \    for(int i=0;i<N;++i) scanf(\"%d %d %d\",&X[i],&Y[i],&W[i]);\n    for(int\
    \ i=0;i<Q;++i) {\n        scanf(\"%d\",&A[i]);\n        if(A[i]==0) scanf(\"%d\
    \ %d %d\",&X[i+N],&Y[i+N],&W[i+N]);\n        else scanf(\"%d %d %d %d\",&L[i],&D[i],&R[i],&U[i]);\n\
    \    }\n    BinaryIndexedTreeOffline2D<AbelPrefixSumPointAdd<long long>> bit(X,Y);\n\
    \    for(int i=0;i<N;++i) bit.operate(X[i],Y[i],W[i]);\n    for(int i=0;i<Q;++i)\
    \ {\n        if(A[i]==0) bit.operate(X[i+N],Y[i+N],W[i+N]);\n        else printf(\"\
    %lld\\n\",bit.fold(L[i],R[i],D[i],U[i]));\n    }\n    return 0; \n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
- /verify/test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp.html
title: test/data-structure/binary-indexed-tree/BinaryIndexedTreeOffline2D-2.test.cpp
---
