#include <bits/stdc++.h>
using namespace std;

//Combination Mod
class Combination_Mod {
public:
	vector<long long> fac,finv,inv;
	long long MOD;

	Combination_Mod(int N,long long mod) : fac(vector<long long>(N + 1)), finv(vector<long long>(N + 1)), inv(vector<long long>(N + 1)), MOD(mod) {
		fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
		for (int i = 2; i <= N; ++i) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}
	
	long long num(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : fac[n] * (finv[k] * finv[n - k] % MOD) % MOD);
	}
};

//verify https://atcoder.jp/contests/abc021/tasks/abc021_d