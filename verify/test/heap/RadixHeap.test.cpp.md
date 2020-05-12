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


# :heavy_check_mark: test/heap/RadixHeap.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a2bf5cb1737b82034660168b413e4164">test/heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/heap/RadixHeap.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 02:48:46+09:00


* see: <a href="https://yukicoder.me/problems/no/807">https://yukicoder.me/problems/no/807</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/heap/RadixHeap.cpp.html">RadixHeap</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/807"

#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/heap/RadixHeap.cpp"

//Dijkstra
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf), cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for (int i = 0; i < N; ++i) cost[i] = inf;

		RadixHeap<int> pq(0);
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			auto p = pq.pop();
			T v = p.first;
			int from = p.second;
			if(cost[from]<v) continue;
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	Dijkstra<long long> dijk(2*N, 1LL<<60);
	for(int i = 0; i < M; ++i){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		a--, b--;
		dijk.make_edge(a, b, c);
		dijk.make_edge(b, a, c);
		dijk.make_edge(a+N, b+N, c);
		dijk.make_edge(b+N, a+N, c);
		dijk.make_edge(a, b+N, 0);
		dijk.make_edge(b, a+N, 0);
	}
	dijk.solve(0);
	dijk.cost[N]=0;
	for (int i = 0; i < N; ++i) cout << dijk.cost[i]+dijk.cost[i+N] << endl;

	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/heap/RadixHeap.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/807"

#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
#line 1 "lib/heap/RadixHeap.cpp"
/*
 * @title RadixHeap
 */
template<class T> class RadixHeap{
	using TypeNode = pair<unsigned long long, T>;
	array<vector<TypeNode>,65> vq;
	unsigned long long size_num;
	TypeNode last;
	inline int bit(unsigned long long a) {
		return a ? 64 - __builtin_clzll(a) : 0;
	}
public:
	RadixHeap(T mini) : size_num(0), last(make_pair(0,mini)) {
		// do nothing
	}
	inline bool empty() {
		return size_num == 0;
	}
	inline size_t size(){
		return size_num;
	}
	inline void push(TypeNode x){
		++size_num;
		vq[bit(x.first^last.first)].push_back(x);
	}
	inline void emplace(unsigned long long key,T val){
		++size_num;
		vq[bit(key^last.first)].emplace_back(key,val);
	}
	inline TypeNode pop() {
		if(vq[0].empty()) {
			int i = 1;
			while(vq[i].empty()) ++i;
			last = *min_element(vq[i].begin(),vq[i].end());
			for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);
			vq[i].clear();
		}
		--size_num;
		auto res = vq[0].back();
		vq[0].pop_back();
		return res;
	}
};
#line 9 "test/heap/RadixHeap.test.cpp"

//Dijkstra
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf), cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for (int i = 0; i < N; ++i) cost[i] = inf;

		RadixHeap<int> pq(0);
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			auto p = pq.pop();
			T v = p.first;
			int from = p.second;
			if(cost[from]<v) continue;
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	Dijkstra<long long> dijk(2*N, 1LL<<60);
	for(int i = 0; i < M; ++i){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		a--, b--;
		dijk.make_edge(a, b, c);
		dijk.make_edge(b, a, c);
		dijk.make_edge(a+N, b+N, c);
		dijk.make_edge(b+N, a+N, c);
		dijk.make_edge(a, b+N, 0);
		dijk.make_edge(b, a+N, 0);
	}
	dijk.solve(0);
	dijk.cost[N]=0;
	for (int i = 0; i < N; ++i) cout << dijk.cost[i]+dijk.cost[i+N] << endl;

	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

