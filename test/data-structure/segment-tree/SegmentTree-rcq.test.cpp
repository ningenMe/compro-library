#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../../lib/data-structure/segment-tree/SegmentTree.cpp"
#include "../../lib/util/ModInt.cpp"

using modint = ModInt<998244353>;
int main(){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<pair<modint,modint>> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    SegmentTree<NodeCompositePointUpdate<pair<modint,modint>>> seg(A);
    while(Q--){
        long long q,l,r,x; cin >> q >> l >> r >> x;
        if(q) {
			auto p = seg.get(l,r);
			cout << p.first*x+p.second << endl;
		}
        else seg.update(l,{r,x});
    }
}

