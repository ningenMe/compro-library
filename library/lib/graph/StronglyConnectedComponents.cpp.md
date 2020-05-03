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


# :x: lib/graph/StronglyConnectedComponents.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/StronglyConnectedComponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 01:17:23+09:00




## Verified with

* :x: <a href="../../../verify/test/graph/StronglyConnectedComponents.test.cpp.html">test/graph/StronglyConnectedComponents.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class StronglyConnectedComponents{
    int num;
    vector<vector<int>> edge,redge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int label_id){
        visited[curr] = 1;
        label[curr] = label_id;
        for(int next:redge[curr]) if(!visited[next]) revDfs(next,label_id);
    }

public:

	StronglyConnectedComponents(const int& num) : 
    num(num), edge(num), redge(num), label(num), visited(num) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        redge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < num; ++i) visited[i] = 0;
        for(int i = 0; i < num; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < num; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int label_id = 0;
        for(int i:order) if(!visited[i]) revDfs(i,label_id++);
    }

    void print(void) {
        for(auto label_id:label) cout << label_id << " ";
        cout << endl;
    }

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/StronglyConnectedComponents.cpp"

class StronglyConnectedComponents{
    int num;
    vector<vector<int>> edge,redge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int label_id){
        visited[curr] = 1;
        label[curr] = label_id;
        for(int next:redge[curr]) if(!visited[next]) revDfs(next,label_id);
    }

public:

	StronglyConnectedComponents(const int& num) : 
    num(num), edge(num), redge(num), label(num), visited(num) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        redge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < num; ++i) visited[i] = 0;
        for(int i = 0; i < num; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < num; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int label_id = 0;
        for(int i:order) if(!visited[i]) revDfs(i,label_id++);
    }

    void print(void) {
        for(auto label_id:label) cout << label_id << " ";
        cout << endl;
    }

};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

