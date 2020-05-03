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


# :x: test/graph/StronglyConnectedComponents.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/StronglyConnectedComponents.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 01:17:52+09:00


* see: <a href="https://yukicoder.me/problems/no/1023">https://yukicoder.me/problems/no/1023</a>


## Depends on

* :x: <a href="../../../library/lib/graph/StronglyConnectedComponents.cpp.html">lib/graph/StronglyConnectedComponents.cpp</a>
* :question: <a href="../../../library/lib/graph/UnionFindTree.cpp.html">lib/graph/UnionFindTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1023"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#include "../../lib/graph/UnionFindTree.cpp"
#include "../../lib/graph/StronglyConnectedComponents.cpp"

int main(){
    int N,M; cin >> N >> M;
    vector<pair<int,int>> edge;
    vector<pair<int,int>> bedge;
    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        int c; cin >> c;
        if(c==1){
            bedge.push_back({a,b});
        }
        else{
            edge.push_back({a,b});
        }
    }
    UnionFindTree uf(N);
    for(auto& e:bedge){
        int a = e.first,b = e.second;
        if(uf.same(a,b)){
            cout << "Yes" << endl;
        };
        uf.unite(a,b);
    }
    StronglyConnectedComponents scc(N);
    for(auto& e:edge){
        int a = e.first,b = e.second;
        if(uf.same(a,b)){
            cout << "Yes" << endl;
            return 0;
        };
        scc.makeEdge(uf.root(a),uf.root(b));
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    for(int i = 0; i < N; ++i) if(cnt[i] > 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl; 
    return 0;}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/StronglyConnectedComponents.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1023"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#line 1 "lib/graph/UnionFindTree.cpp"
//Union Find Tree
class UnionFindTree {
public:
	vector<int> parent;
	vector<int> rank;

	UnionFindTree(int N) : parent(N), rank(N,0){
		iota(parent.begin(),parent.end(),0);
	} 
	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}
	inline int same(int n, int m) {
		return root(n) == root(m);
	}
	inline void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if (rank[n]<rank[m]) {
			parent[n] = m;
		}
		else{
			parent[m] = n;
			if(rank[n] == rank[m]) rank[n]++;
		}
	}
};
#line 1 "lib/graph/StronglyConnectedComponents.cpp"

class StronglyConnectedComponents{
    int num;
    vector<vector<int>> edge,redge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int label_id){
        visited[curr] = 1;
        label[curr] = label_id;
        for(int next:redge[curr]) if(!visited[next]) revDfs(next,label_id);
    }

public:

	StronglyConnectedComponents(const int& num) : 
    num(num), edge(num), redge(num), label(num), visited(num) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        redge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < num; ++i) visited[i] = 0;
        for(int i = 0; i < num; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < num; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int label_id = 0;
        for(int i:order) if(!visited[i]) revDfs(i,label_id++);
    }

    void print(void) {
        for(auto label_id:label) cout << label_id << " ";
        cout << endl;
    }

};
#line 10 "test/graph/StronglyConnectedComponents.test.cpp"

int main(){
    int N,M; cin >> N >> M;
    vector<pair<int,int>> edge;
    vector<pair<int,int>> bedge;
    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        int c; cin >> c;
        if(c==1){
            bedge.push_back({a,b});
        }
        else{
            edge.push_back({a,b});
        }
    }
    UnionFindTree uf(N);
    for(auto& e:bedge){
        int a = e.first,b = e.second;
        if(uf.same(a,b)){
            cout << "Yes" << endl;
        };
        uf.unite(a,b);
    }
    StronglyConnectedComponents scc(N);
    for(auto& e:edge){
        int a = e.first,b = e.second;
        if(uf.same(a,b)){
            cout << "Yes" << endl;
            return 0;
        };
        scc.makeEdge(uf.root(a),uf.root(b));
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    for(int i = 0; i < N; ++i) if(cnt[i] > 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl; 
    return 0;}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

