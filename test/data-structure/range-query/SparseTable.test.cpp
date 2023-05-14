#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <iostream>
using namespace std;
#include "../../../lib/util/FastIO.cpp"
#include "../../../lib/data-structure/range-query/SparseTable.cpp"

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; 
	read(N); read(Q);
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) {
        read(A[i]);
    }
    SparseTable<NodeMin<long long>> st(A);
    while(Q--){
        int l,r; 
		read(l);read(r);
        cout << st.fold(l,r) << "\n";
    }
}