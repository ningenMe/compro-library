#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
#include "../../lib/10-segment-tree/DynamicSegmentTree.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
	DynamicSegmentTree<MonoidRangeSumPointAdd<long long>> seg;
    for(int i = 0; i < N; ++i) {
		int a; cin >> a;
		seg.operate(i,a);
    }
    
    while(Q--){
        long long q,l,r; cin >> q >> l >> r;
        if(q) cout << seg.fold(l,r) << "\n";
        else seg.operate(l,r);
    }
}