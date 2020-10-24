#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <vector>
#include <iostream>
using namespace std;
#include "../../lib/util/LongestIncreasingSubsequence.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<long long> a(N);
    for(int i=0;i<N;++i) cin >> a[i];
    cout << LongestIncreasingSubsequence(a) << endl;
	return 0;
}