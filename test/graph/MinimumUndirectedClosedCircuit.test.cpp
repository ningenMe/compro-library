#define PROBLEM "https://yukicoder.me/problems/no/13"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <array>

using namespace std;
#include "../../lib/40-graph/Graph.cpp"
#include "../../lib/15-queue/RadixHeap.cpp"
#include "../../lib/40-graph/MinimumUndirectedClosedCircuit.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int W,H; cin >> W >> H;
    Graph<int> g(H,W);
    vector<int> a(W),b(W);
    {
        for(int j=0;j  <W;++j) cin >> a[j];
        for(int j=0;j+1<W;++j) if(a[j]==a[j+1]) g.make_bidirectional_edge({0,j},{0,j+1},1);        
    }
    for(int i=1;i<H;++i) {
        b=a;
        for(int j=0;j  <W;++j) cin >> a[j];
        for(int j=0;j  <W;++j) if(b[j]==a[j]) g.make_bidirectional_edge({i,j},{i-1,j},1);
        for(int j=0;j+1<W;++j) if(a[j]==a[j+1]) g.make_bidirectional_edge({i,j},{i,j+1},1);
    }
    int inf = 12345678;
    MinimumUndirectedClosedCircuit<int> mucc(g,inf);
    int flg = 0;
    for(int i=0;i<H;++i) for(int j=0;j<W;++j) {
        int sz = mucc.solve(g.idx({i,j}));
        if(sz < inf) flg = 1;
    }
    cout << (flg?"possible":"impossible") << endl;
	return 0;
}
