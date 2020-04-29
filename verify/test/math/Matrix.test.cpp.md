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


# :heavy_check_mark: test/math/Matrix.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/Matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 07:04:13+09:00


* see: <a href="https://yukicoder.me/problems/no/718">https://yukicoder.me/problems/no/718</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Matrix.cpp.html">lib/math/Matrix.cpp</a>
* :heavy_check_mark: <a href="../../../library/lib/util/ModInt.cpp.html">lib/util/ModInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/718"

#include <vector>
#include <iostream>
#include <array>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/Matrix.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    using modint = ModInt<MOD>;
    array<array<modint,4>,4> a;
    a[0] = {1,2,2,-1};
    a[1] = {0,2,2,-1};
    a[2] = {0,1,0,0};
    a[3] = {0,0,1,0};
    long long N; cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    if(N==2){
        cout << 2 << endl;
        return 0;
    }
    auto s = Matrix<modint,4>::pow(a,N-2);
    cout << s[0][0]*2+s[0][1]+s[0][2] << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/Matrix.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/718"

#include <vector>
#include <iostream>
#include <array>
using namespace std;
#line 1 "lib/util/ModInt.cpp"

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
#line 1 "lib/math/Matrix.cpp"
//Matrix_Repeated_Multiplication_Mod O((N^3)(logK))
template <class T,int N> class Matrix {
public:
    inline static array<array<T,N>,N> pow(array<array<T,N>,N> matrix, long long K){
        array<array<T,N>,N> res,tmp;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res[i][j] = (i == j);
        for (; K > 0; K /= 2) {
            if (K & 1) {
                for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
                for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) tmp[i][j] += matrix[i][k] * res[k][j];
                res = tmp;
            }
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) tmp[i][j] += matrix[i][k] * matrix[k][j];
            matrix = tmp;
        }
        return res;
    }
};

//verify  https://atcoder.jp/contests/dp/tasks/dp_r
#line 9 "test/math/Matrix.test.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    using modint = ModInt<MOD>;
    array<array<modint,4>,4> a;
    a[0] = {1,2,2,-1};
    a[1] = {0,2,2,-1};
    a[2] = {0,1,0,0};
    a[3] = {0,0,1,0};
    long long N; cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }
    if(N==2){
        cout << 2 << endl;
        return 0;
    }
    auto s = Matrix<modint,4>::pow(a,N-2);
    cout << s[0][0]*2+s[0][1]+s[0][2] << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

