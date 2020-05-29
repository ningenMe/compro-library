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


# :warning: non-verified/FastFourierTransform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f62ece6ccc2c02f6163dc5f3da3d641d">non-verified</a>
* <a href="{{ site.github.repository_url }}/blob/master/non-verified/FastFourierTransform.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 05:00:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class FastFourierTransform{
    inline static vector<complex<double>> dft(vector<complex<double>> f, int sgn = 1) {
        int N = f.size();
        if(N == 1) return f;
        vector<complex<double>> g(N/2), h(N/2);
        complex<double> mul = 1,coe(cos(2.0 * M_PI / N), sin(2.0 * M_PI / N) * sgn);
        for(int i=0; i<N/2; i++) g[i] = f[2*i+0],h[i] = f[2*i+1];
        g = dft(g, sgn); h = dft(h, sgn);
        for(int i=0; i<N; ++i, mul *= coe) f[i] = g[i%(N/2)] + mul*h[i%(N/2)];
        return f;
    }
    inline static vector<complex<double>> inv(vector<complex<double>> f, int N) {
        f = dft(f,-1);
        for(int i=0; i<N; i++) f[i] /= N;
        return f;
    }
public:
    template<class T> inline static vector<complex<double>> convolution(const vector<T>& a,const vector<T>& b) {
        int N; for(N=1;N<a.size()+b.size()+1; N*=2);
        vector<complex<double>> f(N),g(N),h(N);
        for(int i = 0; i < a.size(); ++i) g[i]=a[i];
        for(int i = 0; i < b.size(); ++i) h[i]=b[i];
        g = dft(g); h = dft(h);
        for(int i=0; i<N; i++) f[i] = g[i]*h[i];
        return inv(f, N);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "non-verified/FastFourierTransform.cpp"
class FastFourierTransform{
    inline static vector<complex<double>> dft(vector<complex<double>> f, int sgn = 1) {
        int N = f.size();
        if(N == 1) return f;
        vector<complex<double>> g(N/2), h(N/2);
        complex<double> mul = 1,coe(cos(2.0 * M_PI / N), sin(2.0 * M_PI / N) * sgn);
        for(int i=0; i<N/2; i++) g[i] = f[2*i+0],h[i] = f[2*i+1];
        g = dft(g, sgn); h = dft(h, sgn);
        for(int i=0; i<N; ++i, mul *= coe) f[i] = g[i%(N/2)] + mul*h[i%(N/2)];
        return f;
    }
    inline static vector<complex<double>> inv(vector<complex<double>> f, int N) {
        f = dft(f,-1);
        for(int i=0; i<N; i++) f[i] /= N;
        return f;
    }
public:
    template<class T> inline static vector<complex<double>> convolution(const vector<T>& a,const vector<T>& b) {
        int N; for(N=1;N<a.size()+b.size()+1; N*=2);
        vector<complex<double>> f(N),g(N),h(N);
        for(int i = 0; i < a.size(); ++i) g[i]=a[i];
        for(int i = 0; i < b.size(); ++i) h[i]=b[i];
        g = dft(g); h = dft(h);
        for(int i=0; i<N; i++) f[i] = g[i]*h[i];
        return inv(f, N);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

