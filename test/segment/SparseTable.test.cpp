#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/SparseTable.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    SparseTable<NodeMin<long long>> st(A);
    while(Q--){
        int l,r; cin >> l >> r;
        cout << st.get(l,r) << endl;
    }
}