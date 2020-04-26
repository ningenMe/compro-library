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


# :warning: lib-unverified/LongestIncreasingSubsequence.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/LongestIncreasingSubsequence.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//Longest Increasing Subsequence O(NlogN)
template<class T> int LongestIncreasingSubsequence(const vector<T> & ar, T inf) {
	vector<T> dp(ar.size(), inf);
	for (int i = 0; i < ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];
	return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}

//verify https://atcoder.jp/contests/abc006/tasks/abc006_4
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/LongestIncreasingSubsequence.cpp"
//Longest Increasing Subsequence O(NlogN)
template<class T> int LongestIncreasingSubsequence(const vector<T> & ar, T inf) {
	vector<T> dp(ar.size(), inf);
	for (int i = 0; i < ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];
	return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}

//verify https://atcoder.jp/contests/abc006/tasks/abc006_4

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

