/*
 * @title StronglyConnectedComponents
 */
class StronglyConnectedComponents{
	int num,is_2sat,half;
	vector<vector<int>> edge,redge;

	vector<int> label,visited,order;

	inline void dfs(int curr){
		visited[curr] = 1;
		for(int next:edge[curr]) if(!visited[next]) dfs(next);
		order.push_back(curr);
	}

	inline void rdfs(int curr,int id){
		visited[curr] = 1;
		label[curr] = id;
		for(int next:redge[curr]) if(!visited[next]) rdfs(next,id);
	}
    inline int rev(int i) { return i < half ? i + half : i - half; }
public:

	StronglyConnectedComponents(const int n, bool is_2sat=0):num(n),is_2sat(is_2sat){
        if(is_2sat) num*=2;
        edge.resize(num);
        redge.resize(num);
        label.resize(num);
        visited.resize(num);
        half=num/2;
	}
	inline int operator[](int idx) {
		return label[idx];
	}
	inline void make_edge(const int from,const int to) {
		edge[from].push_back(to);
		redge[to].push_back(from);
	}
    inline void make_condition(int x, bool flg_x, int y, bool flg_y) {
        if (!flg_x) x = rev(x);
        if (!flg_y) y = rev(y);
        make_edge(x, y);
        make_edge(rev(y), rev(x));
    }
	inline int solve(void) {
		for(int i = 0; i < num; ++i) visited[i] = 0;
		for(int i = 0; i < num; ++i) if(!visited[i]) dfs(i);
		for(int i = 0; i < num; ++i) visited[i] = 0;
		reverse(order.begin(),order.end());
		int id = 0;
		for(int i:order) if(!visited[i]) rdfs(i,id++);
        if(!is_2sat) return true;
        for (int i = 0; i < num; ++i) if (label[i] == label[rev(i)]) return false;
        return true;
	}
    int is_true(int i) {
        return label[i] > label[rev(i)];
    }
	void print(void) {
		for(auto id:label) cout << id << " ";
		cout << endl;
	}

};
