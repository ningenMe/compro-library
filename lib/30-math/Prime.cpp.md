---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-divisor-1.test.cpp
    title: test/math/Prime-divisor-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-miller-rabin-1.test.cpp
    title: test/math/Prime-miller-rabin-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-miller-rabin-2.test.cpp
    title: test/math/Prime-miller-rabin-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-rho-discrete-logarithm.test.cpp
    title: test/math/Prime-rho-discrete-logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Prime-rho.test.cpp
    title: test/math/Prime-rho.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
    title: test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
    title: test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/math/Prime.md
    document_title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\
      \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm"
    links: []
  bundledCode: "#line 1 \"lib/30-math/Prime.cpp\"\n/*\n * @title Prime - \u9AD8\u901F\
    \u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\u30FBGcd\u30FBLcm\n * @docs md/math/Prime.md\n */\nclass Prime{\n\
    \    using u128 = __uint128_t;\n    using u64 = unsigned long long;\n    using\
    \ u32 = unsigned int;\n    class MontgomeryMod {\n        u64 mod,inv_mod,pow2_128;\n\
    \        inline u64 reduce(const u128& val) {\n            return (val + u128(u64(val)\
    \ * u64(-inv_mod)) * mod) >> 64;\n        }\n        inline u128 init_reduce(const\
    \ u64& val) {\n            return reduce((u128(val) + mod) * pow2_128);\n    \
    \    }\n        inline u64 mul_impl(const u64 l, const u64 r) {\n            return\
    \ reduce(u128(l)*r);\n        }\n    public:\n        MontgomeryMod(const u64\
    \ mod):mod(mod),pow2_128(-u128(mod)%mod) {\n            inv_mod = mod;\n     \
    \       for (int i = 0; i < 5; ++i) inv_mod *= 2 - mod * inv_mod;\n        }\n\
    \        //x^n % mod\n        inline u64 pow(const u64& x, u64 n) {\n        \
    \    u64 mres = init_reduce(1);\n            for (u64 mx = init_reduce(x); n >\
    \ 0; n >>= 1, mx=mul_impl(mx,mx)) if (n & 1) mres = mul_impl(mres,mx);\n     \
    \       mres=reduce(mres);\n            return mres >= mod ? mres - mod : mres;\n\
    \        }\n        inline u64 mul(const u64& l, const u64& r) {\n           \
    \ u64 ml=init_reduce(l),mr=init_reduce(r);\n            u64 mres=reduce(mul_impl(ml,mr));\n\
    \            return mres >= mod ? mres - mod : mres;\n        }\n        inline\
    \ u64 mmul(const u64& l, const u64& r) {\n            u64 ml=init_reduce(l),mr=init_reduce(r);\n\
    \t\t\treturn mul_impl(ml,mr);\n        }\n\t\t//NOTE l\u306Fmontgomery mod\u306E\
    \u72B6\u614B\n        inline u64 add(u64 ml, const u64& r) {\n            u64\
    \ mr=init_reduce(r);\n\t\t\tif ((ml += mr) >= 2 * mod) ml -= 2 * mod;\n      \
    \      u64 mres=reduce(ml);\n            return mres >= mod ? mres - mod : mres;\n\
    \        }\n    };\n    inline static constexpr long long pow_uint128(long long\
    \ x, long long n, long long mod) {\n        long long res = 1;\n        for (x\
    \ %= mod; n > 0; n >>= 1, x=(u128(x)*x)%mod) if (n & 1) res = (u128(res)*x)%mod;\n\
    \        return res;\n    }\n    inline static constexpr long long pow_int64(long\
    \ long x, long long n, long long mod) {\n        long long res = 1;\n        for\
    \ (x %= mod; n > 0; n >>= 1, x=(x*x)%mod) if (n & 1) res = (res*x)%mod;\n    \
    \    return res;\n    }\n    template<size_t sz> inline static constexpr bool\
    \ miller_rabin_uint128(const u64& n, const array<u64,sz>& ar) {\n        u32 i,s=0;\
    \ \n        u64 m = n - 1;\n        for (;!(m&1);++s,m>>=1);\n        MontgomeryMod\
    \ mmod(n);\n        for (const u64& a: ar) {\n            if(a>=n) break;\n  \
    \          u64 r=pow_uint128(a,m,n);\n            if(r != 1) {\n             \
    \   for(i=0; i<s; ++i) {\n                    if(r == n-1) break;\n          \
    \          r = (u128(r)*r)%n;\n                }\n                if(i==s) return\
    \ false;\n            }\n        }\n        return true;\n    }\n    template<size_t\
    \ sz> inline static constexpr bool miller_rabin_montgomery(const u64& n, const\
    \ array<u64,sz>& ar) {\n        u32 i,s=0; \n        u64 m = n - 1;\n        for\
    \ (;!(m&1);++s,m>>=1);\n        MontgomeryMod mmod(n);\n        for (const u64&\
    \ a: ar) {\n            if(a>=n) break;\n            u64 r=mmod.pow(a,m);\n  \
    \          if(r != 1) {\n                for(i=0; i<s; ++i) {\n              \
    \      if(r == n-1) break;\n                    r = mmod.mul(r,r);\n         \
    \       }\n                if(i==s) return false;\n            }\n        }\n\
    \        return true;\n    }\n    inline static constexpr long long K = 5;\n \
    \   inline static constexpr long long gcd_impl(long long n, long long m) {\n \
    \       long long t=0,s=0;\n        for(int i = 0; t = n - m, s = n - m * K, i\
    \ < 80; ++i) {\n            if(t<m){\n                if(!t) return m;\n     \
    \           n = m, m = t;\n            }\n            else{\n                if(!m)\
    \ return t;\n                n=t;\n                if(t >= m * K) n = s;\n   \
    \         }\n        }\n        return gcd_impl(m, n % m);\n    }\n    inline\
    \ static constexpr long long pre(long long n, long long m) {\n        long long\
    \ t = 0;\n        for(int i = 0; t = n - m, i < 4; ++i) {\n            (t < m\
    \ ? n=m,m=t : n=t);\n            if(!m) return n;\n        }\n        return gcd_impl(n,\
    \ m);\n    }\n    inline static constexpr array<u64,3> ar1={2ULL, 7ULL, 61ULL};\n\
    \    inline static constexpr array<u64,7> ar2={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};\n\
    \    inline static u64 rho(const u64& n){\n        if(miller_rabin(n)) return\
    \ n;\n        if((n&1) == 0) return 2;\n\t\tMontgomeryMod mmod(n);\n        for(u64\
    \ c=1,x=2,y=2,d=0;;c++){\n            do{\n\t\t\t\tx=mmod.add(mmod.mmul(x,x),c);\n\
    \t\t\t\ty=mmod.add(mmod.mmul(y,y),c);\n\t\t\t\ty=mmod.add(mmod.mmul(y,y),c);\n\
    \                d=gcd(x-y+n,n);\n            }while(d==1);\n            if(d<n)\
    \ return d;\n        }\n    }\n    inline static vector<u64> factor(const u64&\
    \ n, bool is_root) {\n        if(n <= 1) return {};\n        u64 p = rho(n);\n\
    \        if(p == n) return {p};\n        auto l = factor(p, false);\n        auto\
    \ r = factor(n / p, false);\n        copy(r.begin(), r.end(), back_inserter(l));\n\
    \t\tif(is_root) sort(l.begin(),l.end());\n        return l;\n    }\n    inline\
    \ static constexpr bool miller_rabin(const u64 n) {\n        if(n <= 1) return\
    \ false;\n        if(n == 2) return true;\n        if(n%2 == 0) return false;\n\
    \        if(n == 3) return true;\n        if(n%3 == 0) return false;\n       \
    \ if(n < 4759123141ULL) return miller_rabin_montgomery(n, ar1);\n\t\tif(n <= 1000'000'000'000'000'000ULL)\
    \ miller_rabin_montgomery(n, ar2); //'\n        return miller_rabin_uint128(n,\
    \ ar2);\n    }\n    inline static vector<pair<u64,u64>> factorization_impl(const\
    \ u64 n) {\n\t\t// queue<u64> q; q.push(n);\n\t\t// vector<u64> v;\n\t\t// while(q.size())\
    \ {\n\t\t// \tu64 tn = q.front(); q.pop();\n\t\t// \tif(tn<=1) continue;\n\t\t\
    // \tu64 p = rho(tn);\n\t\t// \tif(p!=tn) q.push(p),q.push(tn/p);\n\t\t// \telse\
    \ v.push_back(p);\n\t\t// }\n        auto v = factor(n, true);\n        vector<pair<u64,u64>>\
    \ vp;\n        u64 prev = 0;\n        for(u64& p:v) {\n            if(p == prev)\
    \ vp.back().second++;\n            else vp.emplace_back(p,1);\n            prev=p;\n\
    \        }\n        return vp;\n    }\n    inline static vector<u64> divisor_impl(const\
    \ u64 n) {\n        auto fac = factorization_impl(n);\n        vector<u64> res\
    \ = {1};\n        for(auto& [p,m]: fac) {\n            u32 sz = res.size();\n\
    \            for(u32 i=0;i<sz;++i) {\n                u64 d = 1;\n           \
    \     for(u32 j=0;j<m;++j) {\n                    d *= p;\n                  \
    \  res.push_back(res[i]*d);\n                }\n            }\n        }\n   \
    \     return res;\n    }\n    inline static long long baby_step_giant_step(long\
    \ long a, long long b, long long mod, const bool is_include_zero) {\n        a\
    \ %= mod, b%= mod;\n        if(mod==1) return is_include_zero ? 0 : 1;\n     \
    \   if(b==1 && is_include_zero) return 0;\n        if(a==0) return (b==0 ? 1:-1);\n\
    \n        long long offset=0, c = 1 % mod;\n        for(long long g; g=gcd(a,mod);\
    \ ++offset, b /= g, mod /= g, (c *= (a/g)) %= mod) {\n            if(g==1) break;\n\
    \            if(b == c) {\n                if(offset) return offset;\n       \
    \         else if(is_include_zero) return offset;\n            }\n           \
    \ if(b % g) return -1;\n        }\n\n        long long sm = sqrtl(mod)+1;\n  \
    \      //{a^0, a^1, ... a^sm} % mod\n        unordered_map<long long, long long>\
    \ pow_a;\n        for(long long i = !is_include_zero, d = b; i <= sm; ++i, (d*=a)%=mod)\
    \ {\n            pow_a[d]=i;\n        }\n        long long e = pow_int64(a,sm,mod);\n\
    \        for(long long i = 1, d = (c*e) % mod; i <= sm; ++i, (d*=e)%=mod) {\n\
    \            if(pow_a.count(d)) return i * sm - pow_a[d] + offset + !is_include_zero;\n\
    \        }\n        return -1;\n    }\npublic:\n    inline static constexpr bool\
    \ is_prime(const u64 n) { return miller_rabin(n); }\n\t//{\u7D20\u56E0\u6570,\u500B\
    \u6570}\u306Evector\u304C\u8FD4\u5374\u3055\u308C\u308B\n    inline static vector<pair<u64,u64>>\
    \ factorization(const u64 n) {return factorization_impl(n);}\n\t//\u7D20\u56E0\
    \u6570\u304C\u611A\u76F4\u306B\u6607\u9806\u3067\u8FD4\u5374\u3055\u308C\u308B\
    \n    inline static vector<u64> factor(const u64 n) {return factor(n, true);}\n\
    \    //\u7D04\u6570\u304C\u6607\u9806\u3067\u5217\u6319\u3055\u308C\u308B\n  \
    \  inline static vector<u64> divisor(const u64 n) {return divisor_impl(n); }\n\
    \    inline static constexpr long long gcd(long long n, long long m) { return\
    \ (n>m ? pre(n,m) : pre(m,n));}\n    inline static constexpr long long naive_gcd(long\
    \ long a, long long b) { return (b ? naive_gcd(b, a % b):a);}\n    inline static\
    \ constexpr long long lcm(long long a, long long b) {return (a*b ? (a / gcd(a,\
    \ b)*b): 0);}\n    //ax+by=gcd(a,b)\n    inline static constexpr long long ext_gcd(long\
    \ long a, long long b, long long &x, long long &y) {\n        if (b == 0) return\
    \ x = 1, y = 0, a; long long d = ext_gcd(b, a%b, y, x); return y -= a / b * x,\
    \ d;\n    }\n    //a^x = b (% mod) \u306A\u308B x\u3092\u6C42\u3081\u308B\n  \
    \  inline static long long discrete_logarithm(long long a, long long b, long long\
    \ mod, bool is_include_zero=1) {return baby_step_giant_step(a,b,mod,is_include_zero);}\n\
    };\n"
  code: "/*\n * @title Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\
    \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm\n * @docs\
    \ md/math/Prime.md\n */\nclass Prime{\n    using u128 = __uint128_t;\n    using\
    \ u64 = unsigned long long;\n    using u32 = unsigned int;\n    class MontgomeryMod\
    \ {\n        u64 mod,inv_mod,pow2_128;\n        inline u64 reduce(const u128&\
    \ val) {\n            return (val + u128(u64(val) * u64(-inv_mod)) * mod) >> 64;\n\
    \        }\n        inline u128 init_reduce(const u64& val) {\n            return\
    \ reduce((u128(val) + mod) * pow2_128);\n        }\n        inline u64 mul_impl(const\
    \ u64 l, const u64 r) {\n            return reduce(u128(l)*r);\n        }\n  \
    \  public:\n        MontgomeryMod(const u64 mod):mod(mod),pow2_128(-u128(mod)%mod)\
    \ {\n            inv_mod = mod;\n            for (int i = 0; i < 5; ++i) inv_mod\
    \ *= 2 - mod * inv_mod;\n        }\n        //x^n % mod\n        inline u64 pow(const\
    \ u64& x, u64 n) {\n            u64 mres = init_reduce(1);\n            for (u64\
    \ mx = init_reduce(x); n > 0; n >>= 1, mx=mul_impl(mx,mx)) if (n & 1) mres = mul_impl(mres,mx);\n\
    \            mres=reduce(mres);\n            return mres >= mod ? mres - mod :\
    \ mres;\n        }\n        inline u64 mul(const u64& l, const u64& r) {\n   \
    \         u64 ml=init_reduce(l),mr=init_reduce(r);\n            u64 mres=reduce(mul_impl(ml,mr));\n\
    \            return mres >= mod ? mres - mod : mres;\n        }\n        inline\
    \ u64 mmul(const u64& l, const u64& r) {\n            u64 ml=init_reduce(l),mr=init_reduce(r);\n\
    \t\t\treturn mul_impl(ml,mr);\n        }\n\t\t//NOTE l\u306Fmontgomery mod\u306E\
    \u72B6\u614B\n        inline u64 add(u64 ml, const u64& r) {\n            u64\
    \ mr=init_reduce(r);\n\t\t\tif ((ml += mr) >= 2 * mod) ml -= 2 * mod;\n      \
    \      u64 mres=reduce(ml);\n            return mres >= mod ? mres - mod : mres;\n\
    \        }\n    };\n    inline static constexpr long long pow_uint128(long long\
    \ x, long long n, long long mod) {\n        long long res = 1;\n        for (x\
    \ %= mod; n > 0; n >>= 1, x=(u128(x)*x)%mod) if (n & 1) res = (u128(res)*x)%mod;\n\
    \        return res;\n    }\n    inline static constexpr long long pow_int64(long\
    \ long x, long long n, long long mod) {\n        long long res = 1;\n        for\
    \ (x %= mod; n > 0; n >>= 1, x=(x*x)%mod) if (n & 1) res = (res*x)%mod;\n    \
    \    return res;\n    }\n    template<size_t sz> inline static constexpr bool\
    \ miller_rabin_uint128(const u64& n, const array<u64,sz>& ar) {\n        u32 i,s=0;\
    \ \n        u64 m = n - 1;\n        for (;!(m&1);++s,m>>=1);\n        MontgomeryMod\
    \ mmod(n);\n        for (const u64& a: ar) {\n            if(a>=n) break;\n  \
    \          u64 r=pow_uint128(a,m,n);\n            if(r != 1) {\n             \
    \   for(i=0; i<s; ++i) {\n                    if(r == n-1) break;\n          \
    \          r = (u128(r)*r)%n;\n                }\n                if(i==s) return\
    \ false;\n            }\n        }\n        return true;\n    }\n    template<size_t\
    \ sz> inline static constexpr bool miller_rabin_montgomery(const u64& n, const\
    \ array<u64,sz>& ar) {\n        u32 i,s=0; \n        u64 m = n - 1;\n        for\
    \ (;!(m&1);++s,m>>=1);\n        MontgomeryMod mmod(n);\n        for (const u64&\
    \ a: ar) {\n            if(a>=n) break;\n            u64 r=mmod.pow(a,m);\n  \
    \          if(r != 1) {\n                for(i=0; i<s; ++i) {\n              \
    \      if(r == n-1) break;\n                    r = mmod.mul(r,r);\n         \
    \       }\n                if(i==s) return false;\n            }\n        }\n\
    \        return true;\n    }\n    inline static constexpr long long K = 5;\n \
    \   inline static constexpr long long gcd_impl(long long n, long long m) {\n \
    \       long long t=0,s=0;\n        for(int i = 0; t = n - m, s = n - m * K, i\
    \ < 80; ++i) {\n            if(t<m){\n                if(!t) return m;\n     \
    \           n = m, m = t;\n            }\n            else{\n                if(!m)\
    \ return t;\n                n=t;\n                if(t >= m * K) n = s;\n   \
    \         }\n        }\n        return gcd_impl(m, n % m);\n    }\n    inline\
    \ static constexpr long long pre(long long n, long long m) {\n        long long\
    \ t = 0;\n        for(int i = 0; t = n - m, i < 4; ++i) {\n            (t < m\
    \ ? n=m,m=t : n=t);\n            if(!m) return n;\n        }\n        return gcd_impl(n,\
    \ m);\n    }\n    inline static constexpr array<u64,3> ar1={2ULL, 7ULL, 61ULL};\n\
    \    inline static constexpr array<u64,7> ar2={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};\n\
    \    inline static u64 rho(const u64& n){\n        if(miller_rabin(n)) return\
    \ n;\n        if((n&1) == 0) return 2;\n\t\tMontgomeryMod mmod(n);\n        for(u64\
    \ c=1,x=2,y=2,d=0;;c++){\n            do{\n\t\t\t\tx=mmod.add(mmod.mmul(x,x),c);\n\
    \t\t\t\ty=mmod.add(mmod.mmul(y,y),c);\n\t\t\t\ty=mmod.add(mmod.mmul(y,y),c);\n\
    \                d=gcd(x-y+n,n);\n            }while(d==1);\n            if(d<n)\
    \ return d;\n        }\n    }\n    inline static vector<u64> factor(const u64&\
    \ n, bool is_root) {\n        if(n <= 1) return {};\n        u64 p = rho(n);\n\
    \        if(p == n) return {p};\n        auto l = factor(p, false);\n        auto\
    \ r = factor(n / p, false);\n        copy(r.begin(), r.end(), back_inserter(l));\n\
    \t\tif(is_root) sort(l.begin(),l.end());\n        return l;\n    }\n    inline\
    \ static constexpr bool miller_rabin(const u64 n) {\n        if(n <= 1) return\
    \ false;\n        if(n == 2) return true;\n        if(n%2 == 0) return false;\n\
    \        if(n == 3) return true;\n        if(n%3 == 0) return false;\n       \
    \ if(n < 4759123141ULL) return miller_rabin_montgomery(n, ar1);\n\t\tif(n <= 1000'000'000'000'000'000ULL)\
    \ miller_rabin_montgomery(n, ar2); //'\n        return miller_rabin_uint128(n,\
    \ ar2);\n    }\n    inline static vector<pair<u64,u64>> factorization_impl(const\
    \ u64 n) {\n\t\t// queue<u64> q; q.push(n);\n\t\t// vector<u64> v;\n\t\t// while(q.size())\
    \ {\n\t\t// \tu64 tn = q.front(); q.pop();\n\t\t// \tif(tn<=1) continue;\n\t\t\
    // \tu64 p = rho(tn);\n\t\t// \tif(p!=tn) q.push(p),q.push(tn/p);\n\t\t// \telse\
    \ v.push_back(p);\n\t\t// }\n        auto v = factor(n, true);\n        vector<pair<u64,u64>>\
    \ vp;\n        u64 prev = 0;\n        for(u64& p:v) {\n            if(p == prev)\
    \ vp.back().second++;\n            else vp.emplace_back(p,1);\n            prev=p;\n\
    \        }\n        return vp;\n    }\n    inline static vector<u64> divisor_impl(const\
    \ u64 n) {\n        auto fac = factorization_impl(n);\n        vector<u64> res\
    \ = {1};\n        for(auto& [p,m]: fac) {\n            u32 sz = res.size();\n\
    \            for(u32 i=0;i<sz;++i) {\n                u64 d = 1;\n           \
    \     for(u32 j=0;j<m;++j) {\n                    d *= p;\n                  \
    \  res.push_back(res[i]*d);\n                }\n            }\n        }\n   \
    \     return res;\n    }\n    inline static long long baby_step_giant_step(long\
    \ long a, long long b, long long mod, const bool is_include_zero) {\n        a\
    \ %= mod, b%= mod;\n        if(mod==1) return is_include_zero ? 0 : 1;\n     \
    \   if(b==1 && is_include_zero) return 0;\n        if(a==0) return (b==0 ? 1:-1);\n\
    \n        long long offset=0, c = 1 % mod;\n        for(long long g; g=gcd(a,mod);\
    \ ++offset, b /= g, mod /= g, (c *= (a/g)) %= mod) {\n            if(g==1) break;\n\
    \            if(b == c) {\n                if(offset) return offset;\n       \
    \         else if(is_include_zero) return offset;\n            }\n           \
    \ if(b % g) return -1;\n        }\n\n        long long sm = sqrtl(mod)+1;\n  \
    \      //{a^0, a^1, ... a^sm} % mod\n        unordered_map<long long, long long>\
    \ pow_a;\n        for(long long i = !is_include_zero, d = b; i <= sm; ++i, (d*=a)%=mod)\
    \ {\n            pow_a[d]=i;\n        }\n        long long e = pow_int64(a,sm,mod);\n\
    \        for(long long i = 1, d = (c*e) % mod; i <= sm; ++i, (d*=e)%=mod) {\n\
    \            if(pow_a.count(d)) return i * sm - pow_a[d] + offset + !is_include_zero;\n\
    \        }\n        return -1;\n    }\npublic:\n    inline static constexpr bool\
    \ is_prime(const u64 n) { return miller_rabin(n); }\n\t//{\u7D20\u56E0\u6570,\u500B\
    \u6570}\u306Evector\u304C\u8FD4\u5374\u3055\u308C\u308B\n    inline static vector<pair<u64,u64>>\
    \ factorization(const u64 n) {return factorization_impl(n);}\n\t//\u7D20\u56E0\
    \u6570\u304C\u611A\u76F4\u306B\u6607\u9806\u3067\u8FD4\u5374\u3055\u308C\u308B\
    \n    inline static vector<u64> factor(const u64 n) {return factor(n, true);}\n\
    \    //\u7D04\u6570\u304C\u6607\u9806\u3067\u5217\u6319\u3055\u308C\u308B\n  \
    \  inline static vector<u64> divisor(const u64 n) {return divisor_impl(n); }\n\
    \    inline static constexpr long long gcd(long long n, long long m) { return\
    \ (n>m ? pre(n,m) : pre(m,n));}\n    inline static constexpr long long naive_gcd(long\
    \ long a, long long b) { return (b ? naive_gcd(b, a % b):a);}\n    inline static\
    \ constexpr long long lcm(long long a, long long b) {return (a*b ? (a / gcd(a,\
    \ b)*b): 0);}\n    //ax+by=gcd(a,b)\n    inline static constexpr long long ext_gcd(long\
    \ long a, long long b, long long &x, long long &y) {\n        if (b == 0) return\
    \ x = 1, y = 0, a; long long d = ext_gcd(b, a%b, y, x); return y -= a / b * x,\
    \ d;\n    }\n    //a^x = b (% mod) \u306A\u308B x\u3092\u6C42\u3081\u308B\n  \
    \  inline static long long discrete_logarithm(long long a, long long b, long long\
    \ mod, bool is_include_zero=1) {return baby_step_giant_step(a,b,mod,is_include_zero);}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/30-math/Prime.cpp
  requiredBy: []
  timestamp: '2023-06-23 05:10:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Prime-miller-rabin-1.test.cpp
  - test/math/Prime-divisor-1.test.cpp
  - test/math/Prime-rho-discrete-logarithm.test.cpp
  - test/math/Prime-miller-rabin-2.test.cpp
  - test/math/Prime-rho.test.cpp
  - test/segment-tree/SegmentTree-prefix-binary-search.test.cpp
  - test/segment-tree/SegmentTree-suffix-binary-search.test.cpp
documentation_of: lib/30-math/Prime.cpp
layout: document
redirect_from:
- /library/lib/30-math/Prime.cpp
- /library/lib/30-math/Prime.cpp.html
title: "Prime - \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u30FB\u30DF\u30E9\u30FC\
  \u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u30FBGcd\u30FBLcm"
---
