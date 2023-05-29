---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/60-optimize/LongestIncreasingSubsequence.cpp
    title: LongestIncreasingSubsequence - LIS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"test/optimize/LongestIncreasingSubsequence.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <vector>\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/60-optimize/LongestIncreasingSubsequence.cpp\"\
    \n/*\n * @title LongestIncreasingSubsequence - LIS\n * @docs md/optimize/LongestIncreasingSubsequence.md\n\
    \ */\ntemplate<class T> inline static int LongestIncreasingSubsequence(const vector<T>\
    \ & ar, T inf=3e18) {\n\tvector<T> dp(ar.size(), inf);\n\tfor (int i = 0; i <\
    \ ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];\n\treturn\
    \ distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));\n}\n#line 7 \"\
    test/optimize/LongestIncreasingSubsequence.test.cpp\"\n\nint main(void){\n   \
    \ cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >> N;\n    vector<long\
    \ long> a(N);\n    for(int i=0;i<N;++i) cin >> a[i];\n    cout << LongestIncreasingSubsequence(a)\
    \ << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <vector>\n#include <iostream>\nusing namespace std;\n#include \"\
    ../../lib/60-optimize/LongestIncreasingSubsequence.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >> N;\n    vector<long\
    \ long> a(N);\n    for(int i=0;i<N;++i) cin >> a[i];\n    cout << LongestIncreasingSubsequence(a)\
    \ << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/60-optimize/LongestIncreasingSubsequence.cpp
  isVerificationFile: true
  path: test/optimize/LongestIncreasingSubsequence.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/optimize/LongestIncreasingSubsequence.test.cpp
layout: document
redirect_from:
- /verify/test/optimize/LongestIncreasingSubsequence.test.cpp
- /verify/test/optimize/LongestIncreasingSubsequence.test.cpp.html
title: test/optimize/LongestIncreasingSubsequence.test.cpp
---
