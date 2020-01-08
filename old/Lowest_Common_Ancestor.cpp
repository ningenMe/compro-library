#include <bits/stdc++.h>
using namespace std;

class Lowest_Common_Ancestor {
public:
	int N, MAX_bit;
	vector<vector<int>> edge;
	vector<int> depth;
	vector<vector<int>> parent;
	vector<vector<int>> child;
	vector<vector<int>> descendant;

	Lowest_Common_Ancestor(int N, int MAX_bit = 20) :N(N), MAX_bit(MAX_bit), edge(N), depth(N, -1), parent(N, vector<int>(MAX_bit)), child(N), descendant(N){
		//do nothing
	}

	//O(1)
	void make_edge(int from, int to) {
		edge[from].push_back(to);
	}

	//O(N)
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

	//O(MAX_bit*N)
	void make_parent() {
		for (int i = 0; i < N; ++i) parent[i][0] = i;
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) parent[i][0] = j;
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1]][bit - 1];
	}

	//O(N)
	void make_child() {
		for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);
	}

	//O(N^2)
	void make_descendant() {
		vector<pair<int,int>> ord(N);
		for (int i = 0; i < N; ++i) ord[i] = {depth[i],i};
		sort(ord.begin(),ord.end(),greater<>());
		for (int i = 0; i < N; ++i) descendant[i].push_back(i);
		for (int i = 0; i < N; ++i) for (auto j : edge[ord[i].second]) if (depth[ord[i].second] < depth[j]) for(auto k: descendant[j]) descendant[ord[i].second].push_back(k);
	}

	//O(MAX_bit*logN)
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

		cout << " child { " << child[0];
		for (int i = 1; i < N; ++i) cout << ", " << child[i];
		cout << " }" << endl;

		cout << "descen { " << descendant[0];
		for (int i = 1; i < N; ++i) cout << ", " << descendant[i];
		cout << " }" << endl;
	}

};

//verify https://atcoder.jp/contests/abc014/tasks/abc014_4
