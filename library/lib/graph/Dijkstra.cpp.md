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


# :x: Dijkstra

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/Dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 17:30:34+09:00




## Verified with

* :x: <a href="../../../verify/test/graph/Dijkstra.test.cpp.html">test/graph/Dijkstra.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
 * @title Dijkstra
 * @docs md/graph/Dijkstra.md
 */
template<class T> class Dijkstra {
	vector<long long> num_list;
	vector<long long> sum;
	int N;
	T inf;
	vector<vector<pair<T,int>>> edge;
	vector<T> cost;
public:
	Dijkstra(int N,T inf):inf(inf),num_list(1,N),sum(1,1),N(N){
		edge.resize(N);
		cost.resize(N);
	}
	Dijkstra(initializer_list<long long> size_list,T inf):num_list(size_list),inf(inf),N(1){
		for(long long& e:num_list) N *= e;
		sum.resize(num_list.size(),1);
		for(int i = 0; i < num_list.size(); ++i) {
			for(int j = i + 1; j < num_list.size(); ++j) {
				sum[i] *= num_list[j];
			}
		}
		edge.resize(N);
		cost.resize(N);
	}
	void make_edge(int from, int to, T w) {
		if(from < 0 || N <= from || to < 0 || N <= to) return;
		edge[from].push_back({ w,to });
	}
	void make_edge(initializer_list<long long> from_list, initializer_list<long long> to_list, T w) {
		int from = 0, to = 0;
		auto from_itr = from_list.begin(),to_itr = to_list.begin();
		for(int i = 0; i < num_list.size(); ++i) {
			if(*from_itr < 0 || num_list[i] <= *from_itr || *to_itr < 0 || num_list[i] <= *to_itr) return;
			from += (*from_itr)*sum[i];
			to   += (*to_itr)*sum[i];
			from_itr++;
			to_itr++;
		}
		edge[from].push_back({ w,to });
	}
	void solve(initializer_list<long long> start_list) {
		int start = 0;
		auto start_itr = start_list.begin();
		for(int i = 0; i < num_list.size(); ++i) {
			start += (*start_itr)*sum[i];
			start_itr++;
		}
		solve(start);
	}
	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });
		while (!pq.empty()) {
			auto [v,from] = pq.top();
			pq.pop();
			if(cost[from] < v) continue;
			for (auto [u,to] : edge[from]) {
				T w = v + u;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
	T get(int idx){
		return cost[idx];
	}
	T get(initializer_list<long long> idx_list){
		int idx = 0;
		auto idx_itr = idx_list.begin();
		for(int i = 0; i < num_list.size(); ++i) {
			idx += (*idx_itr)*sum[i];
			idx_itr++;
		}
		return get(idx);
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/Dijkstra.cpp"
/*
 * @title Dijkstra
 * @docs md/graph/Dijkstra.md
 */
template<class T> class Dijkstra {
	vector<long long> num_list;
	vector<long long> sum;
	int N;
	T inf;
	vector<vector<pair<T,int>>> edge;
	vector<T> cost;
public:
	Dijkstra(int N,T inf):inf(inf),num_list(1,N),sum(1,1),N(N){
		edge.resize(N);
		cost.resize(N);
	}
	Dijkstra(initializer_list<long long> size_list,T inf):num_list(size_list),inf(inf),N(1){
		for(long long& e:num_list) N *= e;
		sum.resize(num_list.size(),1);
		for(int i = 0; i < num_list.size(); ++i) {
			for(int j = i + 1; j < num_list.size(); ++j) {
				sum[i] *= num_list[j];
			}
		}
		edge.resize(N);
		cost.resize(N);
	}
	void make_edge(int from, int to, T w) {
		if(from < 0 || N <= from || to < 0 || N <= to) return;
		edge[from].push_back({ w,to });
	}
	void make_edge(initializer_list<long long> from_list, initializer_list<long long> to_list, T w) {
		int from = 0, to = 0;
		auto from_itr = from_list.begin(),to_itr = to_list.begin();
		for(int i = 0; i < num_list.size(); ++i) {
			if(*from_itr < 0 || num_list[i] <= *from_itr || *to_itr < 0 || num_list[i] <= *to_itr) return;
			from += (*from_itr)*sum[i];
			to   += (*to_itr)*sum[i];
			from_itr++;
			to_itr++;
		}
		edge[from].push_back({ w,to });
	}
	void solve(initializer_list<long long> start_list) {
		int start = 0;
		auto start_itr = start_list.begin();
		for(int i = 0; i < num_list.size(); ++i) {
			start += (*start_itr)*sum[i];
			start_itr++;
		}
		solve(start);
	}
	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });
		while (!pq.empty()) {
			auto [v,from] = pq.top();
			pq.pop();
			if(cost[from] < v) continue;
			for (auto [u,to] : edge[from]) {
				T w = v + u;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
	T get(int idx){
		return cost[idx];
	}
	T get(initializer_list<long long> idx_list){
		int idx = 0;
		auto idx_itr = idx_list.begin();
		for(int i = 0; i < num_list.size(); ++i) {
			idx += (*idx_itr)*sum[i];
			idx_itr++;
		}
		return get(idx);
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

