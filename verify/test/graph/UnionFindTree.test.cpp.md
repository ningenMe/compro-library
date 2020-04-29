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


# :heavy_check_mark: test/graph/UnionFindTree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/UnionFindTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 07:30:44+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/graph/UnionFindTree.cpp.html">lib/graph/UnionFindTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/graph/UnionFindTree.cpp"

int main(){
    int N,Q; cin >> N >> Q;
    UnionFindTree uf(N);
    while(Q--){
        int q,a,b; cin >> q >> a >> b;
        if(q) cout << uf.same(a,b) << endl;
        else uf.unite(a,b);
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/UnionFindTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <vector>
#include <iostream>
#include <numeric>
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
#line 8 "test/graph/UnionFindTree.test.cpp"

int main(){
    int N,Q; cin >> N >> Q;
    UnionFindTree uf(N);
    while(Q--){
        int q,a,b; cin >> q >> a >> b;
        if(q) cout << uf.same(a,b) << endl;
        else uf.unite(a,b);
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

