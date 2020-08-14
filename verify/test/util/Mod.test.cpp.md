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


# :heavy_check_mark: test/util/Mod.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b474f495c8582ac5f92778a42ae814fa">test/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/util/Mod.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 06:33:25+09:00


* see: <a href="https://yukicoder.me/problems/no/1161">https://yukicoder.me/problems/no/1161</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/util/Mod.cpp.html">Mod</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1161"

#include <vector>
#include <iostream>
#include <array>
#include <numeric>
using namespace std;
#include "../../lib/util/Mod.cpp"

int main() {
	long long A,B,C;
	scanf("%lld%lld%lld",&A,&B,&C);
	long long ans = 0;
	array<long long,100001> cnt;
	for(long long i = 1; i <= C; ++i) {
		cnt[i] = Mod::pow(i,B,C);
	}
	for(long long i = 1; i <= A%C; ++i) {
		ans += cnt[i];
	}
	ans += (accumulate(cnt.begin(),cnt.begin()+C,0LL)%C)*(A/C);
	printf("%lld\n",ans%C);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/util/Mod.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1161"

#include <vector>
#include <iostream>
#include <array>
#include <numeric>
using namespace std;
#line 1 "lib/util/Mod.cpp"
/*
 * @title Mod
 */
class Mod{
public:
	//Pow_Mod O(log(n))
	inline static long long pow(long long x, long long n, long long mod) {
		long long res = 1;
		for (x %= mod; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;
		return res;
	}
	//Inv_Mod O(log(mod))
	inline static long long inv(long long x, long long mod){
		return pow(x,mod-2,mod); 
	}
};
#line 9 "test/util/Mod.test.cpp"

int main() {
	long long A,B,C;
	scanf("%lld%lld%lld",&A,&B,&C);
	long long ans = 0;
	array<long long,100001> cnt;
	for(long long i = 1; i <= C; ++i) {
		cnt[i] = Mod::pow(i,B,C);
	}
	for(long long i = 1; i <= A%C; ++i) {
		ans += cnt[i];
	}
	ans += (accumulate(cnt.begin(),cnt.begin()+C,0LL)%C)*(A/C);
	printf("%lld\n",ans%C);
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

