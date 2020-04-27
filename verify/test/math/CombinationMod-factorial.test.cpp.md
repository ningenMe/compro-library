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


# :heavy_check_mark: test/math/CombinationMod-factorial.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/CombinationMod-factorial.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 06:54:04+09:00


* see: <a href="https://yukicoder.me/problems/no/916">https://yukicoder.me/problems/no/916</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/CombinationMod.cpp.html">lib/math/CombinationMod.cpp</a>
* :heavy_check_mark: <a href="../../../library/lib/util/ModInt.cpp.html">lib/util/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/916"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/math/CombinationMod.cpp"
#include "../../lib/util/ModInt.cpp"
constexpr long long MOD = 1000'000'007;
using modint = ModInt<MOD>;

int main(void){
	int d, l, r, k;
    int MAX_d = 20;
	cin >> d >> l >> r >> k;
    CombinationMod<MOD> CM((1<<MAX_d));
    vector<int> sum(MAX_d + 1, 0);
    auto pow2 = CombinationMod<MOD>::pow2(MAX_d + 1);
	for (int i = 1; i < MAX_d + 1; ++i) sum[i] = sum[i - 1] + pow2[i];
	l = lower_bound(sum.begin(), sum.end(), l) - sum.begin();
	r = lower_bound(sum.begin(), sum.end(), r) - sum.begin();

	int lca = -1;
	if ((l + r - k) > 1 && (l + r - k) % 2 == 0) lca = (l + r - k) / 2;
	if(lca == -1 || lca > l || lca > r){
		cout << 0 << endl;
		return 0;
	}
	modint ans = 1;
	for (int i = 1; i <= d; ++i) {
		int cnt = pow2[i];
		if (i == l) cnt--;
		if (i == r) cnt--;
		ans *= CM.factorial(cnt);
	}
	ans *= pow2[lca];
	ans *= pow2[l - lca];
	ans *= pow2[r - lca];
	ans *= 2;

	cout << ans << endl;
	return 0;}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/CombinationMod-factorial.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/916"

#include <vector>
#include <iostream>
using namespace std;
#line 1 "lib/math/CombinationMod.cpp"
//Combination Mod
template<long long mod> class CombinationMod {
	vector<long long> fac,finv,inv;
public:
	CombinationMod(int N) : fac(N + 1), finv(N + 1), inv(N + 1) {
		fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
		for (int i = 2; i <= N; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod%i] * (mod / i) % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}
	inline long long binom(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);
	}
    inline long long factorial(int n) {
        return fac[n];
    }
    inline static vector<long long> pow2(int n) {
        vector<long long> pow2(n+1,1);
        for (int i = 2; i <= n; ++i) pow2[i] = (pow2[i - 1] * 2) % mod;
        return pow2;
    }
};

//verify https://atcoder.jp/contests/abc021/tasks/abc021_d
#line 1 "lib/util/ModInt.cpp"

template<long long mod> class ModInt {
public:
	long long x;
	ModInt():x(0) {
		// do nothing
	}
	ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {
		// do nothing
	}
	ModInt &operator+=(const ModInt &p) {
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator+=(const long long y) {
        ModInt p(y);
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator+=(const int y) {
        ModInt p(y);
		if((x += p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-=(const ModInt &p) {
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-=(const long long y) {
        ModInt p(y);
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator-=(const int y) {
        ModInt p(y);
		if((x += mod - p.x) >= mod) x -= mod;
		return *this;
	}
	ModInt &operator*=(const ModInt &p) {
		x = (x * p.x % mod);
		return *this;
	}
	ModInt &operator*=(const long long y) {
        ModInt p(y);
		x = (x * p.x % mod);
		return *this;
	}
	ModInt &operator*=(const int y) {
        ModInt p(y);
		x = (x * p.x % mod);
		return *this;
	}
	ModInt &operator/=(const ModInt &p) {
		*this *= p.inv();
		return *this;
	}
	ModInt &operator/=(const long long y) {
        ModInt p(y);
		*this *= p.inv();
		return *this;
	}
	ModInt &operator/=(const int y) {
        ModInt p(y);
		*this *= p.inv();
		return *this;
	}
	ModInt operator=(const int y) {
        ModInt p(y);
        *this = p;
        return *this;
    }
    ModInt operator=(const long long y) {
        ModInt p(y);
		*this = p;
        return *this;
    }
	ModInt operator-() const { return ModInt(-x); }
	ModInt operator++() { 
        x++;
        if(x>=mod) x-=mod;
        return *this; 
    }
	ModInt operator--() { 
        x--;
        if(x<0) x+=mod;
        return *this; 
    }
	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
	bool operator==(const ModInt &p) const { return x == p.x; }
	bool operator!=(const ModInt &p) const { return x != p.x; }
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0, t;
		while(b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}
	ModInt pow(long long n) const {
		ModInt ret(1), mul(x);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}
	friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}
	friend istream &operator>>(istream &is, ModInt &a) {
		long long t;
		is >> t;
		a = ModInt<mod>(t);
		return (is);
	}
};
//using modint = ModInt<MOD>;
#line 8 "test/math/CombinationMod-factorial.test.cpp"
constexpr long long MOD = 1000'000'007;
using modint = ModInt<MOD>;

int main(void){
	int d, l, r, k;
    int MAX_d = 20;
	cin >> d >> l >> r >> k;
    CombinationMod<MOD> CM((1<<MAX_d));
    vector<int> sum(MAX_d + 1, 0);
    auto pow2 = CombinationMod<MOD>::pow2(MAX_d + 1);
	for (int i = 1; i < MAX_d + 1; ++i) sum[i] = sum[i - 1] + pow2[i];
	l = lower_bound(sum.begin(), sum.end(), l) - sum.begin();
	r = lower_bound(sum.begin(), sum.end(), r) - sum.begin();

	int lca = -1;
	if ((l + r - k) > 1 && (l + r - k) % 2 == 0) lca = (l + r - k) / 2;
	if(lca == -1 || lca > l || lca > r){
		cout << 0 << endl;
		return 0;
	}
	modint ans = 1;
	for (int i = 1; i <= d; ++i) {
		int cnt = pow2[i];
		if (i == l) cnt--;
		if (i == r) cnt--;
		ans *= CM.factorial(cnt);
	}
	ans *= pow2[lca];
	ans *= pow2[l - lca];
	ans *= pow2[r - lca];
	ans *= 2;

	cout << ans << endl;
	return 0;}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

