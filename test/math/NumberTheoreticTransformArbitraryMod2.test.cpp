#define PROBLEM "https://yukicoder.me/problems/no/754"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticTransform.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    vector<ModInt<MOD>> A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) cin >> A[i];
    for(int i = 0; i < N+1; ++i) cin >> B[i];
    NumberTheoreticTransform<MOD> ntt;
    auto C = ntt.convolution(A,B);
    ModInt<MOD> ans = 0;
    for(int i = 0; i <= N; ++i) ans += C[i];
    cout << ans << endl;
	return 0;
}