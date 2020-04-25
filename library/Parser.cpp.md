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


# :warning: Parser.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Parser.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-17 19:53:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<class T> class Parser {
public:
    int root;
    vector<T> res;
    vector<int> leftNode, rightNode; //左右の子へのindex
	vector<int> idx;//元のindex

	string str;    //構文
	vector<T> num; //数値
    
	Parser(const string& str,const vector<T>& num):str(str),num(num){
        int p = 0;
        root = expr(p);
	}
	
	//構文木のindexに対する文字を取り出す
	char getOperator(int q){
		assert(0 <= q && q <= str.size());
		return str[idx[q]];
	}

private:
	int newNode(int i, int l, int r) {
		leftNode.push_back(l);
		rightNode.push_back(r);
        T val;
		if (str[i] == 'a') {
            val = num[i];
        }
		else if(str[i] == '(' || str[i] == ')'){
            val = -1;
		}
        else {
            if (str[i] == '+') val = res[l] + res[r];
            if (str[i] == '-') val = res[l] - res[r];
            if (str[i] == '*') val = res[l] * res[r];
            if (str[i] == '/') val = res[l] / res[r];
        }
		res.push_back(val);
		idx.push_back(i);
        return (int)res.size() - 1;
    }
    
    int expr(int &p) {
        int l = factor(p);
        while (p < (int)str.size() && (str[p] == '+' || str[p] == '-')) {
			int i = p++;
            int r = factor(p);
            l = newNode(i, l, r);
        }
        return l;
    }
    
    int factor(int &p) {
        int l = value(p);
        while (p < (int)str.size() && (str[p]== '*' || str[p] == '/')) {
			int i = p++;
            int r = value(p);
            l = newNode(i, l, r);
        }
        return l;
    }
    
    int value(int &p) {
        if (str[p] == '(') {
            newNode(p, -1, -1);  //'('
			p++;
            int l = expr(p);
            newNode(p, -1, -1);  //')'
            p++;
			return l;
        }
        else {
			int i = p++;
            return newNode(i, -1, -1);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Parser.cpp"
template<class T> class Parser {
public:
    int root;
    vector<T> res;
    vector<int> leftNode, rightNode; //左右の子へのindex
	vector<int> idx;//元のindex

	string str;    //構文
	vector<T> num; //数値
    
	Parser(const string& str,const vector<T>& num):str(str),num(num){
        int p = 0;
        root = expr(p);
	}
	
	//構文木のindexに対する文字を取り出す
	char getOperator(int q){
		assert(0 <= q && q <= str.size());
		return str[idx[q]];
	}

private:
	int newNode(int i, int l, int r) {
		leftNode.push_back(l);
		rightNode.push_back(r);
        T val;
		if (str[i] == 'a') {
            val = num[i];
        }
		else if(str[i] == '(' || str[i] == ')'){
            val = -1;
		}
        else {
            if (str[i] == '+') val = res[l] + res[r];
            if (str[i] == '-') val = res[l] - res[r];
            if (str[i] == '*') val = res[l] * res[r];
            if (str[i] == '/') val = res[l] / res[r];
        }
		res.push_back(val);
		idx.push_back(i);
        return (int)res.size() - 1;
    }
    
    int expr(int &p) {
        int l = factor(p);
        while (p < (int)str.size() && (str[p] == '+' || str[p] == '-')) {
			int i = p++;
            int r = factor(p);
            l = newNode(i, l, r);
        }
        return l;
    }
    
    int factor(int &p) {
        int l = value(p);
        while (p < (int)str.size() && (str[p]== '*' || str[p] == '/')) {
			int i = p++;
            int r = value(p);
            l = newNode(i, l, r);
        }
        return l;
    }
    
    int value(int &p) {
        if (str[p] == '(') {
            newNode(p, -1, -1);  //'('
			p++;
            int l = expr(p);
            newNode(p, -1, -1);  //')'
            p++;
			return l;
        }
        else {
			int i = p++;
            return newNode(i, -1, -1);
        }
    }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

