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
    - Last commit date: 2020-05-30 05:00:04+09:00


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
using namespace std;
#include "../../lib/math/Garner.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
	vector<long long> b(N), m(N);
	int flg = 1;
	for(int i = 0; i < N; ++i){
		cin >> b[i] >> m[i];
		if(b[i]) flg = 0;
	}
	auto [r,lcm]=Garner<MOD>::garner(b,m);
	long long ans = r;
	if(flg) ans = lcm;
	cout << ans << endl;
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
using namespace std;
#line 1 "lib/math/Garner.cpp"
/*
 * @title Garner
 */
template<long long mod> class Garner{
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
	// O(N^2) a mod m_i = b_i, lcm = LCM(m_i)
    // return {a,lcm} 
	inline static pair<long long,long long> garner(vector<long long> b, vector<long long> m){
        long long lcm=1;
        int flg=1,N=b.size();
        vector<long long> coe(N+1,1),val(N+1,0);
		long long g,gl,gr;
		for (int l = 0; l < N && flg; ++l) {
			for (int r = l+1; r < N && flg; ++r) {
				g = gcd(m[l], m[r]);
				if ((b[l] - b[r]) % g != 0) {
					flg = 0;
					break;
				}
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
		for (int i = 0; i < N; ++i) (lcm *= m[i]) %= mod;
		if(!flg) return make_pair(-1,lcm);
		m.push_back(mod);
		for(int i = 0; i < N; ++i) {
			long long t = (b[i] - val[i]) * inv_mod(coe[i], m[i]);
			((t %= m[i]) += m[i]) %= m[i];
			for (int j = i+1; j < N + (mod > 0); ++j) {
				(val[j] += t * coe[j]) %= m[j];
				(coe[j] *= m[i]) %= m[j];
			}
		}
        return make_pair(val[N-1 + (mod > 0)],lcm);
	}
};
#line 7 "test/math/Garner.test.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
	vector<long long> b(N), m(N);
	int flg = 1;
	for(int i = 0; i < N; ++i){
		cin >> b[i] >> m[i];
		if(b[i]) flg = 0;
	}
	auto [r,lcm]=Garner<MOD>::garner(b,m);
	long long ans = r;
	if(flg) ans = lcm;
	cout << ans << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

