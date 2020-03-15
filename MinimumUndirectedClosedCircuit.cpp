
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
	//rootを含む最小閉路の長さを返す O(N) 閉路がないときは空集合
	vector<int> solve(int root,int inf = 123456789){
		int mini = inf;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<pair<int,int>> q;
		q.push({root,-1});
		dist[root] = 0;
		pair<int,int> last = make_pair(-1,-1);
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
					if(mini > dist[curr]+dist[next]+1){
						mini = dist[curr]+dist[next]+1;
						last = make_pair(curr,next);
					}
				}
			}
		}
		vector<int> idxl,idxr,res;
		if(last != make_pair(-1,-1)){
			queue<int> l;
			stack<int> r;
			int curr;
			curr = last.first;
			while(curr != root){
				l.push(curr);
				for(int next:edge[curr]){
					if(dist[next]+1==dist[curr]) {
						curr = next;
						break;
					}
				}
			}
			curr = last.second;
			while(curr != root){
				r.push(curr);
				for(int next:edge[curr]){
					if(dist[next]+1==dist[curr]) {
						curr = next;
						break;
					}
				}
			}
			while (l.size()) {
				res.push_back(l.front());
				l.pop();
			}
			res.push_back(root);			
			while (r.size()) {
				res.push_back(r.top());
				r.pop();
			}
		}
		return res;
	}
};
