#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

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
        int x,y,z; cin >> x >> y >> z;
        if(x==0) {
            auto w = lbst.get(z);
            lbst.erase(z);
            lbst.insert(y,w);
        }
        if(x==1) {
            cout << lbst.fold(y,z+1) << "\n";
        }
        if(x==2) {
            lbst.operate(y,z);
        }
    }
    return 0; 
}

