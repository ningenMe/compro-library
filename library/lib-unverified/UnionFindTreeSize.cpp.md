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


# :warning: lib-unverified/UnionFindTreeSize.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/UnionFindTreeSize.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

//Union Find Tree
class UnionFindTreeSize {
public:
	vector<int> parent;
    vector<int> maxidx;
    vector<int> minidx;

    UnionFindTreeSize(int N = 1) : parent(N,-1),maxidx(N),minidx(N){
        iota(maxidx.begin(),maxidx.end(),0);
        iota(minidx.begin(),minidx.end(),0);
	}
 
	int root(int n) {
        return (parent[n]<0?n:parent[n] = root(parent[n]));
	}

    bool same(int n, int m) {
		return root(n) == root(m);
	}

    int mini(int n) {
        return minidx[root(n)];
    }

    int maxi(int n) {
        return maxidx[root(n)];
    }
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
        maxidx[n] = max(maxidx[n],maxidx[m]);
        minidx[n] = min(minidx[n],minidx[m]);
	}

    int size(int n){
        return (-parent[root(n)]);
    }

    void print() {
        for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
        cout << endl;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/UnionFindTreeSize.cpp"

//Union Find Tree
class UnionFindTreeSize {
public:
	vector<int> parent;
    vector<int> maxidx;
    vector<int> minidx;

    UnionFindTreeSize(int N = 1) : parent(N,-1),maxidx(N),minidx(N){
        iota(maxidx.begin(),maxidx.end(),0);
        iota(minidx.begin(),minidx.end(),0);
	}
 
	int root(int n) {
        return (parent[n]<0?n:parent[n] = root(parent[n]));
	}

    bool same(int n, int m) {
		return root(n) == root(m);
	}

    int mini(int n) {
        return minidx[root(n)];
    }

    int maxi(int n) {
        return maxidx[root(n)];
    }
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
        maxidx[n] = max(maxidx[n],maxidx[m]);
        minidx[n] = min(minidx[n],minidx[m]);
	}

    int size(int n){
        return (-parent[root(n)]);
    }

    void print() {
        for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
        cout << endl;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

