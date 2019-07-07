#include <bits/stdc++.h>
using namespace std;

template<class T> class Weighted_Tree {
public:
	int N, MAX_bit;
	T ini;
	vector<vector<pair<T,int>>> edge;
	vector<pair<T,int>> depth;
	vector<int> order;
	vector<vector<pair<T,int>>> parent;
	vector<vector<pair<T,int>>> child;

	Weighted_Tree(const int N,  T ini, const int MAX_bit = 20) : N(N), ini(ini) MAX_bit(MAX_bit), edge(N), depth(N, {-1,-1}), order(N, -1), parent(N, vector<pair<T,int>>(MAX_bit)), child(N) {
		//do nothing
	}

	//O(1)
	void make_edge(const int& from, const int& to, const T& w) {
		edge[from].push_back({w,to});
	}

	//O(N)
	void make_depth(const int& root) {
		queue<int> q;
		depth[root] = {0,0};
		q.push(root);
		while (q.size()) {
			int from = q.front();
			q.pop();
			for (auto& e : edge[from]) {
				T w = e.first;
				int to = e.second;
				if (depth[to].second != -1) continue;
				depth[to] = {depth[from].first + w, depth[from].second + 1};
				q.push(to);
			}
		}
	}

	//O(NlogN)
	void make_order(){
		vector<pair<int,int>> tmp(N);
		for (int i = 0; i < N; ++i) tmp[i] = {depth[i].second,i};
		sort(tmp.begin(),tmp.end(),greater<>());
		for (int i = 0; i < N; ++i) order[i] = tmp[i].second;
	}

	//O(MAX_bit*N)
	void make_parent() {
		for (int i = 0; i < N; ++i) parent[i][0] = {ini,i};
		for (int i = 0; i < N; ++i)	for (auto j : edge[i]) {
			if (depth[i].second > depth[j.second].second) parent[i][0] = j;
		}
		for (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1].second][bit - 1];
	}

	//O(N)
	// void make_child() {
	// 	for (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);
	// }

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
	}

};
//verify 
