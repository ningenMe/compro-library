#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticalTransform.cpp"
constexpr long long MOD = 998244353;

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<ModInt<MOD>> A(N),B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
	auto C = NumberTheoreticalTransform<ModInt<MOD>>::convolution(A,B);
    for(int i = 0; i < N+M-1; ++i) cout << C[i] << " ";
    cout << endl;
	return 0;
}
