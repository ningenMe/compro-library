#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#include "../../../lib/util/FastIO.cpp"
#include "../../../lib/data-structure/range-query/DisjointSparseTable.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; 
	read(N); read(Q);
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        read(A[i]);
    }
    DisjointSparseTable<NodeSum<long long>> st(A);
    while(Q--){
		int l,r;
		read(l); read(r);
        cout << st.fold(l,r) << "\n";
    }
}