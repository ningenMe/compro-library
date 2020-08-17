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


# :x: test/graph/MinimumDirectedClosedCircuit.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/MinimumDirectedClosedCircuit.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-18 01:37:07+09:00




## Depends on

* :x: <a href="../../../library/lib/graph/MinimumDirectedClosedCircuit.cpp.html">MinimumDirectedClosedCircuit</a>
* :question: <a href="../../../library/lib/graph/StronglyConnectedComponents.cpp.html">StronglyConnectedComponents</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#define IGNORE

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#include "../../lib/graph/StronglyConnectedComponents.cpp"
#include "../../lib/graph/MinimumDirectedClosedCircuit.cpp"

int main(){
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N);
    MinimumDirectedClosedCircuit dcc(N);
    map<pair<int,int>,int> mp;
    for(int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        scc.make_edge(u,v);
        dcc.make_edge(u,v);
        mp[{u,v}]=i;
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    if(*max_element(cnt.begin(),cnt.end())==1){
		cout << -1 << endl;
        return 0;
    };
    int label=max_element(cnt.begin(),cnt.end())-cnt.begin();
    int root;
    for(int i = 0; i < N; ++i) if(scc[i]==label) root=i;
    auto ans = dcc.solve(root);
    int L = ans.size();
    cout << L << endl;
    for(int i = 0; i < L; ++i) cout << mp[{ans[i],ans[(i+1)%L]}] << endl;
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/MinimumDirectedClosedCircuit.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#define IGNORE

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#line 1 "lib/graph/StronglyConnectedComponents.cpp"
/*
 * @title StronglyConnectedComponents
 */
class StronglyConnectedComponents{
	int num,is_2sat,half;
	vector<vector<int>> edge,redge;

	vector<int> label,visited,order;

	inline void dfs(int curr){
		visited[curr] = 1;
		for(int next:edge[curr]) if(!visited[next]) dfs(next);
		order.push_back(curr);
	}

	inline void rdfs(int curr,int id){
		visited[curr] = 1;
		label[curr] = id;
		for(int next:redge[curr]) if(!visited[next]) rdfs(next,id);
	}
	inline int rev(int i) { return i < half ? i + half : i - half; }
public:

	StronglyConnectedComponents(const int n, bool is_2sat=0):num(n),is_2sat(is_2sat){
		if(is_2sat) num*=2;
		edge.resize(num);
		redge.resize(num);
		label.resize(num);
		visited.resize(num);
		half=num/2;
	}
	inline int operator[](int idx) {
		return label[idx];
	}
	inline void make_edge(const int from,const int to) {
		edge[from].push_back(to);
		redge[to].push_back(from);
	}
	inline void make_condition(int x, bool flg_x, int y, bool flg_y) {
		if (!flg_x) x = rev(x);
		if (!flg_y) y = rev(y);
		make_edge(x, y);
		make_edge(rev(y), rev(x));
	}
	inline int solve(void) {
		for(int i = 0; i < num; ++i) visited[i] = 0;
		for(int i = 0; i < num; ++i) if(!visited[i]) dfs(i);
		for(int i = 0; i < num; ++i) visited[i] = 0;
		reverse(order.begin(),order.end());
		int id = 0;
		for(int i:order) if(!visited[i]) rdfs(i,id++);
		if(!is_2sat) return true;
		for (int i = 0; i < num; ++i) if (label[i] == label[rev(i)]) return false;
		return true;
	}
	int is_true(int i) {
		return label[i] > label[rev(i)];
	}
	void print(void) {
		for(auto id:label) cout << id << " ";
		cout << endl;
	}

};
#line 1 "lib/graph/MinimumDirectedClosedCircuit.cpp"
/*
 * @title MinimumDirectedClosedCircuit
 * @docs md/graph/MinimumDirectedClosedCircuit.md
 */
class MinimumDirectedClosedCircuit {
	vector<vector<int>> edge,redge;  
	vector<int> dist;
	size_t N;
public:
	MinimumDirectedClosedCircuit(size_t N) : N(N),edge(N),redge(N),dist(N) {
		//do nothing
	}
	inline void make_edge(int from,int to){
		edge[from].push_back(to);
		redge[to].push_back(from);
	}
	//rootを含む最小閉路の集合を返す O(N) 閉路がないときは空集合
	inline vector<int> solve(int root,int inf = 123456789){
		int mini = inf, last = -1;
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
#line 13 "test/graph/MinimumDirectedClosedCircuit.test.cpp"

int main(){
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N);
    MinimumDirectedClosedCircuit dcc(N);
    map<pair<int,int>,int> mp;
    for(int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        scc.make_edge(u,v);
        dcc.make_edge(u,v);
        mp[{u,v}]=i;
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    if(*max_element(cnt.begin(),cnt.end())==1){
		cout << -1 << endl;
        return 0;
    };
    int label=max_element(cnt.begin(),cnt.end())-cnt.begin();
    int root;
    for(int i = 0; i < N; ++i) if(scc[i]==label) root=i;
    auto ans = dcc.solve(root);
    int L = ans.size();
    cout << L << endl;
    for(int i = 0; i < L; ++i) cout << mp[{ans[i],ans[(i+1)%L]}] << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

