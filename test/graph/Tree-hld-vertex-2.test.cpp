#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <map>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/graph/Graph.cpp"
#include "../../lib/graph/Tree.cpp"
#include "../../lib/data-structure/segment-tree/SegmentTree.cpp"
#include "../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
	int N,Q; cin >> N >> Q;
	Graph<int> g(N);
	vector<long long> a(N);
	for(int i=0;i<N;++i) cin >> a[i];
	for(int i=0;i<(N-1);++i){
		int u,v; cin >> u >> v;
		g.make_bidirectional_edge(u,v,1);
	}
	auto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();
	SegmentTree<MonoidRangeSumPointAdd<long long>> seg(N);
	for(int i=0;i<N;++i) seg.operate(tree.hld[i],a[i]);
	while(Q--){
		int q,s,t; cin >> q >> s >> t;
		if(q) {
			long long ans=0;
			auto v = tree.vertex_set_on_path(s,t);
			for(auto& e:v) ans += seg.fold(e.first,e.second+1);
			cout << ans << endl;
		}
		else {
			seg.operate(tree.hld[s],t);
		}
	}
    return 0;
}