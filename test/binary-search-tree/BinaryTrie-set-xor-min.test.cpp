#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../lib/12-binary-search-tree/BinaryTrie.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp"
int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	BinaryTrie<MonoidRangeSumPointAdd<int>,30> trie;
	int Q; cin >> Q;
	while (Q--){
		int q; cin >> q;
		long long x; cin >> x;
		if(q==0) {
			long long y=trie.fold(x);
			if(!y) trie.operate(x,1);
		}
		if(q==1) {
			long long y=trie.fold(x);
			if(y) trie.operate(x,-1);
		}
		if(q==2) {
			cout << trie.min_bitwise_xor(x) << endl;
		}
	}
}