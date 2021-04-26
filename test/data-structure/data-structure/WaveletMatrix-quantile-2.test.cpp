#define PROBLEM "https://yukicoder.me/problems/no/919"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;
using int128  = __int128_t;
using int64   = long long;
using int32   = int;
using uint128 = __uint128_t;
using uint64  = unsigned long long;
using uint32  = unsigned int;

#include "../../../lib/data-structure/data-structure/BitVector.cpp"
#include "../../../lib/data-structure/data-structure/WaveletMatrix.cpp"

void chmax(int64& a,int64 b){a=max(a,b);}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
	int N; cin >> N;
    vector<int64> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
    WaveletMatrix<int64> wm(A);

	//クエリ区間を列挙、調和級数なのでO(N*logN)
	vector<pair<int,int>> range;
	for(int j = 1; j <= N; ++j) {
		int M = N/j;
		for(int i = 0;     i+j <= N; i+=j) range.push_back({i,i+j});
		for(int i = N-M*j; i+j <= N; i+=j) range.push_back({i,i+j});
	}

	long long ans = 0;
	int cnt = 0;
	//区間長決め打ち全探索O(N*logN)
	for(long long n = 1; n <= N; ++n) {
		int M = N/n;
		vector<long long> lSum(M,0),rSum(M,0);
		vector<pair<int, int>> l_range(M),r_range(M);
		//区間取得 O(M)
		for(int i = 0; i < M; ++i) {
			l_range[i] = range[cnt + i];
			lSum[i]   = n*wm.quantile(l_range[i].first,l_range[i].second,(l_range[i].second-l_range[i].first-1)/2) ;
			r_range[i] = range[cnt + i + M];
			rSum[i]   = n*wm.quantile(r_range[i].first,r_range[i].second,(r_range[i].second-r_range[i].first-1)/2);
		}
		//累積和 O(M)
		for(int i = 1;    i < M; ++i) lSum[i]  += lSum[i-1];
		for(int i = M-2; 0 <= i; --i) rSum[i]  += rSum[i+1];
		//累積max O(M)
		for(int i = 1;    i < M; ++i) chmax(lSum[i],lSum[i-1]);
		for(int i = M-2; 0 <= i; --i) chmax(rSum[i],rSum[i+1]);

		chmax(ans,lSum[M-1]);
		chmax(ans,rSum[0]);

		//尺取りしながら左右決め打ち全探索 O(M)
		int j = 0;
		for(int i = 0; i < M; ++i) {
			while(j < M && l_range[i].second-1 >= r_range[j].first) j++;
			if(j<M && l_range[i].second-1 < r_range[j].first) {
				chmax(ans,lSum[i]+rSum[j]);
			}
		}
		cnt += 2*M;
	}
	cout << ans << endl;

    return 0;
}
