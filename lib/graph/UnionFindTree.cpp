//Union Find Tree
class UnionFindTree {
public:
	vector<int> parent;
	vector<int> rank;

	UnionFindTree(int N) : parent(N), rank(N,0){
		iota(parent.begin(),parent.end(),0);
	} 
	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}
	inline int same(int n, int m) {
		return root(n) == root(m);
	}
	inline void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if (rank[n]<rank[m]) {
			parent[n] = m;
		}
		else{
			parent[m] = n;
			if(rank[n] == rank[m]) rank[n]++;
		}
	}
};