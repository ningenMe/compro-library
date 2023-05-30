#define PROBLEM "https://yukicoder.me/problems/no/807"

#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/15-heap/RadixHeap.cpp"

//Dijkstra
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf), cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for (int i = 0; i < N; ++i) cost[i] = inf;

		RadixHeap<int,unsigned long long> pq(0);
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			auto p = pq.pop();
			T v = p.first;
			int from = p.second;
			if(cost[from]<v) continue;
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

int main() {
	cin.tie(0);ios::sync_with_stdio(false);
	int N, M; 
    read(N); read(M);
	Dijkstra<long long> dijk(2*N, 1LL<<60);
	for(int i = 0; i < M; ++i){
		int a, b;
		long long c;
        read(a); read(b); read(c);
		a--, b--;
		dijk.make_edge(a, b, c);
		dijk.make_edge(b, a, c);
		dijk.make_edge(a+N, b+N, c);
		dijk.make_edge(b+N, a+N, c);
		dijk.make_edge(a, b+N, 0);
		dijk.make_edge(b, a+N, 0);
	}
	dijk.solve(0);
	dijk.cost[N]=0;
	for (int i = 0; i < N; ++i) cout << dijk.cost[i]+dijk.cost[i+N] << "\n";

	return 0;
}
