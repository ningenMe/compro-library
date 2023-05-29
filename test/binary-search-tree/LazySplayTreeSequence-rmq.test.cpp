#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.cpp"
#include "../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; 
	read(N); read(Q);
    LazySplayTreeSequence<MonoidRangeFoldMinRangeOperateUpdate<int,int>> st;
    for(int i = 0; i < N; ++i) {
        int a; read(a); st.insert(i,a);
    }

    while(Q--){
        int l,r; 
		read(l);read(r);
        cout << st.fold(l,r) << "\n";
    }
    return 0; 
}

