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


# :x: test/segment-tree/SegmentTree-binary-search.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#154f484dac0eb1f2e1b822e326933d6a">test/segment-tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment-tree/SegmentTree-binary-search.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 06:08:31+09:00


* see: <a href="https://yukicoder.me/problems/4072">https://yukicoder.me/problems/4072</a>


## Depends on

* :x: <a href="../../../library/lib/math/GreatestCommonDivisor.cpp.html">lib/math/GreatestCommonDivisor.cpp</a>
* :question: <a href="../../../library/lib/segment-tree/SegmentTree.cpp.html">lib/segment-tree/SegmentTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment-tree/SegmentTree.cpp"
#include "../../lib/math/GreatestCommonDivisor.cpp"

template<class T> struct nodeGcdPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode funcNode(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
	inline static constexpr TypeNode funcMerge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool funcCheck(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

// solution by binary search in prefix range on segment tree 
int main() {
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<nodeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		ans += N - seg.binarySearch(i,N,1);
	}
	cout << ans << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment-tree/SegmentTree-binary-search.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
using namespace std;
#line 1 "lib/segment-tree/SegmentTree.cpp"
template<class Operator> class SegmentTree {
	using TypeNode = typename Operator::TypeNode; 
	size_t length;
	size_t num;
	vector<TypeNode> node;
	vector<pair<size_t,size_t>> range;
public:

	//unitで初期化
	SegmentTree(const size_t num): num(num) {
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length, Operator::unit_node);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//vectorで初期化
	SegmentTree(const vector<TypeNode> & vec) : num(vec.size()) {
		for (length = 1; length < vec.size(); length *= 2);
		node.resize(2 * length, Operator::unit_node);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}
 
	//同じinitで初期化
	SegmentTree(const size_t num, const TypeNode init) : num(num) {
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length, Operator::unit_node);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) node[i+length] = init;
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}
	
	//[idx,idx+1)
	void update(size_t idx, const TypeNode var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] = Operator::funcMerge(node[idx],var);
		while(idx >>= 1) node[idx] = Operator::funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//[l,r)
	TypeNode get(int l, int r) {
		if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_node;
		TypeNode vl = Operator::unit_node, vr = Operator::unit_node;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Operator::funcNode(vl,node[l++]);
			if(r&1) vr = Operator::funcNode(node[--r],vr);
		}
		return Operator::funcNode(vl,vr);
	}

	//return [0,length]
	int prefixBinarySearch(TypeNode var) {
		if(!Operator::funcCheck(node[1],var)) return num;
		TypeNode ret = Operator::unit_node;
		size_t idx = 2;
		for(; idx < 2*length; idx<<=1){
			if(!Operator::funcCheck(Operator::funcNode(ret,node[idx]),var)) {
				ret = Operator::funcNode(ret,node[idx]);
				idx++;
			}
		}
		return min((idx>>1) - length,num);
	}

	//range[l,r) return [l,r]
	int binarySearch(size_t l, size_t r, TypeNode var) {
		if (l < 0 || length <= l || r < 0 || length < r) return -1;
		TypeNode ret = Operator::unit_node;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
			if(range[idx].second<=r && !Operator::funcCheck(Operator::funcNode(ret,node[idx]),var)) {
				ret = Operator::funcNode(ret,node[idx]);
				off = range[idx++].second;
				if(!(idx&1)) idx >>= 1;			
			}
			else{
				idx <<=1;
			}
		}
		return off;
	}
};

//一点更新 区間最小
template<class T> struct nodeMinPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = (1LL<<31)-1;
	inline static constexpr TypeNode funcNode(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeNode funcMerge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool funcCheck(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

#line 1 "lib/math/GreatestCommonDivisor.cpp"
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
#line 8 "test/segment-tree/SegmentTree-binary-search.test.cpp"

template<class T> struct nodeGcdPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode funcNode(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
	inline static constexpr TypeNode funcMerge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool funcCheck(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

// solution by binary search in prefix range on segment tree 
int main() {
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<nodeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		ans += N - seg.binarySearch(i,N,1);
	}
	cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

