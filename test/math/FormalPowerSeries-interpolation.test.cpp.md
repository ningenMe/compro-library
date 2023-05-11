---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/FormalPowerSeries.cpp
    title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
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
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_interpolation
    links:
    - https://judge.yosupo.jp/problem/polynomial_interpolation
  bundledCode: "#line 1 \"test/math/FormalPowerSeries-interpolation.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n#include\
    \ <array>\n\nusing namespace std;\n#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title\
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
    };\n#line 1 \"lib/math/FormalPowerSeries.cpp\"\n/*\n * @title FormalPowerSeries\
    \ - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @docs md/math/FormalPowerSeries.md\n\
    \ */\ntemplate<class T> struct FormalPowerSeries : public vector<T> {\n    using\
    \ vector<T>::vector;\n    using Mint  = T;\n    using Fps   = FormalPowerSeries<T>;\n\
    \    inline static constexpr int N_MAX = 1000000;\npublic:\n    //a0 + a_1*x^1\
    \ + a_2*x^2 + ... + a_(n-1)*x^(n-1)\n    FormalPowerSeries(vector<Mint> v){*this=FormalPowerSeries(v.size());for(int\
    \ i=0;i<v.size();++i) (*this)[i]=v[i];}\n    inline static vector<Mint> invs;\n\
    \    static void invs_build() {\n        if(invs.size()) return;\n        vector<Mint>\
    \ fac(N_MAX+1,1),finv(N_MAX+1,1);\n        invs.resize(N_MAX+1);\n        for(int\
    \ i=1;i<=N_MAX;i++) fac[i]=fac[i-1]*i;\n        finv[N_MAX]=fac[N_MAX].inv();\n\
    \        for(int i=N_MAX;i>=1;i--) finv[i-1]=finv[i]*i;\n        for(int i=1;i<=N_MAX;i++)\
    \ invs[i]=finv[i]*fac[i-1];\n    }\n    Fps operator*(const int r) const {return\
    \ Fps(*this) *= r; }\n    Fps &operator*=(const int r) {for(int i=0;i< this->size();\
    \ ++i) (*this)[i] *= r; return *this; }\n    Fps operator*(const long long int\
    \ r) const {return Fps(*this) *= r; }\n    Fps &operator*=(const long long int\
    \ r) {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }\n   \
    \ Fps operator*(const Mint r) const {return Fps(*this) *= r; }\n    Fps &operator*=(const\
    \ Mint r) {for(int i=0;i< this->size(); ++i) (*this)[i] *= r; return *this; }\n\
    \    Fps operator/(const int r) const {return Fps(*this) /= r; }\n    Fps &operator/=(const\
    \ int r) {return (*this) *= Mint(r).inv(); }\n    Fps operator+(const int r) const\
    \ {return Fps(*this) += r; }\n    Fps &operator+=(const int r) {for(int i=0;i<\
    \ this->size(); ++i) (*this)[i] += r; return *this; }\n    Fps operator-(void)\
    \ const {return Fps(*this) *= (-1);}\n    Fps operator-(const int r) const {return\
    \ Fps(*this) -= r; }\n    Fps &operator-=(const int r) {for(int i=0;i< this->size();\
    \ ++i) (*this)[i] -= r; return *this; }\n    Fps prefix(size_t n) const {\n  \
    \      return Fps(this->begin(),this->begin()+min(n,this->size()));\n    }\n \
    \   Fps inv(size_t n) const {\n        Fps ret({Mint(1)/(*this)[0]});\n      \
    \  for(size_t i=2,m=(n<<1);i < m; i<<=1) {\n            Fps h = mul(mul(ret,ret),(this->prefix(i)));\n\
    \            ret.resize(i);\n            for(int j=i>>1;j<i;++j) ret[j] -= h[j];\n\
    \        }\n        return ret.prefix(n);\n    }\n    Fps inv(void) const {return\
    \ inv(this->size());}\n    Fps even(void) const {Fps ret;for(int i = 0; i < this->size();\
    \ i+=2) ret.push_back((*this)[i]);return ret;}\n    Fps odd(void)  const {Fps\
    \ ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return\
    \ ret;}\n    Fps symmetry(void) const {Fps ret(this->size());for(int i = 0; i\
    \ < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}\n    Fps diff(void)\
    \ const {\n        Fps ret(max(0,int(this->size())-1));\n        for(int i=0;i<ret.size();\
    \ ++i) ret[i]=(*this)[i+1]*(i+1);\n        return ret;\n    }\n    Fps intg(size_t\
    \ n) const {\n        invs_build();\n        Fps ret(min(this->size()+1,n));\n\
    \        for(int i=1;i<ret.size(); ++i) ret[i]=(*this)[i-1]*invs[i];\n       \
    \ return ret;\n    }\n    Fps log(size_t n) const {\n        return mul(this->diff(),this->inv(n)).intg(n);\n\
    \    }\n    Fps log(void) const {return log(this->size());}\n    Fps exp(size_t\
    \ n) const {\n        Fps ret(1,1);\n        for(size_t i=2,m=(n<<1);i<m;i<<=1)\
    \ {\n            Fps h = mul(ret,(sub(this->prefix(i),ret.log(i))));\n       \
    \     ret.resize(i);\n            for(int j=i>>1;j<i;++j) ret[j] += h[j];\n  \
    \      }\n        return ret.prefix(n);\n    }\n    Fps exp(void) const {return\
    \ exp(this->size());}\n    Fps pow(long long k,size_t n) const {\n        Fps\
    \ ret(n,0);\n        for(size_t i=0,m = min(n,this->size()); i < m && i*k < n;\
    \ ++i) {\n            if((*this)[i].x == 0) continue;\n            Mint t0=(*this)[i],\
    \ t0_inv=t0.inv();\n            Fps tmp(n-i);for(int j=i;j<m; ++j) tmp[j-i]=(*this)[j]*t0_inv;\n\
    \            tmp = (tmp.log(n)*k).exp(n)*(t0.pow(k));\n            for(int j=0;j+i*k<n;++j)\
    \ ret[j+i*k] = tmp[j];\n            break;\n        }\n        return ret;\n \
    \   }\n    Fps pow(long long k) const {return pow(k,this->size());}\n    Mint\
    \ eval(Mint x) const {\n        Mint base = 1,ret = 0;\n        for(size_t i=0;i<this->size();++i)\
    \ {\n            ret += (*this)[i]*base;\n            base *= x;\n        }\n\
    \        return ret;\n    }\n    inline static Fps add(const Fps& lhs,const Fps&\
    \ rhs) {\n        size_t n = lhs.size(), m = rhs.size();\n        Fps res(max(n,m),0);\n\
    \        for(int i=0;i<n;++i) res[i] += lhs[i];\n        for(int i=0;i<m;++i)\
    \ res[i] += rhs[i];\n        return res;\n    }\n    inline static Fps sub(const\
    \ Fps& lhs,const Fps& rhs) {\n        size_t n = lhs.size(), m = rhs.size();\n\
    \        Fps res(max(n,m),0);\n        for(int i=0;i<n;++i) res[i] += lhs[i];\n\
    \        for(int i=0;i<m;++i) res[i] -= rhs[i];\n        return res;\n    }\n\
    \    inline static Fps mul(const Fps& lhs, const Fps& rhs) {\n        return NumberTheoreticalTransform<Mint>::convolution(lhs,rhs);\n\
    \    }\n    inline static Fps div(Fps lhs, Fps rhs) {\n        while(lhs.size()\
    \ && lhs.back().x == 0) lhs.pop_back();\n        while(rhs.size() && rhs.back().x\
    \ == 0) rhs.pop_back();\n        int n = lhs.size(), m = rhs.size();\n       \
    \ if(n < m) return Fps(1,0);\n        reverse(lhs.begin(),lhs.end());\n      \
    \  reverse(rhs.begin(),rhs.end());\n        auto f = mul(lhs,rhs.inv(n-m+1)).prefix(n-m+1);\n\
    \        reverse(f.begin(),f.end());\n        return f;\n    }\n    inline static\
    \ Fps mod(const Fps& lhs, const Fps& rhs) {\n        int m = rhs.size();\n   \
    \     auto f = sub(lhs,mul(div(lhs,rhs).prefix(m),rhs)).prefix(m);\n        while(f.size()\
    \ && f.back().x==0) f.pop_back();\n        return f;\n    }\n    vector<Mint>\
    \ multipoint_evaluation(vector<Mint> x) {\n        int n = x.size(),m;\n     \
    \   for(m=1;m<n;m<<=1);\n        vector<Fps> f(2*m,Fps(1,1));\n        for(int\
    \ i=0;i<n;++i) f[i+m] = Fps({-x[i],1});\n        for(int i=m-1;i;--i) f[i] = mul(f[(i<<1)|0],f[(i<<1)|1]);\n\
    \        f[1] = mod(*this,f[1]);\n        for(int i=2;i<m+n;++i) f[i] = mod(f[i>>1],f[i]);\n\
    \        for(int i=0;i<n;++i)   x[i] = f[i+m][0];\n        return x;\n    }\n\
    \    inline static Fps interpolation(const vector<Mint>& x,const vector<Mint>&\
    \ y) {\n        int n = x.size(),m;\n        for(m=1;m<n;m<<=1);\n        vector<Fps>\
    \ f(2*m,Fps(1,1)),g(2*m);\n        for(int i=0;i<n;++i) f[i+m] = Fps({-x[i],1});\n\
    \        for(int i=m-1;i;--i) f[i] = mul(f[(i<<1)|0],f[(i<<1)|1]);\n        g[1]\
    \ = mod(f[1].diff(), f[1]);\n        for(int i=2;i<m+n;++i) g[i] = mod(g[i>>1],f[i]);\n\
    \        for(int i=0;i<n;++i) g[i+m] = Fps(1, y[i] / g[i+m][0]);\n        for(int\
    \ i=m-1;i;--i) g[i] = add(mul(g[(i<<1)|0],f[(i<<1)|1]),mul(f[(i<<1)|0],g[(i<<1)|1]));\n\
    \        return g[1];\n    }\n    inline static Mint nth_term(long long n, Fps\
    \ numerator,Fps denominator) {\n        while(n) {\n            numerator    =\
    \ mul(numerator,denominator.symmetry());\n            numerator    = ((n&1)?numerator.odd():numerator.even());\n\
    \            denominator  = mul(denominator,denominator.symmetry());\n       \
    \     denominator  = denominator.even();\n            n >>= 1;\n        }\n  \
    \      return numerator[0];\n    }\n\n    friend ostream &operator<<(ostream &os,\
    \ const Fps& fps) {os << \"{\" << fps[0];for(int i=1;i<fps.size();++i) os << \"\
    , \" << fps[i];return os << \"}\";}\n};\n//using fps = FormalPowerSeries<RuntimeModInt<mod>>;\n\
    //using fps = FormalPowerSeries<ModInt<MOD>>;\n#line 13 \"test/math/FormalPowerSeries-interpolation.test.cpp\"\
    \nconstexpr long long MOD = 998244353;\nusing fps = FormalPowerSeries<ModInt<MOD>>;\n\
    \nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >>\
    \ N;\n    vector<ModInt<MOD>> X(N),Y(N);\n    for(int i=0;i<N;++i) cin >> X[i];\n\
    \    for(int i=0;i<N;++i) cin >> Y[i];\n    auto f = fps::interpolation(X,Y);\n\
    \    for(int i=0;i<N;++i) cout << f[i] << \" \\n\"[i==N-1];\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n\
    #include <array>\n\nusing namespace std;\n#include \"../../lib/util/ModInt.cpp\"\
    \n#include \"../../lib/math/NumberTheoreticalTransform.cpp\"\n#include \"../../lib/math/FormalPowerSeries.cpp\"\
    \nconstexpr long long MOD = 998244353;\nusing fps = FormalPowerSeries<ModInt<MOD>>;\n\
    \nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >>\
    \ N;\n    vector<ModInt<MOD>> X(N),Y(N);\n    for(int i=0;i<N;++i) cin >> X[i];\n\
    \    for(int i=0;i<N;++i) cin >> Y[i];\n    auto f = fps::interpolation(X,Y);\n\
    \    for(int i=0;i<N;++i) cout << f[i] << \" \\n\"[i==N-1];\n    return 0;\n}"
  dependsOn:
  - lib/util/ModInt.cpp
  - lib/math/NumberTheoreticalTransform.cpp
  - lib/math/FormalPowerSeries.cpp
  isVerificationFile: true
  path: test/math/FormalPowerSeries-interpolation.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:44:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/FormalPowerSeries-interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/math/FormalPowerSeries-interpolation.test.cpp
- /verify/test/math/FormalPowerSeries-interpolation.test.cpp.html
title: test/math/FormalPowerSeries-interpolation.test.cpp
---
