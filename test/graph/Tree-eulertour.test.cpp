#define PROBLEM "https://yukicoder.me/problems/no/900"

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
#include "../../lib/graph/Tree2.cpp"
#include "../../lib/segment/LazySegmentTree.cpp"


//node:総和　lazy:加算
template<class T, class U> struct NodeEulerTourSumRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = {0,0};
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}
	inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};


int main(void){
	int N; cin >> N;
	Graph<long long> g(N);
	for(int i=0;i<N-1;++i) {
		int u,v,w; cin >> u >> v >> w;
		g.make_bidirectional_edge(u,v,w);
	}
	auto tree = Tree<TreeOperator<long long>>::builder(g).root(0).parent().child().eulertour().build();
	int M = tree.eulertour.size();
	vector<pair<long long,long long>> init(M,{0,0});
	for(int i=1;i<M;++i) {
		int l=tree.eulertour[i-1], r = tree.eulertour[i], sgn;
		long long w;
		if(tree.depth[l]<tree.depth[r]) {
			w = tree.parent[r].second;
			sgn = 1;
		}
		else {
			w = tree.parent[l].second;
			sgn = -1;
		}
		init[i] = {w*sgn,sgn};
	}
	LazySegmentTree<NodeEulerTourSumRangeAdd<pair<long long,long long>,long long>> seg(init);
	int Q; cin >> Q;
	while(Q--) {
		int q; cin >> q;
		int a; cin >> a;
		int l = tree.eulertour_range[a].first;
		int r = tree.eulertour_range[a].second;
		if(q==1) {
			long long x; cin >> x;
			seg.update(l+1,r,x);
		}
		else {
			cout << seg.get(0,l+1).first << endl;
		}
	}
	return 0;
}