#define PROBLEM "https://yukicoder.me/problems/no/1307"

#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/convolution/NumberTheoreticalTransform.cpp"

constexpr long long MOD = 1000000000000000000LL;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N); read(Q);
    vector<ModInt<MOD>> A(N),B(N,0),D(N,0);
    for(int i=0;i<N;++i) {
        int a; read(a);
        A[i]=a;
    }
    while(Q--){
        int r; read(r); B[N-1-r]+=1;
    }
    auto C = NumberTheoreticalTransform<MOD>::convolution(A,B);
    for(int i=0;i<2*N-1;++i) {
        D[(i+1)%N]+=C[i];
    }
    for(int i=0;i<N;++i) cout << D[i] << " \n"[i==N-1];
    return 0;
}
