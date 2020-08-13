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


# :warning: non-verified/Accumulate2D.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/Accumulate2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-14 03:16:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> class Accumulate2D {
	vector<vector<T>> acc;
public:
	//arg grid is 0-indexed 
	Accumulate2D(const vector<vector<T>>& grid)
	: acc(grid.size()+1,vector<T>(grid.front().size()+1)){
		for(int i = 1; i < acc.size(); ++i) {
			for(int j = 1; j < acc[i].size(); ++j) {
				acc[i][j]+=grid[i-1][j-1]+acc[i][j-1]+acc[i-1][j]-acc[i-1][j-1];
			}
		}
	}
	// 左上[y1,x1] 右下[y2,x2] 0-indexed
	inline T get(int y1,int x1,int y2,int x2) {
		y2++,x2++;
		return acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/Accumulate2D.cpp"
template<class T> class Accumulate2D {
	vector<vector<T>> acc;
public:
	//arg grid is 0-indexed 
	Accumulate2D(const vector<vector<T>>& grid)
	: acc(grid.size()+1,vector<T>(grid.front().size()+1)){
		for(int i = 1; i < acc.size(); ++i) {
			for(int j = 1; j < acc[i].size(); ++j) {
				acc[i][j]+=grid[i-1][j-1]+acc[i][j-1]+acc[i-1][j]-acc[i-1][j-1];
			}
		}
	}
	// 左上[y1,x1] 右下[y2,x2] 0-indexed
	inline T get(int y1,int x1,int y2,int x2) {
		y2++,x2++;
		return acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

