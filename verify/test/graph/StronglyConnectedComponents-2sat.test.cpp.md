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


# :x: test/graph/StronglyConnectedComponents-2sat.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/StronglyConnectedComponents-2sat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-13 00:33:57+09:00




## Depends on

* :question: <a href="../../../library/lib/graph/StronglyConnectedComponents.cpp.html">StronglyConnectedComponents</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1078"
#define IGNORE

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#include "../../lib/graph/StronglyConnectedComponents.cpp"

int main(){
	int N; cin >> N;
	//[0,N*N)       i番目は0
	//[N*N,2*N*N)   i番目は1
	StronglyConnectedComponents scc(N*N,1);
	vector<int> S(N),T(N),U(N);
	for(int i = 0; i < N; ++i) cin >> S[i],S[i]--;
	for(int i = 0; i < N; ++i) cin >> T[i],T[i]--;
	for(int i = 0; i < N; ++i) cin >> U[i];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			int a=S[i],b=j,c=j,d=T[i];
			int s=a*N+b,t=c*N+d;
			if(U[i]==0) {
				//ab=0&&cd=0がだめ
				scc.make_condition(s,0,t,1);
			}
			if(U[i]==1) {
				//ab=1&&cd=0がだめ
				scc.make_condition(s,1,t,1);
			}
			if(U[i]==2) {
				//ab=0&&cd=1がだめ
				scc.make_condition(s,0,t,0);
			}
			if(U[i]==3) {
				//ab=1&&cd=1がだめ
				scc.make_condition(s,1,t,0);
			}
		}
	}
	int flg = scc.solve();
	if(!flg){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cout << scc.is_true(i*N+j) << " ";
		}
		cout << endl;
	}

	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/StronglyConnectedComponents-2sat.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1078"
#define IGNORE

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
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
#line 10 "test/graph/StronglyConnectedComponents-2sat.test.cpp"

int main(){
	int N; cin >> N;
	//[0,N*N)       i番目は0
	//[N*N,2*N*N)   i番目は1
	StronglyConnectedComponents scc(N*N,1);
	vector<int> S(N),T(N),U(N);
	for(int i = 0; i < N; ++i) cin >> S[i],S[i]--;
	for(int i = 0; i < N; ++i) cin >> T[i],T[i]--;
	for(int i = 0; i < N; ++i) cin >> U[i];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			int a=S[i],b=j,c=j,d=T[i];
			int s=a*N+b,t=c*N+d;
			if(U[i]==0) {
				//ab=0&&cd=0がだめ
				scc.make_condition(s,0,t,1);
			}
			if(U[i]==1) {
				//ab=1&&cd=0がだめ
				scc.make_condition(s,1,t,1);
			}
			if(U[i]==2) {
				//ab=0&&cd=1がだめ
				scc.make_condition(s,0,t,0);
			}
			if(U[i]==3) {
				//ab=1&&cd=1がだめ
				scc.make_condition(s,1,t,0);
			}
		}
	}
	int flg = scc.solve();
	if(!flg){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cout << scc.is_true(i*N+j) << " ";
		}
		cout << endl;
	}

	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

