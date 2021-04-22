#define PROBLEM "https://yukicoder.me/problems/no/399"

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
#include "../../lib/segment/LazySegmentTree.cpp"

int main(void){
	int N; cin >> N;
	Graph<int> g(N);
	for(int i=0;i<N-1;++i) {
		int u,v; cin >> u >> v;
		u--,v--;
		g.make_bidirectional_edge(u,v,1);
	}
	auto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();
	LazySegmentTree<NodeSumRangeAdd<long long,long long>> seg(N);
	int Q; cin >> Q;
	long long ans = 0;
	while(Q--) {
		int a,b; cin >> a >> b;
		a--,b--;
		auto vp = tree.vertex_set_on_path(a,b);
		for(auto& p:vp) {
			int l = p.first, r = p.second+1;
			int n = r-l;
			ans += seg.get(l,r)+n;
			seg.update(l,r,1);
		}
	}
	cout << ans << endl;
   return 0;
}