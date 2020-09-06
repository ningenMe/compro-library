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


# :heavy_check_mark: test/math/NumberTheoreticTransformArbitraryMod1.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/NumberTheoreticTransformArbitraryMod1.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:05:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod_1000000007">https://judge.yosupo.jp/problem/convolution_mod_1000000007</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/NumberTheoreticTransform.cpp.html">NumberTheoreticTransform</a>
* :heavy_check_mark: <a href="../../../library/lib/util/ModInt.cpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticTransform.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<ModInt<1000000007>> A(N),B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
    NumberTheoreticTransform<1000000007> ntt;
	auto C = ntt.convolution(A,B);
    for(int i = 0; i < N+M-1; ++i) cout << C[i] << " ";
    cout << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/NumberTheoreticTransformArbitraryMod1.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <vector>
#include <iostream>
#include <numeric>
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
#line 1 "lib/math/NumberTheoreticTransform.cpp"
/*
 * @title NumberTheoreticTransform
 */
template<int mod> class NumberTheoreticTransform {
	inline static constexpr int prime1 =1004535809;
	inline static constexpr int prime2 =998244353;
	inline static constexpr int prime3 =985661441;
	inline static constexpr int inv21=332747959; // ModInt<mod2>(mod1).inv().x;
	inline static constexpr int inv31=766625513; // ModInt<mod3>(mod1).inv().x;
	inline static constexpr int inv32=657107549; // ModInt<mod3>(mod2).inv().x;
	inline static constexpr int prime12=(1002772198720536577LL) % mod;
	using Mint = ModInt<mod>;
	using Mint1 = ModInt<prime1>;
	using Mint2 = ModInt<prime2>;
	using Mint3 = ModInt<prime3>;
	inline Mint garner(const Mint1& b1,const Mint2& b2,const Mint3& b3) {
		Mint2 t2 = (b2-b1.x)*inv21;
		Mint3 t3 = ((b3-b1.x)*inv31-t2.x)*inv32;
		return Mint(prime12*t3.x+b1.x+prime1*t2.x);
	}
	template<int prime> inline void ntt(vector<ModInt<prime>>& f,int sgn=1) {
		int N = f.size();
		ModInt<prime> h(3); h = h.pow((prime - 1) / N);
		if (sgn == -1) h = h.inv();

		for (int i = 0,j = 1; j < N - 1; ++j) {
			for (int k = N >> 1; k > (i ^= k); k >>= 1);
			if (j < i) swap(f[i], f[j]);
		}
		for (int i = 1,j = 2; i < N; i *= 2, j *= 2) {
			ModInt<prime> w = 1, base = h.pow(N/j);
			for(int k= 0;k < i; ++k, w*=base) {
				for (int l = k; l < N; l += j) {
					auto u = f[l];
					auto d = f[l + i] * w;
					f[l] = u + d;
					f[l + i] = u - d;
				}
			}
		}
	}
	template<int prime=mod> inline vector<ModInt<prime>> convolution(const vector<long long>& a,const vector<long long>& b){
		int N; for(N=1;N<a.size()+b.size(); N*=2);
		vector<ModInt<prime>> f(N),g(N,0),h(N,0);
		for(int i=0;i<a.size();++i) g[i]=a[i];
		for(int i=0;i<b.size();++i) h[i]=b[i];
		ntt<prime>(g); ntt<prime>(h);
		for(int i = 0; i < N; ++i) f[i] = g[i]*h[i];
		ntt<prime>(f,-1);
		ModInt<prime> inverse(N); inverse = inverse.inv();
		for (auto& x : f) x = x * inverse;
		return f;
	}
	template<int prime> inline vector<ModInt<prime>> convolution_friendrymod(const vector<Mint>& mg,const vector<Mint>& mh){
		vector<long long> g(mg.size()),h(mh.size());
		for(int i=0;i<g.size();++i) g[i]=mg[i].x;
		for(int i=0;i<h.size();++i) h[i]=mh[i].x;
		return convolution(g,h);
	}
	inline vector<Mint> convolution_arbitrarymod(const vector<Mint>& mg,const vector<Mint>& mh){
		vector<long long> g(mg.size()),h(mh.size());
		for(int i=0;i<g.size();++i) g[i]=mg[i].x;
		for(int i=0;i<h.size();++i) h[i]=mh[i].x;
		auto f1 = convolution<prime1>(g, h);
		auto f2 = convolution<prime2>(g, h);
		auto f3 = convolution<prime3>(g, h);
		vector<Mint> f(f1.size());
		for(int i=0; i < f1.size(); ++i) f[i] = garner(f1[i],f2[i],f3[i]);
		return f;
	}
public:
	inline vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>& mg,const vector<ModInt<998244353>>& mh){return convolution_friendrymod<998244353>(mg,mh);}
	inline vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>& mg,const vector<ModInt<1000000007>>& mh){return convolution_arbitrarymod(mg,mh);}
};
#line 9 "test/math/NumberTheoreticTransformArbitraryMod1.test.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<ModInt<1000000007>> A(N),B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
    NumberTheoreticTransform<1000000007> ntt;
	auto C = ntt.convolution(A,B);
    for(int i = 0; i < N+M-1; ++i) cout << C[i] << " ";
    cout << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

