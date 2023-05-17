---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/math/FormalPowerSeries.md
    document_title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
    links: []
  bundledCode: "#line 1 \"lib/math/FormalPowerSeries.cpp\"\n/*\n * @title FormalPowerSeries\
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
    //using fps = FormalPowerSeries<ModInt<MOD>>;\n"
  code: "/*\n * @title FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n\
    \ * @docs md/math/FormalPowerSeries.md\n */\ntemplate<class T> struct FormalPowerSeries\
    \ : public vector<T> {\n    using vector<T>::vector;\n    using Mint  = T;\n \
    \   using Fps   = FormalPowerSeries<T>;\n    inline static constexpr int N_MAX\
    \ = 1000000;\npublic:\n    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)\n\
    \    FormalPowerSeries(vector<Mint> v){*this=FormalPowerSeries(v.size());for(int\
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
    //using fps = FormalPowerSeries<ModInt<MOD>>;"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/FormalPowerSeries.cpp
  requiredBy: []
  timestamp: '2021-09-21 19:35:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/FormalPowerSeries.cpp
layout: document
redirect_from:
- /library/lib/math/FormalPowerSeries.cpp
- /library/lib/math/FormalPowerSeries.cpp.html
title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
