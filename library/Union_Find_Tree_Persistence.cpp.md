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


# :warning: Union_Find_Tree_Persistence.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Union_Find_Tree_Persistence.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-21 05:25:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

class  Union_Find_Tree_Persistence{
public:
    vector<map<int,int>> parent;
    vector<int> rank,last;
    int cnt = 0;

    Union_Find_Tree_Persistence(int N):parent(N),rank(N,1),last(N,0){
        for(int i = 0; i < N; ++i) parent[i][0] = i;
    }

    //O(logN)
    int root(int n, int t) {
        return ( (t >= last[n] && parent[n][last[n]] != n) ? root(parent[n][last[n]], t) : n);
    }
 
    //O(logN)
    void unite(int n, int m) {
        n = root(n, cnt);
        m = root(m, cnt);
        cnt++;
        if(n == m) return;
        
        if(rank[n] < rank[m]) {
            parent[n][cnt] = m;
            last[n] = cnt;
        }
        else {
        parent[m][cnt] = n;
        last[m] = cnt;
        if(rank[n] == rank[m]) rank[n]++;
        }
    }
 
    bool same(int n, int m, int t) { 
        return root(n, t) == root(m, t);
    }
};

//verify https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Union_Find_Tree_Persistence.cpp"
#include <bits/stdc++.h>
using namespace std;

class  Union_Find_Tree_Persistence{
public:
    vector<map<int,int>> parent;
    vector<int> rank,last;
    int cnt = 0;

    Union_Find_Tree_Persistence(int N):parent(N),rank(N,1),last(N,0){
        for(int i = 0; i < N; ++i) parent[i][0] = i;
    }

    //O(logN)
    int root(int n, int t) {
        return ( (t >= last[n] && parent[n][last[n]] != n) ? root(parent[n][last[n]], t) : n);
    }
 
    //O(logN)
    void unite(int n, int m) {
        n = root(n, cnt);
        m = root(m, cnt);
        cnt++;
        if(n == m) return;
        
        if(rank[n] < rank[m]) {
            parent[n][cnt] = m;
            last[n] = cnt;
        }
        else {
        parent[m][cnt] = n;
        last[m] = cnt;
        if(rank[n] == rank[m]) rank[n]++;
        }
    }
 
    bool same(int n, int m, int t) { 
        return root(n, t) == root(m, t);
    }
};

//verify https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h

```
{% endraw %}

<a href="../index.html">Back to top page</a>

