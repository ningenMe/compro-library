#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/10-segment-tree/SegmentTree.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeMinPointUpdate.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q; cin >> N >> Q;
	SegmentTree<MonoidRangeMinPointUpdate<long long>> Seg(N);
	while(Q--){
		long long q,a,b;
		cin >> q >> a >> b;
		if(q) cout << Seg.fold(a,b+1) << endl;
		else Seg.operate(a,b);
	}
	return 0;
}