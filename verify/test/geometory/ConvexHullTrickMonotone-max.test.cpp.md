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


# :heavy_check_mark: test/geometory/ConvexHullTrickMonotone-max.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1559848aad74dc56829252d458066b03">test/geometory</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometory/ConvexHullTrickMonotone-max.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 03:11:39+09:00


* see: <a href="https://yukicoder.me/problems/no/409">https://yukicoder.me/problems/no/409</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/geometory/ConvexHullTrickMonotone.cpp.html">ConvexHullTrickMonotone</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
#include "../../lib/geometory/ConvexHullTrickMonotone.cpp"
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
	ConvexHullTrickMonotone<ValueMax<ll>> cht;
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
#line 1 "test/geometory/ConvexHullTrickMonotone-max.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
#line 1 "lib/geometory/ConvexHullTrickMonotone.cpp"
/*
 * @title ConvexHullTrickMonotone
 */
template<class Operator> class ConvexHullTrickMonotone {
private:
	using TypeValue = typename Operator::TypeValue;

	//front->backに向かって傾きがa1<a2<...<aN
	deque<pair<TypeValue,TypeValue>> lines;

	//3直線に関してline2が必要か確認 (このとき a1 < a2 < a3が必要=dequeの順そのまま)
	inline int is_required(const pair<TypeValue,TypeValue>& line1, const pair<TypeValue,TypeValue>& line2, const pair<TypeValue,TypeValue>& line3) {
		return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));
	}

	//y=ax+bの値
	inline TypeValue y(const pair<TypeValue,TypeValue> line, TypeValue x) {
		return line.first * x + line.second;
	}

	inline void insert_back(const pair<TypeValue,TypeValue> line){
		//傾きが同じとき
		if(lines.size() && lines.back().first == line.first){
			if(Operator::func_compare(lines.back().second,line.second)) return;
			else lines.pop_back();
		}
		//不必要な直線を取り除く
		while (lines.size() > 1 && !is_required(lines[(int)lines.size()-2], lines[(int)lines.size()-1],line)) lines.pop_back();
		//backにinsert
		lines.push_back(line);
	}
	inline void insert_front(const pair<TypeValue,TypeValue> line){
		//傾きが同じとき
		if(lines.size() && lines.front().first == line.first){
			if(Operator::func_compare(lines.front().second,line.second)) return;
			else lines.pop_front();
		}
		//不必要な直線を取り除く
		while (lines.size() > 1 && !is_required(line, lines[0], lines[1])) lines.pop_front();
		//frontにinsert
		lines.push_front(line);
	}
public:
	ConvexHullTrickMonotone() {
		// do nothing
	} 
	inline void insert(const TypeValue a, const TypeValue b) {
		insert({a,b});
	}
	//傾きの大きさが常に最大or最小になるようにinsertする
	inline void insert(const pair<TypeValue,TypeValue> line) {
		if(lines.empty() || line.first <= lines.front().first) insert_front(line);
		else if(lines.back().first <= line.first) insert_back(line);
		else assert(false);
	}
	//O(log(N))
	inline TypeValue get(TypeValue x) {
		if(lines.empty()) return Operator::unit_value;
		int ng = -1, ok = (int)lines.size()-1, md;
		while (ok - ng > 1) {
			md = (ok + ng) >> 1;
			( Operator::func_compare(y(lines[md],x),y(lines[md+1],x)) ?ok:ng)=md;
		}
		return y(lines[ok],x);
	}
	//O(log(N))
	inline pair<TypeValue,TypeValue> get_line(TypeValue x) {
		if(lines.empty()) return {0,Operator::unit_value};
		int ng = -1, ok = (int)lines.size()-1, md;
		while (ok - ng > 1) {
			md = (ok + ng) >> 1;
			( Operator::func_compare(y(lines[md],x),y(lines[md+1],x)) ?ok:ng)=md;
		}
		return lines[ok];
	}
	//O(N)
	inline void clear(void) {
		lines.clear();
	}
};

//最小値クエリ
template<class T> struct ValueMin {
	using TypeValue = T;
	inline static constexpr TypeValue unit_value = 3e18;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<r;}
};

//最大値クエリ
template<class T> struct ValueMax {
	using TypeValue = T;
	inline static constexpr TypeValue unit_value = -3e18;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>r;}
};
#line 9 "test/geometory/ConvexHullTrickMonotone-max.test.cpp"
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
	ConvexHullTrickMonotone<ValueMax<ll>> cht;
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

