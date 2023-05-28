#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/operator/monoid-lazy/MonoidRangeSumRangeAdd.cpp"
#include "../../lib/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp"

int main(void){
    int N,Q;
	scanf("%d %d",&N,&Q);
    LazyRandomizedBinarySearchTreeSequence<MonoidRangeSumRangeAdd<long long,long long>> A;
    for(int i=0;i<N;++i) {
		A.insert(i,0);
    }
    while(Q--) {
        int q;
		scanf("%d",&q);
		if(q==0) {
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			l--;
			A.operate(l,r,x);
		}
		else {
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			printf("%lld\n",A.fold(l,r));
		}
    }
    return 0;
}