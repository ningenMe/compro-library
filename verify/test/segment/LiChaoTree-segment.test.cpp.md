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


# :heavy_check_mark: test/segment/LiChaoTree-segment.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#071f76f489cfd361eed2a12635965092">test/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment/LiChaoTree-segment.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:04:31+09:00


* see: <a href="https://judge.yosupo.jp/problem/segment_add_get_min">https://judge.yosupo.jp/problem/segment_add_get_min</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/segment/LiChaoTree.cpp.html">lib/segment/LiChaoTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/segment/LiChaoTree.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int length,Q; cin >> length >> Q;
	vector<long long> A(length),B(length),L(length),R(length),E(Q),F(Q),C(Q),D(Q),S(Q),TypeValue(Q);
	for(int i = 0; i < length; ++i) {
		cin >> L[i] >> R[i] >> A[i] >> B[i];
	}
	LiChaoTree<ValueMin<long long>> lct;
	for(int i = 0; i < length; ++i) lct.x_push_back(L[i]),lct.x_push_back(R[i]);
	for(int i = 0; i < Q; ++i) {
		cin >> E[i];
		if(E[i]) {
			cin >> F[i];
			lct.x_push_back(F[i]);
		}
		else {
			cin >> S[i] >> TypeValue[i] >> C[i] >> D[i];
			lct.x_push_back(S[i]);
			lct.x_push_back(TypeValue[i]);
		}
	}
	lct.build();
	long long inf = 3e18;
	for(int i = 0; i < length; ++i) lct.update({A[i],B[i]},L[i],R[i]);
	for(int i = 0; i < Q; ++i) {
		if(E[i]) {
			long long ans = lct.get(F[i]);
			if(ans!=inf) cout << ans << endl;
			else cout << "INFINITY" << endl;
		}
		else {
			lct.update({C[i],D[i]},S[i],TypeValue[i]);
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment/LiChaoTree-segment.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#line 1 "lib/segment/LiChaoTree.cpp"
template <typename Operator> class LiChaoTree{
    using TypeValue = typename Operator::TypeValue;
    using Line = pair<TypeValue,TypeValue>;
	vector<TypeValue> x;
    vector<Line> node;
    vector<int> clz;
	size_t length;
    const size_t bit;
public:	
	LiChaoTree(const size_t bit=30):bit(bit){
        //do nothing
    }
	inline void build(){
		sort(x.begin(),x.end());
		x.erase(unique(x.begin(),x.end()),x.end());
		TypeValue maxi = x.back() + 1;
		for (length = 1; length < x.size(); length *= 2);
		x.resize(length, maxi);
        node.resize(2*length,make_pair(0,Operator::unit_value));
        clz.resize(2*length,32);
        for(size_t i = 1; i < 2*length; ++i) {
            // for(int j = 0; j < bit; ++j) if(i&(1<<j)) clz[i] = 31-j;
            clz[i] = __builtin_clz(i);
        }
	}

    void x_push_back(TypeValue argx){
        x.push_back(argx);
    }

    //return y = ax+b
	inline static constexpr TypeValue f(Line& line,TypeValue& t)	{
		return line.first*t + line.second;
	}
		
	inline void update(Line line,int i = 1){
		while(i < 2*length){
			int l = (i<<(clz[i]-clz[length]))-length;
			int r = l + (length>>(31-clz[i])) - 1;
			int m = (l+r)>>1;
			bool flgl = Operator::func_compare(f(line,x[l]),f(node[i],x[l]));
			bool flgm = Operator::func_compare(f(line,x[m]),f(node[i],x[m]));
			bool flgr = Operator::func_compare(f(line,x[r]),f(node[i],x[r]));

			if(flgl&&flgr) node[i] = line;
			if(flgl==flgr) break;
			if(flgm) swap(node[i],line),swap(flgl,flgr);
			i = (i<<1)+flgr;
		}
	}
	inline void update(Line line,TypeValue l,TypeValue r){
		l = distance(x.begin(),lower_bound(x.begin(),x.end(),l))+length;
		r = distance(x.begin(),lower_bound(x.begin(),x.end(),r))+length;
		for(; l < r; l >>=1, r >>=1) {
			if(l&1) update(line,l),l++;
			if(r&1) --r,update(line,r);
		}
	}
	
	inline TypeValue get(TypeValue t){
		int i = distance(x.begin(),lower_bound(x.begin(),x.end(),t))+length;
		TypeValue res = Operator::unit_value;
		for(;1<=i;i>>=1) if(!Operator::func_compare(res,f(node[i],t))) res = f(node[i],t);
		return res;
	}
};

//最小値クエリ
template<class T> struct ValueMin {
	using TypeValue = T;
	inline static constexpr TypeValue unit_value = 3e18;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<r;}
};
#line 8 "test/segment/LiChaoTree-segment.test.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int length,Q; cin >> length >> Q;
	vector<long long> A(length),B(length),L(length),R(length),E(Q),F(Q),C(Q),D(Q),S(Q),TypeValue(Q);
	for(int i = 0; i < length; ++i) {
		cin >> L[i] >> R[i] >> A[i] >> B[i];
	}
	LiChaoTree<ValueMin<long long>> lct;
	for(int i = 0; i < length; ++i) lct.x_push_back(L[i]),lct.x_push_back(R[i]);
	for(int i = 0; i < Q; ++i) {
		cin >> E[i];
		if(E[i]) {
			cin >> F[i];
			lct.x_push_back(F[i]);
		}
		else {
			cin >> S[i] >> TypeValue[i] >> C[i] >> D[i];
			lct.x_push_back(S[i]);
			lct.x_push_back(TypeValue[i]);
		}
	}
	lct.build();
	long long inf = 3e18;
	for(int i = 0; i < length; ++i) lct.update({A[i],B[i]},L[i],R[i]);
	for(int i = 0; i < Q; ++i) {
		if(E[i]) {
			long long ans = lct.get(F[i]);
			if(ans!=inf) cout << ans << endl;
			else cout << "INFINITY" << endl;
		}
		else {
			lct.update({C[i],D[i]},S[i],TypeValue[i]);
		}
	}
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

