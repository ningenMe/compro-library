#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/30-math/Eratosthenes.cpp"
#include "../../lib/31-convolution/GcdConvolution.cpp"


int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    using Mint = ModInt<MOD_998244353>;
    int N; read(N);
    vector<Mint> a(N+1,0),b(N+1,0);
    auto e = Eratosthenes(N);
    for(int i=1;i<=N;++i) {
        int t; read(t); a[i]=t;
    }
    for(int i=1;i<=N;++i) {
        int t; read(t); b[i]=t;
    }
    auto c = GcdConvolution::convolution(a,b,e);
    for(int i=1;i<=N;++i) {
        cout << c[i] << " \n"[i==N];
    }
    return 0;
}
