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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: lib-unverified/CombinationMod.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/CombinationMod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//Combination Mod
class CombinationMod {
public:
	vector<long long> fac,finv,inv;
	long long mod;

	CombinationMod(int N,long long mod) : fac(N + 1), finv(N + 1), inv(N + 1), mod(mod) {
		fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
		for (int i = 2; i <= N; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod%i] * (mod / i) % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}
	
	long long num(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);
	}
};

//verify https://atcoder.jp/contests/abc021/tasks/abc021_d

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/CombinationMod.cpp"

//Combination Mod
class CombinationMod {
public:
	vector<long long> fac,finv,inv;
	long long mod;

	CombinationMod(int N,long long mod) : fac(N + 1), finv(N + 1), inv(N + 1), mod(mod) {
		fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
		for (int i = 2; i <= N; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod%i] * (mod / i) % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}
	
	long long num(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);
	}
};

//verify https://atcoder.jp/contests/abc021/tasks/abc021_d

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

