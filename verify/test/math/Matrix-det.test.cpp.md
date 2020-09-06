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


# :heavy_check_mark: test/math/Matrix-det.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/Matrix-det.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 16:23:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/matrix_det">https://judge.yosupo.jp/problem/matrix_det</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Matrix.cpp.html">Matrix</a>
* :heavy_check_mark: <a href="../../../library/lib/util/ModInt.cpp.html">ModInt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <vector>
#include <iostream>
#include <array>
#include <cassert>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/Matrix.cpp"
constexpr long long MOD = 998'244'353;

int main(void){
    using modint = ModInt<MOD>;
    Matrix<modint,500> m=Matrix<modint,500>::E();
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }
    cout << m.determinant() << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/Matrix-det.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <vector>
#include <iostream>
#include <array>
#include <cassert>
using namespace std;
#line 1 "lib/util/ModInt.cpp"
/*
 * @title ModInt
 */
template<long long mod> class ModInt {
public:
	long long x;
	constexpr ModInt():x(0) {}
	constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}
	ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
	ModInt &operator+=(const long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
	ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}
	ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
	ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
	ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}
	ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}
	ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}
	ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return *this;}
	ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return *this;}
	ModInt &operator^=(const long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}
	ModInt &operator^=(const int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}
	ModInt &operator/=(const ModInt &p) {*this *= p.inv();return *this;}
	ModInt &operator/=(const long long y) {ModInt p(y);*this *= p.inv();return *this;}
	ModInt &operator/=(const int y) {ModInt p(y);*this *= p.inv();return *this;}
	ModInt operator=(const int y) {ModInt p(y);*this = p;return *this;}
	ModInt operator=(const long long y) {ModInt p(y);*this = p;return *this;}
	ModInt operator-() const {return ModInt(-x); }
    ModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}
	ModInt operator--() {x--;if(x<0) x+=mod;return *this;}
	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
	ModInt operator^(const ModInt &p) const { return ModInt(*this) ^= p; }
	bool operator==(const ModInt &p) const { return x == p.x; }
	bool operator!=(const ModInt &p) const { return x != p.x; }
	ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}
	ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}
	friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}
	friend istream &operator>>(istream &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}
};
//using modint = ModInt<MOD>;
#line 1 "lib/math/Matrix.cpp"
/*
 * @title Matrix
 */
template <class T, int H, int W = H> class Matrix {
public:
	int h,w;
	array<array<T,W>,H> a;
	Matrix():h(H),w(W){
		// do nothing
	}
	Matrix(const vector<vector<T>>& vec):h(H),w(W) {
		assert(vec.size()==H && vec.front().size()==W);
		for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];
	}
	static Matrix E() {
		assert(H==W);
		Matrix res = Matrix();
		for(int i = 0; i < H; ++i) res[i][i]=1;
		return res;
	}
	Matrix &operator+=(const Matrix &r) {
		assert(H==r.h&&W==r.w);
		for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r[i][j];
		return *this;
	}
	Matrix &operator-=(const Matrix &r) {
		assert(H==r.h&&W==r.w);
		for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r[i][j];
		return *this;
	}
	Matrix &operator*=(const Matrix &r) {
		assert(W==r.h);
		Matrix res = Matrix();
		for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);
		a.swap(res.a);
		return *this;
	}
	Matrix operator+(const Matrix& r) const {
		return Matrix(*this) += r;
	}
	Matrix operator-(const Matrix& r) const {
		return Matrix(*this) -= r;
	}
	Matrix operator*(const Matrix& r) const {
		return Matrix(*this) *= r;
	}
	inline array<T,W> &operator[](int i) { 
		return a[i];
	}
	inline const array<T,W> &operator[](int i) const { 
		return a[i];
	}
	Matrix pow(long long K) const {
		assert(H == W);
		Matrix x(*this);
		Matrix res = this->E();
		for (; K > 0; K /= 2) {
			if (K & 1) res *= x;
			x *= x;
		}
		return res;
	}
	T determinant(void) const {
		assert(H==W);
		Matrix x(*this);
		T res = 1;
		for(int i = 0; i < H; i++) {
			int idx = -1;
			for(int j = i; j < W; j++) if(x[j][i] != 0) idx = j;
			if(idx == -1) return 0;
			if(i != idx) {
				res *= -1;
				swap(x[i], x[idx]);
			}
			res *= x[i][i];
			T tmp = x[i][i];
			for(int j = 0; j < W; ++j) x[i][j] /= tmp;
			for(int j = i + 1; j < H; j++) {
				tmp = x[j][i];
				for(int k = 0; k < W; k++) x[j][k] -= x[i][k]*tmp;
			}
		}
		return res;
	}
};
#line 10 "test/math/Matrix-det.test.cpp"
constexpr long long MOD = 998'244'353;

int main(void){
    using modint = ModInt<MOD>;
    Matrix<modint,500> m=Matrix<modint,500>::E();
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> m[i][j];
        }
    }
    cout << m.determinant() << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

