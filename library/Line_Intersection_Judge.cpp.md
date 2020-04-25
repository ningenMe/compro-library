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


# :warning: Line_Intersection_Judge.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Line_Intersection_Judge.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-21 02:47:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Line Intersection Judge
template<class T> bool Line_Intersection_Judge(T ax, T ay, T bx, T by, T cx, T cy, T dx, T dy) {
    T ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    T tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    T tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    T td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
    return tc * td < 0 && ta * tb < 0;
}

//verify https://atcoder.jp/contests/abc016/tasks/abc016_4
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Line_Intersection_Judge.cpp"
#include <bits/stdc++.h>
using namespace std;

//Line Intersection Judge
template<class T> bool Line_Intersection_Judge(T ax, T ay, T bx, T by, T cx, T cy, T dx, T dy) {
    T ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    T tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    T tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    T td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
    return tc * td < 0 && ta * tb < 0;
}

//verify https://atcoder.jp/contests/abc016/tasks/abc016_4

```
{% endraw %}

<a href="../index.html">Back to top page</a>

