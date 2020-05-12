#define PROBLEM "https://yukicoder.me/problems/no/957"

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "../../lib/graph/Dinic.cpp"

int main() {
    int H,W;
    cin >> H >> W;
    vector<long long> R(H),C(W),G(H*W);
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) cin >> G[i*W+j];
    for(int i = 0; i < H; ++i) cin >> R[i];
    for(int j = 0; j < W; ++j) cin >> C[j];
    
	long long ans = 0;
    Dinic<long long> dinic(H+W+2,0,1e15);
    int S = H+W,T = S + 1;
	//i:Sと接続:使う
	//i:Tと接続:使わない
    for(int i = 0; i < H; ++i) {
		long long sum = 0;
		for(int j = 0; j < W; ++j) sum += G[i*W+j];
		ans += R[i];
		if(R[i]>=sum){
			ans -= sum;
		}
		else{
			dinic.make_edge(S,i,sum-R[i]);
			ans -= R[i];
		}
    }
	//j:Sと接続:使う
	//j:Tと接続:使わない
    for(int j = 0; j < W; ++j) {
		ans += C[j];
		dinic.make_edge(H+j,T,C[j]);
    }
	//この供給は常にある
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
			dinic.make_edge(i,H+j,G[i*W+j]);
		}
    }

    ans -= dinic.maxflow(S,T);
    cout << ans << endl;

    return 0;
}