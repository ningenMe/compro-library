
class StronglyConnectedComponents{
    int nodeNum;
    vector<vector<int>> edge,revEdge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int labelId){
        visited[curr] = 1;
        label[curr] = labelId;
        for(int next:revEdge[curr]) if(!visited[next]) revDfs(next,labelId);
    }

public:

	StronglyConnectedComponents(const int& nodeNum) : 
    nodeNum(nodeNum), edge(nodeNum), revEdge(nodeNum), label(nodeNum), visited(nodeNum) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        revEdge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        for(int i = 0; i < nodeNum; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int labelId = 0;
        for(int i:order) if(!visited[i]) revDfs(i,labelId++);
    }

    void print(void) {
        for(auto labelId:label) cout << labelId << " ";
        cout << endl;
    }

};
