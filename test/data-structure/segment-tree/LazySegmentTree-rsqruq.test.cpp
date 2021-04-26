#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <vector>
#include <iostream>
using namespace std;
#include "../../../lib/data-structure/segment-tree/LazySegmentTree.cpp"
#include "../../../lib/operator/monoid-lazy/MonoidRangeSumRangeUpdate.cpp"
int main(void){
	int N,Q; cin >> N >> Q;
	LazySegmentTree<MonoidRangeSumRangeUpdate<long long,long long>> Seg(N,0);
	while(Q--) {
		int q,s,t,x;
		cin >> q >> s >> t;
		t++;
		if(q){
			cout << Seg.fold(s,t) << endl;
		}
		else {
			cin >> x;
			Seg.operate(s,t,x);
		}
	}
	return 0;
}