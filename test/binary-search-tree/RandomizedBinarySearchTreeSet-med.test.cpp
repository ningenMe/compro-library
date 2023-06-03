#define PROBLEM "https://yukicoder.me/problems/no/919"

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
#include "../../lib/12-binary-search-tree/RandomizedBinarySearchTreeSet.cpp"
#include "../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp"

template<class T> class Mo{
    unordered_map<long long,int> mp;
    long long N;
    int bucket;
    vector<pair<int,int>> range;
	vector<int> idx;
public:

    Mo(int N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N)) {
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int a, int b){
            auto  al = range[a].first/bucket;
            auto  ar = range[a].second;
            auto  bl = range[b].first/bucket;
            auto  br = range[b].second;
            return (al != bl) ? (al < bl) : ((al%2)?(ar > br):(ar < br));
        });
    }
    
    //参照でvectorを渡したりすると良い
    void solve(const vector<int>& A, RandomizedBinarySearchTreeSet<MonoidRangeSumPointAdd<long long>>& med){
        int l = 0, r = 0;
        for(int& i:idx){
            auto& xl = range[i].first;
            auto& xr = range[i].second;
            
            //左端を広げる
            while(xl < l){
                l--;
                med.insert(A[l]);
            }
            //右端を広げる
            while(r < xr){
                r++;
                med.insert(A[r]);
            }
            //左端を狭める
            while(l < xl){
				med.erase(A[l]);
                l++;
            }
            //右端を狭める
            while(xr < r){
				med.erase(A[r]);
                r--;
            }
            mp[xl*N+xr] = med.get((xr-xl)/2);
        }
    }

    T& operator [] (pair<int,int> p) {
        return mp[p.first*N+p.second];
    }
};

template <class T> void chmax(T& a, const T b){a=max(a,b);}

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
	int N; cin >> N;
    vector<int> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];

	//クエリ区間を列挙、調和級数なのでO(N*logN)
	vector<pair<int,int>> range;
	for(int n = 1; n <= N; ++n) {
		int M = N/n;
		for(int i = 0;     i+n <= N; i+=n) range.push_back({i,i+n-1});
		for(int i = N-M*n; i+n <= N; i+=n) range.push_back({i,i+n-1});
	}

	
	//Moで中央値列挙　O(N*sqrt(N)*(logN)^2)
    Mo<int> mo(N,range);
    RandomizedBinarySearchTreeSet<MonoidRangeSumPointAdd<long long>> med;
    med.insert(A[0]);
    mo.solve(A,med);

	long long ans = 0;
	int cnt = 0;
	//区間長決め打ち全探索O(N*logN)
	for(long long n = 1; n <= N; ++n) {
		int M = N/n;
		vector<long long> lSum(M,0),rSum(M,0);
		vector<pair<int, int>> lRange(M),rRange(M);
		//区間取得 O(M)
		for(int i = 0; i < M; ++i) {
			lRange[i] = range[cnt + i];
			lSum[i]   = n*mo[lRange[i]];
			rRange[i] = range[cnt + i + M];
			rSum[i]   = n*mo[rRange[i]];
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
			while(j < M && lRange[i].second >= rRange[j].first) j++;
			if(j<M && lRange[i].second < rRange[j].first) {
				chmax(ans,lSum[i]+rSum[j]);
			}
		}
		cnt += 2*M;
	}
	cout << ans << endl;

    return 0;
}
