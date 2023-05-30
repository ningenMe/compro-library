#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; read(N);
    for(int i = 0; i < N; ++i) {
		long long a; read(a);
		cout << a << " " << Prime::is_prime(a) << "\n";
	}
	return 0;
}
