#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticalTransform.cpp"
#include "../../lib/math/FormalPowerSeries.cpp"
constexpr long long MOD = 998244353;
using fps = FormalPowerSeries<ModInt<MOD>>;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ModInt<MOD>> X(N),Y(N);
    for(int i=0;i<N;++i) cin >> X[i];
    for(int i=0;i<N;++i) cin >> Y[i];
    auto f = fps::interpolation(X,Y);
    for(int i=0;i<N;++i) cout << f[i] << " \n"[i==N-1];
    return 0;
}