#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <stack>
#include <cmath>
using namespace std;

#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/10-segment-tree/RangeIntegerFrequencyQuerySqrtTree.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N); read(Q);

    RangeIntegerFrequencyQuerySqrtTree<30> rfq(N);
    for(int i=0;i<N;++i) {
        int a; read(a);
        rfq.update(i,a);
    }
    while(Q--) {
        int l,r,x;
        read(l); read(r); read(x);
        cout << rfq.range_freq(l,r,x) << "\n";
    }
    return 0;
}