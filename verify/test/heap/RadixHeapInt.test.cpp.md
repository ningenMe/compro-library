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


# :x: test/heap/RadixHeapInt.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a2bf5cb1737b82034660168b413e4164">test/heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/heap/RadixHeapInt.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 04:14:05+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596</a>


## Depends on

* :x: <a href="../../../library/lib/heap/RadixHeapInt.cpp.html">lib/heap/RadixHeapInt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/heap/RadixHeapInt.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,K; cin >> N >> K;
	vector<int> C(N),R(N);
	for(int i = 0; i < N; ++i) cin >> C[i] >> R[i];
	vector<vector<int>> edge(N);
	for(int i = 0; i < K; ++i) {
		int A,B; cin >> A >> B;
		A--,B--;
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	vector<vector<int>> dp(N,vector<int>(N+1,1<<30));
	dp[0][0] = 0;
	RadixHeapInt<pair<int,int>> pq({0,0});
	pq.push({0,{0,0}});
	while(pq.size()){
		auto p = pq.pop();
		int from = p.second.first;
		int r = p.second.second;
		if(r){
			for(int to:edge[from]){
				if(dp[to][r-1]>dp[from][r]){
					dp[to][r-1]=dp[from][r];
					pq.push({dp[to][r-1],{to,r-1}});
				}
			}
		}
		if(dp[from][R[from]]>dp[from][r]+C[from]){
			dp[from][R[from]]=dp[from][r]+C[from];
			pq.push({dp[from][R[from]],{from,R[from]}});
		}
	}
	cout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/heap/RadixHeapInt.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#line 1 "lib/heap/RadixHeapInt.cpp"
template<class T> class RadixHeapInt{
	using TypeNode = pair<unsigned int, T>;
	array<vector<TypeNode>,33> vq;
	unsigned int size_num;
	TypeNode last;
	inline int bit(int a) {
		return a ? 32 - __builtin_clz(a) : 0;
	}
public:
	RadixHeapInt(T mini) : size_num(0), last(make_pair(0,mini)) {
		// do nothing
	}
	inline bool empty() {
		return size_num == 0;
	}
	inline size_t size(){
		return size_num;
	}
	inline void push(TypeNode x){
		++size_num;
		vq[bit(x.first^last.first)].push_back(x);
	}
	inline void emplace(unsigned int key,T val){
		++size_num;
		vq[bit(key^last.first)].emplace_back(key,val);
	}
	inline TypeNode pop() {
		if(vq[0].empty()) {
			int i = 1;
			while(vq[i].empty()) ++i;
			last = *min_element(vq[i].begin(),vq[i].end());
			for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);
			vq[i].clear();
		}
		--size_num;
		auto res = vq[0].back();
		vq[0].pop_back();
		return res;
	}
};
#line 8 "test/heap/RadixHeapInt.test.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,K; cin >> N >> K;
	vector<int> C(N),R(N);
	for(int i = 0; i < N; ++i) cin >> C[i] >> R[i];
	vector<vector<int>> edge(N);
	for(int i = 0; i < K; ++i) {
		int A,B; cin >> A >> B;
		A--,B--;
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	vector<vector<int>> dp(N,vector<int>(N+1,1<<30));
	dp[0][0] = 0;
	RadixHeapInt<pair<int,int>> pq({0,0});
	pq.push({0,{0,0}});
	while(pq.size()){
		auto p = pq.pop();
		int from = p.second.first;
		int r = p.second.second;
		if(r){
			for(int to:edge[from]){
				if(dp[to][r-1]>dp[from][r]){
					dp[to][r-1]=dp[from][r];
					pq.push({dp[to][r-1],{to,r-1}});
				}
			}
		}
		if(dp[from][R[from]]>dp[from][r]+C[from]){
			dp[from][R[from]]=dp[from][r]+C[from];
			pq.push({dp[from][R[from]],{from,R[from]}});
		}
	}
	cout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

