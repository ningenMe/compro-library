#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "../../../lib/binary-search-tree/RandomizedBinarySearchTree.cpp"
#include "../../../lib/operator/operator/ValueMin.cpp"
#include "../../../lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
	ConvexHullTrick<ValueMin<__int128_t>> cht;
	while(N--){
		long long a,b; cin >> a >> b;
		cht.insert(a,b);
	}
	while(Q--){
		int q; cin >> q;
		if(q){
			long long p; cin >> p;
			long long ans = cht.get(p);
			cout << ans << endl;
		}
		else{
			long long a,b; cin >> a >> b;
			cht.insert(a,b);
		}
	}
	return 0;
}