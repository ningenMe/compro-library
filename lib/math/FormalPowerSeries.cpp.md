---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-exp.test.cpp
    title: test/math/FormalPowerSeries-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-inv.test.cpp
    title: test/math/FormalPowerSeries-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-log.test.cpp
    title: test/math/FormalPowerSeries-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/FormalPowerSeries-pow.test.cpp
    title: test/math/FormalPowerSeries-pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \     ret.resize(i);\n            for(int j=i>>1;j<i;++j) ret[j] += h[j];    \
    \        \n        }\n        return ret.prefix(n);\n    }\n    Fps exp(void)\
    \ const {return exp(this->size());}\n\n    Fps pow(long long k,size_t n) const\
    \ {\n        Fps ret(n,0);\n        for(size_t i=0; i < min(n,this->size()) &&\
    \ i*k < n; ++i) {\n            if((*this)[i].x == 0) continue;\n            Mint\
    \ t0=(*this)[i], t0_inv=t0.inv();\n            Fps tmp(n-i);for(int j=i;j<min(n,this->size());\
    \ ++j) tmp[j-i]=(*this)[j]*t0_inv;\n            tmp = (tmp.log(n)*k).exp(n)*(t0.pow(k));\n\
    \            for(int j=0;j+i*k<n;++j) ret[j+i*k] = tmp[j];\n            break;\n\
    \        }\n        return ret;\n    }\n    Fps pow(long long k) const {return\
    \ pow(k,this->size());}\n    Mint sub(Mint x) const {Mint base = 1,ret = 0; for(size_t\
    \ i=0;i<this->size(); ++i,base *= x) ret += base*(*this)[i]; return ret;}\n  \
    \  inline static Fps add(const Fps& lhs,const Fps& rhs) {\n        size_t n =\
    \ lhs.size(), m = rhs.size();\n        Fps res(max(n,m),0);\n        for(int i=0;i<n;++i)\
    \ res[i] += lhs[i];\n        for(int i=0;i<m;++i) res[i] += rhs[i];\n        return\
    \ res;\n    }\n    inline static Fps sub(const Fps& lhs,const Fps& rhs) {\n  \
    \      size_t n = lhs.size(), m = rhs.size();\n        Fps res(max(n,m),0);\n\
    \        for(int i=0;i<n;++i) res[i] += lhs[i];\n        for(int i=0;i<m;++i)\
    \ res[i] -= rhs[i];\n        return res;\n    }\n    inline static Fps mul(const\
    \ Fps& lhs, const Fps& rhs) {\n        return NumberTheoreticalTransform<Mint>::convolution(lhs,rhs);\n\
    \    }\n    inline static Mint nth_term_impl(long long n, Fps numerator,Fps denominator)\
    \ {\n        while(n) {\n            numerator   *= denominator.symmetry();\n\
    \            numerator    = ((n&1)?numerator.odd():numerator.even());\n      \
    \      denominator *= denominator.symmetry();\n            denominator  = denominator.even();\n\
    \            n >>= 1;\n        }\n        return numerator[0];\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const Fps& fps) {os << \"{\" << fps[0];for(int\
    \ i=1;i<fps.size();++i) os << \", \" << fps[i];return os << \"}\";}\n};\n//using\
    \ fps = FormalPowerSeries<RuntimeModInt<mod>>;\n//using fps = FormalPowerSeries<ModInt<MOD>>;\n"
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
    \     ret.resize(i);\n            for(int j=i>>1;j<i;++j) ret[j] += h[j];    \
    \        \n        }\n        return ret.prefix(n);\n    }\n    Fps exp(void)\
    \ const {return exp(this->size());}\n\n    Fps pow(long long k,size_t n) const\
    \ {\n        Fps ret(n,0);\n        for(size_t i=0; i < min(n,this->size()) &&\
    \ i*k < n; ++i) {\n            if((*this)[i].x == 0) continue;\n            Mint\
    \ t0=(*this)[i], t0_inv=t0.inv();\n            Fps tmp(n-i);for(int j=i;j<min(n,this->size());\
    \ ++j) tmp[j-i]=(*this)[j]*t0_inv;\n            tmp = (tmp.log(n)*k).exp(n)*(t0.pow(k));\n\
    \            for(int j=0;j+i*k<n;++j) ret[j+i*k] = tmp[j];\n            break;\n\
    \        }\n        return ret;\n    }\n    Fps pow(long long k) const {return\
    \ pow(k,this->size());}\n    Mint sub(Mint x) const {Mint base = 1,ret = 0; for(size_t\
    \ i=0;i<this->size(); ++i,base *= x) ret += base*(*this)[i]; return ret;}\n  \
    \  inline static Fps add(const Fps& lhs,const Fps& rhs) {\n        size_t n =\
    \ lhs.size(), m = rhs.size();\n        Fps res(max(n,m),0);\n        for(int i=0;i<n;++i)\
    \ res[i] += lhs[i];\n        for(int i=0;i<m;++i) res[i] += rhs[i];\n        return\
    \ res;\n    }\n    inline static Fps sub(const Fps& lhs,const Fps& rhs) {\n  \
    \      size_t n = lhs.size(), m = rhs.size();\n        Fps res(max(n,m),0);\n\
    \        for(int i=0;i<n;++i) res[i] += lhs[i];\n        for(int i=0;i<m;++i)\
    \ res[i] -= rhs[i];\n        return res;\n    }\n    inline static Fps mul(const\
    \ Fps& lhs, const Fps& rhs) {\n        return NumberTheoreticalTransform<Mint>::convolution(lhs,rhs);\n\
    \    }\n    inline static Mint nth_term_impl(long long n, Fps numerator,Fps denominator)\
    \ {\n        while(n) {\n            numerator   *= denominator.symmetry();\n\
    \            numerator    = ((n&1)?numerator.odd():numerator.even());\n      \
    \      denominator *= denominator.symmetry();\n            denominator  = denominator.even();\n\
    \            n >>= 1;\n        }\n        return numerator[0];\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const Fps& fps) {os << \"{\" << fps[0];for(int\
    \ i=1;i<fps.size();++i) os << \", \" << fps[i];return os << \"}\";}\n};\n//using\
    \ fps = FormalPowerSeries<RuntimeModInt<mod>>;\n//using fps = FormalPowerSeries<ModInt<MOD>>;"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/FormalPowerSeries.cpp
  requiredBy: []
  timestamp: '2021-04-08 04:49:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/FormalPowerSeries-inv.test.cpp
  - test/math/FormalPowerSeries-exp.test.cpp
  - test/math/FormalPowerSeries-log.test.cpp
  - test/math/FormalPowerSeries-pow.test.cpp
documentation_of: lib/math/FormalPowerSeries.cpp
layout: document
redirect_from:
- /library/lib/math/FormalPowerSeries.cpp
- /library/lib/math/FormalPowerSeries.cpp.html
title: "FormalPowerSeries - \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
### FormalPowerSeries
- 形式的冪級数
- 具体的には下記の係数$a=(a_0,...a_{n-1})$を保持するクラス
  - $f(x)=a_0 + a_1x^1 + a_2x^2 + ... + a_{n-1}x^{n-1}$

- 以下FormalPowerSeriesの型のことを`Fps`と称す。
- 0-indexed
  - `Fps f(N)`で初期化した場合は`N-1`項までが確保される
- `ModInt`あるいは`RuntimeModInt`をテンプレートで渡す必要がある
- 実装はvectorを継承しているので、`[]`演算子などが使える。
- ntt-friendlyでないmod(1000'000'007など)でも対応。使い方は同じ。
  - 内部でgarnerを使うかどうかを制御している。
- 実行時modにも対応。使い方は同じ。

### コンストラクタ
- 基本的にはvectorに同じ
- FormalPowerSeries(vector< Mint > v)
  - ModInt型のvectorでも初期化できる
  
### メソッド
- int,long long,ModInt型とFpsとの四則演算は各要素に演算が行われる
  - 和,差,積: $O(N)$
  - 商: $O(N+\log mod)$
- Fps型どうしの四則演算は、和,差については各要素同士、積については畳み込みになる
  - 和,差: $O(N)$
  - 積,商: $O(N\log N)$
  - 積はnttによる畳込み
  - 商は形式的ニュートン法
- Fps prefix(size_t n)
  - Fpsのprefix
  - $O(N)$
  - Fpsの`0`項目から`n-1`項目までのコピーが返却される
- Fps pow(long long k,size_t n) 
  - 累乗$ f(x)^k$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFps.size()*kの大きさで返却される
- Fps inv(size_t n)
  - 逆元$1/(f(x))$を返却する
  - $O(N\log N)$
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
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
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