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


# :warning: Distance.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Distance.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-18 19:34:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Euclidean distance
template<class T> T EucDist(T x1, T y1, T x2, T y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//Chebyshev distance
template<class T> T ChebDist(T x1, T y1, T x2, T y2) {
    return max(abs(x1 - x2),abs(y1 - y2));
}

//Manhattan distance
template<class T> T ManhDist(T x1, T y1, T x2, T y2) {
    return abs(x1 - x2)+abs(y1 - y2);
}

double Distance_Point_to_Line(const double& x,const double& y,const double& x1,const double& y1,const double& x2,const double& y2){
	double a = y2 - y1, b = -(x2 - x1), c = -(y2-y1)*x1+(x2-x1)*y1;
	return abs(a*x+b*y+c)/sqrt(a*a+b*b);
}

//verify 
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Distance.cpp"
#include <bits/stdc++.h>
using namespace std;

//Euclidean distance
template<class T> T EucDist(T x1, T y1, T x2, T y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//Chebyshev distance
template<class T> T ChebDist(T x1, T y1, T x2, T y2) {
    return max(abs(x1 - x2),abs(y1 - y2));
}

//Manhattan distance
template<class T> T ManhDist(T x1, T y1, T x2, T y2) {
    return abs(x1 - x2)+abs(y1 - y2);
}

double Distance_Point_to_Line(const double& x,const double& y,const double& x1,const double& y1,const double& x2,const double& y2){
	double a = y2 - y1, b = -(x2 - x1), c = -(y2-y1)*x1+(x2-x1)*y1;
	return abs(a*x+b*y+c)/sqrt(a*a+b*b);
}

//verify 

```
{% endraw %}

<a href="../index.html">Back to top page</a>

