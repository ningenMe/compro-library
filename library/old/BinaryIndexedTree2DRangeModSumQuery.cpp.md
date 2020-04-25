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


# :warning: old/BinaryIndexedTree2DRangeModSumQuery.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#149603e6c03516362a8da23f624db945">old</a>
* <a href="{{ site.github.repository_url }}/blob/master/old/BinaryIndexedTree2DRangeModSumQuery.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-09 00:46:04+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class BinaryIndexedTree2DRangeModSumQuery{
public:
    const int N,M;
    const long long mod;
    vector<vector<long long>> bit;
 
    //1-indexed
    BinaryIndexedTree2DRangeModSumQuery(const int& N,const int& M, const long long& mod):N(N),M(M),mod(mod),bit(N+1,vector<long long>(M+1,0)){
        // do nothing
    }
 
    inline long long getvar(const int& i,const int& j){
        long long val = 0;
        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {
            val += bit[y][x];
            if(val >= mod) val -= mod;
        }
        return val;
    }
 
    // [x1,x2] * [y1,y2] 1-indexed
    inline long long getvar(const int& y1,const int& y2,const int& x1,const int& x2){
        long long res = getvar(y1-1,x1-1);
        res -= getvar(y1-1,x2);
        if(res < 0) res += mod;
        res -= getvar(y2,x1-1);
        if(res < 0) res += mod;
        res += getvar(y2,x2);
        if(res >= mod) res -= mod;
        return res;
    }
 
    //add
    inline void update(const int& i,const int& j,long long val){
        if(i==0||j==0) return;
        if(val>=mod) val -= mod;
        if(val < 0) val += mod;
        for(int y=i;y<=N;y+=(y&-y)) for(int x=j;x<=M;x+=(x&-x)) {
            bit[y][x]+=val;
            if(bit[y][x] >= mod) bit[y][x] -= mod;
        }
    }
 
};

//verify https://atcoder.jp/contests/abc130/tasks/abc130_e
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "old/BinaryIndexedTree2DRangeModSumQuery.cpp"
class BinaryIndexedTree2DRangeModSumQuery{
public:
    const int N,M;
    const long long mod;
    vector<vector<long long>> bit;
 
    //1-indexed
    BinaryIndexedTree2DRangeModSumQuery(const int& N,const int& M, const long long& mod):N(N),M(M),mod(mod),bit(N+1,vector<long long>(M+1,0)){
        // do nothing
    }
 
    inline long long getvar(const int& i,const int& j){
        long long val = 0;
        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {
            val += bit[y][x];
            if(val >= mod) val -= mod;
        }
        return val;
    }
 
    // [x1,x2] * [y1,y2] 1-indexed
    inline long long getvar(const int& y1,const int& y2,const int& x1,const int& x2){
        long long res = getvar(y1-1,x1-1);
        res -= getvar(y1-1,x2);
        if(res < 0) res += mod;
        res -= getvar(y2,x1-1);
        if(res < 0) res += mod;
        res += getvar(y2,x2);
        if(res >= mod) res -= mod;
        return res;
    }
 
    //add
    inline void update(const int& i,const int& j,long long val){
        if(i==0||j==0) return;
        if(val>=mod) val -= mod;
        if(val < 0) val += mod;
        for(int y=i;y<=N;y+=(y&-y)) for(int x=j;x<=M;x+=(x&-x)) {
            bit[y][x]+=val;
            if(bit[y][x] >= mod) bit[y][x] -= mod;
        }
    }
 
};

//verify https://atcoder.jp/contests/abc130/tasks/abc130_e

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

