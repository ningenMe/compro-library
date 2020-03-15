//重みなし有向グラフの最小閉路を求めるクラス
class MinimumDirectedClosedCircuit {
	vector<vector<int>> edge,redge;  
	vector<int> dist;
	size_t N;
public:
	MinimumDirectedClosedCircuit(size_t N) : N(N),edge(N),redge(N),dist(N) {
		//do nothing
	}
	void makeEdge(int from,int to){
		edge[from].push_back(to);
        redge[to].push_back(from);
	}
	//rootを含む最小閉路の集合を返す O(N)
	vector<int> solve(int root,int inf = 123456789){
		int mini = inf;
        int last = -1;
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
            q.push(last);
            while(q.size()){
                int curr = q.front();
                q.pop();
                for(int next:redge[curr]){
                    if(dist[next]+1==dist[curr]) {
                        res.push_back(next);
                        q.push(next);
                        break;
                    }
                }
            }
            reverse(res.begin(),res.end());
        }
		return res;
	}
};
