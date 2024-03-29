#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

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
    vector<ModInt<MOD_998244353>> X(N),Y(N);
    for(int i=0;i<N;++i) {
        int a; read(a);
        X[i]=a;
    }
    for(int i=0;i<N;++i) {
        int a; read(a);
        Y[i]=a;
    }
    auto f = FormalPowerSeries<MOD_998244353>::interpolation(X,Y);
    for(int i=0;i<N;++i) cout << f[i] << " \n"[i==N-1];
    return 0;
}