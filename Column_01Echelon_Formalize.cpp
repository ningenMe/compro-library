#include <bits/stdc++.h>
using namespace std;

// Column_01Echelon_Formalize O(N)
vector<long long> Column_01Echelon_Formalize(const vector<long long>& ar){
	vector<long long> res = ar;
	
	for(long long i = 59; 0 <= i; --i){
		int idx = -1;
		sort(res.begin(),res.end(),greater<long long>());
		for(int j = 0; j < res.size(); ++j){
			if( !(res[j] & (1LL<<i)) ) continue;
			int flg = 1;
			for(long long k = 59; i < k; --k) if(res[j] & (1LL<<k)) flg = 0;
			if(flg){
				idx = j;
				break;
			}
		}
		if(idx == -1) continue;
		for(int j = 0; j < res.size(); ++j) if(idx != j && (res[j] & (1LL<<i)) ) res[j] ^= res[idx];
	}

	return res;
}


//verify https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d