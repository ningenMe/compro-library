#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include <iostream>
using namespace std;
#include "../../../lib/data-structure/data-structure/DisjointSparseTable.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    DisjointSparseTable<NodeSum<long long>> st(A);
    while(Q--){
        int l,r; cin >> l >> r;
        cout << st.fold(l,r) << endl;
    }
}