---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-exp.test.cpp
    title: test/math/FormalPowerSeries-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-interpolation.test.cpp
    title: test/math/FormalPowerSeries-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-inv.test.cpp
    title: test/math/FormalPowerSeries-inv.test.cpp
  - icon: ':x:'
    path: test/math/FormalPowerSeries-log.test.cpp
    title: test/math/FormalPowerSeries-log.test.cpp
  - icon: ':x:'
    path: test/math/FormalPowerSeries-multi-eval.test.cpp
    title: test/math/FormalPowerSeries-multi-eval.test.cpp
  - icon: ':x:'
    path: test/math/FormalPowerSeries-nth.test.cpp
    title: test/math/FormalPowerSeries-nth.test.cpp
  - icon: ':x:'
    path: test/math/FormalPowerSeries-pow.test.cpp
    title: test/math/FormalPowerSeries-pow.test.cpp
  - icon: ':x:'
    path: test/math/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
    title: test/math/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
  - icon: ':x:'
    path: test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
    title: test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  - icon: ':x:'
    path: test/math/NumberTheoreticalTransform-conv-998244353-2.test.cpp
    title: test/math/NumberTheoreticalTransform-conv-998244353-2.test.cpp
  - icon: ':x:'
    path: test/math/NumberTheoreticalTransform-conv-fft.test.cpp
    title: test/math/NumberTheoreticalTransform-conv-fft.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/math/NumberTheoreticalTransform.md
    document_title: "NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"lib/math/NumberTheoreticalTransform.cpp\"\n/*\n * @title\
    \ NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB\n * @docs md/math/NumberTheoreticalTransform.md\n\
    \ */\ntemplate<class T> class NumberTheoreticalTransform {\n    inline static\
    \ constexpr int prime1 =1004535809;\n    inline static constexpr int prime2 =998244353;\n\
    \    inline static constexpr int prime3 =985661441;\n    inline static constexpr\
    \ int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;\n    inline static constexpr\
    \ int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;\n    inline static constexpr\
    \ int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;\n    inline static constexpr\
    \ long long prime12=(1002772198720536577LL);\n    inline static constexpr int\
    \ log2n_max = 21;\n    using Mint  = T;\n    using Mint1 = ModInt<prime1>;\n \
    \   using Mint2 = ModInt<prime2>;\n    using Mint3 = ModInt<prime3>;\n    inline\
    \ static Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2\
    \ = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(Mint(prime12)*t3.x+b1.x+prime1*t2.x);}\n\
    \    template<int prime> inline static array<ModInt<prime>,log2n_max> get_base(int\
    \ inv=0) {\n        array<ModInt<prime>,log2n_max> base, es, ies;\n        ModInt<prime>\
    \ e = ModInt<prime>(3).pow((prime - 1) >> log2n_max), ie = e.inv();\n        for\
    \ (int i = log2n_max; i >= 2; --i) {\n            es[i - 2]  = e, ies[i - 2] =\
    \ ie;\n            e *= e, ie *= ie;\n        }\n        ModInt<prime> acc = 1;\n\
    \        if(!inv) for (int i = 0; i < log2n_max - 2; ++i) {\n                base[i]\
    \ = es[i] * acc;\n                acc *= ies[i];\n            }\n        else\
    \ for (int i = 0; i < log2n_max - 2; ++i) {\n                base[i] = ies[i]\
    \ * acc;\n                acc *= es[i];\n            }\n        return base;\n\
    \    }\n    template<int prime> inline static void butterfly(vector<ModInt<prime>>&\
    \ a, const array<ModInt<prime>,log2n_max>& base) {\n        int h = __builtin_ctz(a.size());\n\
    \        for (int i = 0; i < h; i++) {\n            int w = 1 << i, p = 1 << (h\
    \ - (i+1));\n            ModInt<prime> acc = 1;\n            for (int s = 0; s\
    \ < w; s++) {\n                int offset = s << (h - i);\n                for\
    \ (int j = 0; j < p; ++j) {\n                    auto l = a[j + offset];\n   \
    \                 auto r = a[j + offset + p] * acc;\n                    a[j +\
    \ offset] = l + r;\n                    a[j + offset + p] = l - r;\n         \
    \       }\n                acc *= base[__builtin_ctz(~(unsigned int)(s))];\n \
    \           }\n        }\n    }\n    template<int prime> inline static void ibutterfly(vector<ModInt<prime>>&\
    \ a, const array<ModInt<prime>,log2n_max>& base) {\n        int h = __builtin_ctz(a.size());\n\
    \        for (int i = h-1; 0 <= i; i--) {\n            int w = 1 << i, p = 1 <<\
    \ (h - (i+1));\n            ModInt<prime> acc = 1;\n            for (int s = 0;\
    \ s < w; s++) {\n                int offset = s << (h - i);\n                for\
    \ (int j = 0; j < p; ++j) {\n                    auto l = a[j + offset];\n   \
    \                 auto r = a[j + offset + p];\n                    a[j + offset]\
    \ = l + r;\n                    a[j + offset + p] = (l - r) * acc;\n         \
    \       }\n                acc *= base[__builtin_ctz(~(unsigned int)(s))];\n \
    \           }\n        }\n    }\n    template<int prime> inline static vector<ModInt<prime>>\
    \ convolution_friendrymod(vector<Mint> a,vector<Mint> b){\n        int n = a.size(),\
    \ m = b.size();\n        if (!n || !m) return {};\n        if (min(n, m) <= 60)\
    \ {\n            if (n < m) swap(n, m),swap(a, b);\n            vector<ModInt<prime>>\
    \ f(n+m-1);\n            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)\
    \ f[i+j]+=a[i].x*b[j].x;\n            return f;\n        }\n\n        int N,M=n+m-1;\
    \ for(N=1;N<M;N*=2);\n        ModInt<prime> inverse(N); inverse = inverse.inv();\n\
    \        vector<ModInt<prime>> g(N,0),h(N,0);\n        for(int i=0;i<a.size();++i)\
    \ g[i]=a[i].x;\n        for(int i=0;i<b.size();++i) h[i]=b[i].x;\n\n        static\
    \ array<ModInt<prime>,log2n_max> base;\n        if(!base.front().x) base = get_base<prime>();\n\
    \        static array<ModInt<prime>,log2n_max> ibase;\n        if(!ibase.front().x)\
    \ ibase = get_base<prime>(1);\n\n        butterfly<prime>(g,base);\n        butterfly<prime>(h,base);\n\
    \        for(int i = 0; i < N; ++i) g[i] *= h[i];\n        ibutterfly<prime>(g,ibase);\n\
    \        for (int i = 0; i < n + m - 1; i++) g[i] *= inverse;\n        return\
    \ g;\n    }\n    inline static vector<Mint> convolution_arbitrarymod(const vector<Mint>&\
    \ g,const vector<Mint>& h){\n        auto f1 = convolution_friendrymod<prime1>(g,\
    \ h);\n        auto f2 = convolution_friendrymod<prime2>(g, h);\n        auto\
    \ f3 = convolution_friendrymod<prime3>(g, h);\n\n        vector<Mint> f(f1.size());\n\
    \        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n  \
    \      return f;\n    }\npublic:\n    inline static vector<long long> convolution(const\
    \ vector<long long>& g,const vector<long long>& h) {\n        vector<T> a(g.size()),b(h.size());\n\
    \        for(int i=0;i<a.size();++i) a[i]=T(g[i]);\n        for(int i=0;i<b.size();++i)\
    \ b[i]=T(h[i]);\n        auto f1 = convolution_friendrymod<prime1>(a, b);\n  \
    \      auto f2 = convolution_friendrymod<prime2>(a, b);\n        auto f3 = convolution_friendrymod<prime3>(a,\
    \ b);\n        vector<long long> f(f1.size());\n        for(int i=0; i<f1.size();\
    \ ++i) f[i] = garner(f1[i],f2[i],f3[i]).x;\n        return f;\n    }\n    inline\
    \ static vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>&\
    \ g,const vector<ModInt<998244353>>& h){return convolution_friendrymod<998244353>(g,h);}\n\
    \    inline static vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>&\
    \ g,const vector<ModInt<1000000007>>& h){return convolution_arbitrarymod(g,h);}\n\
    \    // inline vector<RuntimeModInt<runtime_mod>> convolution(const vector<RuntimeModInt<runtime_mod>>&\
    \ g,const vector<RuntimeModInt<runtime_mod>>& h){return convolution_arbitrarymod(g,h);}\n\
    };\n"
  code: "/*\n * @title NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB\n * @docs\
    \ md/math/NumberTheoreticalTransform.md\n */\ntemplate<class T> class NumberTheoreticalTransform\
    \ {\n    inline static constexpr int prime1 =1004535809;\n    inline static constexpr\
    \ int prime2 =998244353;\n    inline static constexpr int prime3 =985661441;\n\
    \    inline static constexpr int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;\n\
    \    inline static constexpr int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;\n\
    \    inline static constexpr int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;\n\
    \    inline static constexpr long long prime12=(1002772198720536577LL);\n    inline\
    \ static constexpr int log2n_max = 21;\n    using Mint  = T;\n    using Mint1\
    \ = ModInt<prime1>;\n    using Mint2 = ModInt<prime2>;\n    using Mint3 = ModInt<prime3>;\n\
    \    inline static Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3)\
    \ {Mint2 t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(Mint(prime12)*t3.x+b1.x+prime1*t2.x);}\n\
    \    template<int prime> inline static array<ModInt<prime>,log2n_max> get_base(int\
    \ inv=0) {\n        array<ModInt<prime>,log2n_max> base, es, ies;\n        ModInt<prime>\
    \ e = ModInt<prime>(3).pow((prime - 1) >> log2n_max), ie = e.inv();\n        for\
    \ (int i = log2n_max; i >= 2; --i) {\n            es[i - 2]  = e, ies[i - 2] =\
    \ ie;\n            e *= e, ie *= ie;\n        }\n        ModInt<prime> acc = 1;\n\
    \        if(!inv) for (int i = 0; i < log2n_max - 2; ++i) {\n                base[i]\
    \ = es[i] * acc;\n                acc *= ies[i];\n            }\n        else\
    \ for (int i = 0; i < log2n_max - 2; ++i) {\n                base[i] = ies[i]\
    \ * acc;\n                acc *= es[i];\n            }\n        return base;\n\
    \    }\n    template<int prime> inline static void butterfly(vector<ModInt<prime>>&\
    \ a, const array<ModInt<prime>,log2n_max>& base) {\n        int h = __builtin_ctz(a.size());\n\
    \        for (int i = 0; i < h; i++) {\n            int w = 1 << i, p = 1 << (h\
    \ - (i+1));\n            ModInt<prime> acc = 1;\n            for (int s = 0; s\
    \ < w; s++) {\n                int offset = s << (h - i);\n                for\
    \ (int j = 0; j < p; ++j) {\n                    auto l = a[j + offset];\n   \
    \                 auto r = a[j + offset + p] * acc;\n                    a[j +\
    \ offset] = l + r;\n                    a[j + offset + p] = l - r;\n         \
    \       }\n                acc *= base[__builtin_ctz(~(unsigned int)(s))];\n \
    \           }\n        }\n    }\n    template<int prime> inline static void ibutterfly(vector<ModInt<prime>>&\
    \ a, const array<ModInt<prime>,log2n_max>& base) {\n        int h = __builtin_ctz(a.size());\n\
    \        for (int i = h-1; 0 <= i; i--) {\n            int w = 1 << i, p = 1 <<\
    \ (h - (i+1));\n            ModInt<prime> acc = 1;\n            for (int s = 0;\
    \ s < w; s++) {\n                int offset = s << (h - i);\n                for\
    \ (int j = 0; j < p; ++j) {\n                    auto l = a[j + offset];\n   \
    \                 auto r = a[j + offset + p];\n                    a[j + offset]\
    \ = l + r;\n                    a[j + offset + p] = (l - r) * acc;\n         \
    \       }\n                acc *= base[__builtin_ctz(~(unsigned int)(s))];\n \
    \           }\n        }\n    }\n    template<int prime> inline static vector<ModInt<prime>>\
    \ convolution_friendrymod(vector<Mint> a,vector<Mint> b){\n        int n = a.size(),\
    \ m = b.size();\n        if (!n || !m) return {};\n        if (min(n, m) <= 60)\
    \ {\n            if (n < m) swap(n, m),swap(a, b);\n            vector<ModInt<prime>>\
    \ f(n+m-1);\n            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)\
    \ f[i+j]+=a[i].x*b[j].x;\n            return f;\n        }\n\n        int N,M=n+m-1;\
    \ for(N=1;N<M;N*=2);\n        ModInt<prime> inverse(N); inverse = inverse.inv();\n\
    \        vector<ModInt<prime>> g(N,0),h(N,0);\n        for(int i=0;i<a.size();++i)\
    \ g[i]=a[i].x;\n        for(int i=0;i<b.size();++i) h[i]=b[i].x;\n\n        static\
    \ array<ModInt<prime>,log2n_max> base;\n        if(!base.front().x) base = get_base<prime>();\n\
    \        static array<ModInt<prime>,log2n_max> ibase;\n        if(!ibase.front().x)\
    \ ibase = get_base<prime>(1);\n\n        butterfly<prime>(g,base);\n        butterfly<prime>(h,base);\n\
    \        for(int i = 0; i < N; ++i) g[i] *= h[i];\n        ibutterfly<prime>(g,ibase);\n\
    \        for (int i = 0; i < n + m - 1; i++) g[i] *= inverse;\n        return\
    \ g;\n    }\n    inline static vector<Mint> convolution_arbitrarymod(const vector<Mint>&\
    \ g,const vector<Mint>& h){\n        auto f1 = convolution_friendrymod<prime1>(g,\
    \ h);\n        auto f2 = convolution_friendrymod<prime2>(g, h);\n        auto\
    \ f3 = convolution_friendrymod<prime3>(g, h);\n\n        vector<Mint> f(f1.size());\n\
    \        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n  \
    \      return f;\n    }\npublic:\n    inline static vector<long long> convolution(const\
    \ vector<long long>& g,const vector<long long>& h) {\n        vector<T> a(g.size()),b(h.size());\n\
    \        for(int i=0;i<a.size();++i) a[i]=T(g[i]);\n        for(int i=0;i<b.size();++i)\
    \ b[i]=T(h[i]);\n        auto f1 = convolution_friendrymod<prime1>(a, b);\n  \
    \      auto f2 = convolution_friendrymod<prime2>(a, b);\n        auto f3 = convolution_friendrymod<prime3>(a,\
    \ b);\n        vector<long long> f(f1.size());\n        for(int i=0; i<f1.size();\
    \ ++i) f[i] = garner(f1[i],f2[i],f3[i]).x;\n        return f;\n    }\n    inline\
    \ static vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>&\
    \ g,const vector<ModInt<998244353>>& h){return convolution_friendrymod<998244353>(g,h);}\n\
    \    inline static vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>&\
    \ g,const vector<ModInt<1000000007>>& h){return convolution_arbitrarymod(g,h);}\n\
    \    // inline vector<RuntimeModInt<runtime_mod>> convolution(const vector<RuntimeModInt<runtime_mod>>&\
    \ g,const vector<RuntimeModInt<runtime_mod>>& h){return convolution_arbitrarymod(g,h);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/NumberTheoreticalTransform.cpp
  requiredBy: []
  timestamp: '2021-09-21 19:35:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/FormalPowerSeries-exp.test.cpp
  - test/math/FormalPowerSeries-pow.test.cpp
  - test/math/FormalPowerSeries-interpolation.test.cpp
  - test/math/FormalPowerSeries-multi-eval.test.cpp
  - test/math/NumberTheoreticalTransform-conv-998244353-2.test.cpp
  - test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  - test/math/FormalPowerSeries-inv.test.cpp
  - test/math/FormalPowerSeries-log.test.cpp
  - test/math/NumberTheoreticalTransform-conv-fft.test.cpp
  - test/math/FormalPowerSeries-nth.test.cpp
  - test/math/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
documentation_of: lib/math/NumberTheoreticalTransform.cpp
layout: document
redirect_from:
- /library/lib/math/NumberTheoreticalTransform.cpp
- /library/lib/math/NumberTheoreticalTransform.cpp.html
title: "NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB"
---
### NumberTheoreticalTransform
- 多項式の畳込みを行う

### コンストラクタ
- なし

### メソッド
- vector<long long> convolution(const vector<long long>& g,const vector<long long>& h)
  - modを取らないときに、畳み込みを返すメソッド。大きいmodintで動作させると良い。内部的にはnttを行っていて、3回畳み込んでいるため定数倍は重め。
- vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>& h)
  - mod 998244353で良いときに畳み込みを返すメソッド。定数倍はふつう。
- vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>& g,const vector<ModInt<1000000007>>& h)
  - mod 1000000007で良いときに畳み込みを返すメソッド。大きいmodintで動作させると良い。内部的にはnttを行っていて、3回畳み込んでいるため定数倍は重め。

### 参考資料
- [高速フーリエ変換](https://atcoder.jp/contests/atc001/tasks/fft_c)
- [Convolution](https://atcoder.github.io/ac-library/production/document_ja/convolution.html)