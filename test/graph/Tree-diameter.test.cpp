#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

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
    cin.tie(0);ios::sync_with_stdio(false);
	int N; cin >> N;
	Graph<long long> g(N);
	for(int i=1;i<N;++i){
		int u,v,w; cin >> u >> v >> w;
		g.make_bidirectional_edge(u,v,w);
	}
	using Op = TreeOperator<long long>;
	auto tree = Tree<Op>::builder(g).build();
	auto p = tree.diameter();
	cout << p.first << " " << p.second.size() << endl;
	for(auto& e:p.second) cout << e << " ";
	cout << endl;
	return 0;
}