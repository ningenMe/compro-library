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


# :warning: ConvexHullTrick.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/ConvexHullTrick.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-05 15:57:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template<class T> class ConvexHullTrick {
private:
    deque<pair<T,T>> lines;
	function<int(T,T)> funcCompare;

	//cが必要かどうか判定する
    inline int isRequired(const pair<T,T>& l, const pair<T,T>& c, const pair<T,T>& r) {
        return (c.first - l.first) * (r.second - c.second) >= (c.second - l.second) * (r.first - c.first);
    }
    
	//k番目のax+bの値
    inline T value(int k, T x) {
        return lines[k].first * x + lines[k].second;
    }

public:
	ConvexHullTrick(function<int(T,T)> funcCompare) : funcCompare(funcCompare) {
		// do nothing
	} 

	//傾きの大きさが単調な順にax+bを追加
	void insert(T a, T b) {
		//insertの必要がないとき
        if(lines.size() && lines.back().first == a && lines.back().second <= b) return;
		// 直前の直線の傾きが同じ　かつ　それが必要ないとき
		if(lines.size() && lines.back().first == a && lines.back().second > b ) lines.pop_back();
		//不必要な直線を取り除く
		while (lines.size() > 1 && isRequired(lines[lines.size()-2], lines[lines.size()-1], {a,b})) lines.pop_back();
		lines.push_back({a,b});
    }
    
    T get(T x) {
        int ng = -1, ok = (int)lines.size()-1, md;
        while (ok - ng > 1) {
            md = (ok + ng) >> 1;
            ( funcCompare(value(md, x),value(md + 1, x)) ?ok:ng)=md;
        }
        return value(ok, x);
    }
    
    // クエリの単調性も成り立つ場合 (x が単調増加)
    T getMonotone(T x) {
        while (lines.size() >= 2 && value(0, x) >= value(1, x)) lines.pop_front();
        return lines[0].first * x + lines[0].second;
    }

};

//最小値クエリの時
//ConvexHullTrick<ll> cht([&](ll l, ll r){return l < r;});
//傾きがa1>=a2>=a3...となるようにinsertする

//最大値クエリの時
//ConvexHullTrick<ll> cht([&](ll l, ll r){return l > r;});
//傾きがa1<=a2<=a3...となるようにinsertする

//verify
//https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "ConvexHullTrick.cpp"

template<class T> class ConvexHullTrick {
private:
    deque<pair<T,T>> lines;
	function<int(T,T)> funcCompare;

	//cが必要かどうか判定する
    inline int isRequired(const pair<T,T>& l, const pair<T,T>& c, const pair<T,T>& r) {
        return (c.first - l.first) * (r.second - c.second) >= (c.second - l.second) * (r.first - c.first);
    }
    
	//k番目のax+bの値
    inline T value(int k, T x) {
        return lines[k].first * x + lines[k].second;
    }

public:
	ConvexHullTrick(function<int(T,T)> funcCompare) : funcCompare(funcCompare) {
		// do nothing
	} 

	//傾きの大きさが単調な順にax+bを追加
	void insert(T a, T b) {
		//insertの必要がないとき
        if(lines.size() && lines.back().first == a && lines.back().second <= b) return;
		// 直前の直線の傾きが同じ　かつ　それが必要ないとき
		if(lines.size() && lines.back().first == a && lines.back().second > b ) lines.pop_back();
		//不必要な直線を取り除く
		while (lines.size() > 1 && isRequired(lines[lines.size()-2], lines[lines.size()-1], {a,b})) lines.pop_back();
		lines.push_back({a,b});
    }
    
    T get(T x) {
        int ng = -1, ok = (int)lines.size()-1, md;
        while (ok - ng > 1) {
            md = (ok + ng) >> 1;
            ( funcCompare(value(md, x),value(md + 1, x)) ?ok:ng)=md;
        }
        return value(ok, x);
    }
    
    // クエリの単調性も成り立つ場合 (x が単調増加)
    T getMonotone(T x) {
        while (lines.size() >= 2 && value(0, x) >= value(1, x)) lines.pop_front();
        return lines[0].first * x + lines[0].second;
    }

};

//最小値クエリの時
//ConvexHullTrick<ll> cht([&](ll l, ll r){return l < r;});
//傾きがa1>=a2>=a3...となるようにinsertする

//最大値クエリの時
//ConvexHullTrick<ll> cht([&](ll l, ll r){return l > r;});
//傾きがa1<=a2<=a3...となるようにinsertする

//verify
//https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c

```
{% endraw %}

<a href="../index.html">Back to top page</a>

