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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../lib/data-structure/binary-search-tree/RandomizedBinarySearchTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/409\"\n\n#include <iostream>\n\
    #include <vector>\n#include <queue>\nusing namespace std;\n#include \"../../../lib/data-structure/binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n#include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"../../../lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp\"\
    \nusing ll = long long;\n\nint main(void){\n\tll N,A,B,W; cin >> N >> A >> B >>\
    \ W;\n\tvector<ll> D(N+2,0);\n\tfor(int i = 1; i <= N; ++i) cin >> D[i];\n\t//\
    \ dp[i]=min{j:[0,i)}-> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)\n\t//            \
    \       -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]\n\t//                   -> dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]\n\
    \t//                   -> (-B*j)*i  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i]\
    \ \n\tll dp=W;\n\tConvexHullTrick<ValueMin<ll>> cht;\n\tcht.insert(0,dp);\n\t\
    for(ll i=1;i<=N+1;++i){\n\t\tdp=cht.get(i)+B*(i*i-i)/2-A*(i-1)+D[i];\n\t\tpair<ll,ll>\
    \ line={-B*i,dp+B*(i*i+i)/2+A*i};\n\t\tcht.insert(line);\n\t}\n\tcout << dp <<\
    \ endl;\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp.html
title: test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
---
