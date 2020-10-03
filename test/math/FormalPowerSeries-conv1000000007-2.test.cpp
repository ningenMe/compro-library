#define PROBLEM "https://yukicoder.me/problems/no/754"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/RuntimeModInt.cpp"
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/FormalPowerSeries.cpp"
constexpr long long MOD = 1000'000'007;
using fps = FormalPowerSeries<ModInt<MOD>>;
int main(void){
    int N; cin >> N;
    fps A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) cin >> A[i];
    for(int i = 0; i < N+1; ++i) cin >> B[i];
    auto C = A*B;
    cout << fps::nth_term(N,C,{1,-1}) << endl;
	return 0;
}