#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/99-operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp"
#include "../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp"


int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    LazySplayTreeSequence<MonoidRangeFoldMinRangeOperateUpdate<int,int>> seq;
    int N,Q; read(N),read(Q);
    for(int i=0;i<N;++i) {
        int a; read(a);
        seq.insert(i,a);
    }
    while(Q--) {
        int x,y,z; 
        read(x),read(y),read(z);
        if(x==0) {
            auto w = seq.get(z);
            seq.erase(z);
            seq.insert(y,w);
        }
        if(x==1) {
            cout << seq.fold(y,z+1) << "\n";
        }
        if(x==2) {
            seq.operate(y,y+1,z);
        }
    }

    return 0; 
}

