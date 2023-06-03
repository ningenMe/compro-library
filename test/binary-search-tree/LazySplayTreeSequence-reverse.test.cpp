#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAffine.cpp"
#include "../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp"

using modint = ModInt<MOD_998244353>;

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N); read(Q);
    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>> st;
    for(int i=0;i<N;++i) {
        int a; read(a); st.insert(i,a);
    }
    while(Q--) {
        int q; read(q);
        if(q==0) {
            int i,x; read(i); read(x);
            st.insert(i,x);
        }
        if(q==1) {
            int i; read(i);
            st.erase(i);
        }
		if(q==2) {
			int l,r; read(l); read(r);
			st.reverse(l,r);
		}
		if(q==3) {
			int l,r,b,c; read(l); read(r); read(b); read(c);
			st.operate(l,r,{b,c});
		}
        if(q==4) {
            int l,r; read(l); read(r);
            cout << st.fold(l,r) << "\n";
        }
    }
    return 0;
}

