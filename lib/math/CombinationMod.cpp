/*
 * @title CombinationMod - mod上の二項係数・階乗
 * @docs md/math/CombinationMod.md
 */
template<long long mod> class CombinationMod {
    vector<long long> fac,finv,inv;
public:
    CombinationMod(int N) : fac(N + 1), finv(N + 1), inv(N + 1) {
        fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i = 2; i <= N; ++i) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    inline long long binom(int n, int k) {
        return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % mod) % mod);
    }
    inline long long factorial(int n) {
        return fac[n];
    }
};

//verify https://atcoder.jp/contests/abc021/tasks/abc021_d