#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/10-segment-tree/DualSegmentTree.cpp"
#include "../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    using Mint = ModInt<MOD_998244353>;
    int N,Q;
    read(N),read(Q);
    DualSegmentTree<MonoidRangeFoldSumRangeOperateAffine<Mint,pair<Mint,Mint>>> seg(N);
    for(int i=0;i<N;++i) {
        int a; read(a);
        seg.operate(i,i+1,{0,a});
    }
    while(Q--) {
        int q; read(q);
        if(q==0) {
            int l,r,b,c;
            read(l),read(r),read(b),read(c);
            seg.operate(l,r,{b,c});
        }
        if(q==1) {
            int i; read(i);
            cout << seg.fold(i) << "\n";
        }
    }
    return 0;
}