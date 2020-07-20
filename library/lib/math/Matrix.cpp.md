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


# :heavy_check_mark: Matrix

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b524a7b47b8ed72180f0e5150ab6d934">lib/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/math/Matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-21 06:48:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/math/Matrix.test.cpp.html">test/math/Matrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
    Matrix(const Matrix& matrix):h(H),w(W) {
        assert(H==matrix.h&&W==matrix.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=matrix.a[i][j];
    }
    static Matrix E() {
        assert(H==W);
        Matrix<T,H,W> res = Matrix();
        for(int i = 0; i < H; ++i) res.a[i][i]=1;
        return res;
    }
    Matrix &operator+=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r.a[i][j];
		return *this;
	}
    Matrix &operator-=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r.a[i][j];
		return *this;
	}
    Matrix &operator*=(const Matrix &r) {
        assert(W==r.h);
        Matrix res = Matrix();
        for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res.a[i][j]+=a[i][k]*r.a[k][j];
        a=res.a;
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
    Matrix pow(long long K) const {
        assert(H == W);
        Matrix x = *this;
        Matrix res = this->E();
        for (; K > 0; K /= 2) {
            if (K & 1) res *= x;
            x *= x;
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
    Matrix(const Matrix& matrix):h(H),w(W) {
        assert(H==matrix.h&&W==matrix.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=matrix.a[i][j];
    }
    static Matrix E() {
        assert(H==W);
        Matrix<T,H,W> res = Matrix();
        for(int i = 0; i < H; ++i) res.a[i][i]=1;
        return res;
    }
    Matrix &operator+=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r.a[i][j];
		return *this;
	}
    Matrix &operator-=(const Matrix &r) {
        assert(H==r.h&&W==r.w);
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r.a[i][j];
		return *this;
	}
    Matrix &operator*=(const Matrix &r) {
        assert(W==r.h);
        Matrix res = Matrix();
        for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res.a[i][j]+=a[i][k]*r.a[k][j];
        a=res.a;
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
    Matrix pow(long long K) const {
        assert(H == W);
        Matrix x = *this;
        Matrix res = this->E();
        for (; K > 0; K /= 2) {
            if (K & 1) res *= x;
            x *= x;
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

