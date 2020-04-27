#define PROBLEM "https://yukicoder.me/problems/no/742"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/segment/BinaryIndexedTree.cpp"

int main(void){
    int N; cin >> N;
    vector<int> A(N+1,0);
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    BinaryIndexedTree<NodePrefixSumPointAdd<int>> bit(N+1);
    int ans = 0;
    for(int i = N; 1 <= i; --i) {
        ans += bit.get(A[i]);
        bit.update(A[i],1);
    }
    cout << ans << endl;
	return 0;
}