#include <bits/stdc++.h>
using namespace std;

//Union Find Tree
class Union_Find_Tree_Size {
public:
	vector<int> parent;

    Union_Find_Tree_Size(int N = 1) : parent(N,-1){
	}
 
	int root(int n) {
        return (parent[n]<0?n:parent[n] = root(parent[n]));
	}

    bool same(int n, int m) {
		return root(n) == root(m);
	}
 
	void unite(int n, int m) {
		n = root(n);
		m = root(m);
		if (n == m) return;
		if(parent[n]>parent[m]) swap(n, m);
        parent[n] += parent[m];
        parent[m] = n;
	}

    int size(int n){
        return (-parent[root(n)]);
    }
};


//verify 