#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#include "../../lib/operator/AbelNodePrefixSumPointAdd.cpp"
#include "../../lib/segment/BinaryIndexedTreeOffline2D.cpp"

int main(void){
    int N,Q;
    scanf("%d %d",&N,&Q);
    vector<long long> X(N),Y(N),W(N);
    for(int i=0;i<N;++i) scanf("%d %d %d",&X[i],&Y[i],&W[i]);
    BinaryIndexedTreeOffline2D<AbelNodePrefixSumPointAdd<long long>> bit(X,Y);
    for(int i=0;i<N;++i) bit.operate(X[i],Y[i],W[i]);
    vector<int> L(Q),D(Q),R(Q),U(Q);
    for(int i=0;i<Q;++i) scanf("%d %d %d %d",&L[i],&D[i],&R[i],&U[i]);
    for(int i=0;i<Q;++i) printf("%lld\n",bit.fold(L[i],R[i],D[i],U[i]));
}