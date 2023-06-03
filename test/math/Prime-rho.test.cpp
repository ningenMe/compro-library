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
        long long a; read(a);
		vector<unsigned long long> v;
		if(Q&1) {
			auto vp = Prime::factorization(a);
			for(auto& p:vp) {
				for(int i=0;i<p.second;++i) v.push_back(p.first);
			}
		}
		else {
			v = Prime::factor(a); 
		}
        cout << v.size();
		for(unsigned long long& b: v) cout << " " << b;
		cout << "\n";
	}
    return 0;
}