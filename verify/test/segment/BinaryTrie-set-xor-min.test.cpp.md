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


# :heavy_check_mark: test/segment/BinaryTrie-set-xor-min.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/BinaryTrie-set-xor-min.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-05 03:48:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/set_xor_min">https://judge.yosupo.jp/problem/set_xor_min</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/BinaryTrie.cpp.html">BinaryTrie</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../lib/segment/BinaryTrie.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	BinaryTrie<NodeSumPointAdd<int>,30> trie;
	int Q; cin >> Q;
	while (Q--){
		int q; cin >> q;
		long long x; cin >> x;
		if(q==0) {
			long long y=trie.get(x);
			if(!y) trie.update(x,1);
		}
		if(q==1) {
			long long y=trie.get(x);
			if(y) trie.update(x,-1);
		}
		if(q==2) {
			cout << trie.min_bitwise_xor(x) << endl;
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/BinaryTrie-set-xor-min.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#line 1 "lib/segment/BinaryTrie.cpp"
/*
 * @title BinaryTrie
 */
template<class Operator, int bit=60> class BinaryTrie{
	using TypeNode = typename Operator::TypeNode; 
public:
	vector<TypeNode> node;
	vector<vector<int>> ch;
	BinaryTrie():node(1),ch(1,vector<int>(2,-1)){}
	void update(long long idx, const TypeNode var) {
		int curr=0;
		stack<int> st;
		for(int i=bit-1; 0 <= i; --i) {
			st.push(curr);
			int f=(idx>>i)&1;
			if(ch[curr][f]==-1) {
				node.push_back(Operator::unit_node);
				ch.push_back(vector<int>(2,-1));
				ch[curr][f] = (int)node.size()-1;
			}
			curr = ch[curr][f];
		}
		node[curr] = Operator::func_merge(node[curr],var);
		while(st.size()) {
			curr = st.top(); st.pop();
			node[curr]=Operator::unit_node;
			if(ch[curr][0]!=-1)	node[curr] = Operator::func_node(node[ch[curr][0]],node[curr]);
			if(ch[curr][1]!=-1)	node[curr] = Operator::func_node(node[curr],node[ch[curr][1]]);
		}
	}
	TypeNode get(long long idx) {
		int curr=0;
		for(int i=bit-1; 0 <= i; --i) {
			int f=(idx>>i)&1;
			if(ch[curr][f]!=-1) curr = ch[curr][f];
			else return Operator::unit_node;
		}
		return node[curr];
	}
	long long min_bitwise_xor(long long x) {
		int curr=0;
		long long y=0;
		for(int i=bit-1; 0 <= i; --i) {
			long long f=(x>>i)&1;
			if(!node[curr]) break;
			if(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];
			else curr = ch[curr][f^=1];
			y^=(f<<i);
		}
		return y^x;
	}
};

//一点加算 区間和
template<class T> struct NodeSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}
};
#line 8 "test/segment/BinaryTrie-set-xor-min.test.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	BinaryTrie<NodeSumPointAdd<int>,30> trie;
	int Q; cin >> Q;
	while (Q--){
		int q; cin >> q;
		long long x; cin >> x;
		if(q==0) {
			long long y=trie.get(x);
			if(!y) trie.update(x,1);
		}
		if(q==1) {
			long long y=trie.get(x);
			if(y) trie.update(x,-1);
		}
		if(q==2) {
			cout << trie.min_bitwise_xor(x) << endl;
		}
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

