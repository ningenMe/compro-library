
template<class T = int> class Tree {
public:
	int nodeNum;
	int isWeighted;
	int maxBit;
	int idx;
	vector<vector<int>> edge;
	vector<vector<T>> weight;
	vector<int> depth;
	vector<int> order;
	vector<T> dist;
	
	vector<int> parent;
	vector<T> parentDist;
	
	vector<vector<int>> child;
	vector<vector<T>> childDist;
 
	vector<vector<int>> ancestor;
	vector<vector<int>> descendant;
	
	vector<int> eulerTour;
    vector<T> eulerTourDist;
	vector<int> eulerTourIdxL;
	vector<int> eulerTourIdxR;
    vector<int> eulerTourDive,eulerTourFloat;
    vector<T> eulerTourDiveDist,eulerTourFloatDist;
	vector<int> eulerTourDiveIdxL,eulerTourFloatIdxL;
	vector<int> eulerTourDiveIdxR,eulerTourFloatIdxR;
 
	Tree(const int nodeNum, const int isWeighted = 0, const int maxBit = 20) : 
	nodeNum(nodeNum),
	isWeighted(isWeighted),
	maxBit(maxBit),
	edge(nodeNum),
	depth(nodeNum),
	order(nodeNum)
	{
		if(isWeighted) weight.resize(nodeNum);
		if(isWeighted) dist.resize(nodeNum);
	}
 
	//O(1) anytime
	void makeEdge(const int& from, const int& to, const T& w = 0) {
		edge[from].push_back(to);
		if(isWeighted)	weight[from].push_back(w);
	}
 
	//O(N) anytime
	void makeDepth(const int root) {
		depth[root] = 0;
		if(isWeighted) dist[root] = 0;
		idx = 0;
		dfs1(root);
		order[idx++] = root;
	}
 
    //for makeDepth
	void dfs1(int from, int prev = -1){
		for(int i = 0; i < edge[from].size(); ++i){
			int to = edge[from][i];
			if(to==prev) continue;
			depth[to] = depth[from] + 1;
			if(isWeighted) dist[to] = dist[from] + weight[from][i];
			dfs1(to,from);
			order[idx++] = to;
		}
	}
 
    //O(N) anytime
	int diameter(void){
		makeDepth(0);
		int tmp = max_element(depth.begin(), depth.end()) - depth.begin();
		makeDepth(tmp);
		return *max_element(depth.begin(), depth.end());
	}
 
	//O(N) after makeDepth
	void makeParent(void) {
		parent.resize(nodeNum);
		iota(parent.begin(),parent.end(),0);
		for (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) parent[i] = j;
 
		if(isWeighted) {
			parentDist.resize(nodeNum);
			for (int i = 0; i < nodeNum; ++i) for (int j = 0; j < edge[i].size(); ++j) if (depth[i] > depth[edge[i][j]]) parentDist[i] = weight[i][j];
		}
	}
 
	//O(N) after makeDepth
	void makeChild(void) {
		child.resize(nodeNum);
		for (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);
 
		if(isWeighted) {
			childDist.resize(nodeNum);
			for (int i = 0; i < nodeNum; ++i) for (int j = 0; j < edge[i].size(); ++j) if (depth[i] < depth[edge[i][j]]) childDist[i].push_back(weight[i][j]);
		}
	}
 
	//O(NlogN) after makeDepth
	void makeAncestor(void) {
		ancestor.resize(nodeNum,vector<int>(maxBit));
		for (int i = 0; i < nodeNum; ++i) ancestor[i][0] = i;
		for (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) ancestor[i][0] = j;
		for (int bit = 1; bit < maxBit; ++bit) for (int i = 0; i < nodeNum; ++i) ancestor[i][bit] = ancestor[ancestor[i][bit - 1]][bit - 1];
	}
 
	//O(N^2) after makeDepth
	void makeDescendant(void) {
		descendant.resize(nodeNum);
		for (int i = 0; i < nodeNum; ++i) descendant[i].push_back(i);
		for (int i = 0; i < nodeNum; ++i) for (auto j : edge[order[i]]) if (depth[order[i]] < depth[j]) for(auto k: descendant[j]) descendant[order[i]].push_back(k);
	}
 
	//O(logN) after makeAncestor
	int lca(int l, int r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		for (int bit = 0; bit < maxBit; ++bit) if (diff & (1 << bit)) l = ancestor[l][bit];
		if(l==r) return l;
		for (int bit = maxBit - 1; 0 <= bit; --bit) if(ancestor[l][bit]!=ancestor[r][bit]) l = ancestor[l][bit], r = ancestor[r][bit];
		return ancestor[l][0];
	}
 
	//O(N) after makeChild and makeParent
	void makeEulerTour(void){
        dfs2(order[nodeNum-1]);
		eulerTourIdxL.resize(nodeNum);
		eulerTourIdxR.resize(nodeNum);
		for(int i = 0; i < eulerTour.size(); ++i) eulerTourIdxR[eulerTour[i]] = i;
		for(int i = eulerTour.size()-1; 0 <= i; --i) eulerTourIdxL[eulerTour[i]] = i;
		return;
	}
 
    //for makeEulerTour
	void dfs2(int from, int prev = -1){
		eulerTour.push_back(from);
        if(isWeighted) eulerTourDist.push_back(parentDist[from]);
 
        for(int i = 0; i < child[from].size(); ++i){
            int to = child[from][i];            
            dfs2(to,from);            
    		eulerTour.push_back(from);
            if(isWeighted) eulerTourDist.push_back(-childDist[from][i]);
        }
	}

	//O(NlogN) after makeEulerTour
	void makeEulerTourEdge(void) {
		eulerTourDive.push_back(order[nodeNum-1]);
		if(isWeighted) eulerTourDiveDist.push_back(0);
		for(int i = 1; i < eulerTour.size(); ++i) {
			int l = eulerTour[i-1];
			int r = eulerTour[i];
			if(depth[l] < depth[r]) {
				eulerTourDive.push_back(i);
				if(isWeighted) eulerTourDiveDist.push_back(eulerTourDist[i]);
			}
			else {
				eulerTourFloat.push_back(i);
				if(isWeighted) eulerTourFloatDist.push_back(eulerTourDist[i]);
			}
		}
		eulerTourDiveIdxL.resize(nodeNum);
		eulerTourDiveIdxR.resize(nodeNum);
		eulerTourFloatIdxL.resize(nodeNum);
		eulerTourFloatIdxR.resize(nodeNum);
		for(int i = 0; i < nodeNum; ++i) {
			int l = eulerTourIdxL[i];
			int r = eulerTourIdxR[i];
			eulerTourDiveIdxL[i]  =  upper_bound(eulerTourDive.begin() ,eulerTourDive.end() ,l) - eulerTourDive.begin()     ;
			eulerTourDiveIdxR[i]  = (upper_bound(eulerTourDive.begin() ,eulerTourDive.end() ,r) - eulerTourDive.begin())  -1;
			eulerTourFloatIdxL[i] =  upper_bound(eulerTourFloat.begin(),eulerTourFloat.end(),l) - eulerTourFloat.begin()    ;
			eulerTourFloatIdxR[i] = (upper_bound(eulerTourFloat.begin(),eulerTourFloat.end(),r) - eulerTourFloat.begin()) -1;
			eulerTourDiveIdxR[i]  = max(eulerTourDiveIdxL[i]-1 ,eulerTourDiveIdxR[i]);
			eulerTourFloatIdxR[i] = max(eulerTourFloatIdxL[i]-1,eulerTourFloatIdxR[i]);
		}
	}
		// iの部分木の頂点に加算するとき
		// [ eulerTourIdxL[i]  ,eulerTourIdxR[i]  ]に　+val
		// [i]の頂点クエリ
		// [eulerTourIdxL[i],eulerTourIdxL[i]]

		// iの部分木の辺に加算するとき
		// [ eulerTourDiveIdxL[i]  ,eulerTourDiveIdxR[i]  ]に　+val
		// [ eulerTourFloatIdxL[i] ,eulerTourFloatIdxR[i] ]に　-val
		// [0,i]のパスクエリ
		// [ 0, eulerTourDiveIdxL[i] ) + [0, eulerTourFloatIdxL[i])
 
};
 
//depth,dist
//https://atcoder.jp/contests/abc126/tasks/abc126_d
 
//lca
//https://atcoder.jp/contests/abc014/tasks/abc014_4
 
//child
//https://atcoder.jp/contests/abc133/tasks/abc133_e

//diameter
//https://atcoder.jp/contests/agc033/tasks/agc033_c

//eulerTour
//https://yukicoder.me/problems/no/900

