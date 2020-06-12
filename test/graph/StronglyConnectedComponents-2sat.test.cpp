#define PROBLEM "https://yukicoder.me/problems/no/1078"
#define IGNORE

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#include "../../lib/graph/StronglyConnectedComponents.cpp"

int main(){
	int N; cin >> N;
	//[0,N*N)       i番目は0
	//[N*N,2*N*N)   i番目は1
	StronglyConnectedComponents scc(N*N,1);
	vector<int> S(N),T(N),U(N);
	for(int i = 0; i < N; ++i) cin >> S[i],S[i]--;
	for(int i = 0; i < N; ++i) cin >> T[i],T[i]--;
	for(int i = 0; i < N; ++i) cin >> U[i];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			int a=S[i],b=j,c=j,d=T[i];
			int s=a*N+b,t=c*N+d;
			if(U[i]==0) {
				//ab=0&&cd=0がだめ
				scc.make_condition(s,0,t,1);
			}
			if(U[i]==1) {
				//ab=1&&cd=0がだめ
				scc.make_condition(s,1,t,1);
			}
			if(U[i]==2) {
				//ab=0&&cd=1がだめ
				scc.make_condition(s,0,t,0);
			}
			if(U[i]==3) {
				//ab=1&&cd=1がだめ
				scc.make_condition(s,1,t,0);
			}
		}
	}
	int flg = scc.solve();
	if(!flg){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cout << scc.is_true(i*N+j) << " ";
		}
		cout << endl;
	}

	return 0;
}
