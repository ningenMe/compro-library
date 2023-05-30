#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int Q; read(Q);
    while(Q--) {
        long long a,sum=0; 
        read(a);
        auto pf = Prime::factorization(a);
        string ans = "";
        for(auto pa:pf) {
            sum += pa.second;
            for(int i=0;i<pa.second;++i) ans += " " + to_string(pa.first);
        }
        cout << sum << ans << "\n";
    }
	return 0;
}