#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../../lib/data-structure/segment-tree/SegmentTree.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q; cin >> N >> Q;
	SegmentTree<NodeSumPointAdd<long long>> Seg(N,0);
	while(Q--){
		int q; cin >> q;
		if(q==0){
			int x,y; cin >> x >> y;
			x--;
			Seg.update(x,y);
		}
		else{
			int x,y; cin >> x >> y;
			x--;
			cout << Seg.get(x,y) << endl;
		}
	}
}