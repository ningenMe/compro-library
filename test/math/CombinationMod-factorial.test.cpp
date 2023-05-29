#define PROBLEM "https://yukicoder.me/problems/no/916"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/30-math/CombinationMod.cpp"
#include "../../lib/00-util/ModInt.cpp"
constexpr long long MOD = 1000'000'007;
using modint = ModInt<MOD>;

int main(void){
	int d, l, r, k;
    int MAX_d = 20;
	cin >> d >> l >> r >> k;
    CombinationMod<MOD> CM((1<<MAX_d));
    vector<int> sum(MAX_d + 1, 0);
	vector<long long> pow2(MAX_d + 1,1);
	for (int i = 2; i <= MAX_d; ++i) pow2[i] = (pow2[i - 1] * 2) % MOD;
	for (int i = 1; i < MAX_d + 1; ++i) sum[i] = sum[i - 1] + pow2[i];
	l = lower_bound(sum.begin(), sum.end(), l) - sum.begin();
	r = lower_bound(sum.begin(), sum.end(), r) - sum.begin();

	int lca = -1;
	if ((l + r - k) > 1 && (l + r - k) % 2 == 0) lca = (l + r - k) / 2;
	if(lca == -1 || lca > l || lca > r){
		cout << 0 << endl;
		return 0;
	}
	modint ans = 1;
	for (int i = 1; i <= d; ++i) {
		int cnt = pow2[i];
		if (i == l) cnt--;
		if (i == r) cnt--;
		ans *= CM.factorial(cnt);
	}
	ans *= pow2[lca];
	ans *= pow2[l - lca];
	ans *= pow2[r - lca];
	ans *= 2;

	cout << ans << endl;
	return 0;}