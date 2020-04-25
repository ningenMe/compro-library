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


# :warning: old/Segment_Tree_Range_Gcd_Query.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/Segment_Tree_Range_Gcd_Query.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 01:48:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template<class T> class Segment_Tree_Range_Gcd_Query {
	size_t N,M;
	T ini;
	vector<T> node;

public:
	Segment_Tree_Range_Gcd_Query(const vector<T> & ar, const T ini) : M(ar.size()), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
		for (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = Gcd(node[2 * i + 1], node[2 * i + 2]);
	}

	Segment_Tree_Range_Gcd_Query(const size_t M, const T ini) : M(M), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
	}

	void update(size_t idx, const T var) {
		idx += (N - 1);
		node[idx] = var;
		while (idx > 0) {
			idx = (idx - 1) / 2;
			node[idx] = Gcd(node[2 * idx + 1], node[2 * idx + 2]);
		}
	}

	T getvar(const int a, const int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = N;
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return node[k];
		T vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);
		return Gcd(vl, vr);
	}

	//Greatest Common Divisor
	T Gcd(T a, T b) {
		return ((b == 0) ? a : Gcd(b, a % b));
	}

	T operator[](size_t idx) {
		return node[idx + N - 1];
	}

	T operator[](pair<size_t, size_t> p) {
		return getvar(p.first, p.second);
	}
	
	void print() {
		cout << "{ " << getvar(0, 1);
		for (int i = 1; i < M; ++i) cout << ", " << getvar(i, i + 1);
		cout << " }" << endl;
	}
};

//verify https://atcoder.jp/contests/abc125/tasks/abc125_c
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/Segment_Tree_Range_Gcd_Query.cpp"
#include <bits/stdc++.h>
using namespace std;

template<class T> class Segment_Tree_Range_Gcd_Query {
	size_t N,M;
	T ini;
	vector<T> node;

public:
	Segment_Tree_Range_Gcd_Query(const vector<T> & ar, const T ini) : M(ar.size()), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
		for (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = Gcd(node[2 * i + 1], node[2 * i + 2]);
	}

	Segment_Tree_Range_Gcd_Query(const size_t M, const T ini) : M(M), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
	}

	void update(size_t idx, const T var) {
		idx += (N - 1);
		node[idx] = var;
		while (idx > 0) {
			idx = (idx - 1) / 2;
			node[idx] = Gcd(node[2 * idx + 1], node[2 * idx + 2]);
		}
	}

	T getvar(const int a, const int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = N;
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return node[k];
		T vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);
		return Gcd(vl, vr);
	}

	//Greatest Common Divisor
	T Gcd(T a, T b) {
		return ((b == 0) ? a : Gcd(b, a % b));
	}

	T operator[](size_t idx) {
		return node[idx + N - 1];
	}

	T operator[](pair<size_t, size_t> p) {
		return getvar(p.first, p.second);
	}
	
	void print() {
		cout << "{ " << getvar(0, 1);
		for (int i = 1; i < M; ++i) cout << ", " << getvar(i, i + 1);
		cout << " }" << endl;
	}
};

//verify https://atcoder.jp/contests/abc125/tasks/abc125_c

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

