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


# :x: test/graph/Dinic.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/Dinic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 02:18:43+09:00


* see: <a href="https://yukicoder.me/problems/no/957">https://yukicoder.me/problems/no/957</a>


## Depends on

* :x: <a href="../../../library/lib/graph/Dinic.cpp.html">Dinic</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/957"

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "../../lib/graph/Dinic.cpp"

int main() {
    int H,W;
    cin >> H >> W;
    vector<long long> R(H),C(W),G(H*W);
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) cin >> G[i*W+j];
    for(int i = 0; i < H; ++i) cin >> R[i];
    for(int j = 0; j < W; ++j) cin >> C[j];
    
	long long ans = 0;
    Dinic<long long> dinic(H+W+2,0,1e15);
    int S = H+W,T = S + 1;
	//i:Sと接続:使う
	//i:Tと接続:使わない
    for(int i = 0; i < H; ++i) {
		long long sum = 0;
		for(int j = 0; j < W; ++j) sum += G[i*W+j];
		ans += R[i];
		if(R[i]>=sum){
			ans -= sum;
		}
		else{
			dinic.make_edge(S,i,sum-R[i]);
			ans -= R[i];
		}
    }
	//j:Sと接続:使う
	//j:Tと接続:使わない
    for(int j = 0; j < W; ++j) {
		ans += C[j];
		dinic.make_edge(H+j,T,C[j]);
    }
	//この供給は常にある
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
			dinic.make_edge(i,H+j,G[i*W+j]);
		}
    }

    ans -= dinic.maxflow(S,T);
    cout << ans << endl;

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/Dinic.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/957"

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
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

#line 8 "test/graph/Dinic.test.cpp"

int main() {
    int H,W;
    cin >> H >> W;
    vector<long long> R(H),C(W),G(H*W);
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) cin >> G[i*W+j];
    for(int i = 0; i < H; ++i) cin >> R[i];
    for(int j = 0; j < W; ++j) cin >> C[j];
    
	long long ans = 0;
    Dinic<long long> dinic(H+W+2,0,1e15);
    int S = H+W,T = S + 1;
	//i:Sと接続:使う
	//i:Tと接続:使わない
    for(int i = 0; i < H; ++i) {
		long long sum = 0;
		for(int j = 0; j < W; ++j) sum += G[i*W+j];
		ans += R[i];
		if(R[i]>=sum){
			ans -= sum;
		}
		else{
			dinic.make_edge(S,i,sum-R[i]);
			ans -= R[i];
		}
    }
	//j:Sと接続:使う
	//j:Tと接続:使わない
    for(int j = 0; j < W; ++j) {
		ans += C[j];
		dinic.make_edge(H+j,T,C[j]);
    }
	//この供給は常にある
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
			dinic.make_edge(i,H+j,G[i*W+j]);
		}
    }

    ans -= dinic.maxflow(S,T);
    cout << ans << endl;

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

