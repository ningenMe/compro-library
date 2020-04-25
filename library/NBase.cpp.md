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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: NBase.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/NBase.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 00:20:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<long long> NBase(long long X,long long N) {
    assert(abs(N)>1);
    vector<long long> res;
    while(1) {
        long long b = (X%abs(N)+abs(N)) % abs(N);
        res.push_back(b);
        (X -= b) /= N;
        if(X==0) break;
    }
    return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "NBase.cpp"
vector<long long> NBase(long long X,long long N) {
    assert(abs(N)>1);
    vector<long long> res;
    while(1) {
        long long b = (X%abs(N)+abs(N)) % abs(N);
        res.push_back(b);
        (X -= b) /= N;
        if(X==0) break;
    }
    return res;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

