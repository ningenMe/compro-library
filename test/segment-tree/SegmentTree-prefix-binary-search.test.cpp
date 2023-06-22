#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
#include <cassert>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
#include "../../lib/10-segment-tree/SegmentTree.cpp"
#include "../../lib/30-math/Prime.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeGcdPointUpdate.cpp"

// solution by binary search in prefix range on segment tree 
int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<MonoidRangeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		ans += N - seg.prefix_binary_search(i,N,1);
	}
	cout << ans << endl;
}
