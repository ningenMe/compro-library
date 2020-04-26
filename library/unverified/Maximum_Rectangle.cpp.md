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


# :warning: unverified/Maximum_Rectangle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/Maximum_Rectangle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

long long Maximum_Rectangle(vector<long long>& ar){
	ar.push_back(0);
	stack<pair<long long,long long>> st;
	long long res = 0;
	for(long long r = 0; r < ar.size(); ++r){
		long long vr = ar[r];
		if(st.empty()){
			st.push({vr,r});
			continue;
		}

		long long vl = st.top().first, l = st.top().second;
		if(vl < vr) st.push({vr,r});
		if(vl < vr || vl == vr)	continue;
		
		while(vl > vr) {
			res = max(res,vl*(r - l));
			st.pop();

			if(st.size() && st.top().first > vr) vl = st.top().first, l = st.top().second;
			else break;
		}
		st.push({vr,l});
	}
	ar.pop_back();
	return res;
}


//verify
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/Maximum_Rectangle.cpp"
#include <bits/stdc++.h>
using namespace std;

long long Maximum_Rectangle(vector<long long>& ar){
	ar.push_back(0);
	stack<pair<long long,long long>> st;
	long long res = 0;
	for(long long r = 0; r < ar.size(); ++r){
		long long vr = ar[r];
		if(st.empty()){
			st.push({vr,r});
			continue;
		}

		long long vl = st.top().first, l = st.top().second;
		if(vl < vr) st.push({vr,r});
		if(vl < vr || vl == vr)	continue;
		
		while(vl > vr) {
			res = max(res,vl*(r - l));
			st.pop();

			if(st.size() && st.top().first > vr) vl = st.top().first, l = st.top().second;
			else break;
		}
		st.push({vr,l});
	}
	ar.pop_back();
	return res;
}


//verify

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

