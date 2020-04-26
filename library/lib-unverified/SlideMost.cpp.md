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


# :warning: lib-unverified/SlideMost.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/SlideMost.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//O(N) N: vec.size();
template<class T> vector<T> SlideMost(vector<T>& vec, const int& width, function<int(T,T)> funcCompare){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && funcCompare(vec[deq.back()],vec[i]) ) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}

	// auto Amax = SlideMost<int>(A,K,[&](ll l,ll r){return l <= r;});
	// auto Amin = SlideMost<int>(A,K,[&](ll l,ll r){return l >= r;});

//verify https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d
//verify https://atcoder.jp/contests/agc038/tasks/agc038_b
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/SlideMost.cpp"

//O(N) N: vec.size();
template<class T> vector<T> SlideMost(vector<T>& vec, const int& width, function<int(T,T)> funcCompare){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && funcCompare(vec[deq.back()],vec[i]) ) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}

	// auto Amax = SlideMost<int>(A,K,[&](ll l,ll r){return l <= r;});
	// auto Amin = SlideMost<int>(A,K,[&](ll l,ll r){return l >= r;});

//verify https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d
//verify https://atcoder.jp/contests/agc038/tasks/agc038_b

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

