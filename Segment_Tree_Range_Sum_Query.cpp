#include <bits/stdc++.h>
using namespace std;

template<class T> class Segment_Tree_Range_Sum_Query {
	size_t N,M;
	T ini;
	vector<T> node;

public:
	Segment_Tree_Range_Sum_Query(const vector<T> & ar, const T ini) : M(ar.size()), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
		for (int i = 0; i < M; ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];
	}
 
	Segment_Tree_Range_Sum_Query(const size_t M, const T ini) : M(M), ini(ini) {
		for (N = 1; N < M; N *= 2);
		node.resize(2 * N - 1, ini);
	}
	
	void update(size_t idx, const T var) {
		idx += (N - 1);
		node[idx] += var;
		while (idx > 0) {
			idx = (idx - 1) / 2;
			node[idx] = node[2 * idx + 1]+node[2 * idx + 2];
		}
	}
 
	T getvar(const int a, const int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = N;
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return node[k];
		T vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl+vr;
	}
	
	T operator[](size_t idx) {
		return getvar(idx, idx + 1);
	}

	T operator[](pair<size_t, size_t> p) {
		return getvar(p.first, p.second);
	}

 
	void print(){
		cout << "{ " << getvar(0,1);
		for(int i = 1; i < M; ++i) cout << ", " << getvar(i,i+1);
		cout << " }" << endl;
	}
};

//verify https://atcoder.jp/contests/arc077/tasks/arc077_c