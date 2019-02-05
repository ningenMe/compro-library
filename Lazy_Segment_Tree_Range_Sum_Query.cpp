#include <bits/stdc++.h>
using namespace std;

template<class T> class Lazy_Segment_Tree_Range_Sum_Query {
public:
 	int N, M;
	T ini;
	vector<T> node,lazy;

    Lazy_Segment_Tree_Range_Sum_Query(const vector<T> & ar, const T ini) : ini(ini){
        for (N = 1, M = ar.size(); N < M; N *= 2);
        node.resize(2 * N - 1, ini);
        lazy.resize(2 * N - 1, ini);
		for (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];
    }

	Lazy_Segment_Tree_Range_Sum_Query(const int M, const T ini) : M(M),ini(ini){
        for (N = 1; N < M; N *= 2);
        node.resize(2 * N - 1, ini);
        lazy.resize(2 * N - 1, ini);
    }

    void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if(r - l > 1) lazy[2*k+1] += lazy[k] / 2;
		if(r - l > 1) lazy[2*k+2] += lazy[k] / 2;
		lazy[k] = ini;
    }

    void update(int a, int b, T x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    T getvar(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        T vl = getvar(a, b, 2*k+1, l, (l+r)/2);
        T vr = getvar(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }

	void print(){
		cout << "{ " << getvar(0,1);
		for(int i = 1; i < M; ++i) cout << ", " << getvar(i,i+1);
		cout << " }" << endl;
	}
};


//verify https://atcoder.jp/contests/arc068/tasks/arc068_c