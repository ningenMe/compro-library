#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SegmentTreeBeats.cpp"

int main(void){
	int N,Q; cin >> N >> Q;
	vector<long long> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	SegmentTreeBeats<long long> seg(A);
	while(Q--){
		long long q,l,r,b;
		cin >> q >> l >> r;
		if(q==3){
			cout << seg.get_sum(l,r) << endl;
		}
		else{
			cin >> b;
			if(q==0) {
				seg.range_chmin(l,r,b);
			}
			if(q==1) {
				seg.range_chmax(l,r,b);
			}
			if(q==2) {
				seg.range_add(l,r,b);
			}
		}
	}
    return 0;
}