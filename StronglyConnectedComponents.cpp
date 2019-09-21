
class StronglyConnectedComponents{
public:
    int nodeNum;
    vector<vector<int>> edge,revEdge;

    vector<int> label,visited;
    stack<int> order;
    
    StronglyConnectedComponents(const int& nodeNum) : 
    nodeNum(nodeNum), edge(nodeNum), revEdge(nodeNum), label(nodeNum), visited(nodeNum) {
        // do nothing        
    }

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        revEdge[to].push_back(from);
    }

    void dfs(int curr){
        if(visited[curr]) return;
        visited[curr] = 1;
        for(int next:edge[curr]) dfs(next);
        order.push(curr);
    }

    void revDfs(int curr,int labelId){
        if(label[curr]!=-1) return;
        label[curr] = labelId;
        for(int next:edge[curr]) revDfs(next,labelId);
    }

    void solve(void) {
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        for(int i = 0; i < nodeNum; ++i) label[i] = -1;
        for(int i = 0; i < nodeNum; ++i) dfs(i);
        int labelId = 0;
        while(order.size()) {
            int i = order.top();
            order.pop();
            if(label[i] != -1) continue;
            revDfs(i,labelId);
            labelId++;
        }
    }

    void print(void) {
        for(auto labelId:label) cout << labelId << " ";
        cout << endl;
    }

};
