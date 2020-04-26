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


# :warning: unverified/BipartiteMatching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/BipartiteMatching.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class BipartiteMatching {
	vector<vector<int>> edge;
	vector<int> match, used;
    size_t N;

    int dfs(int prev) {
        used[prev] = 1;
        for(int curr:edge[prev]){
            int next = match[curr];
            if(next < 0 || (!used[next] && dfs(next)) ) {
                match[prev] = curr;
                match[curr] = prev;
                return 1;
            }
        }
        return 0;
    }

public:

	BipartiteMatching(int N) : N(N), edge(N), match(N,-1), used(N) {
		// do nothing
	}

	void makeEdge(int from, int to) {
		edge[from].push_back(to);
	}

	int maxFlow() {
		int res = 0;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) {
                for(int j = 0; j < N; ++j) used[j] = 0;
                if(dfs(i)) res++;
            }
        }
        return res;
	}

    vector<pair<int,int>> restoration(){
        vector<pair<int,int>> vp;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) continue;
            if(i < match[i]) vp.push_back({i,match[i]});
        }
        return vp;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/BipartiteMatching.cpp"

class BipartiteMatching {
	vector<vector<int>> edge;
	vector<int> match, used;
    size_t N;

    int dfs(int prev) {
        used[prev] = 1;
        for(int curr:edge[prev]){
            int next = match[curr];
            if(next < 0 || (!used[next] && dfs(next)) ) {
                match[prev] = curr;
                match[curr] = prev;
                return 1;
            }
        }
        return 0;
    }

public:

	BipartiteMatching(int N) : N(N), edge(N), match(N,-1), used(N) {
		// do nothing
	}

	void makeEdge(int from, int to) {
		edge[from].push_back(to);
	}

	int maxFlow() {
		int res = 0;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) {
                for(int j = 0; j < N; ++j) used[j] = 0;
                if(dfs(i)) res++;
            }
        }
        return res;
	}

    vector<pair<int,int>> restoration(){
        vector<pair<int,int>> vp;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) continue;
            if(i < match[i]) vp.push_back({i,match[i]});
        }
        return vp;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

