#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/operator/monoid-lazy/MonoidRangeSumRangeAffine.cpp"
#include "../../lib/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp"

using modint = ModInt<998244353>;

int main(void){
    int N,Q;
	scanf("%d %d",&N,&Q);
	LazyRandomizedBinarySearchTreeSequence<MonoidRangeSumRangeAffine<modint,pair<modint,modint>> > rbst;
    for(int i=0;i<N;++i) {
		int a; cin >> a;
		rbst.insert(i,a);
    }
    while(Q--) {
        int q;
		scanf("%d",&q);
		if(q==0) {
			int i,x;
			scanf("%d %d",&i,&x);
			rbst.insert(i,x);
		}
		if(q==1) {
			int i;
			scanf("%d",&i);
			rbst.erase(i);
		}
		if(q==2) {
			int l,r;
			scanf("%d %d",&l,&r);
			rbst.reverse(l,r);
		}
		if(q==3) {
			int l,r,b,c;
			scanf("%d %d %d %d",&l,&r,&b,&c);
			rbst.operate(l,r,{b,c});
		}
		if(q==4) {
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%lld\n",rbst.fold(l,r).x);
		}
    }
    return 0; 
}

