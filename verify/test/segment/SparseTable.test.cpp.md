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


# :heavy_check_mark: test/segment/SparseTable.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/SparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 02:48:46+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/SparseTable.cpp.html">SparseTable</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SparseTable.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    SparseTable<NodeMin<long long>> st(A);
    while(Q--){
        int l,r; cin >> l >> r;
        cout << st.get(l,r) << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/SparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <iostream>
using namespace std;
#line 1 "lib/segment/SparseTable.cpp"
/*
 * @title SparseTable
 */
template<class Operator> class SparseTable{
public:
	using TypeNode = typename Operator::TypeNode;
	vector<TypeNode> node;
	vector<int> idx;
	size_t depth;
	size_t length;

	SparseTable(const vector<TypeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		node.resize(depth*length);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];
		for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Operator::func_node(node[(i-1)*length+j],node[(i-1)*length+j + (1 << (i-1))]);
		idx.resize(vec.size()+1);
		for(int i = 2; i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;
	}

	//[l,r)
	TypeNode get(int l,int r) {
		int bit = idx[r-l];
		return Operator::func_node(node[bit*length+l],node[bit*length+r - (1<<bit)]);
	}
};

template<class T> struct NodeMin {
	using TypeNode = T;
	inline static constexpr TypeNode unitNode = 1LL<<31;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}
};
#line 7 "test/segment/SparseTable.test.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    SparseTable<NodeMin<long long>> st(A);
    while(Q--){
        int l,r; cin >> l >> r;
        cout << st.get(l,r) << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

