#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../../lib/30-math/Gcd.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
	Prime p;
    for(int i = 0; i < N; ++i) {
		long long A; cin >> A;
		cout << A << " " << p.miller_rabin(A) << "\n";
	}
	return 0;
}