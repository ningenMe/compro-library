#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596"

#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/heap/RadixHeapInt.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,K; cin >> N >> K;
	vector<int> C(N),R(N);
	for(int i = 0; i < N; ++i) cin >> C[i] >> R[i];
	vector<vector<int>> edge(N);
	for(int i = 0; i < K; ++i) {
		int A,B; cin >> A >> B;
		A--,B--;
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	vector<vector<int>> dp(N,vector<int>(N+1,1<<30));
	dp[0][0] = 0;
	RadixHeapInt<pair<int,int>> pq({0,0});
	pq.push({0,{0,0}});
	while(pq.size()){
		auto p = pq.pop();
		int from = p.second.first;
		int r = p.second.second;
		if(r){
			for(int to:edge[from]){
				if(dp[to][r-1]>dp[from][r]){
					dp[to][r-1]=dp[from][r];
					pq.push({dp[to][r-1],{to,r-1}});
				}
			}
		}
		if(dp[from][R[from]]>dp[from][r]+C[from]){
			dp[from][R[from]]=dp[from][r]+C[from];
			pq.push({dp[from][R[from]],{from,R[from]}});
		}
	}
	cout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;
	return 0;
}