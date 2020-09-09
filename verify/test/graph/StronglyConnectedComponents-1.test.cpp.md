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


# :heavy_check_mark: test/graph/StronglyConnectedComponents-1.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/StronglyConnectedComponents-1.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 02:59:35+09:00


* see: <a href="https://yukicoder.me/problems/no/1023">https://yukicoder.me/problems/no/1023</a>


## Depends on

* :question: <a href="../../../library/lib/graph/StronglyConnectedComponents.cpp.html">StronglyConnectedComponents</a>
* :heavy_check_mark: <a href="../../../library/lib/graph/UnionFindTree.cpp.html">UnionFindTree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1023"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <stack>
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
        if(uf.connected(a,b)){
            cout << "Yes" << endl;
            return 0;
        }
        uf.merge(a,b);
    }
    StronglyConnectedComponents scc(N);
    for(auto& e:edge){
        int a = e.first,b = e.second;
        if(uf.connected(a,b)){
            cout << "Yes" << endl;
            return 0;
        }
        scc.make_edge(uf[a],uf[b]);
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    for(int i = 0; i < N; ++i) if(cnt[i] > 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl; 
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/StronglyConnectedComponents-1.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1023"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;
#line 1 "lib/graph/UnionFindTree.cpp"
/*
 * @title UnionFindTree
 */
class UnionFindTree {
	vector<int> parent,maxi,mini;
	inline int root(int n) {
		return (parent[n]<0?n:parent[n] = root(parent[n]));
	}
public:
	UnionFindTree(int N = 1) : parent(N,-1),maxi(N),mini(N){
		iota(maxi.begin(),maxi.end(),0);
		iota(mini.begin(),mini.end(),0);
	}
	inline bool connected(int n, int m) {
		return root(n) == root(m);
	}
	inline void merge(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(parent[n]>parent[m]) swap(n, m);
		parent[n] += parent[m];
		parent[m] = n;
		maxi[n] = std::max(maxi[n],maxi[m]);
		mini[n] = std::min(mini[n],mini[m]);
	}
	inline int min(int n) {
		return mini[root(n)];
	}
	inline int max(int n) {
		return maxi[root(n)];
	}
	inline int size(int n){
		return (-parent[root(n)]);
	}
	inline int operator[](int n) {
		return root(n);
	}
	inline void print() {
		for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
		cout << endl;
	}
};
#line 1 "lib/graph/StronglyConnectedComponents.cpp"
/*
 * @title StronglyConnectedComponents
 */
class StronglyConnectedComponents{
	int num,is_2sat,half,max_id,cnt;
	vector<vector<int>> edge;
	vector<int> label,order,low;
    stack<size_t> st;
	inline int rev(int i) { return i < half ? i + half : i - half; }
    inline void dfs(int& from) {
        low[from]=order[from]=cnt++;
        st.push(from);
        for(int& to:edge[from]) {
            if(order[to]==-1) {
                dfs(to);
                low[from]=min(low[from],low[to]);
            }
            else {
                low[from]=min(low[from],order[to]);
            }
        }
        if (low[from] == order[from]) {
            while(st.size()) {
                int u = st.top();st.pop();
                order[u] = num;
                label[u] = max_id;
                if (u == from) break;
            }
            max_id++;
        }
    }
public:
	StronglyConnectedComponents(const int n, bool is_2sat=0):num(n),max_id(0),cnt(0),is_2sat(is_2sat){
		if(is_2sat) num<<=1;
		edge.resize(num);
		label.resize(num);
        order.resize(num,-1);
        low.resize(num);
        half=(num>>1);
	}
	inline int operator[](int idx) {
		return label[idx];
	}
	inline void make_edge(const int from,const int to) {
		edge[from].push_back(to);
	}
    //xがflg_xならばyがflg_y
	inline void make_condition(int x, bool flg_x, int y, bool flg_y) {
		if (!flg_x) x = rev(x);
		if (!flg_y) y = rev(y);
		make_edge(x, y);
		make_edge(rev(y), rev(x));
	}
    //is_2sat=1のときに、2satを満たすかを返却する
	inline bool solve(void) {
        for (int i = 0; i < num; i++) if (order[i] == -1) dfs(i);
        for (int& id:label) id = max_id-1-id;
		if(!is_2sat) return true;
		for (int i = 0; i < num; ++i) if (label[i] == label[rev(i)]) return false;
		return true;
	}
    vector<vector<int>> topological_sort(void) {
        vector<vector<int>> ret(max_id);
        for(int i=0;i<num;++i) ret[label[i]].push_back(i);
        return ret;
    }
	int is_true(int i) {
		return label[i] > label[rev(i)];
	}
	void print(void) {
		for(auto id:label) cout << id << " ";
		cout << endl;
	}
};
#line 11 "test/graph/StronglyConnectedComponents-1.test.cpp"

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
        if(uf.connected(a,b)){
            cout << "Yes" << endl;
            return 0;
        }
        uf.merge(a,b);
    }
    StronglyConnectedComponents scc(N);
    for(auto& e:edge){
        int a = e.first,b = e.second;
        if(uf.connected(a,b)){
            cout << "Yes" << endl;
            return 0;
        }
        scc.make_edge(uf[a],uf[b]);
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    for(int i = 0; i < N; ++i) if(cnt[i] > 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl; 
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

