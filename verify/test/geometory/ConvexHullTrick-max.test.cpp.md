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


# :heavy_check_mark: test/geometory/ConvexHullTrick-max.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1559848aad74dc56829252d458066b03">test/geometory</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometory/ConvexHullTrick-max.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 17:15:41+09:00


* see: <a href="https://yukicoder.me/problems/no/409">https://yukicoder.me/problems/no/409</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/geometory/ConvexHullTrick.cpp.html">ConvexHullTrick</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "../../lib/geometory/ConvexHullTrick.cpp"
using ll = long long;

int main(void){
	ll N,A,B,W; cin >> N >> A >> B >> W;
	vector<ll> D(N+2,0);
	for(int i = 1; i <= N; ++i) cin >> D[i];
	// dp[i]=min{j:[0,i)} -> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)
	//                    -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]
	//                    -> dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]
	//                    -> (-B*j)*i  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] 
	// dp[i]=-max{j:[0,i)}-> (B*j)*i  +  -{dp[j]+B/2*(j*j+j)+A*j} 
	//                    ->
	vector<ll> dp(N+2,1e15);
	dp[0]=W;
	ConvexHullTrick<ValueMax<ll>> cht;
	cht.insert(0,-dp[0]);
	for(ll i=1;i<=N+1;++i){
		dp[i]=-cht.get(i) + B*(i*i-i)/2-A*(i-1)+D[i];
		cht.insert(B*i,-(dp[i]+B*(i*i+i)/2+A*i));
	}
	cout << dp[N+1] << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/geometory/ConvexHullTrick-max.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#line 1 "lib/geometory/ConvexHullTrick.cpp"
/*
 * @title ConvexHullTrick
 */
template<class Operator> class ConvexHullTrick {
private:
	using TypeValue = typename Operator::TypeValue;
	deque<pair<TypeValue,TypeValue>> lines;

	//cが必要かどうか判定する
	inline int isRequired(const pair<TypeValue,TypeValue>& l, const pair<TypeValue,TypeValue>& c, const pair<TypeValue,TypeValue>& r) {
		return (c.first - l.first) * (r.second - c.second) >= (c.second - l.second) * (r.first - c.first);
	}
	
	//k番目のax+bの値
	inline TypeValue value(int k, TypeValue x) {
		return lines[k].first * x + lines[k].second;
	}

public:
	ConvexHullTrick() {
		// do nothing
	} 

	//傾きの大きさが単調な順にax+bを追加
	void insert(TypeValue a, TypeValue b) {
		//insertの必要がないとき
		if(lines.size() && lines.back().first == a && !Operator::func_compare(lines.back().second,b)) return;
		// 直前の直線の傾きが同じ　かつ　それが必要ないとき
		if(lines.size() && lines.back().first == a && Operator::func_compare(b,lines.back().second)) lines.pop_back();
		//不必要な直線を取り除く
		while (lines.size() > 1 && isRequired(lines[lines.size()-2], lines[lines.size()-1], {a,b})) lines.pop_back();
		lines.push_back({a,b});
	}
	
	TypeValue get(TypeValue x) {
		int ng = -1, ok = (int)lines.size()-1, md;
		while (ok - ng > 1) {
			md = (ok + ng) >> 1;
			( Operator::func_compare(value(md, x),value(md + 1, x)) ?ok:ng)=md;
		}
		return value(ok, x);
	}
	
	// クエリの単調性も成り立つ場合 (x が単調増加)
	TypeValue getMonotone(TypeValue x) {
		while (lines.size() >= 2 && value(0, x) >= value(1, x)) lines.pop_front();
		return lines[0].first * x + lines[0].second;
	}

};

//最小値クエリ
template<class T> struct ValueMin {
	using TypeValue = T;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<r;}
};
//傾きがa1>=a2>=a3...となるようにinsertする

//最大値クエリ
template<class T> struct ValueMax {
	using TypeValue = T;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>r;}
};
//傾きがa1<=a2<=a3...となるようにinsertする
#line 8 "test/geometory/ConvexHullTrick-max.test.cpp"
using ll = long long;

int main(void){
	ll N,A,B,W; cin >> N >> A >> B >> W;
	vector<ll> D(N+2,0);
	for(int i = 1; i <= N; ++i) cin >> D[i];
	// dp[i]=min{j:[0,i)} -> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)
	//                    -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]
	//                    -> dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]
	//                    -> (-B*j)*i  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] 
	// dp[i]=-max{j:[0,i)}-> (B*j)*i  +  -{dp[j]+B/2*(j*j+j)+A*j} 
	//                    ->
	vector<ll> dp(N+2,1e15);
	dp[0]=W;
	ConvexHullTrick<ValueMax<ll>> cht;
	cht.insert(0,-dp[0]);
	for(ll i=1;i<=N+1;++i){
		dp[i]=-cht.get(i) + B*(i*i-i)/2-A*(i-1)+D[i];
		cht.insert(B*i,-(dp[i]+B*(i*i+i)/2+A*i));
	}
	cout << dp[N+1] << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

