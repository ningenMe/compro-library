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


# :warning: non-verified/MinimumDirectedClosedCircuit.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/MinimumDirectedClosedCircuit.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:29:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//重みなし有向グラフの最小閉路を求めるクラス
class MinimumDirectedClosedCircuit {
	vector<vector<int>> edge,redge;  
	vector<int> dist;
	size_t N;
public:
	MinimumDirectedClosedCircuit(size_t N) : N(N),edge(N),redge(N),dist(N) {
		//do nothing
	}
	void makeEdge(int from,int to){
		edge[from].push_back(to);
		redge[to].push_back(from);
	}
	//rootを含む最小閉路の集合を返す O(N) 閉路がないときは空集合
	vector<int> solve(int root,int inf = 123456789){
		int mini = inf;
		int last = -1;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<int> q;
		q.push(root);
		dist[root] = 0;
		while (q.size()) {
			int curr = q.front();
			q.pop();
			for(int next:edge[curr]){
				if(next == root && mini > dist[curr]+1) mini = dist[curr]+1,last = curr;
				if(dist[next]==-1) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}
		vector<int> res;
		if(last != -1){
			res.push_back(last);
			int curr = last;
			while(curr != root){
				for(int next:redge[curr]){
					if(dist[next]+1==dist[curr]) {
						res.push_back(next);
						curr = next;
						break;
					}
				}
			}
			reverse(res.begin(),res.end());
		}
		return res;
	}
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/MinimumDirectedClosedCircuit.cpp"

//重みなし有向グラフの最小閉路を求めるクラス
class MinimumDirectedClosedCircuit {
	vector<vector<int>> edge,redge;  
	vector<int> dist;
	size_t N;
public:
	MinimumDirectedClosedCircuit(size_t N) : N(N),edge(N),redge(N),dist(N) {
		//do nothing
	}
	void makeEdge(int from,int to){
		edge[from].push_back(to);
		redge[to].push_back(from);
	}
	//rootを含む最小閉路の集合を返す O(N) 閉路がないときは空集合
	vector<int> solve(int root,int inf = 123456789){
		int mini = inf;
		int last = -1;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<int> q;
		q.push(root);
		dist[root] = 0;
		while (q.size()) {
			int curr = q.front();
			q.pop();
			for(int next:edge[curr]){
				if(next == root && mini > dist[curr]+1) mini = dist[curr]+1,last = curr;
				if(dist[next]==-1) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}
		vector<int> res;
		if(last != -1){
			res.push_back(last);
			int curr = last;
			while(curr != root){
				for(int next:redge[curr]){
					if(dist[next]+1==dist[curr]) {
						res.push_back(next);
						curr = next;
						break;
					}
				}
			}
			reverse(res.begin(),res.end());
		}
		return res;
	}
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

