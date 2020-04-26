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


# :warning: unverified/Maximum_Segment_Sum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/Maximum_Segment_Sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

//Maximum Segment Sum O(N)
template<class T> T Maximum_Segment_Sum(const vector<T> & ar, T inf) {
    T res = -inf, sum = 0;
    for (int i = 0; i < ar.size(); ++i) {
        sum = max(sum + ar[i], ar[i]);
        res = max(res, sum);
    }
    return res;
}

//verify 
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/Maximum_Segment_Sum.cpp"
#include <bits/stdc++.h>
using namespace std;

//Maximum Segment Sum O(N)
template<class T> T Maximum_Segment_Sum(const vector<T> & ar, T inf) {
    T res = -inf, sum = 0;
    for (int i = 0; i < ar.size(); ++i) {
        sum = max(sum + ar[i], ar[i]);
        res = max(res, sum);
    }
    return res;
}

//verify 

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

