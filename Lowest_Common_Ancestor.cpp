#include <bits/stdc++.h>
using namespace std;

class Lowest_Common_Ancestor {
public:
	int N, MAX_bit;
	vector<vector<int>> edge;
	vector<int> depth;
	vector<vector<int>> parent;

	Lowest_Common_Ancestor(int N, int MAX_bit = 20) :N(N), MAX_bit(MAX_bit), edge(N), depth(N, -1), parent(N, vector<int>(MAX_bit)) {
		//do nothing
	}

	void make_edge(int from, int to) {
		edge[from].push_back(to);
	}

	void make_depth(int root) {
		queue<int> q;
		depth[root] = 0;
		q.push(root);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto to : edge[from]) {
				if (depth[to] != -1) continue;
				depth[to] = depth[from] + 1;
				q.push(to);
			}
		}
	}

	void make_parent() {
		for (int i = 0; i < N; ++i) parent[i][0] = i;
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) parent[i][0] = j;
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1]][bit - 1];
	}

	int lca(int l, int r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		for (int bit = 0; bit < MAX_bit; ++bit) if (diff & (1 << bit)) l = parent[l][bit];
		int ok = (1 << MAX_bit), ng = -1, md;
		while (ok - ng>1) {
			md = (ok + ng) / 2;
			int x = l, y = r;
			for (int bit = 0; bit < MAX_bit; ++bit) if (md & (1 << bit)) x = parent[x][bit];
			for (int bit = 0; bit < MAX_bit; ++bit) if (md & (1 << bit)) y = parent[y][bit];
			(x == y ? ok : ng) = md;
		}
		for (int bit = 0; bit < MAX_bit; ++bit) if (ok & (1 << bit)) l = parent[l][bit];
		return l;
	}

	void print() {
		cout << " depth { " << depth[0];
		for (int i = 1; i < N; ++i) cout << ", " << depth[i];
		cout << " }" << endl;

		cout << "parent { " << parent[0][0];
		for (int i = 1; i < N; ++i) cout << ", " << parent[i][0];
		cout << " }" << endl;
	}

};

//verify https://atcoder.jp/contests/abc014/tasks/abc014_4
