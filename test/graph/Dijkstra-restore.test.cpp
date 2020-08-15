#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#define ERROR 0.0001
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#include "../../lib/graph/Dijkstra.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
	int N,M,s,t;
	cin >> N >> M >> s >> t;
	long long inf = 1e15;
	Dijkstra<long long> dijk(N,inf);
	while(M--) {
		int u,v,w; cin >> u >> v >> w;
		dijk.make_edge(u,v,w);
	}
	dijk.solve(s);
	long long cost = dijk.get(t);
	if(cost == inf) {
		cout << -1 << endl;
		return 0;
	}
	auto v = dijk.restore(t);
	cout << cost << " " << (int)v.size()-1 << endl;
	for(int i = 0; i+1 < v.size(); ++i) {
		cout << v[i] << " " << v[i+1] << endl;
	}
    return 0;
}