---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/60-optimize/MaximumRectangle.cpp
    title: "MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
  bundledCode: "#line 1 \"test/optimize/MaximumRectangle-1.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#line\
    \ 1 \"lib/60-optimize/MaximumRectangle.cpp\"\n/*\n * @title MaximumRectangle -\
    \ \u6700\u5927\u9577\u65B9\u5F62\n * @docs md/optimize/MaximumRectangle.md\n */\n\
    template<class T> long long MaximumRectangle(vector<T> ar){\n\tar.push_back(0);\n\
    \tstack<pair<long long,long long>> st;\n\tlong long res = 0;\n\tfor(long long\
    \ r = 0; r < ar.size(); ++r){\n\t\tlong long vr = ar[r];\n\t\tif(st.empty()){\n\
    \t\t\tst.push({vr,r});\n\t\t\tcontinue;\n\t\t}\n\n\t\tlong long vl = st.top().first,\
    \ l = st.top().second;\n\t\tif(vl < vr) st.push({vr,r});\n\t\tif(vl < vr || vl\
    \ == vr)\tcontinue;\n\t\t\n\t\twhile(vl > vr) {\n\t\t\tres = max(res,vl*(r - l));\n\
    \t\t\tst.pop();\n\n\t\t\tif(st.size() && st.top().first > vr) vl = st.top().first,\
    \ l = st.top().second;\n\t\t\telse break;\n\t\t}\n\t\tst.push({vr,l});\n\t}\n\t\
    ar.pop_back();\n\treturn res;\n}\n#line 8 \"test/optimize/MaximumRectangle-1.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int H,W;\
    \ cin >> H >> W;\n    vector<vector<int>> c(H,vector<int>(W,0));\n    vector<vector<int>>\
    \ s(H,vector<int>(W,0));    \n    for(int i=0;i<H;++i) {\n        for(int j=0;j<W;++j)\
    \ {\n            cin >> c[i][j];\n        }\n    }\n    for(int j=0;j<W;++j) {\n\
    \        s[0][j]=(!c[0][j]);\n        for(int i=1;i<H;++i) {\n            if(c[i][j])\
    \ s[i][j]=0;\n            else s[i][j]=s[i-1][j]+1;\n        }\n    }\n    long\
    \ long ans = 0;\n    for(int i=0;i<H;++i) {\n        ans=max(ans,MaximumRectangle(s[i]));\n\
    \    }\n    cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\nusing namespace\
    \ std;\n#include \"../../lib/60-optimize/MaximumRectangle.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int H,W; cin >> H >> W;\n  \
    \  vector<vector<int>> c(H,vector<int>(W,0));\n    vector<vector<int>> s(H,vector<int>(W,0));\
    \    \n    for(int i=0;i<H;++i) {\n        for(int j=0;j<W;++j) {\n          \
    \  cin >> c[i][j];\n        }\n    }\n    for(int j=0;j<W;++j) {\n        s[0][j]=(!c[0][j]);\n\
    \        for(int i=1;i<H;++i) {\n            if(c[i][j]) s[i][j]=0;\n        \
    \    else s[i][j]=s[i-1][j]+1;\n        }\n    }\n    long long ans = 0;\n   \
    \ for(int i=0;i<H;++i) {\n        ans=max(ans,MaximumRectangle(s[i]));\n    }\n\
    \    cout << ans << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/60-optimize/MaximumRectangle.cpp
  isVerificationFile: true
  path: test/optimize/MaximumRectangle-1.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/optimize/MaximumRectangle-1.test.cpp
layout: document
redirect_from:
- /verify/test/optimize/MaximumRectangle-1.test.cpp
- /verify/test/optimize/MaximumRectangle-1.test.cpp.html
title: test/optimize/MaximumRectangle-1.test.cpp
---