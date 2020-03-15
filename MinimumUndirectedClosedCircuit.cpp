//重みなし無効グラフの最小閉路を求めるクラス
class MinimumUndirectedClosedCircuit {
	vector<vector<int>> edge;
	vector<int> dist;
	size_t N;
public:
	MinimumUndirectedClosedCircuit(size_t N) : N(N),edge(N),dist(N) {
		//do nothing
	}
	void makeEdge(int from,int to){
		edge[from].push_back(to);
	}
	//rootを含む最小閉路の長さを返す O(N)
	int solve(int root,int inf = 123456789){
		int res = inf;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<pair<int,int>> q;
		q.push({root,-1});
		dist[root] = 0;
		vector<pair<int,int>> candidate;
		while (q.size()) {
			int curr = q.front().first;
			int prev = q.front().second;
			q.pop();
			for(int next:edge[curr]){
				if(next==prev) continue;
				if(dist[next]==-1) {
					dist[next] = dist[curr] + 1;
					q.push({next,curr});
				}
				else{
					candidate.push_back({next,curr});
				}
			}
		}
		for(auto p:candidate) if(res > dist[p.first]+dist[p.second]+1) res = dist[p.first]+dist[p.second]+1;
		return res;
	}
};
