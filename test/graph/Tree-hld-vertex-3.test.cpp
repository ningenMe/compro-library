#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

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
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/data-structure/segment-tree/SegmentTree.cpp"
#include "../../lib/operator/monoid/MonoidRangeCompositePointUpdate.cpp"

//一次関数
template<class T> struct MonoidRangeRevCompositePointUpdate {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = make_pair(1,0);
    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {l.first*r.first,l.first*r.second+l.second};}
    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

using modint = ModInt<998244353>;
int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    SegmentTree<MonoidRangeCompositePointUpdate<pair<modint,modint>>> segLtoR(N,{1,0});
    SegmentTree<MonoidRangeRevCompositePointUpdate<pair<modint,modint>>> segRtoL(N,{1,0});
    vector<int> A(N),B(N);
    for(int i=0;i<N;++i) cin >> A[i] >> B[i];
    Graph<int> g(N);
    for(int i=0;i+1<N;++i) {
        int u,v; cin >> u >> v;
        g.make_bidirectional_edge(u,v,1);
    }
    auto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();
    for(int i=0;i<N;++i) {
        int j = tree.hld[i];
        segLtoR.operate(j,{A[i],B[i]});
        segRtoL.operate(j,{A[i],B[i]});
    }
    while(Q--) {
        int q; cin >> q;
        if(q==0) {
            int i,a,b; cin >> i >> a >> b;
            int j = tree.hld[i];
            segLtoR.operate(j,{a,b});
            segRtoL.operate(j,{a,b});
        }
        else {
            int l,r,x; cin >> l >> r >> x;
            auto tp = tree.vertex_ordered_set_on_path(l,r);

            pair<modint,modint> line = {1,0};
            for(auto& p:tp.first) {
                auto tmp = segRtoL.fold(p.first,p.second+1);
                line = {tmp.first*line.first,tmp.first*line.second+tmp.second};
            }
            for(auto& p:tp.second) {
                auto tmp = segLtoR.fold(p.first,p.second+1);
                line = {tmp.first*line.first,tmp.first*line.second+tmp.second};
            }
            cout << line.first*x+line.second << "\n";
        }
    }
    return 0; 
}