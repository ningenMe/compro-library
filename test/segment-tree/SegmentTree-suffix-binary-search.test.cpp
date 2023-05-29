#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/10-segment-tree/SegmentTree.cpp"
#include "../../lib/30-math/Gcd.cpp"
#include "../../../lib/operator/monoid/MonoidRangeGcdPointUpdate.cpp"

// solution by binary search in prefix range on segment tree 
int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<MonoidRangeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = N-1; 0 <= i; --i) {
		ans += seg.suffix_binary_search(-1,i,1) + 1;
	}
	cout << ans << endl;
}