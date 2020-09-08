---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/math/FormalPowerSeries-998244353-1.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/FormalPowerSeries-998244353-1.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:22:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends on

* :question: <a href="../../../library/lib/math/FormalPowerSeries.cpp.html">FormalPowerSeries</a>
* :question: <a href="../../../library/lib/util/ModInt.cpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/FormalPowerSeries.cpp"
constexpr long long MOD = 998244353;

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    FormalPowerSeries<MOD> A(N),B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
	auto C = A*B;
    for(int i = 0; i < N+M-1; ++i) cout << C[i] << " ";
    cout << endl;
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/FormalPowerSeries-998244353-1.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
using namespace std;
#line 1 "lib/util/ModInt.cpp"
/*
 * @title ModInt
 */
template<long long mod> class ModInt {
public:
    long long x;
    constexpr ModInt():x(0) {}
    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}
    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}
    ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}
    ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return *this;}
    ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return *this;}
    ModInt &operator^=(const long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}
    ModInt &operator^=(const int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}
    ModInt &operator/=(const ModInt &p) {*this *= p.inv();return *this;}
    ModInt &operator/=(const long long y) {ModInt p(y);*this *= p.inv();return *this;}
    ModInt &operator/=(const int y) {ModInt p(y);*this *= p.inv();return *this;}
    ModInt operator=(const int y) {ModInt p(y);*this = p;return *this;}
    ModInt operator=(const long long y) {ModInt p(y);*this = p;return *this;}
    ModInt operator-() const {return ModInt(-x); }
    ModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}
    ModInt operator--() {x--;if(x<0) x+=mod;return *this;}
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    ModInt operator^(const ModInt &p) const { return ModInt(*this) ^= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}
    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}
    friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}
    friend istream &operator>>(istream &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}
};
//using modint = ModInt<MOD>;
#line 1 "lib/math/FormalPowerSeries.cpp"
/*
 * @title FormalPowerSeries
 */
