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
    - Last commit date: 2020-04-26 16:29:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Combination
class Combination {
public:
	vector<vector<long long>> num;
	
	Combination(int N):num (vector<vector<long long>>(N+1,vector<long long>(N+1,0))) {
		num[0][0] = 1;
		for (int i = 1; i <= N; ++i) for (int j = 0; j <= i; ++j) num[i][j] = ((j == 0) ? 0 : num[i - 1][j - 1]) + num[i - 1][j];		
	}
};

//verify 
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/Combination.cpp"
#include <bits/stdc++.h>
using namespace std;

//Combination
class Combination {
public:
	vector<vector<long long>> num;
	
	Combination(int N):num (vector<vector<long long>>(N+1,vector<long long>(N+1,0))) {
		num[0][0] = 1;
		for (int i = 1; i <= N; ++i) for (int j = 0; j <= i; ++j) num[i][j] = ((j == 0) ? 0 : num[i - 1][j - 1]) + num[i - 1][j];		
	}
};

//verify 

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

