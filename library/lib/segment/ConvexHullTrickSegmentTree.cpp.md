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


# :warning: ConvexHullTrickSegmentTree

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c993b235c21a7035904945a028efa0ef">lib/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/segment/ConvexHullTrickSegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:41:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
 * @title ConvexHullTrickSegmentTree
 */
template<class Operator> class ConvexHullTrickSegmentTree {
	using TypeValue = typename Operator::TypeValue;
	using TypeNode = pair<TypeValue,TypeValue>;
	size_t length;
	size_t num;
	vector<ConvexHullTrick<Operator>> node;
public:
	inline constexpr TypeValue y(const TypeNode p, TypeValue x) {
		return p.first*x+p.second;
	}
	ConvexHullTrickSegmentTree(const size_t num): num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length);
	}
	//[idx,idx+1) insert{ax+b}
	void update(size_t idx, const TypeValue a, const TypeValue b) {
		if(idx < 0 || length <= idx) return;
		for(idx+=length;idx;idx >>= 1) node[idx].insert(a,b);
	}
	//[l,r)
	TypeValue get(int l, int r, TypeValue x) {
		if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;
		TypeValue vl =  Operator::unit_value, vr = Operator::unit_value;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) {
				auto tl=node[l++].get(x);                
				vl = (Operator::func_compare(vl,tl)?vl:tl);
			}
			if(r&1) {
				auto tr=node[--r].get(x);                
				vr = (Operator::func_compare(tr,vr)?tr:vr);
			}
		}
		return (Operator::func_compare(vl,vr)?vl:vr);
	}
	//[l,r)
	TypeNode get_line(int l, int r, TypeValue x) {
		if (l < 0 || length <= l || r < 0 || length < r) return {0,Operator::unit_value};
		TypeNode vl = {0,Operator::unit_value}, vr = {0,Operator::unit_value};
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) {
				auto tl=node[l++].get_line(x);                
				vl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);
			}
			if(r&1) {
				auto tr=node[--r].get_line(x);                
				vr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);
			}
		}
		return (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);
	}
	void print(){
		cout << "node" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			node[i].print();
			if(i==((1<<j)-1) && ++j) cout << endl;
		}    
	}
};
//https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/segment/ConvexHullTrickSegmentTree.cpp"
/*
 * @title ConvexHullTrickSegmentTree
 */
template<class Operator> class ConvexHullTrickSegmentTree {
	using TypeValue = typename Operator::TypeValue;
	using TypeNode = pair<TypeValue,TypeValue>;
	size_t length;
	size_t num;
	vector<ConvexHullTrick<Operator>> node;
public:
	inline constexpr TypeValue y(const TypeNode p, TypeValue x) {
		return p.first*x+p.second;
	}
	ConvexHullTrickSegmentTree(const size_t num): num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length);
	}
	//[idx,idx+1) insert{ax+b}
	void update(size_t idx, const TypeValue a, const TypeValue b) {
		if(idx < 0 || length <= idx) return;
		for(idx+=length;idx;idx >>= 1) node[idx].insert(a,b);
	}
	//[l,r)
	TypeValue get(int l, int r, TypeValue x) {
		if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;
		TypeValue vl =  Operator::unit_value, vr = Operator::unit_value;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) {
				auto tl=node[l++].get(x);                
				vl = (Operator::func_compare(vl,tl)?vl:tl);
			}
			if(r&1) {
				auto tr=node[--r].get(x);                
				vr = (Operator::func_compare(tr,vr)?tr:vr);
			}
		}
		return (Operator::func_compare(vl,vr)?vl:vr);
	}
	//[l,r)
	TypeNode get_line(int l, int r, TypeValue x) {
		if (l < 0 || length <= l || r < 0 || length < r) return {0,Operator::unit_value};
		TypeNode vl = {0,Operator::unit_value}, vr = {0,Operator::unit_value};
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) {
				auto tl=node[l++].get_line(x);                
				vl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);
			}
			if(r&1) {
				auto tr=node[--r].get_line(x);                
				vr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);
			}
		}
		return (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);
	}
	void print(){
		cout << "node" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			node[i].print();
			if(i==((1<<j)-1) && ++j) cout << endl;
		}    
	}
};
//https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

