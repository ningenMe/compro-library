#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/10-segment-tree/SegmentTree2D.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; read(N);
    int L = 1002;
    SegmentTree2D<MonoidRangeSumPointAdd<int>> seg(L,L);
    while(N--) {
        int x1,y1,x2,y2; 
        read(x1),read(y1),read(x2),read(y2);
        seg.operate(y1,x1, 1);
        seg.operate(y1,x2,-1);
        seg.operate(y2,x1,-1);
        seg.operate(y2,x2, 1);
    }
    for(int i=0;i<L;++i) {
        for(int j=1;j<L;++j) {
            seg.operate(i,j,seg.fold(i,i+1,j-1,j));
        }
    }
    for(int j=0;j<L;++j) {
        for(int i=1;i<L;++i) {
            seg.operate(i,j,seg.fold(i-1,i,j,j+1));
        }
    }
    int ans = 0;
    for(int i=0;i<L;++i) {
        for(int j=0;j<L;++j) {
            ans=max(ans,seg.fold(i,i+1,j,j+1));
        }
    }
    cout << ans << "\n";
	return 0;
}