---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  - icon: ':x:'
    path: test/polynomial/FormalPowerSeries-nth.test.cpp
    title: test/polynomial/FormalPowerSeries-nth.test.cpp
  - icon: ':x:'
    path: test/polynomial/FormalPowerSeries-pow.test.cpp
    title: test/polynomial/FormalPowerSeries-pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/polynomial/FormalPowerSeries.md
    document_title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
    links: []
  bundledCode: "#line 1 \"lib/polynomial/FormalPowerSeries.cpp\"\n\n/*\n * @title\
    \ FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @docs md/polynomial/FormalPowerSeries.md\n\
    \ */\ntemplate<long long prime, class T = ModInt<prime>> struct FormalPowerSeries\
    \ : public vector<T> {\n    using vector<T>::vector;\n    using Mint  = T;\n \
    \   using Fps   = FormalPowerSeries<prime>;\n    inline static constexpr int N_MAX\
    \ = 1000000;\n    Fps even(void) const {Fps ret;for(int i = 0; i < this->size();\
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
    , \" << fps[i];return os << \"}\";}\n};\n"
  code: "\n/*\n * @title FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n\
    \ * @docs md/polynomial/FormalPowerSeries.md\n */\ntemplate<long long prime, class\
    \ T = ModInt<prime>> struct FormalPowerSeries : public vector<T> {\n    using\
    \ vector<T>::vector;\n    using Mint  = T;\n    using Fps   = FormalPowerSeries<prime>;\n\
    \    inline static constexpr int N_MAX = 1000000;\n    Fps even(void) const {Fps\
    \ ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return\
    \ ret;}\n    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2)\
    \ ret.push_back((*this)[i]);return ret;}\n    Fps symmetry(void) const {Fps ret(this->size());for(int\
    \ i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}\npublic:\n\
    \    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)\n    FormalPowerSeries(const\
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
    , \" << fps[i];return os << \"}\";}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/polynomial/FormalPowerSeries.cpp
  requiredBy: []
  timestamp: '2023-05-18 02:25:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/polynomial/FormalPowerSeries-exp.test.cpp
  - test/polynomial/FormalPowerSeries-pow.test.cpp
  - test/polynomial/FormalPowerSeries-interpolation.test.cpp
  - test/polynomial/FormalPowerSeries-multi-eval.test.cpp
  - test/polynomial/FormalPowerSeries-inv.test.cpp
  - test/polynomial/FormalPowerSeries-log.test.cpp
  - test/polynomial/FormalPowerSeries-nth.test.cpp
documentation_of: lib/polynomial/FormalPowerSeries.cpp
layout: document
redirect_from:
- /library/lib/polynomial/FormalPowerSeries.cpp
- /library/lib/polynomial/FormalPowerSeries.cpp.html
title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
### FormalPowerSeries
- 形式的冪級数、多項式ライブラリ
- 具体的には下記の係数$a=(a_0,...a_{n-1})$を保持するクラス
  - $f(x)=a_0 + a_1x^1 + a_2x^2 + ... + a_{n-1}x^{n-1}$

- 以下FormalPowerSeriesの型のことを`Fps`と称す。
- 0-indexed
  - `Fps f(N)`で初期化した場合は`N-1`項までが確保される
