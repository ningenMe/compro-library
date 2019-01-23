#include <bits/stdc++.h>
using namespace std;

//Pow_Mod O(log(N))
long long Pow_Mod(long long x, long long n, long long mod) {
    long long res = 1;
    for (; n > 0; n >>= 1, (x *= x) %= mod) if (n & 1) (res *= x) %= mod;
    return res;
}

//Permutation_Mod O(N^2)
vector<vector<long long>> Permutation_Mod(long long N, long long mod) {
    vector<long long> fac(N + 1, 1);
    for (long long i = 1; i <= N; ++i) fac[i] = (fac[i - 1] * i) % mod;
    vector<long long> inv(N + 1, 1);
    for (long long i = 1; i <= N; ++i) inv[i] = Pow_Mod(fac[i], mod - 2, mod);
    vector<vector<long long>> res(N + 1, vector<long long>(N + 1, 1));
    for (long long i = 1; i <= N; ++i) for (long long j = 1; j <= i; ++j) res[i][j] = (fac[i] * inv[i - j]) % mod;
    return res;
}

//verify https://atcoder.jp/contests/arc067/tasks/arc067_c