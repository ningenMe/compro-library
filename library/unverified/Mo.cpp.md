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


# :warning: unverified/Mo.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/Mo.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> class Mo{
    unordered_map<long long,int> mp;
    long long N;
    int bucket;
    vector<pair<int,int>> range;
	vector<int> idx;
public:

    Mo(long long N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N)) {
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int a, int b){
            auto  al = range[a].first/bucket;
            auto  ar = range[a].second;
            auto  bl = range[b].first/bucket;
            auto  br = range[b].second;
            return (al != bl) ? (al < bl) : ((al%2)?(ar > br):(ar < br));
        });
    }
    
    //参照でvectorを渡したりすると良い
    void solve(){
        int l = 0, r = 0;
        for(int& i:idx){
            auto& xl = range[i].first;
            auto& xr = range[i].second;
            
            //左端を広げる
            while(xl < l){
                l--;
                extend(l);
            }
            //右端を広げる
            while(r < xr){
                r++;
                extend(r);
            }
            //左端を狭める
            while(l < xl){
                shrink(l);
                l++;
            }
            //右端を狭める
            while(xr < r){
                shrink(r);
                r--;
            }
            mp[xl*N+xr] = get();
        }
    }

    T operator [] (pair<int,int> p) {
        return mp[p.first*N+p.second];
    }

private:
    
    //伸びるとき
    void extend(int k){
    }

    //縮むとき
    void shrink(int k){
    }

    //クエリ結果
    T get(){
        return;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/Mo.cpp"
template<class T> class Mo{
    unordered_map<long long,int> mp;
    long long N;
    int bucket;
    vector<pair<int,int>> range;
	vector<int> idx;
public:

    Mo(long long N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N)) {
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int a, int b){
            auto  al = range[a].first/bucket;
            auto  ar = range[a].second;
            auto  bl = range[b].first/bucket;
            auto  br = range[b].second;
            return (al != bl) ? (al < bl) : ((al%2)?(ar > br):(ar < br));
        });
    }
    
    //参照でvectorを渡したりすると良い
    void solve(){
        int l = 0, r = 0;
        for(int& i:idx){
            auto& xl = range[i].first;
            auto& xr = range[i].second;
            
            //左端を広げる
            while(xl < l){
                l--;
                extend(l);
            }
            //右端を広げる
            while(r < xr){
                r++;
                extend(r);
            }
            //左端を狭める
            while(l < xl){
                shrink(l);
                l++;
            }
            //右端を狭める
            while(xr < r){
                shrink(r);
                r--;
            }
            mp[xl*N+xr] = get();
        }
    }

    T operator [] (pair<int,int> p) {
        return mp[p.first*N+p.second];
    }

private:
    
    //伸びるとき
    void extend(int k){
    }

    //縮むとき
    void shrink(int k){
    }

    //クエリ結果
    T get(){
        return;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

