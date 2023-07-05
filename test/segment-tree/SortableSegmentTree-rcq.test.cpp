#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"

#include <vector>
#include <iostream>
#include <cassert>
#include <set>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/10-segment-tree/SortableSegmentTree.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp"

int main(void){
     cin.tie(0);ios::sync_with_stdio(false);
    using Mint = ModInt<MOD_998244353>;

    int N; read(N);
    int Q; read(Q);
    vector<unsigned long long> k(N);
    vector<pair<Mint,Mint>> v(N);
    for(int i=0;i<N;++i) {
        int p,a,b; read(p),read(a),read(b);
        k[i]=p,v[i]={a,b};
    }
    SortableSegmentTree<30UL, MonoidRangeCompositePointUpdate<pair<Mint,Mint>>> seg(k,v);
    while(Q--) {
        int q; read(q);
        if(q==0) {
            int i,p,a,b; read(i),read(p),read(a),read(b);
            seg.operate(i,p,{a,b});
        }
        if(q==1) {
            int l,r,x; read(l),read(r),read(x);
            auto [a,b]=seg.fold(l,r);
            cout << a*x + b << "\n";
        }
        if(q==2) {
            int l,r; read(l),read(r);
            seg.sort_asc(l,r);
        }
        if(q==3) {
            int l,r; read(l),read(r);
            seg.sort_desc(l,r);
        }
    }
    return 0;
}