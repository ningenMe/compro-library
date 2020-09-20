---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/FloorSum.cpp
    title: FloorSum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/FloorSum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/math/FloorSum.cpp\"\
    \n/**\n * @title FloorSum\n * O(log(n+m+a+b))\n * \u03A3i:[0,N) floor((a*i+b)/m)\u3092\
    \u8A08\u7B97\u3059\u308B\n * @see \"https://min-25.hatenablog.com/entry/2018/04/27/225535\"\
    \n * @see \"https://min-25.hatenablog.com/entry/2018/05/03/145505\"\n */\ninline\
    \ static long long FloorSum(long long n, long long m, long long a, long long b)\
    \ {\n    long long ret=0;\n    while(1) {\n        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;\n\
    \        if(b >= m) ret += n*(b / m),b%=m;\n        long long y=(a*n+b)/m, x=(y*m-b);\n\
    \        if(y==0) return ret;\n        ret += (n-(x+a-1)/a)*y;\n        b=(a-x%a)%a;\
    \ swap(a,m); n=y;\n    }\n}\n#line 6 \"test/math/FloorSum.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(nullptr);ios::sync_with_stdio(false);\n    int Q; cin >> Q;\n\
    \    while(Q--){\n        long long N,M,A,B; cin >> N >> M >> A >> B;\n      \
    \  cout << FloorSum(N,M,A,B) << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\nusing namespace std;\n#include \"../../lib/math/FloorSum.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);ios::sync_with_stdio(false);\n    int Q;\
    \ cin >> Q;\n    while(Q--){\n        long long N,M,A,B; cin >> N >> M >> A >>\
    \ B;\n        cout << FloorSum(N,M,A,B) << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - lib/math/FloorSum.cpp
  isVerificationFile: true
  path: test/math/FloorSum.test.cpp
  requiredBy: []
  timestamp: '2020-09-08 05:45:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/FloorSum.test.cpp
layout: document
redirect_from:
- /verify/test/math/FloorSum.test.cpp
- /verify/test/math/FloorSum.test.cpp.html
title: test/math/FloorSum.test.cpp
---
