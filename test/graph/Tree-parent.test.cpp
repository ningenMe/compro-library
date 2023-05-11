#define PROBLEM "https://yukicoder.me/problems/no/1308"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/graph/Graph.cpp"
#include "../../lib/graph/Tree.cpp"

template<class T> void chmin(T& a,T b) {a=min(a,b);}

int main(void){
    long long N,Q,C; cin >> N >> Q >> C;
    Graph<long long> g(N);
    for(int i=0;i+1<N;++i) {
        int u,v,w; cin >> u >> v >> w;
        u--,v--;
        g.make_bidirectional_edge(u,v,w);
    }
    vector<int> X(Q);
    for(int i=0;i<Q;++i) cin >> X[i],X[i]--;

    //dp_i,j := x_iにいて、ジャンプビーコンがjにあるときの最小値。j=Nはビーコンなし。
	vector<vector<long long>> dp(Q,vector<long long>(N+1,1e18));
    dp[0][N]=0;
    for(int i=1;i<Q;++i) {

        auto tree = Tree<TreeOperator<long long>>::builder(g).root(X[i]).parent().child().build();

        //jにあるジャンプビーコンをそのままにして、X[i]へ向かうとき
        for(int j=0;j<=N;++j) {
            chmin(dp[i][j],dp[i-1][j]+tree.edge_dist[X[i-1]]);
        }
        //jにジャンプビーコンを置いて、X[i]へ向かうとき
        {
            long long cost=tree.edge_dist[X[i-1]];
            for(int j=X[i-1]; j != X[i]; j = tree.parent[j].first) {
                chmin(dp[i][j],dp[i-1][N]+cost);
            }
        }
        //ジャンプビーコンを使った後、X[i]へ向かうとき
        for(int j=0;j<N;++j){
            chmin(dp[i][N],dp[i-1][j]+tree.edge_dist[j]+C);
        }
        //ジャンプビーコンを使った後jにジャンプビーコンを置いて、X[i]へ向かうとき
        //dp2_j := 頂点jにいるときの最小値
        vector<long long> dp2(N);
        for(int j=0;j<N;++j) dp2[j]=dp[i-1][j]+(X[i-1]==j?0:C);

        for(int j:tree.order) {
            long long cost=0;
            {
                cost+=tree.edge_dist[j];
            }
            for(auto& e:tree.child[j]) {
                int ch = e.first;
                chmin(dp2[j],dp2[ch]+e.second);
            }
            cost += dp2[j];
            chmin(dp[i][j],cost);
        }
    }
    cout << *min_element(dp.back().begin(),dp.back().end()) << endl;
    return 0;
}