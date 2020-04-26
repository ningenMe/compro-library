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


# :warning: non-verified/Garner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/Garner.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:29:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;


class Garner{
public:
	long long lcm,r;
	int flg;
	size_t N;
	vector<long long> coef,val;

	long long GCD(long long a, long long b) {
		return ((b == 0) ? a : GCD(b, a % b));
	}

	long long Ext_GCD(long long a, long long b, long long &x, long long &y) {
		long long res;
		if (b == 0) res = a,x = 1,y = 0;
		else res = Ext_GCD(b, a%b, y, x), y -= a/b * x;
		return res;
	}

	// a^-1 mod b, a and b must be coprime
	long long Inv_Mod(long long a, long long b) {
		long long x, y;
		Ext_GCD(a, b, x, y);
		return (x%b+b)%b;
	}

	// O(N^2 ?) r mod m_i = b_i, lcm = LCM(m_i) 
	Garner(vector<long long> b, vector<long long> m, const long long mod = (long long)1e18)
	 : N(b.size()), lcm(1), flg(1), coef(N+1,1),val(N+1,0) {
		long long g,gl,gr;
		for (int l = 0; l < N && flg; ++l) {
			for (int r = l+1; r < N && flg; ++r) {
				g = GCD(m[l], m[r]);
				
				if ((b[l] - b[r]) % g != 0) {
					flg = 0;
					break;
				}

				m[l] /= g, m[r] /= g;
				gl = GCD(m[l], g), gr = g/gl;
				do {
					g = GCD(gl, gr);
					gl *= g, gr /= g;
				} while (g != 1);
				m[l] *= gl, m[r] *= gr;
				b[l] %= m[l], b[r] %= m[r];
			}
		}
		for (int i = 0; i < N; ++i) (lcm *= m[i]) %= mod;
		
		if(!flg){
			r = -1;
			return;
		} 
		m.push_back(mod);
		for (int i = 0; i < N; ++i) {
			long long t = (b[i] - val[i]) * Inv_Mod(coef[i], m[i]);
			((t %= m[i]) += m[i]) %= m[i];
			for (int j = i+1; j < N + 1; ++j) {
				(val[j] += t * coef[j]) %= m[j];
				(coef[j] *= m[i]) %= m[j];
			}
		}
		r = val[N];
	}

};

//verify https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/Garner.cpp"
#include <bits/stdc++.h>
using namespace std;


class Garner{
public:
	long long lcm,r;
	int flg;
	size_t N;
	vector<long long> coef,val;

	long long GCD(long long a, long long b) {
		return ((b == 0) ? a : GCD(b, a % b));
	}

	long long Ext_GCD(long long a, long long b, long long &x, long long &y) {
		long long res;
		if (b == 0) res = a,x = 1,y = 0;
		else res = Ext_GCD(b, a%b, y, x), y -= a/b * x;
		return res;
	}

	// a^-1 mod b, a and b must be coprime
	long long Inv_Mod(long long a, long long b) {
		long long x, y;
		Ext_GCD(a, b, x, y);
		return (x%b+b)%b;
	}

	// O(N^2 ?) r mod m_i = b_i, lcm = LCM(m_i) 
	Garner(vector<long long> b, vector<long long> m, const long long mod = (long long)1e18)
	 : N(b.size()), lcm(1), flg(1), coef(N+1,1),val(N+1,0) {
		long long g,gl,gr;
		for (int l = 0; l < N && flg; ++l) {
			for (int r = l+1; r < N && flg; ++r) {
				g = GCD(m[l], m[r]);
				
				if ((b[l] - b[r]) % g != 0) {
					flg = 0;
					break;
				}

				m[l] /= g, m[r] /= g;
				gl = GCD(m[l], g), gr = g/gl;
				do {
					g = GCD(gl, gr);
					gl *= g, gr /= g;
				} while (g != 1);
				m[l] *= gl, m[r] *= gr;
				b[l] %= m[l], b[r] %= m[r];
			}
		}
		for (int i = 0; i < N; ++i) (lcm *= m[i]) %= mod;
		
		if(!flg){
			r = -1;
			return;
		} 
		m.push_back(mod);
		for (int i = 0; i < N; ++i) {
			long long t = (b[i] - val[i]) * Inv_Mod(coef[i], m[i]);
			((t %= m[i]) += m[i]) %= m[i];
			for (int j = i+1; j < N + 1; ++j) {
				(val[j] += t * coef[j]) %= m[j];
				(coef[j] *= m[i]) %= m[j];
			}
		}
		r = val[N];
	}

};

//verify https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

