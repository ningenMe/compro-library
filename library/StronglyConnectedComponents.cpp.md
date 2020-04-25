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


# :warning: StronglyConnectedComponents.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/StronglyConnectedComponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-31 00:21:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class StronglyConnectedComponents{
    int nodeNum;
    vector<vector<int>> edge,revEdge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int labelId){
        visited[curr] = 1;
        label[curr] = labelId;
        for(int next:revEdge[curr]) if(!visited[next]) revDfs(next,labelId);
    }

public:

	StronglyConnectedComponents(const int& nodeNum) : 
    nodeNum(nodeNum), edge(nodeNum), revEdge(nodeNum), label(nodeNum), visited(nodeNum) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        revEdge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        for(int i = 0; i < nodeNum; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int labelId = 0;
        for(int i:order) if(!visited[i]) revDfs(i,labelId++);
    }

    void print(void) {
        for(auto labelId:label) cout << labelId << " ";
        cout << endl;
    }

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "StronglyConnectedComponents.cpp"

class StronglyConnectedComponents{
    int nodeNum;
    vector<vector<int>> edge,revEdge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int labelId){
        visited[curr] = 1;
        label[curr] = labelId;
        for(int next:revEdge[curr]) if(!visited[next]) revDfs(next,labelId);
    }

public:

	StronglyConnectedComponents(const int& nodeNum) : 
    nodeNum(nodeNum), edge(nodeNum), revEdge(nodeNum), label(nodeNum), visited(nodeNum) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        revEdge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        for(int i = 0; i < nodeNum; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int labelId = 0;
        for(int i:order) if(!visited[i]) revDfs(i,labelId++);
    }

    void print(void) {
        for(auto labelId:label) cout << labelId << " ";
        cout << endl;
    }

};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

