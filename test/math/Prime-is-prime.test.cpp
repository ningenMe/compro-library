#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
using namespace std;
#include "../../lib/math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
    for(int i = 0; i < N; ++i) {
		long long A; cin >> A;
		cout << A << " " << Prime::is_prime(A) << "\n";
	}
	return 0;
}