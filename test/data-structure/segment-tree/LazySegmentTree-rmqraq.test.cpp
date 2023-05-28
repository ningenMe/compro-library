#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <vector>
#include <iostream>
using namespace std;
#include "../../../lib/data-structure/segment-tree/LazySegmentTree.cpp"
#include "../../../lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateAdd.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	long inf = 1234567890LL;
	LazySegmentTree<MonoidRangeFoldMinRangeOperateAdd<long long,long long>> seg(N,0LL);
	while(Q--) {
		int q,s,t,x;
		cin >> q >> s >> t;
		t++;
		if(q){
			cout << seg.fold(s,t) << endl;
		}
		else {
			cin >> x;
			seg.operate(s,t,x);
		}
	}
	return 0;
}