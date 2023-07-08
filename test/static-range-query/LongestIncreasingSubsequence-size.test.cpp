#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/13-static-range-query/LongestIncreasingSubsequence.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; read(N);
    vector<long long> a(N);
    for(int i=0;i<N;++i) read(a[i]);
    LongestIncreasingSubsequence lis(a);
    cout << lis.size() << endl;
	return 0;
}