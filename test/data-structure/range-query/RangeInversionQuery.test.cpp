#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;
#include "../../../lib/11-binary-indexed-tree/BinaryIndexedTree.cpp"
#include "../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp"
#include "../../../lib/data-structure/range-query/RangeInversionQuery.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false); 
    int N,Q; cin >> N >> Q;
    vector<long long> A(N);
    for(int i=0;i<N;++i) cin >> A[i];
    RangeInversionQuery<long long> riq(A);
    while(Q--) {
        int l,r; cin >> l >> r;
        long long inv = riq.fold(l,r);
        cout << inv << "\n";
    }
}