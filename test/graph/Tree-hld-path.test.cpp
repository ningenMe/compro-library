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
#include "../../lib/graph/Graph.cpp"
#include "../../lib/math/Matrix.cpp"
#include "../../lib/graph/Tree2.cpp"
#include "../../lib/segment/SegmentTree.cpp"
#include "../../lib/util/ModInt.cpp"

constexpr long long MOD = 1'000'000'007LL;
using modint = ModInt<MOD>;
using matrix = Matrix<modint,2,2>;

//一点更新 区間最小
template<class T> struct NodeMulPointUpdate {
    using TypeNode = T;
    inline static TypeNode unit_node = Matrix<modint,2,2>::E();
    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l*r;}
    inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}
};


int main(void){
	int N; cin >> N;
	Graph<int> g(N);
	vector<pair<size_t,size_t>> vp(N-1);
	for(int i = 0; i < N-1; ++i) {
		int u,v; cin >> u >> v;
		g.make_bidirectional_edge(u,v,1);
		vp[i]={u,v};
	}
	auto tree = Tree<TreeOperator<int>>::builder(g).root(0).child().subtree_size().parent().heavy_light_decomposition().build();
    SegmentTree<NodeMulPointUpdate<matrix>> seg(N);
    int Q; cin >> Q;
    while(Q--) {
        char c; cin >> c;
        if(c == 'x'){
            int i; cin >> i;
            modint a,b,c,d; cin >> a >> b >> c >> d;
            matrix x;
			x[0]={a,b};
			x[1]={c,d};
			int l = vp[i].first, r = vp[i].second;
            l = tree.hld[l],r = tree.hld[r];
            seg.update(max(l,r),x);
        }
        else{
            int l,r; cin >> l >> r;
            auto vp = tree.edge_set_on_path(l,r);
            matrix ans = matrix::E();
            for(auto p:vp){
                ans *= seg.get(p.first,p.second+1);
            }
            cout << ans[0][0] << " " << ans[0][1] << " " << ans[1][0] << " " << ans[1][1] << endl;
        }
    }
	return 0;
}