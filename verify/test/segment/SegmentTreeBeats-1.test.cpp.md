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


# :heavy_check_mark: test/segment/SegmentTreeBeats-1.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/SegmentTreeBeats-1.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-15 00:33:13+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum">https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/SegmentTreeBeats.cpp.html">SegmentTreeBeats</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SegmentTreeBeats.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTreeBeats<long long> seg(A);
	while(Q--){
		long long q,l,r,b;
		cin >> q >> l >> r;
		if(q==3){
			cout << seg.get_sum(l,r) << endl;
		}
		else{
			cin >> b;
			if(q==0) {
				seg.range_chmin(l,r,b);
			}
			if(q==1) {
				seg.range_chmax(l,r,b);
			}
			if(q==2) {
				seg.range_add(l,r,b);
			}
		}
	}
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/SegmentTreeBeats-1.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#line 1 "lib/segment/SegmentTreeBeats.cpp"
/*
 * @title SegmentTreeBeats
 */
template<class T> class SegmentTreeBeats {
	T inf;
	size_t length;
	size_t height;
	vector<T>
	node_max_first,node_max_second,count_max_first,
	node_min_first,node_min_second,count_min_first,
	node_sum,lazy_add,lazy_update;
	vector<pair<int,int>> range;

	inline void internal_chmax(int k, long long x) {
		node_sum[k] += (x - node_max_first[k]) * count_max_first[k];
		if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k] = x;
		else if(node_max_first[k] == node_min_second[k]) node_max_first[k] = node_min_second[k] = x;
		else node_max_first[k] = x;
		if(lazy_update[k] != inf && x < lazy_update[k]) lazy_update[k] = x;
	}
	inline void internal_chmin(int k, long long x) {
		node_sum[k] += (x - node_min_first[k]) * count_min_first[k];
		if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k] = x;
		else if(node_max_second[k] == node_min_first[k]) node_min_first[k] = node_max_second[k] = x;
		else node_min_first[k] = x;
		if(lazy_update[k] != inf && lazy_update[k] < x) lazy_update[k] = x;
	}
	inline void internal_add(int k, long long x) {
		node_max_first[k] += x;
		if(node_max_second[k] != -inf) node_max_second[k] += x;
		node_min_first[k] += x;
		if(node_min_second[k] != inf) node_min_second[k] += x;
		node_sum[k] += x * (range[k].second - range[k].first);
		(lazy_update[k] != inf ? lazy_update[k]:lazy_add[k]) += x;
	}
	inline void internal_update(int k, long long x) {
		node_max_first[k] = x; node_max_second[k] = -inf;
		node_min_first[k] = x; node_min_second[k] = inf;
		count_max_first[k] = count_min_first[k] = (range[k].second - range[k].first);
		node_sum[k] = x * (range[k].second - range[k].first);
		lazy_update[k] = x;
		lazy_add[k] = 0;
	}
	inline void propagate(int k) {
		if(length-1 <= k) return;
		if(lazy_update[k] != inf) {
			internal_update(2*k+0, lazy_update[k]);
			internal_update(2*k+1, lazy_update[k]);
			lazy_update[k] = inf;
			return;
		}
		if(lazy_add[k] != 0) {
			internal_add(2*k+0, lazy_add[k]);
			internal_add(2*k+1, lazy_add[k]);
			lazy_add[k] = 0;
		}
		if(node_max_first[k] < node_max_first[2*k+0]) {
			internal_chmax(2*k+0, node_max_first[k]);
		}
		if(node_min_first[2*k+0] < node_min_first[k]) {
			internal_chmin(2*k+0, node_min_first[k]);
		}
		if(node_max_first[k] < node_max_first[2*k+1]) {
			internal_chmax(2*k+1, node_max_first[k]);
		}
		if(node_min_first[2*k+1] < node_min_first[k]) {
			internal_chmin(2*k+1, node_min_first[k]);
		}
	}
	inline void merge(int k) {
		node_sum[k] = node_sum[2*k+0] + node_sum[2*k+1];
		if(node_max_first[2*k+0] < node_max_first[2*k+1]) {
			node_max_first[k] = node_max_first[2*k+1];
			count_max_first[k] = count_max_first[2*k+1];
			node_max_second[k] = max(node_max_first[2*k+0], node_max_second[2*k+1]);
		}
		else if(node_max_first[2*k+0] > node_max_first[2*k+1]) {
			node_max_first[k] = node_max_first[2*k+0];
			count_max_first[k] = count_max_first[2*k+0];
			node_max_second[k] = max(node_max_second[2*k+0], node_max_first[2*k+1]);
		}
		else {
			node_max_first[k] = node_max_first[2*k+0];
			count_max_first[k] = count_max_first[2*k+0] + count_max_first[2*k+1];
			node_max_second[k] = max(node_max_second[2*k+0], node_max_second[2*k+1]);
		}
		if(node_min_first[2*k+0] < node_min_first[2*k+1]) {
			node_min_first[k] = node_min_first[2*k+0];
			count_min_first[k] = count_min_first[2*k+0];
			node_min_second[k] = min(node_min_second[2*k+0], node_min_first[2*k+1]);
		}
		else if(node_min_first[2*k+0] > node_min_first[2*k+1]) {
			node_min_first[k] = node_min_first[2*k+1];
			count_min_first[k] = count_min_first[2*k+1];
			node_min_second[k] = min(node_min_first[2*k+0], node_min_second[2*k+1]);
		}
		else {
			node_min_first[k] = node_min_first[2*k+0];
			count_min_first[k] = count_min_first[2*k+0] + count_min_first[2*k+1];
			node_min_second[k] = min(node_min_second[2*k+0], node_min_second[2*k+1]);
		}
	}
