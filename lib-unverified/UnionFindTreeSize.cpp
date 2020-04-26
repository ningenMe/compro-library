
//Union Find Tree
class UnionFindTreeSize {
public:
	vector<int> parent;
    vector<int> maxidx;
    vector<int> minidx;

    UnionFindTreeSize(int N = 1) : parent(N,-1),maxidx(N),minidx(N){
        iota(maxidx.begin(),maxidx.end(),0);
        iota(minidx.begin(),minidx.end(),0);
	}
 
	int root(int n) {
        return (parent[n]<0?n:parent[n] = root(parent[n]));
	}

    bool same(int n, int m) {
		return root(n) == root(m);
	}

    int mini(int n) {
        return minidx[root(n)];
    }

    int maxi(int n) {
        return maxidx[root(n)];
    }
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
        maxidx[n] = max(maxidx[n],maxidx[m]);
        minidx[n] = min(minidx[n],minidx[m]);
	}

    int size(int n){
        return (-parent[root(n)]);
    }

    void print() {
        for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
        cout << endl;
    }
};