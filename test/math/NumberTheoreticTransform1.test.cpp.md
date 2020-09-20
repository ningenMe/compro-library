---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/math/NumberTheoreticTransform.cpp
    title: NumberTheoreticTransform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/math/NumberTheoreticTransform1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include <vector>\n\
    #include <iostream>\n#include <numeric>\n#include <algorithm>\n#include <array>\n\
    using namespace std;\n#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title ModInt\n\
    \ */\ntemplate<long long mod> class ModInt {\npublic:\n    long long x;\n    constexpr\
    \ ModInt():x(0) {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod -\
    \ (-y)%mod)%mod) {}\n    ModInt &operator+=(const ModInt &p) {if((x += p.x) >=\
    \ mod) x -= mod;return *this;}\n    ModInt &operator+=(const long long y) {ModInt\
    \ p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const\
    \ int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt\
    \ &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >=\
    \ mod) x -= mod;return *this;}\n    ModInt &operator-=(const int y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator*=(const\
    \ ModInt &p) {x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const\
    \ long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    ModInt &operator*=(const\
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
    //using modint = ModInt<MOD>;\n#line 1 \"lib/math/NumberTheoreticTransform.cpp\"\
    \n/*\n * @title NumberTheoreticTransform\n */\ntemplate<int mod> class NumberTheoreticTransform\
    \ {\n\tinline static constexpr int prime1 =1004535809;\n\tinline static constexpr\
    \ int prime2 =998244353;\n\tinline static constexpr int prime3 =985661441;\n\t\
    inline static constexpr int inv21=332747959; // ModInt<mod2>(mod1).inv().x;\n\t\
    inline static constexpr int inv31=766625513; // ModInt<mod3>(mod1).inv().x;\n\t\
    inline static constexpr int inv32=657107549; // ModInt<mod3>(mod2).inv().x;\n\t\
    inline static constexpr int prime12=(1002772198720536577LL) % mod;\n\tinline static\
    \ constexpr array<int,21> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};\n\
    \tusing Mint = ModInt<mod>;\n\tusing Mint1 = ModInt<prime1>;\n\tusing Mint2 =\
    \ ModInt<prime2>;\n\tusing Mint3 = ModInt<prime3>;\n\tinline Mint garner(const\
    \ Mint1& b1,const Mint2& b2,const Mint3& b3) {\n\t\tMint2 t2 = (b2-b1.x)*inv21;\n\
    \t\tMint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;\n\t\treturn Mint(prime12*t3.x+b1.x+prime1*t2.x);\n\
    \t}\n\ttemplate<int prime> inline void ntt(vector<ModInt<prime>>& f) {\n\t\tconst\
    \ int N = f.size(), M = N>>1;\n\t\tconst int log2N = __builtin_ctz(N);\n\t\tModInt<prime>\
    \ h(3); h = h.pow((prime - 1)/N);\n\t\tvector<ModInt<prime>> base(log2N),g(N);\n\
    \t\tfor(int i=0;i<log2N;++i) base[i] = h.pow(N/pow2[i+1]);\n\t\tfor(int n=0;n<log2N;++n)\
    \ {\n\t\t\tconst int& p = pow2[log2N-n-1];\n\t\t\tModInt<prime> w = 1;\n\t\t\t\
    for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n]) {\n\t\t\t\tfor(int j=0;j<p;++j) {\n\
    \t\t\t\t\tModInt<prime> l = f[k|j];\n\t\t\t\t\tModInt<prime> r = w * f[k|j|p];\n\
    \t\t\t\t\tg[i|j]   = l + r;\n\t\t\t\t\tg[i|j|M] = l - r;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tswap(f,g);\n\t\t}\n\t}\n\ttemplate<int prime=mod> inline vector<ModInt<prime>>\
    \ convolution(const vector<Mint>& a,const vector<Mint>& b){\n\t\tint N,M=a.size()+b.size()-1;\
    \ for(N=1;N<M;N*=2);\n\t\tModInt<prime> inverse(N); inverse = inverse.inv();\n\
    \t\tvector<ModInt<prime>> g(N,0),h(N,0);\n\t\tfor(int i=0;i<a.size();++i) g[i]=a[i].x;\n\
    \t\tfor(int i=0;i<b.size();++i) h[i]=b[i].x;\n\t\tntt<prime>(g); ntt<prime>(h);\n\
    \t\tfor(int i = 0; i < N; ++i) g[i] = g[i]*h[i]*inverse;\n\t\treverse(g.begin()+1,g.end());\n\
    \t\tntt<prime>(g);\n\t\treturn g;\n\t}\n\tinline vector<Mint> convolution_arbitrarymod(const\
    \ vector<Mint>& g,const vector<Mint>& h){\n\t\tauto f1 = convolution<prime1>(g,\
    \ h);\n\t\tauto f2 = convolution<prime2>(g, h);\n\t\tauto f3 = convolution<prime3>(g,\
    \ h);\n\t\tvector<Mint> f(f1.size());\n\t\tfor(int i=0; i < f1.size(); ++i) f[i]\
    \ = garner(f1[i],f2[i],f3[i]);\n\t\treturn f;\n\t}\npublic:\n\tinline vector<ModInt<998244353>>\
    \ convolution(const vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>&\
    \ h){return convolution<998244353>(g,h);}\n\tinline vector<ModInt<1000000007>>\
    \ convolution(const vector<ModInt<1000000007>>& g,const vector<ModInt<1000000007>>&\
    \ h){return convolution_arbitrarymod(g,h);}\n};\n#line 11 \"test/math/NumberTheoreticTransform1.test.cpp\"\
    \nconstexpr long long MOD = 998244353;\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,M; cin >> N >> M;\n    vector<ModInt<MOD>> A(N),B(M);\n    for(int\
    \ i = 0; i < N; ++i) cin >> A[i];\n    for(int i = 0; i < M; ++i) cin >> B[i];\n\
    \    NumberTheoreticTransform<MOD> ntt;\n\tauto C = ntt.convolution(A,B);\n  \
    \  for(int i = 0; i < N+M-1; ++i) cout << C[i] << \" \";\n    cout << endl;\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n#include\
    \ <array>\nusing namespace std;\n#include \"../../lib/util/ModInt.cpp\"\n#include\
    \ \"../../lib/math/NumberTheoreticTransform.cpp\"\nconstexpr long long MOD = 998244353;\n\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,M; cin\
    \ >> N >> M;\n    vector<ModInt<MOD>> A(N),B(M);\n    for(int i = 0; i < N; ++i)\
    \ cin >> A[i];\n    for(int i = 0; i < M; ++i) cin >> B[i];\n    NumberTheoreticTransform<MOD>\
    \ ntt;\n\tauto C = ntt.convolution(A,B);\n    for(int i = 0; i < N+M-1; ++i) cout\
    \ << C[i] << \" \";\n    cout << endl;\n\treturn 0;\n}\n"
  dependsOn:
  - lib/util/ModInt.cpp
  - lib/math/NumberTheoreticTransform.cpp
  isVerificationFile: true
  path: test/math/NumberTheoreticTransform1.test.cpp
  requiredBy: []
  timestamp: '2020-09-07 05:30:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/NumberTheoreticTransform1.test.cpp
layout: document
redirect_from:
- /verify/test/math/NumberTheoreticTransform1.test.cpp
- /verify/test/math/NumberTheoreticTransform1.test.cpp.html
title: test/math/NumberTheoreticTransform1.test.cpp
---
