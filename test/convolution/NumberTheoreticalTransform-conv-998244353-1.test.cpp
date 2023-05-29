#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/convolution/NumberTheoreticalTransform.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
    int N,M; read(N),read(M);
    vector<ModInt<MOD_998244353>> A(N),B(M);
    for(int i = 0; i < N; ++i) {
        int a; read(a); A[i]=a;
    }
    for(int i = 0; i < M; ++i) {
        int b; read(b); B[i]=b;
    }
	auto C = NumberTheoreticalTransform<MOD_998244353>::convolution(A,B);
    for(int i = 0; i < N+M-1; ++i) cout << C[i] << " \n"[i==N+M-2];
	return 0;
}
