#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
#include "../../../lib/data-structure/segment-tree/DynamicSegmentTree.cpp"
#include "../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    DynamicSegmentTree<MonoidRangeSumPointAdd<long long>> dseg;
    int N,Q; cin >> N >> Q;
    for(int i=0;i<N;++i) {
        int a; cin >> a;
        dseg.operate(i,a);
    }
    while(Q--) {
        int l,r; cin >> l >> r;
        cout << dseg.fold(l,r) << endl;
    }
    return 0;

}