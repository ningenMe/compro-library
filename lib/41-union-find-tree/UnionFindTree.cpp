/*
 * @title UnionFindTree - Union Find Tree
 * @docs md/union-find-tree/UnionFindTree.md
 */
class UnionFindTree {
    vector<int> parent,maxi,mini;
    inline int root(int n) {
        return (parent[n]<0?n:parent[n] = root(parent[n]));
    }
public:
    UnionFindTree(const int N = 1) : parent(N,-1),maxi(N),mini(N){
        iota(maxi.begin(),maxi.end(),0);
        iota(mini.begin(),mini.end(),0);
    }
    inline bool connected(const int n, const int m) {
        return root(n) == root(m);
    }
    inline void merge(int n,int m) {
        n = root(n);
        m = root(m);
        if (n == m) return;
        if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
        maxi[n] = std::max(maxi[n],maxi[m]);
        mini[n] = std::min(mini[n],mini[m]);
    }
    inline int min(const int n) {
        return mini[root(n)];
    }
    inline int max(const int n) {
        return maxi[root(n)];
    }
    inline int size(const int n){
        return (-parent[root(n)]);
    }
    inline int operator[](const int n) {
        return root(n);
    }
    inline void print() {
        for(int i = 0; i < parent.size(); ++i) cout << root(i) << " ";
        cout << endl;
    }
};
