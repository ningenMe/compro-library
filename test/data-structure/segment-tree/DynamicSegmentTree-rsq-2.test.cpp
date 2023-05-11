#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <vector>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
#include "../../../lib/data-structure/segment-tree/DynamicSegmentTree.cpp"
#include "../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    DynamicSegmentTree<MonoidRangeSumPointAdd<long long>> seg;
    int N; cin >> N;
    long long ans = 0;
    while(N--) {
        int q,l,r; cin >> q >> l >> r;
        if(q==0) seg.operate(l,r);
        else ans += seg.fold(l,r+1);
    }
    cout << ans << endl;
    return 0;
}