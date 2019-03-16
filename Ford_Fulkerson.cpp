#include <bits/stdc++.h>
using namespace std;

//O(F|E|)
template <class T> class Ford_Fulkerson {
public:
	struct info {
		int to, rev;
		T cap;
	};
	T ini, inf;
	vector<vector<info>> edge;
	vector<bool> visit;

	Ford_Fulkerson(int N, T ini, T inf) : edge(N), visit(N), ini(ini), inf(inf) {
		// do nothing
	}

	void make_edge(int from, int to, int cap) {
		edge[from].push_back({ to, (int)edge[to].size(), cap });
		edge[to].push_back({ from, (int)edge[from].size() - 1, ini });
	}

	T dfs(int from, int goal, T flow) {
		if (from == goal) return flow;
		visit[from] = false;
		for (int i = 0; i < edge[from].size(); ++i) {
			if (visit[edge[from][i].to] && edge[from][i].cap > ini) {
				T dflow = dfs(edge[from][i].to, goal, min(flow, edge[from][i].cap));
				if (dflow > 0) {
					edge[from][i].cap -= dflow;
					edge[edge[from][i].to][edge[from][i].rev].cap += dflow;
					return dflow;
				}
			}
		}
		return ini;
	}

	T maxflow(int start, int goal) {
		T maxflow = ini;
		while (1) {
			for (int i = 0; i < edge.size(); ++i) visit[i] = true;
			T flow = dfs(start, goal, inf);
			if (flow == ini) return maxflow;
			maxflow += flow;
		}
	}
};

