#define PROBLEM "https://yukicoder.me/problems/no/979"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
	int N; read(N);
	vector<long long> A(N),dp(300001,0);
	for(int i = 0; i < N; ++i) read(A[i]);

	for(int i = 0; i < N; ++i) {
		auto D = Prime::divisor(A[i]);
        if(A[i]!=0){
			dp[A[i]]=max(dp[A[i]],dp[0]+1);
        }
		for(auto e:D){
			if(e==A[i]) continue;
			dp[A[i]]=max(dp[A[i]],dp[e]+1);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}