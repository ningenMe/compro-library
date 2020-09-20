#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2020Day2/problems/B"
#define IGNORE

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/segment/Rbst.cpp"
#include "../../lib/geometory/ConvexHullTrick.cpp"
#include "../../lib/segment/ConvexHullTrickSegmentTree.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    ConvexHullTrickSegmentTree<ValueMin<long long>> seg(N);
    for(int i=0;i<N;++i){
        int a,b; cin >> a >> b;
        seg.update(i,a,b);
    }
    while(Q--){
        int l,r;long long x; cin >> l >> r >> x;
        l--;
        cout << seg.get(l,r,x) << "\n";
    }
	return 0;
}