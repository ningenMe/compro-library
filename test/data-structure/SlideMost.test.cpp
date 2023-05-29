#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <vector>
#include <iostream>
#include <deque>
using namespace std;
#include "../../lib/14-data-structure/SlideMost.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,L; cin >> N >> L;
    vector<int> A(N);
    for(int i=0;i<N;++i) cin >> A[i];
    SlideMost<ValueMin<int>> sld;
    auto B = sld.window(A,L);
    for(int i=L-1;i<N;++i) cout << B[i] << " \n"[i==N-1];
    return 0;
}