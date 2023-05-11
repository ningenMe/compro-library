---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/optimize/MaximumRectangle.cpp
    title: "MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/optimize/MaximumRectangle-2.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#line\
    \ 1 \"lib/optimize/MaximumRectangle.cpp\"\n/*\n * @title MaximumRectangle - \u6700\
    \u5927\u9577\u65B9\u5F62\n * @docs md/optimize/MaximumRectangle.md\n */\ntemplate<class\
    \ T> long long MaximumRectangle(vector<T> ar){\n\tar.push_back(0);\n\tstack<pair<long\
    \ long,long long>> st;\n\tlong long res = 0;\n\tfor(long long r = 0; r < ar.size();\
    \ ++r){\n\t\tlong long vr = ar[r];\n\t\tif(st.empty()){\n\t\t\tst.push({vr,r});\n\
    \t\t\tcontinue;\n\t\t}\n\n\t\tlong long vl = st.top().first, l = st.top().second;\n\
    \t\tif(vl < vr) st.push({vr,r});\n\t\tif(vl < vr || vl == vr)\tcontinue;\n\t\t\
    \n\t\twhile(vl > vr) {\n\t\t\tres = max(res,vl*(r - l));\n\t\t\tst.pop();\n\n\t\
    \t\tif(st.size() && st.top().first > vr) vl = st.top().first, l = st.top().second;\n\
    \t\t\telse break;\n\t\t}\n\t\tst.push({vr,l});\n\t}\n\tar.pop_back();\n\treturn\
    \ res;\n}\n#line 8 \"test/optimize/MaximumRectangle-2.test.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >> N;\n    vector<long\
    \ long> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    cout << MaximumRectangle(A)\
    \ << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\nusing namespace\
    \ std;\n#include \"../../lib/optimize/MaximumRectangle.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >> N;\n    vector<long\
    \ long> A(N);\n    for(int i=0;i<N;++i) cin >> A[i];\n    cout << MaximumRectangle(A)\
    \ << endl;\n    return 0;\n}"
  dependsOn:
  - lib/optimize/MaximumRectangle.cpp
  isVerificationFile: true
  path: test/optimize/MaximumRectangle-2.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:04:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/optimize/MaximumRectangle-2.test.cpp
layout: document
redirect_from:
- /verify/test/optimize/MaximumRectangle-2.test.cpp
- /verify/test/optimize/MaximumRectangle-2.test.cpp.html
title: test/optimize/MaximumRectangle-2.test.cpp
---
