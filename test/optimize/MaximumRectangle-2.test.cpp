#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../lib/60-optimize/MaximumRectangle.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<long long> A(N);
    for(int i=0;i<N;++i) cin >> A[i];
    cout << MaximumRectangle(A) << endl;
    return 0;
}