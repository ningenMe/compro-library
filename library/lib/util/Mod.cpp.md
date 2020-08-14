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


# :heavy_check_mark: Mod

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/Mod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 06:33:25+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/util/Mod.test.cpp.html">test/util/Mod.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

