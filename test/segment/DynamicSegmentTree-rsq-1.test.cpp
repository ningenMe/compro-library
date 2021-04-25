#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
#include "../../lib/segment/DynamicSegmentTree.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    DynamicSegmentTree<NodeSumPointAdd<long long>> dseg;
    int N,Q; cin >> N >> Q;
    for(int i=0;i<N;++i) {
        int a; cin >> a;
        dseg.update(i,a);
    }
    while(Q--) {
        int l,r; cin >> l >> r;
        cout << dseg.get(l,r) << endl;
    }
    return 0;

}