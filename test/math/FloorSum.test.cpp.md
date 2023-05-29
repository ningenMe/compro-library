---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/30-math/FloorSum.cpp
    title: "FloorSum - \u76F4\u7DDA\u9818\u57DF\u306E\u683C\u5B50\u70B9\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/FloorSum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/30-math/FloorSum.cpp\"\
    \n/**\n * @title FloorSum - \u76F4\u7DDA\u9818\u57DF\u306E\u683C\u5B50\u70B9\u6570\
    \n * @docs md/math/FloorSum.md\n */\ninline static long long FloorSum(long long\
    \ n, long long m, long long a, long long b) {\n    long long ret=0;\n    while(1)\
    \ {\n        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;\n        if(b >= m) ret\
    \ += n*(b / m),b%=m;\n        long long y=(a*n+b)/m, x=(y*m-b);\n        if(y==0)\
    \ return ret;\n        ret += (n-(x+a-1)/a)*y;\n        b=(a-x%a)%a; swap(a,m);\
    \ n=y;\n    }\n}\n#line 6 \"test/math/FloorSum.test.cpp\"\n\nint main() {\n  \
    \  cin.tie(nullptr);ios::sync_with_stdio(false);\n    int Q; cin >> Q;\n    while(Q--){\n\
    \        long long N,M,A,B; cin >> N >> M >> A >> B;\n        cout << FloorSum(N,M,A,B)\
    \ << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\nusing namespace std;\n#include \"../../lib/30-math/FloorSum.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);ios::sync_with_stdio(false);\n    int Q;\
    \ cin >> Q;\n    while(Q--){\n        long long N,M,A,B; cin >> N >> M >> A >>\
    \ B;\n        cout << FloorSum(N,M,A,B) << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - lib/30-math/FloorSum.cpp
  isVerificationFile: true
  path: test/math/FloorSum.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/FloorSum.test.cpp
layout: document
redirect_from:
- /verify/test/math/FloorSum.test.cpp
- /verify/test/math/FloorSum.test.cpp.html
title: test/math/FloorSum.test.cpp
---
