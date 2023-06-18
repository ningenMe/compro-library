/*
 * @title UndoUnionFindTree - Undoつき Union Find Tree
 * @docs md/union-find-tree/UndoUnionFindTree.md
 */
class UndoUnionFindTree {
    vector<int> parent;
    stack<array<int,2>> history;
    inline int root(int n) {
        return (parent[n]<0?n:root(parent[n]));
    }
public:
    UndoUnionFindTree(const int N = 1) : parent(N,-1){
    }
    inline bool connected(const int n, const int m) {
        return root(n) == root(m);
    }
    inline void merge(int n,int m) {
        n = root(n);
        m = root(m);
        history.push({n,parent[n]});
        history.push({m,parent[m]});
        if (n == m) return;
        if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
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
    inline void undo() {
        for(int i=0;i<2;++i) {
            auto ar=history.top(); history.pop();
            parent[ar[0]]=ar[1];
        }
    }
};