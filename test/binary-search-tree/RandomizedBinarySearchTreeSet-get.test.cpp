#define PROBLEM "https://yukicoder.me/problems/no/649"

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
#include "../../lib/12-binary-search-tree/RandomizedBinarySearchTreeSet.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
	RandomizedBinarySearchTreeSet<MonoidRangeSumPointAdd<long long>> st;
	int Q,K; cin >> Q >> K;
	while (Q--){
		int q; cin >> q;
		if(q==1){
			long long x; cin >> x;
			st.insert(x);
		}
		else{
			long long x=-1;
			if(st.size()>=K){
				x=st.get(K-1);
				st.erase(x);
			}
			cout << x << endl;
		}
	}

    return 0;
}