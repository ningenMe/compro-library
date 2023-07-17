
/*
 * @title DinicMaxFlow - Dinicフロー
 * @docs md/graph/DinicMaxFlow.md
 */
template <class TypeFlow> class DinicMaxFlow {
	struct Edge {
		size_t to, rev;
		TypeFlow cap;
	};
	vector<vector<Edge>> edge;
	vector<int> level, iter;
    TypeFlow inf_flow;

	inline void bfs(const size_t start) {
		for (int i = 0; i < level.size(); ++i) level[i] = -1;
		queue<size_t> q;
		level[start] = 0;
		q.push(start);
		while (q.size()) {
			auto from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[from] + 1;
					q.push(e.to);
				}
			}
		}
	}

	inline TypeFlow dfs(size_t from, size_t goal, TypeFlow flow) {
		if (from == goal) return flow;
		for (int& i = iter[from]; i < edge[from].size(); ++i) {
            //TODO 参照が効いてなくて冗長
			auto& e = edge[from][i];
			if (e.cap <= 0 || level[from] >= level[e.to]) continue;
			TypeFlow dflow = dfs(e.to, goal, min(flow, e.cap));
			if (dflow <= 0) continue;
			e.cap -= dflow;
			edge[e.to][e.rev].cap += dflow;
			return dflow;
		}
		return 0;
	}

public:
	DinicMaxFlow(const size_t N) : edge(N), level(N), iter(N), inf_flow(0) {
		// do nothing
	}

	inline void make_edge(const size_t from,const size_t to, TypeFlow cap) {
		edge[from].push_back({ to, edge[to].size(), cap });
		edge[to].push_back({ from, edge[from].size() - 1, 0});
        inf_flow += cap;
	}

	inline TypeFlow flow(const size_t start,const size_t goal) {
		TypeFlow max_flow = 0;
		while (1) {
			bfs(start);
			if (level[goal] < 0) return max_flow;
			for (int i = 0; i < iter.size(); ++i) iter[i] = 0;
			TypeFlow flow;
			while ((flow = dfs(start, goal, inf_flow))>0) max_flow += flow;
		}
	}
};