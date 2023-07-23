---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':question:'
    path: lib/30-math/CombinationMod.cpp
    title: "CombinationMod - mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57"
  - icon: ':question:'
    path: lib/31-convolution/NumberTheoreticalTransform.cpp
    title: "NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: lib/32-polynomial/FormalPowerSeries.cpp
    title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
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
  bundledCode: "#line 1 \"test/polynomial/FormalPowerSeries-interpolation.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n\
    #include <array>\n#include <queue>\n#include <cassert>\n#include <unordered_map>\n\
    \nusing namespace std;\n\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n\
    \ * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n    inline static constexpr\
    \ int ch_0='0';\n    inline static constexpr int ch_9='9';\n    inline static\
    \ constexpr int ch_n='-';\n    inline static constexpr int ch_s=' ';\n    inline\
    \ static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/00-util/ModInt.cpp\"\n/*\n * @title ModInt\n * @docs md/util/ModInt.md\n\
    \ */\ntemplate<long long mod> class ModInt {\npublic:\n    long long x;\n    constexpr\
    \ ModInt():x(0) {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod -\
    \ (-y)%mod)%mod) {}\n    constexpr ModInt &operator+=(const ModInt &p) {if((x\
    \ += p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator+=(const\
    \ long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n  \
    \  constexpr ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod)\
    \ x -= mod;return *this;}\n    constexpr ModInt &operator-=(const ModInt &p) {if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    constexpr ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x)\
    \ >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator*=(const ModInt\
    \ &p) {x = (x * p.x % mod);return *this;}\n    constexpr ModInt &operator*=(const\
    \ long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    constexpr\
    \ ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n\
    \    constexpr ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    constexpr ModInt &operator^=(const long long y) {ModInt p(y);x\
    \ = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const int\
    \ y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator/=(const\
    \ ModInt &p) {*this *= p.inv();return *this;}\n    constexpr ModInt &operator/=(const\
    \ long long y) {ModInt p(y);*this *= p.inv();return *this;}\n    constexpr ModInt\
    \ &operator/=(const int y) {ModInt p(y);*this *= p.inv();return *this;}\n    constexpr\
    \ ModInt operator=(const int y) {ModInt p(y);*this = p;return *this;}\n    constexpr\
    \ ModInt operator=(const long long y) {ModInt p(y);*this = p;return *this;}\n\
    \    constexpr ModInt operator-() const {return ModInt(-x); }\n    constexpr ModInt\
    \ operator++() {x++;if(x>=mod) x-=mod;return *this;}\n    constexpr ModInt operator--()\
    \ {x--;if(x<0) x+=mod;return *this;}\n    constexpr ModInt operator+(const ModInt\
    \ &p) const { return ModInt(*this) += p; }\n    constexpr ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    constexpr ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    constexpr ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    constexpr ModInt operator^(const\
    \ ModInt &p) const { return ModInt(*this) ^= p; }\n    constexpr bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n    constexpr bool operator!=(const ModInt\
    \ &p) const { return x != p.x; }\n    // ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    constexpr ModInt inv() const {int a=x,b=mod,u=1,v=0,t=0,tmp=0;while(b > 0)\
    \ {t = a / b;a-=t*b;tmp=a;a=b;b=tmp;u-=t*v;tmp=u;u=v;v=tmp;} return ModInt(u);}\n\
    \    constexpr ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul\
    \ *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    constexpr long long MOD_998244353 = 998244353;\nconstexpr long long MOD_1000000007\
    \ = 1'000'000'000LL + 7; //'\n#line 1 \"lib/31-convolution/NumberTheoreticalTransform.cpp\"\
    \n/*\n * @title NumberTheoreticalTransform - \u6570\u8AD6\u5909\u63DB\n * @docs\
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
    };\n#line 1 \"lib/30-math/CombinationMod.cpp\"\n/*\n * @title CombinationMod -\
    \ mod\u4E0A\u306E\u4E8C\u9805\u4FC2\u6570\u30FB\u968E\u4E57\n * @docs md/math/CombinationMod.md\n\
    \ */\ntemplate<long long mod> class CombinationMod {\n    vector<long long> fac,finv,inv;\n\
    public:\n    CombinationMod(int N) : fac(N + 1), finv(N + 1), inv(N + 1) {\n \
    \       fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;\n        for (int i\
    \ = 2; i <= N; ++i) {\n            fac[i] = fac[i - 1] * i % mod;\n          \
    \  inv[i] = mod - inv[mod%i] * (mod / i) % mod;\n            finv[i] = finv[i\
    \ - 1] * inv[i] % mod;\n        }\n    }\n    inline long long binom(int n, int\
    \ k) {\n        return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n\
    \ - k] % mod) % mod);\n    }\n    inline long long factorial(int n) {\n      \
    \  return fac[n];\n    }\n};\n\n//verify https://atcoder.jp/contests/abc021/tasks/abc021_d\n\
    #line 1 \"lib/32-polynomial/FormalPowerSeries.cpp\"\n/*\n * @title FormalPowerSeries\
    \ - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @docs md/polynomial/FormalPowerSeries.md\n\
    \ */\ntemplate<long long prime, class T = ModInt<prime>> struct FormalPowerSeries;\n\
    template<long long prime, class T = ModInt<prime>> class SparseFormalPowerSeries\
    \ {\n    using Mint = T;\n    using Sfps = SparseFormalPowerSeries<prime>;\n \
    \   unordered_map<size_t, T> mp;\n    size_t sz;\npublic:\n    friend class FormalPowerSeries<prime>;\n\
    \    SparseFormalPowerSeries():sz(0){}\n    void update(const size_t idx, const\
    \ Mint val) {\n        if(val.x == 0) mp.erase(idx);\n        else mp[idx]=val;\n\
    \        size_t tmp_sz=0;\n        for(auto& p:mp) tmp_sz=max(tmp_sz,p.first);\n\
    \        sz=tmp_sz;\n    }\n    inline static Sfps mul(const Sfps& lhs, const\
    \ Sfps& rhs) {\n        unordered_map<size_t, T> ret;\n        for(auto& [i,a]:\
    \ lhs.mp) {\n            for(auto& [j,b]: rhs.mp) {\n                ret[i+j]+=a*b;\n\
    \            }\n        }\n        return ret;\n    }\n    //map\u306E\u30B5\u30A4\
    \u30BA\u3058\u3083\u306A\u304F\u3066\u3001\u6700\u5927\u306Eindex\u3092\u8FD4\u3059\
    \u3053\u3068\u306B\u6CE8\u610F\n    size_t size() const {return sz+1;}\n};\ntemplate<long\
    \ long prime, class T> struct FormalPowerSeries : public vector<T> {\n    using\
    \ vector<T>::vector;\n    using Mint  = T;\n    using Fps   = FormalPowerSeries<prime>;\n\
    \    using Sfps   = SparseFormalPowerSeries<prime>;\n    inline static constexpr\
    \ int N_MAX = 1000000;\n    Fps even(void) const {Fps ret;for(int i = 0; i < this->size();\
    \ i+=2) ret.push_back((*this)[i]);return ret;}\n    Fps odd(void)  const {Fps\
    \ ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return\
    \ ret;}\n    Fps symmetry(void) const {Fps ret(this->size());for(int i = 0; i\
    \ < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}\npublic:\n  \
    \  //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)\n    FormalPowerSeries(const\
    \ vector<Mint>& v){*this=FormalPowerSeries(v.size());for(int i=0;i<v.size();++i)\
    \ (*this)[i]=v[i];}\n    //TODO constexpr\u306B\u3059\u308B\n    inline static\
    \ vector<Mint> invs;\n    static void invs_build() {\n        if(invs.size())\
    \ return;\n        vector<Mint> fac(N_MAX+1,1),finv(N_MAX+1,1);\n        invs.resize(N_MAX+1);\n\
    \        for(int i=1;i<=N_MAX;i++) fac[i]=fac[i-1]*i;\n        finv[N_MAX]=fac[N_MAX].inv();\n\
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
    \ inv(this->size());}\n    Fps diff(void) const {\n        Fps ret(max(0,int(this->size())-1));\n\
    \        for(int i=0;i<ret.size(); ++i) ret[i]=(*this)[i+1]*(i+1);\n        return\
    \ ret;\n    }\n    Fps intg(size_t n) const {\n        invs_build();\n       \
    \ Fps ret(min(this->size()+1,n));\n        for(int i=1;i<ret.size(); ++i) ret[i]=(*this)[i-1]*invs[i];\n\
    \        return ret;\n    }\n    Fps log(size_t n) const {\n        return mul(this->diff(),this->inv(n)).intg(n);\n\
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
    \    inline static Fps mul(const Fps& lhs, const Fps& rhs) {\n        return NumberTheoreticalTransform<prime>::convolution(lhs,rhs);\n\
    \    }\n    inline static Fps mul(const Fps& lhs, const Sfps& rhs) {\n       \
    \ size_t n = lhs.size() + rhs.size();\n        Fps res(n,0);\n        for(auto&\
    \ [i,a]:rhs.mp) {\n            for (int j = 0; j < lhs.size(); ++j) res[i+j]+=a*lhs[j];\n\
    \        }\n        return res;\n    }\n    inline static Fps div(Fps lhs, Fps\
    \ rhs) {\n        while(lhs.size() && lhs.back().x == 0) lhs.pop_back();\n   \
    \     while(rhs.size() && rhs.back().x == 0) rhs.pop_back();\n        int n =\
    \ lhs.size(), m = rhs.size();\n        if(n < m) return Fps(1,0);\n        reverse(lhs.begin(),lhs.end());\n\
    \        reverse(rhs.begin(),rhs.end());\n        auto f = mul(lhs,rhs.inv(n-m+1)).prefix(n-m+1);\n\
    \        reverse(f.begin(),f.end());\n        return f;\n    }\n    inline static\
    \ Fps mod(const Fps& lhs, const Fps& rhs) {\n        int m = rhs.size();\n   \
    \     auto f = sub(lhs,mul(div(lhs,rhs).prefix(m),rhs)).prefix(m);\n        while(f.size()\
    \ && f.back().x==0) f.pop_back();\n        return f;\n    }\n    inline static\
    \ Fps fold_all(vector<Fps> vfps, size_t n=0) {\n        if(vfps.empty()) return\
    \ {};\n        priority_queue<pair<size_t,size_t>, vector<pair<size_t,size_t>>,\
    \ greater<>> pq;\n        for(size_t i=0;i<vfps.size(); ++i) pq.emplace(vfps[i].size(),\
    \ i);\n        while(pq.size()>1) {\n            auto l=pq.top().second; pq.pop();\n\
    \            auto r=pq.top().second; pq.pop();\n            vfps[l]=mul(vfps[l],vfps[r]);\n\
    \            if(n) vfps[l].resize(n);\n            vfps[r]={};\n            pq.emplace(vfps[l].size(),\
    \ l);\n        }\n        auto ret=pq.top().second; pq.pop();\n        return\
    \ vfps[ret];\n    }\n    vector<Mint> multipoint_evaluation(vector<Mint> x) {\n\
    \        int n = x.size(),m;\n        for(m=1;m<n;m<<=1);\n        vector<Fps>\
    \ f(2*m,Fps(1,1));\n        for(int i=0;i<n;++i) f[i+m] = Fps({-x[i],1});\n  \
    \      for(int i=m-1;i;--i) f[i] = mul(f[(i<<1)|0],f[(i<<1)|1]);\n        f[1]\
    \ = mod(*this,f[1]);\n        for(int i=2;i<m+n;++i) f[i] = mod(f[i>>1],f[i]);\n\
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
    \      return numerator[0];\n    }\n    //(1-rx)^(-n) = \u03A3 (i+n-1)_C_(n-1)\
    \ (rx)^i \u3092m\u9805\u307E\u3067\u8A08\u7B97\u3057\u3066\u8FD4\u3057\u3066\u304F\
    \u308C\u308B\n    inline static Fps negative_binomial_theorem(const Mint r, const\
    \ size_t n, const size_t m, const CombinationMod<prime>& cm) {\n        assert(n-1+m-1\
    \ <= cm.size());\n        Fps res(m,0);\n        for(int i=0;i<m;++i) {\n    \
    \        res[i]= Mint(cm.binom(i+n-1,n-1));\n        }\n        return res;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const Fps& fps) {os << \"\
    {\" << fps[0];for(int i=1;i<fps.size();++i) os << \", \" << fps[i];return os <<\
    \ \"}\";}\n};\n#line 19 \"test/polynomial/FormalPowerSeries-interpolation.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; read(N);\n\
    \    vector<ModInt<MOD_998244353>> X(N),Y(N);\n    for(int i=0;i<N;++i) {\n  \
    \      int a; read(a);\n        X[i]=a;\n    }\n    for(int i=0;i<N;++i) {\n \
    \       int a; read(a);\n        Y[i]=a;\n    }\n    auto f = FormalPowerSeries<MOD_998244353>::interpolation(X,Y);\n\
    \    for(int i=0;i<N;++i) cout << f[i] << \" \\n\"[i==N-1];\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n\n#include <vector>\n#include <iostream>\n#include <numeric>\n#include <algorithm>\n\
    #include <array>\n#include <queue>\n#include <cassert>\n#include <unordered_map>\n\
    \nusing namespace std;\n\n#include \"../../lib/00-util/FastIO.cpp\"\n#include\
    \ \"../../lib/00-util/ModInt.cpp\"\n#include \"../../lib/31-convolution/NumberTheoreticalTransform.cpp\"\
    \n#include \"../../lib/30-math/CombinationMod.cpp\"\n#include \"../../lib/32-polynomial/FormalPowerSeries.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; read(N);\n\
    \    vector<ModInt<MOD_998244353>> X(N),Y(N);\n    for(int i=0;i<N;++i) {\n  \
    \      int a; read(a);\n        X[i]=a;\n    }\n    for(int i=0;i<N;++i) {\n \
    \       int a; read(a);\n        Y[i]=a;\n    }\n    auto f = FormalPowerSeries<MOD_998244353>::interpolation(X,Y);\n\
    \    for(int i=0;i<N;++i) cout << f[i] << \" \\n\"[i==N-1];\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/00-util/ModInt.cpp
  - lib/31-convolution/NumberTheoreticalTransform.cpp
  - lib/30-math/CombinationMod.cpp
  - lib/32-polynomial/FormalPowerSeries.cpp
  isVerificationFile: true
  path: test/polynomial/FormalPowerSeries-interpolation.test.cpp
  requiredBy: []
  timestamp: '2023-06-05 03:49:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/FormalPowerSeries-interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/FormalPowerSeries-interpolation.test.cpp
- /verify/test/polynomial/FormalPowerSeries-interpolation.test.cpp.html
title: test/polynomial/FormalPowerSeries-interpolation.test.cpp
---