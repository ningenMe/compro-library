#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/13-static-range-query/LongestIncreasingSubsequence.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; read(N);
    vector<long long> A(N);
    for(int i =0;i<N;++i) read(A[i]);
    LongestIncreasingSubsequence<long long> lis(A);
    auto sz = lis.size();
    auto v = lis.index();
    cout << sz << "\n";
    for(int i=0; i < sz; ++i) cout << v[i] << " \n"[i==sz-1];
	return 0;
}