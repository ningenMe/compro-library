#define PROBLEM "https://yukicoder.me/problems/no/1307"

#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/util/ModInt.cpp"
#include "../../lib/math/FastFourierTransform.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> A(N),B(N,0),D(N,0);
    for(int i=0;i<N;++i) cin >> A[i];
    while(Q--){
        int r; cin >> r; B[N-1-r]++;
    }
    auto C = FastFourierTransform::convolution(A,B);
    for(int i=0;i<2*N-1;++i) {
        D[(i+1)%N]+=C[i];
    }
    for(int i=0;i<N;++i) cout << D[i] << " \n"[i==N-1];
    return 0;
}
