#include <bits/stdc++.h>
using namespace std;

template<class T> class Segment_Tree_Range_Minimum_Query {
public:
	int N;
	T ini;
	vector<T> node;

	Segment_Tree_Range_Minimum_Query(const vector<T> & ar, const T ini) : ini(ini) {
		for (N = 1; N < ar.size(); N *= 2);
		node.resize(2 * N - 1, ini);
		for (int i = 0; i<ar.size(); ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
	}

	void update(int idx, const T var) {
		idx += (N - 1);
		node[idx] = var;
		while (idx > 0) {
			idx = (idx - 1) / 2;
			node[idx] = min(node[2 * idx + 1], node[2 * idx + 2]);
		}
	}

	T getvar(const int a, const int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = N;
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return node[k];
		T vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
};

//verify https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_c