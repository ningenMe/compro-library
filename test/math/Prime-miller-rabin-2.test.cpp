#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int Q; read(Q);
    while(Q--) {
        unsigned long long n; read(n);
        cout << (Prime::is_prime(n) ? "Yes" : "No") << "\n";
	}
	return 0;
}
