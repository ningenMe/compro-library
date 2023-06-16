---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/40-graph/UnionFindTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1170\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    using namespace std;\n#include \"../../lib/00-util/RangeIndex.cpp\"\n#include\
    \ \"../../lib/40-graph/UnionFindTree.cpp\"\n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\
    \    long long N,A,B; cin >> N >> A >> B;\n    vector<long long> X(N);\n    for(int\
    \ i = 0; i < N; ++i) cin >> X[i];\n    X.push_back(1e10);\n    RangeIndex ri(N);\n\
    \    UnionFindTree uf(ri.size());\n    vector<int> st(ri.size(),0);\n    for(int\
    \ i = 0; i < N; ++i) {\n        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();\n\
    \        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();\n        for(auto&\
    \ e:ri.range(l,r)) {\n            st[e]=1;\n            uf.merge(ri[i],e);\n \
    \       }\n    }\n    for(int i = 0; i < N; ++i) {\n        for(auto& e:ri.include_range(i))\
    \ if(st[e]) uf.merge(ri[i],e);\n    }\n    vector<int> cnt(ri.size(),0);\n   \
    \ for(int i = 0; i < N; ++i) {\n        cnt[uf[ri[i]]]++;\n    }\n    for(int\
    \ i = 0; i < N; ++i) {\n        cout << cnt[uf[ri[i]]] << endl;\n    }\n\n   \
    \ return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/util/RangeIndex.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/util/RangeIndex.test.cpp
layout: document
redirect_from:
- /verify/test/util/RangeIndex.test.cpp
- /verify/test/util/RangeIndex.test.cpp.html
title: test/util/RangeIndex.test.cpp
---
