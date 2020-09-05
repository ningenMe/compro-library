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


# :heavy_check_mark: test/math/Prime-miller-rabin.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/Prime-miller-rabin.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-05 23:00:06+09:00


* see: <a href="https://yukicoder.me/problems/no/3030">https://yukicoder.me/problems/no/3030</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Gcd.cpp.html">Gcd</a>
* :heavy_check_mark: <a href="../../../library/lib/math/Prime.cpp.html">Prime</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../../lib/math/Gcd.cpp"
#include "../../lib/math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
	Prime p;
    for(int i = 0; i < N; ++i) {
		long long A; cin >> A;
		cout << A << " " << p.miller_rabin(A) << "\n";
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/Prime-miller-rabin.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#line 1 "lib/math/Gcd.cpp"
/*
 * @title Gcd
 */
class Gcd{
public:
	inline static long long impl(long long n, long long m) {
		static constexpr long long K = 5;
		long long t,s;
		for(int i = 0; t = n - m, s = n - m * K, i < 80; ++i) {
			if(t<m){
				if(!t) return m;
				n = m, m = t;
			}
			else{
				if(!m) return t;
				n=t;
				if(t >= m * K) n = s;
			}
		}
		return impl(m, n % m);
	}
	inline static long long pre(long long n, long long m) {
		long long t;
		for(int i = 0; t = n - m, i < 4; ++i) {
			(t < m ? n=m,m=t : n=t);
			if(!m) return n;
		}
		return impl(n, m);
	}
	inline static long long gcd(long long n, long long m) {
		return (n>m ? pre(n,m) : pre(m,n));
	}
	inline static constexpr long long pureGcd(long long a, long long b) {
		return (b ? pureGcd(b, a % b):a);
	}
	inline static constexpr long long lcm(long long a, long long b) {
		return (a*b ? (a / gcd(a, b)*b): 0);
	}
	inline static constexpr long long extGcd(long long a, long long b, long long &x, long long &y) {
		if (b == 0) return x = 1, y = 0, a;
		long long d = extGcd(b, a%b, y, x);
		return y -= a / b * x, d;
	}
};
#line 1 "lib/math/Prime.cpp"
/*
 * @title Prime
 */
class Prime{
	using int128 = __int128_t;
	using int64  = long long;
	long long pow(long long x, long long n, long long mod) {
		long long res = 1;
		for (x %= mod; n > 0; n >>= 1, x=(int128(x)*x)%mod) if (n & 1) res = (int128(res)*x)%mod;
		return res;
	}
    int64 rho(int64 n){
        if(miller_rabin(n)) return n;
        if(n%2 == 0) return 2;
        for(int64 c=1,x=2,y=2,d;;c++){
            do{
                x=(int128(x)*x+c)%n;
                y=(int128(y)*y+c)%n;
                y=(int128(y)*y+c)%n;
                d=Gcd::gcd(x-y+n,n);
            }while(d==1);
            if(d<n) return d;
        }
    }
    vector<int64> factor(int64 n) {
        if(n <= 1) return {};
        int64 p = rho(n);
        if(p == n) return {p};
        auto l = factor(p);
        auto r = factor(n / p);
        copy(r.begin(), r.end(), back_inserter(l));
        return l;
    }
public:
	int miller_rabin(const int64 n) {
        if(n == 2) return 1;
        if(n < 2 || n%2 == 0) return 0;
		int64 m = n - 1;
		for (;!(m&1);m>>=1);
		for (int64 a: {2,325,9375,28178,450775,9780504,1795265022}) {
			if(a>=n) break;
            int64 x=m,r=pow(a,x,n);
            for(;x != n-1 && r != 1 && r != n-1;x <<= 1) r = (int128(r)*r)%n;
            if(r!=n-1 && x%2==0) return 0;
		}
		return 1;
	}
    vector<pair<int64,int64>> factorization(int64 n) {
        auto v = factor(n);
        vector<pair<int64,int64>> vp;
        sort(v.begin(),v.end());
        int64 prev = 0;
        for(int64 p:v) {
            if(p == prev) vp.back().second++;
            else vp.emplace_back(p,1);
        }
        return vp;
    }
};
#line 9 "test/math/Prime-miller-rabin.test.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
	Prime p;
    for(int i = 0; i < N; ++i) {
		long long A; cin >> A;
		cout << A << " " << p.miller_rabin(A) << "\n";
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

