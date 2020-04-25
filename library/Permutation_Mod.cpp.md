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


# :warning: Permutation_Mod.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Permutation_Mod.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-24 04:36:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Pow_Mod O(log(N))
long long Pow_Mod(long long x, long long n, long long mod) {
    long long res = 1;
    for (; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;
    return res;
}

//Permutation_Mod O(N^2)
vector<vector<long long>> Permutation_Mod(long long N, long long mod) {
    vector<long long> fac(N + 1, 1);
    for (long long i = 1; i <= N; ++i) fac[i] = (fac[i - 1] * i) % mod;
    vector<long long> inv(N + 1, 1);
    for (long long i = 1; i <= N; ++i) inv[i] = Pow_Mod(fac[i], mod - 2, mod);
    vector<vector<long long>> res(N + 1, vector<long long>(N + 1, 1));
    for (long long i = 1; i <= N; ++i) for (long long j = 1; j <= i; ++j) res[i][j] = (fac[i] * inv[i - j]) % mod;
    return res;
}

//verify https://atcoder.jp/contests/arc067/tasks/arc067_c
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Permutation_Mod.cpp"
#include <bits/stdc++.h>
using namespace std;

//Pow_Mod O(log(N))
long long Pow_Mod(long long x, long long n, long long mod) {
    long long res = 1;
    for (; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;
    return res;
}

//Permutation_Mod O(N^2)
vector<vector<long long>> Permutation_Mod(long long N, long long mod) {
    vector<long long> fac(N + 1, 1);
    for (long long i = 1; i <= N; ++i) fac[i] = (fac[i - 1] * i) % mod;
    vector<long long> inv(N + 1, 1);
    for (long long i = 1; i <= N; ++i) inv[i] = Pow_Mod(fac[i], mod - 2, mod);
    vector<vector<long long>> res(N + 1, vector<long long>(N + 1, 1));
    for (long long i = 1; i <= N; ++i) for (long long j = 1; j <= i; ++j) res[i][j] = (fac[i] * inv[i - j]) % mod;
    return res;
}

//verify https://atcoder.jp/contests/arc067/tasks/arc067_c

```
{% endraw %}

<a href="../index.html">Back to top page</a>

