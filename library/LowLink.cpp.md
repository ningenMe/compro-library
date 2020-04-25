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


# :warning: LowLink.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/LowLink.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-23 20:24:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class LowLink{
private:
    int N,inc;
    vector<int> ord,low;
public:
    vector<vector<int>> edge;
    vector<int> articulation;
    vector<pair<int,int>> bridge;

    LowLink(int N) : N(N),edge(N),ord(N,-1),low(N,0) {
        // do nothing
    }
    void make_edge(int from, int to) {
		edge[from].push_back(to);
	}
    void solve() {
        inc = 0;
        for(int i = 0; i < N; ++i) if(ord[i]==-1) dfs(i,-1);
    }
private:
    void dfs(int curr,int prev) {
        ord[curr] = inc++;
        low[curr] = ord[curr];
        int isArticulation = 0;
        int cnt = 0;
        for(int next:edge[curr]) {
            if(next == prev) continue;
            if(ord[next]==-1){
                cnt++;
                dfs(next,curr);
                low[curr] = min(low[curr],low[next]);
                if(prev != -1 && low[next] >= ord[curr]) isArticulation = 1;
                if(ord[curr]<low[next]) {
                    bridge.push_back({curr,next});
                    bridge.push_back({next,curr});
                }
            }
            else{
                low[curr] = min(low[curr],ord[next]);
            }
        }
        if(prev==-1 && cnt>1) isArticulation = 1;
        if(isArticulation) articulation.push_back(curr);
    }
};

//verify https://atcoder.jp/contests/arc039/tasks/arc039_d

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "LowLink.cpp"

class LowLink{
private:
    int N,inc;
    vector<int> ord,low;
public:
    vector<vector<int>> edge;
    vector<int> articulation;
    vector<pair<int,int>> bridge;

    LowLink(int N) : N(N),edge(N),ord(N,-1),low(N,0) {
        // do nothing
    }
    void make_edge(int from, int to) {
		edge[from].push_back(to);
	}
    void solve() {
        inc = 0;
        for(int i = 0; i < N; ++i) if(ord[i]==-1) dfs(i,-1);
    }
private:
    void dfs(int curr,int prev) {
        ord[curr] = inc++;
        low[curr] = ord[curr];
        int isArticulation = 0;
        int cnt = 0;
        for(int next:edge[curr]) {
            if(next == prev) continue;
            if(ord[next]==-1){
                cnt++;
                dfs(next,curr);
                low[curr] = min(low[curr],low[next]);
                if(prev != -1 && low[next] >= ord[curr]) isArticulation = 1;
                if(ord[curr]<low[next]) {
                    bridge.push_back({curr,next});
                    bridge.push_back({next,curr});
                }
            }
            else{
                low[curr] = min(low[curr],ord[next]);
            }
        }
        if(prev==-1 && cnt>1) isArticulation = 1;
        if(isArticulation) articulation.push_back(curr);
    }
};

//verify https://atcoder.jp/contests/arc039/tasks/arc039_d

```
{% endraw %}

<a href="../index.html">Back to top page</a>

