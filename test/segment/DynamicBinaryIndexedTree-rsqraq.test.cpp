#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;
#include "../../lib/segment/DynamicBinaryIndexedTree.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    DynamicBinaryIndexedTree<NodePrefixSumPointAdd<long long>> seg(1000000010);
    int N; cin >> N;
    long long ans = 0;
    while(N--) {
        int q,l,r; cin >> q >> l >> r;
        if(q==0) seg.update(l,r);
        else ans += seg.get(l,r+1);
    }
    cout << ans << endl;
    return 0; 
}