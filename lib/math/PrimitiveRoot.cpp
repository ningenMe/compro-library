/*
 * @title PrimitiveRoot - 原始根
 * @docs md/math/PrimitiveRoot.md
 */
class PrimitiveRoot{
    inline static constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
        if (m == 1) return 0;
        unsigned int _m = (unsigned int)(m);
        unsigned long long r = 1;
        unsigned long long y = x;
        y %= m;
        if(x < 0) x += m;
        while (n) {
            if (n & 1) r = (r * y) % _m;
            y = (y * y) % _m;
            n >>= 1;
        }
        return r;
    }
public:
    inline static long long root(long long p) {
        if(p == 2) return 1;
        if(p == 167772161) return 3;
        if(p == 469762049) return 3;
        if(p == 754974721) return 11;
        if(p == 998244353) return 3;
        if(p == 1000000007) return 5;
        if(p == 1004535809) return 3;
        array<int,20> divs;
        divs[0] = 2;
        int cnt = 1;
        int x = (p - 1) >> 1;
        while (!(x&1)) x >>= 1;
        for (long long i = 3; i*i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) {
            divs[cnt++] = x;
        }
        for (int g = 2;; ++g) {
            bool ok = true;
            for (int i = 0; i < cnt; i++) {
                if (pow_mod_constexpr(g, (p - 1) / divs[i], p) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) return g;
        }        
    }
};
