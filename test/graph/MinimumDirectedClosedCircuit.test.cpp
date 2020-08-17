#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#define IGNORE

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#include "../../lib/graph/StronglyConnectedComponents.cpp"
#include "../../lib/graph/MinimumDirectedClosedCircuit.cpp"

int main(){
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N);
    MinimumDirectedClosedCircuit dcc(N);
    map<pair<int,int>,int> mp;
    for(int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        scc.make_edge(u,v);
        dcc.make_edge(u,v);
        mp[{u,v}]=i;
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    if(*max_element(cnt.begin(),cnt.end())==1){
		cout << -1 << endl;
        return 0;
    };
    int label=max_element(cnt.begin(),cnt.end())-cnt.begin();
    int root;
    for(int i = 0; i < N; ++i) if(scc[i]==label) root=i;
    auto ans = dcc.solve(root);
    int L = ans.size();
    cout << L << endl;
    for(int i = 0; i < L; ++i) cout << mp[{ans[i],ans[(i+1)%L]}] << endl;
	return 0;
}
