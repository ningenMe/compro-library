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


# :heavy_check_mark: test/geometory/Distance-line.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1559848aad74dc56829252d458066b03">test/geometory</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometory/Distance-line.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 00:50:06+09:00


* see: <a href="https://yukicoder.me/problems/no/1041">https://yukicoder.me/problems/no/1041</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/geometory/Distance.cpp.html">lib/geometory/Distance.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1041"

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "../../lib/geometory/Distance.cpp"

int main(void){
    int N; cin >> N;
    vector<double> x(N),y(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            int cnt = 2;
            for(int k = 0; k < N; ++k){
                if(k==i || k == j) continue;
                if(Distance<long double>::between_point_and_line(x[i],y[i],x[j],y[j],x[k],y[k]) < 1e-3 ) cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/geometory/Distance-line.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1041"

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#line 1 "lib/geometory/Distance.cpp"

template<class T> class Distance{
public:
    //Euclidean distance
    inline static constexpr T euclid(const T& x1, const T& y1, const T& x2, const T& y2) {
        return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }
    //Chebyshev distance
    inline static constexpr T chebyshev(T x1, T y1, T x2, T y2) {
        return max(abs(x1 - x2),abs(y1 - y2));
    }
    //Manhattan distance
    inline static constexpr T manhattan(T x1, T y1, T x2, T y2) {
        return abs(x1 - x2)+abs(y1 - y2);
    }
    inline static constexpr T between_point_and_line(const T& x,const T& y,const T& x1,const T& y1,const T& x2,const T& y2){
        return abs((y2 - y1)*x+(x1 - x2)*y-(y2-y1)*x1+(x2-x1)*y1)/sqrt((y2 - y1)*(y2 - y1)+(x1 - x2)*(x1 - x2));
    }
};
#line 8 "test/geometory/Distance-line.test.cpp"

int main(void){
    int N; cin >> N;
    vector<double> x(N),y(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            int cnt = 2;
            for(int k = 0; k < N; ++k){
                if(k==i || k == j) continue;
                if(Distance<long double>::between_point_and_line(x[i],y[i],x[j],y[j],x[k],y[k]) < 1e-3 ) cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

