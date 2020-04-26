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


# :warning: lib-unverified/BinaryIndexedTree2D.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#155a5098a95a6467136de23a79cf53bd">lib-unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib-unverified/BinaryIndexedTree2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 16:21:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> class BinaryIndexedTree2D {
//抽象化してない　一点加算、区間総和のみ
	const int N,M;
	vector<vector<T>> node;

public:
    //1-indexed
    BinaryIndexedTree2D(const int& N,const int& M):N(N),M(M),node(N+1,vector<T>(M+1,0)){
        // do nothing
    }
 
    inline T getvar(const int i,const int j){
        T res = 0;
        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {
			res += node[y][x];
        }
        return res;
    }
 
    // [x1,x2] * [y1,y2] 1-indexed
    inline T getvar(const int y1,const int y2,const int x1,const int x2){
        T res = 0;
		res += getvar(y1-1,x1-1);
        res -= getvar(y1-1,x2);
        res -= getvar(y2,x1-1);
        res += getvar(y2,x2);
        return res;
    }
 
    //add
    inline void update(const int i,const int j,T val){
        for(int y=i;y&&y<=N;y+=(y&-y)) for(int x=j;x&&x<=M;x+=(x&-x)) {
            node[y][x]+=val;
        }
    } 
};

//verify https://atcoder.jp/contests/abc130/tasks/abc130_e

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib-unverified/BinaryIndexedTree2D.cpp"
template<class T> class BinaryIndexedTree2D {
//抽象化してない　一点加算、区間総和のみ
	const int N,M;
	vector<vector<T>> node;

public:
    //1-indexed
    BinaryIndexedTree2D(const int& N,const int& M):N(N),M(M),node(N+1,vector<T>(M+1,0)){
        // do nothing
    }
 
    inline T getvar(const int i,const int j){
        T res = 0;
        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {
			res += node[y][x];
        }
        return res;
    }
 
    // [x1,x2] * [y1,y2] 1-indexed
    inline T getvar(const int y1,const int y2,const int x1,const int x2){
        T res = 0;
		res += getvar(y1-1,x1-1);
        res -= getvar(y1-1,x2);
        res -= getvar(y2,x1-1);
        res += getvar(y2,x2);
        return res;
    }
 
    //add
    inline void update(const int i,const int j,T val){
        for(int y=i;y&&y<=N;y+=(y&-y)) for(int x=j;x&&x<=M;x+=(x&-x)) {
            node[y][x]+=val;
        }
    } 
};

//verify https://atcoder.jp/contests/abc130/tasks/abc130_e

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

