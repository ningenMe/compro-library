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


# :warning: non-verified/Union_Find_Tree_With_Potential.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/Union_Find_Tree_With_Potential.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:29:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Union Find Tree With Potential
template<class T> class Union_Find_Tree_With_Potential {
public:
	vector<int> parent;
	vector<int> rank;
	vector<T> dist;

	Union_Find_Tree_With_Potential(int N = 1, T ini = 0) :parent(N), rank(N,0), dist(N, ini) {
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	int root(int x) {
		if (parent[x] == x) return x;
		else {
			int r = root(parent[x]);
			dist[x] += dist[parent[x]];
			return parent[x] = r;
		}
	}

	T updated_dist(int x) {
		root(x);
		return dist[x];
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y, T d = 0) {
		d += updated_dist(x);
		d -= updated_dist(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) {
			swap(x, y);
			d = -d;
		}
		if (rank[x] == rank[y]) ++rank[x];
		parent[y] = x;
		dist[y] = d;
		return true;
	}

	T diff(int x, int y) {
		return updated_dist(y) - updated_dist(x);
	}
};

//verify https://atcoder.jp/contests/abc087/tasks/arc090_b 
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/Union_Find_Tree_With_Potential.cpp"
#include <bits/stdc++.h>
using namespace std;

//Union Find Tree With Potential
template<class T> class Union_Find_Tree_With_Potential {
public:
	vector<int> parent;
	vector<int> rank;
	vector<T> dist;

	Union_Find_Tree_With_Potential(int N = 1, T ini = 0) :parent(N), rank(N,0), dist(N, ini) {
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	int root(int x) {
		if (parent[x] == x) return x;
		else {
			int r = root(parent[x]);
			dist[x] += dist[parent[x]];
			return parent[x] = r;
		}
	}

	T updated_dist(int x) {
		root(x);
		return dist[x];
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y, T d = 0) {
		d += updated_dist(x);
		d -= updated_dist(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) {
			swap(x, y);
			d = -d;
		}
		if (rank[x] == rank[y]) ++rank[x];
		parent[y] = x;
		dist[y] = d;
		return true;
	}

	T diff(int x, int y) {
		return updated_dist(y) - updated_dist(x);
	}
};

//verify https://atcoder.jp/contests/abc087/tasks/arc090_b 

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

