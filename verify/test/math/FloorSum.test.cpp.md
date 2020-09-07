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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/math/FloorSum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/FloorSum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 05:45:39+09:00


* see: <a href="https://judge.yosupo.jp/problem/sum_of_floor_of_linear">https://judge.yosupo.jp/problem/sum_of_floor_of_linear</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/FloorSum.cpp.html">FloorSum</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>
using namespace std;
#include "../../lib/math/FloorSum.cpp"

int main() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    int Q; cin >> Q;
    while(Q--){
        long long N,M,A,B; cin >> N >> M >> A >> B;
        cout << FloorSum(N,M,A,B) << "\n";
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/FloorSum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>
using namespace std;
#line 1 "lib/math/FloorSum.cpp"
/**
 * @title FloorSum
 * O(log(n+m+a+b))
 * Σi:[0,N) floor((a*i+b)/m)を計算する
 * @see "https://min-25.hatenablog.com/entry/2018/04/27/225535"
 * @see "https://min-25.hatenablog.com/entry/2018/05/03/145505"
 */
inline static long long FloorSum(long long n, long long m, long long a, long long b) {
    long long ret=0;
    while(1) {
        if(a >= m) ret += ((n-1)*n*(a/m))>>1,a%=m;
        if(b >= m) ret += n*(b / m),b%=m;
        long long y=(a*n+b)/m, x=(y*m-b);
        if(y==0) return ret;
        ret += (n-(x+a-1)/a)*y;
        b=(a-x%a)%a; swap(a,m); n=y;
    }
}
#line 6 "test/math/FloorSum.test.cpp"

int main() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    int Q; cin >> Q;
    while(Q--){
        long long N,M,A,B; cin >> N >> M >> A >> B;
        cout << FloorSum(N,M,A,B) << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

