#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <vector>
#include <iostream>
using namespace std;
#include "../../../lib/data-structure/segment-tree/LazySegmentTree.cpp"
#include "../../../lib/operator/monoid-lazy/MonoidRangeMinRangeAdd.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	long inf = 1234567890LL;
	LazySegmentTree<MonoidRangeMinRangeAdd<long long,long long>> Seg(N,0LL);
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