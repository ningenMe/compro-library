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


# :warning: Median.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Median.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-09 17:35:21+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template<class T> class Median{
	multiset<T, greater<>> stl;
	multiset<T> str;
    T init;

    // 要素の均衡を保つ関数
    inline void balance() {
        while(stl.size() < str.size()) {
            stl.insert(*str.begin());
            str.erase(str.begin());
        }
        while(stl.size() > str.size()+1) {
            str.insert(*stl.begin());
            stl.erase(stl.begin());
        }

        if(!str.size()) return;

        for(T tmpl = *stl.begin(),tmpr = *str.begin(); tmpl>tmpr; tmpl = *stl.begin(), tmpr = *str.begin()) {
            stl.erase(stl.begin());
            str.erase(str.begin());
            stl.insert(tmpr);
            str.insert(tmpl);
        }
    }
public:
    Median(T init):init(init){
        //do nothing
    }

    void insert(T val){
        stl.insert(val);
        balance();
    }

    int find(T val){
        return (stl.find(val)!=stl.end() || str.find(val)!=str.end());
    }

    void eraseItr(T val){
        auto itr = stl.find(val);
        if(itr != stl.end()) {
            stl.erase(itr);
            balance();
            return;
        }
        itr = str.find(val);
        if(itr != str.end()) {
            str.erase(itr);
            balance();
            return;
        }
    }

    void eraseVal(T val){
        stl.erase(val);
        str.erase(val);
        balance();
    }

    T get(){
        return (stl.empty()?init:*stl.begin());
    }

    size_t size(){
        return stl.size()+str.size();
    }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Median.cpp"

template<class T> class Median{
	multiset<T, greater<>> stl;
	multiset<T> str;
    T init;

    // 要素の均衡を保つ関数
    inline void balance() {
        while(stl.size() < str.size()) {
            stl.insert(*str.begin());
            str.erase(str.begin());
        }
        while(stl.size() > str.size()+1) {
            str.insert(*stl.begin());
            stl.erase(stl.begin());
        }

        if(!str.size()) return;

        for(T tmpl = *stl.begin(),tmpr = *str.begin(); tmpl>tmpr; tmpl = *stl.begin(), tmpr = *str.begin()) {
            stl.erase(stl.begin());
            str.erase(str.begin());
            stl.insert(tmpr);
            str.insert(tmpl);
        }
    }
public:
    Median(T init):init(init){
        //do nothing
    }

    void insert(T val){
        stl.insert(val);
        balance();
    }

    int find(T val){
        return (stl.find(val)!=stl.end() || str.find(val)!=str.end());
    }

    void eraseItr(T val){
        auto itr = stl.find(val);
        if(itr != stl.end()) {
            stl.erase(itr);
            balance();
            return;
        }
        itr = str.find(val);
        if(itr != str.end()) {
            str.erase(itr);
            balance();
            return;
        }
    }

    void eraseVal(T val){
        stl.erase(val);
        str.erase(val);
        balance();
    }

    T get(){
        return (stl.empty()?init:*stl.begin());
    }

    size_t size(){
        return stl.size()+str.size();
    }
};


```
{% endraw %}

<a href="../index.html">Back to top page</a>

