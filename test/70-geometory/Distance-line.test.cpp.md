---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/70-geometory/Distance.cpp
    title: "Distance - \u8DDD\u96E2"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1041
    links:
    - https://yukicoder.me/problems/no/1041
  bundledCode: "#line 1 \"test/70-geometory/Distance-line.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1041\"\n\n#include <iostream>\n#include <vector>\n\
    #include <cmath>\nusing namespace std;\n#line 1 \"lib/70-geometory/Distance.cpp\"\
    \n/*\n * @title Distance - \u8DDD\u96E2\n * @docs md/geometory/Distance.md\n */\n\
    template<class T> class Distance{\npublic:\n    //Euclidean distance\n    inline\
    \ static constexpr T euclid(const T& x1, const T& y1, const T& x2, const T& y2)\
    \ {\n        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));\n    }\n\
    \    //Chebyshev distance\n    inline static constexpr T chebyshev(T x1, T y1,\
    \ T x2, T y2) {\n        return max(abs(x1 - x2),abs(y1 - y2));\n    }\n    //Manhattan\
    \ distance\n    inline static constexpr T manhattan(T x1, T y1, T x2, T y2) {\n\
    \        return abs(x1 - x2)+abs(y1 - y2);\n    }\n    inline static constexpr\
    \ T between_point_and_line(const T& x,const T& y,const T& x1,const T& y1,const\
    \ T& x2,const T& y2){\n        return abs((y2 - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2\
    \ - y1)*(y2 - y1)+(x1 - x2)*(x1 - x2));\n    }\n};\n#line 8 \"test/70-geometory/Distance-line.test.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<double> x(N),y(N);\n   \
    \ for(int i = 0; i < N; ++i) {\n        cin >> x[i] >> y[i];\n    }\n    int ans\
    \ = 0;\n    for(int i = 0; i < N; ++i) {\n        for(int j = i+1; j < N; ++j)\
    \ {\n            int cnt = 2;\n            for(int k = 0; k < N; ++k){\n     \
    \           if(k==i || k == j) continue;\n                if(Distance<long double>::between_point_and_line(x[i],y[i],x[j],y[j],x[k],y[k])\
    \ < 1e-3 ) cnt++;\n            }\n            ans = max(ans,cnt);\n        }\n\
    \    }\n    cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1041\"\n\n#include <iostream>\n\
    #include <vector>\n#include <cmath>\nusing namespace std;\n#include \"../../lib/70-geometory/Distance.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<double> x(N),y(N);\n   \
    \ for(int i = 0; i < N; ++i) {\n        cin >> x[i] >> y[i];\n    }\n    int ans\
    \ = 0;\n    for(int i = 0; i < N; ++i) {\n        for(int j = i+1; j < N; ++j)\
    \ {\n            int cnt = 2;\n            for(int k = 0; k < N; ++k){\n     \
    \           if(k==i || k == j) continue;\n                if(Distance<long double>::between_point_and_line(x[i],y[i],x[j],y[j],x[k],y[k])\
    \ < 1e-3 ) cnt++;\n            }\n            ans = max(ans,cnt);\n        }\n\
    \    }\n    cout << ans << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/70-geometory/Distance.cpp
  isVerificationFile: true
  path: test/70-geometory/Distance-line.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/70-geometory/Distance-line.test.cpp
layout: document
redirect_from:
- /verify/test/70-geometory/Distance-line.test.cpp
- /verify/test/70-geometory/Distance-line.test.cpp.html
title: test/70-geometory/Distance-line.test.cpp
---
