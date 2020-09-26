---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-conv1000000007-2.test.cpp
    title: test/math/FormalPowerSeries-conv1000000007-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-conv1000000007-1.test.cpp
    title: test/math/FormalPowerSeries-conv1000000007-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-conv998244353-2.test.cpp
    title: test/math/FormalPowerSeries-conv998244353-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-conv998244353-1.test.cpp
    title: test/math/FormalPowerSeries-conv998244353-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-exp.test.cpp
    title: test/math/FormalPowerSeries-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-pow.test.cpp
    title: test/math/FormalPowerSeries-pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-log.test.cpp
    title: test/math/FormalPowerSeries-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-inv.test.cpp
    title: test/math/FormalPowerSeries-inv.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/math/FormalPowerSeries.md
    document_title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
    links: []
  bundledCode: "#line 1 \"lib/math/FormalPowerSeries.cpp\"\n/*\n * @title FormalPowerSeries\
    \ - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @docs md/math/FormalPowerSeries.md\n\
    \ */\ntemplate<int mod> struct FormalPowerSeries : public vector<ModInt<mod>>\
    \ {\n    inline static constexpr int prime1 =1004535809;\n    inline static constexpr\
    \ int prime2 =998244353;\n    inline static constexpr int prime3 =985661441;\n\
    \    inline static constexpr int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;\n\
    \    inline static constexpr int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;\n\
    \    inline static constexpr int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;\n\
    \    inline static constexpr int prime12=(1002772198720536577LL) % mod;\n    inline\
    \ static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};\n\
    \    using vector<ModInt<mod>>::vector;\n    using Mint  = ModInt<mod>;\n    using\
    \ Mint1 = ModInt<prime1>;\n    using Mint2 = ModInt<prime2>;\n    using Mint3\
    \ = ModInt<prime3>;\n    using Fps   = FormalPowerSeries<mod>;\n    Fps even(void)\
    \ const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return\
    \ ret;}\n    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2)\
    \ ret.push_back((*this)[i]);return ret;}\n    Fps minus_x(void) const {Fps ret(this->size());for(int\
    \ i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}\n  \
    \  inline Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2\
    \ t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(prime12*t3.x+b1.x+prime1*t2.x);}\n\
    \    template<int prime> inline void ntt(vector<ModInt<prime>>& f) {\n       \
    \ const int N = f.size(), M = N>>1;\n        const int log2N = __builtin_ctz(N);\n\
    \        ModInt<prime> h(3);\n        vector<ModInt<prime>> g(N),base(log2N);\n\
    \        for(int i=0;i<log2N;++i) base[i] = h.pow((prime - 1)/pow2[i+1]);\n  \
    \      for(int n=0;n<log2N;++n) {\n            const int& p = pow2[log2N-n-1];\n\
    \            ModInt<prime> w = 1;\n            for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n])\
    \ {\n                for(int j=0;j<p;++j) {\n                    ModInt<prime>\
    \ l = f[k|j],r = w*f[k|j|p];\n                    g[i|j]   = l + r;\n        \
    \            g[i|j|M] = l - r;\n                }\n            }\n           \
    \ swap(f,g);\n        }\n    }\n    template<int prime=mod> inline vector<ModInt<prime>>\
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
    \    static inline Mint nth_term_impl(long long n, Fps numerator,Fps denominator)\
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
    \ {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }\n    Fps\
    \ operator/(const int r) const {return Fps(*this) /= r; }\n    Fps &operator/=(const\
    \ int r) {return (*this) *= Mint(r).inv(); }\n    Fps operator+(const Fps& r)\
    \ const { return Fps(*this) += r; }\n    Fps &operator+=(const Fps& r) {if(r.size()\
    \ > this->size()) this->resize(r.size());for(int i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];return *this;}\n    Fps operator+(const int r) const {return Fps(*this)\
    \ += r; }\n    Fps &operator+=(const int r) {for(int i=0;i< this->size(); ++i)\
    \ (*this)[i] += r; return *this; }\n    Fps operator-(void) const {return Fps(*this)\
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
    \ ret.prefix(n);}\n    Fps exp(void) const {return exp(this->size());}\n    friend\
    \ ostream &operator<<(ostream &os, const Fps& fps) {os << \"{\" << fps[0];for(int\
    \ i=1;i<fps.size();++i) os << \", \" << fps[i];return os << \"}\";}\n};\n\n//using\
    \ fps = FormalPowerSeries<MOD>;\n"
  code: "/*\n * @title FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n\
    \ * @docs md/math/FormalPowerSeries.md\n */\ntemplate<int mod> struct FormalPowerSeries\
    \ : public vector<ModInt<mod>> {\n    inline static constexpr int prime1 =1004535809;\n\
    \    inline static constexpr int prime2 =998244353;\n    inline static constexpr\
    \ int prime3 =985661441;\n    inline static constexpr int inv21  =332747959; //\
    \ ModInt<mod2>(mod1).inv().x;\n    inline static constexpr int inv31  =766625513;\
    \ // ModInt<mod3>(mod1).inv().x;\n    inline static constexpr int inv32  =657107549;\
    \ // ModInt<mod3>(mod2).inv().x;\n    inline static constexpr int prime12=(1002772198720536577LL)\
    \ % mod;\n    inline static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};\n\
    \    using vector<ModInt<mod>>::vector;\n    using Mint  = ModInt<mod>;\n    using\
    \ Mint1 = ModInt<prime1>;\n    using Mint2 = ModInt<prime2>;\n    using Mint3\
    \ = ModInt<prime3>;\n    using Fps   = FormalPowerSeries<mod>;\n    Fps even(void)\
    \ const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return\
    \ ret;}\n    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2)\
    \ ret.push_back((*this)[i]);return ret;}\n    Fps minus_x(void) const {Fps ret(this->size());for(int\
    \ i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}\n  \
    \  inline Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2\
    \ t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(prime12*t3.x+b1.x+prime1*t2.x);}\n\
    \    template<int prime> inline void ntt(vector<ModInt<prime>>& f) {\n       \
    \ const int N = f.size(), M = N>>1;\n        const int log2N = __builtin_ctz(N);\n\
    \        ModInt<prime> h(3);\n        vector<ModInt<prime>> g(N),base(log2N);\n\
    \        for(int i=0;i<log2N;++i) base[i] = h.pow((prime - 1)/pow2[i+1]);\n  \
    \      for(int n=0;n<log2N;++n) {\n            const int& p = pow2[log2N-n-1];\n\
    \            ModInt<prime> w = 1;\n            for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n])\
    \ {\n                for(int j=0;j<p;++j) {\n                    ModInt<prime>\
    \ l = f[k|j],r = w*f[k|j|p];\n                    g[i|j]   = l + r;\n        \
    \            g[i|j|M] = l - r;\n                }\n            }\n           \
    \ swap(f,g);\n        }\n    }\n    template<int prime=mod> inline vector<ModInt<prime>>\
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
    \    static inline Mint nth_term_impl(long long n, Fps numerator,Fps denominator)\
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
    \ {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }\n    Fps\
    \ operator/(const int r) const {return Fps(*this) /= r; }\n    Fps &operator/=(const\
    \ int r) {return (*this) *= Mint(r).inv(); }\n    Fps operator+(const Fps& r)\
    \ const { return Fps(*this) += r; }\n    Fps &operator+=(const Fps& r) {if(r.size()\
    \ > this->size()) this->resize(r.size());for(int i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];return *this;}\n    Fps operator+(const int r) const {return Fps(*this)\
    \ += r; }\n    Fps &operator+=(const int r) {for(int i=0;i< this->size(); ++i)\
    \ (*this)[i] += r; return *this; }\n    Fps operator-(void) const {return Fps(*this)\
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
    \ ret.prefix(n);}\n    Fps exp(void) const {return exp(this->size());}\n    friend\
    \ ostream &operator<<(ostream &os, const Fps& fps) {os << \"{\" << fps[0];for(int\
    \ i=1;i<fps.size();++i) os << \", \" << fps[i];return os << \"}\";}\n};\n\n//using\
    \ fps = FormalPowerSeries<MOD>;\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/FormalPowerSeries.cpp
  requiredBy: []
  timestamp: '2020-09-26 15:25:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/FormalPowerSeries-conv1000000007-2.test.cpp
  - test/math/FormalPowerSeries-conv1000000007-1.test.cpp
  - test/math/FormalPowerSeries-conv998244353-2.test.cpp
  - test/math/FormalPowerSeries-conv998244353-1.test.cpp
  - test/math/FormalPowerSeries-exp.test.cpp
  - test/math/FormalPowerSeries-pow.test.cpp
  - test/math/FormalPowerSeries-log.test.cpp
  - test/math/FormalPowerSeries-inv.test.cpp
documentation_of: lib/math/FormalPowerSeries.cpp
layout: document
redirect_from:
- /library/lib/math/FormalPowerSeries.cpp
- /library/lib/math/FormalPowerSeries.cpp.html
title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
### FormalPowerSeries
- 形式的冪級数
- 具体的には下記の係数$a=(a0,...a_(n-1))$を保持するクラス
```
f(x)=a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)
```
- 以下FormalPowerSeriesの型のことを`Fps`と称す。
- 0-indexed
  - `Fps f(N)`で初期化した場合は`N-1`項までが確保される
- `mod`をテンプレートで渡す必要がある
- 実装はvectorを継承しているので、`[]`演算子などが使える。

### コンストラクタ
- 基本的にはvectorに同じ
- FormalPowerSeries(vector<Mint> v)
  - ModInt型のvectorでも初期化できる
  
### メソッド
- int,long long,ModInt型とFpsとの四則演算は各要素に演算が行われる
  - 和,差,積: $O(N)$
  - 商: $O(N+log(mod))$
- Fps型どうしの四則演算は、和,差については各要素同士、積については畳み込みになる
  - 和,差: $O(N)$
  - 積,商: $O(Nlog(N))$
  - 積はnttによる畳込み
  - 商は形式的ニュートン法
- Fps prefix(size_t n)
  - Fpsのprefix
  - $O(N)$
  - Fpsの`0`項目から`n-1`項目までのコピーが返却される
- Fps pow(long long k,size_t n) 
  - 累乗$(f(x))^k$を返却する
  - $O(NlogN)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps inv(size_t n)
  - 逆元$1/(f(x))$を返却する
  - $O(NlogN)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps diff(void) 
  - 微分$\( f'(x) \)$を返却する
  - $O(N)$
- Fps intg(void) 
  - 積分$\( \int f(x)dx \)$を返却する
  - $O(N)$
- Fps log(size_t n)
  - 対数$\log f(x)$を返却する
  - $O(NlogN)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps exp(size_t n) 
  - 指数$\exp f(x)$を返却する
  - $O(NlogN)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Mint nth_term(long long n,const Fps& numerator,const Fps& denominator)
  - f(x)のn項目が返却される
  - $O(N\log N \log n)$
  - nは求めたい項数
  - numeratorは分子のFps
  - denominatorは分母のFps

### 参考資料
- https://qiita.com/hotman78/items/f0e6d2265badd84d429a
- https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html
- https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac
- https://sen-comp.hatenablog.com/entry/2019/12/07/142131
- https://www.hamayanhamayan.com/entry/2019/12/07/000441
- http://q.c.titech.ac.jp/docs/progs/polynomial_division.html