---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/NumberTheoreticalTransform.cpp
    title: "NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: lib/util/ModInt.cpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n#include\
    \ <array>\nusing namespace std;\n#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title\
    \ ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt\
    \ {\npublic:\n    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr\
    \ ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    ModInt &operator+=(const\
    \ ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const\
    \ long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n  \
    \  ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod)\
    \ x -= mod;return *this;}\n    ModInt &operator-=(const long long y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator-=(const\
    \ int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n  \
    \  ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n \
    \   ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    ModInt &operator^=(const long long y) {ModInt p(y);x = (x ^ p.x)\
    \ % mod;return *this;}\n    ModInt &operator^=(const int y) {ModInt p(y);x = (x\
    \ ^ p.x) % mod;return *this;}\n    ModInt &operator/=(const ModInt &p) {*this\
    \ *= p.inv();return *this;}\n    ModInt &operator/=(const long long y) {ModInt\
    \ p(y);*this *= p.inv();return *this;}\n    ModInt &operator/=(const int y) {ModInt\
    \ p(y);*this *= p.inv();return *this;}\n    ModInt operator=(const int y) {ModInt\
    \ p(y);*this = p;return *this;}\n    ModInt operator=(const long long y) {ModInt\
    \ p(y);*this = p;return *this;}\n    ModInt operator-() const {return ModInt(-x);\
    \ }\n    ModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}\n    ModInt\
    \ operator--() {x--;if(x<0) x+=mod;return *this;}\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    ModInt operator^(const\
    \ ModInt &p) const { return ModInt(*this) ^= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    //using modint = ModInt<MOD>;\n#line 1 \"lib/math/NumberTheoreticalTransform.cpp\"\
    \n/*\n * @title NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB\n * @docs\
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
    };\n#line 11 \"test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp\"\
    \nconstexpr long long MOD = 998244353;\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,M; cin >> N >> M;\n    vector<ModInt<MOD>> A(N),B(M);\n    for(int\
    \ i = 0; i < N; ++i) cin >> A[i];\n    for(int i = 0; i < M; ++i) cin >> B[i];\n\
    \tauto C = NumberTheoreticalTransform<ModInt<MOD>>::convolution(A,B);\n    for(int\
    \ i = 0; i < N+M-1; ++i) cout << C[i] << \" \";\n    cout << endl;\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n#include\
    \ <array>\nusing namespace std;\n#include \"../../lib/util/ModInt.cpp\"\n#include\
    \ \"../../lib/math/NumberTheoreticalTransform.cpp\"\nconstexpr long long MOD =\
    \ 998244353;\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n \
    \   int N,M; cin >> N >> M;\n    vector<ModInt<MOD>> A(N),B(M);\n    for(int i\
    \ = 0; i < N; ++i) cin >> A[i];\n    for(int i = 0; i < M; ++i) cin >> B[i];\n\
    \tauto C = NumberTheoreticalTransform<ModInt<MOD>>::convolution(A,B);\n    for(int\
    \ i = 0; i < N+M-1; ++i) cout << C[i] << \" \";\n    cout << endl;\n\treturn 0;\n\
    }\n"
  dependsOn:
  - lib/util/ModInt.cpp
  - lib/math/NumberTheoreticalTransform.cpp
  isVerificationFile: true
  path: test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:44:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
layout: document
redirect_from:
- /verify/test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
- /verify/test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp.html
title: test/math/NumberTheoreticalTransform-conv-998244353-1.test.cpp
---
