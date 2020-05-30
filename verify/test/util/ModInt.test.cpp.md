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


# :heavy_check_mark: test/util/ModInt.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b474f495c8582ac5f92778a42ae814fa">test/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/util/ModInt.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 17:16:02+09:00


* see: <a href="https://yukicoder.me/problems/no/1067">https://yukicoder.me/problems/no/1067</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/util/ModInt.cpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1067"

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#include "../../lib/util/ModInt.cpp"

constexpr long long MOD2 = 998244353;
using modint = ModInt<MOD2>;
int main() {
    long long N,Q; cin >> N >> Q;
    vector<long long> A(N+1,1234567890LL);
    for(int i = 1; i <= N; ++i) cin >> A[i];
	sort(A.begin(),A.end(),greater<>());
    A.push_back(0);
    vector<long long> L(Q),R(Q),P(Q);
    for(int i = 0; i < Q; ++i) cin >> L[i] >> R[i] >> P[i];
    priority_queue<pair<long long,int>> pq;
    for(int i = 0; i < Q; ++i) {
        for(int j = L[i]; j <= R[i]; ++j) {
            pq.push({j,P[i]});
        }
    }
    vector<vector<modint>> dp(2,vector<modint>(N+2));
    dp[0][0]=1;
    modint cnt = 1;
    for(int i = 1; i <= N; ++i) cnt *= A[i];
    map<pair<long long,int>,modint> mp;
    for(int i = 1; i <= N+1; ++i) {
        while(pq.size() && pq.top().first>A[i]) {
            auto p = pq.top();
            pq.pop();
            mp[p]=dp[(i-1)%2][p.second]*cnt;
        }
        for(int j = 0; j <= N; ++j) {
            dp[i%2][j] = 0;
        }
        for(int j = 0; j <= i-1; ++j) {
            dp[i%2][j+1] += dp[(i-1)%2][j];
            dp[i%2][j]   += dp[(i-1)%2][j]*(A[i]-1);
        }
        cnt /= A[i];
    }
    for(int i = 0; i < Q; ++i) {
        modint ans = 0;
        for(int j = L[i]; j <= R[i]; ++j) {
            ans ^= mp[{j,P[i]}];
        }
        cout << ans << endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/util/ModInt.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1067"

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#line 1 "lib/util/ModInt.cpp"
/*
 * @title ModInt
 */
template<long long mod> class ModInt {
public:
	long long x;
	constexpr ModInt():x(0) {
		// do nothing
	}
	constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {
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
	ModInt &operator^=(const ModInt &p) {
		x = (x ^ p.x) % mod;
		return *this;
	}
	ModInt &operator^=(const long long y) {
		ModInt p(y);
		x = (x ^ p.x) % mod;
		return *this;
	}
	ModInt &operator^=(const int y) {
		ModInt p(y);
		x = (x ^ p.x) % mod;
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
	ModInt operator^(const ModInt &p) const { return ModInt(*this) ^= p; }
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
#line 10 "test/util/ModInt.test.cpp"

constexpr long long MOD2 = 998244353;
using modint = ModInt<MOD2>;
int main() {
    long long N,Q; cin >> N >> Q;
    vector<long long> A(N+1,1234567890LL);
    for(int i = 1; i <= N; ++i) cin >> A[i];
	sort(A.begin(),A.end(),greater<>());
    A.push_back(0);
    vector<long long> L(Q),R(Q),P(Q);
    for(int i = 0; i < Q; ++i) cin >> L[i] >> R[i] >> P[i];
    priority_queue<pair<long long,int>> pq;
    for(int i = 0; i < Q; ++i) {
        for(int j = L[i]; j <= R[i]; ++j) {
            pq.push({j,P[i]});
        }
    }
    vector<vector<modint>> dp(2,vector<modint>(N+2));
    dp[0][0]=1;
    modint cnt = 1;
    for(int i = 1; i <= N; ++i) cnt *= A[i];
    map<pair<long long,int>,modint> mp;
    for(int i = 1; i <= N+1; ++i) {
        while(pq.size() && pq.top().first>A[i]) {
            auto p = pq.top();
            pq.pop();
            mp[p]=dp[(i-1)%2][p.second]*cnt;
        }
        for(int j = 0; j <= N; ++j) {
            dp[i%2][j] = 0;
        }
        for(int j = 0; j <= i-1; ++j) {
            dp[i%2][j+1] += dp[(i-1)%2][j];
            dp[i%2][j]   += dp[(i-1)%2][j]*(A[i]-1);
        }
        cnt /= A[i];
    }
    for(int i = 0; i < Q; ++i) {
        modint ans = 0;
        for(int j = L[i]; j <= R[i]; ++j) {
            ans ^= mp[{j,P[i]}];
        }
        cout << ans << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

