#define PROBLEM "https://yukicoder.me/problems/no/1170"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
using namespace std;
#include "../../lib/00-util/RangeIndex.cpp"
#include "../../lib/40-graph/UnionFindTree.cpp"


int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    long long N,A,B; cin >> N >> A >> B;
    vector<long long> X(N);
    for(int i = 0; i < N; ++i) cin >> X[i];
    X.push_back(1e10);
    RangeIndex ri(N);
    UnionFindTree uf(ri.size());
    vector<int> st(ri.size(),0);
    for(int i = 0; i < N; ++i) {
        int l = lower_bound(X.begin(),X.end(),X[i]+A)-X.begin();
        int r = upper_bound(X.begin(),X.end(),X[i]+B)-X.begin();
        for(auto& e:ri.range(l,r)) {
            st[e]=1;
            uf.merge(ri[i],e);
        }
    }
    for(int i = 0; i < N; ++i) {
        for(auto& e:ri.include_range(i)) if(st[e]) uf.merge(ri[i],e);
    }
    vector<int> cnt(ri.size(),0);
    for(int i = 0; i < N; ++i) {
        cnt[uf[ri[i]]]++;
    }
    for(int i = 0; i < N; ++i) {
        cout << cnt[uf[ri[i]]] << endl;
    }

    return 0;
}
