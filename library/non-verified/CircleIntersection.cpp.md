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


# :warning: non-verified/CircleIntersection.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/CircleIntersection.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:29:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> inline vector<pair<T,T>> CircleIntersection(pair<T,T> p1, T r1, pair<T,T> p2, T r2, T eps = 1e-6) {
	vector<pair<T,T>> res;
	T x1 = p1.first;
	T y1 = p1.second;
	T x2 = p2.first;
	T y2 = p2.second;
	if(abs(x1-x2) < eps && abs(y1-y2) < eps && abs(r1-r2) < eps) return res;
	if(r1 + r2 + eps < sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))) return res;
	T a = 2*(x1-x2);
	T b = 2*(y1-y2);
	T c = -(x1*x1-x2*x2) - (y1*y1-y2*y2) + (r1*r1 - r2*r2);
	T d = a*x1+b*y1+c;
	T e = (a*a+b*b)*r1*r1-d*d;
	if(e<0) return res;
	e = sqrt(e);
	T x3 = (-a*d+b*e)/(a*a+b*b) + x1;
	T y3 = (-b*d-a*e)/(a*a+b*b) + y1;
	T x4 = (-a*d-b*e)/(a*a+b*b) + x1;
	T y4 = (-b*d+a*e)/(a*a+b*b) + y1;
	res.push_back({x3,y3});
	res.push_back({x4,y4});
	return res;
}
//verify https://atcoder.jp/contests/abc157/tasks/abc157_f
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/CircleIntersection.cpp"
template<class T> inline vector<pair<T,T>> CircleIntersection(pair<T,T> p1, T r1, pair<T,T> p2, T r2, T eps = 1e-6) {
	vector<pair<T,T>> res;
	T x1 = p1.first;
	T y1 = p1.second;
	T x2 = p2.first;
	T y2 = p2.second;
	if(abs(x1-x2) < eps && abs(y1-y2) < eps && abs(r1-r2) < eps) return res;
	if(r1 + r2 + eps < sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))) return res;
	T a = 2*(x1-x2);
	T b = 2*(y1-y2);
	T c = -(x1*x1-x2*x2) - (y1*y1-y2*y2) + (r1*r1 - r2*r2);
	T d = a*x1+b*y1+c;
	T e = (a*a+b*b)*r1*r1-d*d;
	if(e<0) return res;
	e = sqrt(e);
	T x3 = (-a*d+b*e)/(a*a+b*b) + x1;
	T y3 = (-b*d-a*e)/(a*a+b*b) + y1;
	T x4 = (-a*d-b*e)/(a*a+b*b) + x1;
	T y4 = (-b*d+a*e)/(a*a+b*b) + y1;
	res.push_back({x3,y3});
	res.push_back({x4,y4});
	return res;
}
//verify https://atcoder.jp/contests/abc157/tasks/abc157_f

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

