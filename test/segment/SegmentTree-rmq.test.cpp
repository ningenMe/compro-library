#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SegmentTree.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	SegmentTree<nodeMinPointUpdate<long long>> Seg(N);
	while(Q--){
		long long q,a,b;
		cin >> q >> a >> b;
		if(q) cout << Seg.get(a,b+1) << endl;
		else Seg.update(a,b);
	}
	return 0;
}