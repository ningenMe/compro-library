#define PROBLEM "https://yukicoder.me/problems/no/1068"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticTransform.cpp"
constexpr long long MOD = 998244353;

vector<vector<ModInt<MOD>>> v;
vector<ModInt<MOD>> rec(int l, int r,NumberTheoreticTransform<MOD>& ntt) {
    if(r-l==1) return v[l];
    if(r-l==2) return ntt.convolution(v[l],v[l+1]);
    auto vl=rec(l,(l+r)/2,ntt);
    auto vr=rec((l+r)/2,r,ntt);
    return ntt.convolution(vl,vr);
}

int main() {
    int N,Q; cin >> N >> Q;
    vector<ModInt<MOD>> A(N);
    vector<int> B(Q);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < Q; ++i) cin >> B[i];
    v.resize(N);
    for(int i = 0; i < N; ++i) v[i].push_back(A[i]-1),v[i].push_back(1);
    NumberTheoreticTransform<MOD> ntt;
    auto c = rec(0,N,ntt);
    for(int i = 0; i < Q; ++i) {
        cout << c[B[i]] << endl;
    }
    return 0;
}
