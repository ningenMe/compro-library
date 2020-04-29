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
#include "../../lib/graph/Tree.cpp"
#include "../../lib/segment/LazySegmentTree.cpp"

int main(void){
	int N; cin >> N;
	Tree<TreeOperator<int>> tree(N);
	vector<pair<int,int>> edge(N-1);
	for(int i = 0; i < N-1; ++i) {
		int u,v; cin >> u >> v;
		u--,v--;
		tree.make_edge(u,v);
		tree.make_edge(v,u);
		edge[i] = {u,v};
	}
	tree.make_heavy_light_decomposition(0);
    LazySegmentTree<NodeSumRangeAdd<long long,long long>> seg(N);
    int Q; cin >> Q;
    long long ans = 0;
    for(int i = 0; i < Q; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        auto path = tree.path(a,b);
        for(auto p:path){
            int l = p.first,r = p.second;
            seg.update(l,r+1,1);
            ans += seg.get(l,r+1);
        }
    }
    cout << ans << endl;
    return 0;
}