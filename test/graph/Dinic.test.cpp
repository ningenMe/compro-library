#define PROBLEM "https://yukicoder.me/problems/no/904"

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "../../lib/40-graph/Dinic.cpp"

int main() {
	int N; cin >> N;
	vector<int> A(N),B(N);
	for(int i = 1; i < N; ++i) cin >> A[i] >> B[i];
	Dinic<int>  dinic(2*N,0,1234567);
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j < N; ++j) {
			if(i==j) continue;
			dinic.make_edge(i,j+N,1234567);
		}
	}
	for(int i = 1; i < N; ++i) dinic.make_edge(0,i,A[i]);
	for(int i = 1; i < N; ++i) dinic.make_edge(i+N,N,B[i]);
	cout << dinic.maxflow(0,N)+1 << endl;
    return 0;
}