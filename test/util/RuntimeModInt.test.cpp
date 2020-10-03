#define PROBLEM "https://yukicoder.me/problems/no/1161"

#include <vector>
#include <iostream>
#include <array>
#include <numeric>
using namespace std;
#include "../../lib/util/RuntimeModInt.cpp"

int main() {
	long long A,B,C;
	cin >> A >> B >> C;
	mod = C;
	modint ans = 0;
	array<modint,100001> cnt;
	for(long long i = 1; i <= C; ++i) {
		cnt[i] = modint(i).pow(B);
	}
	for(long long i = 1; i <= A%C; ++i) {
		ans += cnt[i];
	}
	ans += accumulate(cnt.begin(),cnt.begin()+C,modint(0))*(A/C);
	cout << ans << "\n";
    return 0;
}
