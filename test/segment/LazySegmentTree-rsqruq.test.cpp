#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/LazySegmentTree.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	LazySegmentTree<NodeSumRangeUpdate<long long,long long>> Seg(N,0);
	while(Q--) {
		int q,s,t,x;
		cin >> q >> s >> t;
		t++;
		if(q){
			cout << Seg.get(s,t) << endl;
		}
		else {
			cin >> x;
			Seg.update(s,t,x);
		}
	}
	return 0;
}