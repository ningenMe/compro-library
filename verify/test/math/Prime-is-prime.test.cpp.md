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


# :heavy_check_mark: test/math/Prime-is-prime.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/Prime-is-prime.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-05 14:17:10+09:00


* see: <a href="https://yukicoder.me/problems/no/3030">https://yukicoder.me/problems/no/3030</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Prime.cpp.html">Prime</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
using namespace std;
#include "../../lib/math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
    for(int i = 0; i < N; ++i) {
		long long A; cin >> A;
		cout << A << " " << Prime::is_prime(A) << "\n";
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/Prime-is-prime.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
using namespace std;
#line 1 "lib/math/Prime.cpp"
/*
 * @title Prime
 */
class Prime{
	using int128 = __int128_t;
	inline static int miller_rabin64(const int128 N) {
		long long M = N - 1,L = 0;
		for (; !(M&1); M >>= 1,L++);
		for (int128 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
			if(a >= N) break;
			int128 r = 1;
			for (long long K=M; K>0; K>>=1, (a*=a) %= N) if(K&1) (r *= a) %= N;
			if (r == 1) continue;
			for (int j = 1; j < L && r != N - 1; j++) (r *= r) %= N;
			if (r != N - 1) return 0;
		}
		return 1;
	}
	inline static int miller_rabin32(const long long N) {
		long long M = N - 1,L = 0;
		for (; !(M&1); M >>= 1,L++);
		for (long long a: {2, 7, 61}) {
			if(a >= N) break;
			long long r = 1;
			for (long long K=M; K>0; K>>=1, (a*=a) %= N) if(K&1) (r *= a) %= N;
			if (r == 1) continue;
			for (int j = 1; j < L && r != N - 1; j++) (r *= r) %= N;
			if (r != N - 1) return 0;
		}
		return 1;
	}
public:
	inline static int is_prime(long long n) {
		if (n == 2 || n == 3) return 1;
		if (!(n&1) || n%3 == 0 || n <= 1) return 0;
		if (n < (1LL<<32)) return miller_rabin32(n);
		else return miller_rabin64(n);
	}
};
#line 6 "test/math/Prime-is-prime.test.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
    for(int i = 0; i < N; ++i) {
		long long A; cin >> A;
		cout << A << " " << Prime::is_prime(A) << "\n";
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

