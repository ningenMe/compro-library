#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>
#include <queue>
#include <map>
#include <array>

using namespace std;
#include "../../lib/graph/Graph.cpp"
#include "../../lib/heap/RadixHeap.cpp"
#include "../../lib/graph/MinimumDirectedClosedCircuit.cpp"

int main(){
    int N,M; cin >> N >> M;
    Graph<int> graph(N);
    for(int i = 0; i < M; ++i){
        int u,v; cin >> u >> v;
        graph.make_edge(u,v,1);
    }
    MinimumDirectedClosedCircuit<int> mdcc(graph,1234567);
    int ans = 0;
    int inf = 1234567;
    for(int i = 0; i < N; ++i){
        mdcc.solve(i);
        auto tmp = mdcc.restore();
        if(!tmp.empty()) ans = 1;
    }
    cout << ans << endl;
	return 0;
}
