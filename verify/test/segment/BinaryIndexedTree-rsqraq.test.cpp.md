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


# :heavy_check_mark: test/segment/BinaryIndexedTree-rsqraq.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/BinaryIndexedTree-rsqraq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 08:12:39+09:00


* see: <a href="https://yukicoder.me/problems/no/742">https://yukicoder.me/problems/no/742</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/BinaryIndexedTree.cpp.html">lib/segment/BinaryIndexedTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/742"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/segment/BinaryIndexedTree.cpp"

int main(void){
    int N; cin >> N;
    vector<int> A(N+1,0);
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    BinaryIndexedTree<NodePrefixSumPointAdd<int>> bit(N+1);
    int ans = 0;
    for(int i = N; 1 <= i; --i) {
        ans += bit.get(A[i]);
        bit.update(A[i],1);
    }
    cout << ans << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/BinaryIndexedTree-rsqraq.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/742"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#line 1 "lib/segment/BinaryIndexedTree.cpp"
//Binary Indexed Tree
template<class Operator> class BinaryIndexedTree {
	using TypeNode = typename Operator::TypeNode;
	size_t depth;         
	size_t length;
	size_t num;
	vector<TypeNode> node;
public:
	BinaryIndexedTree(const size_t num) : num(num) {
		for (depth = 1,length = 1; length < num; depth++,length *= 2);
		node.resize(length+1, Operator::unit_node);
	}
 
	//[idx,idx+1) update
	void update(size_t idx, TypeNode var) {
		assert(0 <= idx && idx < length);
		for (++idx; idx <= length; idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);
	}

	//[0,idx) get
	TypeNode get(size_t idx) {
		TypeNode ret = Operator::unit_node;
		for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);
		return ret;
	}

	//return [0,length]
	int binary_search(TypeNode var) {
		if(!Operator::func_check(node.back(),var)) return num;
		TypeNode ret = Operator::unit_node;
		size_t off = 0;
		for(size_t idx = length; idx; idx >>= 1){
			if(off + idx <= length && !Operator::func_check(Operator::func_node(ret,node[off+idx]),var)) {
				off += idx;
				ret = Operator::func_node(ret,node[off]);
			}
		}
		return min(off,num);
	}

	void print() {
		cout << "{ " << get(1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i+1);
		cout << " }" << endl;
	}
};

template<class T> struct NodePrefixSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	// Binary Search for first index where func_check is true
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode val){return val <= nodeVal;}
};

template<class TypeNode> struct nodeUpdatePrefixGCD {
	TypeNode unit_node = 0;
	TypeNode func_node(TypeNode l,TypeNode r){return ((r == 0) ? l : func_node(r, l % r));}
	// Binary Search for first index at where func_check is true
	bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

//verify https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j
//verify https://atcoder.jp/contests/abc130/tasks/abc130_d
#line 8 "test/segment/BinaryIndexedTree-rsqraq.test.cpp"

int main(void){
    int N; cin >> N;
    vector<int> A(N+1,0);
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    BinaryIndexedTree<NodePrefixSumPointAdd<int>> bit(N+1);
    int ans = 0;
    for(int i = N; 1 <= i; --i) {
        ans += bit.get(A[i]);
        bit.update(A[i],1);
    }
    cout << ans << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

