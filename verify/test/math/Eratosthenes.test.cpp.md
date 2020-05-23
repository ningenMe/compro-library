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


# :heavy_check_mark: test/math/Eratosthenes.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baced925baac5b3f9b4d24b3b28c718e">test/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/math/Eratosthenes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 02:56:21+09:00


* see: <a href="https://yukicoder.me/problems/no/1058">https://yukicoder.me/problems/no/1058</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/math/Eratosthenes.cpp.html">Eratosthenes</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1058"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/math/Eratosthenes.cpp"

int main() {
    long long N;
    cin >> N;
    auto E = Eratosthenes(200000);
    vector<long long> A;
    for(int i = 100001; i < 100100; ++i) {
        if(E[i]) A.push_back(i);
    }
    vector<long long> B={1};
    for(auto& e1:A) for(auto& e2:A) B.push_back(e1*e2);
    sort(B.begin(),B.end());
    unique(B.begin(),B.end());
    cout << B[N-1] << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/math/Eratosthenes.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1058"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#line 1 "lib/math/Eratosthenes.cpp"
/*
 * @title Eratosthenes
 * @docs md/math/Eratosthenes.md
 */
inline static vector<int> Eratosthenes(int N) {
    vector<int> res(N + 1, 1);
    res[0] = res[1%(N+1)] = 0;
    for (int i = 1; i*i <= N; i++) if (res[i]) for (int j = 2 * i; j <= N; j += i) res[j] = 0;
    return res;
}
#line 8 "test/math/Eratosthenes.test.cpp"

int main() {
    long long N;
    cin >> N;
    auto E = Eratosthenes(200000);
    vector<long long> A;
    for(int i = 100001; i < 100100; ++i) {
        if(E[i]) A.push_back(i);
    }
    vector<long long> B={1};
    for(auto& e1:A) for(auto& e2:A) B.push_back(e1*e2);
    sort(B.begin(),B.end());
    unique(B.begin(),B.end());
    cout << B[N-1] << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

