#define PROBLEM "https://yukicoder.me/problems/no/872"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/graph/Graph.cpp"
#include "../../lib/graph/Tree.cpp"

int main(void){
    int N;
	cin >> N;
	Graph<long long> g(N);
	for(int i = 0; i < N-1; ++i){
		int u,v,w;
		cin >> u >> v >> w;
		u--,v--;
		g.make_bidirectional_edge(u,v,w);
	}
	auto tree = Tree<TreeOperator<long long>>::builder(g).root(0).child().subtree_size().build();
	long long ans = 0;
	for(int pa:tree.order) for(auto e:tree.child[pa]) ans += e.second*tree.subtree_size[e.first]*(N-tree.subtree_size[e.first])*2LL;
	cout << ans << endl;
	return 0;
}