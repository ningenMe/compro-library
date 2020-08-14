

//Union Find Tree
template<class T> class UnionFindTreeMerge {
public:
	vector<int> parent;
    vector<int> rank;
    vector<T> value;

    UnionFindTreeMerge(int N) : parent(N), rank(N,0), value(N){
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	void setValue(int n, T v) {
		value[n] = v;
	}

	T rootValue(int n) {
		return value[root(n)];
	}

	int root(int n) {
		return (parent[n] == n ? n : parent[n] = root(parent[n]));
	}

    int same(int n, int m) {
		return root(n) == root(m);
	}
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(rank[n]<rank[m]) {
            parent[n] = m;
			value[m] += value[n];
        }
        else{
            parent[m] = n;
			value[n] += value[m];
            if(rank[n] == rank[m]) rank[n]++;
        }
	}
};

//verify https://atcoder.jp/contests/abc097/tasks/arc097_b
