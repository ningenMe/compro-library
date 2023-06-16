/*
 * @title PotentializedUnionFindTree - ポテンシャル付きUnionFind木
 * @docs md/union-find-tree/PotentializedUnionFindTree.md
 */
template<class T> class PotentializedUnionFindTree {
    vector<int> parent,rank;
    vector<T> potential;
    inline int root(int n) {
        if (parent[n] == n) {
            return n;
        }
        else {
            int r = root(parent[n]);
            potential[n] += potential[parent[n]];
            return parent[n] = r;
        }
    }
    inline T updated_dist(int x) {
        root(x);
        return potential[x];
    }
public:
    PotentializedUnionFindTree(int N = 1, T ini = 0) : parent(N),rank(N,1),potential(N,ini) {
        iota(parent.begin(),parent.end(),0);
    }
    inline bool connected(int n, int m) {
        return root(n) == root(m);
    }
    /*
    * potential[m] = potential[n] + dとなるようにマージする
    */
    bool merge(int n, int m, T d=0) {
        d += updated_dist(n);
        d -= updated_dist(m);
        n = root(n); m = root(m);
        if (n == m) return false;
        if (rank[n] < rank[m]) {
            swap(n, m);
            d = -d;
        }
        if (rank[n] == rank[m]) ++rank[n];
        parent[m] = n;
        potential[m] = d;
        return true;
    }
    /*
    * potential[m] - potential[n]
    */
    T diff(int n, int m) {
        return updated_dist(m) - updated_dist(n);
    }
    inline int operator[](int n) {
        return root(n);
    }
    inline void print() {
        for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
        cout << endl;
    }
};
