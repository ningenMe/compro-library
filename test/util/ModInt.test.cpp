#define PROBLEM "https://yukicoder.me/problems/no/1067"

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#include "../../lib/util/ModInt.cpp"

constexpr long long MOD2 = 998244353;
using modint = ModInt<MOD2>;
int main() {
    long long N,Q; cin >> N >> Q;
    vector<long long> A(N+1,1234567890LL);
    for(int i = 1; i <= N; ++i) cin >> A[i];
	sort(A.begin(),A.end(),greater<>());
    A.push_back(0);
    vector<long long> L(Q),R(Q),P(Q);
    for(int i = 0; i < Q; ++i) cin >> L[i] >> R[i] >> P[i];
    priority_queue<pair<long long,int>> pq;
    for(int i = 0; i < Q; ++i) {
        for(int j = L[i]; j <= R[i]; ++j) {
            pq.push({j,P[i]});
        }
    }
    vector<vector<modint>> dp(2,vector<modint>(N+2));
    dp[0][0]=1;
    modint cnt = 1;
    for(int i = 1; i <= N; ++i) cnt *= A[i];
    map<pair<long long,int>,modint> mp;
    for(int i = 1; i <= N+1; ++i) {
        while(pq.size() && pq.top().first>A[i]) {
            auto p = pq.top();
            pq.pop();
            mp[p]=dp[(i-1)%2][p.second]*cnt;
        }
        for(int j = 0; j <= N; ++j) {
            dp[i%2][j] = 0;
        }
        for(int j = 0; j <= i-1; ++j) {
            dp[i%2][j+1] += dp[(i-1)%2][j];
            dp[i%2][j]   += dp[(i-1)%2][j]*(A[i]-1);
        }
        cnt /= A[i];
    }
    for(int i = 0; i < Q; ++i) {
        modint ans = 0;
        for(int j = L[i]; j <= R[i]; ++j) {
            ans ^= mp[{j,P[i]}];
        }
        cout << ans << endl;
    }
    return 0;
}
