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


# :warning: unverified/Longest_Common_Subsequence_Size.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/Longest_Common_Subsequence_Size.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

int Longest_Common_Subsequence_Size(const string& S, const string& T){
	vector<vector<int>> res(S.size()+1,vector<int>(T.size()+1,0));
    for(size_t i = 0; i < S.size(); i++)
    for(size_t j = 0; j < T.size(); j++)
    res[i+1][j+1] = (S[i] == T[j] ? res[i][j] + 1 : max(res[i][j + 1],res[i + 1][j]) );
    return res[S.size()][T.size()];
}

//verify https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_a
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/Longest_Common_Subsequence_Size.cpp"
#include <bits/stdc++.h>
using namespace std;

int Longest_Common_Subsequence_Size(const string& S, const string& T){
	vector<vector<int>> res(S.size()+1,vector<int>(T.size()+1,0));
    for(size_t i = 0; i < S.size(); i++)
    for(size_t j = 0; j < T.size(); j++)
    res[i+1][j+1] = (S[i] == T[j] ? res[i][j] + 1 : max(res[i][j + 1],res[i + 1][j]) );
    return res[S.size()][T.size()];
}

//verify https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_a

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

