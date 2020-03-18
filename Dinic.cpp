
template <class T> class Dinic {
	struct info {
		int to, rev;
		T cap;
	};
	T ini, inf;
	vector<vector<info>> edge;
	vector<int> level, iter;

	void bfs(int start) {
		for (int i = 0; i < level.size(); ++i) level[i] = -1;
		queue<int> q;
		level[start] = 0;
		q.push(start);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[from] + 1;
					q.push(e.to);
				}
			}
		}
	}

	T dfs(int from, int goal, T flow) {
		if (from == goal) return flow;
		for (int& i = iter[from]; i < edge[from].size(); ++i) {
			auto& e = edge[from][i];
			if (e.cap <= 0 || level[from] >= level[e.to]) continue;
			T dflow = dfs(e.to, goal, min(flow, e.cap));
			if (dflow <= 0) continue;
			e.cap -= dflow;
			edge[e.to][e.rev].cap += dflow;
			return dflow;
		}
		return ini;
	}

public:

	Dinic(int N, T ini, T inf) : edge(N), level(N), iter(N), ini(ini), inf(inf) {
		// do nothing
	}

	void makeEdge(int from, int to, T cap) {
		edge[from].push_back({ to, (int)edge[to].size(), cap });
		edge[to].push_back({ from, (int)edge[from].size() - 1, ini });
	}

	T maxFlow(int start, int goal) {
		T maxflow = ini;
		while (1) {
			bfs(start);
			if (level[goal] < 0) return maxflow;
			for (int i = 0; i < iter.size(); ++i) iter[i] = 0;
			T flow;
			while ((flow = dfs(start, goal, inf))>0) maxflow += flow;
		}
	}
};

//verify https://atcoder.jp/contests/arc085/tasks/arc085_c
