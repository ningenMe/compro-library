#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/segment/LiChaoTree.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q; cin >> N >> Q;
	vector<long long> A(N),B(N),C(Q),D(Q),E(Q);
	for(int i = 0; i < N; ++i) cin >> A[i] >> B[i];
	LiChaoTree<ValueMin<long long>> lct;
	for(int i = 0; i < Q; ++i) {
		cin >> C[i];
		if(C[i]) {
			cin >> D[i];
			lct.x_push_back(D[i]);
		}
		else {
			cin >> D[i] >> E[i];
		}
	}
	lct.build();
	for(int i = 0; i < N; ++i) lct.update({A[i],B[i]});
	long long inf = 3e18;
	for(int i = 0; i < Q; ++i) {
		if(C[i]) {
			long long ans = lct.get(D[i]);
			if(ans!=inf) cout << ans << endl;
			else cout << "INFINITY" << endl;
		}
		else {
			lct.update({D[i],E[i]});
		}
	}
}