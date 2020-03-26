
class BipartiteMatching {
	vector<vector<int>> edge;
	vector<int> match, used;
    size_t N;

    int dfs(int prev) {
        used[prev] = 1;
        for(int curr:edge[prev]){
            int next = match[curr];
            if(next < 0 || (!used[next] && dfs(next)) ) {
                match[prev] = curr;
                match[curr] = prev;
                return 1;
            }
        }
        return 0;
    }

public:

	BipartiteMatching(int N) : N(N), edge(N), match(N,-1), used(N) {
		// do nothing
	}

	void makeEdge(int from, int to) {
		edge[from].push_back(to);
	}

	int maxFlow() {
		int res = 0;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) {
                for(int j = 0; j < N; ++j) used[j] = 0;
                if(dfs(i)) res++;
            }
        }
        return res;
	}

    vector<pair<int,int>> restoration(){
        vector<pair<int,int>> vp;
        for(int i = 0; i < N; ++i) {
            if(match[i] < 0) continue;
            if(i < match[i]) vp.push_back({i,match[i]});
        }
        return vp;
    }
};
