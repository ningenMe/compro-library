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


# :heavy_check_mark: test/math/NumberTheoreticTransform.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/NumberTheoreticTransform.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 16:25:57+09:00


* see: <a href="https://yukicoder.me/problems/no/754">https://yukicoder.me/problems/no/754</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/NumberTheoreticTransform.cpp.html">NumberTheoreticTransform</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/754"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/math/NumberTheoreticTransform.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    vector<long long> A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) cin >> A[i];
    for(int i = 0; i < N+1; ++i) cin >> B[i];
    auto C = NumberTheoreticTransform<MOD>::convolution_arbitrarymod(A,B);
    long long ans = 0;
    for(int i = 0; i <= N; ++i) (ans += C[i]) %= MOD;
    cout << ans << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/NumberTheoreticTransform.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/754"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#line 1 "lib/math/NumberTheoreticTransform.cpp"
/*
 * @title NumberTheoreticTransform
 */
template<int mod, int root = 3> class NumberTheoreticTransform {
	inline static constexpr long long gcd(long long a, long long b) {
		return (b ? gcd(b, a % b):a);
	}
	inline static long long ext_gcd(long long a, long long b, long long &x, long long &y) {
		long long res;
		if (b == 0) res = a,x = 1,y = 0;
		else res = ext_gcd(b, a%b, y, x), y -= a/b * x;
		return res;
	}
	inline static long long inv_mod(long long a, long long b) {
		long long x, y;
		ext_gcd(a, b, x, y);
		return (x%b+b)%b;
	}
	inline static long long pow_mod(long long x, long long n, long long m) {
		long long res = 1;
		for (; n > 0; n >>= 1, (x *= x) %= m) if (n & 1) (res *= x) %= m;
		return res;
	}
	inline static long long garner(vector<long long> b, vector<long long> m, long long d){
		int N=b.size();
		vector<long long> coe(N+1,1),val(N+1,0);
		long long g,gl,gr,sum=accumulate(b.begin(),b.end(),0LL);
		//互いに素になるように処理
		for (int l = 0; l < N; ++l) {
			for (int r = l+1; r < N; ++r) {
				g = gcd(m[l], m[r]);
				if (sum && (b[l] - b[r]) % g != 0) return -1;
				m[l] /= g, m[r] /= g;
				gl = gcd(m[l], g), gr = g/gl;
				do {
					g = gcd(gl, gr);
					gl *= g, gr /= g;
				} while (g != 1);
				m[l] *= gl, m[r] *= gr;
				b[l] %= m[l], b[r] %= m[r];
			}
		}
		if(!sum) {
			long long lcm = 1;
			for(auto& e:m) (lcm*=e)%=d;
			return lcm;
		}
		m.push_back(d);
		for(int i = 0; i < N; ++i) {
			long long t = (b[i] - val[i]) * inv_mod(coe[i], m[i]);
			((t %= m[i]) += m[i]) %= m[i];
			for (int j = i+1; j <= N; ++j) {
				(val[j] += t * coe[j]) %= m[j];
				(coe[j] *= m[i]) %= m[j];
			}
		}
		return val.back();
	}
	inline static void ntt(vector<long long>& f,int sgn=1) {
		int N = f.size();
		int h = pow_mod(root, (mod - 1) / N, mod);
		if (sgn == -1) h = inv_mod(h, mod);
		for (int i = 0,j = 1; j < N - 1; ++j) {
			for (int k = N >> 1; k > (i ^= k); k >>= 1);
			if (j < i) swap(f[i], f[j]);
		}
		for (int i = 1,j = 2; i < N; i *= 2, j *= 2) {
			long long w = 1, base = pow_mod(h, N / j, mod);
			for(int k= 0;k < i; ++k, (w *= base) %= mod) {
				for (int l = k; l < N; l += j) {
					long long u = f[l];
					long long d = f[l + i] * w % mod;
					f[l] = u + d;
					if (f[l] >= mod) f[l] -= mod;
					f[l + i] = u - d;
					if (f[l + i] < 0) f[l + i] += mod;
				}
			}
		}
		for (auto& x : f) if (x < 0) x += mod;
	}
public:
	inline static vector<long long> convolution(vector<long long> g,vector<long long> h){
		int N; for(N=1;N<g.size()+h.size(); N*=2);
		vector<long long> f(N);
		g.resize(N); h.resize(N);
		ntt(g);	ntt(h);
		for(int i = 0; i < N; ++i) (f[i] = g[i]*h[i]) %= mod;
		ntt(f,-1);
		long long inv = inv_mod(N, mod);
		for (auto& x : f) x = x * inv % mod;
		return f;
	}
	inline static vector<long long> convolution_arbitrarymod(vector<long long> g, vector<long long> h){
		for (auto& a : g) a %= mod;
		for (auto& a : h) a %= mod;
		const int mod1=167772161;
		const int mod2=469762049;
		const int mod3=1224736769;
		auto x = NumberTheoreticTransform<mod1>::convolution(g, h);
		auto y = NumberTheoreticTransform<mod2>::convolution(g, h);
		auto z = NumberTheoreticTransform<mod3>::convolution(g, h);
		vector<long long> res(x.size()),b(3),m(3);
		for(int i=0; i < x.size(); ++i){
			m[0] = mod1, b[0] = x[i];
			m[1] = mod2, b[1] = y[i];
			m[2] = mod3, b[2] = z[i];
			res[i] = garner(b, m, mod);
		}
		return res;
	}
};
#line 8 "test/math/NumberTheoreticTransform.test.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    vector<long long> A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) cin >> A[i];
    for(int i = 0; i < N+1; ++i) cin >> B[i];
    auto C = NumberTheoreticTransform<MOD>::convolution_arbitrarymod(A,B);
    long long ans = 0;
    for(int i = 0; i <= N; ++i) (ans += C[i]) %= MOD;
    cout << ans << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

