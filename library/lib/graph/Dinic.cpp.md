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


# :heavy_check_mark: Dinic

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/Dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 02:18:43+09:00




##### Dinic(int N, T ini, T inf)  
- コンストラクタ  
##### inline void make_edge(int from, int to, T cap)  
- from から to に容量 cap の辺を張る  
##### inline T maxflow(int start, int goal)  
- start から goal への最大流  

## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/Dinic.test.cpp.html">test/graph/Dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
 * @title Dinic
 * @docs md/graph/Dinic.md
 */
template <class T> class Dinic {
	struct info {
		int to, rev;
		T cap;
	};
	T ini, inf;
	vector<vector<info>> edge;
	vector<int> level, iter;

	inline void bfs(int start) {
		for (int i = 0; i < level.size(); ++i) level[i] = -1;
		queue<int> q;
		level[start] = 0;
		q.push(start);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[from] + 1;
					q.push(e.to);
				}
			}
		}
	}

	inline T dfs(int from, int goal, T flow) {
		if (from == goal) return flow;
		for (int& i = iter[from]; i < edge[from].size(); ++i) {
			auto& e = edge[from][i];
			if (e.cap <= 0 || level[from] >= level[e.to]) continue;
			T dflow = dfs(e.to, goal, min(flow, e.cap));
			if (dflow <= 0) continue;
			e.cap -= dflow;
			edge[e.to][e.rev].cap += dflow;
			return dflow;
		}
		return ini;
	}

public:
	Dinic(int N, T ini, T inf) : edge(N), level(N), iter(N), ini(ini), inf(inf) {
		// do nothing
	}

	inline void make_edge(int from, int to, T cap) {
		edge[from].push_back({ to, (int)edge[to].size(), cap });
		edge[to].push_back({ from, (int)edge[from].size() - 1, ini });
	}

	inline T maxflow(int start, int goal) {
		T maxflow = ini;
		while (1) {
			bfs(start);
			if (level[goal] < 0) return maxflow;
			for (int i = 0; i < iter.size(); ++i) iter[i] = 0;
			T flow;
			while ((flow = dfs(start, goal, inf))>0) maxflow += flow;
		}
	}
};

//verify https://atcoder.jp/contests/arc085/tasks/arc085_c


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/Dinic.cpp"
/*
 * @title Dinic
 * @docs md/graph/Dinic.md
 */
template <class T> class Dinic {
	struct info {
		int to, rev;
		T cap;
	};
	T ini, inf;
	vector<vector<info>> edge;
	vector<int> level, iter;

	inline void bfs(int start) {
		for (int i = 0; i < level.size(); ++i) level[i] = -1;
		queue<int> q;
		level[start] = 0;
		q.push(start);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[from] + 1;
					q.push(e.to);
				}
			}
		}
	}

	inline T dfs(int from, int goal, T flow) {
		if (from == goal) return flow;
		for (int& i = iter[from]; i < edge[from].size(); ++i) {
			auto& e = edge[from][i];
			if (e.cap <= 0 || level[from] >= level[e.to]) continue;
			T dflow = dfs(e.to, goal, min(flow, e.cap));
			if (dflow <= 0) continue;
			e.cap -= dflow;
			edge[e.to][e.rev].cap += dflow;
			return dflow;
		}
		return ini;
	}

public:
	Dinic(int N, T ini, T inf) : edge(N), level(N), iter(N), ini(ini), inf(inf) {
		// do nothing
	}

	inline void make_edge(int from, int to, T cap) {
		edge[from].push_back({ to, (int)edge[to].size(), cap });
		edge[to].push_back({ from, (int)edge[from].size() - 1, ini });
	}

	inline T maxflow(int start, int goal) {
		T maxflow = ini;
		while (1) {
			bfs(start);
			if (level[goal] < 0) return maxflow;
			for (int i = 0; i < iter.size(); ++i) iter[i] = 0;
			T flow;
			while ((flow = dfs(start, goal, inf))>0) maxflow += flow;
		}
	}
};

//verify https://atcoder.jp/contests/arc085/tasks/arc085_c


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

