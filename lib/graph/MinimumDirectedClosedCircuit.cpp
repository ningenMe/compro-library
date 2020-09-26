/*
 * @title MinimumDirectedClosedCircuit - 最小有効閉路検出
 * @docs md/graph/MinimumDirectedClosedCircuit.md
 */
class MinimumDirectedClosedCircuit {
	vector<vector<int>> edge,redge;  
	vector<int> dist;
	size_t N;
public:
	MinimumDirectedClosedCircuit(size_t N) : N(N),edge(N),redge(N),dist(N) {
		//do nothing
	}
	inline void make_edge(int from,int to){
		edge[from].push_back(to);
		redge[to].push_back(from);
	}
	//rootを含む最小閉路の集合を返す O(N) 閉路がないときは空集合
	inline vector<int> solve(int root,int inf = 123456789){
		int mini = inf, last = -1;
		for(int i = 0; i < N; ++i) dist[i] = -1;
		queue<int> q;
		q.push(root);
		dist[root] = 0;
		while (q.size()) {
			int curr = q.front();
			q.pop();
			for(int next:edge[curr]){
				if(next == root && mini > dist[curr]+1) mini = dist[curr]+1,last = curr;
				if(dist[next]==-1) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}
		vector<int> res;
		if(last != -1){
			res.push_back(last);
			int curr = last;
			while(curr != root){
				for(int next:redge[curr]){
					if(dist[next]+1==dist[curr]) {
						res.push_back(next);
						curr = next;
						break;
					}
				}
			}
			reverse(res.begin(),res.end());
		}
		return res;
	}
};