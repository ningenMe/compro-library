#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <vector>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/10-segment-tree/DynamicSegmentTree.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeCompositePointUpdate.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    using Mint = ModInt<MOD_998244353>;
    int N,Q; 
    read(N), read(Q);
    DynamicSegmentTree<MonoidRangeCompositePointUpdate<pair<Mint,Mint>>> seg;
    for(int i = 0; i < N; ++i) {
		int a,b; read(a), read(b);
		seg.operate(i,{a,b});
    }
    while(Q--){
        long long q,l,r,x; 
		read(q),read(l),read(r),read(x);
        if(q) {
			auto p = seg.fold(l,r);
			cout << p.first*x+p.second << "\n";
		}
        else seg.operate(l,{r,x});
    }
}