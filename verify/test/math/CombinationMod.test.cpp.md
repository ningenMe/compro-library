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


# :heavy_check_mark: test/math/CombinationMod.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/CombinationMod.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 06:45:59+09:00


* see: <a href="https://yukicoder.me/problems/no/741">https://yukicoder.me/problems/no/741</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/CombinationMod.cpp.html">lib/math/CombinationMod.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/741"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/math/CombinationMod.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    CombinationMod<MOD> CM(N+10);
    cout << CM.binom(N+9,9) << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/CombinationMod.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/741"

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
#line 7 "test/math/CombinationMod.test.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    CombinationMod<MOD> CM(N+10);
    cout << CM.binom(N+9,9) << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

