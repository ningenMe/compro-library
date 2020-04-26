#include <bits/stdc++.h>
using namespace std;

//Union Find Tree With Potential
template<class T> class Union_Find_Tree_With_Potential {
public:
	vector<int> parent;
	vector<int> rank;
	vector<T> dist;

	Union_Find_Tree_With_Potential(int N = 1, T ini = 0) :parent(N), rank(N,0), dist(N, ini) {
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	int root(int x) {
		if (parent[x] == x) return x;
		else {
			int r = root(parent[x]);
			dist[x] += dist[parent[x]];
			return parent[x] = r;
		}
	}

	T updated_dist(int x) {
		root(x);
		return dist[x];
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y, T d = 0) {
		d += updated_dist(x);
		d -= updated_dist(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) {
			swap(x, y);
			d = -d;
		}
		if (rank[x] == rank[y]) ++rank[x];
		parent[y] = x;
		dist[y] = d;
		return true;
	}

	T diff(int x, int y) {
		return updated_dist(y) - updated_dist(x);
	}
};

//verify https://atcoder.jp/contests/abc087/tasks/arc090_b 