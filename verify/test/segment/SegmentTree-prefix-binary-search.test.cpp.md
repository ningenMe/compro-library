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


# :heavy_check_mark: test/segment/SegmentTree-prefix-binary-search.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/SegmentTree-prefix-binary-search.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 08:49:30+09:00


* see: <a href="https://yukicoder.me/problems/4072">https://yukicoder.me/problems/4072</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Gcd.cpp.html">Gcd</a>
* :heavy_check_mark: <a href="../../../library/lib/segment/SegmentTree.cpp.html">SegmentTree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/segment/SegmentTree.cpp"
#include "../../lib/math/Gcd.cpp"

template<class T> struct NodeGcdPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

// solution by binary search in prefix range on segment tree 
int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<NodeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		ans += N - seg.prefix_binary_search(i,N,1);
	}
	cout << ans << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/SegmentTree-prefix-binary-search.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#line 1 "lib/segment/SegmentTree.cpp"
/*
 * @title SegmentTree
 */
template<class Operator> class SegmentTree {
	using TypeNode = typename Operator::TypeNode; 
	size_t length;
	size_t num;
	vector<TypeNode> node;
	vector<pair<int,int>> range;
    inline void build() {
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
        range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
    }
public:

	//unitで初期化
	SegmentTree(const size_t num): num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length, Operator::unit_node);
        build();
	}

	//vectorで初期化
	SegmentTree(const vector<TypeNode> & vec) : num(vec.size()) {
		for (length = 1; length <= vec.size(); length *= 2);
		node.resize(2 * length, Operator::unit_node);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
        build();
	}
 
	//同じinitで初期化
	SegmentTree(const size_t num, const TypeNode init) : num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length, Operator::unit_node);
		for (int i = 0; i < length; ++i) node[i+length] = init;
        build();
	}
	
	//[idx,idx+1)
	void update(size_t idx, const TypeNode var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] = Operator::func_merge(node[idx],var);
		while(idx >>= 1) node[idx] = Operator::func_node(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//[l,r)
	TypeNode get(int l, int r) {
		if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_node;
		TypeNode vl = Operator::unit_node, vr = Operator::unit_node;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Operator::func_node(vl,node[l++]);
			if(r&1) vr = Operator::func_node(node[--r],vr);
		}
		return Operator::func_node(vl,vr);
	}

	//range[l,r) return [l,r] search max right
	int prefix_binary_search(int l, int r, TypeNode var) {
		assert(0 <= l && l < length && 0 < r && r <= length);
		TypeNode ret = Operator::unit_node;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
			if(range[idx].second<=r && !Operator::func_check(Operator::func_node(ret,node[idx]),var)) {
				ret = Operator::func_node(ret,node[idx]);
				off = range[idx++].second;
				if(!(idx&1)) idx >>= 1;			
			}
			else{
				idx <<=1;
			}
		}
		return off;
	}

	//range(l,r] return [l,r] search max left
	int suffix_binary_search(const int l, const int r, const TypeNode var) {
		assert(-1 <= l && l < (int)length-1 && 0 <= r && r < length);
		TypeNode ret = Operator::unit_node;
		int off = r;
		for(size_t idx = r+length; idx < 2*length && l < off; ){
			if(l < range[idx].first && !Operator::func_check(Operator::func_node(node[idx],ret),var)) {
				ret = Operator::func_node(node[idx],ret);
				off = range[idx--].first-1;
				if(idx&1) idx >>= 1;
			}
			else{
				idx = (idx<<1)+1;
			}
		}
		return off;
	}

	void print(){
		// cout << "node" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << node[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}
};

//一点更新 区間最小
template<class T> struct NodeMinPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = (1LL<<31)-1;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

//一点加算 区間総和
template<class T> struct NodeSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

//一次関数
template<class T> struct NodeCompositePointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = make_pair(1,0);
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};
#line 1 "lib/math/Gcd.cpp"
/*
 * @title Gcd
 */
class Gcd{
public:
	inline static long long impl(long long n, long long m) {
		static constexpr long long K = 5;
		long long t,s;
		for(int i = 0; t = n - m, s = n - m * K, i < 80; ++i) {
			if(t<m){
				if(!t) return m;
				n = m, m = t;
			}
			else{
				if(!m) return t;
				n=t;
				if(t >= m * K) n = s;
			}
		}
		return impl(m, n % m);
	}
	inline static long long pre(long long n, long long m) {
		long long t;
		for(int i = 0; t = n - m, i < 4; ++i) {
			(t < m ? n=m,m=t : n=t);
			if(!m) return n;
		}
		return impl(n, m);
	}
	inline static long long gcd(long long n, long long m) {
		return (n>m ? pre(n,m) : pre(m,n));
	}
	inline static constexpr long long pureGcd(long long a, long long b) {
		return (b ? pureGcd(b, a % b):a);
	}
	inline static constexpr long long lcm(long long a, long long b) {
		return (a*b ? (a / gcd(a, b)*b): 0);
	}
	inline static constexpr long long extGcd(long long a, long long b, long long &x, long long &y) {
		if (b == 0) return x = 1, y = 0, a;
		long long d = extGcd(b, a%b, y, x);
		return y -= a / b * x, d;
	}
};
#line 9 "test/segment/SegmentTree-prefix-binary-search.test.cpp"

template<class T> struct NodeGcdPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

// solution by binary search in prefix range on segment tree 
int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<NodeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		ans += N - seg.prefix_binary_search(i,N,1);
	}
	cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

