#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../../lib/30-math/Gcd.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int Q; cin >> Q;
	Prime P;
    while(Q--) {
        long long a,sum=0; cin >> a;
        auto pf = P.factorization(a);
        string ans = "";
        for(auto pa:pf) {
            sum += pa.second;
            for(int i=0;i<pa.second;++i) ans += " " + to_string(pa.first);
        }
        cout << sum << ans << "\n";
    }
	return 0;
}