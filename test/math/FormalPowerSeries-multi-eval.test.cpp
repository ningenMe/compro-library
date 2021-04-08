#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

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
    int N,M; cin >> N >> M;
    fps C(N);
    vector<ModInt<MOD>> P(M);
    for(int i=0;i<N;++i) cin >> C[i];
    for(int i=0;i<M;++i) cin >> P[i];
    P = C.multipoint_evaluation(P);
    for(int i=0;i<M;++i) cout << P[i] << " \n"[i==M-1];
    return 0;
}