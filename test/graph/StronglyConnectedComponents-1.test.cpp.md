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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1023\"\n\n#include <vector>\n\
    #include <iostream>\n#include <numeric>\n#include <algorithm>\n#include <stack>\n\
    using namespace std;\n#include \"../../lib/40-graph/UnionFindTree.cpp\"\n#include\
    \ \"../../lib/40-graph/StronglyConnectedComponents.cpp\"\n\nint main(){\n    int\
    \ N,M; cin >> N >> M;\n    vector<pair<int,int>> edge;\n    vector<pair<int,int>>\
    \ bedge;\n    for(int i = 0; i < M; ++i) {\n        int a,b; cin >> a >> b;\n\
    \        a--,b--;\n        int c; cin >> c;\n        if(c==1){\n            bedge.push_back({a,b});\n\
    \        }\n        else{\n            edge.push_back({a,b});\n        }\n   \
    \ }\n    UnionFindTree uf(N);\n    for(auto& e:bedge){\n        int a = e.first,b\
    \ = e.second;\n        if(uf.connected(a,b)){\n            cout << \"Yes\" <<\
    \ endl;\n            return 0;\n        }\n        uf.merge(a,b);\n    }\n   \
    \ StronglyConnectedComponents scc(N);\n    for(auto& e:edge){\n        int a =\
    \ e.first,b = e.second;\n        if(uf.connected(a,b)){\n            cout << \"\
    Yes\" << endl;\n            return 0;\n        }\n        scc.make_edge(uf[a],uf[b]);\n\
    \    }\n    scc.solve();\n    vector<int> cnt(N,0);\n    for(int i = 0; i < N;\
    \ ++i) cnt[scc[i]]++;\n    for(int i = 0; i < N; ++i) if(cnt[i] > 1){\n      \
    \  cout << \"Yes\" << endl;\n        return 0;\n    }\n    cout << \"No\" << endl;\
    \ \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/StronglyConnectedComponents-1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/StronglyConnectedComponents-1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/StronglyConnectedComponents-1.test.cpp
- /verify/test/graph/StronglyConnectedComponents-1.test.cpp.html
title: test/graph/StronglyConnectedComponents-1.test.cpp
---
