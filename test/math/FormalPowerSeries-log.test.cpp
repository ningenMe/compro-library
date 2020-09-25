#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/FormalPowerSeries.cpp"
constexpr long long MOD = 998244353;
using fps = FormalPowerSeries<MOD>;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    fps f(N);
    for(int i=0;i<N;++i) cin >> f[i];
    f = f.log();
    for(int i=0;i<f.size();++i) cout << f[i] << " \n"[i==N-1];
    return 0;
}