#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;
#include "../../lib/40-graph/StronglyConnectedComponents.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N);
    while(M--) {
        int u,v; cin >> u >> v;
        scc.make_edge(u,v);
    }
    scc.solve();
    auto vv=scc.topological_sort();
    cout << vv.size() << "\n";
    for(auto& v:vv) {
        cout << v.size();
        for(auto& e:v) cout << " " << e;
        cout << "\n";
    }
    return 0;
}
