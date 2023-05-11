#define PROBLEM "https://yukicoder.me/problems/448"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/math/Garner.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
	vector<long long> b(N), m(N);
	for(int i = 0; i < N; ++i){
		cin >> b[i] >> m[i];
	}
	cout << Garner::garner(b,m,MOD) << endl;
	return 0;
}