public:
	SegmentTreeBeats(const int num,const T inf = (1LL<<60)) {
		vector<T> a(num,0);
		*this = SegmentTreeBeats(a,inf);
	}
	SegmentTreeBeats(const vector<T>& a,const T inf = (1LL<<60)) : inf(inf){
		int num = a.size();
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node_max_first.resize(2*length);
		node_max_second.resize(2*length);
		count_max_first.resize(2*length);
		node_min_first.resize(2*length);
		node_min_second.resize(2*length);
		count_min_first.resize(2*length);
		node_sum.resize(2*length);
		range.resize(2*length);
		lazy_add.resize(2*length);
		lazy_update.resize(2*length);

		for(int i=0; i<2*length; ++i) lazy_add[i] = 0, lazy_update[i] = inf;
		for(int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for(int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);

		for(int i=0; i<num; ++i) {
			node_max_first[length+i] = node_min_first[length+i] = node_sum[length+i] = a[i];
			node_max_second[length+i] = -inf;
			node_min_second[length+i] = inf;
			count_max_first[length+i] = count_min_first[length+i] = 1;
		}
		for(int i=num; i<length; ++i) {
			node_max_first[length+i] = node_max_second[length+i] = -inf;
			node_min_first[length+i] = node_min_second[length+i] = inf;
			count_max_first[length+i] = count_min_first[length+i] = 0;
		}
		for(int i=length-1; i; --i) merge(i);
	}
	inline void range_chmin(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a || node_max_first[k] <= x) return;
		if(a <= range[k].first && range[k].second <= b && node_max_second[k] < x) {
			internal_chmax(k, x);
			return;
		}
		propagate(k);
		range_chmin(a, b, x, 2*k+0);
		range_chmin(a, b, x, 2*k+1);
		merge(k);
	}
	inline void range_chmax(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a || x <= node_min_first[k]) return;
		if(a <= range[k].first && range[k].second <= b && x < node_min_second[k]) {
			internal_chmin(k, x);
			return;
		}
		propagate(k);
		range_chmax(a, b, x, 2*k+0);
		range_chmax(a, b, x, 2*k+1);
		merge(k);
	}
	inline void range_add(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return;
		if(a <= range[k].first && range[k].second <= b) {
			internal_add(k, x);
			return;
		}
		propagate(k);
		range_add(a, b, x, 2*k+0);
		range_add(a, b, x, 2*k+1);
		merge(k);
	}
	inline void range_update(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return;
		if(a <= range[k].first && range[k].second <= b) {
			internal_update(k, x);
			return;
		}
		propagate(k);
		range_update(a, b, x, 2*k+0);
		range_update(a, b, x, 2*k+1);
		merge(k);
	}
	inline T get_max(int a, int b, int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return -inf;
		if(a <= range[k].first && range[k].second <= b) return node_max_first[k];
		propagate(k);
		T vl = get_max(a, b, 2*k+0);
		T vr = get_max(a, b, 2*k+1);
		return max(vl, vr);
	}
	inline T get_min(int a, int b, int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return inf;
		if(a <= range[k].first && range[k].second <= b) return node_min_first[k];
		propagate(k);
		T vl = get_min(a, b, 2*k+0);
		T vr = get_min(a, b, 2*k+1);
		return min(vl, vr);
	}
	inline T get_sum(int a, int b, int k=1) {
		if(b <= range[k].first || range[k].second <= a) return 0;
		if(a <= range[k].first && range[k].second <= b) return node_sum[k];
		propagate(k);
		T vl = get_sum(a, b, 2*k+0);
		T vr = get_sum(a, b, 2*k+1);
		return vl + vr;
	}
};
#line 7 "test/segment/SegmentTreeBeats-1.test.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTreeBeats<long long> seg(A);
	while(Q--){
		long long q,l,r,b;
		cin >> q >> l >> r;
		if(q==3){
			cout << seg.get_sum(l,r) << endl;
		}
		else{
			cin >> b;
			if(q==0) {
				seg.range_chmin(l,r,b);
			}
			if(q==1) {
				seg.range_chmax(l,r,b);
			}
			if(q==2) {
				seg.range_add(l,r,b);
			}
		}
	}
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

