---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-998244353-1.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-998244353-2.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-998244353-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/NumberTheoreticalTransform-conv-fft.test.cpp
    title: test/convolution/NumberTheoreticalTransform-conv-fft.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-exp.test.cpp
    title: test/polynomial/FormalPowerSeries-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-interpolation.test.cpp
    title: test/polynomial/FormalPowerSeries-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-inv.test.cpp
    title: test/polynomial/FormalPowerSeries-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-log.test.cpp
    title: test/polynomial/FormalPowerSeries-log.test.cpp
  - icon: ':x:'
    path: test/polynomial/FormalPowerSeries-multi-eval.test.cpp
    title: test/polynomial/FormalPowerSeries-multi-eval.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/FormalPowerSeries-nth.test.cpp
    title: test/polynomial/FormalPowerSeries-nth.test.cpp
  - icon: ':x:'
    path: test/polynomial/FormalPowerSeries-pow.test.cpp
    title: test/polynomial/FormalPowerSeries-pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/convolution/NumberTheoreticalTransform.md
    document_title: "NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"lib/31-convolution/NumberTheoreticalTransform.cpp\"\n/*\n\
    \ * @title NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB\n * @docs md/convolution/NumberTheoreticalTransform.md\n\
    \ */\ntemplate<long long mod> class NumberTheoreticalTransform {\n    inline static\
    \ constexpr int prime_1004535809 =1004535809;\n    inline static constexpr int\
    \ prime_998244353  =998244353;\n    inline static constexpr int prime_985661441\
    \  =985661441;\n    inline static constexpr int prime_998244353_1004535809 = ModInt<prime_998244353>(prime_1004535809).inv().x;\n\
    \    inline static constexpr int prime_985661441_1004535809 = ModInt<prime_985661441>(prime_1004535809).inv().x;\n\
    \    inline static constexpr int prime_985661441_998244353 = ModInt<prime_985661441>(prime_998244353).inv().x;\n\
    \    inline static constexpr long long prime12=((long long)prime_1004535809) *\
    \ prime_998244353;\n    inline static constexpr int log2n_max = 21;\n    template<int\
    \ prime> inline static constexpr array<ModInt<prime>,log2n_max> get_pow2_inv()\
    \ {\n        array<ModInt<prime>,log2n_max>  ar;\n        ModInt<prime> v=1; ar[0]=v;\n\
    \        for(int i=1;i<log2n_max;++i) ar[i]=ar[i-1]/2;\n        return ar;\n \
    \   }\n    inline static constexpr array<ModInt<prime_1004535809>,log2n_max> pow2_inv_1004535809\
    \ = get_pow2_inv<prime_1004535809>();\n    inline static constexpr array<ModInt<prime_998244353>,\
    \ log2n_max> pow2_inv_998244353  = get_pow2_inv<prime_998244353>();\n    inline\
    \ static constexpr array<ModInt<prime_985661441>, log2n_max> pow2_inv_985661441\
    \  = get_pow2_inv<prime_985661441>();\n\n    template<int prime> inline static\
    \ constexpr array<ModInt<prime>,log2n_max> get_base(int inv=0) {\n        array<ModInt<prime>,log2n_max>\
    \ base, es, ies;\n        //TODO 3\u306E\u30CF\u30FC\u30C9\u30B3\u30FC\u30C7\u30A3\
    \u30F3\u30B0\u3092\u76F4\u3059\n        ModInt<prime> e = ModInt<prime>(3).pow((prime\
    \ - 1) >> log2n_max), ie = e.inv();\n        for (int i = log2n_max; i >= 2; --i)\
    \ {\n            es[i - 2]  = e, ies[i - 2] = ie;\n            e *= e, ie *= ie;\n\
    \        }\n        ModInt<prime> acc = 1;\n        if(!inv) {\n            for\
    \ (int i = 0; i < log2n_max - 2; ++i) {\n                base[i] = es[i] * acc;\n\
    \                acc *= ies[i];\n            }\n        }\n        else {\n  \
    \          for (int i = 0; i < log2n_max - 2; ++i) {\n                base[i]\
    \ = ies[i] * acc;\n                acc *= es[i];\n            }\n        }\n \
    \       return base;\n    }\n    inline static constexpr array<ModInt<prime_1004535809>,log2n_max>\
    \ base_1004535809=get_base<prime_1004535809>();\n    inline static constexpr array<ModInt<prime_1004535809>,log2n_max>\
    \ ibase_1004535809=get_base<prime_1004535809>(1);\n    inline static constexpr\
    \ array<ModInt<prime_998244353>,log2n_max> base_998244353=get_base<prime_998244353>();\n\
    \    inline static constexpr array<ModInt<prime_998244353>,log2n_max> ibase_998244353=get_base<prime_998244353>(1);\n\
    \    inline static constexpr array<ModInt<prime_985661441>,log2n_max> base_985661441=get_base<prime_985661441>();\n\
    \    inline static constexpr array<ModInt<prime_985661441>,log2n_max> ibase_985661441=get_base<prime_985661441>(1);\n\
    \n    using Mint1 = ModInt<prime_1004535809>;\n    using Mint2 = ModInt<prime_998244353>;\n\
    \    using Mint3 = ModInt<prime_985661441>;\n    inline static ModInt<mod> garner(const\
    \ Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*prime_998244353_1004535809;Mint3\
    \ t3 = ((b3-b1.x)*prime_985661441_1004535809-t2.x)*prime_985661441_998244353;return\
    \ ModInt<mod>(ModInt<mod>(prime12)*t3.x+b1.x+prime_1004535809*t2.x);}\n\n    template<long\
    \ long prime> inline static void butterfly(vector<ModInt<prime>>& a, const array<ModInt<prime>,log2n_max>&\
    \ base) {\n        int h = __builtin_ctz(a.size());\n        for (int i = 0; i\
    \ < h; i++) {\n            int w = 1 << i, p = 1 << (h - (i+1));\n           \
    \ ModInt<prime> acc = 1;\n            for (unsigned int s = 0; s < w; s++) {\n\
    \                int offset = s << (h - i);\n                for (int j = 0; j\
    \ < p; ++j) {\n                    auto l = a[j + offset];\n                 \
    \   auto r = a[j + offset + p] * acc;\n                    a[j + offset] = l +\
    \ r;\n                    a[j + offset + p] = l - r;\n                }\n    \
    \            acc *= base[__builtin_ctz(~s)];\n            }\n        }\n    }\n\
    \    template<long long prime> inline static void ibutterfly(vector<ModInt<prime>>&\
    \ a, const array<ModInt<prime>,log2n_max>& base) {\n        int h = __builtin_ctz(a.size());\n\
    \        for (int i = h-1; 0 <= i; i--) {\n            int w = 1 << i, p = 1 <<\
    \ (h - (i+1));\n            ModInt<prime> acc = 1;\n            for (unsigned\
    \ int s = 0; s < w; s++) {\n                int offset = s << (h - i);\n     \
    \           for (int j = 0; j < p; ++j) {\n                    auto l = a[j +\
    \ offset];\n                    auto r = a[j + offset + p];\n                \
    \    a[j + offset] = l + r;\n                    a[j + offset + p] = (l - r) *\
    \ acc;\n                }\n                acc *= base[__builtin_ctz(~s)];\n \
    \           }\n        }\n    }\n    template<long long prime> inline static vector<ModInt<prime>>\
    \ convolution_friendrymod(\n        const vector<ModInt<mod>>& a,\n        const\
    \ vector<ModInt<mod>>& b,\n        const array<ModInt<prime>,log2n_max>& base,\n\
    \        const array<ModInt<prime>,log2n_max>& ibase,\n        const array<ModInt<prime>,log2n_max>&\
    \ pow2_inv\n    ){\n        int n = a.size(), m = b.size();\n        if (!n ||\
    \ !m) return {};\n        if (min(n, m) <= 60) {\n            vector<ModInt<prime>>\
    \ f(n+m-1);\n            if (n >= m) for (int i = 0; i < n; i++) for (int j =\
    \ 0; j < m; j++) f[i+j]+=a[i].x*b[j].x;\n            else for (int j = 0; j <\
    \ m; j++) for (int i = 0; i < n; i++) f[i+j]+=a[i].x*b[j].x;\n            return\
    \ f;\n        }\n\n        int N,L,M=n+m-1; for(N=1,L=0;N<M;N*=2,++L);\n     \
    \   ModInt<prime> inverse = pow2_inv[L];\n        vector<ModInt<prime>> g(N,0),h(N,0);\n\
    \        for(int i=0;i<a.size();++i) g[i]=a[i].x;\n        for(int i=0;i<b.size();++i)\
    \ h[i]=b[i].x;\n\n        butterfly<prime>(g,base);\n        butterfly<prime>(h,base);\n\
    \        for(int i = 0; i < N; ++i) g[i] *= h[i];\n        ibutterfly<prime>(g,ibase);\n\
    \        for (int i = 0; i < n + m - 1; i++) g[i] *= inverse;\n        return\
    \ g;\n    }\n    template<long long prime, long long ZZ> class Inner {\n    public:\n\
    \        inline static vector<ModInt<prime>> convolution_impl(const vector<ModInt<mod>>&\
    \ g,const vector<ModInt<mod>>& h){\n            auto f1 = convolution_friendrymod<prime_1004535809>(g,\
    \ h, base_1004535809, ibase_1004535809, pow2_inv_1004535809);\n            auto\
    \ f2 = convolution_friendrymod<prime_998244353> (g, h, base_998244353,  ibase_998244353,\
    \  pow2_inv_998244353);\n            auto f3 = convolution_friendrymod<prime_985661441>\
    \ (g, h, base_985661441,  ibase_985661441,  pow2_inv_985661441);\n\n         \
    \   vector<ModInt<prime>> f(f1.size());\n            for(int i=0; i<f1.size();\
    \ ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n            return f;\n        }\n \
    \   };\n    template<long long prime> class Inner<prime, prime_998244353> {\n\
    \    public:\n        inline static vector<ModInt<prime>> convolution_impl(const\
    \ vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h) { \n            return\
    \ convolution_friendrymod<prime>(g,h,base_998244353,ibase_998244353,pow2_inv_998244353);\n\
    \        }\n    }; \npublic:\n    inline static vector<ModInt<mod>> convolution(const\
    \ vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h){return Inner<mod,mod>::convolution_impl(g,h);}\n\
    };\n"
  code: "/*\n * @title NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB\n * @docs\
    \ md/convolution/NumberTheoreticalTransform.md\n */\ntemplate<long long mod> class\
    \ NumberTheoreticalTransform {\n    inline static constexpr int prime_1004535809\
    \ =1004535809;\n    inline static constexpr int prime_998244353  =998244353;\n\
    \    inline static constexpr int prime_985661441  =985661441;\n    inline static\
    \ constexpr int prime_998244353_1004535809 = ModInt<prime_998244353>(prime_1004535809).inv().x;\n\
    \    inline static constexpr int prime_985661441_1004535809 = ModInt<prime_985661441>(prime_1004535809).inv().x;\n\
    \    inline static constexpr int prime_985661441_998244353 = ModInt<prime_985661441>(prime_998244353).inv().x;\n\
    \    inline static constexpr long long prime12=((long long)prime_1004535809) *\
    \ prime_998244353;\n    inline static constexpr int log2n_max = 21;\n    template<int\
    \ prime> inline static constexpr array<ModInt<prime>,log2n_max> get_pow2_inv()\
    \ {\n        array<ModInt<prime>,log2n_max>  ar;\n        ModInt<prime> v=1; ar[0]=v;\n\
    \        for(int i=1;i<log2n_max;++i) ar[i]=ar[i-1]/2;\n        return ar;\n \
    \   }\n    inline static constexpr array<ModInt<prime_1004535809>,log2n_max> pow2_inv_1004535809\
    \ = get_pow2_inv<prime_1004535809>();\n    inline static constexpr array<ModInt<prime_998244353>,\
    \ log2n_max> pow2_inv_998244353  = get_pow2_inv<prime_998244353>();\n    inline\
    \ static constexpr array<ModInt<prime_985661441>, log2n_max> pow2_inv_985661441\
    \  = get_pow2_inv<prime_985661441>();\n\n    template<int prime> inline static\
    \ constexpr array<ModInt<prime>,log2n_max> get_base(int inv=0) {\n        array<ModInt<prime>,log2n_max>\
    \ base, es, ies;\n        //TODO 3\u306E\u30CF\u30FC\u30C9\u30B3\u30FC\u30C7\u30A3\
    \u30F3\u30B0\u3092\u76F4\u3059\n        ModInt<prime> e = ModInt<prime>(3).pow((prime\
    \ - 1) >> log2n_max), ie = e.inv();\n        for (int i = log2n_max; i >= 2; --i)\
    \ {\n            es[i - 2]  = e, ies[i - 2] = ie;\n            e *= e, ie *= ie;\n\
    \        }\n        ModInt<prime> acc = 1;\n        if(!inv) {\n            for\
    \ (int i = 0; i < log2n_max - 2; ++i) {\n                base[i] = es[i] * acc;\n\
    \                acc *= ies[i];\n            }\n        }\n        else {\n  \
    \          for (int i = 0; i < log2n_max - 2; ++i) {\n                base[i]\
    \ = ies[i] * acc;\n                acc *= es[i];\n            }\n        }\n \
    \       return base;\n    }\n    inline static constexpr array<ModInt<prime_1004535809>,log2n_max>\
    \ base_1004535809=get_base<prime_1004535809>();\n    inline static constexpr array<ModInt<prime_1004535809>,log2n_max>\
    \ ibase_1004535809=get_base<prime_1004535809>(1);\n    inline static constexpr\
    \ array<ModInt<prime_998244353>,log2n_max> base_998244353=get_base<prime_998244353>();\n\
    \    inline static constexpr array<ModInt<prime_998244353>,log2n_max> ibase_998244353=get_base<prime_998244353>(1);\n\
    \    inline static constexpr array<ModInt<prime_985661441>,log2n_max> base_985661441=get_base<prime_985661441>();\n\
    \    inline static constexpr array<ModInt<prime_985661441>,log2n_max> ibase_985661441=get_base<prime_985661441>(1);\n\
    \n    using Mint1 = ModInt<prime_1004535809>;\n    using Mint2 = ModInt<prime_998244353>;\n\
    \    using Mint3 = ModInt<prime_985661441>;\n    inline static ModInt<mod> garner(const\
    \ Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*prime_998244353_1004535809;Mint3\
    \ t3 = ((b3-b1.x)*prime_985661441_1004535809-t2.x)*prime_985661441_998244353;return\
    \ ModInt<mod>(ModInt<mod>(prime12)*t3.x+b1.x+prime_1004535809*t2.x);}\n\n    template<long\
    \ long prime> inline static void butterfly(vector<ModInt<prime>>& a, const array<ModInt<prime>,log2n_max>&\
    \ base) {\n        int h = __builtin_ctz(a.size());\n        for (int i = 0; i\
    \ < h; i++) {\n            int w = 1 << i, p = 1 << (h - (i+1));\n           \
    \ ModInt<prime> acc = 1;\n            for (unsigned int s = 0; s < w; s++) {\n\
    \                int offset = s << (h - i);\n                for (int j = 0; j\
    \ < p; ++j) {\n                    auto l = a[j + offset];\n                 \
    \   auto r = a[j + offset + p] * acc;\n                    a[j + offset] = l +\
    \ r;\n                    a[j + offset + p] = l - r;\n                }\n    \
    \            acc *= base[__builtin_ctz(~s)];\n            }\n        }\n    }\n\
    \    template<long long prime> inline static void ibutterfly(vector<ModInt<prime>>&\
    \ a, const array<ModInt<prime>,log2n_max>& base) {\n        int h = __builtin_ctz(a.size());\n\
    \        for (int i = h-1; 0 <= i; i--) {\n            int w = 1 << i, p = 1 <<\
    \ (h - (i+1));\n            ModInt<prime> acc = 1;\n            for (unsigned\
    \ int s = 0; s < w; s++) {\n                int offset = s << (h - i);\n     \
    \           for (int j = 0; j < p; ++j) {\n                    auto l = a[j +\
    \ offset];\n                    auto r = a[j + offset + p];\n                \
    \    a[j + offset] = l + r;\n                    a[j + offset + p] = (l - r) *\
    \ acc;\n                }\n                acc *= base[__builtin_ctz(~s)];\n \
    \           }\n        }\n    }\n    template<long long prime> inline static vector<ModInt<prime>>\
    \ convolution_friendrymod(\n        const vector<ModInt<mod>>& a,\n        const\
    \ vector<ModInt<mod>>& b,\n        const array<ModInt<prime>,log2n_max>& base,\n\
    \        const array<ModInt<prime>,log2n_max>& ibase,\n        const array<ModInt<prime>,log2n_max>&\
    \ pow2_inv\n    ){\n        int n = a.size(), m = b.size();\n        if (!n ||\
    \ !m) return {};\n        if (min(n, m) <= 60) {\n            vector<ModInt<prime>>\
    \ f(n+m-1);\n            if (n >= m) for (int i = 0; i < n; i++) for (int j =\
    \ 0; j < m; j++) f[i+j]+=a[i].x*b[j].x;\n            else for (int j = 0; j <\
    \ m; j++) for (int i = 0; i < n; i++) f[i+j]+=a[i].x*b[j].x;\n            return\
    \ f;\n        }\n\n        int N,L,M=n+m-1; for(N=1,L=0;N<M;N*=2,++L);\n     \
    \   ModInt<prime> inverse = pow2_inv[L];\n        vector<ModInt<prime>> g(N,0),h(N,0);\n\
    \        for(int i=0;i<a.size();++i) g[i]=a[i].x;\n        for(int i=0;i<b.size();++i)\
    \ h[i]=b[i].x;\n\n        butterfly<prime>(g,base);\n        butterfly<prime>(h,base);\n\
    \        for(int i = 0; i < N; ++i) g[i] *= h[i];\n        ibutterfly<prime>(g,ibase);\n\
    \        for (int i = 0; i < n + m - 1; i++) g[i] *= inverse;\n        return\
    \ g;\n    }\n    template<long long prime, long long ZZ> class Inner {\n    public:\n\
    \        inline static vector<ModInt<prime>> convolution_impl(const vector<ModInt<mod>>&\
    \ g,const vector<ModInt<mod>>& h){\n            auto f1 = convolution_friendrymod<prime_1004535809>(g,\
    \ h, base_1004535809, ibase_1004535809, pow2_inv_1004535809);\n            auto\
    \ f2 = convolution_friendrymod<prime_998244353> (g, h, base_998244353,  ibase_998244353,\
    \  pow2_inv_998244353);\n            auto f3 = convolution_friendrymod<prime_985661441>\
    \ (g, h, base_985661441,  ibase_985661441,  pow2_inv_985661441);\n\n         \
    \   vector<ModInt<prime>> f(f1.size());\n            for(int i=0; i<f1.size();\
    \ ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n            return f;\n        }\n \
    \   };\n    template<long long prime> class Inner<prime, prime_998244353> {\n\
    \    public:\n        inline static vector<ModInt<prime>> convolution_impl(const\
    \ vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h) { \n            return\
    \ convolution_friendrymod<prime>(g,h,base_998244353,ibase_998244353,pow2_inv_998244353);\n\
    \        }\n    }; \npublic:\n    inline static vector<ModInt<mod>> convolution(const\
    \ vector<ModInt<mod>>& g,const vector<ModInt<mod>>& h){return Inner<mod,mod>::convolution_impl(g,h);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/31-convolution/NumberTheoreticalTransform.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:32:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/convolution/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  - test/convolution/NumberTheoreticalTransform-conv-fft.test.cpp
  - test/convolution/NumberTheoreticalTransform-conv-1000000007-1.test.cpp
  - test/convolution/NumberTheoreticalTransform-conv-998244353-2.test.cpp
  - test/polynomial/FormalPowerSeries-multi-eval.test.cpp
  - test/polynomial/FormalPowerSeries-pow.test.cpp
  - test/polynomial/FormalPowerSeries-exp.test.cpp
  - test/polynomial/FormalPowerSeries-log.test.cpp
  - test/polynomial/FormalPowerSeries-interpolation.test.cpp
  - test/polynomial/FormalPowerSeries-nth.test.cpp
  - test/polynomial/FormalPowerSeries-inv.test.cpp
documentation_of: lib/31-convolution/NumberTheoreticalTransform.cpp
layout: document
redirect_from:
- /library/lib/31-convolution/NumberTheoreticalTransform.cpp
- /library/lib/31-convolution/NumberTheoreticalTransform.cpp.html
title: "NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB"
---
### NumberTheoreticalTransform
- 多項式の畳込みを行う

### コンストラクタ
- なし

### メソッド
- vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>& h)
  - mod 998244353で良いときに畳み込みを返すメソッド。定数倍はふつう。
- vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>& g,const vector<ModInt<1000000007>>& h)
  - mod 1000000007で良いときに畳み込みを返すメソッド。内部的にはnttとgarnarを行っていて、3回畳み込んでいるため定数倍は重め。

### 参考資料
- [高速フーリエ変換](https://atcoder.jp/contests/atc001/tasks/fft_c)
- [Convolution](https://atcoder.github.io/ac-library/production/document_ja/convolution.html)