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


# :warning: lib-unverified/SparseTable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/SparseTable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template<class Operator> class SparseTable{
public:
	Operator Op;                           
	using typeNode = decltype(Op.unitNode);
	vector<typeNode> node;
	vector<int> idx;
	size_t depth;
	size_t length;

	SparseTable(const vector<typeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		node.resize(depth*length);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];
		for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Op.funcNode(node[(i-1)*length+j],node[(i-1)*length+j + (1 << (i-1))]);
		idx.resize(vec.size()+1);
		for(int i = 2; i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;
	}

	//[l,r)
	typeNode get(int l,int r) {
		int bit = idx[r-l];
		return Op.funcNode(node[bit*length+l],node[bit*length+r - (1<<bit)]);
	}
};

template<class typeNode> struct nodeGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return r?funcNode(r,l%r):l;}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/SparseTable.cpp"

template<class Operator> class SparseTable{
public:
	Operator Op;                           
	using typeNode = decltype(Op.unitNode);
	vector<typeNode> node;
	vector<int> idx;
	size_t depth;
	size_t length;

	SparseTable(const vector<typeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		node.resize(depth*length);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];
		for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Op.funcNode(node[(i-1)*length+j],node[(i-1)*length+j + (1 << (i-1))]);
		idx.resize(vec.size()+1);
		for(int i = 2; i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;
	}

	//[l,r)
	typeNode get(int l,int r) {
		int bit = idx[r-l];
		return Op.funcNode(node[bit*length+l],node[bit*length+r - (1<<bit)]);
	}
};

template<class typeNode> struct nodeGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return r?funcNode(r,l%r):l;}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

