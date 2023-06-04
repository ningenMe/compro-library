#define PROBLEM "https://yukicoder.me/problems/no/754"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/31-convolution/NumberTheoreticalTransform.cpp"
#include "../../lib/32-polynomial/FormalPowerSeries.cpp"

int main(void){
    int N; read(N);
    FormalPowerSeries<MOD_1000000007> A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) {
        int a; read(a);
        A[i]=a;
    }
    for(int i = 0; i < N+1; ++i) {
        int a; read(a);
        B[i]=a;
    }
    FormalPowerSeries<MOD_1000000007> C = FormalPowerSeries<MOD_1000000007>::mul(A,B), D({1,-1});
    cout << FormalPowerSeries<MOD_1000000007>::nth_term(N,C,D) << "\n";
	return 0;
}