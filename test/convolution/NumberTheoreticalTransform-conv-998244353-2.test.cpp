#define PROBLEM "https://yukicoder.me/problems/no/1068"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/convolution/NumberTheoreticalTransform.cpp"
using modint = ModInt<MOD_998244353>;

vector<vector<ModInt<MOD_998244353>>> v;
vector<ModInt<MOD_998244353>> rec(int l, int r) {
    if(r-l==1) return v[l];
    if(r-l==2) return NumberTheoreticalTransform<MOD_998244353>::convolution(v[l],v[l+1]);
    return NumberTheoreticalTransform<MOD_998244353>::convolution(rec(l,(l+r)/2),rec((l+r)/2,r));
}

int main() {
    int N,Q; read(N),read(Q);
    vector<ModInt<MOD_998244353>> A(N);
    vector<int> B(Q);
    for(int i = 0; i < N; ++i) {
        long long a; read(a);
        A[i]=a;
    }
    for(int i = 0; i < Q; ++i) read(B[i]);
    v.resize(N);
    for(int i = 0; i < N; ++i) v[i]={A[i]-1,1};
    auto c = rec(0,N);
    for(int i = 0; i < Q; ++i) {
        cout << c[B[i]] << "\n";
    }
    return 0;
}
