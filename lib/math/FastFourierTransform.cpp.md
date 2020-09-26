---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/math/FastFourierTransform.md
    document_title: "FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\
      \u63DB"
    links: []
  bundledCode: "#line 1 \"lib/math/FastFourierTransform.cpp\"\n/*\n * @title FastFourierTransform\
    \ - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\n * @docs md/math/FastFourierTransform.md\n\
    \ */\nclass FastFourierTransform{\n    inline static constexpr double pi2 = 2.0\
    \ * M_PI;\n    inline static constexpr pair<double,double> mul(const pair<double,double>&\
    \ l,const pair<double,double>& r) {\n        return {(l.first*r.first-l.second*r.second),(l.first*r.second+l.second*r.first)};\n\
    \    }\n    inline static constexpr pair<double,double> add(const pair<double,double>&\
    \ l,const pair<double,double>& r) {\n        return {(l.first+r.first),(l.second+r.second)};\n\
    \    }\n    inline static vector<pair<double,double>> dft(vector<pair<double,double>>\
    \ f, int sgn = 1) {\n        int N = f.size(),M = N/2;\n        if(!M) return\
    \ f;\n        vector<pair<double,double>> g(M), h(M);\n        pair<double,double>\
    \ acc = {1,0},coe = {cos(pi2 / N), sin(pi2 / N)*sgn};\n        for(int i=0; i<M;\
    \ i++) g[i] = f[(i<<1)+0],h[i] = f[(i<<1)+1];\n        g = dft(g, sgn); h = dft(h,\
    \ sgn);\n        for(int i=0; i<N; ++i, acc = mul(acc,coe)) f[i] = add(g[i%M],mul(acc,h[i%M]));\n\
    \        return f;\n    }\n    inline static vector<pair<double,double>> inv(vector<pair<double,double>>\
    \ f) {\n        int N=f.size();\n        f = dft(f,-1);\n        for(int i=0;\
    \ i<N; i++) f[i].first /= N;\n        return f;\n    }\npublic:\n    template<class\
    \ T> inline static vector<pair<double,double>> convolution(const vector<T>& a,const\
    \ vector<T>& b) {\n        int N; for(N=1;N<a.size()+b.size()+1; N<<=1);\n   \
    \     vector<pair<double,double>> f(N),g(N),h(N);\n        for(int i = 0; i <\
    \ a.size(); ++i) g[i]={a[i],0};\n        for(int i = 0; i < b.size(); ++i) h[i]={b[i],0};\n\
    \        g = dft(g); h = dft(h);\n        for(int i=0; i<N; i++) f[i] = mul(g[i],h[i]);\n\
    \        return inv(f);\n    }\n};\n"
  code: "/*\n * @title FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
    \u5909\u63DB\n * @docs md/math/FastFourierTransform.md\n */\nclass FastFourierTransform{\n\
    \    inline static constexpr double pi2 = 2.0 * M_PI;\n    inline static constexpr\
    \ pair<double,double> mul(const pair<double,double>& l,const pair<double,double>&\
    \ r) {\n        return {(l.first*r.first-l.second*r.second),(l.first*r.second+l.second*r.first)};\n\
    \    }\n    inline static constexpr pair<double,double> add(const pair<double,double>&\
    \ l,const pair<double,double>& r) {\n        return {(l.first+r.first),(l.second+r.second)};\n\
    \    }\n    inline static vector<pair<double,double>> dft(vector<pair<double,double>>\
    \ f, int sgn = 1) {\n        int N = f.size(),M = N/2;\n        if(!M) return\
    \ f;\n        vector<pair<double,double>> g(M), h(M);\n        pair<double,double>\
    \ acc = {1,0},coe = {cos(pi2 / N), sin(pi2 / N)*sgn};\n        for(int i=0; i<M;\
    \ i++) g[i] = f[(i<<1)+0],h[i] = f[(i<<1)+1];\n        g = dft(g, sgn); h = dft(h,\
    \ sgn);\n        for(int i=0; i<N; ++i, acc = mul(acc,coe)) f[i] = add(g[i%M],mul(acc,h[i%M]));\n\
    \        return f;\n    }\n    inline static vector<pair<double,double>> inv(vector<pair<double,double>>\
    \ f) {\n        int N=f.size();\n        f = dft(f,-1);\n        for(int i=0;\
    \ i<N; i++) f[i].first /= N;\n        return f;\n    }\npublic:\n    template<class\
    \ T> inline static vector<pair<double,double>> convolution(const vector<T>& a,const\
    \ vector<T>& b) {\n        int N; for(N=1;N<a.size()+b.size()+1; N<<=1);\n   \
    \     vector<pair<double,double>> f(N),g(N),h(N);\n        for(int i = 0; i <\
    \ a.size(); ++i) g[i]={a[i],0};\n        for(int i = 0; i < b.size(); ++i) h[i]={b[i],0};\n\
    \        g = dft(g); h = dft(h);\n        for(int i=0; i<N; i++) f[i] = mul(g[i],h[i]);\n\
    \        return inv(f);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/FastFourierTransform.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:29:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/FastFourierTransform.cpp
layout: document
redirect_from:
- /library/lib/math/FastFourierTransform.cpp
- /library/lib/math/FastFourierTransform.cpp.html
title: "FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
---
