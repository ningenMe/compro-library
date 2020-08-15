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


# :heavy_check_mark: RangeIndex

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#76d75a8065c92efe3b83e817563c11ef">lib/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/util/RangeIndex.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 15:57:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/util/RangeIndex.test.cpp.html">test/util/RangeIndex.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
 * @title RangeIndex
 */
/*
 * @title RangeIndex
 */
class RangeIndex{
	int length;
public:
	RangeIndex(const int N) {
		for (length = 1; length <= N; length *= 2);
	}
	//[l,r)
	vector<int> range(int l,int r) {
		vector<int> res;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) res.push_back(l++);
			if(r&1) res.push_back(--r);
		}
		return res;
	}
	// ranges that include x
	vector<int> include_range(int x) {
		vector<int> res;
        for(int i=x+length; i; i >>= 1) res.push_back(i);
		return res;
	}
	inline int operator[](int idx) {
		return idx+length;
	}
	inline size_t size(void){
		return 2*length;
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/util/RangeIndex.cpp"
/*
 * @title RangeIndex
 */
/*
 * @title RangeIndex
 */
class RangeIndex{
	int length;
public:
	RangeIndex(const int N) {
		for (length = 1; length <= N; length *= 2);
	}
	//[l,r)
	vector<int> range(int l,int r) {
		vector<int> res;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) res.push_back(l++);
			if(r&1) res.push_back(--r);
		}
		return res;
	}
	// ranges that include x
	vector<int> include_range(int x) {
		vector<int> res;
        for(int i=x+length; i; i >>= 1) res.push_back(i);
		return res;
	}
	inline int operator[](int idx) {
		return idx+length;
	}
	inline size_t size(void){
		return 2*length;
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

