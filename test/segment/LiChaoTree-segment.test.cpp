#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/segment/LiChaoTree.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int length,Q; cin >> length >> Q;
	vector<long long> A(length),B(length),L(length),R(length),E(Q),F(Q),C(Q),D(Q),S(Q),TypeValue(Q);
	for(int i = 0; i < length; ++i) {
		cin >> L[i] >> R[i] >> A[i] >> B[i];
	}
	LiChaoTree<ValueMin<long long>> lct;
	for(int i = 0; i < length; ++i) lct.x_push_back(L[i]),lct.x_push_back(R[i]);
	for(int i = 0; i < Q; ++i) {
		cin >> E[i];
		if(E[i]) {
			cin >> F[i];
			lct.x_push_back(F[i]);
		}
		else {
			cin >> S[i] >> TypeValue[i] >> C[i] >> D[i];
			lct.x_push_back(S[i]);
			lct.x_push_back(TypeValue[i]);
		}
	}
	lct.build();
	long long inf = 3e18;
	for(int i = 0; i < length; ++i) lct.update({A[i],B[i]},L[i],R[i]);
	for(int i = 0; i < Q; ++i) {
		if(E[i]) {
			long long ans = lct.get(F[i]);
			if(ans!=inf) cout << ans << endl;
			else cout << "INFINITY" << endl;
		}
		else {
			lct.update({C[i],D[i]},S[i],TypeValue[i]);
		}
	}
}