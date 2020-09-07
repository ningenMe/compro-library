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


# :heavy_check_mark: FloorSum

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b524a7b47b8ed72180f0e5150ab6d934">lib/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/math/FloorSum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 05:45:39+09:00


* see: <a href=""https://min-25.hatenablog.com/entry/2018/04/27/225535"">"https://min-25.hatenablog.com/entry/2018/04/27/225535"</a>
* see: <a href=""https://min-25.hatenablog.com/entry/2018/05/03/145505"">"https://min-25.hatenablog.com/entry/2018/05/03/145505"</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/math/FloorSum.test.cpp.html">test/math/FloorSum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title FloorSum
 * O(log(n+m+a+b))
 * Σi:[0,N) floor((a*i+b)/m)を計算する
 * @see "https://min-25.hatenablog.com/entry/2018/04/27/225535"
 * @see "https://min-25.hatenablog.com/entry/2018/05/03/145505"
 */
inline static long long FloorSum(long long n, long long m, long long a, long long b) {
    long long ret=0;
    while(1) {
        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;
        if(b >= m) ret += n*(b / m),b%=m;
        long long y=(a*n+b)/m, x=(y*m-b);
        if(y==0) return ret;
        ret += (n-(x+a-1)/a)*y;
        b=(a-x%a)%a; swap(a,m); n=y;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/math/FloorSum.cpp"
/**
 * @title FloorSum
 * O(log(n+m+a+b))
 * Σi:[0,N) floor((a*i+b)/m)を計算する
 * @see "https://min-25.hatenablog.com/entry/2018/04/27/225535"
 * @see "https://min-25.hatenablog.com/entry/2018/05/03/145505"
 */
inline static long long FloorSum(long long n, long long m, long long a, long long b) {
    long long ret=0;
    while(1) {
        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;
        if(b >= m) ret += n*(b / m),b%=m;
        long long y=(a*n+b)/m, x=(y*m-b);
        if(y==0) return ret;
        ret += (n-(x+a-1)/a)*y;
        b=(a-x%a)%a; swap(a,m); n=y;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

