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
#include "../../lib/graph/Tree.cpp"
#include "../../lib/segment/LazySegmentTree.cpp"

//node:総和　lazy:更新
template<class T, class U> struct NodeSumRangeEoulerTourAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = {0,0};
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}
	inline static constexpr TypeLazy func_lazy(TypeLazy l,TypeLazy r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int l,int r){return {node.first+node.second*lazy,node.second};}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};

int main(void){
    int N; cin >> N;
    Tree<TreeOperator<long long>> tree(N);
    map<pair<long long,long long>,long long> mp;
    for(int i = 0; i < N-1; ++i) {
        int u,v,w; cin >> u >> v >> w;
        tree.make_edge(u,v,w);
        tree.make_edge(v,u,w);
        mp[{u,v}] = mp[{v,u}] = w;
    } 
    tree.make_eulertour();
    int M = tree.eulertour.size();
    vector<pair<long long,long long>> A(M,{0,0});
    for(int i = 1; i < M; ++i) {
        int l = tree.eulertour[i-1],r = tree.eulertour[i];
        int sgn = (tree.depth[l]<tree.depth[r]?1:-1);
        A[i] = {sgn*mp[{l,r}],sgn};
    }
    LazySegmentTree<NodeSumRangeEoulerTourAdd<pair<long long,long long>,long long>> seg(A);
    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i) {
        int q; cin >> q;
        if(q==1){
            int a; cin >> a;
            long long x; cin >> x;
            seg.update(tree.eulertour_range[a].first+1,tree.eulertour_range[a].second+1,x);
        }
        else{
            int b; cin >> b;
            cout << seg.get(0,tree.eulertour_range[b].first+1).first << endl;
        }
    }
	return 0;
}