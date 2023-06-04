#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
#include <queue>
#include <cassert>
#include <unordered_map>

using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/31-convolution/NumberTheoreticalTransform.cpp"
#include "../../lib/30-math/CombinationMod.cpp"
#include "../../lib/32-polynomial/FormalPowerSeries.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N; read(N);
    FormalPowerSeries<MOD_998244353> f(N);
    for(int i=0;i<N;++i) {
        int a; read(a);
        f[i]=a;
    }
    f = f.exp();
    for(int i=0;i<f.size();++i) cout << f[i] << " \n"[i==N-1];
    return 0;
}