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


# :warning: unverified/RollingHash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#77abbaef317832d0cd0f51a55cb5a0a2">unverified</a>
* <a href="{{ site.github.repository_url }}/blob/master/unverified/RollingHash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 11:55:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class RollingHash {
private:
    long long base1,base2;
    long long mod1,mod2;
    vector<long long> hash1,hash2,pow1,pow2;
 
public: 
    RollingHash(const string& S) : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {
        int N = S.size();
        hash1.resize(N+1,0);
        hash2.resize(N+1,0);
        pow1.resize(N+1,1);
        pow2.resize(N+1,1);
 
        for(int i=1; i<=N; ++i) {
            hash1[i] = ((hash1[i-1]+S[i-1]) * base1) % mod1;
            hash2[i] = ((hash2[i-1]+S[i-1]) * base2) % mod2;
            pow1[i] = (pow1[i-1] * base1) % mod1;
            pow2[i] = (pow2[i-1] * base2) % mod2;
        }
    }

	//[l,r)
    pair<long long, long long> get(int l,int r) {
        long long t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        long long t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return {t1,t2};
    }
};

//verify
//https://atcoder.jp/contests/abc141/tasks/abc141_e
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "unverified/RollingHash.cpp"
class RollingHash {
private:
    long long base1,base2;
    long long mod1,mod2;
    vector<long long> hash1,hash2,pow1,pow2;
 
public: 
    RollingHash(const string& S) : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {
        int N = S.size();
        hash1.resize(N+1,0);
        hash2.resize(N+1,0);
        pow1.resize(N+1,1);
        pow2.resize(N+1,1);
 
        for(int i=1; i<=N; ++i) {
            hash1[i] = ((hash1[i-1]+S[i-1]) * base1) % mod1;
            hash2[i] = ((hash2[i-1]+S[i-1]) * base2) % mod2;
            pow1[i] = (pow1[i-1] * base1) % mod1;
            pow2[i] = (pow2[i-1] * base2) % mod2;
        }
    }

	//[l,r)
    pair<long long, long long> get(int l,int r) {
        long long t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        long long t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return {t1,t2};
    }
};

//verify
//https://atcoder.jp/contests/abc141/tasks/abc141_e

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

