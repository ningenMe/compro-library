#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SegmentTree.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	SegmentTree<nodeSumPointAdd<long long>> Seg(N,0);
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