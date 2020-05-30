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


# :heavy_check_mark: test/math/Garner.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/Garner.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 13:58:38+09:00


* see: <a href="https://yukicoder.me/problems/448">https://yukicoder.me/problems/448</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Garner.cpp.html">Garner</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/448"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/math/Garner.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
	vector<long long> b(N), m(N);
	for(int i = 0; i < N; ++i){
		cin >> b[i] >> m[i];
	}
	cout << Garner::garner(b,m,MOD) << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/Garner.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/448"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#line 1 "lib/math/Garner.cpp"
/*
 * @title Garner
 */
class Garner{
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
public:
	// O(N^2) x mod m_i = b_i なる x を返却　, b_iがすべて0のときは0ではなくm_iのlcmを返す
	// return x
	inline static long long garner(vector<long long> b, vector<long long> m, long long mod){
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
			for(auto& e:m) (lcm*=e)%=mod;
			return lcm;
		}
		m.push_back(mod);
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
};
#line 8 "test/math/Garner.test.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
	vector<long long> b(N), m(N);
	for(int i = 0; i < N; ++i){
		cin >> b[i] >> m[i];
	}
	cout << Garner::garner(b,m,MOD) << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

