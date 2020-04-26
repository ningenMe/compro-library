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


# :warning: non-verified/Ford_Fulkerson.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/Ford_Fulkerson.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:29:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//O(F|E|)

template <class T> class Ford_Fulkerson {
public:
	struct info {
		int to, rev;
		T cap;
	};
	T ini, inf;
	vector<vector<info>> edge;
	vector<bool> visit;

	Ford_Fulkerson(int N, T ini, T inf) : edge(N), visit(N), ini(ini), inf(inf) {
		// do nothing
	}

	void make_edge(int from, int to, T cap) {
		edge[from].push_back({ to, (int)edge[to].size(), cap });
		edge[to].push_back({ from, (int)edge[from].size() - 1, ini });
	}

	T dfs(int from, int goal, T flow) {
		if (from == goal) return flow;
		visit[from] = false;
		for (int i = 0; i < edge[from].size(); ++i) {
			if (visit[edge[from][i].to] && edge[from][i].cap > ini) {
				T dflow = dfs(edge[from][i].to, goal, min(flow, edge[from][i].cap));
				if (dflow > 0) {
					edge[from][i].cap -= dflow;
					edge[edge[from][i].to][edge[from][i].rev].cap += dflow;
					return dflow;
				}
			}
		}
		return ini;
	}

	T maxflow(int start, int goal) {
		T maxflow = ini;
		while (1) {
			for (int i = 0; i < edge.size(); ++i) visit[i] = true;
			T flow = dfs(start, goal, inf);
			if (flow == ini) return maxflow;
			maxflow += flow;
		}
	}
};

//verify https://atcoder.jp/contests/arc085/tasks/arc085_c


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/Ford_Fulkerson.cpp"
#include <bits/stdc++.h>
using namespace std;

//O(F|E|)

template <class T> class Ford_Fulkerson {
public:
	struct info {
		int to, rev;
		T cap;
	};
	T ini, inf;
	vector<vector<info>> edge;
	vector<bool> visit;

	Ford_Fulkerson(int N, T ini, T inf) : edge(N), visit(N), ini(ini), inf(inf) {
		// do nothing
	}

	void make_edge(int from, int to, T cap) {
		edge[from].push_back({ to, (int)edge[to].size(), cap });
		edge[to].push_back({ from, (int)edge[from].size() - 1, ini });
	}

	T dfs(int from, int goal, T flow) {
		if (from == goal) return flow;
		visit[from] = false;
		for (int i = 0; i < edge[from].size(); ++i) {
			if (visit[edge[from][i].to] && edge[from][i].cap > ini) {
				T dflow = dfs(edge[from][i].to, goal, min(flow, edge[from][i].cap));
				if (dflow > 0) {
					edge[from][i].cap -= dflow;
					edge[edge[from][i].to][edge[from][i].rev].cap += dflow;
					return dflow;
				}
			}
		}
		return ini;
	}

	T maxflow(int start, int goal) {
		T maxflow = ini;
		while (1) {
			for (int i = 0; i < edge.size(); ++i) visit[i] = true;
			T flow = dfs(start, goal, inf);
			if (flow == ini) return maxflow;
			maxflow += flow;
		}
	}
};

//verify https://atcoder.jp/contests/arc085/tasks/arc085_c


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

