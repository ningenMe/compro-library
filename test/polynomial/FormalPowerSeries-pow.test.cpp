#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/FastIO.cpp"
#include "../../lib/util/ModInt.cpp"
#include "../../lib/convolution/NumberTheoreticalTransform.cpp"
#include "../../lib/polynomial/FormalPowerSeries.cpp"


int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,M; read(N);read(M);
    FormalPowerSeries<MOD_998244353> f(N);
    for(int i=0;i<N;++i) {
        int a; read(a);
        f[i]=a;
    }
    f = f.pow(M,N);
    for(int i=0;i<f.size();++i) cout << f[i] << " \n"[i==N-1];
    return 0;
}