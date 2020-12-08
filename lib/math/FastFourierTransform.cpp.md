---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FastFourierTransform.test.cpp
    title: test/math/FastFourierTransform.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/FastFourierTransform.md
    document_title: "FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\
      \u63DB"
    links: []
  bundledCode: "#line 1 \"lib/math/FastFourierTransform.cpp\"\n/*\n * @title FastFourierTransform\
    \ - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\n * @docs md/math/FastFourierTransform.md\n\
    \ */\nclass FastFourierTransform {\n    inline static constexpr int prime1 =1004535809;\n\
    \    inline static constexpr int prime2 =998244353;\n    inline static constexpr\
    \ int prime3 =985661441;\n    inline static constexpr int inv21  =332747959; //\
    \ ModInt<mod2>(mod1).inv().x;\n    inline static constexpr int inv31  =766625513;\
    \ // ModInt<mod3>(mod1).inv().x;\n    inline static constexpr int inv32  =657107549;\
    \ // ModInt<mod3>(mod2).inv().x;\n    inline static constexpr long long prime12=(1002772198720536577LL);\n\
    \    inline static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};\n\
    \    using Mint1 = ModInt<prime1>;\n    using Mint2 = ModInt<prime2>;\n    using\
    \ Mint3 = ModInt<prime3>;\n    inline static long long garner(const Mint1& b1,const\
    \ Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return\
    \ prime12*t3.x+b1.x+prime1*t2.x;}\n    template<int prime> inline static void\
    \ ntt(vector<ModInt<prime>>& f) {\n        const int N = f.size(), M = N>>1;\n\
    \        const int log2_N = __builtin_ctz(N);\n        ModInt<prime> h(3);\n \
    \       vector<ModInt<prime>> g(N),base(log2_N);\n        for(int i=0;i<log2_N;++i)\
    \ base[i] = h.pow((prime - 1)/pow2[i+1]);\n        for(int n=0;n<log2_N;++n) {\n\
    \            const int& p = pow2[log2_N-n-1];\n            ModInt<prime> w = 1;\n\
    \            for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n]) {\n                for(int\
    \ j=0;j<p;++j) {\n                    ModInt<prime> l = f[k|j],r = w*f[k|j|p];\n\
    \                    g[i|j]   = l + r;\n                    g[i|j|M] = l - r;\n\
    \                }\n            }\n            swap(f,g);\n        }\n    }\n\
    \    template<int prime> inline static vector<ModInt<prime>> convolution_friendlymod(const\
    \ vector<long long>& a,const vector<long long>& b){\n        if (min(a.size(),\
    \ b.size()) <= 60) {\n            vector<ModInt<prime>> f(a.size() + b.size()\
    \ - 1);\n            for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size();\
    \ j++) f[i+j]+=a[i]*b[j];\n            return f;\n        }\n        int N,M=a.size()+b.size()-1;\
    \ for(N=1;N<M;N*=2);\n        ModInt<prime> inverse(N); inverse = inverse.inv();\n\
    \        vector<ModInt<prime>> g(N,0),h(N,0);\n        for(int i=0;i<a.size();++i)\
    \ g[i]=a[i];\n        for(int i=0;i<b.size();++i) h[i]=b[i];\n        ntt<prime>(g);\
    \ ntt<prime>(h);\n        for(int i = 0; i < N; ++i) g[i] *= h[i]*inverse;\n \
    \       reverse(g.begin()+1,g.end());\n        ntt<prime>(g);\n        return\
    \ g;\n    }\npublic:\n    inline static vector<long long> convolution(const vector<long\
    \ long>& g,const vector<long long>& h){\n        auto f1 = convolution_friendlymod<prime1>(g,\
    \ h);\n        auto f2 = convolution_friendlymod<prime2>(g, h);\n        auto\
    \ f3 = convolution_friendlymod<prime3>(g, h);\n        vector<long long> f(f1.size());\n\
    \        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n  \
    \      return f;\n    }\n};\n"
  code: "/*\n * @title FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
    \u5909\u63DB\n * @docs md/math/FastFourierTransform.md\n */\nclass FastFourierTransform\
    \ {\n    inline static constexpr int prime1 =1004535809;\n    inline static constexpr\
    \ int prime2 =998244353;\n    inline static constexpr int prime3 =985661441;\n\
    \    inline static constexpr int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;\n\
    \    inline static constexpr int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;\n\
    \    inline static constexpr int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;\n\
    \    inline static constexpr long long prime12=(1002772198720536577LL);\n    inline\
    \ static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};\n\
    \    using Mint1 = ModInt<prime1>;\n    using Mint2 = ModInt<prime2>;\n    using\
    \ Mint3 = ModInt<prime3>;\n    inline static long long garner(const Mint1& b1,const\
    \ Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return\
    \ prime12*t3.x+b1.x+prime1*t2.x;}\n    template<int prime> inline static void\
    \ ntt(vector<ModInt<prime>>& f) {\n        const int N = f.size(), M = N>>1;\n\
    \        const int log2_N = __builtin_ctz(N);\n        ModInt<prime> h(3);\n \
    \       vector<ModInt<prime>> g(N),base(log2_N);\n        for(int i=0;i<log2_N;++i)\
    \ base[i] = h.pow((prime - 1)/pow2[i+1]);\n        for(int n=0;n<log2_N;++n) {\n\
    \            const int& p = pow2[log2_N-n-1];\n            ModInt<prime> w = 1;\n\
    \            for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n]) {\n                for(int\
    \ j=0;j<p;++j) {\n                    ModInt<prime> l = f[k|j],r = w*f[k|j|p];\n\
    \                    g[i|j]   = l + r;\n                    g[i|j|M] = l - r;\n\
    \                }\n            }\n            swap(f,g);\n        }\n    }\n\
    \    template<int prime> inline static vector<ModInt<prime>> convolution_friendlymod(const\
    \ vector<long long>& a,const vector<long long>& b){\n        if (min(a.size(),\
    \ b.size()) <= 60) {\n            vector<ModInt<prime>> f(a.size() + b.size()\
    \ - 1);\n            for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size();\
    \ j++) f[i+j]+=a[i]*b[j];\n            return f;\n        }\n        int N,M=a.size()+b.size()-1;\
    \ for(N=1;N<M;N*=2);\n        ModInt<prime> inverse(N); inverse = inverse.inv();\n\
    \        vector<ModInt<prime>> g(N,0),h(N,0);\n        for(int i=0;i<a.size();++i)\
    \ g[i]=a[i];\n        for(int i=0;i<b.size();++i) h[i]=b[i];\n        ntt<prime>(g);\
    \ ntt<prime>(h);\n        for(int i = 0; i < N; ++i) g[i] *= h[i]*inverse;\n \
    \       reverse(g.begin()+1,g.end());\n        ntt<prime>(g);\n        return\
    \ g;\n    }\npublic:\n    inline static vector<long long> convolution(const vector<long\
    \ long>& g,const vector<long long>& h){\n        auto f1 = convolution_friendlymod<prime1>(g,\
    \ h);\n        auto f2 = convolution_friendlymod<prime2>(g, h);\n        auto\
    \ f3 = convolution_friendlymod<prime3>(g, h);\n        vector<long long> f(f1.size());\n\
    \        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n  \
    \      return f;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/FastFourierTransform.cpp
  requiredBy: []
  timestamp: '2020-12-09 06:18:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/FastFourierTransform.test.cpp
documentation_of: lib/math/FastFourierTransform.cpp
layout: document
redirect_from:
- /library/lib/math/FastFourierTransform.cpp
- /library/lib/math/FastFourierTransform.cpp.html
title: "FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
---
