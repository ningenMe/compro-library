
class LowLink{
private:
    int N,inc;
    vector<int> ord,low;
public:
    vector<vector<int>> edge;
    vector<int> articulation;
    vector<pair<int,int>> bridge;

    LowLink(int N) : N(N),edge(N),ord(N,-1),low(N,0) {
        // do nothing
    }
    void make_edge(int from, int to) {
		edge[from].push_back(to);
	}
    void solve() {
        inc = 0;
        for(int i = 0; i < N; ++i) if(ord[i]==-1) dfs(i,-1);
    }
private:
    void dfs(int curr,int prev) {
        ord[curr] = inc++;
        low[curr] = ord[curr];
        int isArticulation = 0;
        int cnt = 0;
        for(int next:edge[curr]) {
            if(next == prev) continue;
            if(ord[next]==-1){
                cnt++;
                dfs(next,curr);
                low[curr] = min(low[curr],low[next]);
                if(prev != -1 && low[next] >= ord[curr]) isArticulation = 1;
                if(ord[curr]<low[next]) {
                    bridge.push_back({curr,next});
                    bridge.push_back({next,curr});
                }
            }
            else{
                low[curr] = min(low[curr],ord[next]);
            }
        }
        if(prev==-1 && cnt>1) isArticulation = 1;
        if(isArticulation) articulation.push_back(curr);
    }
};

//verify https://atcoder.jp/contests/arc039/tasks/arc039_d
