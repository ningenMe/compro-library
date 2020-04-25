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


# :warning: SmallestEnclosingDisc.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/SmallestEnclosingDisc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-19 02:10:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <class T> class SmallestEnclosingDisc{
    inline T cross(const complex<T>& a, const complex<T>& b) {return a.real()*b.imag() - a.imag()*b.real(); }
    inline T dot(const complex<T>& a, const complex<T>& b) { return a.real()*b.real() + a.imag()*b.imag(); }
    inline void makeCenter(const complex<T>& a,const complex<T>& b) {
        center = (a+b)/2.;
        radius = abs(a-center);
    }
    inline void makeCenter(const complex<T>& a,const complex<T>& b,const complex<T>& c) {
        T s = norm(b-c),t = norm(c-a),u = norm(a-b),z = abs(cross(b-a,c-a));
        center = (s*(t+u-s)*a+t*(u+s-t)*b+u*(s+t-u)*c)/(4*z*z);
        radius = abs(a-center);
    }
    inline bool isInCircle(const complex<T>& point){
        return norm(point-center) <= radius*radius + eps;
    } 
    vector<complex<T>> points;
    T eps;
public:
    complex<T> center;
    T radius;

    SmallestEnclosingDisc(T eps = 1e-9): eps(eps){
    }
    inline void addPoint(complex<T> point){
        points.push_back(point);
    }
    void solve(){
        int num = points.size();
        if(num == 1) {
            radius = 0;
            center = points.front();
            return;
        }
        random_device seed_gen;
        mt19937 engine(seed_gen());
        shuffle(points.begin(), points.end(), engine);
        makeCenter(points[0],points[1]);
        for(int i = 2; i < num; ++i){
            if(isInCircle(points[i])) continue;
            makeCenter(points[0],points[i]);
            for(int j = 1; j < i; ++j) {
                if(isInCircle(points[j])) continue;
                makeCenter(points[i],points[j]);
                for(int k = 0; k < j; ++k) {
                    if(isInCircle(points[k])) continue;
                    makeCenter(points[i],points[j],points[k]);
                }
            }
        }
    }
};

//verify https://atcoder.jp/contests/abc151/tasks/abc151_f

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "SmallestEnclosingDisc.cpp"

template <class T> class SmallestEnclosingDisc{
    inline T cross(const complex<T>& a, const complex<T>& b) {return a.real()*b.imag() - a.imag()*b.real(); }
    inline T dot(const complex<T>& a, const complex<T>& b) { return a.real()*b.real() + a.imag()*b.imag(); }
    inline void makeCenter(const complex<T>& a,const complex<T>& b) {
        center = (a+b)/2.;
        radius = abs(a-center);
    }
    inline void makeCenter(const complex<T>& a,const complex<T>& b,const complex<T>& c) {
        T s = norm(b-c),t = norm(c-a),u = norm(a-b),z = abs(cross(b-a,c-a));
        center = (s*(t+u-s)*a+t*(u+s-t)*b+u*(s+t-u)*c)/(4*z*z);
        radius = abs(a-center);
    }
    inline bool isInCircle(const complex<T>& point){
        return norm(point-center) <= radius*radius + eps;
    } 
    vector<complex<T>> points;
    T eps;
public:
    complex<T> center;
    T radius;

    SmallestEnclosingDisc(T eps = 1e-9): eps(eps){
    }
    inline void addPoint(complex<T> point){
        points.push_back(point);
    }
    void solve(){
        int num = points.size();
        if(num == 1) {
            radius = 0;
            center = points.front();
            return;
        }
        random_device seed_gen;
        mt19937 engine(seed_gen());
        shuffle(points.begin(), points.end(), engine);
        makeCenter(points[0],points[1]);
        for(int i = 2; i < num; ++i){
            if(isInCircle(points[i])) continue;
            makeCenter(points[0],points[i]);
            for(int j = 1; j < i; ++j) {
                if(isInCircle(points[j])) continue;
                makeCenter(points[i],points[j]);
                for(int k = 0; k < j; ++k) {
                    if(isInCircle(points[k])) continue;
                    makeCenter(points[i],points[j],points[k]);
                }
            }
        }
    }
};

//verify https://atcoder.jp/contests/abc151/tasks/abc151_f

```
{% endraw %}

<a href="../index.html">Back to top page</a>

