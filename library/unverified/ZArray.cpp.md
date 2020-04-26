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


# :warning: unverified/ZArray.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/ZArray.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

// O(N)
template<class T> vector<int> ZArray(const vector<T> arr) {
	int N = arr.size();
	vector<int> res(N);
	for(int i = 1, j = 0; i < N; i++) {
		if(i + res[i - j] < j + res[j]) {
			res[i] = res[i - j];
		} 
		else {
			int k = max(0, j + res[j] - i);
			while(i + k < N && arr[k] == arr[i + k]) ++k;
			res[j = i] = k;
		}
	}
	res[0] = N;
	return res;
}
//verify https://atcoder.jp/contests/abc150/tasks/abc150_f
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/ZArray.cpp"

// O(N)
template<class T> vector<int> ZArray(const vector<T> arr) {
	int N = arr.size();
	vector<int> res(N);
	for(int i = 1, j = 0; i < N; i++) {
		if(i + res[i - j] < j + res[j]) {
			res[i] = res[i - j];
		} 
		else {
			int k = max(0, j + res[j] - i);
			while(i + k < N && arr[k] == arr[i + k]) ++k;
			res[j = i] = k;
		}
	}
	res[0] = N;
	return res;
}
//verify https://atcoder.jp/contests/abc150/tasks/abc150_f

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

