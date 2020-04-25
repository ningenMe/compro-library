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


# :warning: old/Weighted_Tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/Weighted_Tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 00:30:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template<class T> class Weighted_Tree {
public:
	int N, MAX_bit;
	T ini;
	vector<vector<pair<T,int>>> edge;
	vector<pair<T,int>> depth;
	vector<int> order;
	vector<vector<pair<T,int>>> parent;
	vector<vector<pair<T,int>>> child;

	Weighted_Tree(const int N,  T ini, const int MAX_bit = 20) : N(N), ini(ini) MAX_bit(MAX_bit), edge(N), depth(N, {-1,-1}), order(N, -1), parent(N, vector<pair<T,int>>(MAX_bit)), child(N) {
		//do nothing
	}

	//O(1)
	void make_edge(const int& from, const int& to, const T& w) {
		edge[from].push_back({w,to});
	}

	//O(N)
	void make_depth(const int& root) {
		queue<int> q;
		depth[root] = {0,0};
		q.push(root);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				T w = e.first;
				int to = e.second;
				if (depth[to].second != -1) continue;
				depth[to] = {depth[from].first + w, depth[from].second + 1};
				q.push(to);
			}
		}
	}

	//O(NlogN)
	void make_order(){
		vector<pair<int,int>> tmp(N);
		for (int i = 0; i < N; ++i) tmp[i] = {depth[i].second,i};
		sort(tmp.begin(),tmp.end(),greater<>());
		for (int i = 0; i < N; ++i) order[i] = tmp[i].second;
	}

	//O(MAX_bit*N)
	void make_parent() {
		for (int i = 0; i < N; ++i) parent[i][0] = {ini,i};
		for (int i = 0; i < N; ++i)	for (auto j : edge[i]) {
			if (depth[i].second > depth[j.second].second) parent[i][0] = j;
		}
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1].second][bit - 1];
	}

	//O(N)
	// void make_child() {
	// 	for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);
	// }

	void print() {
		cout << " depth { " << depth[0];
		for (int i = 1; i < N; ++i) cout << ", " << depth[i];
		cout << " }" << endl;

		cout << "parent { " << parent[0][0];
		for (int i = 1; i < N; ++i) cout << ", " << parent[i][0];
		cout << " }" << endl;

		cout << " child { " << child[0];
		for (int i = 1; i < N; ++i) cout << ", " << child[i];
		cout << " }" << endl;
	}

};
//verify 

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/Weighted_Tree.cpp"
#include <bits/stdc++.h>
using namespace std;

template<class T> class Weighted_Tree {
public:
	int N, MAX_bit;
	T ini;
	vector<vector<pair<T,int>>> edge;
	vector<pair<T,int>> depth;
	vector<int> order;
	vector<vector<pair<T,int>>> parent;
	vector<vector<pair<T,int>>> child;

	Weighted_Tree(const int N,  T ini, const int MAX_bit = 20) : N(N), ini(ini) MAX_bit(MAX_bit), edge(N), depth(N, {-1,-1}), order(N, -1), parent(N, vector<pair<T,int>>(MAX_bit)), child(N) {
		//do nothing
	}

	//O(1)
	void make_edge(const int& from, const int& to, const T& w) {
		edge[from].push_back({w,to});
	}

	//O(N)
	void make_depth(const int& root) {
		queue<int> q;
		depth[root] = {0,0};
		q.push(root);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				T w = e.first;
				int to = e.second;
				if (depth[to].second != -1) continue;
				depth[to] = {depth[from].first + w, depth[from].second + 1};
				q.push(to);
			}
		}
	}

	//O(NlogN)
	void make_order(){
		vector<pair<int,int>> tmp(N);
		for (int i = 0; i < N; ++i) tmp[i] = {depth[i].second,i};
		sort(tmp.begin(),tmp.end(),greater<>());
		for (int i = 0; i < N; ++i) order[i] = tmp[i].second;
	}

	//O(MAX_bit*N)
	void make_parent() {
		for (int i = 0; i < N; ++i) parent[i][0] = {ini,i};
		for (int i = 0; i < N; ++i)	for (auto j : edge[i]) {
			if (depth[i].second > depth[j.second].second) parent[i][0] = j;
		}
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1].second][bit - 1];
	}

	//O(N)
	// void make_child() {
	// 	for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);
	// }

	void print() {
		cout << " depth { " << depth[0];
		for (int i = 1; i < N; ++i) cout << ", " << depth[i];
		cout << " }" << endl;

		cout << "parent { " << parent[0][0];
		for (int i = 1; i < N; ++i) cout << ", " << parent[i][0];
		cout << " }" << endl;

		cout << " child { " << child[0];
		for (int i = 1; i < N; ++i) cout << ", " << child[i];
		cout << " }" << endl;
	}

};
//verify 

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

