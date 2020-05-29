#define PROBLEM "https://yukicoder.me/problems/448"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/math/Garner.cpp"
constexpr long long MOD = 1000'000'007;

int main(void){
    int N; cin >> N;
	vector<long long> b(N), m(N);
	int flg = 1;
	for(int i = 0; i < N; ++i){
		cin >> b[i] >> m[i];
		if(b[i]) flg = 0;
	}
	auto [r,lcm]=Garner<MOD>::garner(b,m);
	long long ans = r;
	if(flg) ans = lcm;
	cout << ans << endl;
	return 0;
}