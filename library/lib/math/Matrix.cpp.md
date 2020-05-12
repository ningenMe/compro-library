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
    - Last commit date: 2020-05-13 02:48:46+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/math/Matrix.test.cpp.html">test/math/Matrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
 * @title Matrix
 */
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/math/Matrix.cpp"
/*
 * @title Matrix
 */
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

