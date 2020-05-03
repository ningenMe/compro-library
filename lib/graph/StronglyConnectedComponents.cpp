
class StronglyConnectedComponents{
    int num;
    vector<vector<int>> edge,redge;

    vector<int> label,visited,order;
    
    void dfs(int curr){
        visited[curr] = 1;
        for(int next:edge[curr]) if(!visited[next]) dfs(next);
        order.push_back(curr);
    }

    void revDfs(int curr,int label_id){
        visited[curr] = 1;
        label[curr] = label_id;
        for(int next:redge[curr]) if(!visited[next]) revDfs(next,label_id);
    }

public:

	StronglyConnectedComponents(const int& num) : 
    num(num), edge(num), redge(num), label(num), visited(num) {
        // do nothing        
    }

	int operator[](int idx) {
		return label[idx];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        redge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < num; ++i) visited[i] = 0;
        for(int i = 0; i < num; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < num; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int label_id = 0;
        for(int i:order) if(!visited[i]) revDfs(i,label_id++);
    }

    void print(void) {
        for(auto label_id:label) cout << label_id << " ";
        cout << endl;
    }

};
