#define PROBLEM "https://yukicoder.me/problems/no/1068"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/NumberTheoreticalTransform.cpp"
constexpr long long MOD = 998244353;
using modint = ModInt<MOD>;

vector<vector<modint>> v;
vector<modint> rec(int l, int r) {
    if(r-l==1) return v[l];
    if(r-l==2) return NumberTheoreticalTransform<modint>::convolution(v[l],v[l+1]);
    return NumberTheoreticalTransform<modint>::convolution(rec(l,(l+r)/2),rec((l+r)/2,r));
}

int main() {
    int N,Q; cin >> N >> Q;
    vector<ModInt<MOD>> A(N);
    vector<int> B(Q);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < Q; ++i) cin >> B[i];
    v.resize(N);
    for(int i = 0; i < N; ++i) v[i]={A[i]-1,1};
    auto c = rec(0,N);
    for(int i = 0; i < Q; ++i) {
        cout << c[B[i]] << endl;
    }
    return 0;
}
