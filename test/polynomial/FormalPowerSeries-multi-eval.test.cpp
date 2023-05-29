#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/31-convolution/NumberTheoreticalTransform.cpp"
#include "../../lib/32-polynomial/FormalPowerSeries.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,M; read(N);
    FormalPowerSeries<MOD_998244353> C(N);
    vector<ModInt<MOD_998244353>> P(M);
    for(int i=0;i<N;++i) {
        int a; read(a);
        C[i]=a;
    }
    for(int i=0;i<M;++i) {
        int a; read(a);
        P[i]=a;
    }
    P = C.multipoint_evaluation(P);
    for(int i=0;i<M;++i) cout << P[i] << " \n"[i==M-1];
    return 0;
}