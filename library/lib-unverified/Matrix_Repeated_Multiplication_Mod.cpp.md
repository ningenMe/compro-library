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


# :warning: lib-unverified/Matrix_Repeated_Multiplication_Mod.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/Matrix_Repeated_Multiplication_Mod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Matrix_Repeated_Multiplication_Mod O((N^3)(logK))
vector<vector<long long>> Matrix_Repeated_Multiplication_Mod(vector<vector<long long>> mat, long long K, long long mod) {
    int N = mat.size();
    vector<vector<long long>> res(N, vector<long long>(N)), tmp(N, vector<long long>(N));

    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res[i][j] = (i == j);
    for (; K > 0; K /= 2) {
        if (K & 1) {
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) (tmp[i][j] += (mat[i][k] * res[k][j]) % mod) %= mod;
            res = tmp;
        }
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) (tmp[i][j] += (mat[i][k] * mat[k][j]) % mod) %= mod;
        mat = tmp;
    }
    return res;
}

//verify  https://atcoder.jp/contests/dp/tasks/dp_r

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/Matrix_Repeated_Multiplication_Mod.cpp"
#include <bits/stdc++.h>
using namespace std;

//Matrix_Repeated_Multiplication_Mod O((N^3)(logK))
vector<vector<long long>> Matrix_Repeated_Multiplication_Mod(vector<vector<long long>> mat, long long K, long long mod) {
    int N = mat.size();
    vector<vector<long long>> res(N, vector<long long>(N)), tmp(N, vector<long long>(N));

    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res[i][j] = (i == j);
    for (; K > 0; K /= 2) {
        if (K & 1) {
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) (tmp[i][j] += (mat[i][k] * res[k][j]) % mod) %= mod;
            res = tmp;
        }
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) (tmp[i][j] += (mat[i][k] * mat[k][j]) % mod) %= mod;
        mat = tmp;
    }
    return res;
}

//verify  https://atcoder.jp/contests/dp/tasks/dp_r

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

