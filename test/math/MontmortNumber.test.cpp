#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/RuntimeModInt.cpp"
#include "../../lib/30-math/MontmortNumber.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,M; read(N), read(M);
    runtime_mod = M;
    auto ar = MontmortNumber<RuntimeModInt<runtime_mod>>::get(N);
    for(int i=1;i<=N;++i) cout << ar[i] << " \n"[i==N];
    return 0;
}