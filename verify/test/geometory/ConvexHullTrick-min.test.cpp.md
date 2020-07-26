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


# :x: test/geometory/ConvexHullTrick-min.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1559848aad74dc56829252d458066b03">test/geometory</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/geometory/ConvexHullTrick-min.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "../../lib/segment/rbst.cpp"
#include "../../lib/geometory/ConvexHullTrick.cpp"
using ll = long long;

int main(void){
	ll N,A,B,W; cin >> N >> A >> B >> W;
	vector<ll> D(N+2,0);
	for(int i = 1; i <= N; ++i) cin >> D[i];
	// dp[i]=min{j:[0,i)}-> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)
	//                   -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]
	//                   -> dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]
	//                   -> (-B*j)*i  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] 
	ll dp=W;
	ConvexHullTrick<ValueMin<ll>> cht;
	cht.insert(0,dp);
	for(ll i=1;i<=N+1;++i){
		dp=cht.get(i)+B*(i*i-i)/2-A*(i-1)+D[i];
		pair<ll,ll> line={-B*i,dp+B*(i*i+i)/2+A*i};
		cht.insert(line);
	}
	cout << dp << endl;
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../lib/segment/rbst.cpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

