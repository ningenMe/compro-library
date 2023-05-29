#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/operator/monoid-lazy/MonoidRangeSumRangeAffine.cpp"
#include "../../lib/12-binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp"
#include "../../lib/00-util/ModInt.cpp"

using modint = ModInt<998244353>;
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;} 

int main(void){
    int N,Q;
	scanf("%d %d",&N,&Q);
    LazyRandomizedBinarySearchTreeSequence<MonoidRangeSumRangeAffine<modint,pair<modint,modint>>> A;
    for(int i=0;i<N;++i) {
		int a;
		scanf("%d",&a);
		A.insert(i,a);
    }
    while(Q--) {
        int q;
		scanf("%d",&q);
		if(q==0) {
			int l,r,b,c;
			scanf("%d %d %d %d",&l,&r,&b,&c);
			A.operate(l,r,{b,c});
		}
		else {
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%lld\n",A.fold(l,r).x);
		}
    }
    return 0;
}

