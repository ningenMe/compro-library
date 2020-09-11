#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/segment/SegmentTree.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q; cin >> N >> Q;
	SegmentTree<NodeMinPointUpdate<long long>> Seg(N);
	while(Q--){
		long long q,a,b;
		cin >> q >> a >> b;
		if(q) cout << Seg.get(a,b+1) << endl;
		else Seg.update(a,b);
	}
	return 0;
}