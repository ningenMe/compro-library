#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;
#include "../../lib/30-math/Quotient.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    long long N; cin >> N;
    auto vp = Quotient(N);
    int M = vp.size();
    cout << M << "\n";
    for(int i = 0; i<M; ++i) cout << vp[i].first << " \n"[i==M-1];
	return 0;
}