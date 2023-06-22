/*
 * @title Prime - 高速素因数分解・ミラーラビン素数判定・Gcd・Lcm
 * @docs md/math/Prime.md
 */
class Prime{
    using u128 = __uint128_t;
    using u64 = unsigned long long;
    using u32 = unsigned int;
    class MontgomeryMod {
        u64 mod,inv_mod,pow2_128;
        inline u64 reduce(const u128& val) {
            return (val + u128(u64(val) * u64(-inv_mod)) * mod) >> 64;
        }
        inline u128 init_reduce(const u64& val) {
            return reduce((u128(val) + mod) * pow2_128);
        }
        inline u64 mul_impl(const u64 l, const u64 r) {
            return reduce(u128(l)*r);
        }
    public:
        MontgomeryMod(const u64 mod):mod(mod),pow2_128(-u128(mod)%mod) {
            inv_mod = mod;
            for (int i = 0; i < 5; ++i) inv_mod *= 2 - mod * inv_mod;
        }
        //x^n % mod
        inline u64 pow(const u64& x, u64 n) {
            u64 mres = init_reduce(1);
            for (u64 mx = init_reduce(x); n > 0; n >>= 1, mx=mul_impl(mx,mx)) if (n & 1) mres = mul_impl(mres,mx);
            mres=reduce(mres);
            return mres >= mod ? mres - mod : mres;
        }
        inline u64 mul(const u64& l, const u64& r) {
            u64 ml=init_reduce(l),mr=init_reduce(r);
            u64 mres=reduce(mul_impl(ml,mr));
            return mres >= mod ? mres - mod : mres;
        }
        inline u64 mmul(const u64& l, const u64& r) {
            u64 ml=init_reduce(l),mr=init_reduce(r);
			return mul_impl(ml,mr);
        }
		//NOTE lはmontgomery modの状態
        inline u64 add(u64 ml, const u64& r) {
            u64 mr=init_reduce(r);
			if ((ml += mr) >= 2 * mod) ml -= 2 * mod;
            u64 mres=reduce(ml);
            return mres >= mod ? mres - mod : mres;
        }
    };
    inline static constexpr long long pow_uint128(long long x, long long n, long long mod) {
        long long res = 1;
        for (x %= mod; n > 0; n >>= 1, x=(u128(x)*x)%mod) if (n & 1) res = (u128(res)*x)%mod;
        return res;
    }
    inline static constexpr long long pow_int64(long long x, long long n, long long mod) {
        long long res = 1;
        for (x %= mod; n > 0; n >>= 1, x=(x*x)%mod) if (n & 1) res = (res*x)%mod;
        return res;
    }
    template<size_t sz> inline static constexpr bool miller_rabin_uint128(const u64& n, const array<u64,sz>& ar) {
        u32 i,s=0; 
        u64 m = n - 1;
        for (;!(m&1);++s,m>>=1);
        MontgomeryMod mmod(n);
        for (const u64& a: ar) {
            if(a>=n) break;
            u64 r=pow_uint128(a,m,n);
            if(r != 1) {
                for(i=0; i<s; ++i) {
                    if(r == n-1) break;
                    r = (u128(r)*r)%n;
                }
                if(i==s) return false;
            }
        }
        return true;
    }
    template<size_t sz> inline static constexpr bool miller_rabin_montgomery(const u64& n, const array<u64,sz>& ar) {
        u32 i,s=0; 
        u64 m = n - 1;
        for (;!(m&1);++s,m>>=1);
        MontgomeryMod mmod(n);
        for (const u64& a: ar) {
            if(a>=n) break;
            u64 r=mmod.pow(a,m);
            if(r != 1) {
                for(i=0; i<s; ++i) {
                    if(r == n-1) break;
                    r = mmod.mul(r,r);
                }
                if(i==s) return false;
            }
        }
        return true;
    }
    inline static constexpr long long K = 5;
    inline static constexpr long long gcd_impl(long long n, long long m) {
        long long t=0,s=0;
        for(int i = 0; t = n - m, s = n - m * K, i < 80; ++i) {
            if(t<m){
                if(!t) return m;
                n = m, m = t;
            }
            else{
                if(!m) return t;
                n=t;
                if(t >= m * K) n = s;
            }
        }
        return gcd_impl(m, n % m);
    }
    inline static constexpr long long pre(long long n, long long m) {
        long long t = 0;
        for(int i = 0; t = n - m, i < 4; ++i) {
            (t < m ? n=m,m=t : n=t);
            if(!m) return n;
        }
        return gcd_impl(n, m);
    }
    inline static constexpr array<u64,3> ar1={2ULL, 7ULL, 61ULL};
    inline static constexpr array<u64,7> ar2={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};
    inline static u64 rho(const u64& n){
        if(miller_rabin(n)) return n;
        if((n&1) == 0) return 2;
		MontgomeryMod mmod(n);
        for(u64 c=1,x=2,y=2,d=0;;c++){
            do{
				x=mmod.add(mmod.mmul(x,x),c);
				y=mmod.add(mmod.mmul(y,y),c);
				y=mmod.add(mmod.mmul(y,y),c);
                d=gcd(x-y+n,n);
            }while(d==1);
            if(d<n) return d;
        }
    }
    inline static vector<u64> factor(const u64& n, bool is_root) {
        if(n <= 1) return {};
        u64 p = rho(n);
        if(p == n) return {p};
        auto l = factor(p, false);
        auto r = factor(n / p, false);
        copy(r.begin(), r.end(), back_inserter(l));
		if(is_root) sort(l.begin(),l.end());
        return l;
    }
    inline static constexpr bool miller_rabin(const u64 n) {
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n%2 == 0) return false;
        if(n == 3) return true;
        if(n%3 == 0) return false;
        if(n < 4759123141ULL) return miller_rabin_montgomery(n, ar1);
		if(n <= 1000'000'000'000'000'000ULL) miller_rabin_montgomery(n, ar2); //'
        return miller_rabin_uint128(n, ar2);
    }
    inline static vector<pair<u64,u64>> factorization_impl(const u64 n) {
		// queue<u64> q; q.push(n);
		// vector<u64> v;
		// while(q.size()) {
		// 	u64 tn = q.front(); q.pop();
		// 	if(tn<=1) continue;
		// 	u64 p = rho(tn);
		// 	if(p!=tn) q.push(p),q.push(tn/p);
		// 	else v.push_back(p);
		// }
        auto v = factor(n, true);
        vector<pair<u64,u64>> vp;
        u64 prev = 0;
        for(u64& p:v) {
            if(p == prev) vp.back().second++;
            else vp.emplace_back(p,1);
            prev=p;
        }
        return vp;
    }
    inline static vector<u64> divisor_impl(const u64 n) {
        auto fac = factorization_impl(n);
        vector<u64> res = {1};
        for(auto& [p,m]: fac) {
            u32 sz = res.size();
            for(u32 i=0;i<sz;++i) {
                u64 d = 1;
                for(u32 j=0;j<m;++j) {
                    d *= p;
                    res.push_back(res[i]*d);
                }
            }
        }
        return res;
    }
    inline static long long baby_step_giant_step(long long a, long long b, long long mod, const bool is_include_zero) {
        a %= mod, b%= mod;
        if(mod==1) return is_include_zero ? 0 : 1;
        if(b==1 && is_include_zero) return 0;
        if(a==0) return (b==0 ? 1:-1);

        long long offset=0, c = 1 % mod;
        for(long long g; g=gcd(a,mod); ++offset, b /= g, mod /= g, (c *= (a/g)) %= mod) {
            if(g==1) break;
            if(b == c) {
                if(offset) return offset;
                else if(is_include_zero) return offset;
            }
            if(b % g) return -1;
        }

        long long sm = sqrtl(mod)+1;
        //{a^0, a^1, ... a^sm} % mod
        unordered_map<long long, long long> pow_a;
        for(long long i = !is_include_zero, d = b; i <= sm; ++i, (d*=a)%=mod) {
            pow_a[d]=i;
        }
        long long e = pow_int64(a,sm,mod);
        for(long long i = 1, d = (c*e) % mod; i <= sm; ++i, (d*=e)%=mod) {
            if(pow_a.count(d)) return i * sm - pow_a[d] + offset + !is_include_zero;
        }
        return -1;
    }
public:
    inline static constexpr bool is_prime(const u64 n) { return miller_rabin(n); }
	//{素因数,個数}のvectorが返却される
    inline static vector<pair<u64,u64>> factorization(const u64 n) {return factorization_impl(n);}
	//素因数が愚直に昇順で返却される
    inline static vector<u64> factor(const u64 n) {return factor(n, true);}
    //約数が昇順で列挙される
    inline static vector<u64> divisor(const u64 n) {return divisor_impl(n); }
    inline static constexpr long long gcd(long long n, long long m) { return (n>m ? pre(n,m) : pre(m,n));}
    inline static constexpr long long naive_gcd(long long a, long long b) { return (b ? naive_gcd(b, a % b):a);}
    inline static constexpr long long lcm(long long a, long long b) {return (a*b ? (a / gcd(a, b)*b): 0);}
    //ax+by=gcd(a,b)
    inline static constexpr long long ext_gcd(long long a, long long b, long long &x, long long &y) {
        if (b == 0) return x = 1, y = 0, a; long long d = ext_gcd(b, a%b, y, x); return y -= a / b * x, d;
    }
    //a^x = b (% mod) なる xを求める
    inline static long long discrete_logarithm(long long a, long long b, long long mod, bool is_include_zero=1) {return baby_step_giant_step(a,b,mod,is_include_zero);}
};