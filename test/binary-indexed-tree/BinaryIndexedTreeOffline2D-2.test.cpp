#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#include "../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp"
#include "../../lib/11-binary-indexed-tree/BinaryIndexedTreeOffline2D.cpp"

int main(void){
    int N,Q;
    scanf("%d %d",&N,&Q);
    vector<long long> X(N+Q,0),Y(N+Q,0),W(N+Q,0);
    vector<int> A(Q),L(Q),D(Q),R(Q),U(Q);
    for(int i=0;i<N;++i) scanf("%d %d %d",&X[i],&Y[i],&W[i]);
    for(int i=0;i<Q;++i) {
        scanf("%d",&A[i]);
        if(A[i]==0) scanf("%d %d %d",&X[i+N],&Y[i+N],&W[i+N]);
        else scanf("%d %d %d %d",&L[i],&D[i],&R[i],&U[i]);
    }
    BinaryIndexedTreeOffline2D<AbelPrefixSumPointAdd<long long>> bit(X,Y);
    for(int i=0;i<N;++i) bit.operate(X[i],Y[i],W[i]);
    for(int i=0;i<Q;++i) {
        if(A[i]==0) bit.operate(X[i+N],Y[i+N],W[i+N]);
        else printf("%lld\n",bit.fold(L[i],R[i],D[i],U[i]));
    }
    return 0; 
}