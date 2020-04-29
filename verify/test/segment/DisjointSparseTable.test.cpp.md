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


# :heavy_check_mark: test/segment/DisjointSparseTable.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/DisjointSparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 07:55:12+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/DisjointSparseTable.cpp.html">lib/segment/DisjointSparseTable.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/DisjointSparseTable.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    DisjointSparseTable<NodeSum<long long>> st(A);
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
#line 1 "test/segment/DisjointSparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#line 1 "lib/segment/DisjointSparseTable.cpp"
template<class Operator> class DisjointSparseTable{
public:
	using TypeNode = typename Operator::TypeNode;
	size_t depth;
	size_t length;
	vector<TypeNode> node;
	vector<size_t> msb;

	DisjointSparseTable(const vector<TypeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		
		//msb
		msb.resize(length,0);
		for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;

		//init value
		node.resize(depth*length,Operator::unit_node);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];

		for(int i = 1; i < depth; ++i) {
			for(int r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){
				//init accumulate
				node[i*length+l] = node[l];
				node[i*length+r] = node[r];
				//accumulate
				for(int k = 1; k < (1<<i); ++k) {
					node[i*length+l-k] = Operator::func_node(node[i*length+l-k+1],node[l-k]);
					node[i*length+r+k] = Operator::func_node(node[i*length+r+k-1],node[r+k]);
				}
			}
		}
	}

	//[l,r)
	TypeNode get(int l,int r) {
		r--;
		return (l>r||l<0||length<=r) ? Operator::unit_node: (l==r ? node[l] : Operator::func_node(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));
	}
};

//sum
template<class T> struct NodeSum {
    using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
};
#line 7 "test/segment/DisjointSparseTable.test.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    DisjointSparseTable<NodeSum<long long>> st(A);
    while(Q--){
        int l,r; cin >> l >> r;
        cout << st.get(l,r) << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

