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


# :warning: unverified/Longest_Common_Subsequence.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/Longest_Common_Subsequence.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

string Longest_Common_Subsequence(const string& S, const string& T){
	int N = S.size(), M = T.size();
	vector<vector<int>> ar(N+1,vector<int>(M+1,0));
    for(size_t i = 0; i < N; i++)
    for(size_t j = 0; j < M; j++)
    ar[i+1][j+1] = (S[i] == T[j] ? ar[i][j] + 1 : max(ar[i][j + 1],ar[i + 1][j]) );

	string res = "";
	while(ar[N][M]>0){
		if(S[N-1]==T[M-1]){
			res.push_back(S[N-1]);
			N--,M--;
		}
		else{
			(ar[N-1][M]>ar[N][M-1]?N:M)--;
		}
	}

    reverse(res.begin(),res.end());
	return res;
}
//verify https://atcoder.jp/contests/dp/tasks/dp_f
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/Longest_Common_Subsequence.cpp"
#include <bits/stdc++.h>
using namespace std;

string Longest_Common_Subsequence(const string& S, const string& T){
	int N = S.size(), M = T.size();
	vector<vector<int>> ar(N+1,vector<int>(M+1,0));
    for(size_t i = 0; i < N; i++)
    for(size_t j = 0; j < M; j++)
    ar[i+1][j+1] = (S[i] == T[j] ? ar[i][j] + 1 : max(ar[i][j + 1],ar[i + 1][j]) );

	string res = "";
	while(ar[N][M]>0){
		if(S[N-1]==T[M-1]){
			res.push_back(S[N-1]);
			N--,M--;
		}
		else{
			(ar[N-1][M]>ar[N][M-1]?N:M)--;
		}
	}

    reverse(res.begin(),res.end());
	return res;
}
//verify https://atcoder.jp/contests/dp/tasks/dp_f

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

