#define PROBLEM "https://yukicoder.me/problems/no/650"

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
#include "../../lib/segment/SegmentTree.cpp"
#include "../../lib/util/ModInt.cpp"

constexpr long long MOD = 1'000'000'007LL;
using modint = ModInt<MOD>;
using matrix = array<modint, 4>;
constexpr matrix E = {1,0,0,1};

//一点更新 区間最小
template<class T> struct NodeMatrixPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = {1,0,0,1};
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){
        matrix res = {};
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 2; ++j) {
                for(int k = 0; k < 2; ++k) {
                    res[i*2+j] += l[i*2+k]*r[k*2+j];
                }
            }
        }
        return res;
    }
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

int main(void){
	int N; cin >> N;
	Tree<TreeOperator<int>> tree(N);
	vector<pair<int,int>> edge(N-1);
	for(int i = 0; i < N-1; ++i) {
		int u,v; cin >> u >> v;
		tree.make_edge(u,v);
		tree.make_edge(v,u);
		edge[i] = {u,v};
	}
	tree.make_heavy_light_decomposition(0);
    SegmentTree<NodeMatrixPointUpdate<matrix>> seg(N);
    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i) {
        char c; cin >> c;
        if(c == 'x'){
            int j; cin >> j;
            modint a,b,c,d; cin >> a >> b >> c >> d;
            matrix x = {a,b,c,d};
            int l = edge[j].first, r = edge[j].second;
            l = tree.hldorder[l],r = tree.hldorder[r];
            if(l > r) swap(l,r);
            seg.update(r,x);
        }
        else{
            int l,r; cin >> l >> r;
            auto vp = tree.path(l,r,1);
            matrix ans = E;
            for(auto p:vp){
                ans = NodeMatrixPointUpdate<matrix>::func_node(ans,seg.get(p.first,p.second+1));
            }
            cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        }
    }
	return 0;
}