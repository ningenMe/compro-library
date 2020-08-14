#define PROBLEM "https://yukicoder.me/problems/no/1161"

#include <vector>
#include <iostream>
#include <array>
#include <numeric>
using namespace std;
#include "../../lib/util/Mod.cpp"

int main() {
	long long A,B,C;
	scanf("%lld%lld%lld",&A,&B,&C);
	long long ans = 0;
	array<long long,100001> cnt;
	for(long long i = 1; i <= C; ++i) {
		cnt[i] = Mod::pow(i,B,C);
	}
	for(long long i = 1; i <= A%C; ++i) {
		ans += cnt[i];
	}
	ans += (accumulate(cnt.begin(),cnt.begin()+C,0LL)%C)*(A/C);
	printf("%lld\n",ans%C);
    return 0;
}
