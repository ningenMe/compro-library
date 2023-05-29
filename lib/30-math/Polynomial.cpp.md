---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/Polynomial.md
    document_title: "Polynomial - \u591A\u9805\u5F0F\u88DC\u9593"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Polynomial.cpp\"\n/*\n * @title Polynomial -\
    \ \u591A\u9805\u5F0F\u88DC\u9593\n * @docs md/math/Polynomial.md\n */\ntemplate<class\
    \ T> class Polynomial{\npublic:\n    //O(N^2)\n    inline static vector<T> interpolation(const\
    \ vector<T>& x,const vector<T>& y) {\n        assert(x.size()==y.size());\n  \
    \      int n = x.size();\n        vector<T> dp(n+1,0),tp(n+1),res(n,0);\n    \
    \    dp[0] = 1;\n        for(int i=0;i<n;++i) {\n            for(int j=0;j<=n;++j)\
    \ tp[j] = 0;\n            for(int j=0;j<=i;++j) {\n                tp[j+0] +=\
    \ dp[j]*(-x[i]);\n                tp[j+1] += dp[j]*1;\n            }\n       \
    \     swap(dp,tp);\n        }\n        for(int i=0;i<n;++i) {\n            if(x[i].x\
    \ == 0) {\n                for(int j=0;j<n;++j) {\n                    tp[j] =\
    \ dp[j+1];\n                }\n            }\n            else {\n           \
    \     T ix = T(1) / x[i];\n                tp[0] = dp[0]*(-ix);\n            \
    \    for(int j=1;j<n;++j) {\n                    tp[j] = (dp[j]-tp[j-1])*(-ix);\n\
    \                }\n            }\n            T base = 1,c = 0;\n           \
    \ for(int j=0;j<n;++j) {\n                c += base*tp[j];\n                base\
    \ *= x[i];\n            }\n            c = y[i] / c;\n            for(int j=0;j<n;++j)\
    \ {\n                res[j] += c*tp[j];\n            }\n        }\n        return\
    \ res;\n    }\n    //O(N \\log mod)\n    inline static T interpolation_arithmetic(const\
    \ T a0,const T d, const vector<T>& y,const T x) {\n        int n = y.size();\n\
    \        T gx = 1,fx = 0;\n        vector<T> gxi(n,1);\n        for(int i=0;i<n;++i)\
    \ gx *= x-(a0 + d*i);\n        for(int i=1;i<n;++i) gxi[0] *= (-d*i);\n      \
    \  for(int i=1;i<n;++i) gxi[i] = gxi[i-1] * (d*i) / (d*(i-n));\n        for(int\
    \ i=0;i<n;++i) fx += (y[i] / gxi[i]) * (gx / (x - (a0 + d*i)));\n        return\
    \ fx;\n    }\n    //O(N)\n    inline static T eval(const vector<T>& f,T x) {\n\
    \        T base = 1, res = 0;\n        for(int i=0;i<f.size(); ++i) {\n      \
    \      res += base*f[i];\n            base *= x;\n        }\n        return res;\n\
    \    }\n};\n"
  code: "/*\n * @title Polynomial - \u591A\u9805\u5F0F\u88DC\u9593\n * @docs md/math/Polynomial.md\n\
    \ */\ntemplate<class T> class Polynomial{\npublic:\n    //O(N^2)\n    inline static\
    \ vector<T> interpolation(const vector<T>& x,const vector<T>& y) {\n        assert(x.size()==y.size());\n\
    \        int n = x.size();\n        vector<T> dp(n+1,0),tp(n+1),res(n,0);\n  \
    \      dp[0] = 1;\n        for(int i=0;i<n;++i) {\n            for(int j=0;j<=n;++j)\
    \ tp[j] = 0;\n            for(int j=0;j<=i;++j) {\n                tp[j+0] +=\
    \ dp[j]*(-x[i]);\n                tp[j+1] += dp[j]*1;\n            }\n       \
    \     swap(dp,tp);\n        }\n        for(int i=0;i<n;++i) {\n            if(x[i].x\
    \ == 0) {\n                for(int j=0;j<n;++j) {\n                    tp[j] =\
    \ dp[j+1];\n                }\n            }\n            else {\n           \
    \     T ix = T(1) / x[i];\n                tp[0] = dp[0]*(-ix);\n            \
    \    for(int j=1;j<n;++j) {\n                    tp[j] = (dp[j]-tp[j-1])*(-ix);\n\
    \                }\n            }\n            T base = 1,c = 0;\n           \
    \ for(int j=0;j<n;++j) {\n                c += base*tp[j];\n                base\
    \ *= x[i];\n            }\n            c = y[i] / c;\n            for(int j=0;j<n;++j)\
    \ {\n                res[j] += c*tp[j];\n            }\n        }\n        return\
    \ res;\n    }\n    //O(N \\log mod)\n    inline static T interpolation_arithmetic(const\
    \ T a0,const T d, const vector<T>& y,const T x) {\n        int n = y.size();\n\
    \        T gx = 1,fx = 0;\n        vector<T> gxi(n,1);\n        for(int i=0;i<n;++i)\
    \ gx *= x-(a0 + d*i);\n        for(int i=1;i<n;++i) gxi[0] *= (-d*i);\n      \
    \  for(int i=1;i<n;++i) gxi[i] = gxi[i-1] * (d*i) / (d*(i-n));\n        for(int\
    \ i=0;i<n;++i) fx += (y[i] / gxi[i]) * (gx / (x - (a0 + d*i)));\n        return\
    \ fx;\n    }\n    //O(N)\n    inline static T eval(const vector<T>& f,T x) {\n\
    \        T base = 1, res = 0;\n        for(int i=0;i<f.size(); ++i) {\n      \
    \      res += base*f[i];\n            base *= x;\n        }\n        return res;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Polynomial.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/30-math/Polynomial.cpp
layout: document
redirect_from:
- /library/lib/30-math/Polynomial.cpp
- /library/lib/30-math/Polynomial.cpp.html
title: "Polynomial - \u591A\u9805\u5F0F\u88DC\u9593"
---
### Polynomial
- 多項式のライブラリ
  - 現状、多項式補間しかない
  - Fpsは別ライブラリなので、そっちを参照

### コンストラクタ
- なし

### メソッド
- vector<T> interpolation(const vector<T>& x,const vector<T>& y)
  - 多項式補間。
  - $O(N^2)$
- T interpolation_arithmetic(const T a0,const T d, const vector<T>& y,const T x)
  - 等差数列での多項式補間
  - f(x_i)=y_iとなるx_iが等差数列のときの多項式補間。より速いオーダーで解ける
  - $O(N /log mod)$
  
### 参考資料
- [ラグランジュ補間](https://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93)
- [見たことのない多項式](https://atcoder.jp/contests/arc033/tasks/arc033_4)
- [Interpolation](https://snuke.hatenablog.com/entry/2014/08/14/031418)