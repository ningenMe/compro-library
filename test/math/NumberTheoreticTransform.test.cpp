#define PROBLEM "https://yukicoder.me/problems/no/718"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/math/NumberTheoreticTransform.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
    vector<long long> A(N+1),B(N+1);
    for(int i = 0; i < N+1; ++i) cin >> A[i];
    for(int i = 0; i < N+1; ++i) cin >> B[i];
    auto C = NumberTheoreticTransform<MOD>::convolution_arbitrarymod(A,B);
    long long ans = 0;
    for(int i = 0; i <= N; ++i) (ans += C[i]) %= MOD;
    cout << ans << endl;
	return 0;
}