template<int mod,int max_size=500000> class FormalPowerSeries{
	inline static constexpr int prime1 =1004535809;
	inline static constexpr int prime2 =998244353;
	inline static constexpr int prime3 =985661441;
	inline static constexpr int inv21  =332747959; // ModInt<mod2>(mod1).inv().x;
	inline static constexpr int inv31  =766625513; // ModInt<mod3>(mod1).inv().x;
	inline static constexpr int inv32  =657107549; // ModInt<mod3>(mod2).inv().x;
	inline static constexpr int prime12=(1002772198720536577LL) % mod;
	inline static constexpr array<int,26> pow2 = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
	using Mint  = ModInt<mod>;
	using Mint1 = ModInt<prime1>;
	using Mint2 = ModInt<prime2>;
	using Mint3 = ModInt<prime3>;
    using Fps   = FormalPowerSeries<mod,max_size>;
    vector<Mint> ar;
    Fps even(void) const {Fps ret;for(int i = 0; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps odd(void)  const {Fps ret;for(int i = 1; i < this->size(); i+=2) ret.push_back((*this)[i]);return ret;}
    Fps minus_x(void) const {Fps ret(this->size());for(int i = 0; i < ret.size(); ++i) ret[i] = (*this)[i]*(i&1?-1:1);return ret;}
	inline Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {Mint2 t2 = (b2-b1.x)*inv21;Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;return Mint(prime12*t3.x+b1.x+prime1*t2.x);}
	template<int prime> inline void ntt(vector<ModInt<prime>>& f) {
		const int N = f.size(), M = N>>1;
		const int log2N = __builtin_ctz(N);
		ModInt<prime> h(3);
		vector<ModInt<prime>> g(N),base(log2N);
		for(int i=0;i<log2N;++i) base[i] = h.pow((prime - 1)/pow2[i+1]);
		for(int n=0;n<log2N;++n) {
			const int& p = pow2[log2N-n-1];
			ModInt<prime> w = 1;
			for (int i=0,k=0;i<M;i+=p,k=i<<1,w*=base[n]) {
				for(int j=0;j<p;++j) {
					ModInt<prime> l = f[k|j],r = w*f[k|j|p];
					g[i|j]   = l + r;
					g[i|j|M] = l - r;
				}
			}
			swap(f,g);
		}
	}
	template<int prime=mod> inline vector<ModInt<prime>> convolution_friendrymod(const vector<Mint>& a,const vector<Mint>& b){
		if (min(a.size(), b.size()) <= 60) {
			vector<ModInt<prime>> f(a.size() + b.size() - 1);
			for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) f[i+j]+=a[i].x*b[j].x;
			return f;
		}
		int N,M=a.size()+b.size()-1; for(N=1;N<M;N*=2);
		ModInt<prime> inverse(N); inverse = inverse.inv();
		vector<ModInt<prime>> g(N,0),h(N,0);
		for(int i=0;i<a.size();++i) g[i]=a[i].x;
		for(int i=0;i<b.size();++i) h[i]=b[i].x;
		ntt<prime>(g); ntt<prime>(h);
		for(int i = 0; i < N; ++i) g[i] *= h[i]*inverse;
		reverse(g.begin()+1,g.end());
		ntt<prime>(g);
        if(g.size()>max_size) g.resize(max_size);
		return g;
	}
	inline vector<Mint> convolution_arbitrarymod(const vector<Mint>& g,const vector<Mint>& h){
        auto f1 = convolution_friendrymod<prime1>(g, h);
		auto f2 = convolution_friendrymod<prime2>(g, h);
		auto f3 = convolution_friendrymod<prime3>(g, h);
		vector<Mint> f(f1.size());
		for(int i=0; i<f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);
		return f;
	}
	inline vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>& h){return convolution_friendrymod<998244353>(g,h);}
	inline vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>& g,const vector<ModInt<1000000007>>& h){return convolution_arbitrarymod(g,h);}
    /**
     * O(log(n)*d*d)
     * fpsのn項目のみを求める。
     * @param n 求めたい項数
     * @param numerator 分子のfps
     * @param denominator 分母のfps
     * @see http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
     */
    static inline Mint nth_term_impl(long long n, Fps numerator,Fps denominator) {
        while(n) {
            numerator   *= denominator.minus_x();
            numerator    = ((n&1)?numerator.odd():numerator.even());
            denominator *= denominator.minus_x();
            denominator  = denominator.even();
            n >>= 1;
        }
        return numerator[0];
    }
public:
    //a0 + a_1*x^1 + a_2*x^2 + ... + a_(n-1)*x^(n-1)
    FormalPowerSeries(){}
    FormalPowerSeries(int n):ar(n,0){}
    FormalPowerSeries(int n,Mint a):ar(n,a){}
    FormalPowerSeries(const vector<Mint>& v):ar(v){}
    FormalPowerSeries(initializer_list<Mint> v):ar(v){}
    static inline Mint nth_term(long long n,const Fps& numerator,const Fps& denominator) {return nth_term_impl(n,numerator,denominator);}
    inline size_t size(void) const {return ar.size();}
    inline void push_back(Mint a){ar.push_back(a);}
    inline void pop_back(void){ar.pop_back();}
    Mint& operator[](size_t i) {return ar[i];}
    Mint operator[](size_t i) const {return ar[i];}
    Fps operator*(const Fps& r) const { return Fps(*this) *= r; }
    Fps &operator*=(const Fps& r) {return *this = convolution(ar,r.ar);}
    Fps pow(long long n) const {Fps ret(1,1), mul(*this);for(;n > 0;mul *= mul,n >>= 1LL) if(n & 1LL) ret *= mul;return ret;}
    friend ostream &operator<<(ostream &os, const Fps& fps) {os << "{" << fps[0];for(int i=1;i<fps.size();++i) os << ", " << fps[i];return os << "}";}
};

// using fps = FormalPowerSeries<MOD,1500000>;
#line 11 "test/math/FormalPowerSeries-998244353-1.test.cpp"
constexpr long long MOD = 998244353;

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    FormalPowerSeries<MOD> A(N),B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
	auto C = A*B;
    for(int i = 0; i < N+M-1; ++i) cout << C[i] << " ";
    cout << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

