#define PROBLEM "https://yukicoder.me/problems/no/1068"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/math/NumberTheoreticTransform.cpp"
constexpr long long MOD = 998244353;

vector<vector<long long>> v;
vector<long long> rec(int l, int r) {
    if(r-l==1) return v[l];
    if(r-l==2) return NumberTheoreticTransform<MOD>::convolution(v[l],v[l+1]);
    auto vl=rec(l,(l+r)/2);
    auto vr=rec((l+r)/2,r);
    return NumberTheoreticTransform<MOD>::convolution(vl,vr);
}

int main() {
    int N,Q; cin >> N >> Q;
    vector<long long> A(N),B(Q);
    for(int i = 0; i < N; ++i) cin >> A[i],A[i] %= MOD;
    for(int i = 0; i < Q; ++i) cin >> B[i];
    v.resize(N);
    for(int i = 0; i < N; ++i) v[i].push_back(A[i]-1),v[i].push_back(1);
    auto c = rec(0,N);
    for(int i = 0; i < Q; ++i) {
        cout << c[B[i]] << endl;
    }
    return 0;
}
