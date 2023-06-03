#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

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
    int N,Q; 
	read(N); read(Q);
    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAffine<modint,pair<modint,modint>>> st;
    for(int i = 0; i < N; ++i) {
        int a; read(a); st.insert(i,a);
    }
    while(Q--){
        int q,l,r; 
		read(q); read(l); read(r);
        if(q) {
			cout << st.fold(l,r) << "\n";
		}
        else {
			int b,c; read(b); read(c);
			st.operate(l,r,{modint(b),modint(c)});
		}
    }
}

