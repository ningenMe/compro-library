#define PROBLEM "https://yukicoder.me/problems/4072"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SegmentTree.cpp"
#include "../../lib/math/GreatestCommonDivisor.cpp"

template<class T> struct NodeGcdPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

// solution by binary search in prefix range on segment tree 
int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTree<NodeGcdPointUpdate<long long>> seg(A);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		ans += N - seg.binary_search(i,N,1);
	}
	cout << ans << endl;
}