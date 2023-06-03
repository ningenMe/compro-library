#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp"
#include "../../lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N); read(Q);
    LazyRandomizedBinarySearchTreeSequence<MonoidRangeFoldSumRangeOperateAdd<long long,long long>> st;
    for(int i=0;i<N;++i) {
        int a; read(a); st.insert(i,a);
    }
    while(Q--) {
        int q; read(q);
        int l,r; read(l); read(r);
        if(q==0) {
            st.reverse(l,r);
        }
        if(q==1) {
            cout << st.fold(l,r) << "\n";
        }
    }
    return 0;
}

