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


# :warning: unverified/Chinese_Remainder_Theorem.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/Chinese_Remainder_Theorem.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		long long d = extGCD(b, a%b, y, x);
		y -= a / b * x;
		return d;
	}
}

// r mod m_i = b_i, M = lcm(m_i)
pair<long long, long long> Chinese_Remainder_Theorem(const vector<long long> &b, const vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < b.size(); ++i) {
        long long p, q;
        long long d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return {0, -1};
        long long tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return {(r%M+M)%M, M};
}

//verify https://yukicoder.me/problems/no/186
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/Chinese_Remainder_Theorem.cpp"
#include <bits/stdc++.h>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		long long d = extGCD(b, a%b, y, x);
		y -= a / b * x;
		return d;
	}
}

// r mod m_i = b_i, M = lcm(m_i)
pair<long long, long long> Chinese_Remainder_Theorem(const vector<long long> &b, const vector<long long> &m) {
    long long r = 0, M = 1;
    for (int i = 0; i < b.size(); ++i) {
        long long p, q;
        long long d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return {0, -1};
        long long tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return {(r%M+M)%M, M};
}

//verify https://yukicoder.me/problems/no/186

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

