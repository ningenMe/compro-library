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


# :heavy_check_mark: test/string/Zalgorithm.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e46c0047b1d14ef43eeaaf13f64d385f">test/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/string/Zalgorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 00:15:05+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/string/Zalgorithm.cpp.html">Zalgorithm</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/string/Zalgorithm.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string S; cin >> S;
    Zalgorithm z(S);
    for(int i=0;i<S.size();++i) cout << z[i] << " ";
    cout << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/string/Zalgorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <vector>
#include <iostream>
using namespace std;
#line 1 "lib/string/Zalgorithm.cpp"
/*
 * @title Zalgorithm
 */
class Zalgorithm{
    vector<int> zarray;
    template<class T> void init(const vector<T>& ar) {
        int N = ar.size();
        for(int i = 1, j = 0; i < N; ++i) {
            if(i + zarray[i - j] < j + zarray[j]) {
                zarray[i] = zarray[i - j];
            } 
            else {
                int k = max(0, j + zarray[j] - i);
                while(i + k < N && ar[k] == ar[i + k]) ++k;
                zarray[j = i] = k;
            }
        }
        zarray[0] = N;
    }
public:
    template<class T> Zalgorithm(const vector<T>& ar) : zarray(ar.size()) {
        init(ar);
    }
    Zalgorithm(const string& s) : zarray(s.size()) {
        vector<char> ar(s.size());
        for(int i=0; i<s.size(); ++i) ar[i]=s[i];
        init(ar);
    }
	inline int operator[](int idx) {
		return zarray[idx];
	}
};
#line 7 "test/string/Zalgorithm.test.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    string S; cin >> S;
    Zalgorithm z(S);
    for(int i=0;i<S.size();++i) cout << z[i] << " ";
    cout << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

