#define PROBLEM "https://yukicoder.me/problems/no/754"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticalTransform.cpp"
#include "../../lib/math/FormalPowerSeries.cpp"
constexpr long long MOD = 1000'000'007;
using fps = FormalPowerSeries<ModInt<MOD>>;
int main(void){
    int N; cin >> N;
    fps A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) cin >> A[i];
    for(int i = 0; i < N+1; ++i) cin >> B[i];
    fps C = fps::mul(A,B), D({1,-1});
    cout << fps::nth_term(N,C,D) << endl;
	return 0;
}