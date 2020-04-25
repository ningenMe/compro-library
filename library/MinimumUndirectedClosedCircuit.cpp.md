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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: MinimumUndirectedClosedCircuit.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/MinimumUndirectedClosedCircuit.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-16 00:44:56+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//重みなし無効グラフの最小閉路を求めるクラス
class MinimumUndirectedClosedCircuit {
	vector<vector<int>> edge;
	vector<int> dist;
	size_t N;
public:
	MinimumUndirectedClosedCircuit(size_t N) : N(N),edge(N),dist(N) {
		//do nothing
	}
	void makeEdge(int from,int to){
		edge[from].push_back(to);
	}
	//rootを含む最小閉路の長さを返す O(N) 閉路がないときは空集合
	vector<int> solve(int root,int inf = 123456789){
		int mini = inf;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<pair<int,int>> q;
		q.push({root,-1});
		dist[root] = 0;
		pair<int,int> last = make_pair(-1,-1);
		while (q.size()) {
			int curr = q.front().first;
			int prev = q.front().second;
			q.pop();
			for(int next:edge[curr]){
				if(next==prev) continue;
				if(dist[next]==-1) {
					dist[next] = dist[curr] + 1;
					q.push({next,curr});
				}
				else{
					if(mini > dist[curr]+dist[next]+1){
						mini = dist[curr]+dist[next]+1;
						last = make_pair(curr,next);
					}
				}
			}
		}
		vector<int> idxl,idxr,res;
		if(last != make_pair(-1,-1)){
			queue<int> l;
			stack<int> r;
			int curr;
			curr = last.first;
			while(curr != root){
				l.push(curr);
				for(int next:edge[curr]){
					if(dist[next]+1==dist[curr]) {
						curr = next;
						break;
					}
				}
			}
			curr = last.second;
			while(curr != root){
				r.push(curr);
				for(int next:edge[curr]){
					if(dist[next]+1==dist[curr]) {
						curr = next;
						break;
					}
				}
			}
			while (l.size()) {
				res.push_back(l.front());
				l.pop();
			}
			res.push_back(root);			
			while (r.size()) {
				res.push_back(r.top());
				r.pop();
			}
		}
		return res;
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "MinimumUndirectedClosedCircuit.cpp"

//重みなし無効グラフの最小閉路を求めるクラス
class MinimumUndirectedClosedCircuit {
	vector<vector<int>> edge;
	vector<int> dist;
	size_t N;
public:
	MinimumUndirectedClosedCircuit(size_t N) : N(N),edge(N),dist(N) {
		//do nothing
	}
	void makeEdge(int from,int to){
		edge[from].push_back(to);
	}
	//rootを含む最小閉路の長さを返す O(N) 閉路がないときは空集合
	vector<int> solve(int root,int inf = 123456789){
		int mini = inf;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<pair<int,int>> q;
		q.push({root,-1});
		dist[root] = 0;
		pair<int,int> last = make_pair(-1,-1);
		while (q.size()) {
			int curr = q.front().first;
			int prev = q.front().second;
			q.pop();
			for(int next:edge[curr]){
				if(next==prev) continue;
				if(dist[next]==-1) {
					dist[next] = dist[curr] + 1;
					q.push({next,curr});
				}
				else{
					if(mini > dist[curr]+dist[next]+1){
						mini = dist[curr]+dist[next]+1;
						last = make_pair(curr,next);
					}
				}
			}
		}
		vector<int> idxl,idxr,res;
		if(last != make_pair(-1,-1)){
			queue<int> l;
			stack<int> r;
			int curr;
			curr = last.first;
			while(curr != root){
				l.push(curr);
				for(int next:edge[curr]){
					if(dist[next]+1==dist[curr]) {
						curr = next;
						break;
					}
				}
			}
			curr = last.second;
			while(curr != root){
				r.push(curr);
				for(int next:edge[curr]){
					if(dist[next]+1==dist[curr]) {
						curr = next;
						break;
					}
				}
			}
			while (l.size()) {
				res.push_back(l.front());
				l.pop();
			}
			res.push_back(root);			
			while (r.size()) {
				res.push_back(r.top());
				r.pop();
			}
		}
		return res;
	}
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

