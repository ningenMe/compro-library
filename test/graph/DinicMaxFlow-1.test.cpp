#define PROBLEM "https://yukicoder.me/problems/no/904"

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "../../lib/40-graph/DinicMaxFlow.cpp"

int main() {
	int N; cin >> N;
	vector<int> A(N),B(N);
	for(int i = 1; i < N; ++i) cin >> A[i] >> B[i];
	DinicMaxFlow<int>  mf(2*N);
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j < N; ++j) {
			if(i==j) continue;
			mf.make_edge(i,j+N,1234567);
		}
	}
	for(int i = 1; i < N; ++i) mf.make_edge(0,i,A[i]);
	for(int i = 1; i < N; ++i) mf.make_edge(i+N,N,B[i]);
	cout << mf.flow(0,N)+1 << endl;
    return 0;
}