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


# :warning: old/UnionFindTreeMerge.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/UnionFindTreeMerge.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 06:33:25+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp


//Union Find Tree
template<class T> class UnionFindTreeMerge {
public:
	vector<int> parent;
    vector<int> rank;
    vector<T> value;

    UnionFindTreeMerge(int N) : parent(N), rank(N,0), value(N){
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	void setValue(int n, T v) {
		value[n] = v;
	}

	T rootValue(int n) {
		return value[root(n)];
	}

	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}

    int same(int n, int m) {
		return root(n) == root(m);
	}
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(rank[n]<rank[m]) {
            parent[n] = m;
			value[m] += value[n];
        }
        else{
            parent[m] = n;
			value[n] += value[m];
            if(rank[n] == rank[m]) rank[n]++;
        }
	}
};

//verify https://atcoder.jp/contests/abc097/tasks/arc097_b

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/UnionFindTreeMerge.cpp"


//Union Find Tree
template<class T> class UnionFindTreeMerge {
public:
	vector<int> parent;
    vector<int> rank;
    vector<T> value;

    UnionFindTreeMerge(int N) : parent(N), rank(N,0), value(N){
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	void setValue(int n, T v) {
		value[n] = v;
	}

	T rootValue(int n) {
		return value[root(n)];
	}

	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}

    int same(int n, int m) {
		return root(n) == root(m);
	}
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(rank[n]<rank[m]) {
            parent[n] = m;
			value[m] += value[n];
        }
        else{
            parent[m] = n;
			value[n] += value[m];
            if(rank[n] == rank[m]) rank[n]++;
        }
	}
};

//verify https://atcoder.jp/contests/abc097/tasks/arc097_b

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

