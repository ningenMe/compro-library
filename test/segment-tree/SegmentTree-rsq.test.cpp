#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/10-segment-tree/SegmentTree.cpp"
#include "../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q; cin >> N >> Q;
	SegmentTree<MonoidRangeSumPointAdd<long long>> Seg(N,0);
	while(Q--){
		int q; cin >> q;
		if(q==0){
			int x,y; cin >> x >> y;
			x--;
			Seg.operate(x,y);
		}
		else{
			int x,y; cin >> x >> y;
			x--;
			cout << Seg.fold(x,y) << endl;
		}
	}
}