- `ModInt`あるいは`RuntimeModInt`をテンプレートで渡す必要がある
  - [RuntimeModIntのときの使い方はこの提出を参考](https://atcoder.jp/contests/abc137/submissions/21563722)
- 実装はvectorを継承しているので、`[]`演算子などが使える。
- ntt-friendlyでないmod(1000'000'007など)でも対応。使い方は同じ。
  - 内部でgarnerを使うかどうかを制御している。
- 実行時modにも対応。使い方は同じ。

### コンストラクタ
- 基本的にはvectorに同じ
- FormalPowerSeries(vector< Mint > v)
  - ModInt型のvectorでも初期化できる
  
### メソッド
- int,long long,ModInt型に対して、Fpsとの四則演算をオーバーロードしている。
  - 演算は、fpsの各項に対して行われる。
  - +,-,*: $O(N)$
  - /: $O(N+\log mod)$
- Fps prefix(size_t n)
  - Fpsのprefix
  - $O(n)$
  - Fpsの`0`項目から`n-1`項目までのコピーが返却される
- Fps inv(size_t n)
  - Fpsの逆元$1/(f(x))$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps diff(void) 
  - 微分$\( f'(x) \)$を返却する
  - $O(N)$
- Fps intg(void) 
  - 積分$\( \int f(x)dx \)$を返却する
  - $O(N)$
  - 初回時だけ、$O(N+\log mod)$
- Fps log(size_t n)
  - 対数$\log f(x)$を返却する
  - $O(NlogN)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps exp(size_t n) 
  - 指数$\exp f(x)$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps pow(long long k,size_t n) 
  - 累乗$ f(x)^k$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFps.size()*kの大きさで返却される
- Mint eval(Mint x)
  - 一点評価
  - f(x)を返す
  - $O(N)$
- Fps add(const Fps& lhs,const Fps& rhs) 
  - 2個のfpsの各要素の和を取ったfpsを返却する。
  - $O(N)$
  - サイズは、lhs,rhsの大きい方に合わせる。
- Fps sub(const Fps& lhs,const Fps& rhs) 
  - 2個のfpsの各要素の差を取ったfpsを返却する。
  - lhs[i]-rhs[i]が返ると思って良い
  - $O(N)$
  - サイズは、lhs,rhsの大きい方に合わせる。
- Fps mul(const Fps& lhs,const Fps& rhs) 
  - 2個のfpsを畳み込んだfpsを返却する。
  - 内部的にはnttを使用
  - $O(N\log N)$
  - サイズは、lhs.size()+rhs.size()-1になる。
- Fps div(const Fps& lhs,const Fps& rhs) 
  - lhsをrhsで割ったfpsを返却する。
  - lhs * rhs.inv() とは違うことに注意。単純な多項式除算である。
  - $O(N\log N)$
  - サイズは、lhs.size()-rhs.size()+1になる。
- Fps mod(const Fps& lhs,const Fps& rhs) 
  - lhsをrhsで割ったあまりのfpsを返却する。
  - 単純な多項式除算から発生する余りであることに注意。
  - $O(N\log N)$
  - サイズは、rhs.size()-1になる
- vector<Mint> multipoint_evaluation(vector<Mint> x)
  - 多点評価
  - f(x_0),f(x_1), ... , f(x_N) が返る
  - $O(N\log N)$ 定数倍重め。
- inline static Fps interpolation(const vector<Mint>& x,const vector<Mint>& y) 
  - 多項式補間
  - f(x_0)=y_0,f(x_1)=y_1, ... , f(x_N)=y_N を満たすfpsが返る
  - $O(N\log N)$ 定数倍重め。
- Mint nth_term(long long n,const Fps& numerator,const Fps& denominator)
  - f(x)のn項目が返却される
  - $O(N\log N \log n)$
  - nは求めたい項数
  - numeratorは分子のFps
  - denominatorは分母のFps

### 参考資料
- [【競技プログラミング】形式的冪級数の応用テクニック(前編)](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)
- [形式的冪級数(Formal-Power-Series) / Luzhiled’s memo](https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html)
- [形式的べき級数解説 / maspyのHP](https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac)
- [(形式的)べき級数と数え上げの写像12相との関係性　前編 - Senの競技プログラミング備忘録](https://sen-comp.hatenablog.com/entry/2019/12/07/142131)
- [今年中に理解する！多項式、母関数、形式的べき級数の競プロでの実践的使い方 - はまやんはまやんはまやん](https://www.hamayanhamayan.com/entry/2019/12/07/000441)
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)
- [形式的冪級数（FPS）の inv，log，exp，pow の定数倍の軽いアルゴリズム](https://opt-cp.com/fps-fast-algorithms/)
- [多項式を使うテクニックたち](https://yukicoder.me/wiki/polynomial_techniques)
- [非再帰で多項式の多点評価をするよ](https://rsk0315.hatenablog.com/entry/2020/04/05/190941)
- [非再帰で補間多項式を求めるよ](https://rsk0315.hatenablog.com/entry/2020/04/05/203210)