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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: non-verified/Combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/Combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 12:36:39+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> class Combination{
	vector<vector<T>> num;
public:    
    //O(N^2)
    Combination(int N):num(N+1,vector<T>(N+1,(T)0)){
		num[0][0] = 1;
		for (int n = 1; n <= N; n++) {
			for (int k = 0; k <= n; k++) {
				num[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0));
			}
		}
    } 
	inline T binom(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);
	}
    //nCk mod p (p is prime & p <= N)
    inline T lucas(int n, int k, long long p) {
        long long res=1;
        for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p]) %= p;
        return res;
    }
};
//https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/Combination.cpp"
template<class T> class Combination{
	vector<vector<T>> num;
public:    
    //O(N^2)
    Combination(int N):num(N+1,vector<T>(N+1,(T)0)){
		num[0][0] = 1;
		for (int n = 1; n <= N; n++) {
			for (int k = 0; k <= n; k++) {
				num[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0));
			}
		}
    } 
	inline T binom(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);
	}
    //nCk mod p (p is prime & p <= N)
    inline T lucas(int n, int k, long long p) {
        long long res=1;
        for(;n||k;n/=p,k/=p) (res *= num[n%p][k%p]) %= p;
        return res;
    }
};
//https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

