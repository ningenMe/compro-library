#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;
using int128  = __int128_t;
using int64   = long long;
using int32   = int;
using uint128 = __uint128_t;
using uint64  = unsigned long long;
using uint32  = unsigned int;

#include "../../lib/14-data-structure/BitVector.cpp"
#include "../../lib/14-data-structure/WaveletMatrix.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	vector<uint32> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
	WaveletMatrix<uint32> wm(A);
    while(Q--) {
        int l,r; uint32 k;
		cin >> l >> r >> k;
		cout << wm.quantile(l, r, k) << "\n";
	}

    return 0;
}