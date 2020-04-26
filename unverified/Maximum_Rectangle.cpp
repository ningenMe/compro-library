#include <bits/stdc++.h>
using namespace std;

long long Maximum_Rectangle(vector<long long>& ar){
	ar.push_back(0);
	stack<pair<long long,long long>> st;
	long long res = 0;
	for(long long r = 0; r < ar.size(); ++r){
		long long vr = ar[r];
		if(st.empty()){
			st.push({vr,r});
			continue;
		}

		long long vl = st.top().first, l = st.top().second;
		if(vl < vr) st.push({vr,r});
		if(vl < vr || vl == vr)	continue;
		
		while(vl > vr) {
			res = max(res,vl*(r - l));
			st.pop();

			if(st.size() && st.top().first > vr) vl = st.top().first, l = st.top().second;
			else break;
		}
		st.push({vr,l});
	}
	ar.pop_back();
	return res;
}


//verify