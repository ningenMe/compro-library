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


# :heavy_check_mark: test/util/RangeIndex.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b474f495c8582ac5f92778a42ae814fa">test/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/util/RangeIndex.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 04:04:43+09:00


* see: <a href="https://yukicoder.me/problems/no/1170">https://yukicoder.me/problems/no/1170</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/graph/UnionFindTree.cpp.html">UnionFindTree</a>
* :heavy_check_mark: <a href="../../../library/lib/util/RangeIndex.cpp.html">RangeIndex</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1170"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
using namespace std;
#include "../../lib/util/RangeIndex.cpp"
#include "../../lib/graph/UnionFindTree.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    long long N,A,B; cin >> N >> A >> B;
    vector<long long> X(N);
    for(int i = 0; i < N; ++i) cin >> X[i];
    X.push_back(1e10);
    RangeIndex ri(N);
    UnionFindTree uf(2*ri.size());
    vector<int> st(2*ri.size(),0);
    for(int i = 0; i < N; ++i) {
        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();
        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();
        for(auto& e:ri.range(l,r)) {
            st[e]=1;
            uf.merge(ri[i],e);
        }
    }
    for(int i = 0; i < N; ++i) {
        int j=i+ri.size();
        while(j >>= 1) if(st[j]) uf.merge(ri[i],j);
    }
    vector<int> cnt(2*ri.size(),0);
    for(int i = 0; i < N; ++i) {
        cnt[uf[ri[i]]]++;
    }
    for(int i = 0; i < N; ++i) {
        cout << cnt[uf[ri[i]]] << endl;
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/util/RangeIndex.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1170"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
using namespace std;
#line 1 "lib/util/RangeIndex.cpp"
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
    inline int operator[](int idx) {
		return idx+length;
	}
    inline size_t size(void){
        return length;
    }
};
#line 1 "lib/graph/UnionFindTree.cpp"
/*
 * @title UnionFindTree
 */
class UnionFindTree {
	vector<int> parent,maxi,mini;
	inline int root(int n) {
        return (parent[n]<0?n:parent[n] = root(parent[n]));
	}
public:
    UnionFindTree(int N = 1) : parent(N,-1),maxi(N),mini(N){
        iota(maxi.begin(),maxi.end(),0);
        iota(mini.begin(),mini.end(),0);
	}
    inline bool connected(int n, int m) {
		return root(n) == root(m);
	}
	inline void merge(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
        maxi[n] = std::max(maxi[n],maxi[m]);
        mini[n] = std::min(mini[n],mini[m]);
	}
    inline int min(int n) {
        return mini[root(n)];
    }
    inline int max(int n) {
        return maxi[root(n)];
    }
    inline int size(int n){
        return (-parent[root(n)]);
    }
    inline int operator[](int n) {
		return root(n);
	}
    inline void print() {
        for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
        cout << endl;
    }
};
#line 11 "test/util/RangeIndex.test.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    long long N,A,B; cin >> N >> A >> B;
    vector<long long> X(N);
    for(int i = 0; i < N; ++i) cin >> X[i];
    X.push_back(1e10);
    RangeIndex ri(N);
    UnionFindTree uf(2*ri.size());
    vector<int> st(2*ri.size(),0);
    for(int i = 0; i < N; ++i) {
        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();
        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();
        for(auto& e:ri.range(l,r)) {
            st[e]=1;
            uf.merge(ri[i],e);
        }
    }
    for(int i = 0; i < N; ++i) {
        int j=i+ri.size();
        while(j >>= 1) if(st[j]) uf.merge(ri[i],j);
    }
    vector<int> cnt(2*ri.size(),0);
    for(int i = 0; i < N; ++i) {
        cnt[uf[ri[i]]]++;
    }
    for(int i = 0; i < N; ++i) {
        cout << cnt[uf[ri[i]]] << endl;
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

