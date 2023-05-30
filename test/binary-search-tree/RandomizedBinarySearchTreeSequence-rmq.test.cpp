#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/99-operator/monoid/MonoidRangeMinPointUpdate.cpp"
#include "../../lib/12-binary-search-tree/RandomizedBinarySearchTreeSequence.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    RandomizedBinarySearchTreeSequence<MonoidRangeMinPointUpdate<long long>> lbst;
    int N,Q; cin >> N >> Q;
    for(int i=0;i<N;++i) {
        int a; cin >> a;
        lbst.insert(i,a);
    }
    while(Q--) {
        int l,r; cin >> l >> r;
        cout << lbst.fold(l,r) << "\n";
    }
    return 0; 
}

