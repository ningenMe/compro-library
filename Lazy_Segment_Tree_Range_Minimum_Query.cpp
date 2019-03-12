#include <bits/stdc++.h>
using namespace std;


template<class T> class Lazy_Segment_Tree_Range_Minimum_Query {
	size_t N, M;
	T ini;
	vector<T> node, lazy;
	vector<bool> lazyflag;

public:
	Lazy_Segment_Tree_Range_Minimum_Query(const vector<T>& ar, const T ini) : M(ar.size()), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1);
		lazy.resize(2 * N - 1, ini);
		lazyflag.resize(2 * N - 1, false);
		for (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
	}

	Lazy_Segment_Tree_Range_Minimum_Query(const size_t M, const T ini) : M(M), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
		lazy.resize(2 * N - 1, ini);
		lazyflag.resize(2 * N - 1, false);
	}

	void eval(int k, int l, int r) {
		if (lazyflag[k]) {
			node[k] = lazy[k];
			if (r - l > 1) {
				lazy[k * 2 + 1] = lazy[k];
				lazy[k * 2 + 2] = lazy[k];
				lazyflag[k * 2 + 1] = lazyflag[k * 2 + 2] = true;
			}
			lazyflag[k] = false;
		}
	}

	void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = N;
		eval(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			lazyflag[k] = true;
			eval(k, l, r);
		}
		else {
			update(a, b, x, 2 * k + 1, l, (l + r) / 2);
			update(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	}

	T getvar(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = N;
		eval(k, l, r);
		if (b <= l || r <= a) return ini;
		if (a <= l && r <= b) return node[k];
		T vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);
	}

	T operator[](size_t i) {
		return getvar(i, i + 1);
	}

	T operator[](pair<size_t, size_t> p) {
		return getvar(p.first, p.second);
	}

	void print() {
		cout << "{ " << getvar(0, 1);
		for (int i = 1; i < M; ++i) cout << ", " << getvar(i, i + 1);
		cout << " }" << endl;
	}
};


//verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e