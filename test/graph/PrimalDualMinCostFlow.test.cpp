#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <vector>
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/40-graph/PrimalDualMinCostFlow.cpp"

int main() {
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M,F;
    read(N),read(M),read(F);
    PrimalDualMinCostFlow<int,int> pdmcf(N, 123456789);
    for(int i=0;i<M;++i) {
        int u,v,c,d;
        read(u),read(v),read(c),read(d);
        pdmcf.make_edge(u,v,c,d);
    }
    auto [flow,cost] = pdmcf.min_cost_flow(0,N-1,F);
    if(flow < F) cost = -1;
    cout << cost << endl;
    return 0;
}