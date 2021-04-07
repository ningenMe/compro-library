---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/FormalPowerSeries.cpp
    title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: lib/util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/util/RuntimeModInt.cpp
    title: "RuntimeModInt - \u5B9F\u884C\u6642ModInt"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/math/FormalPowerSeries-conv1000000007-1.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n\
    #include <array>\n\nusing namespace std;\n#line 1 \"lib/util/RuntimeModInt.cpp\"\
    \n/*\n * @title RuntimeModInt - \u5B9F\u884C\u6642ModInt\n * @docs md/util/RuntimeModInt.md\n\
    \ */\ntemplate<long long& mod> class RuntimeModInt {\npublic:\n    long long x;\n\
    \    constexpr RuntimeModInt():x(0) {}\n    constexpr RuntimeModInt(long long\
    \ y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    RuntimeModInt &operator+=(const\
    \ RuntimeModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt\
    \ &operator+=(const long long y) {RuntimeModInt p(y);if((x += p.x) >= mod) x -=\
    \ mod;return *this;}\n    RuntimeModInt &operator+=(const int y) {RuntimeModInt\
    \ p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt &operator-=(const\
    \ RuntimeModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n   \
    \ RuntimeModInt &operator-=(const long long y) {RuntimeModInt p(y);if((x += mod\
    \ - p.x) >= mod) x -= mod;return *this;}\n    RuntimeModInt &operator-=(const\
    \ int y) {RuntimeModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    RuntimeModInt &operator*=(const RuntimeModInt &p) {x = (x * p.x % mod);return\
    \ *this;}\n    RuntimeModInt &operator*=(const long long y) {RuntimeModInt p(y);x\
    \ = (x * p.x % mod);return *this;}\n    RuntimeModInt &operator*=(const int y)\
    \ {RuntimeModInt p(y);x = (x * p.x % mod);return *this;}\n    RuntimeModInt &operator^=(const\
    \ RuntimeModInt &p) {x = (x ^ p.x) % mod;return *this;}\n    RuntimeModInt &operator^=(const\
    \ long long y) {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    RuntimeModInt\
    \ &operator^=(const int y) {RuntimeModInt p(y);x = (x ^ p.x) % mod;return *this;}\n\
    \    RuntimeModInt &operator/=(const RuntimeModInt &p) {*this *= p.inv();return\
    \ *this;}\n    RuntimeModInt &operator/=(const long long y) {RuntimeModInt p(y);*this\
    \ *= p.inv();return *this;}\n    RuntimeModInt &operator/=(const int y) {RuntimeModInt\
    \ p(y);*this *= p.inv();return *this;}\n    RuntimeModInt operator=(const int\
    \ y) {RuntimeModInt p(y);*this = p;return *this;}\n    RuntimeModInt operator=(const\
    \ long long y) {RuntimeModInt p(y);*this = p;return *this;}\n    RuntimeModInt\
    \ operator-() const {return RuntimeModInt(-x); }\n    RuntimeModInt operator++()\
    \ {x++;if(x>=mod) x-=mod;return *this;}\n    RuntimeModInt operator--() {x--;if(x<0)\
    \ x+=mod;return *this;}\n    RuntimeModInt operator+(const RuntimeModInt &p) const\
    \ { return RuntimeModInt(*this) += p; }\n    RuntimeModInt operator-(const RuntimeModInt\
    \ &p) const { return RuntimeModInt(*this) -= p; }\n    RuntimeModInt operator*(const\
    \ RuntimeModInt &p) const { return RuntimeModInt(*this) *= p; }\n    RuntimeModInt\
    \ operator/(const RuntimeModInt &p) const { return RuntimeModInt(*this) /= p;\
    \ }\n    RuntimeModInt operator^(const RuntimeModInt &p) const { return RuntimeModInt(*this)\
    \ ^= p; }\n    bool operator==(const RuntimeModInt &p) const { return x == p.x;\
    \ }\n    bool operator!=(const RuntimeModInt &p) const { return x != p.x; }\n\
    \    RuntimeModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a /\
    \ b;swap(a -= t * b, b);swap(u -= t * v, v);} return RuntimeModInt(u);}\n    RuntimeModInt\
    \ pow(long long n) const {RuntimeModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const RuntimeModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, RuntimeModInt &a) {long long t;is >> t;a = RuntimeModInt<mod>(t);return\
    \ (is);}\n};\nlong long runtime_mod;\n// using modint = RuntimeModInt<mod>;\n\
    #line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title ModInt\n * @docs md/util/ModInt.md\n\
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
    //using modint = ModInt<MOD>;\n#line 1 \"lib/math/FormalPowerSeries.cpp\"\n/*\n\
    \ * @title FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @docs\
    \ md/math/FormalPowerSeries.md\n */\ntemplate<class T> struct FormalPowerSeries\
    \ : public vector<T> {\n    inline static constexpr int prime1 =1004535809;\n\
    \    inline static constexpr int prime2 =998244353;\n    inline static constexpr\
    \ int prime3 =985661441;\n    inline static constexpr int inv21  =332747959; //\
    \ ModInt<mod2>(mod1).inv().x;\n    inline static constexpr int inv31  =766625513;\
    \ // ModInt<mod3>(mod1).inv().x;\n    inline static constexpr int inv32  =657107549;\
    \ // ModInt<mod3>(mod2).inv().x;\n    inline static constexpr long long prime12=(1002772198720536577LL);\n\
    \    inline static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};\n\
    \    using vector<T>::vector;\n    using Mint  = T;\n    using Mint1 = ModInt<prime1>;\n\
    \    using Mint2 = ModInt<prime2>;\n    using Mint3 = ModInt<prime3>;\n    using\
    \ Fps   = FormalPowerSeries<T>;\n    Fps even(void) const {Fps ret;for(int i =\
    \ 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}\n    Fps odd(void)\
    \  const {Fps ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return\
    \ ret;}\n    Fps minus_x(void) const {Fps ret(this->size());for(int i = 0; i <\
    \ ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}\n    inline Mint\
    \ garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*inv21;Mint3\
    \ t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(Mint(prime12)*t3.x+b1.x+prime1*t2.x);}\n\
    \    template<int prime> inline void ntt(vector<ModInt<prime>>& f) {\n       \
    \ const int N = f.size(), M = N>>1;\n        const int log2N = __builtin_ctz(N);\n\
    \        ModInt<prime> h(3);\n        vector<ModInt<prime>> g(N),base(log2N);\n\
    \        for(int i=0;i<log2N;++i) base[i] = h.pow((prime - 1)/pow2[i+1]);\n  \
    \      for(int n=0;n<log2N;++n) {\n            const int& p = pow2[log2N-n-1];\n\
    \            ModInt<prime> w = 1;\n            for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n])\
    \ {\n                for(int j=0;j<p;++j) {\n                    ModInt<prime>\
    \ l = f[k|j],r = w*f[k|j|p];\n                    g[i|j]   = l + r;\n        \
    \            g[i|j|M] = l - r;\n                }\n            }\n           \
    \ swap(f,g);\n        }\n    }\n    template<int prime> inline vector<ModInt<prime>>\
    \ convolution_friendrymod(const vector<Mint>& a,const vector<Mint>& b){\n    \
    \    if (min(a.size(), b.size()) <= 60) {\n            vector<ModInt<prime>> f(a.size()\
    \ + b.size() - 1);\n            for (int i = 0; i < a.size(); i++) for (int j\
    \ = 0; j < b.size(); j++) f[i+j]+=a[i].x*b[j].x;\n            return f;\n    \
    \    }\n        int N,M=a.size()+b.size()-1; for(N=1;N<M;N*=2);\n        ModInt<prime>\
    \ inverse(N); inverse = inverse.inv();\n        vector<ModInt<prime>> g(N,0),h(N,0);\n\
    \        for(int i=0;i<a.size();++i) g[i]=a[i].x;\n        for(int i=0;i<b.size();++i)\
    \ h[i]=b[i].x;\n        ntt<prime>(g); ntt<prime>(h);\n        for(int i = 0;\
    \ i < N; ++i) g[i] *= h[i]*inverse;\n        reverse(g.begin()+1,g.end());\n \
    \       ntt<prime>(g);\n        return g;\n    }\n    inline vector<Mint> convolution_arbitrarymod(const\
    \ vector<Mint>& g,const vector<Mint>& h){\n        auto f1 = convolution_friendrymod<prime1>(g,\
    \ h);\n        auto f2 = convolution_friendrymod<prime2>(g, h);\n        auto\
    \ f3 = convolution_friendrymod<prime3>(g, h);\n        vector<Mint> f(f1.size());\n\
    \        for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);\n  \
    \      return f;\n    }\n    inline vector<ModInt<998244353>> convolution(const\
    \ vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>& h){return convolution_friendrymod<998244353>(g,h);}\n\
    \    inline vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>&\
    \ g,const vector<ModInt<1000000007>>& h){return convolution_arbitrarymod(g,h);}\n\
    \    // inline vector<RuntimeModInt<runtime_mod>> convolution(const vector<RuntimeModInt<runtime_mod>>&\
    \ g,const vector<RuntimeModInt<runtime_mod>>& h){return convolution_arbitrarymod(g,h);}\n\
    \n    static inline Mint nth_term_impl(long long n, Fps numerator,Fps denominator)\
    \ {\n        while(n) {\n            numerator   *= denominator.minus_x();\n \
    \           numerator    = ((n&1)?numerator.odd():numerator.even());\n       \
    \     denominator *= denominator.minus_x();\n            denominator  = denominator.even();\n\
    \            n >>= 1;\n        }\n        return numerator[0];\n    }\npublic:\n\
    \    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)\n    inline static Mint\
    \ nth_term(long long n,const Fps& numerator,const Fps& denominator) {return nth_term_impl(n,numerator,denominator);}\n\
    \    FormalPowerSeries(vector<Mint> v){*this=FormalPowerSeries(v.size());for(int\
    \ i=0;i<v.size();++i) (*this)[i]=v[i];}\n    Fps operator*(const Fps& r) const\
    \ { return Fps(*this) *= r; }\n    Fps &operator*=(const Fps& r) {return *this\
    \ = convolution(*this,r);}\n    Fps operator*(const int r) const {return Fps(*this)\
    \ *= r; }\n    Fps &operator*=(const int r) {for(int i=0;i< this->size(); ++i)\
    \ (*this)[i] *= r; return *this; }\n    Fps operator*(const long long int r) const\
    \ {return Fps(*this) *= r; }\n    Fps &operator*=(const long long int r) {for(int\
    \ i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }\n    Fps operator*(const\
    \ Mint r) const {return Fps(*this) *= r; }\n    Fps &operator*=(const Mint r)\
    \ {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }\n\n    Fps\
    \ operator/(const int r) const {return Fps(*this) /= r; }\n    Fps &operator/=(const\
    \ int r) {return (*this) *= Mint(r).inv(); }\n\n    Fps operator+(const Fps& r)\
    \ const { return Fps(*this) += r; }\n    Fps &operator+=(const Fps& r) {if(r.size()\
    \ > this->size()) this->resize(r.size());for(int i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];return *this;}\n    Fps operator+(const int r) const {return Fps(*this)\
    \ += r; }\n    Fps &operator+=(const int r) {for(int i=0;i< this->size(); ++i)\
    \ (*this)[i] += r; return *this; }\n\n    Fps operator-(void) const {return Fps(*this)\
    \ *= (-1);}\n    Fps operator-(const Fps& r) const { return Fps(*this) -= r; }\n\
    \    Fps &operator-=(const Fps& r) {if(r.size() > this->size()) this->resize(r.size());for(int\
    \ i = 0; i < r.size(); i++) (*this)[i] -= r[i];return *this;}\n    Fps operator-(const\
    \ int r) const {return Fps(*this) -= r; }\n    Fps &operator-=(const int r) {for(int\
    \ i=0;i< this->size(); ++i) (*this)[i] -= r; return *this; }\n    Fps prefix(size_t\
    \ n) const {return Fps(this->begin(),this->begin()+min(n,this->size()));}\n  \
    \  Fps pow(long long k,size_t n) const {\n        Fps ret(n,0);\n        for(size_t\
    \ i=0; i < min(n,this->size()) && i*k < n; ++i) {\n            if((*this)[i].x\
    \ == 0) continue;\n            Mint t0=(*this)[i], t0_inv=t0.inv();\n        \
    \    Fps tmp(n-i);for(int j=i;j<min(n,this->size()); ++j) tmp[j-i]=(*this)[j]*t0_inv;\n\
    \            tmp = (tmp.log(n)*k).exp(n)*(t0.pow(k));\n            for(int j=0;j+i*k<n;++j)\
    \ ret[j+i*k] = tmp[j];\n            break;\n        }\n        return ret;\n \
    \   }\n    Fps pow(long long k) const {return pow(k,this->size());}\n    Fps inv(size_t\
    \ n) const {Fps ret({Mint(1)/(*this)[0]});for(size_t i=1;i < n; i<<=1) ret = (ret*2-ret*(ret*(this->prefix(i<<1))).prefix(i<<1)).prefix(i<<1);return\
    \ ret.prefix(n);}\n    Fps inv(void) const {return inv(this->size());}\n    Fps\
    \ diff(void) const {Fps ret(max(0,int(this->size())-1));for(int i=0;i<ret.size();\
    \ ++i) ret[i]=(*this)[i+1]*(i+1);return ret;}\n    Fps intg(void) const {Fps ret(this->size()+1);for(int\
    \ i=1;i<ret.size(); ++i) ret[i]=(*this)[i-1]/i;return ret;}\n    Fps log(size_t\
    \ n) const {return (this->diff()*this->inv(n)).intg().prefix(n);}\n    Fps log(void)\
    \ const {return log(this->size());}\n    Fps exp(size_t n) const {Fps ret(1,1);for(size_t\
    \ i=1;i<n;i<<=1) ret = (ret*(this->prefix(i<<1) + Fps(1,1) - ret.log(i<<1))).prefix(i<<1);return\
    \ ret.prefix(n);}\n    Fps exp(void) const {return exp(this->size());}\n    Mint\
    \ sub(Mint x) const {Mint base = 1,ret = 0; for(size_t i=0;i<this->size(); ++i,base\
    \ *= x) ret += base*(*this)[i]; return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const Fps& fps) {os << \"{\" << fps[0];for(int i=1;i<fps.size();++i) os\
    \ << \", \" << fps[i];return os << \"}\";}\n};\n//using fps = FormalPowerSeries<RuntimeModInt<mod>>;\n\
    //using fps = FormalPowerSeries<ModInt<MOD>>;\n#line 13 \"test/math/FormalPowerSeries-conv1000000007-1.test.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\nusing fps = FormalPowerSeries<ModInt<MOD>>;\n\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,M; cin\
    \ >> N >> M;\n    fps A(N),B(M);\n    for(int i = 0; i < N; ++i) cin >> A[i];\n\
    \    for(int i = 0; i < M; ++i) cin >> B[i];\n\tauto C = A*B;\n    for(int i =\
    \ 0; i < N+M-1; ++i) cout << C[i] << \" \";\n    cout << endl;\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n\
    #include <array>\n\nusing namespace std;\n#include \"../../lib/util/RuntimeModInt.cpp\"\
    \n#include \"../../lib/util/ModInt.cpp\"\n#include \"../../lib/math/FormalPowerSeries.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\nusing fps = FormalPowerSeries<ModInt<MOD>>;\n\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,M; cin\
    \ >> N >> M;\n    fps A(N),B(M);\n    for(int i = 0; i < N; ++i) cin >> A[i];\n\
    \    for(int i = 0; i < M; ++i) cin >> B[i];\n\tauto C = A*B;\n    for(int i =\
    \ 0; i < N+M-1; ++i) cout << C[i] << \" \";\n    cout << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/util/RuntimeModInt.cpp
  - lib/util/ModInt.cpp
  - lib/math/FormalPowerSeries.cpp
  isVerificationFile: true
  path: test/math/FormalPowerSeries-conv1000000007-1.test.cpp
  requiredBy: []
  timestamp: '2021-04-07 21:05:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/FormalPowerSeries-conv1000000007-1.test.cpp
layout: document
redirect_from:
- /verify/test/math/FormalPowerSeries-conv1000000007-1.test.cpp
- /verify/test/math/FormalPowerSeries-conv1000000007-1.test.cpp.html
title: test/math/FormalPowerSeries-conv1000000007-1.test.cpp
---
