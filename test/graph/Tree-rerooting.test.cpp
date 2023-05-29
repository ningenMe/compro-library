#define PROBLEM "https://yukicoder.me/problems/no/922"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/40-graph/UnionFindTree.cpp"
#include "../../lib/40-graph/Graph.cpp"
#include "../../lib/40-graph/Tree.cpp"

int main(void){
    int N,M,Q; cin >> N >> M >> Q;
    UnionFindTree uf(N);
    Graph<long long> g(N);
    for(int i=0;i<M;++i) {
        int u,v; cin >> u >> v;
        u--,v--;
		uf.merge(u,v);
        g.make_bidirectional_edge(u,v,1);
    }
    auto tree = Tree<TreeOperator<long long>>::builder(g).root().parent().ancestor().child().build();
	long long ans = 0;
	vector<pair<long long,long long>> cnt(N,{0,0}),par(N,{0,0});
	for(int i = 0; i < Q; ++i){
        int a,b; cin >> a >> b;
        a--,b--;
        if(uf.connected(a,b)){
			ans += tree.lca(a,b).second;
        }
        else{
            cnt[a].second++;
            cnt[b].second++;
        }
    }
	for(int i = 0; i < N; ++i) if(tree.depth[i]) par[i] = cnt[tree.parent[i].first];
	auto dp = tree.rerooting<pair<long long,long long>>(cnt,par);
	const long long inf = 1e15;
	vector<long long> sum(N,inf);
	for(int i = 0,j; i < N; ++i) j = uf[i],sum[j] = min(sum[j],dp[i].first);
    for(int i = 0; i < N; ++i) if(sum[i] != inf) ans += sum[i];
	cout << ans << endl;	
	return 0;
}