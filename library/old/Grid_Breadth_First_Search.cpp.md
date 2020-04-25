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


# :warning: old/Grid_Breadth_First_Search.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/Grid_Breadth_First_Search.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 00:30:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;


class Grid_Breadth_First_Dearch{
public:
	int H,W;
	vector<string> S;
	vector<vector<int>> dist;

	Grid_Breadth_First_Dearch(int H,int W):H(H),W(W),S(H),dist(H,vector<int>(W)){
		//do nothing
	}

	void solve(int sy,int sx){
		for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) dist[i][j] = -1;
		queue<pair<int,int>> q;
		dist[sy][sx] = 0;
		q.push({sy,sx});
		while(q.size()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if(0 < y && S[y-1][x] == '.' && dist[y-1][x] == -1){
				dist[y-1][x] = dist[y][x] + 1;
				q.push({y-1,x});
			}
			if(y < H - 1 && S[y+1][x] == '.' && dist[y+1][x] == -1){
				dist[y+1][x] = dist[y][x] + 1;
				q.push({y+1,x});
			}
			if(0 < x && S[y][x-1] == '.' && dist[y][x-1] == -1){
				dist[y][x-1] = dist[y][x] + 1;
				q.push({y,x-1});
			}
			if(x < W - 1 && S[y][x+1] == '.' && dist[y][x+1] == -1){
				dist[y][x+1] = dist[y][x] + 1;
				q.push({y,x+1});
			}
		}
	}
};

//verify https://atcoder.jp/contests/agc014/tasks/agc014_c
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/Grid_Breadth_First_Search.cpp"
#include <bits/stdc++.h>
using namespace std;


class Grid_Breadth_First_Dearch{
public:
	int H,W;
	vector<string> S;
	vector<vector<int>> dist;

	Grid_Breadth_First_Dearch(int H,int W):H(H),W(W),S(H),dist(H,vector<int>(W)){
		//do nothing
	}

	void solve(int sy,int sx){
		for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) dist[i][j] = -1;
		queue<pair<int,int>> q;
		dist[sy][sx] = 0;
		q.push({sy,sx});
		while(q.size()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if(0 < y && S[y-1][x] == '.' && dist[y-1][x] == -1){
				dist[y-1][x] = dist[y][x] + 1;
				q.push({y-1,x});
			}
			if(y < H - 1 && S[y+1][x] == '.' && dist[y+1][x] == -1){
				dist[y+1][x] = dist[y][x] + 1;
				q.push({y+1,x});
			}
			if(0 < x && S[y][x-1] == '.' && dist[y][x-1] == -1){
				dist[y][x-1] = dist[y][x] + 1;
				q.push({y,x-1});
			}
			if(x < W - 1 && S[y][x+1] == '.' && dist[y][x+1] == -1){
				dist[y][x+1] = dist[y][x] + 1;
				q.push({y,x+1});
			}
		}
	}
};

//verify https://atcoder.jp/contests/agc014/tasks/agc014_c

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

