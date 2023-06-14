#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <stack>
using namespace std;

#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/98-needless/IntegerRangeFrequencyQueryTree.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N); read(Q);
    vector<unsigned long long> A(N);
    for(int i=0;i<N;++i) read(A[i]);
    IntegerRangeFrequencyQueryTree<30> rfqt(A);
    while(Q--) {
        int l,r,k; read(l); read(r); read(k);
		cout << rfqt.range_freq(l,r,k) << "\n";
    }
    return 0;
}