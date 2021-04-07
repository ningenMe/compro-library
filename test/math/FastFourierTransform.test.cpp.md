---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/FastFourierTransform.cpp
    title: "FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: lib/util/ModInt.cpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1307
    links:
    - https://yukicoder.me/problems/no/1307
  bundledCode: "#line 1 \"test/math/FastFourierTransform.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1307\"\n\n#include <vector>\n#include <iostream>\n\
    #include <algorithm>\n#include <array>\nusing namespace std;\n#line 1 \"lib/util/ModInt.cpp\"\
    \n/*\n * @title ModInt\n * @docs md/util/ModInt.md\n */\ntemplate<long long mod>\
    \ class ModInt {\npublic:\n    long long x;\n    constexpr ModInt():x(0) {}\n\
    \    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n\
    \    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x)\
    \ >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const int y) {ModInt\
    \ p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator-=(const\
    \ ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt\
    \ &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -=\
    \ mod;return *this;}\n    ModInt &operator-=(const int y) {ModInt p(y);if((x +=\
    \ mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator*=(const ModInt\
    \ &p) {x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const long long\
    \ y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const\
    \ int y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator^=(const\
    \ ModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator^=(const\
    \ long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator^=(const\
    \ int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    ModInt &operator/=(const\
    \ ModInt &p) {*this *= p.inv();return *this;}\n    ModInt &operator/=(const long\
    \ long y) {ModInt p(y);*this *= p.inv();return *this;}\n    ModInt &operator/=(const\
    \ int y) {ModInt p(y);*this *= p.inv();return *this;}\n    ModInt operator=(const\
    \ int y) {ModInt p(y);*this = p;return *this;}\n    ModInt operator=(const long\
    \ long y) {ModInt p(y);*this = p;return *this;}\n    ModInt operator-() const\
    \ {return ModInt(-x); }\n    ModInt operator++() {x++;if(x>=mod) x-=mod;return\
    \ *this;}\n    ModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n    ModInt\
    \ operator+(const ModInt &p) const { return ModInt(*this) += p; }\n    ModInt\
    \ operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt\
    \ operator*(const ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt\
    \ operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n    ModInt\
    \ operator^(const ModInt &p) const { return ModInt(*this) ^= p; }\n    bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    //using modint = ModInt<MOD>;\n#line 1 \"lib/math/FastFourierTransform.cpp\"\n\
    /*\n * @title FastFourierTransform - \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\
    \u63DB\n * @docs md/math/FastFourierTransform.md\n */\nclass FastFourierTransform\
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
    \      return f;\n    }\n};\n#line 10 \"test/math/FastFourierTransform.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N),B(N,0),D(N,0);\n    for(int i=0;i<N;++i)\
    \ cin >> A[i];\n    while(Q--){\n        int r; cin >> r; B[N-1-r]++;\n    }\n\
    \    auto C = FastFourierTransform::convolution(A,B);\n    for(int i=0;i<2*N-1;++i)\
    \ {\n        D[(i+1)%N]+=C[i];\n    }\n    for(int i=0;i<N;++i) cout << D[i] <<\
    \ \" \\n\"[i==N-1];\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1307\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/util/ModInt.cpp\"\n#include \"../../lib/math/FastFourierTransform.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N),B(N,0),D(N,0);\n    for(int i=0;i<N;++i)\
    \ cin >> A[i];\n    while(Q--){\n        int r; cin >> r; B[N-1-r]++;\n    }\n\
    \    auto C = FastFourierTransform::convolution(A,B);\n    for(int i=0;i<2*N-1;++i)\
    \ {\n        D[(i+1)%N]+=C[i];\n    }\n    for(int i=0;i<N;++i) cout << D[i] <<\
    \ \" \\n\"[i==N-1];\n    return 0;\n}\n"
  dependsOn:
  - lib/util/ModInt.cpp
  - lib/math/FastFourierTransform.cpp
  isVerificationFile: true
  path: test/math/FastFourierTransform.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 06:18:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/FastFourierTransform.test.cpp
layout: document
redirect_from:
- /verify/test/math/FastFourierTransform.test.cpp
- /verify/test/math/FastFourierTransform.test.cpp.html
title: test/math/FastFourierTransform.test.cpp
---
