#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/40-graph/Graph.cpp"
#include "../../lib/40-graph/Tree.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    Graph<int> g(N);
    for(int i=1;i<N;++i) {
        int p; cin >> p;
        g.make_bidirectional_edge(i,p,1);
    }
    auto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().ancestor().build();
    while(Q--) {
        int u,v; cin >> u >> v;
        cout << tree.lca(u,v).first << "\n";
    }
  	return 0;
}