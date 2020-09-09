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


# :heavy_check_mark: test/graph/StronglyConnectedComponents-2sat.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/StronglyConnectedComponents-2sat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 02:59:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :question: <a href="../../../library/lib/graph/StronglyConnectedComponents.cpp.html">StronglyConnectedComponents</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;
#include "../../lib/graph/StronglyConnectedComponents.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    string _; cin >> _ >> _;
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N,1);
    while(M--) {
        int u,v,t; cin >> u >> v >> t;
        int fu=1,fv=1;
        if(u<0) fu=0;
        if(v<0) fv=0;
        u = abs(u)-1;
        v = abs(v)-1;
        scc.make_condition(u,!fu,v,fv);
    }
    if(scc.solve()) {
        cout << "s SATISFIABLE\nv";
        for(int i = 0; i < N; ++i) {
            cout << " " << (2*scc.is_true(i)-1)*(i+1);
        }
        cout << " 0\n";
    }
    else {
        cout << "s UNSATISFIABLE\n";
    }

	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/StronglyConnectedComponents-2sat.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;
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
#line 10 "test/graph/StronglyConnectedComponents-2sat.test.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    string _; cin >> _ >> _;
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N,1);
    while(M--) {
        int u,v,t; cin >> u >> v >> t;
        int fu=1,fv=1;
        if(u<0) fu=0;
        if(v<0) fv=0;
        u = abs(u)-1;
        v = abs(v)-1;
        scc.make_condition(u,!fu,v,fv);
    }
    if(scc.solve()) {
        cout << "s SATISFIABLE\nv";
        for(int i = 0; i < N; ++i) {
            cout << " " << (2*scc.is_true(i)-1)*(i+1);
        }
        cout << " 0\n";
    }
    else {
        cout << "s UNSATISFIABLE\n";
    }

	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

