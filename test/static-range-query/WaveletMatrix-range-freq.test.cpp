#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;

#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/13-static-range-query/WaveletMatrix.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N); read(Q);
    vector<long long> A(N);
    for(int i=0;i<N;++i) read(A[i]);
    WaveletMatrix<long long> wm(A);
    while(Q--) {
        int l,r,k; read(l); read(r); read(k);
		cout << wm.range_freq(l,r,k) << "\n";
    }
    return 0;
}