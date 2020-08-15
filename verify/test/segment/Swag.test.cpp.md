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


# :heavy_check_mark: test/segment/Swag.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/Swag.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 20:43:47+09:00


* see: <a href="https://yukicoder.me/problems/no/1036">https://yukicoder.me/problems/no/1036</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/Swag.cpp.html">Swag</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../lib/segment/Swag.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N+1,1);
	for(int i = 0; i < N; ++i) cin >> A[i];
	Swag<NodeGcd<long long>> swag;
	long long ans=0;
	int r=0;
	swag.push(A[0]);
	for(int i=0; i<N; i++){
		while(r<i) {
			r++;
			swag.push(A[r]);
		}
		while(r<N){
			if(swag.fold()==1) break;
			r++;
			swag.push(A[r]);
		}
		ans+=N-r;
		swag.pop();
	}
	cout << ans << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/Swag.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#line 1 "lib/segment/Swag.cpp"
/*
 * @title Swag
 */
template<class Operator> class Swag{
public:
	using TypeNode = typename Operator::TypeNode;
	stack<pair<TypeNode,TypeNode>> pre,suf;

	Swag() {
		// do nothing
	}
	TypeNode fold() {
		TypeNode res = Operator::unit_node;
		if(pre.size()) res = Operator::func_node(pre.top().second,res);
		if(suf.size()) res = Operator::func_node(res,suf.top().second);
		return res;
	}
	void push(TypeNode val) {
		TypeNode acc = val;
		if(suf.size()) acc = Operator::func_node(suf.top().second,acc);
		suf.emplace(val,acc);
	}
	void pop() {
		if(pre.empty()) {
			TypeNode acc = Operator::unit_node;
			while(suf.size()) {
				auto [val,_] = suf.top();
				suf.pop();
				acc = Operator::func_node(val,acc);
				pre.emplace(val,acc);
			}
		}
		if(pre.size()) pre.pop();			
	}
	size_t size(){
		return pre.size()+suf.size();
	}
};

template<class T> struct NodeGcd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return r?func_node(r,l%r):l;}
};

template<class T> struct NodeComposite {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = {1,0};
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}
};
#line 8 "test/segment/Swag.test.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N+1,1);
	for(int i = 0; i < N; ++i) cin >> A[i];
	Swag<NodeGcd<long long>> swag;
	long long ans=0;
	int r=0;
	swag.push(A[0]);
	for(int i=0; i<N; i++){
		while(r<i) {
			r++;
			swag.push(A[r]);
		}
		while(r<N){
			if(swag.fold()==1) break;
			r++;
			swag.push(A[r]);
		}
		ans+=N-r;
		swag.pop();
	}
	cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

