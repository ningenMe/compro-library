---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/30-math/Eratosthenes.cpp
    title: "Eratosthenes - \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  - icon: ':heavy_check_mark:'
    path: lib/31-convolution/DivisorZetaMoebiusTransform.cpp
    title: "DivisorZetaMoebiusTransform - \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u30FB\
      \u30E1\u30D3\u30A6\u30B9\u5909\u63DB (gcd/lcm\u7573\u307F\u8FBC\u307F)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\nusing namespace std;\n#line\
    \ 1 \"lib/00-util/ModInt.cpp\"\n/*\n * @title ModInt\n * @docs md/util/ModInt.md\n\
    \ */\ntemplate<long long mod> class ModInt {\npublic:\n    long long x;\n    constexpr\
    \ ModInt():x(0) {}\n    constexpr ModInt(long long y) : x(y>=0?(y%mod): (mod -\
    \ (-y)%mod)%mod) {}\n    constexpr ModInt &operator+=(const ModInt &p) {if((x\
    \ += p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator+=(const\
    \ long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n  \
    \  constexpr ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod)\
    \ x -= mod;return *this;}\n    constexpr ModInt &operator-=(const ModInt &p) {if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ long long y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n\
    \    constexpr ModInt &operator-=(const int y) {ModInt p(y);if((x += mod - p.x)\
    \ >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator*=(const ModInt\
    \ &p) {x = (x * p.x % mod);return *this;}\n    constexpr ModInt &operator*=(const\
    \ long long y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n    constexpr\
    \ ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return *this;}\n\
    \    constexpr ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    constexpr ModInt &operator^=(const long long y) {ModInt p(y);x\
    \ = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const int\
    \ y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator/=(const\
    \ ModInt &p) {*this *= p.inv();return *this;}\n    constexpr ModInt &operator/=(const\
    \ long long y) {ModInt p(y);*this *= p.inv();return *this;}\n    constexpr ModInt\
    \ &operator/=(const int y) {ModInt p(y);*this *= p.inv();return *this;}\n    constexpr\
    \ ModInt operator=(const int y) {ModInt p(y);*this = p;return *this;}\n    constexpr\
    \ ModInt operator=(const long long y) {ModInt p(y);*this = p;return *this;}\n\
    \    constexpr ModInt operator-() const {return ModInt(-x); }\n    constexpr ModInt\
    \ operator++() {x++;if(x>=mod) x-=mod;return *this;}\n    constexpr ModInt operator--()\
    \ {x--;if(x<0) x+=mod;return *this;}\n    constexpr ModInt operator+(const ModInt\
    \ &p) const { return ModInt(*this) += p; }\n    constexpr ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    constexpr ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    constexpr ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    constexpr ModInt operator^(const\
    \ ModInt &p) const { return ModInt(*this) ^= p; }\n    constexpr bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n    constexpr bool operator!=(const ModInt\
    \ &p) const { return x != p.x; }\n    // ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    constexpr ModInt inv() const {int a=x,b=mod,u=1,v=0,t=0,tmp=0;while(b > 0)\
    \ {t = a / b;a-=t*b;tmp=a;a=b;b=tmp;u-=t*v;tmp=u;u=v;v=tmp;} return ModInt(u);}\n\
    \    constexpr ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul\
    \ *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    constexpr long long MOD_998244353 = 998244353;\nconstexpr long long MOD_1000000007\
    \ = 1'000'000'000LL + 7; //'\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title\
    \ FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n    inline\
    \ static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/30-math/Eratosthenes.cpp\"\n/*\n * @title Eratosthenes - \u30A8\u30E9\
    \u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n * @docs md/math/Eratosthenes.md\n\
    \ */\nclass Eratosthenes {\n    unsigned int sz;\npublic:\n    vector<unsigned\
    \ int> sieve;\n    vector<long long> prime;\n    Eratosthenes(unsigned int N):sz(N+1),sieve(N+1,\
    \ 1) {\n        sieve[0]=sieve[1]=0;\n        for(int i=1; i <= N/i; ++i) if(sieve[i])\
    \ for(int j=2*i;j<=N;j+=i) sieve[j]=0;\n        for(int i=1; i <= N  ; ++i) if(sieve[i])\
    \ prime.push_back(i);\n    }\n    size_t size() const {\n        return sz;\n\
    \    }\n};\n#line 1 \"lib/31-convolution/DivisorZetaMoebiusTransform.cpp\"\n/*\n\
    \ * @title DivisorZetaMoebiusTransform - \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u30FB\
    \u30E1\u30D3\u30A6\u30B9\u5909\u63DB (gcd/lcm\u7573\u307F\u8FBC\u307F)\n * @docs\
    \ md/math/DivisorZetaMoebiusTransform.md\n */\nclass DivisorZetaMoebiusTransform\
    \ {\n    template<class T> inline static void zeta_multiple(vector<T>& v, const\
    \ Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) v[i]\
    \ += v[i*p];\n    }\n    template<class T> inline static void mobius_multiple(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) v[i] -=\
    \ v[i*p];\n    }\n    template<class T> inline static void zeta_divisor(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=1; i*p<N; ++i) {v[i*p]\
    \ += v[i];}\n    }\n    template<class T> inline static void mobius_divisor(vector<T>&\
    \ v, const Eratosthenes& eratosthenes) {\n        assert(v.size()); int N = v.size();\n\
    \        for(const int& p:eratosthenes.prime) for(int i=(N-1)/p; i; --i) {v[i*p]\
    \ -= v[i];}\n    }\npublic:\n    template<class T> inline static vector<T> gcd_convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta_multiple(f,eratosthenes);zeta_multiple(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius_multiple(f,eratosthenes);\n\
    \        return f;\n    }\n    template<class T> inline static vector<T> lcm_convolution(const\
    \ vector<T>& a,const vector<T>& b, const Eratosthenes& eratosthenes) {\n     \
    \   int N = max(a.size(),b.size());\n        assert(N <= eratosthenes.size());\n\
    \        vector<T> f(N,0),g(N,0);\n        for(int i=0;i<N;++i) f[i] = a[i];\n\
    \        for(int i=0;i<N;++i) g[i] = b[i];\n        zeta_divisor(f,eratosthenes);zeta_divisor(g,eratosthenes);\n\
    \        for(int i=0;i<N;++i) f[i] = f[i]*g[i];\n        mobius_divisor(f,eratosthenes);\n\
    \        return f;\n    }\n};\n#line 11 \"test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp\"\
    \n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    using Mint\
    \ = ModInt<MOD_998244353>;\n    int N; read(N);\n    vector<Mint> a(N+1,0),b(N+1,0);\n\
    \    auto e = Eratosthenes(N);\n    for(int i=1;i<=N;++i) {\n        int t; read(t);\
    \ a[i]=t;\n    }\n    for(int i=1;i<=N;++i) {\n        int t; read(t); b[i]=t;\n\
    \    }\n    auto c = DivisorZetaMoebiusTransform::lcm_convolution(a,b,e);\n  \
    \  for(int i=1;i<=N;++i) {\n        cout << c[i] << \" \\n\"[i==N];\n    }\n \
    \   return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\nusing namespace std;\n#include\
    \ \"../../lib/00-util/ModInt.cpp\"\n#include \"../../lib/00-util/FastIO.cpp\"\n\
    #include \"../../lib/30-math/Eratosthenes.cpp\"\n#include \"../../lib/31-convolution/DivisorZetaMoebiusTransform.cpp\"\
    \n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    using Mint\
    \ = ModInt<MOD_998244353>;\n    int N; read(N);\n    vector<Mint> a(N+1,0),b(N+1,0);\n\
    \    auto e = Eratosthenes(N);\n    for(int i=1;i<=N;++i) {\n        int t; read(t);\
    \ a[i]=t;\n    }\n    for(int i=1;i<=N;++i) {\n        int t; read(t); b[i]=t;\n\
    \    }\n    auto c = DivisorZetaMoebiusTransform::lcm_convolution(a,b,e);\n  \
    \  for(int i=1;i<=N;++i) {\n        cout << c[i] << \" \\n\"[i==N];\n    }\n \
    \   return 0;\n}\n"
  dependsOn:
  - lib/00-util/ModInt.cpp
  - lib/00-util/FastIO.cpp
  - lib/30-math/Eratosthenes.cpp
  - lib/31-convolution/DivisorZetaMoebiusTransform.cpp
  isVerificationFile: true
  path: test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 05:25:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
- /verify/test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp.html
title: test/convolution/DivisorZetaMoebiusTransform-lcm-convolution.test.cpp
---
