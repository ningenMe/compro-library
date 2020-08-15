#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/graph/Tree.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
	int N; cin >> N;
	Tree<TreeOperator<long long>> tree(N);
	for(int i=1;i<N;++i){
		int u,v,w; cin >> u >> v >> w;
		tree.make_edge(u,v,w);
		tree.make_edge(v,u,w);
	}
	auto p = tree.diameter();
	cout << p.first << " " << p.second.size() << endl;
	for(auto& e:p.second) cout << e << " ";
	cout << endl;
	return 0;
}