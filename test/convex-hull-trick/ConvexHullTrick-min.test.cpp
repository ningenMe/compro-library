#define PROBLEM "https://yukicoder.me/problems/no/409"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "../../lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp"
#include "../../lib/99-operator/operator/ValueMin.cpp"
#include "../../lib/16-convex-hull-trick/ConvexHullTrick.cpp"
using ll = long long;

int main(void){
	ll N,A,B,W; cin >> N >> A >> B >> W;
	vector<ll> D(N+2,0);
	for(int i = 1; i <= N; ++i) cin >> D[i];
	// dp[i]=min{j:[0,i)}-> dp[j]+B*k*(k+1)/2-k*A+D[i] (k=i-j-1)
	//                   -> dp[j]+B*(i-j-1)*(i-j)/2-(i-j-1)*A+D[i]
	//                   -> dp[j]+B/2*(i*i-2*i*j+j*j-i+j)-A*(i-j-1)+D[i]
	//                   -> (-B*j)*i  +  dp[j]+B/2*(j*j+j)+A*j  +  B/2*(i*i-i)-A*(i-1)+D[i] 
	ll dp=W;
	ConvexHullTrick<ValueMin<ll>> cht;
	cht.insert(0,dp);
	for(ll i=1;i<=N+1;++i){
		dp=cht.get(i)+B*(i*i-i)/2-A*(i-1)+D[i];
		pair<ll,ll> line={-B*i,dp+B*(i*i+i)/2+A*i};
		cht.insert(line);
	}
	cout << dp << endl;
	return 0;
}