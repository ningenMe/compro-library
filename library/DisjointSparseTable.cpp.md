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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: DisjointSparseTable.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/DisjointSparseTable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-12 12:36:43+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class Operator> class DisjointSparseTable{
public:
	Operator Op;                           
	using typeNode = decltype(Op.unitNode);
	size_t depth;
	size_t length;
	vector<vector<typeNode>> node;
	vector<size_t> msb;

	DisjointSparseTable(const vector<typeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		
		//msb
		msb.resize(length,0);
		for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;

		//init value
		node.resize(depth,vector<typeNode>(length,Op.unitNode));
		for(int i = 0; i < vec.size(); ++i) node[0][i] = vec[i];

		for(int i = 1; i < depth; ++i) {
			for(int r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){
				//init accumulate
				node[i][l] = node[0][l];
				node[i][r] = node[0][r];
				//accumulate
				for(int k = 1; k < (1<<i); ++k) {
					node[i][l-k] = Op.funcNode(node[i][l-k+1],node[0][l-k]);
					node[i][r+k] = Op.funcNode(node[i][r+k-1],node[0][r+k]);
				}
			}
		}
	}

	//[l,r)
	typeNode get(int l,int r) {
		r--;
		return (l>r||l<0||length<=r) ? Op.unitNode: (l==r ? node[0][l] : Op.funcNode(node[msb[l^r]][l],node[msb[l^r]][r]));
	}
};

//区間GCD
template<class typeNode> struct nodeGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
};

//区間最大
template<class typeNode> struct nodeMax {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
};

//区間最小
template<class typeNode> struct nodeMin {
	typeNode unitNode = LOWINF;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DisjointSparseTable.cpp"
template<class Operator> class DisjointSparseTable{
public:
	Operator Op;                           
	using typeNode = decltype(Op.unitNode);
	size_t depth;
	size_t length;
	vector<vector<typeNode>> node;
	vector<size_t> msb;

	DisjointSparseTable(const vector<typeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		
		//msb
		msb.resize(length,0);
		for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;

		//init value
		node.resize(depth,vector<typeNode>(length,Op.unitNode));
		for(int i = 0; i < vec.size(); ++i) node[0][i] = vec[i];

		for(int i = 1; i < depth; ++i) {
			for(int r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){
				//init accumulate
				node[i][l] = node[0][l];
				node[i][r] = node[0][r];
				//accumulate
				for(int k = 1; k < (1<<i); ++k) {
					node[i][l-k] = Op.funcNode(node[i][l-k+1],node[0][l-k]);
					node[i][r+k] = Op.funcNode(node[i][r+k-1],node[0][r+k]);
				}
			}
		}
	}

	//[l,r)
	typeNode get(int l,int r) {
		r--;
		return (l>r||l<0||length<=r) ? Op.unitNode: (l==r ? node[0][l] : Op.funcNode(node[msb[l^r]][l],node[msb[l^r]][r]));
	}
};

//区間GCD
template<class typeNode> struct nodeGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
};

//区間最大
template<class typeNode> struct nodeMax {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
};

//区間最小
template<class typeNode> struct nodeMin {
	typeNode unitNode = LOWINF;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
};


```
{% endraw %}

<a href="../index.html">Back to top page</a>

