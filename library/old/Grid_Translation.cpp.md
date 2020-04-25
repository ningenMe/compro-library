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


# :warning: old/Grid_Translation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/Grid_Translation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 00:30:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

class Grid_Translation {
	int H,W;
public:
	Grid_Translation(const int& H,const int& W):H(H),W(W){
		// do nothing
	}

	int YXtoN(const int& y,const int& x){
		return y*W+x;
	}

	int NtoY(const int& N){
		return N/W;
	}

	int NtoX(const int& N){
		return N%W;
	}
};

//verify https://codeforces.com/contest/1130/problem/C
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/Grid_Translation.cpp"
#include <bits/stdc++.h>
using namespace std;

class Grid_Translation {
	int H,W;
public:
	Grid_Translation(const int& H,const int& W):H(H),W(W){
		// do nothing
	}

	int YXtoN(const int& y,const int& x){
		return y*W+x;
	}

	int NtoY(const int& N){
		return N/W;
	}

	int NtoX(const int& N){
		return N%W;
	}
};

//verify https://codeforces.com/contest/1130/problem/C

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

