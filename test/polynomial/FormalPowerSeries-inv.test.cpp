#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/util/ModInt.cpp"
#include "../../lib/convolution/NumberTheoreticalTransform.cpp"
#include "../../lib/polynomial/FormalPowerSeries.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N; read(N);
    FormalPowerSeries<MOD_998244353> f(N);
    for(int i=0;i<N;++i) {
        int a; read(a); f[i]=a;
    }
    f = f.inv();
    for(int i=0;i<f.size();++i) cout << f[i] << " \n"[i==N-1];
    return 0;
}
