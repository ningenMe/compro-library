#define PROBLEM "https://yukicoder.me/problems/no/1170"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
using namespace std;
#include "../../lib/util/RangeIndex.cpp"
#include "../../lib/graph/UnionFindTree.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    long long N,A,B; cin >> N >> A >> B;
    vector<long long> X(N);
    for(int i = 0; i < N; ++i) cin >> X[i];
    X.push_back(1e10);
    RangeIndex ri(N);
    UnionFindTree uf(2*ri.size());
    vector<int> st(2*ri.size(),0);
    for(int i = 0; i < N; ++i) {
        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();
        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();
        for(auto& e:ri.range(l,r)) {
            st[e]=1;
            uf.merge(ri[i],e);
        }
    }
    for(int i = 0; i < N; ++i) {
        int j=i+ri.size();
        while(j >>= 1) if(st[j]) uf.merge(ri[i],j);
    }
    vector<int> cnt(2*ri.size(),0);
    for(int i = 0; i < N; ++i) {
        cnt[uf[ri[i]]]++;
    }
    for(int i = 0; i < N; ++i) {
        cout << cnt[uf[ri[i]]] << endl;
    }

    return 0;
}
