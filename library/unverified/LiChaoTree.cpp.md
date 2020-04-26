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


# :warning: unverified/LiChaoTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/LiChaoTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class Operator> class LiChaoTree{
	Operator Op;                                         //Operator 演算子、型、単位元を持つ
	using typeValue = decltype(Op.unitValue);            //valueの型
	struct domain{typeValue l,c,r;};
	size_t length;
	typeValue yInf;
	vector<typeValue> x;
	vector<pair<typeValue,typeValue>> node;
	vector<domain> range;

public:
	//取りうるxの値を先読みして渡す
	LiChaoTree(vector<typeValue> argx) {
		sort(argx.begin(),argx.end());
		argx.erase(unique(argx.begin(),argx.end()),argx.end());
		typeValue maxi = argx.back() + 1;
		for (length = 1; length < argx.size(); length *= 2);
		x.resize(length + 1, maxi);
		node.resize(2 * length, {0,Op.unitValue});
		range.resize(2 * length,  {maxi,maxi,maxi});
		for (int i = 0; i < argx.size(); ++i) x[i] = argx[i];
		for (int i = 0; i < argx.size(); ++i) range[i + length] = {x[i],-1,x[i+1]};
		for (int i = length-1; 1 <= i; --i) range[i] = {range[(i<<1)+0].l,range[(i<<1)+0].r,range[(i<<1)+1].r};
	}

	//return y = ax+b
	inline typeValue f(pair<typeValue,typeValue>& line,typeValue& t)	{
		return line.first*t + line.second;
	}

	//直線追加　ax + b  O(logN)
	void update(pair<typeValue,typeValue> line,int i = 1) {
		while(i < 2*length){
			typeValue& xl = range[i].l;
			typeValue& xc = range[i].c;
			typeValue& xr = range[i].r;
			int flgl = Op.funcCompare(f(line,xl),f(node[i],xl));
			int flgc = Op.funcCompare(f(line,xc),f(node[i],xc));
			int flgr = Op.funcCompare(f(line,xr),f(node[i],xr));
			if(flgl && flgr) node[i] = line;
			if(flgl == flgr) break;
			if((flgl && flgc) || (flgc && flgr)) swap(node[i],line);
			if((flgl &&!flgc) || (flgc && flgr)) i = (i<<1)+0;
			if((flgl && flgc) || (!flgc&& flgr)) i = (i<<1)+1;
		}
	}

	//線分追加　y = ax + b [l,r) O((logN)^2)
	void update(pair<typeValue,typeValue> line, typeValue L, typeValue R) {
		int l = (lower_bound(x.begin(),x.end(),L) - x.begin()) + length;
		int r = (lower_bound(x.begin(),x.end(),R) - x.begin()) + length - 1;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) update(line,l),l++;
			if(r&1) --r,update(line,r);
		}
	}

	//値を取得 t is in {x}
	typeValue get(typeValue t) {
		int i = (lower_bound(x.begin(),x.end(),t) - x.begin()) + length;
		typeValue res = Op.unitValue;
		for(;1<=i;i>>=1) if(Op.funcCompare(f(node[i],t),res)) res = f(node[i],t);
		return res; 
	}

	void print(){
		// cout << "{ " << get(0,1);
		// for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		// cout << " }" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << "{" << range[i].l << ", " << range[i].c << ", " << range[i].r << "}" << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
	}
};

//最小値クエリ
template<class typeValue> struct valueMin {
	typeValue unitValue = 3e18;
	bool funcCompare(typeValue l,typeValue r){return l<r;}
};

// verify https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
// verify https://atcoder.jp/contests/code-festival-2018-final-open/tasks/code_festival_2018_final_c


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/LiChaoTree.cpp"
template<class Operator> class LiChaoTree{
	Operator Op;                                         //Operator 演算子、型、単位元を持つ
	using typeValue = decltype(Op.unitValue);            //valueの型
	struct domain{typeValue l,c,r;};
	size_t length;
	typeValue yInf;
	vector<typeValue> x;
	vector<pair<typeValue,typeValue>> node;
	vector<domain> range;

public:
	//取りうるxの値を先読みして渡す
	LiChaoTree(vector<typeValue> argx) {
		sort(argx.begin(),argx.end());
		argx.erase(unique(argx.begin(),argx.end()),argx.end());
		typeValue maxi = argx.back() + 1;
		for (length = 1; length < argx.size(); length *= 2);
		x.resize(length + 1, maxi);
		node.resize(2 * length, {0,Op.unitValue});
		range.resize(2 * length,  {maxi,maxi,maxi});
		for (int i = 0; i < argx.size(); ++i) x[i] = argx[i];
		for (int i = 0; i < argx.size(); ++i) range[i + length] = {x[i],-1,x[i+1]};
		for (int i = length-1; 1 <= i; --i) range[i] = {range[(i<<1)+0].l,range[(i<<1)+0].r,range[(i<<1)+1].r};
	}

	//return y = ax+b
	inline typeValue f(pair<typeValue,typeValue>& line,typeValue& t)	{
		return line.first*t + line.second;
	}

	//直線追加　ax + b  O(logN)
	void update(pair<typeValue,typeValue> line,int i = 1) {
		while(i < 2*length){
			typeValue& xl = range[i].l;
			typeValue& xc = range[i].c;
			typeValue& xr = range[i].r;
			int flgl = Op.funcCompare(f(line,xl),f(node[i],xl));
			int flgc = Op.funcCompare(f(line,xc),f(node[i],xc));
			int flgr = Op.funcCompare(f(line,xr),f(node[i],xr));
			if(flgl && flgr) node[i] = line;
			if(flgl == flgr) break;
			if((flgl && flgc) || (flgc && flgr)) swap(node[i],line);
			if((flgl &&!flgc) || (flgc && flgr)) i = (i<<1)+0;
			if((flgl && flgc) || (!flgc&& flgr)) i = (i<<1)+1;
		}
	}

	//線分追加　y = ax + b [l,r) O((logN)^2)
	void update(pair<typeValue,typeValue> line, typeValue L, typeValue R) {
		int l = (lower_bound(x.begin(),x.end(),L) - x.begin()) + length;
		int r = (lower_bound(x.begin(),x.end(),R) - x.begin()) + length - 1;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) update(line,l),l++;
			if(r&1) --r,update(line,r);
		}
	}

	//値を取得 t is in {x}
	typeValue get(typeValue t) {
		int i = (lower_bound(x.begin(),x.end(),t) - x.begin()) + length;
		typeValue res = Op.unitValue;
		for(;1<=i;i>>=1) if(Op.funcCompare(f(node[i],t),res)) res = f(node[i],t);
		return res; 
	}

	void print(){
		// cout << "{ " << get(0,1);
		// for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		// cout << " }" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << "{" << range[i].l << ", " << range[i].c << ", " << range[i].r << "}" << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
	}
};

//最小値クエリ
template<class typeValue> struct valueMin {
	typeValue unitValue = 3e18;
	bool funcCompare(typeValue l,typeValue r){return l<r;}
};

// verify https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
// verify https://atcoder.jp/contests/code-festival-2018-final-open/tasks/code_festival_2018_final_c


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

