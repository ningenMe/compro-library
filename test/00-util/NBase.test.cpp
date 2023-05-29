#define PROBLEM "https://yukicoder.me/problems/no/699"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include "../../lib/00-util/NBase.cpp"

int main(void){
	int N; cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(),A.end());
    vector<long long> B(N/2),C(N/2);
    long long ans = 0;
    for(int i = 0; i < (1<<N); ++i) {
        if(i&1 || NBase::digit_sum(i,2)!=N/2) continue;
        int b=0,c=0;
        for(int j = 0; j < N; ++j) {
            if(i&(1<<j)) B[b++]=A[j];
            else C[c++]=A[j];
        }
        do{
            long long sum = 0;
            for(int j = 0; j < N/2; ++j) {
                sum ^= (B[j]+C[j]);
            }
			ans = max(ans,sum);
        }while (next_permutation(B.begin(),B.end()));
    }
    cout << ans << endl;

	return 0;
}